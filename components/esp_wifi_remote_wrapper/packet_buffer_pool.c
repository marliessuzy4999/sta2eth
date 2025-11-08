/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * PSRAM-based Packet Buffer Pool for P4+C6 Speed Mismatch
 * 
 * This provides large packet buffers in PSRAM to absorb the speed difference
 * between P4 (fast Ethernet) and C6 (slower WiFi/SDIO)
 */

#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "packet_buffer_pool.h"

static const char *TAG = "pkt_pool";

// Independent packet pool state for each direction
typedef struct {
    packet_buffer_t *buffer_pool;
    packet_buffer_t *free_list;
    SemaphoreHandle_t mutex;
    uint32_t total_buffers;
    uint32_t free_buffers;
    uint32_t used_buffers;
    uint32_t pool_size;
    const char *name;
} pool_state_t;

static pool_state_t s_pools[POOL_DIRECTION_MAX] = {
    {NULL, NULL, NULL, 0, 0, 0, ETH_TO_WIFI_POOL_SIZE, "ETH->WiFi"},
    {NULL, NULL, NULL, 0, 0, 0, WIFI_TO_ETH_POOL_SIZE, "WiFi->ETH"}
};

/**
 * Initialize packet buffer pool in PSRAM with independent pools per direction
 */
esp_err_t packet_pool_init(void)
{
    ESP_LOGI(TAG, "Initializing independent PSRAM packet pools:");
    ESP_LOGI(TAG, "  - ETH->WiFi: %d buffers", ETH_TO_WIFI_POOL_SIZE);
    ESP_LOGI(TAG, "  - WiFi->ETH: %d buffers", WIFI_TO_ETH_POOL_SIZE);
    ESP_LOGI(TAG, "  - Total: %d buffers × %d bytes = %d KB",
             PACKET_POOL_SIZE, MAX_PACKET_SIZE, 
             (PACKET_POOL_SIZE * MAX_PACKET_SIZE) / 1024);
    
    // Initialize each pool independently
    for (int dir = 0; dir < POOL_DIRECTION_MAX; dir++) {
        pool_state_t *pool = &s_pools[dir];
        
        if (pool->buffer_pool != NULL) {
            ESP_LOGW(TAG, "%s pool already initialized", pool->name);
            continue;
        }
        
        // Create mutex for this pool
        pool->mutex = xSemaphoreCreateMutex();
        if (!pool->mutex) {
            ESP_LOGE(TAG, "Failed to create mutex for %s pool", pool->name);
            return ESP_ERR_NO_MEM;
        }
        
        // Allocate buffer structures in PSRAM
        pool->buffer_pool = heap_caps_malloc(sizeof(packet_buffer_t) * pool->pool_size, 
                                             MALLOC_CAP_SPIRAM);
        if (!pool->buffer_pool) {
            ESP_LOGE(TAG, "Failed to allocate %s buffer pool in PSRAM", pool->name);
            vSemaphoreDelete(pool->mutex);
            return ESP_ERR_NO_MEM;
        }
        
        // Initialize all buffers and build free list
        pool->free_list = NULL;
        for (int i = 0; i < pool->pool_size; i++) {
            packet_buffer_t *buf = &pool->buffer_pool[i];
            
            // Allocate data buffer in PSRAM
            buf->data = heap_caps_malloc(MAX_PACKET_SIZE, MALLOC_CAP_SPIRAM);
            if (!buf->data) {
                ESP_LOGE(TAG, "Failed to allocate %s packet data buffer %d", pool->name, i);
                // Cleanup already allocated buffers
                for (int j = 0; j < i; j++) {
                    free(pool->buffer_pool[j].data);
                }
                free(pool->buffer_pool);
                vSemaphoreDelete(pool->mutex);
                return ESP_ERR_NO_MEM;
            }
            
            buf->len = 0;
            buf->capacity = MAX_PACKET_SIZE;
            buf->free_arg = NULL;
            
            // Add to free list
            buf->next = pool->free_list;
            pool->free_list = buf;
        }
        
        pool->total_buffers = pool->pool_size;
        pool->free_buffers = pool->pool_size;
        pool->used_buffers = 0;
        
        ESP_LOGI(TAG, "%s pool initialized: %d buffers", pool->name, pool->pool_size);
    }
    
    ESP_LOGI(TAG, "Independent PSRAM pools initialized successfully");
    ESP_LOGI(TAG, "Each direction has its own pool - no interference!");
    
    return ESP_OK;
}

/**
 * Allocate packet buffer from specific direction pool
 */
packet_buffer_t* packet_pool_alloc(uint16_t size, pool_direction_t direction)
{
    if (size > MAX_PACKET_SIZE) {
        ESP_LOGW(TAG, "Requested size %d exceeds max %d", size, MAX_PACKET_SIZE);
        return NULL;
    }
    
    if (direction >= POOL_DIRECTION_MAX) {
        ESP_LOGE(TAG, "Invalid pool direction: %d", direction);
        return NULL;
    }
    
    pool_state_t *pool = &s_pools[direction];
    
    xSemaphoreTake(pool->mutex, portMAX_DELAY);
    
    packet_buffer_t *buf = pool->free_list;
    if (buf) {
        // Remove from free list
        pool->free_list = buf->next;
        buf->next = NULL;
        buf->len = 0;
        buf->free_arg = NULL;
        
        pool->free_buffers--;
        pool->used_buffers++;
    } else {
        ESP_LOGD(TAG, "%s pool exhausted", pool->name);
    }
    
    xSemaphoreGive(pool->mutex);
    
    return buf;
}

