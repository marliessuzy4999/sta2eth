/*
 * SPDX-FileCopyrightText: 2023-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

/**
 * sta2eth L2 Bridge for ESP32-P4 with ESP32-C6
 * 
 * This bridges WiFi (via C6 over SDIO using esp_wifi_remote) to Ethernet on P4
 * Uses PSRAM-based large buffers to handle P4-C6 speed mismatch
 */

#include <string.h>
#include <esp_timer.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"

#include "esp_log.h"
#include "esp_mac.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "wired_iface.h"
#include "wifi_remote_sta.h"
#include "wifi_config_portal.h"
#include "packet_buffer_pool.h"

static const char *TAG = "sta2eth_p4c6";

static EventGroupHandle_t s_event_flags;
static bool s_wifi_is_connected = false;
static uint8_t s_sta_mac[6];

// PSRAM packet queues for flow control
static packet_queue_t s_eth_to_wifi_queue;
static packet_queue_t s_wifi_to_eth_queue;

#define MAX_ETH_TO_WIFI_QUEUE   512  // Large PSRAM queue for Ethernet → WiFi
#define MAX_WIFI_TO_ETH_QUEUE   256  // WiFi → Ethernet queue

const int CONNECTED_BIT = BIT0;
const int DISCONNECTED_BIT = BIT1;
const int RECONFIGURE_BIT = BIT2;
const int PROV_SUCCESS_BIT = BIT3;
const int PROV_FAIL_BIT = BIT4;

/**
 * Ethernet -> WiFi Remote packet path (with PSRAM buffering)
 */
