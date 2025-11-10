/*
 * Minimal sta2eth implementation based on eth2ap example
 * For testing purposes - hardcoded WiFi credentials
 * 
 * This is a simplified version to isolate driver vs code issues
 */
#include <string.h>
#include <stdlib.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_eth_driver.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_private/wifi.h"
#include "ethernet_init.h"

static const char *TAG = "minimal_sta2eth";
static esp_eth_handle_t s_eth_handle = NULL;
static QueueHandle_t eth2wifi_queue = NULL;
static QueueHandle_t wifi2eth_queue = NULL;
static bool s_sta_is_connected = false;
static bool s_ethernet_is_connected = false;

// Hardcoded WiFi credentials for testing
#define TEST_WIFI_SSID "xinxin"
#define TEST_WIFI_PASSWORD "19840226"

#define FLOW_CONTROL_QUEUE_TIMEOUT_MS (100)
#define FLOW_CONTROL_QUEUE_LENGTH (40)
#define FLOW_CONTROL_WIFI_SEND_TIMEOUT_MS (100)

typedef struct {
    void *packet;
    uint16_t length;
} flow_control_msg_t;

// Forward packets from WiFi to Ethernet (WiFi RX callback)
static esp_err_t pkt_wifi2eth(void *buffer, uint16_t len, void *eb)
{
    if (s_ethernet_is_connected && len > 0) {
        // For simplicity, send directly without queue (like eth2ap wifi2eth does)
        if (esp_eth_transmit(s_eth_handle, buffer, len) != ESP_OK) {
            ESP_LOGE(TAG, "Ethernet send packet failed");
        }
    }
    // WiFi buffer must be freed immediately
    esp_wifi_internal_free_rx_buffer(eb);
    return ESP_OK;
}

// Forward packets from Ethernet to WiFi (Ethernet RX callback)
static esp_err_t pkt_eth2wifi(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t len, void *priv)
{
    esp_err_t ret = ESP_OK;
    flow_control_msg_t msg = {
        .packet = buffer,
        .length = len
    };
    // Use queue for flow control (Ethernet is faster than WiFi/SDIO)
    if (xQueueSend(eth2wifi_queue, &msg, pdMS_TO_TICKS(FLOW_CONTROL_QUEUE_TIMEOUT_MS)) != pdTRUE) {
        ESP_LOGE(TAG, "eth2wifi queue full, dropping packet");
        free(buffer);
        ret = ESP_FAIL;
    }
    return ret;
}

// Task: Ethernet to WiFi with retry (matching eth2ap pattern exactly)
static void eth2wifi_flow_control_task(void *args)
{
    flow_control_msg_t msg;
    int res = 0;
    uint32_t timeout = 0;
    
    while (1) {
        if (xQueueReceive(eth2wifi_queue, &msg, pdMS_TO_TICKS(FLOW_CONTROL_QUEUE_TIMEOUT_MS)) == pdTRUE) {
            timeout = 0;
            if (s_sta_is_connected && msg.length) {
                // Retry loop with progressive backoff (eth2ap pattern)
                do {
                    vTaskDelay(pdMS_TO_TICKS(timeout));
                    timeout += 2;
                    res = esp_wifi_internal_tx(WIFI_IF_STA, msg.packet, msg.length);
                } while (res && timeout < FLOW_CONTROL_WIFI_SEND_TIMEOUT_MS);
                
                if (res != ESP_OK) {
                    ESP_LOGE(TAG, "WiFi send packet failed: %d", res);
                }
            }
            // Always free buffer (eth2ap pattern)
            free(msg.packet);
        }
    }
    vTaskDelete(NULL);
}

// Event handler for Ethernet
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
        s_ethernet_is_connected = true;
        break;
    case ETHERNET_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "Ethernet Link Down");
        s_ethernet_is_connected = false;
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

