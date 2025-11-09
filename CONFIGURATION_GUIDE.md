# sta2eth Configuration Guide

## Overview

This project is now configured with **optimal default parameters** in `sdkconfig.defaults.esp32p4`. No manual configuration is needed - just build and flash!

## Configuration Philosophy

Per user requirements, all configurations are set to optimal values based on:
- ESP32-P4 + ESP32-C6 SDIO testing
- esp-hosted-mcu best practices
- Performance optimization analysis

## Key Configurations in sdkconfig.defaults.esp32p4

### ESP-Hosted (SDIO Transport)
```ini
# Co-processor target
CONFIG_SLAVE_IDF_TARGET_ESP32C6=y

# Use P4 Function EV Board preset
CONFIG_ESP_HOSTED_P4_DEV_BOARD_FUNC_BOARD=y

# SDIO Transport: 40MHz, 4-bit mode
CONFIG_ESP_HOSTED_SDIO_HOST_INTERFACE=y
CONFIG_ESP_HOSTED_SDIO_CLOCK_FREQ_KHZ=40000
CONFIG_ESP_HOSTED_SDIO_BUS_WIDTH=4

# SDIO Queues (optimized for performance)
CONFIG_ESP_HOSTED_SDIO_TX_Q_SIZE=20
CONFIG_ESP_HOSTED_SDIO_RX_Q_SIZE=20
```

### WiFi Remote Buffers (Optimized for C6)
```ini
# Static RX buffers: 32 (matches RX_BA_WIN)
CONFIG_WIFI_RMT_STATIC_RX_BUFFER_NUM=32

# Dynamic buffers for high throughput
CONFIG_WIFI_RMT_DYNAMIC_RX_BUFFER_NUM=64
CONFIG_WIFI_RMT_DYNAMIC_TX_BUFFER_NUM=64

# AMPDU for aggregated frames
CONFIG_WIFI_RMT_AMPDU_TX_ENABLED=y
CONFIG_WIFI_RMT_TX_BA_WIN=32
CONFIG_WIFI_RMT_AMPDU_RX_ENABLED=y
CONFIG_WIFI_RMT_RX_BA_WIN=32

# IRAM optimizations for lower latency
CONFIG_WIFI_RMT_IRAM_OPT=y
CONFIG_WIFI_RMT_EXTRA_IRAM_OPT=y
CONFIG_WIFI_RMT_RX_IRAM_OPT=y

# Static management buffers
CONFIG_WIFI_RMT_STATIC_RX_MGMT_BUFFER=y
```

### Network Performance
```ini
# Large TCP buffers (131KB each)
CONFIG_LWIP_TCP_SND_BUF_DEFAULT=131070
CONFIG_LWIP_TCP_WND_DEFAULT=131070

# Mailbox sizes
CONFIG_LWIP_TCP_RECVMBOX_SIZE=64
CONFIG_LWIP_UDP_RECVMBOX_SIZE=64
CONFIG_LWIP_TCPIP_RECVMBOX_SIZE=64

# TCP optimizations
CONFIG_LWIP_TCP_TIMESTAMPS=y
CONFIG_LWIP_TCP_SACK_OUT=y
CONFIG_LWIP_TCP_KEEPALIVE=y
CONFIG_LWIP_SO_REUSE=y
```

### PSRAM Configuration
```ini
# High-speed PSRAM: 200MHz, 16-line (hex) mode
CONFIG_SPIRAM=y
CONFIG_SPIRAM_MODE_HEX=y
CONFIG_SPIRAM_SPEED_200M=y
CONFIG_SPIRAM_ECC_ENABLE=y
```

### FreeRTOS & System
```ini
# 1000Hz tick rate (1ms resolution)
CONFIG_FREERTOS_HZ=1000

# CPU at 360MHz
CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_360=y

# Watchdogs and safety features
CONFIG_ESP_INT_WDT=y
CONFIG_ESP_TASK_WDT_TIMEOUT_S=10
CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY=y
CONFIG_ESP_BROWNOUT_DET=y
CONFIG_HEAP_ABORT_WHEN_ALLOCATION_FAILS=y
```

## Application-Level Optimizations

These are implemented in `sta2eth_main.c` (not in Kconfig):

### SDIO Timeout & Retry
- **TX Timeout**: 100ms (prevents indefinite blocking)
- **Max Retries**: 5 (reduced from 20, for 5x faster error detection)
- **Retry Delay**: 5ms with exponential backoff
- **Worst-case blocking**: ~250ms (down from ~2000ms)

### SDIO Health Monitoring
- **Health Check**: Enabled with 5s interval
- **Stall Threshold**: 10 seconds
- **Verbose Logging**: Disabled for performance

### Task Priorities
- **WiFi TX/RX Tasks**: Priority 10 (high priority)
- **Queue Poll Interval**: 1ms (low latency mode)

## Building the Project

```bash
# Set target
idf.py set-target esp32p4

# Build (all configs are already optimal)
idf.py build

# Flash
idf.py -p /dev/ttyUSB0 flash monitor
```

## Expected Performance

With these optimizations, expect:

| Metric | Value |
|--------|-------|
| SDIO blocking time | < 250ms (vs 2000ms before) |
| WiFi throughput (TCP) | 30-32 Mbps |
| WiFi throughput (UDP) | 49-50 Mbps |
| Raw SDIO throughput | 70-80 Mbps |
| SDIO stall detection | < 10 seconds |

## Advanced Tuning (Not Recommended)

If you need to modify the default configurations:

1. **Edit** `sdkconfig.defaults.esp32p4` directly
2. Or use `idf.py menuconfig` to override defaults
3. Save changes to `sdkconfig` (not tracked in git)

**Note**: The defaults are already optimized for ESP32-P4 + ESP32-C6 via SDIO. Only modify if you have specific requirements or different hardware.

## References

- [esp-hosted-mcu Documentation](https://github.com/espressif/esp-hosted-mcu/tree/main/docs)
- [esp-wifi-remote Configuration](https://github.com/espressif/esp-wifi-remote)
- [BLOCKING_ANALYSIS.md](BLOCKING_ANALYSIS.md) - Problem analysis
- [WIFI_REMOTE_BUFFER_OPTIMIZATION.md](WIFI_REMOTE_BUFFER_OPTIMIZATION.md) - Buffer details

## Troubleshooting

### Issue: Build fails with "unknown configuration option"
- **Solution**: Run `idf.py reconfigure` to update component dependencies

### Issue: Lower throughput than expected
- **Check**: SDIO connections and signal quality
- **Check**: WiFi signal strength (use 2.4GHz, not 5GHz for C6)
- **Check**: Network congestion

### Issue: SDIO stalls
- **Check**: Logs for "SDIO STALL DETECTED" warnings
- **Check**: Power supply stability
- **Check**: Hardware connections (pull-ups, trace lengths)

For more details, see the full documentation in the repository.
