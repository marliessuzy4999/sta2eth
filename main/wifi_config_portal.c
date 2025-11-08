/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * WiFi Configuration Portal for ESP32-P4 + C6
 * 
 * Uses SoftAP on C6 for configuration via mobile phone
 * Separate compilation unit to use WiFi remote types
 */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

// Include injected headers BEFORE esp_wifi_remote.h
#include "injected/esp_wifi.h"
#include "esp_wifi_remote.h"

#include "esp_event.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "esp_http_server.h"
#include "dns_server.h"
#include "wifi_config_portal.h"

static const char *TAG = "wifi_config_portal";

static httpd_handle_t s_web_server = NULL;
static EventGroupHandle_t *s_event_flags = NULL;
static int s_success_bit;
static esp_netif_t *s_ap_netif = NULL;

// SoftAP configuration
#define SOFTAP_SSID       "ESP32-P4-Config"
#define SOFTAP_CHANNEL    6
#define SOFTAP_MAX_CONN   4

// HTML configuration page with WiFi scanning
static const char config_page_html[] = 
"<!DOCTYPE html><html><head>"
"<meta charset='UTF-8'><meta name='viewport' content='width=device-width,initial-scale=1'>"
"<title>ESP32-P4 WiFi Setup</title>"
"<style>"
"*{margin:0;padding:0;box-sizing:border-box}"
"body{font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Roboto,sans-serif;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);min-height:100vh;padding:20px}"
".container{max-width:500px;margin:0 auto;background:white;border-radius:20px;box-shadow:0 20px 60px rgba(0,0,0,0.3);overflow:hidden}"
".header{background:linear-gradient(135deg,#667eea,#764ba2);color:white;padding:30px;text-align:center}"
".header h1{font-size:24px;margin-bottom:10px}"
".header p{opacity:0.9;font-size:14px}"
".content{padding:30px}"
".network-list{margin:20px 0}"
".network-item{display:flex;align-items:center;padding:15px;margin:10px 0;background:#f8f9fa;border:2px solid transparent;border-radius:10px;cursor:pointer;transition:all 0.3s}"
".network-item:hover{background:#e9ecef;border-color:#667eea}"
".network-item.selected{background:#667eea;color:white;border-color:#667eea}"
".network-item .signal{margin-right:15px;font-size:20px}"
".network-item .ssid{flex:1;font-weight:500}"
".network-item .lock{font-size:16px;opacity:0.6}"
".form-group{margin:20px 0}"
".form-group label{display:block;margin-bottom:8px;font-weight:600;color:#333}"
".form-group input{width:100%;padding:12px;border:2px solid #e0e0e0;border-radius:8px;font-size:16px;transition:border 0.3s}"
".form-group input:focus{outline:none;border-color:#667eea}"
".btn{width:100%;padding:15px;background:linear-gradient(135deg,#667eea,#764ba2);color:white;border:none;border-radius:10px;font-size:16px;font-weight:600;cursor:pointer;transition:transform 0.2s}"
".btn:hover{transform:translateY(-2px)}"
".btn:active{transform:translateY(0)}"
".btn:disabled{opacity:0.6;cursor:not-allowed}"
".status{margin:20px 0;padding:15px;border-radius:10px;text-align:center;display:none}"
".status.show{display:block}"
".status.info{background:#e3f2fd;color:#1976d2}"
".status.success{background:#e8f5e9;color:#388e3c}"
".status.error{background:#ffebee;color:#c62828}"
".loading{display:inline-block;width:20px;height:20px;border:3px solid rgba(255,255,255,0.3);border-radius:50%;border-top-color:white;animation:spin 1s linear infinite}"
"@keyframes spin{to{transform:rotate(360deg)}}"
"</style></head><body>"
"<div class='container'>"
"<div class='header'><h1>🌐 WiFi Configuration</h1><p>ESP32-P4 + C6 Bridge</p></div>"
"<div class='content'>"
"<button class='btn' onclick='scanNetworks()' id='scanBtn'>📡 Scan Networks</button>"
"<div class='network-list' id='networkList'></div>"
"<div class='form-group'><label>WiFi Name (SSID)</label>"
"<input type='text' id='ssid' placeholder='Select network or enter SSID'></div>"
"<div class='form-group'><label>Password</label>"
"<input type='password' id='password' placeholder='Enter WiFi password'></div>"
"<button class='btn' onclick='connectWiFi()' id='connectBtn'>✓ Connect</button>"
"<div class='status' id='status'></div>"
"</div></div>"
"<script>"
"let selectedSSID='';"
"function selectNetwork(ssid,btn){selectedSSID=ssid;document.getElementById('ssid').value=ssid;"
"document.querySelectorAll('.network-item').forEach(el=>el.classList.remove('selected'));"
"btn.classList.add('selected');document.getElementById('password').focus();}"
"function showStatus(msg,type){const s=document.getElementById('status');s.className='status show '+type;s.innerHTML=msg;}"
"function scanNetworks(){const btn=document.getElementById('scanBtn');"
"btn.disabled=true;btn.innerHTML='<span class=\"loading\"></span> Scanning...';"
"fetch('/scan').then(r=>r.json()).then(data=>{"
"const list=document.getElementById('networkList');"
"if(data.networks.length===0){list.innerHTML='<p style=\"text-align:center;color:#999;padding:20px\">No networks found</p>';}"
"else{list.innerHTML=data.networks.map(n=>"
"'<div class=\"network-item\" onclick=\"selectNetwork(\\''+n.ssid+'\\',this)\">"
"<span class=\"signal\">'+getSignalIcon(n.rssi)+'</span>"
"<span class=\"ssid\">'+n.ssid+'</span>"
"<span class=\"lock\">'+(n.auth!==0?'🔒':'')+'</span></div>').join('');}"
"btn.disabled=false;btn.innerHTML='📡 Scan Networks';}).catch(e=>{"
"showStatus('Scan failed: '+e,'error');btn.disabled=false;btn.innerHTML='📡 Scan Networks';});}"
"function getSignalIcon(rssi){if(rssi>-50)return'📶';if(rssi>-70)return'📶';return'📶';}"
"function connectWiFi(){const ssid=document.getElementById('ssid').value.trim();"
"const pwd=document.getElementById('password').value;"
"if(!ssid){showStatus('Please select or enter WiFi network','error');return;}"
"if(!pwd){showStatus('Please enter password','error');return;}"
"const btn=document.getElementById('connectBtn');"
"btn.disabled=true;btn.innerHTML='<span class=\"loading\"></span> Connecting...';"
"showStatus('Connecting to '+ssid+'...','info');"
"fetch('/connect?ssid='+encodeURIComponent(ssid)+'&password='+encodeURIComponent(pwd))"
".then(r=>r.json()).then(data=>{"
"if(data.success){showStatus('✓ Connected! Device will restart...','success');"
"setTimeout(()=>window.location.reload(),3000);}"
"else{showStatus('✗ Connection failed: '+data.message,'error');"
"btn.disabled=false;btn.innerHTML='✓ Connect';}}).catch(e=>{"
"showStatus('✗ Error: '+e,'error');btn.disabled=false;btn.innerHTML='✓ Connect';});}"
"window.onload=scanNetworks;"
"</script></body></html>";

