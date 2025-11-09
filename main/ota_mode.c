/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include "ota_mode.h"
#include "c6_version_check.h"
#include "ota_webserver.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_eth.h"
#include "ethernet_init.h"
#include "esp_event.h"

static const char *TAG = "ota_mode";

#ifndef CONFIG_C6_OTA_ENABLED
#define CONFIG_C6_OTA_ENABLED 1
#endif

#ifndef CONFIG_C6_OTA_VERSION_QUERY_TIMEOUT_MS
#define CONFIG_C6_OTA_VERSION_QUERY_TIMEOUT_MS 10000
#endif

#ifndef CONFIG_C6_OTA_NETWORK_IP
#define CONFIG_C6_OTA_NETWORK_IP "192.168.100.1"
#endif

#ifndef CONFIG_C6_OTA_NETWORK_NETMASK
#define CONFIG_C6_OTA_NETWORK_NETMASK "255.255.255.0"
#endif

bool should_enter_ota_mode(void)
{
#if CONFIG_C6_OTA_ENABLED
    ESP_LOGI(TAG, "Checking if OTA mode is needed...");
    
    // Check if C6 firmware needs upgrade
    bool needs_upgrade = c6_needs_firmware_upgrade(CONFIG_C6_OTA_VERSION_QUERY_TIMEOUT_MS);
    
    if (needs_upgrade) {
        ESP_LOGW(TAG, "C6 firmware upgrade required, entering OTA mode");
        return true;
    }
    
    ESP_LOGI(TAG, "C6 firmware version is OK, skipping OTA mode");
    return false;
#else
    return false;
#endif
}

/**
 * @brief Event handler for Ethernet in OTA mode
 */
static void ota_eth_event_handler(void *arg, esp_event_base_t event_base,
                                  int32_t event_id, void *event_data)
{
    uint8_t mac_addr[6] = {0};
    esp_eth_handle_t eth_handle = *(esp_eth_handle_t *)event_data;

    switch (event_id) {
    case ETHERNET_EVENT_CONNECTED:
        ESP_LOGI(TAG, "Ethernet Link Up in OTA mode");
        esp_eth_ioctl(eth_handle, ETH_CMD_G_MAC_ADDR, mac_addr);
        ESP_LOGI(TAG, "Ethernet HW Addr %02x:%02x:%02x:%02x:%02x:%02x",
                 mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
        break;
    case ETHERNET_EVENT_DISCONNECTED:
        ESP_LOGW(TAG, "Ethernet Link Down in OTA mode");
        break;
    case ETHERNET_EVENT_START:
        ESP_LOGI(TAG, "Ethernet Started in OTA mode");
        break;
    case ETHERNET_EVENT_STOP:
        ESP_LOGI(TAG, "Ethernet Stopped in OTA mode");
        break;
    default:
        break;
    }
}

esp_err_t start_ota_mode(void)
{
    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "   Starting C6 OTA Mode");
    ESP_LOGI(TAG, "========================================");
    
    // Initialize netif
    ESP_ERROR_CHECK(esp_netif_init());
    
    // Create default event loop if not already created
    esp_event_loop_create_default();
    
    // Create Ethernet netif with static IP
    esp_netif_config_t netif_cfg = ESP_NETIF_DEFAULT_ETH();
    esp_netif_t *eth_netif = esp_netif_new(&netif_cfg);
    
    // Stop DHCP client (we want static IP)
    esp_netif_dhcpc_stop(eth_netif);
    
    // Set static IP configuration
    esp_netif_ip_info_t ip_info = {
        .ip = { .addr = ESP_IP4TOADDR(192, 168, 100, 1) },
        .gw = { .addr = ESP_IP4TOADDR(192, 168, 100, 1) },
        .netmask = { .addr = ESP_IP4TOADDR(255, 255, 255, 0) },
    };
    
    esp_err_t ret = esp_netif_set_ip_info(eth_netif, &ip_info);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set static IP: %s", esp_err_to_name(ret));
        return ret;
    }
    
    ESP_LOGI(TAG, "Static IP configured: %s", CONFIG_C6_OTA_NETWORK_IP);
    ESP_LOGI(TAG, "Netmask: %s", CONFIG_C6_OTA_NETWORK_NETMASK);
    
    // Initialize Ethernet driver
    eth_config_t eth_config = ETH_DEFAULT_CONFIG();
    esp_eth_handle_t eth_handle = NULL;
    
    ret = example_eth_init(&eth_config, &eth_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize Ethernet: %s", esp_err_to_name(ret));
        return ret;
    }
    
    // Register event handler
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, 
                                               &ota_eth_event_handler, NULL));
    
    // Attach Ethernet driver to netif
    void *glue = esp_eth_new_netif_glue(eth_handle);
    ESP_ERROR_CHECK(esp_netif_attach(eth_netif, glue));
    
    // Start Ethernet
    ESP_ERROR_CHECK(esp_eth_start(eth_handle));
    
    ESP_LOGI(TAG, "Ethernet initialized in OTA mode");
    
    // Start DHCP server for connected PC
    ESP_ERROR_CHECK(esp_netif_dhcps_start(eth_netif));
    ESP_LOGI(TAG, "DHCP server started (range: 192.168.100.100-200)");
    
    // Start OTA web server
    ret = ota_webserver_start();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start OTA web server");
        return ret;
    }
    
    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "   OTA Mode Ready");
    ESP_LOGI(TAG, "   Connect PC to Ethernet port");
    ESP_LOGI(TAG, "   Open browser: http://192.168.100.1/");
    ESP_LOGI(TAG, "========================================");
    
    return ESP_OK;
}
