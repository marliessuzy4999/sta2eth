/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"

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
    char git_hash[9];  // 8 chars + null terminator
} firmware_version_t;

/**
 * @brief Query C6 firmware version via ESP-Hosted control channel
 * 
 * @param version Pointer to store the retrieved version
 * @param timeout_ms Timeout in milliseconds
 * @return ESP_OK on success, ESP_ERR_TIMEOUT on timeout, other errors on failure
 */
esp_err_t c6_get_firmware_version(firmware_version_t *version, uint32_t timeout_ms);

/**
 * @brief Compare firmware versions
 * 
 * @param c6_ver C6 firmware version
 * @param min_ver Minimum required version
 * @return true if C6 version is >= minimum version, false otherwise
 */
bool c6_version_is_compatible(firmware_version_t *c6_ver, firmware_version_t *min_ver);

/**
 * @brief Check if C6 firmware needs upgrade
 * 
 * Queries C6 version and compares with minimum required version from config.
 * 
 * @param timeout_ms Timeout for version query
 * @return true if upgrade is needed, false if version is OK
 */
bool c6_needs_firmware_upgrade(uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif
