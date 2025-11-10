# STA2ETH L2 Bridge Implementation Using Official ESP-IDF Bridge API

## Overview

This implementation uses the **official ESP-IDF bridge API** (`esp_netif_br_glue`) for L2 bridging between Ethernet (ESP32-P4) and WiFi STA (ESP32-C6 via esp_wifi_remote over SDIO).

## Key Innovation: WiFi STA MAC = Ethernet MAC

The critical technique that enables WiFi STA bridging is:

**Set WiFi STA MAC address to match the Ethernet MAC address**

### Why This Works

1. **3-Address WiFi Limitation:**
   - WiFi STA normally only receives packets where Address 1 (destination) matches its MAC
   - This is why ESP-IDF documentation states "WiFi STA cannot be bridged"

2. **The Solution:**
   - Set WiFi STA MAC = Ethernet MAC using `esp_wifi_set_mac(WIFI_IF_STA, eth_mac)`
   - Now when packets arrive at the AP destined for the Ethernet MAC, they're forwarded to the STA
   - STA receives them because Address 1 matches its (now identical) MAC!
   - This achieves **transparent L2 bridging** without needing promiscuous mode

3. **Why Not Promiscuous Mode:**
   - ESP-Hosted doesn't support WiFi promiscuous mode
   - C6 cannot handle the packet flood from promiscuous mode
   - Would turn the device into a packet sniffer (not desired)

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    ESP32-P4 (Host)                          │
│  ┌──────────────────────────────────────────────────────┐  │
│  │         Official esp_netif_br_glue Bridge            │  │
│  │                                                       │  │
│  │  ┌──────────────┐         ┌─────────────────────┐  │  │
│  │  │   Ethernet   │◄───────►│   WiFi STA (Remote) │  │  │
│  │  │   (P4 PHY)   │         │   MAC = ETH MAC     │  │  │
│  │  └──────────────┘         └─────────────────────┘  │  │
│  │         ▲                           ▲              │  │
│  └─────────┼───────────────────────────┼──────────────┘  │
│            │                           │                  │
│            │                      SDIO │                  │
└────────────┼───────────────────────────┼──────────────────┘
             │                           ▼
             │                  ┌─────────────────┐
             │                  │   ESP32-C6      │
             │                  │  (WiFi Slave)   │
             │                  │  via ESP-Hosted │
             │                  └─────────────────┘
             │                           │
             ▼                           ▼
         Ethernet                   WiFi AP
         Network                    Network
```

## Implementation Details

### 1. Initialization Order

```c
// 1. Initialize Ethernet and get MAC
ethernet_init_all(&eth_handles, &eth_port_cnt);
esp_eth_ioctl(eth_handle, ETH_CMD_G_MAC_ADDR, common_mac);

// 2. Initialize WiFi Remote
esp_wifi_remote_init(&cfg);
esp_wifi_set_mode(WIFI_MODE_STA);

// 3. CRITICAL: Set WiFi STA MAC = Ethernet MAC
esp_wifi_set_mac(WIFI_IF_STA, common_mac);

// 4. Create netifs for bridge (flags=0, no IP)
esp_netif_t *eth_netif = esp_netif_new(&eth_cfg);
esp_netif_t *wifi_netif = esp_netif_create_wifi(WIFI_IF_STA, &wifi_cfg);

// 5. Create bridge
esp_netif_br_glue_handle_t br_glue = esp_netif_br_glue_new();
esp_netif_br_glue_add_port(br_glue, eth_netif);
esp_netif_br_glue_add_wifi_port(br_glue, wifi_netif);
esp_netif_attach(br_netif, br_glue);

// 6. Enable Ethernet promiscuous mode
esp_eth_ioctl(eth_handle, ETH_CMD_S_PROMISCUOUS, &promiscuous);

