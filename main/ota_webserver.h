/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "esp_err.h"
#include "esp_http_server.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Start OTA web server
 * 
 * Starts an HTTP server on the configured port for OTA firmware upload
 * 
 * @return ESP_OK on success
 */
esp_err_t ota_webserver_start(void);

/**
 * @brief Stop OTA web server
 */
void ota_webserver_stop(void);

/**
 * @brief Check if OTA web server is running
 * 
 * @return true if running
 */
bool ota_webserver_is_running(void);

#ifdef __cplusplus
}
#endif
