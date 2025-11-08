# sta2eth - ESP32-P4 + ESP32-C6 L2 Bridge

WiFi station to Ethernet L2 bridge for ESP32-P4 with ESP32-C6 as WiFi coprocessor.

## Overview

This project implements a transparent L2 bridge between WiFi (via ESP32-C6) and Ethernet (on ESP32-P4). The ESP32-P4 communicates with ESP32-C6 via SDIO using ESP-Hosted, with WiFi functionality provided by `esp_wifi_remote`.

### Architecture

- **ESP32-P4 (Host)**: Runs the bridge application with Ethernet interface
- **ESP32-C6 (Slave)**: Provides WiFi connectivity via ESP-Hosted firmware
- **Communication**: SDIO transport with PSRAM buffering for flow control
- **WiFi API**: `esp_wifi_remote` transparently wraps WiFi calls to C6

### Features

- ✅ L2 bridge between WiFi and Ethernet
- ✅ MAC address spoofing for transparent bridging
- ✅ SoftAP-based WiFi configuration via mobile phone
- ✅ Captive portal for easy setup
- ✅ WiFi network scanning
- ✅ PSRAM buffering to handle P4-C6 speed mismatch
- ✅ Auto-reconnect on WiFi disconnection

## Requirements

### Hardware

- **ESP32-P4-Function-EV-Board** (recommended) - Has P4 and C6 with SDIO pre-wired
- Or custom board with:
  - ESP32-P4 with Ethernet PHY
  - ESP32-C6 connected via SDIO

### Software

- **ESP-IDF**: master branch (latest)
- **Components**:
  - `esp_wifi_remote` (latest)
  - `esp_hosted` (latest)

## Quick Start

### 1. Setup ESP-IDF

```bash
# Clone ESP-IDF master branch
git clone --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh
. ./export.sh
```

### 2. Flash ESP32-C6 Slave Firmware

First, flash the ESP-Hosted slave firmware to C6:

```bash
cd $IDF_PATH/../
git clone https://github.com/espressif/esp-hosted.git
cd esp-hosted/esp_hosted_fg/esp/esp_driver/network_adapter

# Configure for C6
idf.py set-target esp32c6
idf.py menuconfig

# In menuconfig, enable:
# - Transport: SDIO
# - Enable Network Split (optional)
# - Allow host to power save (optional)

# Build and flash to C6
idf.py build flash monitor
```

### 3. Build and Flash ESP32-P4 Host

```bash
cd /path/to/sta2eth

# Set target to P4
idf.py set-target esp32p4

# Configure (optional)
idf.py menuconfig

# Build and flash
idf.py build flash monitor
```

## Configuration

### First-Time WiFi Setup

1. Power on the device
2. The C6 will create a SoftAP named **`ESP32-P4-Config`** (no password)
3. Connect your phone to this network
4. A captive portal should automatically open, or navigate to `http://192.168.4.1`
5. Click "Scan Networks" to see available WiFi networks
6. Select your network and enter the password
7. Click "Connect"
8. Device will save the configuration and restart

### Reconfiguration

Long-press the Boot button (GPIO0) for 2 seconds to enter configuration mode again.

### Configuration Options

Use `idf.py menuconfig` to configure:

- **PSRAM**: Enabled by default for packet buffering
- **Ethernet PHY**: Configure for your board's PHY chip
- **SDIO**: Should match C6 slave configuration
- **WiFi Remote**: Buffer sizes and flow control

## Project Structure

```
sta2eth/
├── main/
│   ├── sta2eth_main.c          # Main application
│   ├── wifi_remote_sta.c       # WiFi remote wrapper (separate compilation unit)
│   ├── wifi_config_portal.c    # SoftAP configuration portal
│   ├── ethernet_iface.c        # Ethernet interface
│   └── CMakeLists.txt
├── components/
│   └── esp_wifi_remote_wrapper/  # PSRAM buffer pool (optional)
├── sdkconfig.defaults.esp32p4  # P4-specific configuration
└── README.md
```

## How It Works

### Packet Flow

```
Ethernet (P4) → PSRAM Buffer → SDIO → WiFi (C6) → Internet
             ←                 ←              ←
```

### PSRAM Buffering

The P4 is faster than the C6's SDIO/WiFi interface. To prevent packet loss:

1. Large PSRAM-based packet queues absorb traffic bursts
2. Adaptive rate limiting prevents overwhelming C6
3. Backpressure mechanism provides flow control

### MAC Spoofing

For transparent L2 bridging, MAC addresses are rewritten:
- Ethernet→WiFi: Source MAC is changed to WiFi STA MAC
- WiFi→Ethernet: Destination MAC is changed to Ethernet MAC

## Troubleshooting

### C6 Not Responding

- Verify SDIO connections
- Check C6 has ESP-Hosted slave firmware
- Ensure SDIO configuration matches between P4 and C6

### WiFi Not Connecting

- Check SSID and password
- Verify WiFi network is 2.4GHz (C6 doesn't support 5GHz)
- Check WiFi signal strength

### Packet Loss / Poor Performance

- Increase PSRAM buffer sizes in `sdkconfig.defaults.esp32p4`
- Adjust `CONFIG_WIFI_RMT_*` buffer settings
- Check SDIO clock speed configuration

### Configuration Portal Not Accessible

- Verify phone is connected to `ESP32-P4-Config` SoftAP
- Try manually navigating to `http://192.168.4.1`
- Check C6 is running and SDIO communication is working

## Performance

Expected throughput (TCP iperf):
- **Ethernet → WiFi**: ~40-50 Mbps
- **WiFi → Ethernet**: ~30-40 Mbps

Performance depends on:
- WiFi signal quality
- Network congestion  
- SDIO clock speed
- PSRAM buffer configuration

## Advanced Configuration

### Custom PSRAM Buffer Pool

Edit `sdkconfig.defaults.esp32p4` to adjust:

```
CONFIG_SPIRAM=y
CONFIG_SPIRAM_USE_MALLOC=y
CONFIG_LWIP_TCP_SND_BUF_DEFAULT=65535
CONFIG_LWIP_TCP_WND_DEFAULT=65535
```

### Network Split (Optional)

Enable in C6 slave firmware to handle some traffic on C6 directly, reducing P4 wake-ups.

## License

This project is licensed under Apache License 2.0 and CC0 (for example code).

## References

- [ESP-IDF](https://github.com/espressif/esp-idf)
- [ESP-Hosted](https://github.com/espressif/esp-hosted)
- [esp_wifi_remote](https://github.com/espressif/esp-wifi-remote)
- [ESP32-P4](https://www.espressif.com/en/products/socs/esp32-p4)
- [ESP32-C6](https://www.espressif.com/en/products/socs/esp32-c6)