/**
 * Free packet buffer back to pool
 * Automatically determines which pool based on buffer address
 */
void packet_pool_free(packet_buffer_t *pkt)
{
    if (!pkt) {
        return;
    }
    
    // Determine which pool this buffer belongs to
    pool_state_t *pool = NULL;
    for (int dir = 0; dir < POOL_DIRECTION_MAX; dir++) {
        pool_state_t *p = &s_pools[dir];
        if (pkt >= p->buffer_pool && pkt < (p->buffer_pool + p->pool_size)) {
            pool = p;
            break;
        }
    }
    
    if (!pool) {
        ESP_LOGE(TAG, "Buffer doesn't belong to any pool!");
        return;
    }
    
    xSemaphoreTake(pool->mutex, portMAX_DELAY);
    
    // Add back to free list
    pkt->next = pool->free_list;
    pool->free_list = pkt;
    pkt->len = 0;
    pkt->free_arg = NULL;
    
    pool->free_buffers++;
    pool->used_buffers--;
    
    xSemaphoreGive(pool->mutex);
}

/**
 * Get pool statistics for specific direction
 */
void packet_pool_get_stats(pool_direction_t direction, uint32_t *total_buffers, uint32_t *free_buffers, uint32_t *used_buffers)
{
    if (direction >= POOL_DIRECTION_MAX) {
        ESP_LOGE(TAG, "Invalid pool direction: %d", direction);
        return;
    }
    
    pool_state_t *pool = &s_pools[direction];
    
    xSemaphoreTake(pool->mutex, portMAX_DELAY);
    
    if (total_buffers) *total_buffers = pool->total_buffers;
    if (free_buffers) *free_buffers = pool->free_buffers;
    if (used_buffers) *used_buffers = pool->used_buffers;
    
    xSemaphoreGive(pool->mutex);
}

/**
 * Initialize packet queue
 */
esp_err_t packet_queue_init(packet_queue_t *queue, uint32_t max_count)
{
    if (!queue) {
        return ESP_ERR_INVALID_ARG;
    }
    
    memset(queue, 0, sizeof(packet_queue_t));
    queue->max_count = max_count;
    
    // Create mutex for thread safety
    queue->mutex = xSemaphoreCreateMutex();
    if (!queue->mutex) {
        ESP_LOGE(TAG, "Failed to create queue mutex");
        return ESP_ERR_NO_MEM;
    }
    
    ESP_LOGI(TAG, "Queue initialized with max_count=%lu, mutex=%p", max_count, queue->mutex);
    
    return ESP_OK;
}

/**
 * Enqueue packet with flow control
 */
esp_err_t packet_queue_enqueue(packet_queue_t *queue, packet_buffer_t *pkt)
{
    if (!queue || !pkt) {
        ESP_LOGE(TAG, "Invalid queue or packet");
        return ESP_ERR_INVALID_ARG;
    }
    
    if (!queue->mutex) {
        ESP_LOGE(TAG, "Queue mutex not initialized!");
        return ESP_ERR_INVALID_STATE;
    }
    
    xSemaphoreTake(queue->mutex, portMAX_DELAY);
    
    // Check if queue is full
    if (queue->max_count > 0 && queue->count >= queue->max_count) {
        queue->dropped++;
        xSemaphoreGive(queue->mutex);
        ESP_LOGW(TAG, "Queue full (%lu/%lu), packet dropped (total dropped: %lu)", 
                 queue->count, queue->max_count, queue->dropped);
        return ESP_ERR_NO_MEM;
    }
    
    // Add to end of queue
    pkt->next = NULL;
    if (queue->tail) {
        queue->tail->next = pkt;
    } else {
        queue->head = pkt;
    }
    queue->tail = pkt;
    queue->count++;
    
    xSemaphoreGive(queue->mutex);
    
    return ESP_OK;
}

/**
 * Dequeue packet
 */
packet_buffer_t* packet_queue_dequeue(packet_queue_t *queue)
{
    if (!queue) {
        return NULL;
    }
    
    if (!queue->mutex) {
        ESP_LOGE(TAG, "Queue mutex not initialized!");
        return NULL;
    }
    
    xSemaphoreTake(queue->mutex, portMAX_DELAY);
    
    if (!queue->head) {
        xSemaphoreGive(queue->mutex);
        return NULL;
    }
    
    packet_buffer_t *pkt = queue->head;
    queue->head = pkt->next;
    if (!queue->head) {
        queue->tail = NULL;
    }
    queue->count--;
    
    xSemaphoreGive(queue->mutex);
    
    pkt->next = NULL;
    return pkt;
}

/**
 * Check if queue is empty
 */
bool packet_queue_is_empty(packet_queue_t *queue)
{
    if (!queue || !queue->mutex) {
        return true;
    }
    
    xSemaphoreTake(queue->mutex, portMAX_DELAY);
    bool is_empty = (queue->count == 0);
    xSemaphoreGive(queue->mutex);
    
    return is_empty;
}

/**
 * Get queue statistics
 */
void packet_queue_get_stats(packet_queue_t *queue, uint32_t *count, uint32_t *dropped)
{
    if (!queue || !queue->mutex) {
        return;
    }
    
    xSemaphoreTake(queue->mutex, portMAX_DELAY);
    
    if (count) *count = queue->count;
    if (dropped) *dropped = queue->dropped;
    
    xSemaphoreGive(queue->mutex);
}
