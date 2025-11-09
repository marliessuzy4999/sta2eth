/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include "c6_version_check.h"
#include "esp_log.h"
#include "esp_wifi_remote.h"

static const char *TAG = "c6_version";

// Minimum required C6 firmware version (from config or hardcoded)
#ifndef CONFIG_C6_OTA_MIN_VERSION_MAJOR
#define CONFIG_C6_OTA_MIN_VERSION_MAJOR 1
#endif

#ifndef CONFIG_C6_OTA_MIN_VERSION_MINOR
#define CONFIG_C6_OTA_MIN_VERSION_MINOR 2
#endif

#ifndef CONFIG_C6_OTA_MIN_VERSION_PATCH
#define CONFIG_C6_OTA_MIN_VERSION_PATCH 0
#endif

esp_err_t c6_get_firmware_version(firmware_version_t *version, uint32_t timeout_ms)
{
    if (!version) {
        return ESP_ERR_INVALID_ARG;
    }

    // Initialize version structure
    memset(version, 0, sizeof(firmware_version_t));

    // Try to get WiFi remote version information
    // Note: esp_wifi_remote doesn't have a direct version query API
    // For now, we'll attempt to initialize WiFi remote and check if it succeeds
    // In a full implementation, this would query the ESP-Hosted version via control channel
    
    ESP_LOGI(TAG, "Attempting to query C6 firmware version...");
    
    // For initial implementation, we'll set a placeholder version
    // TODO: Implement actual ESP-Hosted control channel version query
    // Reference: https://github.com/espressif/esp-hosted/blob/master/host/control_lib/include/ctrl_api.h
    
    version->major = 1;
    version->minor = 0;
    version->patch = 0;
    strncpy(version->git_hash, "unknown", sizeof(version->git_hash) - 1);
    
    ESP_LOGI(TAG, "C6 firmware version: %d.%d.%d (%s)", 
             version->major, version->minor, version->patch, version->git_hash);
    
    return ESP_OK;
}

bool c6_version_is_compatible(firmware_version_t *c6_ver, firmware_version_t *min_ver)
{
    if (!c6_ver || !min_ver) {
        return false;
    }

    // Compare major version
    if (c6_ver->major > min_ver->major) {
        return true;
    }
    if (c6_ver->major < min_ver->major) {
        return false;
    }

    // Major versions equal, compare minor
    if (c6_ver->minor > min_ver->minor) {
        return true;
    }
    if (c6_ver->minor < min_ver->minor) {
        return false;
    }

    // Major and minor equal, compare patch
    return c6_ver->patch >= min_ver->patch;
}

bool c6_needs_firmware_upgrade(uint32_t timeout_ms)
{
    firmware_version_t c6_ver;
    firmware_version_t min_ver = {
        .major = CONFIG_C6_OTA_MIN_VERSION_MAJOR,
        .minor = CONFIG_C6_OTA_MIN_VERSION_MINOR,
        .patch = CONFIG_C6_OTA_MIN_VERSION_PATCH
    };

    ESP_LOGI(TAG, "Checking if C6 firmware upgrade is needed...");
    ESP_LOGI(TAG, "Minimum required version: %d.%d.%d", 
             min_ver.major, min_ver.minor, min_ver.patch);

    esp_err_t ret = c6_get_firmware_version(&c6_ver, timeout_ms);
    if (ret != ESP_OK) {
        ESP_LOGW(TAG, "Failed to get C6 firmware version (error: %d), assuming upgrade needed", ret);
        return true;  // If we can't get version, trigger OTA mode
    }

    bool compatible = c6_version_is_compatible(&c6_ver, &min_ver);
    
    if (!compatible) {
        ESP_LOGW(TAG, "C6 firmware version %d.%d.%d is older than minimum required %d.%d.%d",
                 c6_ver.major, c6_ver.minor, c6_ver.patch,
                 min_ver.major, min_ver.minor, min_ver.patch);
        ESP_LOGW(TAG, "C6 firmware upgrade is REQUIRED");
    } else {
        ESP_LOGI(TAG, "C6 firmware version is compatible, no upgrade needed");
    }

    return !compatible;
}
