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

// Queue sizes can be large - queues only store pointers (in internal RAM)
// Actual packet data is in PSRAM buffer pools
#define MAX_ETH_TO_WIFI_QUEUE   2048  // Large queue for Ethernet → WiFi (pointers only, ~32KB RAM)
#define MAX_WIFI_TO_ETH_QUEUE   2048  // WiFi → Ethernet queue (pointers only, ~32KB RAM, prevents SDIO crash)

const int CONNECTED_BIT = BIT0;
const int DISCONNECTED_BIT = BIT1;
const int RECONFIGURE_BIT = BIT2;
const int PROV_SUCCESS_BIT = BIT3;
const int PROV_FAIL_BIT = BIT4;

// Traffic statistics structure
typedef struct {
    uint32_t eth_rx_count;
    uint32_t eth_rx_bytes;
    uint32_t eth_to_wifi_tx_count;
    uint32_t eth_to_wifi_tx_bytes;
    uint32_t eth_to_wifi_tx_errors;
    uint32_t eth_to_wifi_retries;       // Added for retry tracking
    uint32_t eth_to_wifi_pool_exhausted;
    uint32_t eth_to_wifi_queue_full;
    
    uint32_t wifi_rx_count;
    uint32_t wifi_rx_bytes;
    uint32_t wifi_to_eth_tx_count;
    uint32_t wifi_to_eth_tx_bytes;
    uint32_t wifi_to_eth_tx_errors;
    uint32_t wifi_to_eth_retries;
    uint32_t wifi_to_eth_pool_exhausted;
    uint32_t wifi_to_eth_queue_full;
} traffic_stats_t;

static traffic_stats_t s_stats = {0};
static traffic_stats_t s_stats_last = {0};

// Traffic activity counters for stall detection
static volatile uint32_t s_eth_rx_total = 0;
static volatile uint32_t s_wifi_rx_total = 0;
static volatile uint32_t s_last_eth_rx_check = 0;
static volatile uint32_t s_last_wifi_rx_check = 0;
static volatile TickType_t s_last_activity_time = 0;

// Memory monitoring thresholds (bytes)
#define INTERNAL_RAM_WARNING_THRESHOLD  (20 * 1024)   // Warn when <20KB internal RAM free
#define PSRAM_WARNING_THRESHOLD         (1024 * 1024) // Warn when <1MB PSRAM free

// SDIO stall detection threshold (ms)
#define SDIO_STALL_THRESHOLD_MS (5000)  // Warn if no activity for 5 seconds during data transfer

/**
 * Ethernet -> WiFi Remote packet path (with PSRAM buffering)
 */
