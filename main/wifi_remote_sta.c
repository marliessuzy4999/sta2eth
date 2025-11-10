/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

/**
 * WiFi Remote Station - Separate compilation unit for esp_wifi_remote
 * 
 * IMPORTANT: This file must be compiled separately from main sta2eth code
 * because esp_wifi_remote uses different type definitions than native WiFi
 */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

// Include injected headers BEFORE esp_wifi_remote.h to use SLAVE_ types
#include "injected/esp_wifi.h"
#include "esp_wifi_remote.h"

#include "esp_event.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "esp_private/wifi.h"  // For esp_wifi_internal_* APIs
#include "nvs_flash.h"
#include "wifi_remote_sta.h"
#include "wifi_config_portal.h"  // For credential management

static const char *TAG = "wifi_remote_sta";

static EventGroupHandle_t s_event_flags = NULL;
static int s_connected_bit = 0;
static int s_disconnected_bit = 0;
static uint8_t *s_sta_mac = NULL;

/**
 * Event handler for WiFi Remote events
 */
static void wifi_remote_event_handler(void *arg, esp_event_base_t event_base,
                                      int32_t event_id, void *event_data)
{
    if (event_base == WIFI_REMOTE_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        ESP_LOGI(TAG, "WiFi Remote STA disconnected");
        if (s_event_flags) {
            xEventGroupClearBits(s_event_flags, s_connected_bit);
            xEventGroupSetBits(s_event_flags, s_disconnected_bit);
        }
        // Try to reconnect
        esp_wifi_remote_connect();
    } else if (event_base == WIFI_REMOTE_EVENT && event_id == WIFI_EVENT_STA_CONNECTED) {
        ESP_LOGI(TAG, "WiFi Remote STA connected");
        if (s_event_flags) {
            xEventGroupClearBits(s_event_flags, s_disconnected_bit);
            xEventGroupSetBits(s_event_flags, s_connected_bit);
        }
    }
}

esp_err_t wifi_remote_sta_init(EventGroupHandle_t event_flags,
                                int connected_bit,
                                int disconnected_bit,
                                uint8_t *sta_mac,
                                const uint8_t *eth_mac)
{
    s_event_flags = event_flags;
    s_connected_bit = connected_bit;
    s_disconnected_bit = disconnected_bit;
    s_sta_mac = sta_mac;

    // Create WiFi STA netif with DHCP disabled (static IP for L2 bridging)
    esp_netif_inherent_config_t netif_cfg = ESP_NETIF_INHERENT_DEFAULT_WIFI_STA();
    netif_cfg.flags &= ~ESP_NETIF_DHCP_CLIENT;  // Disable DHCP client
    esp_netif_config_t cfg_sta = {
        .base = &netif_cfg,
        .stack = ESP_NETIF_NETSTACK_DEFAULT_WIFI_STA,
    };
    esp_netif_t *sta_netif = esp_netif_new(&cfg_sta);
    esp_netif_attach_wifi_station(sta_netif);
    
    // Assign link-local static IP to prevent DHCP client from running
    // Using 169.254.0.1 (RFC 3927 link-local) - never routed, no network conflicts
    // This IP is just for netif initialization - L2 frames are bridged transparently
    esp_netif_dhcpc_stop(sta_netif);
    esp_netif_ip_info_t ip_info = {
        .ip = { .addr = ESP_IP4TOADDR(169, 254, 0, 1) },
        .gw = { .addr = ESP_IP4TOADDR(169, 254, 0, 1) },
        .netmask = { .addr = ESP_IP4TOADDR(255, 255, 0, 0) },
    };
    esp_netif_set_ip_info(sta_netif, &ip_info);

    // Initialize WiFi - esp_wifi_remote transparently forwards to C6
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_remote_init(&cfg));

    // Register event handler for WiFi remote events
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_REMOTE_EVENT, ESP_EVENT_ANY_ID,
                                               wifi_remote_event_handler, NULL));

    // Set mode to STA BEFORE setting MAC - regular esp_wifi API
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    
    // CRITICAL: Set WiFi STA MAC = Ethernet MAC for transparent L2 bridging
    // This allows WiFi STA to receive packets destined for the Ethernet device
    // Without this, WiFi STA only receives packets destined to its own default MAC
    if (eth_mac) {
        ESP_LOGI(TAG, "Setting WiFi STA MAC to match Ethernet MAC: %02x:%02x:%02x:%02x:%02x:%02x",
                 eth_mac[0], eth_mac[1], eth_mac[2], eth_mac[3], eth_mac[4], eth_mac[5]);
        esp_err_t ret = esp_wifi_set_mac(WIFI_IF_STA, eth_mac);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to set WiFi STA MAC: %s", esp_err_to_name(ret));
            return ret;
        }
        // Update our MAC buffer with the set MAC
        if (s_sta_mac) {
            memcpy(s_sta_mac, eth_mac, 6);
        }
    } else {
        // Get default MAC address if not setting custom one
        if (s_sta_mac) {
            esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, s_sta_mac);
            if (ret != ESP_OK) {
                ESP_LOGW(TAG, "Failed to get WiFi MAC: %d", ret);
            }
        }
    }
    
    // Set WiFi TX power to maximum (20.5 dBm = 82 * 0.25 dBm for ESP32-C6)
    // ESP32-C6 max power: 20.5 dBm (82 in units of 0.25 dBm)
    // This improves WiFi range and signal strength
    int8_t max_power = 82;  // 20.5 dBm for C6
    esp_err_t power_ret = esp_wifi_set_max_tx_power(max_power);
    if (power_ret == ESP_OK) {
        ESP_LOGI(TAG, "WiFi TX power set to maximum: %d (%.1f dBm)", 
                 max_power, max_power * 0.25);
    } else {
        ESP_LOGW(TAG, "Failed to set WiFi TX power: %s", esp_err_to_name(power_ret));
    }
    
    // Clear any stored credentials on C6 to ensure clean state
    // Set storage to flash temporarily to clear, then back to RAM for runtime
    ESP_LOGI(TAG, "Clearing any stored credentials on C6");
    esp_wifi_set_storage(WIFI_STORAGE_FLASH);
    wifi_config_t empty_cfg = {0};
    esp_wifi_set_config(WIFI_IF_STA, &empty_cfg);
    
    // Set storage back to RAM only for runtime operation
    esp_wifi_set_storage(WIFI_STORAGE_RAM);

    ESP_LOGI(TAG, "WiFi remote initialized (C6 credentials cleared, will use P4's NVS)");
    return ESP_OK;
}

