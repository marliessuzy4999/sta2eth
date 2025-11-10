# ESP32-C6 Slave Firmware Setup Guide

This guide explains how to flash the ESP-Hosted slave firmware to ESP32-C6 for use with the sta2eth P4 host.

## Prerequisites

- ESP-IDF master branch installed and activated
- ESP32-C6 with SDIO connection to P4

## Quick Setup (ESP32-P4-Function-EV-Board)

If you're using the ESP32-P4-Function-EV-Board, the C6 is already connected via SDIO. Just flash the firmware:

### 1. Clone ESP-Hosted

```bash
cd /path/to/your/projects
git clone --recursive https://github.com/espressif/esp-hosted.git
cd esp-hosted/esp_hosted_fg/esp/esp_driver/network_adapter
```

### 2. Configure for C6

```bash
# Set target
idf.py set-target esp32c6

# Configure
idf.py menuconfig
```

### 3. Configure Transport (SDIO)

In menuconfig:

```
Example Configuration →
    Transport layer →
        (X) SDIO interface
```

### 4. Optional: Enable Network Split

For better performance with power management:

```
Example Configuration →
    [*] Enable Network Split
    [*] Allow host to power save
```

### 5. Build and Flash

```bash
# Build
idf.py build

# Flash to C6 (connect USB to C6 port)
idf.py -p /dev/ttyUSB0 flash

# Monitor (optional)
idf.py -p /dev/ttyUSB0 monitor
```

## Custom Board Setup

If you're using a custom board:

### Hardware Connections (SDIO)

Connect C6 to P4 via SDIO:

| Signal | P4 Pin | C6 Pin | Notes |
|--------|--------|--------|-------|
| CLK    | GPIO43 | GPIO14 | SDIO Clock |
| CMD    | GPIO44 | GPIO15 | SDIO Command |
| DATA0  | GPIO39 | GPIO16 | SDIO Data 0 |
| DATA1  | GPIO40 | GPIO17 | SDIO Data 1 |
| DATA2  | GPIO41 | GPIO18 | SDIO Data 2 |
| DATA3  | GPIO42 | GPIO19 | SDIO Data 3 |
| GND    | GND    | GND    | Common Ground |

Optional GPIO for power management:
| Signal | P4 Pin | C6 Pin | Purpose |
|--------|--------|--------|---------|
| WAKEUP | GPIO6  | GPIO2  | Host wakeup signal |

### Software Configuration

1. In C6 menuconfig, configure SDIO pins if different from default:

```
Example Configuration →
    SDIO Configuration →
        SDIO CLK GPIO
        SDIO CMD GPIO
        SDIO DATA0 GPIO
        (etc.)
```

2. If using custom host wakeup GPIO:

```
Example Configuration →
    Host Power Save Configuration →
        Host wakeup GPIO number
```

## Verification

After flashing C6, you should see:

```
I (xxx) slave_init: ESP-Hosted slave firmware starting
I (xxx) slave_init: Transport: SDIO
I (xxx) slave_init: Waiting for host...
```

When P4 connects, you'll see:

```
I (xxx) slave_sdio: Host connected via SDIO
I (xxx) slave_ctrl: Control path initialized
```

## Troubleshooting

### C6 Won't Flash

- Check USB cable connection
- Verify correct port: `ls /dev/ttyUSB*`
- Try holding BOOT button while connecting USB
- Check ESP-IDF is activated: `. $IDF_PATH/export.sh`

### P4 Can't Connect to C6

- Verify SDIO pin connections
- Check SDIO configuration matches between P4 and C6
- Ensure C6 firmware is running (check with monitor)
- Verify power supply is adequate for both chips

### Slow Performance

- Check SDIO clock speed in menuconfig
- Verify buffer sizes are adequate
- Enable network split for better traffic distribution
- Check WiFi signal strength

## Advanced Configuration

### Increase SDIO Speed

```
Example Configuration →
    SDIO Configuration →
        SDIO clock speed → High Speed (40MHz or 50MHz)
```

### Adjust Buffer Sizes

```
Component config →
    ESP-Hosted config →
        RX buffer count (increase for high throughput)
        TX buffer count (increase for high throughput)
```

### Enable Debug Logging

```
Component config →
    Log output →
        Default log verbosity → Debug
```

## References

- [ESP-Hosted Documentation](https://github.com/espressif/esp-hosted)
- [ESP32-P4 Function EV Board Guide](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32p4/esp32-p4-function-ev-board/index.html)
- [SDIO Interface Guide](https://github.com/espressif/esp-hosted/blob/master/docs/sdio.md)