/**
 * Root page handler
 */
static esp_err_t root_handler(httpd_req_t *req)
{
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, config_page_html, strlen(config_page_html));
    return ESP_OK;
}

/**
 * Captive portal redirect handler for common detection URLs
 * This handles requests to domains like:
 * - connectivitycheck.gstatic.com (Android)
 * - captive.apple.com (iOS)
 * - www.msftconnecttest.com (Windows)
 */
static esp_err_t captive_portal_redirect_handler(httpd_req_t *req)
{
    // Return 302 redirect to our config page
    httpd_resp_set_status(req, "302 Found");
    httpd_resp_set_hdr(req, "Location", "http://192.168.4.1/");
    httpd_resp_send(req, NULL, 0);
    return ESP_OK;
}

/**
 * WiFi scan handler
 */
static esp_err_t scan_handler(httpd_req_t *req)
{
    ESP_LOGI(TAG, "Scanning WiFi networks...");
    
    wifi_scan_config_t scan_config = {
        .ssid = NULL,
        .bssid = NULL,
        .channel = 0,
        .show_hidden = false
    };
    
    // Start scan
    // Regular esp_wifi API - forwarded to C6 via esp_wifi_remote
    esp_err_t ret = esp_wifi_scan_start(&scan_config, true);
    if (ret != ESP_OK) {
        httpd_resp_set_type(req, "application/json");
        httpd_resp_sendstr(req, "{\"networks\":[]}");
        return ESP_OK;
    }
    
    // Get scan results
    uint16_t ap_count = 0;
    esp_wifi_scan_get_ap_num(&ap_count);
    
    char json[4096] = "{\"networks\":[";
    size_t offset = strlen(json);
    
    if (ap_count > 0) {
        wifi_ap_record_t *ap_records = malloc(sizeof(wifi_ap_record_t) * ap_count);
        if (ap_records) {
            ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_count, ap_records));
            
            for (int i = 0; i < ap_count && offset < sizeof(json) - 200; i++) {
                if (i > 0) {
                    offset += snprintf(json + offset, sizeof(json) - offset, ",");
                }
                offset += snprintf(json + offset, sizeof(json) - offset,
                    "{\"ssid\":\"%s\",\"rssi\":%d,\"auth\":%d}",
                    ap_records[i].ssid,
                    ap_records[i].rssi,
                    ap_records[i].authmode);
            }
            free(ap_records);
        }
    }
    
    snprintf(json + offset, sizeof(json) - offset, "]}");
    
    httpd_resp_set_type(req, "application/json");
    httpd_resp_sendstr(req, json);
    
    return ESP_OK;
}

