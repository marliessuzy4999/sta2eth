/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <sys/param.h>
#include "ota_webserver.h"
#include "c6_ota_manager.h"
#include "c6_version_check.h"
#include "esp_log.h"
#include "esp_http_server.h"

static const char *TAG = "ota_webserver";

static httpd_handle_t s_server = NULL;

// HTML page for OTA upload
static const char ota_html_page[] = 
"<!DOCTYPE html>"
"<html>"
"<head>"
"    <meta charset='UTF-8'>"
"    <meta name='viewport' content='width=device-width, initial-scale=1.0'>"
"    <title>ESP32-C6 OTA Upgrade</title>"
"    <style>"
"        body { font-family: Arial, sans-serif; margin: 40px; background: #f5f5f5; }"
"        .container { max-width: 600px; margin: auto; background: white; padding: 30px; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }"
"        h1 { color: #333; text-align: center; }"
"        .version-info { background: #e8f4f8; padding: 15px; margin: 20px 0; border-radius: 4px; border-left: 4px solid #2196F3; }"
"        .version-info h3 { margin-top: 0; color: #1976D2; }"
"        .version-info p { margin: 8px 0; }"
"        .upload-form { border: 2px dashed #ccc; padding: 30px; text-align: center; margin: 20px 0; border-radius: 4px; }"
"        .upload-form:hover { border-color: #2196F3; background: #fafafa; }"
"        input[type='file'] { margin: 20px 0; }"
"        button { background: #2196F3; color: white; border: none; padding: 12px 30px; font-size: 16px; border-radius: 4px; cursor: pointer; }"
"        button:hover { background: #1976D2; }"
"        button:disabled { background: #ccc; cursor: not-allowed; }"
"        .progress-bar { width: 100%; height: 30px; background: #f0f0f0; margin: 20px 0; border-radius: 4px; overflow: hidden; display: none; }"
"        .progress-fill { height: 100%; background: linear-gradient(90deg, #4CAF50, #8BC34A); width: 0%; transition: width 0.3s; text-align: center; line-height: 30px; color: white; font-weight: bold; }"
"        .status { margin: 20px 0; padding: 15px; border-radius: 4px; display: none; }"
"        .success { background: #d4edda; color: #155724; border: 1px solid #c3e6cb; }"
"        .error { background: #f8d7da; color: #721c24; border: 1px solid #f5c6cb; }"
"        .warning { background: #fff3cd; color: #856404; border: 1px solid #ffeaa7; }"
"        .info { background: #d1ecf1; color: #0c5460; border: 1px solid #bee5eb; }"
"        .spinner { border: 3px solid #f3f3f3; border-top: 3px solid #2196F3; border-radius: 50%; width: 20px; height: 20px; animation: spin 1s linear infinite; display: inline-block; margin-right: 10px; }"
"        @keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }"
"    </style>"
"</head>"
"<body>"
"    <div class='container'>"
"        <h1>🔧 ESP32-C6 Firmware OTA Upgrade</h1>"
"        <div class='version-info'>"
"            <h3>Version Information</h3>"
"            <p>Current C6 Version: <strong id='current-version'>Checking...</strong></p>"
"            <p>Minimum Required: <strong id='min-version'>1.2.0</strong></p>"
"            <p>Status: <span id='version-status'>Checking...</span></p>"
"        </div>"
"        <div class='upload-form'>"
"            <h3>📤 Upload Firmware</h3>"
"            <p>Select ESP32-C6 firmware binary file (.bin)</p>"
"            <input type='file' id='firmware-file' accept='.bin'>"
"            <br><button id='upload-btn' onclick='uploadFirmware()'>Start Upgrade</button>"
"        </div>"
"        <div class='progress-bar' id='progress-container'>"
"            <div class='progress-fill' id='progress-fill'>0%</div>"
"        </div>"
"        <div id='status-message' class='status'></div>"
"    </div>"
"    <script>"
"        function showStatus(message, type) {"
"            var statusDiv = document.getElementById('status-message');"
"            statusDiv.textContent = message;"
"            statusDiv.className = 'status ' + type;"
"            statusDiv.style.display = 'block';"
"        }"
"        function updateProgress(percent) {"
"            var progressBar = document.getElementById('progress-container');"
"            var progressFill = document.getElementById('progress-fill');"
"            progressBar.style.display = 'block';"
"            progressFill.style.width = percent + '%';"
"            progressFill.textContent = percent + '%';"
"        }"
"        function checkVersion() {"
"            fetch('/api/version')"
"                .then(response => response.json())"
"                .then(data => {"
"                    document.getElementById('current-version').textContent = data.current || 'Unknown';"
"                    document.getElementById('min-version').textContent = data.minimum || '1.2.0';"
"                    document.getElementById('version-status').textContent = data.compatible ? '✅ OK' : '⚠️ Upgrade Required';"
"                })"
"                .catch(err => {"
"                    document.getElementById('current-version').textContent = 'Error';"
"                    document.getElementById('version-status').textContent = '❌ Cannot check';"
"                });"
"        }"
"        function uploadFirmware() {"
"            var fileInput = document.getElementById('firmware-file');"
"            var uploadBtn = document.getElementById('upload-btn');"
"            var file = fileInput.files[0];"
"            if (!file) {"
"                showStatus('⚠️ Please select a firmware file first!', 'warning');"
"                return;"
"            }"
"            uploadBtn.disabled = true;"
"            uploadBtn.textContent = 'Uploading...';"
"            showStatus('📡 Uploading firmware... Please wait.', 'info');"
"            updateProgress(0);"
"            var formData = new FormData();"
"            formData.append('firmware', file);"
"            var xhr = new XMLHttpRequest();"
"            xhr.upload.addEventListener('progress', function(e) {"
"                if (e.lengthComputable) {"
"                    var percent = Math.round((e.loaded / e.total) * 100);"
"                    updateProgress(percent);"
"                }"
"            });"
"            xhr.addEventListener('load', function() {"
"                if (xhr.status === 200) {"
"                    showStatus('✅ Firmware uploaded successfully! C6 will restart.', 'success');"
"                    uploadBtn.textContent = 'Upload Complete';"
"                    setTimeout(function() { location.reload(); }, 5000);"
"                } else {"
"                    showStatus('❌ Upload failed: ' + xhr.responseText, 'error');"
"                    uploadBtn.disabled = false;"
"                    uploadBtn.textContent = 'Retry Upload';"
"                }"
"            });"
"            xhr.addEventListener('error', function() {"
"                showStatus('❌ Network error during upload', 'error');"
"                uploadBtn.disabled = false;"
"                uploadBtn.textContent = 'Retry Upload';"
"            });"
"            xhr.open('POST', '/api/upload', true);"
"            xhr.send(formData);"
"        }"
"        checkVersion();"
"    </script>"
"</body>"
"</html>";

