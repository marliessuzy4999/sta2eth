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
#include "nvs_flash.h"
#include "wifi_remote_sta.h"

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
                                uint8_t *sta_mac)
{
    s_event_flags = event_flags;
    s_connected_bit = connected_bit;
    s_disconnected_bit = disconnected_bit;
    s_sta_mac = sta_mac;

    // Create default WiFi remote STA netif
    esp_wifi_remote_create_default_sta();

    // Initialize WiFi remote
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_remote_init(&cfg));

    // Register event handler
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_REMOTE_EVENT, ESP_EVENT_ANY_ID,
                                               wifi_remote_event_handler, NULL));

    // Get MAC address
    if (s_sta_mac) {
        esp_err_t ret = esp_wifi_remote_get_mac(WIFI_IF_STA, s_sta_mac);
        if (ret != ESP_OK) {
            ESP_LOGW(TAG, "Failed to get WiFi remote MAC: %d", ret);
        }
    }

    // Set mode to STA
    ESP_ERROR_CHECK(esp_wifi_remote_set_mode(WIFI_MODE_STA));

    ESP_LOGI(TAG, "WiFi remote initialized");
    return ESP_OK;
}

esp_err_t wifi_remote_sta_connect(void)
{
    wifi_config_t wifi_cfg;
    
    // Try to get existing config
    if (esp_wifi_remote_get_config(WIFI_IF_STA, &wifi_cfg) != ESP_OK) {
        ESP_LOGW(TAG, "WiFi config not available");
        return ESP_FAIL;
    }

    // Start WiFi
    ESP_ERROR_CHECK(esp_wifi_remote_start());

    // Connect
    esp_err_t ret = esp_wifi_remote_connect();
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
    return esp_wifi_remote_internal_reg_rxcb(WIFI_IF_STA, callback);
}

esp_err_t wifi_remote_unreg_rxcb(void)
{
    return esp_wifi_remote_internal_reg_rxcb(WIFI_IF_STA, NULL);
}

esp_err_t wifi_remote_tx(void *buffer, uint16_t len)
{
    return esp_wifi_remote_internal_tx(WIFI_IF_STA, buffer, len);
}

void wifi_remote_free_rx_buffer(void *buffer)
{
    esp_wifi_remote_internal_free_rx_buffer(buffer);
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
