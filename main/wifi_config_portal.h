/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "esp_err.h"
#include "freertos/event_groups.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Start WiFi configuration portal using SoftAP on C6
 * 
 * This creates a SoftAP on ESP32-C6 for WiFi configuration via mobile phone
 * 
 * @param flags Event group for synchronization
 * @param success_bit Bit to set when configuration succeeds
 * @param fail_bit Bit to set when configuration fails
 * @return ESP_OK on success
 */
esp_err_t start_wifi_config_portal(EventGroupHandle_t *flags, int success_bit, int fail_bit);

/**
 * @brief Check if WiFi is provisioned
 * 
 * @return true if provisioned
 */
bool is_wifi_provisioned(void);

#ifdef __cplusplus
}
#endif