/* Handler for root path */
static esp_err_t ota_root_handler(httpd_req_t *req)
{
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, ota_html_page, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

/* Handler for version API */
static esp_err_t ota_version_handler(httpd_req_t *req)
{
    firmware_version_t c6_ver;
    firmware_version_t min_ver = {
        .major = 1,
        .minor = 2,
        .patch = 0
    };

    char json_resp[256];
    bool compatible = false;
    
    esp_err_t ret = c6_get_firmware_version(&c6_ver, 5000);
    if (ret == ESP_OK) {
        compatible = c6_version_is_compatible(&c6_ver, &min_ver);
        snprintf(json_resp, sizeof(json_resp),
                 "{\"current\":\"%d.%d.%d\",\"minimum\":\"%d.%d.%d\",\"compatible\":%s}",
                 c6_ver.major, c6_ver.minor, c6_ver.patch,
                 min_ver.major, min_ver.minor, min_ver.patch,
                 compatible ? "true" : "false");
    } else {
        snprintf(json_resp, sizeof(json_resp),
                 "{\"current\":\"unknown\",\"minimum\":\"%d.%d.%d\",\"compatible\":false}",
                 min_ver.major, min_ver.minor, min_ver.patch);
    }

    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, json_resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

/* Handler for firmware upload */
static esp_err_t ota_upload_handler(httpd_req_t *req)
{
    char buf[512];
    size_t received = 0;
    size_t total_size = req->content_len;
    bool ota_started = false;

    ESP_LOGI(TAG, "Firmware upload started, size: %zu bytes", total_size);

    // Start OTA session
    esp_err_t ret = c6_ota_begin(total_size);
    if (ret != ESP_OK) {
        const char *err = c6_ota_get_error();
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, 
                           err ? err : "Failed to start OTA");
        return ESP_FAIL;
    }
    ota_started = true;

    // Receive and write firmware data
    while (received < total_size) {
        int recv_len = httpd_req_recv(req, buf, MIN(sizeof(buf), total_size - received));
        
        if (recv_len < 0) {
            if (recv_len == HTTPD_SOCK_ERR_TIMEOUT) {
                ESP_LOGW(TAG, "Socket timeout, continuing...");
                continue;
            }
            ESP_LOGE(TAG, "Failed to receive data");
            c6_ota_abort();
            httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Upload interrupted");
            return ESP_FAIL;
        }

        ret = c6_ota_write((uint8_t*)buf, recv_len);
        if (ret != ESP_OK) {
            const char *err = c6_ota_get_error();
            ESP_LOGE(TAG, "OTA write failed");
            c6_ota_abort();
            httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR,
                               err ? err : "OTA write failed");
            return ESP_FAIL;
        }

        received += recv_len;
        
        if (received % (64 * 1024) == 0 || received == total_size) {
            ESP_LOGI(TAG, "Upload progress: %zu/%zu bytes (%.1f%%)",
                     received, total_size, (float)received * 100 / total_size);
        }
    }

    ESP_LOGI(TAG, "Firmware upload complete, finalizing OTA...");

    // Complete OTA
    ret = c6_ota_end();
    if (ret != ESP_OK) {
        const char *err = c6_ota_get_error();
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR,
                           err ? err : "OTA finalization failed");
        return ESP_FAIL;
    }

    // Send success response
    httpd_resp_send(req, "Firmware uploaded successfully", HTTPD_RESP_USE_STRLEN);
    
    ESP_LOGI(TAG, "OTA completed successfully");
    
    return ESP_OK;
}

