/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Large PSRAM-based packet buffer pool for handling speed mismatch
 *        between P4 (fast) and C6 (slower WiFi/SDIO)
 * 
 * This pool uses PSRAM to create a large buffer that can absorb bursts
 * of packets from P4 Ethernet without overwhelming C6's SDIO/WiFi interface
 */

/* Configuration - Independent pools for each direction */
#define ETH_TO_WIFI_POOL_SIZE   768      // Ethernet → WiFi pool (increased 20% for burst traffic)
#define WIFI_TO_ETH_POOL_SIZE   640      // WiFi → Ethernet pool (increased 67% to prevent SDIO exhaustion)
#define PACKET_POOL_SIZE        (ETH_TO_WIFI_POOL_SIZE + WIFI_TO_ETH_POOL_SIZE)  // Total: 1408
#define MAX_PACKET_SIZE         1600     // Maximum Ethernet frame size

/* Pool direction identifiers */
typedef enum {
    POOL_ETH_TO_WIFI = 0,
    POOL_WIFI_TO_ETH = 1,
    POOL_DIRECTION_MAX = 2
} pool_direction_t;

typedef struct packet_buffer_s {
    uint8_t *data;              // Packet data (allocated in PSRAM)
    uint16_t len;               // Actual packet length
    uint16_t capacity;          // Buffer capacity
    void *free_arg;             // Argument for free callback
    struct packet_buffer_s *next;
} packet_buffer_t;

typedef void (*packet_free_cb_t)(void *buffer, void *arg);

/**
 * @brief Initialize the PSRAM-based packet buffer pool
 * 
 * @return ESP_OK on success
 */
esp_err_t packet_pool_init(void);

/**
 * @brief Allocate a packet buffer from the pool
 * 
 * @param size Required buffer size
 * @param direction Pool direction (ETH_TO_WIFI or WIFI_TO_ETH)
 * @return Pointer to allocated packet buffer, NULL if pool is exhausted
 */
packet_buffer_t* packet_pool_alloc(uint16_t size, pool_direction_t direction);

/**
 * @brief Free a packet buffer back to the pool
 * 
 * @param pkt Packet buffer to free
 */
void packet_pool_free(packet_buffer_t *pkt);

/**
 * @brief Get pool statistics
 * 
 * @param direction Pool direction (ETH_TO_WIFI or WIFI_TO_ETH)
 * @param total_buffers Total number of buffers in pool
 * @param free_buffers Number of free buffers
 * @param used_buffers Number of buffers in use
 */
void packet_pool_get_stats(pool_direction_t direction, uint32_t *total_buffers, uint32_t *free_buffers, uint32_t *used_buffers);

/**
 * @brief Queue management with flow control
 */
typedef struct {
    packet_buffer_t *head;
    packet_buffer_t *tail;
    uint32_t count;
    uint32_t max_count;
    uint32_t dropped;           // Dropped packet counter
    SemaphoreHandle_t mutex;    // Thread safety
} packet_queue_t;

/**
 * @brief Initialize a packet queue
 * 
 * @param queue Queue to initialize
 * @param max_count Maximum number of packets in queue (0 = unlimited)
 * @return ESP_OK on success
 */
esp_err_t packet_queue_init(packet_queue_t *queue, uint32_t max_count);

/**
 * @brief Enqueue a packet with flow control
 * 
 * @param queue Queue to enqueue to
 * @param pkt Packet to enqueue
 * @return ESP_OK on success, ESP_ERR_NO_MEM if queue is full
 */
esp_err_t packet_queue_enqueue(packet_queue_t *queue, packet_buffer_t *pkt);

/**
 * @brief Dequeue a packet
 * 
 * @param queue Queue to dequeue from
 * @return Pointer to packet, NULL if queue is empty
 */
packet_buffer_t* packet_queue_dequeue(packet_queue_t *queue);

/**
 * @brief Check if queue is empty
 * 
 * @param queue Queue to check
 * @return true if empty
 */
bool packet_queue_is_empty(packet_queue_t *queue);

/**
 * @brief Get queue statistics
 * 
 * @param queue Queue to get stats for
 * @param count Current number of packets
 * @param dropped Number of dropped packets
 */
void packet_queue_get_stats(packet_queue_t *queue, uint32_t *count, uint32_t *dropped);

#ifdef __cplusplus
}
#endif
