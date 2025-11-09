/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief OTA state enumeration
 */
typedef enum {
    OTA_STATE_IDLE,
    OTA_STATE_IN_PROGRESS,
    OTA_STATE_SUCCESS,
    OTA_STATE_FAILED
} c6_ota_state_t;

/**
 * @brief Initialize OTA session
 * 
 * @param firmware_size Total firmware size in bytes
 * @return ESP_OK on success
 */
esp_err_t c6_ota_begin(size_t firmware_size);

/**
 * @brief Write firmware data chunk
 * 
 * @param data Pointer to data chunk
 * @param len Length of data chunk
 * @return ESP_OK on success
 */
esp_err_t c6_ota_write(const uint8_t *data, size_t len);

/**
 * @brief Complete OTA and trigger C6 restart
 * 
 * @return ESP_OK on success
 */
esp_err_t c6_ota_end(void);

/**
 * @brief Abort OTA session
 */
void c6_ota_abort(void);

/**
 * @brief Get OTA progress percentage
 * 
 * @return Progress percentage (0-100)
 */
uint8_t c6_ota_get_progress(void);

/**
 * @brief Get OTA state
 * 
 * @return Current OTA state
 */
c6_ota_state_t c6_ota_get_state(void);

/**
 * @brief Get last error message
 * 
 * @return Error message string (or NULL if no error)
 */
const char* c6_ota_get_error(void);

#ifdef __cplusplus
}
#endif