esp_err_t wifi_remote_sta_connect(void)
{
    char ssid[33] = {0};
    char password[65] = {0};
    
    // Load credentials from P4's NVS
    esp_err_t ret = load_wifi_credentials(ssid, password);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to load WiFi credentials from P4's NVS");
        return ESP_FAIL;
    }
    
    ESP_LOGI(TAG, "Loaded credentials from P4's NVS, setting to C6 (RAM only)");
    
    // Configure WiFi credentials for C6 (in RAM only, not flash)
    wifi_config_t wifi_cfg = {0};
    strlcpy((char *)wifi_cfg.sta.ssid, ssid, sizeof(wifi_cfg.sta.ssid));
    strlcpy((char *)wifi_cfg.sta.password, password, sizeof(wifi_cfg.sta.password));
    
    // Set storage to RAM only - DO NOT save to C6's flash
    ret = esp_wifi_set_storage(WIFI_STORAGE_RAM);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set WiFi storage to RAM: %s", esp_err_to_name(ret));
        return ret;
    }
    
    // Set configuration in C6's RAM
    ret = esp_wifi_set_config(WIFI_IF_STA, &wifi_cfg);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set WiFi config: %s", esp_err_to_name(ret));
        return ret;
    }

    // Start WiFi - regular esp_wifi API
    ESP_ERROR_CHECK(esp_wifi_start());
    
    // Ensure TX power is at maximum after WiFi start
    // Re-apply in case WiFi start resets power settings
    int8_t max_power = 82;  // 20.5 dBm for C6
    esp_wifi_set_max_tx_power(max_power);
    ESP_LOGI(TAG, "WiFi TX power confirmed at maximum after start");

    // Connect - regular esp_wifi API
    ret = esp_wifi_connect();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to connect: %d", ret);
        return ret;
    }

    // Wait for connection (with timeout)
    EventBits_t status = xEventGroupWaitBits(s_event_flags, s_connected_bit, 
                                             0, 1, 10000 / portTICK_PERIOD_MS);
    if (status & s_connected_bit) {
        ESP_LOGI(TAG, "WiFi remote station connected successfully");
        return ESP_OK;
    }

    ESP_LOGE(TAG, "WiFi remote station connection timeout");
    return ESP_ERR_TIMEOUT;
}

bool wifi_remote_is_provisioned(void)
{
    wifi_config_t wifi_cfg;
    if (esp_wifi_remote_get_config(WIFI_IF_STA, &wifi_cfg) != ESP_OK) {
        return false;
    }
    
    // Check if SSID is configured
    return (wifi_cfg.sta.ssid[0] != 0);
}

esp_err_t wifi_remote_reg_rxcb(void *callback)
{
    // Use esp_wifi internal API through remote - works the same way as native WiFi
    return esp_wifi_internal_reg_rxcb(WIFI_IF_STA, callback);
}

esp_err_t wifi_remote_unreg_rxcb(void)
{
    return esp_wifi_internal_reg_rxcb(WIFI_IF_STA, NULL);
}

esp_err_t wifi_remote_tx(void *buffer, uint16_t len)
{
    // Use esp_wifi internal API through remote - works for L2 frame transmission
    return esp_wifi_internal_tx(WIFI_IF_STA, buffer, len);
}

void wifi_remote_free_rx_buffer(void *buffer)
{
    esp_wifi_internal_free_rx_buffer(buffer);
}

esp_err_t wifi_remote_set_config(const char *ssid, const char *password)
{
    wifi_config_t wifi_config = {0};
    
    strlcpy((char *)wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    if (password) {
        strlcpy((char *)wifi_config.sta.password, password, sizeof(wifi_config.sta.password));
    }
    
    esp_err_t ret = esp_wifi_remote_set_storage(WIFI_STORAGE_FLASH);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set storage: %d", ret);
        return ret;
    }
    
    ret = esp_wifi_remote_set_config(WIFI_IF_STA, &wifi_config);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set config: %d", ret);
        return ret;
    }
    
    ESP_LOGI(TAG, "WiFi configuration saved: SSID=%s", ssid);
    return ESP_OK;
}