// 7. Start interfaces
esp_eth_start(eth_handle);
esp_wifi_start();
esp_wifi_remote_connect();
```

### 2. Network Interface Configuration

**Bridged Ports (Ethernet & WiFi STA):**
```c
esp_netif_inherent_config_t port_cfg = ESP_NETIF_INHERENT_DEFAULT_*();
port_cfg.flags = 0;          // NO flags for bridged ports
port_cfg.ip_info = NULL;     // NO IP address for physical interfaces
```

**Bridge Interface:**
```c
esp_netif_inherent_config_t br_cfg = ESP_NETIF_INHERENT_DEFAULT_BR();
// Bridge gets IP via DHCP
// All ports share this single IP address
```

### 3. Bridge Configuration

```c
bridgeif_config_t bridgeif_config = {
    .max_fdb_dyn_entries = 10,  // Dynamic forwarding database entries
    .max_fdb_sta_entries = 2,   // Static forwarding database entries
    .max_ports = 2              // Ethernet + WiFi STA
};
```

### 4. Promiscuous Mode

Ethernet promiscuous mode is **required** for bridge operation:
```c
bool promiscuous = true;
esp_eth_ioctl(eth_handle, ETH_CMD_S_PROMISCUOUS, &promiscuous);
```

This allows Ethernet to receive all packets, which the bridge then filters and forwards.

## Benefits Over Custom Packet Forwarding

### Official Bridge API Advantages:

1. **Officially Maintained:** Espressif maintains and tests the bridge code
2. **Better Performance:** Optimized L2 forwarding in LwIP
3. **Automatic Flow Control:** No need for custom queuing/retry logic
4. **FDB Management:** Automatic MAC learning and forwarding database
5. **Standards Compliant:** IEEE 802.1D bridge implementation
6. **Less Code:** No custom packet forwarding tasks needed
7. **More Stable:** Proven code used in production

### What Was Removed:

- ❌ Custom packet forwarding tasks (`eth2wifi_task`, `wifi2eth_task`)
- ❌ PSRAM buffer pools and management code
- ❌ Manual MAC address spoofing logic
- ❌ Custom retry logic with progressive backoff
- ❌ Flow control queues and management
- ❌ Statistics tracking code
- ❌ Memory monitoring tasks

### What Remains:

- ✅ WiFi configuration portal (SoftAP provisioning)
- ✅ C6 OTA upgrade functionality
- ✅ GPIO button for reconfiguration
- ✅ Credential storage in NVS
- ✅ Event handling for connection status

## Code Structure

```
main/
├── sta2eth_bridge.c          # Main bridge implementation (NEW)
├── wifi_config_portal.c      # WiFi provisioning via SoftAP
├── c6_ota.c                   # C6 firmware OTA upgrade
└── CMakeLists.txt            # Updated to use bridge implementation
```

## Configuration

### Required Kconfig Options

Must be enabled in ESP-IDF:

```
CONFIG_ESP_NETIF_BRIDGE_EN=y           # Enable bridge support
CONFIG_LWIP_NUM_NETIF_CLIENT_DATA=2    # Required for bridge
```

### Project Configuration

In `sdkconfig.defaults.esp32p4`:
```
CONFIG_ESP_NETIF_BRIDGE_EN=y
CONFIG_LWIP_NUM_NETIF_CLIENT_DATA=2
CONFIG_LWIP_L2_TO_L3_COPY=y           # Copy packets from L2 to L3
```

## Testing

1. **Build and Flash P4:**
   ```bash
   idf.py set-target esp32p4
   idf.py build flash monitor
   ```

2. **Configure WiFi:**
   - Connect phone to `ESP32-P4-Config` AP
   - Open captive portal (http://192.168.4.1)
   - Enter WiFi credentials

3. **Test Bridge:**
   - Connect Ethernet cable to P4
   - Device should get single IP address via DHCP
   - Ethernet and WiFi traffic should be bridged transparently
   - Both interfaces appear as single device on network

## Troubleshooting

### Bridge Not Working

1. **Check MAC addresses match:**
   ```
   I (1234) sta2eth_bridge: Using common MAC address: aa:bb:cc:dd:ee:ff
   ```
   Both Ethernet and WiFi STA should show same MAC.

2. **Check promiscuous mode enabled:**
   ```
   I (1234) sta2eth_bridge: Enabled Ethernet promiscuous mode for bridge operation
   ```

3. **Check both ports added to bridge:**
   ```
   I (1234) sta2eth_bridge: Added Ethernet port to bridge
   I (1234) sta2eth_bridge: Added WiFi STA port to bridge
   ```

### WiFi Not Connecting

1. Check credentials are saved correctly
2. Verify 2.4GHz WiFi network (C6 doesn't support 5GHz)
3. Check WiFi signal strength
4. Review logs for connection errors

### No IP Address

1. Check DHCP server is available on network
2. Verify bridge netif created correctly
3. Check both ports are up and connected

## Performance

Expected throughput:
- **Ethernet → WiFi:** 40-50 Mbps
- **WiFi → Ethernet:** 30-40 Mbps

Performance limited by:
- WiFi signal quality
- SDIO bandwidth
- C6 processing capacity
- Network congestion

## References

- [ESP-IDF Bridge Example](https://github.com/espressif/esp-idf/tree/master/examples/network/bridge)
- [ESP-Hosted Documentation](https://github.com/espressif/esp-hosted)
- [esp_wifi_remote Component](https://github.com/espressif/esp-protocols/tree/master/components/esp_wifi_remote)
- [IEEE 802.1D Bridge Specification](https://en.wikipedia.org/wiki/IEEE_802.1D)
