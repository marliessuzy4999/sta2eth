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
#include "dhcpserver/dhcpserver.h"

static const char *TAG = "ota_mode";

// OTA mode configuration - hardcoded
#define OTA_NETWORK_IP      "192.168.100.1"
#define OTA_NETWORK_NETMASK "255.255.255.0"
#define OTA_NETWORK_GATEWAY "192.168.100.1"
#define OTA_DHCP_START_IP   "192.168.100.100"
#define OTA_DHCP_END_IP     "192.168.100.200"

// Global netif pointer for event handler
static esp_netif_t *s_ota_eth_netif = NULL;

bool should_enter_ota_mode(void)
{
    ESP_LOGI(TAG, "Checking if C6 OTA upgrade is needed...");
    
    // Check if C6 firmware needs upgrade
    // This will query C6 version and compare with minimum required
    bool needs_upgrade = c6_needs_firmware_upgrade(10000); // 10 second timeout
    
    if (needs_upgrade) {
        ESP_LOGW(TAG, "C6 firmware upgrade required, will enter OTA mode");
        return true;
    }
    
    ESP_LOGI(TAG, "C6 firmware version is OK, skipping OTA mode");
    return false;
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
        
        // Try to start DHCP server when link comes up
        if (s_ota_eth_netif) {
            esp_err_t ret = esp_netif_dhcps_start(s_ota_eth_netif);
            if (ret == ESP_OK) {
                ESP_LOGI(TAG, "DHCP server started on link up");
            } else if (ret != ESP_ERR_ESP_NETIF_DHCP_ALREADY_STARTED) {
                ESP_LOGW(TAG, "Failed to start DHCP server on link up: %s", esp_err_to_name(ret));
            }
        }
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
    
    // Store netif for event handler
    s_ota_eth_netif = eth_netif;
    
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
    
    ESP_LOGI(TAG, "Static IP configured: %s", OTA_NETWORK_IP);
    ESP_LOGI(TAG, "Netmask: %s", OTA_NETWORK_NETMASK);
    
    // Initialize Ethernet driver
    uint8_t eth_port_cnt = 0;
    esp_eth_handle_t *eth_handles;
    ret = ethernet_init_all(&eth_handles, &eth_port_cnt);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize Ethernet: %s", esp_err_to_name(ret));
        return ret;
    }
    
    // Use the first Ethernet interface
    if (eth_port_cnt == 0) {
        ESP_LOGE(TAG, "No Ethernet interface found");
        return ESP_FAIL;
    }
    esp_eth_handle_t eth_handle = eth_handles[0];
    free(eth_handles);
    
    // Register event handler
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, 
                                               &ota_eth_event_handler, NULL));
    
    // Attach Ethernet driver to netif
    void *glue = esp_eth_new_netif_glue(eth_handle);
    ESP_ERROR_CHECK(esp_netif_attach(eth_netif, glue));
    
    // Start Ethernet
    ESP_ERROR_CHECK(esp_eth_start(eth_handle));
    
    ESP_LOGI(TAG, "Ethernet initialized in OTA mode");
    
    // Configure DHCP server range
    esp_netif_dhcps_stop(eth_netif);
    
    // Set DHCP server IP range (non-blocking, can fail if interface not ready)
    dhcps_lease_t dhcp_lease;
    dhcp_lease.enable = true;
    dhcp_lease.start_ip.addr = ESP_IP4TOADDR(192, 168, 100, 100);
    dhcp_lease.end_ip.addr = ESP_IP4TOADDR(192, 168, 100, 200);
    ret = esp_netif_dhcps_option(eth_netif, ESP_NETIF_OP_SET, 
                                 ESP_NETIF_REQUESTED_IP_ADDRESS, 
                                 &dhcp_lease, sizeof(dhcp_lease));
    if (ret != ESP_OK) {
        ESP_LOGW(TAG, "Failed to set DHCP lease range: %s (will use default)", esp_err_to_name(ret));
    }
    
    // Start DHCP server for connected PC (can fail if interface not ready)
    ret = esp_netif_dhcps_start(eth_netif);
    if (ret == ESP_OK) {
        ESP_LOGI(TAG, "DHCP server started (range: 192.168.100.100-200)");
    } else {
        ESP_LOGW(TAG, "Failed to start DHCP server: %s (will retry when link is up)", esp_err_to_name(ret));
    }
    
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