static esp_err_t wired_recv_callback(void *buffer, uint16_t len, void *ctx)
{
    s_stats.eth_rx_count++;
    s_stats.eth_rx_bytes += len;
    s_eth_rx_total++;  // Track for stall detection
    
    if (!s_wifi_is_connected) {
        return ESP_OK;
    }
    
    // Allocate packet buffer from ETH->WiFi independent pool
    packet_buffer_t *pkt = packet_pool_alloc(len, POOL_ETH_TO_WIFI);
    if (!pkt) {
        s_stats.eth_to_wifi_pool_exhausted++;
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
        s_stats.eth_to_wifi_queue_full++;
        packet_pool_free(pkt);
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
    s_stats.wifi_rx_count++;
    s_stats.wifi_rx_bytes += len;
    s_wifi_rx_total++;  // Track for stall detection
    s_last_activity_time = xTaskGetTickCount();  // Update activity timestamp
    
    // Allocate packet buffer from WiFi->ETH independent pool
    packet_buffer_t *pkt = packet_pool_alloc(len, POOL_WIFI_TO_ETH);
    if (!pkt) {
        s_stats.wifi_to_eth_pool_exhausted++;
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
        s_stats.wifi_to_eth_queue_full++;
        wifi_remote_free_rx_buffer(eb);
        packet_pool_free(pkt);
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
        
        s_stats.eth_to_wifi_tx_count++;
        s_stats.eth_to_wifi_tx_bytes += pkt->len;
        
        // Rate limiting to prevent overwhelming C6
        TickType_t now = xTaskGetTickCount();
        if (now - last_tx_time < min_interval) {
            vTaskDelay(min_interval - (now - last_tx_time));
        }
        
        // Send to WiFi via remote with retries (now we have large PSRAM buffers, can afford retries)
        esp_err_t ret = ESP_FAIL;
        const int max_retries = 20;  // Increased from 0 to 20 due to large PSRAM buffer capacity
        
        for (int retry = 0; retry < max_retries; retry++) {
            ret = wifi_remote_tx(pkt->data, pkt->len);
            if (ret == ESP_OK) {
                break;  // Success
            }
            
            // Count retry attempts
            if (retry > 0) {
                s_stats.eth_to_wifi_retries++;
            }
            
            // Short delay before retry (let SDIO/WiFi process backlog)
            vTaskDelay(pdMS_TO_TICKS(2));
        }
        
        if (ret != ESP_OK) {
            s_stats.eth_to_wifi_tx_errors++;
            // NOTE: Ethernet RX packets don't have free_arg, so no additional cleanup needed
        }
        
        last_tx_time = xTaskGetTickCount();
        
        // Free packet buffer (Ethernet path doesn't use free_arg)
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
    
    ESP_LOGI(TAG, "WiFi→Eth forwarding task started");
    
    while (1) {
        // Dequeue packet
        packet_buffer_t *pkt = packet_queue_dequeue(&s_wifi_to_eth_queue);
        if (!pkt) {
            vTaskDelay(pdMS_TO_TICKS(1));
            continue;
        }
        
        s_stats.wifi_to_eth_tx_count++;
        s_stats.wifi_to_eth_tx_bytes += pkt->len;
        
        // Validate buffer before transmission (prevent NULL pointer crashes in esp_hosted)
        if (!pkt->data || pkt->len == 0 || pkt->len > MAX_PACKET_SIZE) {
            ESP_LOGW(TAG, "Invalid WiFi→ETH packet: data=%p len=%d, dropping", pkt->data, pkt->len);
            s_stats.wifi_to_eth_tx_errors++;
            if (pkt->free_arg) {
                wifi_remote_free_rx_buffer(pkt->free_arg);
            }
            packet_pool_free(pkt);
            continue;
        }
        
        // Rate limiting to prevent overwhelming Ethernet driver
        TickType_t now = xTaskGetTickCount();
        if (now - last_tx_time < min_interval) {
            vTaskDelay(min_interval - (now - last_tx_time));
        }
        
        // Send to Ethernet with retries (large PSRAM buffers allow more retries)
        esp_err_t ret = ESP_FAIL;
        const int max_retries = 20;  // Increased from 1 to 20 due to large PSRAM buffer capacity
        
        for (int retry = 0; retry < max_retries; retry++) {
            ret = wired_send(pkt->data, pkt->len, pkt->free_arg);
            if (ret == ESP_OK) {
                break;  // Success
            }
            
            // Count retry attempts
            if (retry > 0) {
                s_stats.wifi_to_eth_retries++;
            }
            
            // Short delay before retry (let Ethernet DMA process backlog)
            vTaskDelay(pdMS_TO_TICKS(2));
        }
        
        if (ret != ESP_OK) {
            s_stats.wifi_to_eth_tx_errors++;
            // Free WiFi buffer on failure after all retries exhausted
            if (pkt->free_arg) {
                wifi_remote_free_rx_buffer(pkt->free_arg);
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
/**
 * Statistics reporting task - prints comprehensive report every 30 seconds
 */
static void stats_task(void *arg)
{
    ESP_LOGI(TAG, "Statistics task started - reporting every 30s");
    
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(30000));  // Every 30 seconds
        
        // Calculate deltas
        traffic_stats_t delta;
        delta.eth_rx_count = s_stats.eth_rx_count - s_stats_last.eth_rx_count;
        delta.eth_rx_bytes = s_stats.eth_rx_bytes - s_stats_last.eth_rx_bytes;
        delta.eth_to_wifi_tx_count = s_stats.eth_to_wifi_tx_count - s_stats_last.eth_to_wifi_tx_count;
        delta.eth_to_wifi_tx_bytes = s_stats.eth_to_wifi_tx_bytes - s_stats_last.eth_to_wifi_tx_bytes;
        delta.eth_to_wifi_tx_errors = s_stats.eth_to_wifi_tx_errors - s_stats_last.eth_to_wifi_tx_errors;
        delta.eth_to_wifi_retries = s_stats.eth_to_wifi_retries - s_stats_last.eth_to_wifi_retries;
        delta.eth_to_wifi_pool_exhausted = s_stats.eth_to_wifi_pool_exhausted - s_stats_last.eth_to_wifi_pool_exhausted;
        delta.eth_to_wifi_queue_full = s_stats.eth_to_wifi_queue_full - s_stats_last.eth_to_wifi_queue_full;
        
        delta.wifi_rx_count = s_stats.wifi_rx_count - s_stats_last.wifi_rx_count;
        delta.wifi_rx_bytes = s_stats.wifi_rx_bytes - s_stats_last.wifi_rx_bytes;
        delta.wifi_to_eth_tx_count = s_stats.wifi_to_eth_tx_count - s_stats_last.wifi_to_eth_tx_count;
        delta.wifi_to_eth_tx_bytes = s_stats.wifi_to_eth_tx_bytes - s_stats_last.wifi_to_eth_tx_bytes;
        delta.wifi_to_eth_tx_errors = s_stats.wifi_to_eth_tx_errors - s_stats_last.wifi_to_eth_tx_errors;
        delta.wifi_to_eth_retries = s_stats.wifi_to_eth_retries - s_stats_last.wifi_to_eth_retries;
        delta.wifi_to_eth_pool_exhausted = s_stats.wifi_to_eth_pool_exhausted - s_stats_last.wifi_to_eth_pool_exhausted;
        delta.wifi_to_eth_queue_full = s_stats.wifi_to_eth_queue_full - s_stats_last.wifi_to_eth_queue_full;
        
        // Get pool and queue stats
        uint32_t eth_total, eth_free, eth_used;
        packet_pool_get_stats(POOL_ETH_TO_WIFI, &eth_total, &eth_free, &eth_used);
        
        uint32_t wifi_total, wifi_free, wifi_used;
        packet_pool_get_stats(POOL_WIFI_TO_ETH, &wifi_total, &wifi_free, &wifi_used);
        
        uint32_t eth_queue_count, eth_queue_dropped;
        packet_queue_get_stats(&s_eth_to_wifi_queue, &eth_queue_count, &eth_queue_dropped);
        
        uint32_t wifi_queue_count, wifi_queue_dropped;
        packet_queue_get_stats(&s_wifi_to_eth_queue, &wifi_queue_count, &wifi_queue_dropped);
        
        // Print comprehensive statistics report
        ESP_LOGI(TAG, "====== 30s TRAFFIC STATISTICS ======");
        ESP_LOGI(TAG, "WiFi Status: %s", s_wifi_is_connected ? "CONNECTED" : "DISCONNECTED");
        
        ESP_LOGI(TAG, "ETH->WiFi Path:");
        ESP_LOGI(TAG, "  RX: %lu pkts (%lu KB) | TX: %lu pkts (%lu KB)",
                 delta.eth_rx_count, delta.eth_rx_bytes / 1024,
                 delta.eth_to_wifi_tx_count, delta.eth_to_wifi_tx_bytes / 1024);
        ESP_LOGI(TAG, "  Errors: TX=%lu Retries=%lu | Pool Exhausted=%lu | Queue Full=%lu",
                 delta.eth_to_wifi_tx_errors, delta.eth_to_wifi_retries,
                 delta.eth_to_wifi_pool_exhausted, delta.eth_to_wifi_queue_full);
        ESP_LOGI(TAG, "  Pool: %lu/%lu used (%.1f%%) | Queue: %lu/%d",
                 eth_used, eth_total, (float)eth_used * 100 / eth_total,
                 eth_queue_count, MAX_ETH_TO_WIFI_QUEUE);
        
        ESP_LOGI(TAG, "WiFi->ETH Path:");
        ESP_LOGI(TAG, "  RX: %lu pkts (%lu KB) | TX: %lu pkts (%lu KB)",
                 delta.wifi_rx_count, delta.wifi_rx_bytes / 1024,
                 delta.wifi_to_eth_tx_count, delta.wifi_to_eth_tx_bytes / 1024);
        ESP_LOGI(TAG, "  Errors: TX=%lu Retries=%lu | Pool Exhausted=%lu | Queue Full=%lu",
                 delta.wifi_to_eth_tx_errors, delta.wifi_to_eth_retries,
                 delta.wifi_to_eth_pool_exhausted, delta.wifi_to_eth_queue_full);
        ESP_LOGI(TAG, "  Pool: %lu/%lu used (%.1f%%) | Queue: %lu/%d",
                 wifi_used, wifi_total, (float)wifi_used * 100 / wifi_total,
                 wifi_queue_count, MAX_WIFI_TO_ETH_QUEUE);
        
        // Calculate packet loss rates
        if (delta.eth_rx_count > 0) {
            uint32_t eth_dropped = delta.eth_to_wifi_pool_exhausted + delta.eth_to_wifi_queue_full;
            float eth_loss_rate = (float)eth_dropped * 100 / delta.eth_rx_count;
            ESP_LOGI(TAG, "ETH Loss Rate: %.2f%% (%lu dropped / %lu received)",
                     eth_loss_rate, eth_dropped, delta.eth_rx_count);
        }
        
        if (delta.wifi_rx_count > 0) {
            uint32_t wifi_dropped = delta.wifi_to_eth_pool_exhausted + delta.wifi_to_eth_queue_full;
            float wifi_loss_rate = (float)wifi_dropped * 100 / delta.wifi_rx_count;
            ESP_LOGI(TAG, "WiFi Loss Rate: %.2f%% (%lu dropped / %lu received)",
                     wifi_loss_rate, wifi_dropped, delta.wifi_rx_count);
        }
        
        // Cumulative totals
        ESP_LOGI(TAG, "Cumulative Totals:");
        ESP_LOGI(TAG, "  ETH: RX=%lu TX=%lu Err=%lu | WiFi: RX=%lu TX=%lu Err=%lu",
                 s_stats.eth_rx_count, s_stats.eth_to_wifi_tx_count, s_stats.eth_to_wifi_tx_errors,
                 s_stats.wifi_rx_count, s_stats.wifi_to_eth_tx_count, s_stats.wifi_to_eth_tx_errors);
        ESP_LOGI(TAG, "====================================");
        
        // Save current stats for next delta calculation
        s_stats_last = s_stats;
    }
}

/**
 * Memory monitoring task - warns when heap is running low
 * Reports top memory consumers by task
 */
static void memory_monitor_task(void *arg)
{
    ESP_LOGI(TAG, "Memory monitor task started - checking every 10s");
    
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(10000));  // Check every 10 seconds
        
        // Get heap information
        size_t free_internal = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
        size_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
        size_t min_free_internal = heap_caps_get_minimum_free_size(MALLOC_CAP_INTERNAL);
        size_t min_free_psram = heap_caps_get_minimum_free_size(MALLOC_CAP_SPIRAM);
        
        bool critical_warning = false;
        
        // Check internal RAM threshold
        if (free_internal < INTERNAL_RAM_WARNING_THRESHOLD) {
            critical_warning = true;
            ESP_LOGW(TAG, "⚠️  LOW INTERNAL RAM WARNING!");
            ESP_LOGW(TAG, "  Free: %u KB | Min Ever: %u KB | Threshold: %u KB",
                     free_internal / 1024, min_free_internal / 1024,
                     INTERNAL_RAM_WARNING_THRESHOLD / 1024);
        }
        
        // Check PSRAM threshold
        if (free_psram < PSRAM_WARNING_THRESHOLD) {
            critical_warning = true;
            ESP_LOGW(TAG, "⚠️  LOW PSRAM WARNING!");
            ESP_LOGW(TAG, "  Free: %u KB | Min Ever: %u KB | Threshold: %u KB",
                     free_psram / 1024, min_free_psram / 1024,
                     PSRAM_WARNING_THRESHOLD / 1024);
        }
        
        // If critical, report task stack usage (top memory consumers)
        if (critical_warning) {
            ESP_LOGW(TAG, "===== TOP MEMORY CONSUMERS (Task Stacks) =====");
            
            TaskStatus_t *task_array;
            UBaseType_t num_tasks;
            uint32_t total_runtime;
            
            // Get number of tasks
            num_tasks = uxTaskGetNumberOfTasks();
            
            // Allocate array for task status (use malloc to avoid stack overflow here)
            task_array = pvPortMalloc(num_tasks * sizeof(TaskStatus_t));
            if (task_array != NULL) {
                // Get task status
                num_tasks = uxTaskGetSystemState(task_array, num_tasks, &total_runtime);
                
                // Sort tasks by stack high water mark (lower = more used)
                // Print top 5 stack consumers
                ESP_LOGW(TAG, "Task Name         | Stack Used | Stack Free | Priority");
                ESP_LOGW(TAG, "------------------|------------|------------|----------");
                
                for (UBaseType_t i = 0; i < num_tasks && i < 10; i++) {
                    uint32_t stack_size = task_array[i].usStackHighWaterMark * sizeof(StackType_t);
                    uint32_t stack_used = 0;
                    
                    // Estimate stack size based on task name (known task stack sizes)
                    const char *name = task_array[i].pcTaskName;
                    uint32_t total_stack = 0;
                    
                    if (strcmp(name, "eth2wifi") == 0) total_stack = 4096;
                    else if (strcmp(name, "wifi2eth") == 0) total_stack = 4096;
                    else if (strcmp(name, "stats") == 0) total_stack = 4096;
                    else if (strcmp(name, "conn_monitor") == 0) total_stack = 2048;
                    else if (strcmp(name, "mem_monitor") == 0) total_stack = 3072;
                    else if (strcmp(name, "IDLE") == 0) total_stack = 1536;
                    else if (strcmp(name, "main") == 0) total_stack = 8192;
                    else if (strcmp(name, "ipc0") == 0 || strcmp(name, "ipc1") == 0) total_stack = 1024;
                    else if (strcmp(name, "tcpip_task") == 0) total_stack = 4096;
                    else if (strcmp(name, "esp_timer") == 0) total_stack = 4096;
                    else if (strcmp(name, "sys_evt") == 0) total_stack = 4096;
                    else total_stack = 2048;  // Default estimate
                    
                    stack_used = total_stack - stack_size;
                    
                    ESP_LOGW(TAG, "%-17s | %6lu B | %6lu B | %u",
                             name, stack_used, stack_size, task_array[i].uxCurrentPriority);
                }
                
                ESP_LOGW(TAG, "==============================================");
                
                // Free the array
                vPortFree(task_array);
            } else {
                ESP_LOGE(TAG, "Failed to allocate memory for task status array!");
            }
            
            // Report buffer pool usage (major PSRAM consumers)
            ESP_LOGW(TAG, "===== PSRAM BUFFER POOLS =====");
            uint32_t eth_total, eth_free, eth_used;
            packet_pool_get_stats(POOL_ETH_TO_WIFI, &eth_total, &eth_free, &eth_used);
            ESP_LOGW(TAG, "ETH->WiFi Pool: %lu buffers used / %lu total (%lu KB used)",
                     eth_used, eth_total, (eth_used * 1600) / 1024);
            
            uint32_t wifi_total, wifi_free, wifi_used;
            packet_pool_get_stats(POOL_WIFI_TO_ETH, &wifi_total, &wifi_free, &wifi_used);
            ESP_LOGW(TAG, "WiFi->ETH Pool: %lu buffers used / %lu total (%lu KB used)",
                     wifi_used, wifi_total, (wifi_used * 1600) / 1024);
            
            ESP_LOGW(TAG, "Total Buffer Pool Memory: %lu KB / %lu KB used",
                     ((eth_used + wifi_used) * 1600) / 1024,
                     ((eth_total + wifi_total) * 1600) / 1024);
            ESP_LOGW(TAG, "==============================");
        }
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
            
            // Create statistics task (4096 bytes for comprehensive logging with floats)
            xTaskCreate(stats_task, "stats", 4096, NULL, 3, NULL);
            
            // Create memory monitor task (3072 bytes for task array allocation + logging)
            xTaskCreate(memory_monitor_task, "mem_monitor", 3072, NULL, 2, NULL);
            
            ESP_LOGI(TAG, "Bridge active: Ethernet (P4) <-> PSRAM Queue <-> SDIO <-> WiFi (C6)");
            ESP_LOGI(TAG, "PSRAM buffering enabled for speed mismatch handling");
            ESP_LOGI(TAG, "Memory monitoring active - warns when RAM/PSRAM low");
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
