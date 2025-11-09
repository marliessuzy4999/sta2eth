/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef C6_OTA_H
#define C6_OTA_H

#include "esp_err.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Firmware version structure
 */
typedef struct {
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} firmware_version_t;

/**
 * @brief Check if device should enter C6 OTA mode
 * 
 * This function checks the C6 firmware version and determines
 * if an upgrade is needed.
 * 
 * @return true if OTA mode should be entered, false otherwise
 */
bool c6_ota_should_enter_mode(void);

/**
 * @brief Start C6 OTA mode
 * 
 * Initializes Ethernet with static IP, starts DHCP server,
 * and launches the OTA web server on http://192.168.100.1
 * 
 * @return ESP_OK on success, error code otherwise
 */
esp_err_t c6_ota_start_mode(void);

#ifdef __cplusplus
}
#endif

#endif /* C6_OTA_H */
