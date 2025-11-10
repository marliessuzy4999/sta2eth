/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

/**
 * sta2eth L2 Bridge using Official ESP-IDF Bridge API
 * 
 * This implementation uses esp_netif_br_glue for L2 bridging between:
 * - Ethernet (ESP32-P4)
 * - WiFi STA (ESP32-C6 via esp_wifi_remote over SDIO)
 * 
 * Key technique: Set WiFi STA MAC = Ethernet MAC for transparent bridging
 * This allows WiFi STA to receive packets destined for the Ethernet device
 */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "esp_netif.h"
#include "esp_netif_br_glue.h"
#include "esp_eth.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "esp_wifi_remote.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "ethernet_init.h"
#include "wifi_remote_sta.h"
#include "wifi_config_portal.h"
#include "c6_ota.h"

static const char *TAG = "sta2eth_bridge";

static EventGroupHandle_t s_event_flags;
static esp_netif_t *s_br_netif = NULL;
static esp_eth_handle_t s_eth_handle = NULL;
static uint8_t s_common_mac[6];

const int CONNECTED_BIT = BIT0;
const int DISCONNECTED_BIT = BIT1;
const int RECONFIGURE_BIT = BIT2;
const int PROV_SUCCESS_BIT = BIT3;
const int PROV_FAIL_BIT = BIT4;

/** Event handler for Ethernet events */
static void eth_event_handler(void *arg, esp_event_base_t event_base,
                              int32_t event_id, void *event_data)
{
    uint8_t mac_addr[6] = {0};
    esp_eth_handle_t eth_handle = *(esp_eth_handle_t *)event_data;

    switch (event_id) {
    case ETHERNET_EVENT_CONNECTED:
        esp_eth_ioctl(eth_handle, ETH_CMD_G_MAC_ADDR, mac_addr);
        ESP_LOGI(TAG, "Ethernet Link Up");
        ESP_LOGI(TAG, "Ethernet HW Addr %02x:%02x:%02x:%02x:%02x:%02x",
                 mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
        break;
    case ETHERNET_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "Ethernet Link Down");
        break;
    case ETHERNET_EVENT_START:
        ESP_LOGI(TAG, "Ethernet Started");
        break;
    case ETHERNET_EVENT_STOP:
        ESP_LOGI(TAG, "Ethernet Stopped");
        break;
    default:
        break;
    }
}

/** Event handler for WiFi Remote events */
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    if (event_base == WIFI_REMOTE_EVENT) {
        switch (event_id) {
        case WIFI_EVENT_STA_START:
            ESP_LOGI(TAG, "WiFi STA Started");
            break;
        case WIFI_EVENT_STA_CONNECTED:
            ESP_LOGI(TAG, "WiFi STA Connected");
            xEventGroupSetBits(s_event_flags, CONNECTED_BIT);
            xEventGroupClearBits(s_event_flags, DISCONNECTED_BIT);
            break;
        case WIFI_EVENT_STA_DISCONNECTED:
            ESP_LOGI(TAG, "WiFi STA Disconnected - reconnecting...");
            xEventGroupClearBits(s_event_flags, CONNECTED_BIT);
            xEventGroupSetBits(s_event_flags, DISCONNECTED_BIT);
            esp_wifi_remote_connect();
            break;
        default:
            break;
        }
    }
}

/** Event handler for IP events */
static void got_ip_event_handler(void *arg, esp_event_base_t event_base,
                                 int32_t event_id, void *event_data)
{
    ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
    const esp_netif_ip_info_t *ip_info = &event->ip_info;

    ESP_LOGI(TAG, "Bridge Got IP Address");
    ESP_LOGI(TAG, "~~~~~~~~~~~");
    ESP_LOGI(TAG, "IP:" IPSTR, IP2STR(&ip_info->ip));
    ESP_LOGI(TAG, "MASK:" IPSTR, IP2STR(&ip_info->netmask));
    ESP_LOGI(TAG, "GW:" IPSTR, IP2STR(&ip_info->gw));
    ESP_LOGI(TAG, "~~~~~~~~~~~");
}

/**
 * Initialize L2 bridge with Ethernet and WiFi STA
 */
