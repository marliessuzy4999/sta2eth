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

// Packet pool state
static packet_buffer_t *s_buffer_pool = NULL;
static packet_buffer_t *s_free_list = NULL;
static SemaphoreHandle_t s_pool_mutex = NULL;
static uint32_t s_total_buffers = 0;
static uint32_t s_free_buffers = 0;
static uint32_t s_used_buffers = 0;

/**
 * Initialize packet buffer pool in PSRAM
 */
esp_err_t packet_pool_init(void)
{
    if (s_buffer_pool != NULL) {
        ESP_LOGW(TAG, "Packet pool already initialized");
        return ESP_OK;
    }
    
    ESP_LOGI(TAG, "Initializing packet pool with %d buffers in PSRAM", PACKET_POOL_SIZE);
    
    // Create mutex
    s_pool_mutex = xSemaphoreCreateMutex();
    if (!s_pool_mutex) {
        ESP_LOGE(TAG, "Failed to create mutex");
        return ESP_ERR_NO_MEM;
    }
    
    // Allocate buffer structures in PSRAM
    s_buffer_pool = heap_caps_malloc(sizeof(packet_buffer_t) * PACKET_POOL_SIZE, 
                                     MALLOC_CAP_SPIRAM);
    if (!s_buffer_pool) {
        ESP_LOGE(TAG, "Failed to allocate buffer pool in PSRAM");
        vSemaphoreDelete(s_pool_mutex);
        return ESP_ERR_NO_MEM;
    }
    
    // Initialize all buffers and build free list
    s_free_list = NULL;
    for (int i = 0; i < PACKET_POOL_SIZE; i++) {
        packet_buffer_t *buf = &s_buffer_pool[i];
        
        // Allocate data buffer in PSRAM
        buf->data = heap_caps_malloc(MAX_PACKET_SIZE, MALLOC_CAP_SPIRAM);
        if (!buf->data) {
            ESP_LOGE(TAG, "Failed to allocate packet data buffer %d", i);
            // Cleanup already allocated buffers
            for (int j = 0; j < i; j++) {
                free(s_buffer_pool[j].data);
            }
            free(s_buffer_pool);
            vSemaphoreDelete(s_pool_mutex);
            return ESP_ERR_NO_MEM;
        }
        
        buf->len = 0;
        buf->capacity = MAX_PACKET_SIZE;
        buf->free_arg = NULL;
        
        // Add to free list
        buf->next = s_free_list;
        s_free_list = buf;
    }
    
    s_total_buffers = PACKET_POOL_SIZE;
    s_free_buffers = PACKET_POOL_SIZE;
    s_used_buffers = 0;
    
    ESP_LOGI(TAG, "Packet pool initialized: %d buffers × %d bytes = %d KB total",
             PACKET_POOL_SIZE, MAX_PACKET_SIZE, 
             (PACKET_POOL_SIZE * MAX_PACKET_SIZE) / 1024);
    
    return ESP_OK;
}

/**
 * Allocate packet buffer from pool
 */
packet_buffer_t* packet_pool_alloc(uint16_t size)
{
    if (size > MAX_PACKET_SIZE) {
        ESP_LOGW(TAG, "Requested size %d exceeds max %d", size, MAX_PACKET_SIZE);
        return NULL;
    }
    
    xSemaphoreTake(s_pool_mutex, portMAX_DELAY);
    
    packet_buffer_t *buf = s_free_list;
    if (buf) {
        // Remove from free list
        s_free_list = buf->next;
        buf->next = NULL;
        buf->len = 0;
        buf->free_arg = NULL;
        
        s_free_buffers--;
        s_used_buffers++;
    } else {
        ESP_LOGD(TAG, "Packet pool exhausted");
    }
    
    xSemaphoreGive(s_pool_mutex);
    
    return buf;
}

/**
 * Free packet buffer back to pool
 */
void packet_pool_free(packet_buffer_t *pkt)
{
    if (!pkt) {
        return;
    }
    
    xSemaphoreTake(s_pool_mutex, portMAX_DELAY);
    
    // Add back to free list
    pkt->next = s_free_list;
    s_free_list = pkt;
    pkt->len = 0;
    pkt->free_arg = NULL;
    
    s_free_buffers++;
    s_used_buffers--;
    
    xSemaphoreGive(s_pool_mutex);
}

/**
 * Get pool statistics
 */
void packet_pool_get_stats(uint32_t *total_buffers, uint32_t *free_buffers, uint32_t *used_buffers)
{
    xSemaphoreTake(s_pool_mutex, portMAX_DELAY);
    
    if (total_buffers) *total_buffers = s_total_buffers;
    if (free_buffers) *free_buffers = s_free_buffers;
    if (used_buffers) *used_buffers = s_used_buffers;
    
    xSemaphoreGive(s_pool_mutex);
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
    
    return ESP_OK;
}

/**
 * Enqueue packet with flow control
 */
esp_err_t packet_queue_enqueue(packet_queue_t *queue, packet_buffer_t *pkt)
{
    if (!queue || !pkt) {
        return ESP_ERR_INVALID_ARG;
    }
    
    // Check if queue is full
    if (queue->max_count > 0 && queue->count >= queue->max_count) {
        queue->dropped++;
        ESP_LOGD(TAG, "Queue full, packet dropped (total dropped: %lu)", queue->dropped);
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
    
    return ESP_OK;
}

/**
 * Dequeue packet
 */
packet_buffer_t* packet_queue_dequeue(packet_queue_t *queue)
{
    if (!queue || !queue->head) {
        return NULL;
    }
    
    packet_buffer_t *pkt = queue->head;
    queue->head = pkt->next;
    if (!queue->head) {
        queue->tail = NULL;
    }
    queue->count--;
    
    pkt->next = NULL;
    return pkt;
}

/**
 * Check if queue is empty
 */
bool packet_queue_is_empty(packet_queue_t *queue)
{
    return (queue && queue->count == 0);
}

/**
 * Get queue statistics
 */
void packet_queue_get_stats(packet_queue_t *queue, uint32_t *count, uint32_t *dropped)
{
    if (!queue) {
        return;
    }
    
    if (count) *count = queue->count;
    if (dropped) *dropped = queue->dropped;
}