/**
 * WiFi connect handler
 */
static esp_err_t connect_handler(httpd_req_t *req)
{
    char ssid[33] = {0};
    char password[65] = {0};
    
    // Parse query
    char query[256];
    if (httpd_req_get_url_query_str(req, query, sizeof(query)) == ESP_OK) {
        httpd_query_key_value(query, "ssid", ssid, sizeof(ssid));
        httpd_query_key_value(query, "password", password, sizeof(password));
    }
    
    if (strlen(ssid) == 0) {
        httpd_resp_set_type(req, "application/json");
        httpd_resp_sendstr(req, "{\"success\":false,\"message\":\"SSID empty\"}");
        return ESP_OK;
    }
    
    ESP_LOGI(TAG, "Configuring WiFi: %s", ssid);
    
    // Save configuration
    wifi_config_t wifi_config = {0};
    strlcpy((char *)wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    strlcpy((char *)wifi_config.sta.password, password, sizeof(wifi_config.sta.password));
    
    // Regular esp_wifi APIs - forwarded to C6
    esp_err_t ret = esp_wifi_set_storage(WIFI_STORAGE_FLASH);
    ret |= esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    
    if (ret == ESP_OK) {
        httpd_resp_set_type(req, "application/json");
        httpd_resp_sendstr(req, "{\"success\":true,\"message\":\"Configuration saved\"}");
        
        // Signal success
        if (s_event_flags) {
            vTaskDelay(pdMS_TO_TICKS(1000));
            xEventGroupSetBits(*s_event_flags, s_success_bit);
        }
    } else {
        httpd_resp_set_type(req, "application/json");
        httpd_resp_sendstr(req, "{\"success\":false,\"message\":\"Failed to save\"}");
    }
    
    return ESP_OK;
}

static const httpd_uri_t uri_root = {.uri = "/", .method = HTTP_GET, .handler = root_handler};
static const httpd_uri_t uri_scan = {.uri = "/scan", .method = HTTP_GET, .handler = scan_handler};
static const httpd_uri_t uri_connect = {.uri = "/connect", .method = HTTP_GET, .handler = connect_handler};

// Captive portal detection URLs
static const httpd_uri_t uri_generate_204 = {.uri = "/generate_204", .method = HTTP_GET, .handler = captive_portal_redirect_handler};
static const httpd_uri_t uri_hotspot = {.uri = "/hotspot-detect.html", .method = HTTP_GET, .handler = captive_portal_redirect_handler};
static const httpd_uri_t uri_connecttest = {.uri = "/connecttest.txt", .method = HTTP_GET, .handler = captive_portal_redirect_handler};
static const httpd_uri_t uri_redirect = {.uri = "/redirect", .method = HTTP_GET, .handler = captive_portal_redirect_handler};
static const httpd_uri_t uri_success = {.uri = "/success.txt", .method = HTTP_GET, .handler = captive_portal_redirect_handler};

/**
 * Start web server
 */
static void start_webserver(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.max_open_sockets = 5;
    config.lru_purge_enable = true;

    ESP_LOGI(TAG, "Starting web server");
    if (httpd_start(&s_web_server, &config) == ESP_OK) {
        httpd_register_uri_handler(s_web_server, &uri_root);
        httpd_register_uri_handler(s_web_server, &uri_scan);
        httpd_register_uri_handler(s_web_server, &uri_connect);
        
        // Register captive portal detection URLs for auto-popup
        httpd_register_uri_handler(s_web_server, &uri_generate_204);  // Android
        httpd_register_uri_handler(s_web_server, &uri_hotspot);        // iOS
        httpd_register_uri_handler(s_web_server, &uri_connecttest);    // Windows
        httpd_register_uri_handler(s_web_server, &uri_redirect);       // Generic
        httpd_register_uri_handler(s_web_server, &uri_success);        // Generic
        
        ESP_LOGI(TAG, "Captive portal handlers registered for auto-popup");
    }
}

/**
 * WiFi event handler for AP mode
 */
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    if (event_id == WIFI_EVENT_AP_STACONNECTED) {
        wifi_event_ap_staconnected_t *event = (wifi_event_ap_staconnected_t *)event_data;
        ESP_LOGI(TAG, "Station connected, MAC:" MACSTR, MAC2STR(event->mac));
    } else if (event_id == WIFI_EVENT_AP_STADISCONNECTED) {
        wifi_event_ap_stadisconnected_t *event = (wifi_event_ap_stadisconnected_t *)event_data;
        ESP_LOGI(TAG, "Station disconnected, MAC:" MACSTR, MAC2STR(event->mac));
    }
}