static esp_err_t init_l2_bridge(void)
{
    // Initialize Ethernet driver
    uint8_t eth_port_cnt = 0;
    esp_eth_handle_t *eth_handles;
    ESP_ERROR_CHECK(ethernet_init_all(&eth_handles, &eth_port_cnt));

    if (eth_port_cnt == 0) {
        ESP_LOGE(TAG, "No Ethernet interface found!");
        return ESP_FAIL;
    }
    
    if (eth_port_cnt > 1) {
        ESP_LOGW(TAG, "Multiple Ethernet interfaces detected, using only the first one");
    }
    
    s_eth_handle = eth_handles[0];

    // Read Ethernet MAC address - this will be our common MAC for the bridge
    ESP_ERROR_CHECK(esp_eth_ioctl(s_eth_handle, ETH_CMD_G_MAC_ADDR, s_common_mac));
    ESP_LOGI(TAG, "Using common MAC address: %02x:%02x:%02x:%02x:%02x:%02x",
             s_common_mac[0], s_common_mac[1], s_common_mac[2],
             s_common_mac[3], s_common_mac[4], s_common_mac[5]);

    // Set Ethernet MAC to common MAC
    ESP_ERROR_CHECK(esp_eth_ioctl(s_eth_handle, ETH_CMD_S_MAC_ADDR, s_common_mac));

    // Create Ethernet netif for bridge (no IP, flags = 0)
    esp_netif_inherent_config_t eth_cfg = ESP_NETIF_INHERENT_DEFAULT_ETH();
    eth_cfg.flags = 0;  // No flags for bridged port
    eth_cfg.ip_info = NULL;  // No IP address for physical interface
    esp_netif_config_t netif_cfg = {
        .base = &eth_cfg,
        .stack = ESP_NETIF_NETSTACK_DEFAULT_ETH
    };
    esp_netif_t *eth_netif = esp_netif_new(&netif_cfg);
    
    // Attach Ethernet driver to netif
    ESP_ERROR_CHECK(esp_netif_attach(eth_netif, esp_eth_new_netif_glue(s_eth_handle)));

    // Initialize WiFi in STA mode with esp_wifi_remote
    ESP_LOGI(TAG, "Initializing WiFi Remote (C6 via SDIO)...");
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_remote_init(&cfg));
    
    // Set WiFi mode to STA
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    
    // CRITICAL: Set WiFi STA MAC = Ethernet MAC for transparent L2 bridging
    ESP_LOGI(TAG, "Setting WiFi STA MAC to match Ethernet MAC for transparent bridging");
    ESP_ERROR_CHECK(esp_wifi_set_mac(WIFI_IF_STA, s_common_mac));

    // Create WiFi STA netif for bridge (no IP, flags = 0)
    esp_netif_inherent_config_t wifi_cfg = ESP_NETIF_INHERENT_DEFAULT_WIFI_STA();
    wifi_cfg.flags = 0;  // No flags for bridged port (unlike AP which needs ESP_NETIF_FLAG_AUTOUP)
    wifi_cfg.ip_info = NULL;  // No IP address for physical interface
    esp_netif_t *wifi_netif = esp_netif_create_wifi(WIFI_IF_STA, &wifi_cfg);
    ESP_ERROR_CHECK(esp_wifi_set_default_wifi_sta_handlers());

    // Create bridge netif (this gets the IP address via DHCP)
    esp_netif_inherent_config_t br_cfg = ESP_NETIF_INHERENT_DEFAULT_BR();
    esp_netif_config_t br_netif_cfg = {
        .base = &br_cfg,
        .stack = ESP_NETIF_NETSTACK_DEFAULT_BR,
    };
    
    // Bridge configuration
    bridgeif_config_t bridgeif_config = {
        .max_fdb_dyn_entries = 10,  // Maximum dynamic forwarding database entries
        .max_fdb_sta_entries = 2,   // Maximum static forwarding database entries
        .max_ports = 2              // Ethernet + WiFi STA = 2 ports
    };
    br_cfg.bridge_info = &bridgeif_config;
    
    // Set bridge MAC address to common MAC
    memcpy(br_cfg.mac, s_common_mac, 6);
    s_br_netif = esp_netif_new(&br_netif_cfg);

    // Create bridge glue and add ports
    esp_netif_br_glue_handle_t br_glue = esp_netif_br_glue_new();
    
    // Add Ethernet port to bridge
    ESP_ERROR_CHECK(esp_netif_br_glue_add_port(br_glue, eth_netif));
    ESP_LOGI(TAG, "Added Ethernet port to bridge");
    
    // Add WiFi STA port to bridge
    ESP_ERROR_CHECK(esp_netif_br_glue_add_wifi_port(br_glue, wifi_netif));
    ESP_LOGI(TAG, "Added WiFi STA port to bridge");

    // Attach bridge glue to bridge netif
    ESP_ERROR_CHECK(esp_netif_attach(s_br_netif, br_glue));

    // Register event handlers
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, &eth_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_REMOTE_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_GOT_IP, &got_ip_event_handler, NULL));

    // Enable Ethernet promiscuous mode for bridge operation
    // This allows Ethernet to receive all packets, which are then filtered by the bridge
    bool promiscuous = true;
    ESP_ERROR_CHECK(esp_eth_ioctl(s_eth_handle, ETH_CMD_S_PROMISCUOUS, &promiscuous));
    ESP_LOGI(TAG, "Enabled Ethernet promiscuous mode for bridge operation");

    // Start Ethernet
    ESP_ERROR_CHECK(esp_eth_start(s_eth_handle));

    // Free the handles array
    free(eth_handles);

    return ESP_OK;
}

/**
 * Connect to WiFi using stored credentials
 */