// Event handler for WiFi
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    switch (event_id) {
    case WIFI_EVENT_STA_START:
        ESP_LOGI(TAG, "WiFi STA started, connecting...");
        esp_wifi_connect();
        break;
    case WIFI_EVENT_STA_CONNECTED:
        ESP_LOGI(TAG, "WiFi STA connected");
        s_sta_is_connected = true;
        // Register RX callback for WiFi→Eth path
        esp_wifi_internal_reg_rxcb(WIFI_IF_STA, pkt_wifi2eth);
        break;
    case WIFI_EVENT_STA_DISCONNECTED:
        ESP_LOGI(TAG, "WiFi STA disconnected, reconnecting...");
        s_sta_is_connected = false;
        esp_wifi_internal_reg_rxcb(WIFI_IF_STA, NULL);
        esp_wifi_connect();
        break;
    default:
        break;
    }
}

static void ip_event_handler(void *arg, esp_event_base_t event_base,
                            int32_t event_id, void *event_data)
{
    if (event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "Got IP address: " IPSTR, IP2STR(&event->ip_info.ip));
    }
}

static void initialize_ethernet(void)
{
    uint8_t eth_port_cnt = 0;
    esp_eth_handle_t *eth_handles;
    
    // Use the same ethernet_init_all function as main sta2eth
    ESP_ERROR_CHECK(ethernet_init_all(&eth_handles, &eth_port_cnt));
    if (eth_port_cnt > 1) {
        ESP_LOGW(TAG, "Multiple Ethernet devices detected, using first one");
    }
    s_eth_handle = eth_handles[0];
    free(eth_handles);
    
    // Set Ethernet RX callback (zero-copy, eth2ap pattern)
    ESP_ERROR_CHECK(esp_eth_update_input_path(s_eth_handle, pkt_eth2wifi, NULL));
    
    // Enable promiscuous mode (matching eth2ap)
    bool eth_promiscuous = true;
    ESP_ERROR_CHECK(esp_eth_ioctl(s_eth_handle, ETH_CMD_S_PROMISCUOUS, &eth_promiscuous));
    
    // Register event handler
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, eth_event_handler, NULL));
    
    // Start Ethernet
    ESP_ERROR_CHECK(esp_eth_start(s_eth_handle));
}

static void initialize_wifi(void)
{
    // Register event handlers
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, ip_event_handler, NULL));
    
    // Initialize WiFi with default config
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    
    // Configure STA mode with hardcoded credentials
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = TEST_WIFI_SSID,
            .password = TEST_WIFI_PASSWORD,
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
        },
    };
    
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    
    ESP_LOGI(TAG, "WiFi initialized - SSID: %s", TEST_WIFI_SSID);
}

static esp_err_t initialize_flow_control(void)
{
    // Create queue for Eth→WiFi path (Ethernet is faster)
    eth2wifi_queue = xQueueCreate(FLOW_CONTROL_QUEUE_LENGTH, sizeof(flow_control_msg_t));
    if (!eth2wifi_queue) {
        ESP_LOGE(TAG, "Failed to create eth2wifi queue");
        return ESP_FAIL;
    }
    
    // Create task for Eth→WiFi with retry logic (matching eth2ap: 2KB stack, priority tskIDLE_PRIORITY+2)
    BaseType_t ret = xTaskCreate(eth2wifi_flow_control_task, "flow_ctl_eth", 2048, NULL, (tskIDLE_PRIORITY + 2), NULL);
    if (ret != pdTRUE) {
        ESP_LOGE(TAG, "Failed to create flow control task");
        return ESP_FAIL;
    }
    
    ESP_LOGI(TAG, "Flow control initialized (eth2ap pattern)");
    return ESP_OK;
}

void app_main(void)
{
    ESP_LOGI(TAG, "=== Minimal sta2eth Test (based on eth2ap) ===");
    ESP_LOGI(TAG, "WiFi: %s / %s", TEST_WIFI_SSID, TEST_WIFI_PASSWORD);
    
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    
    // Initialize event loop
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    // Initialize components (order matters)
    ESP_ERROR_CHECK(initialize_flow_control());
    initialize_wifi();
    initialize_ethernet();
    
    ESP_LOGI(TAG, "Minimal sta2eth bridge started");
    ESP_LOGI(TAG, "Waiting for WiFi connection and Ethernet link...");
}