/**
 * Start WiFi configuration portal
 */
esp_err_t start_wifi_config_portal(EventGroupHandle_t *flags, int success_bit, int fail_bit)
{
    ESP_LOGI(TAG, "Starting WiFi configuration portal");
    
    s_event_flags = flags;
    s_success_bit = success_bit;
    
    // Create AP netif
    s_ap_netif = esp_netif_create_default_wifi_ap();
    
    // Initialize WiFi in AP mode
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_remote_init(&cfg));
    
    // Register event handler
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_REMOTE_EVENT, ESP_EVENT_ANY_ID,
                                               wifi_event_handler, NULL));
    
    // Configure AP
    wifi_config_t ap_config = {
        .ap = {
            .ssid = SOFTAP_SSID,
            .ssid_len = strlen(SOFTAP_SSID),
            .channel = SOFTAP_CHANNEL,
            .password = "",
            .max_connection = SOFTAP_MAX_CONN,
            .authmode = WIFI_AUTH_OPEN,
        },
    };
    
    // Use regular esp_wifi APIs - transparently forwarded to C6 via esp_wifi_remote
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &ap_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    
    ESP_LOGI(TAG, "SoftAP started: SSID=%s", SOFTAP_SSID);
    
    // Start web server
    start_webserver();
    
    // Start DNS server for captive portal
    dns_server_config_t dns_config = DNS_SERVER_CONFIG_SINGLE("*", "ap");
    start_dns_server(&dns_config);
    
    ESP_LOGI(TAG, "Configuration portal ready:");
    ESP_LOGI(TAG, "  1. Connect phone to WiFi: %s (no password)", SOFTAP_SSID);
    ESP_LOGI(TAG, "  2. Browser will auto-open or go to: http://192.168.4.1");
    ESP_LOGI(TAG, "  3. Select your WiFi network and enter password");
    
    return ESP_OK;
}

/**
 * Check if WiFi is provisioned
 */
bool is_wifi_provisioned(void)
{
    wifi_config_t wifi_cfg;
    if (esp_wifi_get_config(WIFI_IF_STA, &wifi_cfg) != ESP_OK) {
        return false;
    }
    return (wifi_cfg.sta.ssid[0] != 0);
}
