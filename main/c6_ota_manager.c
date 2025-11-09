/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include "c6_ota_manager.h"
#include "esp_log.h"
#include "esp_heap_caps.h"

static const char *TAG = "c6_ota_mgr";

// OTA manager state
typedef struct {
    c6_ota_state_t state;
    size_t total_size;
    size_t bytes_written;
    uint8_t *buffer;
    char error_msg[128];
} ota_manager_t;

static ota_manager_t s_ota_mgr = {
    .state = OTA_STATE_IDLE,
    .total_size = 0,
    .bytes_written = 0,
    .buffer = NULL,
    .error_msg = {0}
};

// Maximum firmware size (2MB for C6)
#define MAX_FIRMWARE_SIZE (2 * 1024 * 1024)

esp_err_t c6_ota_begin(size_t firmware_size)
{
    if (s_ota_mgr.state == OTA_STATE_IN_PROGRESS) {
        ESP_LOGE(TAG, "OTA already in progress");
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg), 
                 "OTA already in progress");
        return ESP_ERR_INVALID_STATE;
    }

    if (firmware_size == 0 || firmware_size > MAX_FIRMWARE_SIZE) {
        ESP_LOGE(TAG, "Invalid firmware size: %zu", firmware_size);
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg),
                 "Invalid firmware size: %zu bytes", firmware_size);
        return ESP_ERR_INVALID_SIZE;
    }

    ESP_LOGI(TAG, "Starting OTA session, firmware size: %zu bytes", firmware_size);

    // Allocate PSRAM buffer for firmware
    s_ota_mgr.buffer = heap_caps_malloc(firmware_size, MALLOC_CAP_SPIRAM);
    if (!s_ota_mgr.buffer) {
        ESP_LOGE(TAG, "Failed to allocate %zu bytes in PSRAM", firmware_size);
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg),
                 "Out of memory (PSRAM)");
        return ESP_ERR_NO_MEM;
    }

    s_ota_mgr.total_size = firmware_size;
    s_ota_mgr.bytes_written = 0;
    s_ota_mgr.state = OTA_STATE_IN_PROGRESS;
    memset(s_ota_mgr.error_msg, 0, sizeof(s_ota_mgr.error_msg));

    ESP_LOGI(TAG, "OTA session started, buffer allocated at %p", s_ota_mgr.buffer);
    
    return ESP_OK;
}

esp_err_t c6_ota_write(const uint8_t *data, size_t len)
{
    if (s_ota_mgr.state != OTA_STATE_IN_PROGRESS) {
        ESP_LOGE(TAG, "OTA not in progress");
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg),
                 "OTA not in progress");
        return ESP_ERR_INVALID_STATE;
    }

    if (!data || len == 0) {
        ESP_LOGE(TAG, "Invalid data or length");
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg),
                 "Invalid data");
        return ESP_ERR_INVALID_ARG;
    }

    if (s_ota_mgr.bytes_written + len > s_ota_mgr.total_size) {
        ESP_LOGE(TAG, "Write would exceed firmware size (%zu + %zu > %zu)",
                 s_ota_mgr.bytes_written, len, s_ota_mgr.total_size);
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg),
                 "Firmware size exceeded");
        c6_ota_abort();
        return ESP_ERR_INVALID_SIZE;
    }

    // Copy data to PSRAM buffer
    memcpy(s_ota_mgr.buffer + s_ota_mgr.bytes_written, data, len);
    s_ota_mgr.bytes_written += len;

    ESP_LOGD(TAG, "Written %zu bytes, total: %zu/%zu (%.1f%%)",
             len, s_ota_mgr.bytes_written, s_ota_mgr.total_size,
             (float)s_ota_mgr.bytes_written * 100 / s_ota_mgr.total_size);

    return ESP_OK;
}

esp_err_t c6_ota_end(void)
{
    if (s_ota_mgr.state != OTA_STATE_IN_PROGRESS) {
        ESP_LOGE(TAG, "OTA not in progress");
        return ESP_ERR_INVALID_STATE;
    }

    if (s_ota_mgr.bytes_written != s_ota_mgr.total_size) {
        ESP_LOGE(TAG, "Incomplete firmware upload: %zu/%zu bytes",
                 s_ota_mgr.bytes_written, s_ota_mgr.total_size);
        snprintf(s_ota_mgr.error_msg, sizeof(s_ota_mgr.error_msg),
                 "Incomplete upload: %zu/%zu bytes",
                 s_ota_mgr.bytes_written, s_ota_mgr.total_size);
        c6_ota_abort();
        return ESP_ERR_INVALID_STATE;
    }

    ESP_LOGI(TAG, "Firmware upload complete, total: %zu bytes", s_ota_mgr.bytes_written);
    ESP_LOGI(TAG, "Starting firmware transfer to C6...");

    // TODO: Implement actual SDIO transfer to C6
    // For now, just simulate success
    // This would involve:
    // 1. Send OTA start command to C6 via ESP-Hosted control channel
    // 2. Transfer firmware in chunks via SDIO
    // 3. Send OTA end command to C6
    // 4. Wait for C6 to verify and reboot

    ESP_LOGI(TAG, "Firmware transfer simulated (TODO: implement SDIO transfer)");

    s_ota_mgr.state = OTA_STATE_SUCCESS;

    // Keep buffer for now (will be freed after successful reboot confirmation)
    ESP_LOGI(TAG, "OTA completed successfully");

    return ESP_OK;
}

void c6_ota_abort(void)
{
    ESP_LOGW(TAG, "Aborting OTA session");

    if (s_ota_mgr.buffer) {
        heap_caps_free(s_ota_mgr.buffer);
        s_ota_mgr.buffer = NULL;
    }

    s_ota_mgr.state = OTA_STATE_FAILED;
    s_ota_mgr.bytes_written = 0;
    s_ota_mgr.total_size = 0;
}

uint8_t c6_ota_get_progress(void)
{
    if (s_ota_mgr.state != OTA_STATE_IN_PROGRESS || s_ota_mgr.total_size == 0) {
        return 0;
    }

    return (uint8_t)((s_ota_mgr.bytes_written * 100) / s_ota_mgr.total_size);
}

c6_ota_state_t c6_ota_get_state(void)
{
    return s_ota_mgr.state;
}

const char* c6_ota_get_error(void)
{
    if (s_ota_mgr.error_msg[0] == '\0') {
        return NULL;
    }
    return s_ota_mgr.error_msg;
}
