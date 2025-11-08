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

// Traffic activity counters for stall detection
static volatile uint32_t s_eth_rx_total = 0;
static volatile uint32_t s_wifi_rx_total = 0;

/**
 * Ethernet -> WiFi Remote packet path (with PSRAM buffering)
 */
static esp_err_t wired_recv_callback(void *buffer, uint16_t len, void *ctx)
{
    static uint32_t eth_rx_count = 0;
    eth_rx_count++;
    s_eth_rx_total++;  // Track for stall detection
    
    // Log every 100th packet to reduce spam and avoid deadlock
    if (eth_rx_count % 100 == 1) {
        ESP_LOGI(TAG, "ETH RX: count=%lu, len=%d, wifi_connected=%d", eth_rx_count, len, s_wifi_is_connected);
    }
    
    if (!s_wifi_is_connected) {
        // Only log first few times
        if (eth_rx_count < 5) {
            ESP_LOGW(TAG, "WiFi not connected, dropping Ethernet packet");
        }
        return ESP_OK;
    }
    
    // Allocate packet buffer from ETH->WiFi independent pool
    packet_buffer_t *pkt = packet_pool_alloc(len, POOL_ETH_TO_WIFI);
    if (!pkt) {
        // Pool exhausted - log every 100th occurrence
        static uint32_t pool_exhausted = 0;
        if (++pool_exhausted % 100 == 1) {
            ESP_LOGW(TAG, "ETH->WiFi pool exhausted %lu times", pool_exhausted);
        }
        return ESP_ERR_NO_MEM;
    }
    
    // Copy packet data
    memcpy(pkt->data, buffer, len);
    pkt->len = len;
    
    // Apply MAC spoofing
    mac_spoof(FROM_WIRED, pkt->data, pkt->len, s_sta_mac);
    
    // Enqueue for transmission (with flow control)
    esp_err_t ret = packet_queue_enqueue(&s_eth_to_wifi_queue, pkt);
    if (ret != ESP_OK) {
        // Queue full, drop packet
        packet_pool_free(pkt);
        // Error already logged in enqueue function (every 100th)
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
    static uint32_t wifi_rx_count = 0;
    wifi_rx_count++;
    s_wifi_rx_total++;  // Track for stall detection
    
    // Log every 100th packet to reduce spam and avoid deadlock
    if (wifi_rx_count % 100 == 1) {
        ESP_LOGI(TAG, "WiFi RX: count=%lu, len=%d", wifi_rx_count, len);
    }
    
    // Allocate packet buffer from WiFi->ETH independent pool
    packet_buffer_t *pkt = packet_pool_alloc(len, POOL_WIFI_TO_ETH);
    if (!pkt) {
        // Pool exhausted - log every 100th occurrence
        static uint32_t pool_exhausted = 0;
        if (++pool_exhausted % 100 == 1) {
            ESP_LOGW(TAG, "WiFi->ETH pool exhausted %lu times", pool_exhausted);
        }
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
    esp_err_t ret = packet_queue_enqueue(&s_wifi_to_eth_queue, pkt);
    if (ret != ESP_OK) {
        // Queue full, drop packet
        wifi_remote_free_rx_buffer(eb);
        packet_pool_free(pkt);
        // Error already logged in enqueue function (every 100th)
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
    uint32_t tx_count = 0;
    uint32_t tx_error_count = 0;
    
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
        
        tx_count++;
        
        // Log every 100th packet to reduce spam
        if (tx_count % 100 == 1) {
            ESP_LOGI(TAG, "ETH->WiFi TX: count=%lu, len=%d", tx_count, pkt->len);
        }
        
        // Rate limiting to prevent overwhelming C6
        TickType_t now = xTaskGetTickCount();
        if (now - last_tx_time < min_interval) {
            vTaskDelay(min_interval - (now - last_tx_time));
        }
        
        // Send to WiFi via remote
        esp_err_t ret = wifi_remote_tx(pkt->data, pkt->len);
        if (ret != ESP_OK) {
            tx_error_count++;
            // Log errors every 10th occurrence
            if (tx_error_count % 10 == 1) {
                ESP_LOGW(TAG, "WiFi TX failed %lu times, last error: %d", tx_error_count, ret);
            }
        }
        
        last_tx_time = xTaskGetTickCount();
        
        // Free packet buffer
        packet_pool_free(pkt);
    }
}

/**
 * WiFi → Ethernet forwarding task with rate limiting
 */
static void wifi_to_eth_task(void *arg)
{
    TickType_t last_tx_time = 0;
    const TickType_t min_interval = pdMS_TO_TICKS(1);  // Rate limiting: min 1ms between packets
    uint32_t tx_count = 0;
    uint32_t tx_error_count = 0;
    uint32_t retry_count = 0;
    
    ESP_LOGI(TAG, "WiFi→Eth forwarding task started");
    
    while (1) {
        // Dequeue packet
        packet_buffer_t *pkt = packet_queue_dequeue(&s_wifi_to_eth_queue);
        if (!pkt) {
            vTaskDelay(pdMS_TO_TICKS(1));
            continue;
        }
        
        tx_count++;
        
        // Log every 100th packet to reduce spam
        if (tx_count % 100 == 1) {
            ESP_LOGI(TAG, "WiFi->ETH TX: count=%lu, len=%d", tx_count, pkt->len);
        }
        
        // Rate limiting to prevent overwhelming Ethernet driver
        TickType_t now = xTaskGetTickCount();
        if (now - last_tx_time < min_interval) {
            vTaskDelay(min_interval - (now - last_tx_time));
        }
        
        // Send to Ethernet with retry on failure
        esp_err_t ret = wired_send(pkt->data, pkt->len, pkt->free_arg);
        if (ret != ESP_OK) {
            // Retry once after a short delay (Ethernet TX queue might be full)
            retry_count++;
            vTaskDelay(pdMS_TO_TICKS(2));  // 2ms delay before retry
            ret = wired_send(pkt->data, pkt->len, pkt->free_arg);
            
            if (ret != ESP_OK) {
                tx_error_count++;
                // Log errors every 10th occurrence
                if (tx_error_count % 10 == 1) {
                    ESP_LOGW(TAG, "Ethernet TX failed %lu times (retries: %lu), last error: %d", 
                             tx_error_count, retry_count, ret);
                }
                // Free WiFi buffer on failure
                if (pkt->free_arg) {
                    wifi_remote_free_rx_buffer(pkt->free_arg);
                }
            }
        }
        
        last_tx_time = xTaskGetTickCount();
        
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
                esp_err_t ret = wifi_remote_reg_rxcb(wifi_recv_callback);
                ESP_LOGI(TAG, "RX callback registration result: %d", ret);
                s_wifi_is_connected = true;
                // Clear the bit to avoid re-processing
                xEventGroupClearBits(s_event_flags, CONNECTED_BIT);
            }
        }
        
        if (bits & DISCONNECTED_BIT) {
            if (s_wifi_is_connected) {
                ESP_LOGW(TAG, "WiFi Remote disconnected - unregistering RX callback");
                wifi_remote_unreg_rxcb();
                s_wifi_is_connected = false;
                // Clear the bit to avoid re-processing
                xEventGroupClearBits(s_event_flags, DISCONNECTED_BIT);
            }
        }
        
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * Statistics logging task with health monitoring
 */
static void stats_task(void *arg)
{
    static uint32_t last_eth_queue_count = 0;
    static uint32_t last_wifi_queue_count = 0;
    static uint32_t last_eth_rx_total = 0;
    static uint32_t last_wifi_rx_total = 0;
    static uint32_t stall_count = 0;
    static uint32_t no_traffic_count = 0;
    uint32_t log_count = 0;
    
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(10000));  // Every 10 seconds
        log_count++;
        
        // Get stats for ETH->WiFi pool
        uint32_t eth_total, eth_free, eth_used;
        packet_pool_get_stats(POOL_ETH_TO_WIFI, &eth_total, &eth_free, &eth_used);
        
        // Get stats for WiFi->ETH pool
        uint32_t wifi_total, wifi_free, wifi_used;
        packet_pool_get_stats(POOL_WIFI_TO_ETH, &wifi_total, &wifi_free, &wifi_used);
        
        uint32_t eth_queue_count, eth_queue_dropped;
        packet_queue_get_stats(&s_eth_to_wifi_queue, &eth_queue_count, &eth_queue_dropped);
        
        uint32_t wifi_queue_count, wifi_queue_dropped;
        packet_queue_get_stats(&s_wifi_to_eth_queue, &wifi_queue_count, &wifi_queue_dropped);
        
        // Get current RX counts
        uint32_t curr_eth_rx = s_eth_rx_total;
        uint32_t curr_wifi_rx = s_wifi_rx_total;
        
        // Only log stats every 60 seconds (every 6th check) to reduce log spam
        if (log_count % 6 == 0) {
            ESP_LOGI(TAG, "Pool Stats: ETH->WiFi=%lu/%lu Queue=%lu(drop=%lu) | WiFi->ETH=%lu/%lu Queue=%lu(drop=%lu)",
                     eth_used, eth_total, eth_queue_count, eth_queue_dropped,
                     wifi_used, wifi_total, wifi_queue_count, wifi_queue_dropped);
        }
        
        // Health check: detect if pool is getting exhausted (only log warnings)
        if (eth_used > eth_total * 80 / 100) {
            ESP_LOGW(TAG, "ETH->WiFi pool high: %lu/%lu (%.0f%%)", 
                     eth_used, eth_total, (float)eth_used * 100 / eth_total);
        }
        if (wifi_used > wifi_total * 80 / 100) {
            ESP_LOGW(TAG, "WiFi->ETH pool high: %lu/%lu (%.0f%%)", 
                     wifi_used, wifi_total, (float)wifi_used * 100 / wifi_total);
        }
        
        // Detect stalls - if queues haven't changed for multiple intervals
        if (eth_queue_count == last_eth_queue_count && wifi_queue_count == last_wifi_queue_count) {
            if (eth_queue_count > 0 || wifi_queue_count > 0) {
                stall_count++;
                if (stall_count >= 3) {  // Stalled for 30+ seconds
                    ESP_LOGE(TAG, "QUEUE STALL! Queues frozen for %lus, WiFi connected=%d", 
                             stall_count * 10, s_wifi_is_connected);
                }
            } else {
                stall_count = 0;  // Queues are empty, that's normal
            }
        } else {
            stall_count = 0;  // Queues are changing, system is healthy
        }
        
        // Detect complete traffic stop - NO RX callbacks at all
        if (curr_eth_rx == last_eth_rx_total && curr_wifi_rx == last_wifi_rx_total) {
            no_traffic_count++;
            if (no_traffic_count >= 3) {  // No traffic for 30+ seconds
                ESP_LOGE(TAG, "TRAFFIC STOPPED! No RX for %lus - ETH_RX=%lu WiFi_RX=%lu WiFi_connected=%d", 
                         no_traffic_count * 10, curr_eth_rx, curr_wifi_rx, s_wifi_is_connected);
            }
        } else {
            no_traffic_count = 0;  // Traffic is flowing
        }
        
        last_eth_queue_count = eth_queue_count;
        last_wifi_queue_count = wifi_queue_count;
        last_eth_rx_total = curr_eth_rx;
        last_wifi_rx_total = curr_wifi_rx;
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
        
        /* Initialize WiFi remote in STA mode (connects to C6 via SDIO) */
        ESP_LOGI(TAG, "Initializing WiFi remote (C6 via SDIO)...");
        ESP_ERROR_CHECK(wifi_remote_sta_init(s_event_flags, CONNECTED_BIT, 
                                             DISCONNECTED_BIT, s_sta_mac));
        
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
