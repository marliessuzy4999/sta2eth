/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Check if OTA mode should be entered
 * 
 * Checks C6 firmware version and decides if OTA mode is needed
 * 
 * @return true if OTA mode should be entered, false otherwise
 */
bool should_enter_ota_mode(void);

/**
 * @brief Start OTA mode
 * 
 * Initializes Ethernet with static IP and starts OTA web server
 * 
 * @return ESP_OK on success
 */
esp_err_t start_ota_mode(void);

#ifdef __cplusplus
}
#endif