static esp_err_t wired_recv_callback(void *buffer, uint16_t len, void *ctx)
{
    if (!s_wifi_is_connected) {
        return ESP_OK;
    }
    
    // Allocate packet buffer from PSRAM pool
    packet_buffer_t *pkt = packet_pool_alloc(len);
    if (!pkt) {
        ESP_LOGD(TAG, "Packet pool exhausted, dropping Ethernet packet");
        return ESP_ERR_NO_MEM;
    }
    
    // Copy packet data
    memcpy(pkt->data, buffer, len);
    pkt->len = len;
    
    // Apply MAC spoofing
    mac_spoof(FROM_WIRED, pkt->data, pkt->len, s_sta_mac);
    
    // Enqueue for transmission (with flow control)
    if (packet_queue_enqueue(&s_eth_to_wifi_queue, pkt) != ESP_OK) {
        // Queue full, drop packet
        packet_pool_free(pkt);
        ESP_LOGD(TAG, "Eth→WiFi queue full, packet dropped");
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
 * WiFi Remote -> Ethernet packet path (with buffering)
 */
static esp_err_t wifi_recv_callback(void *buffer, uint16_t len, void *eb)
{
    // Allocate packet buffer from PSRAM pool
    packet_buffer_t *pkt = packet_pool_alloc(len);
    if (!pkt) {
        ESP_LOGD(TAG, "Packet pool exhausted, dropping WiFi packet");
        wifi_remote_free_rx_buffer(eb);
        return ESP_ERR_NO_MEM;
    }
    
    // Copy packet data
    memcpy(pkt->data, buffer, len);
    pkt->len = len;
    pkt->free_arg = eb;  // Store WiFi buffer for later free
    
    // Apply MAC spoofing
    mac_spoof(TO_WIRED, pkt->data, pkt->len, s_sta_mac);
    
    // Enqueue for transmission
    if (packet_queue_enqueue(&s_wifi_to_eth_queue, pkt) != ESP_OK) {
        // Queue full, drop packet
        wifi_remote_free_rx_buffer(eb);
        packet_pool_free(pkt);
        ESP_LOGD(TAG, "WiFi→Eth queue full, packet dropped");
    }
    
    return ESP_OK;
}

/**
 * Ethernet → WiFi forwarding task with rate limiting
 */
static void eth_to_wifi_task(void *arg)
{
    TickType_t last_tx_time = 0;
    const TickType_t min_interval = pdMS_TO_TICKS(1);  // Rate limiting: min 1ms between packets
    
    ESP_LOGI(TAG, "Eth→WiFi forwarding task started");
    
    while (1) {
        // Check if WiFi is connected
        if (!s_wifi_is_connected) {
            vTaskDelay(pdMS_TO_TICKS(100));
            continue;
        }
        
        // Dequeue packet
        packet_buffer_t *pkt = packet_queue_dequeue(&s_eth_to_wifi_queue);
        if (!pkt) {
            vTaskDelay(pdMS_TO_TICKS(1));
            continue;
        }
        
        // Rate limiting to prevent overwhelming C6
        TickType_t now = xTaskGetTickCount();
        if (now - last_tx_time < min_interval) {
            vTaskDelay(min_interval - (now - last_tx_time));
        }
        
        // Send to WiFi via remote
        esp_err_t ret = wifi_remote_tx(pkt->data, pkt->len);
        if (ret != ESP_OK) {
            ESP_LOGD(TAG, "WiFi TX failed: %d", ret);
        }
        
        last_tx_time = xTaskGetTickCount();
        
        // Free packet buffer
        packet_pool_free(pkt);
    }
}

/**
 * WiFi → Ethernet forwarding task
 */
static void wifi_to_eth_task(void *arg)
{
    ESP_LOGI(TAG, "WiFi→Eth forwarding task started");
    
    while (1) {
        // Dequeue packet
        packet_buffer_t *pkt = packet_queue_dequeue(&s_wifi_to_eth_queue);
        if (!pkt) {
            vTaskDelay(pdMS_TO_TICKS(1));
            continue;
        }
        
        // Send to Ethernet
        esp_err_t ret = wired_send(pkt->data, pkt->len, pkt->free_arg);
        if (ret != ESP_OK) {
            ESP_LOGD(TAG, "Ethernet TX failed: %d", ret);
            // Free WiFi buffer on failure
            if (pkt->free_arg) {
                wifi_remote_free_rx_buffer(pkt->free_arg);
            }
        }
        
        // Free packet buffer
        packet_pool_free(pkt);
    }
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
 * Statistics logging task
 */
static void stats_task(void *arg)
{
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(10000));  // Every 10 seconds
        
        uint32_t total, free, used;
        packet_pool_get_stats(&total, &free, &used);
        
        uint32_t eth_queue_count, eth_queue_dropped;
        packet_queue_get_stats(&s_eth_to_wifi_queue, &eth_queue_count, &eth_queue_dropped);
        
        uint32_t wifi_queue_count, wifi_queue_dropped;
        packet_queue_get_stats(&s_wifi_to_eth_queue, &wifi_queue_count, &wifi_queue_dropped);
        
        ESP_LOGI(TAG, "Stats: Pool=%lu/%lu used, Eth→WiFi Q=%lu(-%lu), WiFi→Eth Q=%lu(-%lu)",
                 used, total, eth_queue_count, eth_queue_dropped,
                 wifi_queue_count, wifi_queue_dropped);
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

    /* Initialize PSRAM packet buffer pool */
    ESP_LOGI(TAG, "Initializing PSRAM packet buffer pool...");
    ESP_ERROR_CHECK(packet_pool_init());
    
    /* Initialize packet queues */
    ESP_ERROR_CHECK(packet_queue_init(&s_eth_to_wifi_queue, MAX_ETH_TO_WIFI_QUEUE));
    ESP_ERROR_CHECK(packet_queue_init(&s_wifi_to_eth_queue, MAX_WIFI_TO_ETH_QUEUE));

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
            
            // Create packet forwarding tasks (high priority)
            xTaskCreate(eth_to_wifi_task, "eth2wifi", 4096, NULL, 10, NULL);
            xTaskCreate(wifi_to_eth_task, "wifi2eth", 4096, NULL, 10, NULL);
            
            // Create connection monitor task
            xTaskCreate(connection_monitor_task, "conn_monitor", 2048, NULL, 5, NULL);
            
            // Create statistics task
            xTaskCreate(stats_task, "stats", 2048, NULL, 3, NULL);
            
            ESP_LOGI(TAG, "Bridge active: Ethernet (P4) <-> PSRAM Queue <-> SDIO <-> WiFi (C6)");
            ESP_LOGI(TAG, "PSRAM buffering enabled for speed mismatch handling");
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
