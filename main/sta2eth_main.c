/*
 * SPDX-FileCopyrightText: 2023-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

/**
 * sta2eth L2 Bridge for ESP32-P4 with ESP32-C6
 * 
 * This bridges WiFi (via C6 over SDIO using esp_wifi_remote) to Ethernet on P4
 */

#include <string.h>
#include <esp_timer.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#include "esp_log.h"
#include "esp_mac.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "wired_iface.h"
#include "wifi_remote_sta.h"
#include "wifi_config_portal.h"

static const char *TAG = "sta2eth_p4c6";

static EventGroupHandle_t s_event_flags;
static bool s_wifi_is_connected = false;
static uint8_t s_sta_mac[6];

const int CONNECTED_BIT = BIT0;
const int DISCONNECTED_BIT = BIT1;
const int RECONFIGURE_BIT = BIT2;
const int PROV_SUCCESS_BIT = BIT3;
const int PROV_FAIL_BIT = BIT4;

/**
 * Ethernet -> WiFi Remote packet path
 */
static esp_err_t wired_recv_callback(void *buffer, uint16_t len, void *ctx)
{
    if (s_wifi_is_connected) {
        mac_spoof(FROM_WIRED, buffer, len, s_sta_mac);
        if (wifi_remote_tx(buffer, len) != ESP_OK) {
            ESP_LOGD(TAG, "Failed to send packet to WiFi remote!");
        }
    }
    return ESP_OK;
}

/**
 * Free WiFi remote RX buffer
 */
static void wifi_buff_free(void *buffer, void *ctx)
{
    wifi_remote_free_rx_buffer(buffer);
}

/**
 * WiFi Remote -> Ethernet packet path
 */
static esp_err_t wifi_recv_callback(void *buffer, uint16_t len, void *eb)
{
    mac_spoof(TO_WIRED, buffer, len, s_sta_mac);
    if (wired_send(buffer, len, eb) != ESP_OK) {
        wifi_remote_free_rx_buffer(eb);
        ESP_LOGD(TAG, "Failed to send packet to Ethernet!");
    }
    return ESP_OK;
}

/**
 * Monitor WiFi connection status and register RX callback
 */
static void connection_monitor_task(void *arg)
{
    while (1) {
        EventBits_t bits = xEventGroupWaitBits(s_event_flags, 
                                               CONNECTED_BIT | DISCONNECTED_BIT,
                                               pdFALSE, pdFALSE, portMAX_DELAY);
        
        if (bits & CONNECTED_BIT) {
            if (!s_wifi_is_connected) {
                ESP_LOGI(TAG, "WiFi Remote connected - registering RX callback");
                wifi_remote_reg_rxcb(wifi_recv_callback);
                s_wifi_is_connected = true;
            }
        }
        
        if (bits & DISCONNECTED_BIT) {
            if (s_wifi_is_connected) {
                ESP_LOGI(TAG, "WiFi Remote disconnected - unregistering RX callback");
                wifi_remote_unreg_rxcb();
                s_wifi_is_connected = false;
            }
        }
        
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * Connect to WiFi via remote
 */
static esp_err_t connect_wifi(void)
{
    return wifi_remote_sta_connect();
}

/**
 * GPIO button functionality for reconfiguration
 */
#define GPIO_INPUT          CONFIG_EXAMPLE_RECONFIGURE_BUTTON
#define GPIO_LONG_PUSH_US   2000000  /* push for 2 seconds to reconfigure */

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

    ESP_LOGI(TAG, "ESP32-P4 sta2eth bridge with ESP32-C6 starting...");

    /* Check reset reason and decide if we should re-provision */
    bool do_provision = false;
    esp_reset_reason_t reason = esp_reset_reason();
    ESP_LOGD(TAG, "Reset reason: %d", reason);
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

    /* Initialize event loop and event flags */
    s_event_flags = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* Initialize WiFi remote (connects to C6 via SDIO) */
    ESP_LOGI(TAG, "Initializing WiFi remote (C6 via SDIO)...");
    ESP_ERROR_CHECK(wifi_remote_sta_init(s_event_flags, CONNECTED_BIT, 
                                         DISCONNECTED_BIT, s_sta_mac));

    /* Initialize GPIO button for reconfiguration */
    gpio_init();

    /* Start the application in configuration mode or bridge mode */
    if (do_provision || !is_wifi_provisioned()) {
        ESP_LOGI(TAG, "Starting WiFi configuration portal (SoftAP mode)");
        ESP_ERROR_CHECK(esp_netif_init());
        
        // Start configuration portal using SoftAP on C6
        start_wifi_config_portal(&s_event_flags, PROV_SUCCESS_BIT, PROV_FAIL_BIT);
    } else {
        ESP_LOGI(TAG, "Starting bridge mode (Ethernet <-> WiFi via C6)");
        
        // Connect to WiFi via C6
        if (connect_wifi() != ESP_OK) {
            // If we cannot connect, try to re-provision
            ESP_LOGW(TAG, "WiFi connection failed, entering provisioning mode");
            xEventGroupSetBits(s_event_flags, RECONFIGURE_BIT);
        } else {
            // Start the Ethernet interface in bridge mode
            wired_bridge_init(wired_recv_callback, wifi_buff_free);
            
            // Create task to monitor connection and manage RX callback
            xTaskCreate(connection_monitor_task, "conn_monitor", 2048, NULL, 5, NULL);
            
            ESP_LOGI(TAG, "Bridge active: Ethernet (P4) <-> SDIO <-> WiFi (C6)");
        }
    }

    /* Wait for reconfiguration request or provisioning result */
    EventBits_t bits = xEventGroupWaitBits(s_event_flags, 
                                           RECONFIGURE_BIT | PROV_SUCCESS_BIT | PROV_FAIL_BIT, 
                                           pdTRUE, pdFALSE, portMAX_DELAY);
    
    if (bits & RECONFIGURE_BIT || bits & PROV_FAIL_BIT) {
        // Retry provisioning if it failed or was requested
        s_reconfigure_requested = RECONFIGURE_REQUEST;
    } else {
        // Provisioning succeeded, restart to bridge mode
        s_reconfigure_requested = 0;
    }

    vTaskDelay(pdMS_TO_TICKS(1000));  // Allow httpd to handle closure
    esp_restart();
}