esp_err_t ota_webserver_start(void)
{
    if (s_server != NULL) {
        ESP_LOGW(TAG, "OTA web server already running");
        return ESP_OK;
    }

    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.server_port = 80;
    config.max_uri_handlers = 8;
    config.stack_size = 8192;  // Increased for file upload
    config.lru_purge_enable = true;

    ESP_LOGI(TAG, "Starting OTA web server on port %d", config.server_port);

    esp_err_t ret = httpd_start(&s_server, &config);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start HTTP server: %s", esp_err_to_name(ret));
        return ret;
    }

    // Register URI handlers
    httpd_uri_t root_uri = {
        .uri = "/",
        .method = HTTP_GET,
        .handler = ota_root_handler,
        .user_ctx = NULL
    };
    httpd_register_uri_handler(s_server, &root_uri);

    httpd_uri_t version_uri = {
        .uri = "/api/version",
        .method = HTTP_GET,
        .handler = ota_version_handler,
        .user_ctx = NULL
    };
    httpd_register_uri_handler(s_server, &version_uri);

    httpd_uri_t upload_uri = {
        .uri = "/api/upload",
        .method = HTTP_POST,
        .handler = ota_upload_handler,
        .user_ctx = NULL
    };
    httpd_register_uri_handler(s_server, &upload_uri);

    ESP_LOGI(TAG, "OTA web server started successfully");
    ESP_LOGI(TAG, "Access the OTA interface at: http://192.168.100.1/");

    return ESP_OK;
}

void ota_webserver_stop(void)
{
    if (s_server) {
        ESP_LOGI(TAG, "Stopping OTA web server");
        httpd_stop(s_server);
        s_server = NULL;
    }
}

bool ota_webserver_is_running(void)
{
    return s_server != NULL;
}
