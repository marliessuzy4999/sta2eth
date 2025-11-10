/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#pragma once

#include "esp_err.h"
#include "freertos/event_groups.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief WiFi Remote station interface for ESP32-P4 with C6 slave
 * 
 * This module uses esp_wifi_remote to access WiFi on ESP32-C6
 * via ESP-Hosted over SDIO. It is in a separate compilation unit
 * to avoid type conflicts between native and remote WiFi types.
 */

/**
 * @brief Initialize WiFi remote station
 * 
 * @param event_flags Event group for synchronization
 * @param connected_bit Bit to set when connected
 * @param disconnected_bit Bit to set when disconnected  
 * @param sta_mac MAC address buffer to store WiFi STA MAC
 * @param eth_mac Ethernet MAC address to set as WiFi STA MAC (for transparent bridging), or NULL to use default
 * @return ESP_OK on success
 */
esp_err_t wifi_remote_sta_init(EventGroupHandle_t event_flags, 
                                int connected_bit,
                                int disconnected_bit,
                                uint8_t *sta_mac,
                                const uint8_t *eth_mac);

/**
 * @brief Connect to WiFi network
 * 
 * @return ESP_OK on success
 */
esp_err_t wifi_remote_sta_connect(void);

/**
 * @brief Check if WiFi is provisioned
 * 
 * @return true if provisioned
 */
bool wifi_remote_is_provisioned(void);

/**
 * @brief Register RX callback for WiFi packets
 * 
 * @param callback Callback function
 * @return ESP_OK on success
 */
esp_err_t wifi_remote_reg_rxcb(void *callback);

/**
 * @brief Unregister RX callback
 * 
 * @return ESP_OK on success
 */
esp_err_t wifi_remote_unreg_rxcb(void);

/**
 * @brief Send packet via WiFi remote
 * 
 * @param buffer Packet buffer
 * @param len Packet length
 * @return ESP_OK on success
 */
esp_err_t wifi_remote_tx(void *buffer, uint16_t len);

/**
 * @brief Free WiFi RX buffer
 * 
 * @param buffer Buffer to free
 */
void wifi_remote_free_rx_buffer(void *buffer);

/**
 * @brief Set WiFi configuration
 * 
 * @param ssid SSID to connect to
 * @param password Password
 * @return ESP_OK on success
 */
esp_err_t wifi_remote_set_config(const char *ssid, const char *password);

#ifdef __cplusplus
}
#endif