static esp_err_t connect_wifi(void)
{
    char ssid[33] = {0};
    char password[65] = {0};
    
    // Load credentials
    esp_err_t ret = load_wifi_credentials(ssid, password);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to load WiFi credentials");
        return ESP_FAIL;
    }
    
    ESP_LOGI(TAG, "Connecting to WiFi SSID: %s", ssid);
    
    // Configure WiFi
    wifi_config_t wifi_config = {
        .sta = {
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
            .pmf_cfg = {
                .capable = true,
                .required = false
            },
        },
    };
    strlcpy((char *)wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    strlcpy((char *)wifi_config.sta.password, password, sizeof(wifi_config.sta.password));
    
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    
    // Connect to AP using esp_wifi_remote
    esp_err_t err = esp_wifi_remote_connect();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "WiFi connect failed: %s", esp_err_to_name(err));
        return err;
    }
    
    return ESP_OK;
}

/**
 * GPIO button functionality for reconfiguration
 */
#define GPIO_INPUT          CONFIG_EXAMPLE_RECONFIGURE_BUTTON
#define GPIO_LONG_PUSH_US   2000000  /* 2 seconds */

static void IRAM_ATTR gpio_isr_handler(void *arg)
{
    static int64_t last_pushed = -1;
    if (gpio_get_level(GPIO_INPUT) == 0) {
        last_pushed = esp_timer_get_time();
    } else {
        uint64_t now = esp_timer_get_time();
        if (last_pushed != -1 && now - last_pushed > GPIO_LONG_PUSH_US) {
            BaseType_t high_task_wakeup;
            xEventGroupSetBitsFromISR(s_event_flags, RECONFIGURE_BIT, &high_task_wakeup);
            if (high_task_wakeup) {
                portYIELD_FROM_ISR();
            }
        }
        last_pushed = -1;
    }
}

static void gpio_init(void)
{
    gpio_config_t io_conf = { 
        .intr_type = GPIO_INTR_ANYEDGE,
        .pin_bit_mask = (1ULL << GPIO_INPUT),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE
    };
    gpio_config(&io_conf);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(GPIO_INPUT, gpio_isr_handler, NULL);
}

/**
 * Application entry point
 */
void app_main(void)
{
    static __NOINIT_ATTR uint32_t s_reconfigure_requested;
    static const uint32_t RECONFIGURE_REQUEST = 0x1C55AA;

    ESP_LOGI(TAG, "===========================================");
    ESP_LOGI(TAG, "ESP32-P4 + ESP32-C6 L2 Bridge (Official API)");
    ESP_LOGI(TAG, "Using esp_netif_br_glue for L2 bridging");
    ESP_LOGI(TAG, "===========================================");

    /* Check reset reason */
    bool do_provision = false;
    esp_reset_reason_t reason = esp_reset_reason();
    if (reason != ESP_RST_SW) {
        s_reconfigure_requested = 0;
    } else if (s_reconfigure_requested == RECONFIGURE_REQUEST) {
        do_provision = true;
    }

    /* Initialize NVS */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    /* Initialize event loop and flags */
    s_event_flags = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    /* Initialize netif */
    ESP_ERROR_CHECK(esp_netif_init());

    /* Initialize GPIO for reconfiguration button */
    gpio_init();

    /* Check C6 OTA mode */
    if (c6_ota_should_enter_mode()) {
        ESP_LOGW(TAG, "==========================================");
        ESP_LOGW(TAG, "Entering C6 OTA upgrade mode");
        ESP_LOGW(TAG, "==========================================");
        ESP_ERROR_CHECK(c6_ota_start_mode());
        
        while (1) {
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    /* Check provisioning */
    if (do_provision || !is_wifi_provisioned()) {
        ESP_LOGI(TAG, "Starting WiFi configuration portal");
        start_wifi_config_portal(&s_event_flags, PROV_SUCCESS_BIT, PROV_FAIL_BIT);
    } else {
        ESP_LOGI(TAG, "Starting L2 bridge mode");
        
        /* Initialize L2 bridge with official API */
        ESP_ERROR_CHECK(init_l2_bridge());
        
        /* Connect to WiFi */
        if (connect_wifi() != ESP_OK) {
            ESP_LOGW(TAG, "WiFi connection failed, entering provisioning mode");
            xEventGroupSetBits(s_event_flags, RECONFIGURE_BIT);
        } else {
            ESP_LOGI(TAG, "==========================================");
            ESP_LOGI(TAG, "L2 Bridge Active!");
            ESP_LOGI(TAG, "Ethernet <-> Official Bridge <-> WiFi STA");
            ESP_LOGI(TAG, "MAC: %02x:%02x:%02x:%02x:%02x:%02x",
                     s_common_mac[0], s_common_mac[1], s_common_mac[2],
                     s_common_mac[3], s_common_mac[4], s_common_mac[5]);
            ESP_LOGI(TAG, "==========================================");
        }
    }

    /* Wait for events */
    EventBits_t bits = xEventGroupWaitBits(s_event_flags, 
                                           RECONFIGURE_BIT | PROV_SUCCESS_BIT | PROV_FAIL_BIT, 
                                           pdTRUE, pdFALSE, portMAX_DELAY);
    
    if (bits & RECONFIGURE_BIT || bits & PROV_FAIL_BIT) {
        s_reconfigure_requested = RECONFIGURE_REQUEST;
    } else {
        s_reconfigure_requested = 0;
    }

    vTaskDelay(pdMS_TO_TICKS(1000));
    esp_restart();
}
