# ESP32-P4 Configuration Optimization Guide for sta2eth

> Based on ESP-IDF Kconfig Reference Analysis
> Project: WiFi to Ethernet L2 Bridge with PSRAM Buffer Pool

## Overview

This guide provides configuration recommendations for optimizing the ESP32-P4 
in the sta2eth project, focusing on:
- PSRAM configuration for 1.6MB buffer pool
- Network performance optimization  
- Power and performance tuning
- System stability

---

## 1. PSRAM Configuration (Critical)

### Current Configuration (✅ Optimized)

```ini
# Enable PSRAM
CONFIG_SPIRAM=y
CONFIG_IDF_EXPERIMENTAL_FEATURES=y

# PSRAM Mode & Speed
CONFIG_SPIRAM_MODE_HEX=y                    # 16-line mode for max bandwidth
CONFIG_SPIRAM_SPEED_200M=y                  # 200MHz operation

# Initialization & Protection  
CONFIG_SPIRAM_BOOT_INIT=y                   # Early init (CRITICAL)
CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION=y  # Auto-enabled by BOOT_INIT

# Memory Allocation Strategy
CONFIG_SPIRAM_USE_MALLOC=y                  # Integrate with malloc
CONFIG_SPIRAM_MALLOC_RESERVE_INTERNAL=32768 # Reserve 32KB for DMA
CONFIG_SPIRAM_MALLOC_ALWAYSINTERNAL=16384   # Small allocs in internal RAM

# Data Segments
CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY=y    # BSS in PSRAM
CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP=y           # WiFi/LWIP in PSRAM

# Reliability vs Capacity
CONFIG_SPIRAM_ECC_ENABLE=y                  # Error correction (trades 4MB)

# Boot Optimization
# CONFIG_SPIRAM_MEMTEST is not set          # Faster boot (~1 sec)

# Safety
# CONFIG_SPIRAM_IGNORE_NOTFOUND is not set  # Fail if PSRAM missing
```

### Additional PSRAM Options to Consider

#### CONFIG_SPIRAM_XIP_FROM_PSRAM
**Status**: ❌ Not recommended for this project
**Reason**: Moves code execution to PSRAM, increases bus contention
```ini
# CONFIG_SPIRAM_XIP_FROM_PSRAM is not set
```

#### CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY
**Status**: ⚪ Optional
**Use case**: For uninitialized variables that need to persist across resets
```ini
# CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY is not set  # Not needed
```

---

## 2. CPU & Performance Configuration

### Current Configuration

```ini
# CPU Frequency
CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_360=y
CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ=360

# Power Management
# CONFIG_PM_ENABLE is not set                # Disabled for max performance

# Compiler Optimization
CONFIG_COMPILER_OPTIMIZATION_PERF=y         # Optimize for speed
```

### Additional CPU Options from Kconfig

#### Watchdog Timers

```ini
# Task Watchdog (Currently Configured)
CONFIG_ESP_TASK_WDT_TIMEOUT_S=10
CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU0=y

# Interrupt Watchdog (Recommended to Add)
CONFIG_ESP_INT_WDT=y
CONFIG_ESP_INT_WDT_TIMEOUT_MS=300
CONFIG_ESP_INT_WDT_CHECK_CPU0=y
```

#### Core Dump for Debugging

```ini
# Currently Configured
CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH=y

# Additional Options to Consider
CONFIG_ESP_COREDUMP_DATA_FORMAT_ELF=y       # ELF format for better debugging
CONFIG_ESP_COREDUMP_CHECKSUM_CRC32=y        # Verify dump integrity
```

---

## 3. Network & LWIP Optimization

### Current Configuration (✅ Well Optimized)

```ini
# Socket Configuration
CONFIG_LWIP_MAX_SOCKETS=32

# TCP Buffers (Doubled)
CONFIG_LWIP_TCP_SND_BUF_DEFAULT=131070
CONFIG_LWIP_TCP_WND_DEFAULT=131070

# Mailbox Sizes
CONFIG_LWIP_TCP_RECVMBOX_SIZE=64
CONFIG_LWIP_UDP_RECVMBOX_SIZE=64
CONFIG_LWIP_TCPIP_RECVMBOX_SIZE=64

# TCP/IP Task
CONFIG_LWIP_TCPIP_TASK_STACK_SIZE=4096

# Performance Features
CONFIG_LWIP_TCP_OVERSIZE_MSS=y
CONFIG_LWIP_TCP_SACK_OUT=y

# Reassembly
CONFIG_LWIP_IP_REASS_MAX_PBUFS=20
```

### Additional LWIP Options from Kconfig

#### TCP Advanced Options

```ini
# TCP Timestamps (for better RTT estimation)
CONFIG_LWIP_TCP_TIMESTAMPS=y

# TCP Keep-Alive
CONFIG_LWIP_TCP_KEEPALIVE_IDLE=7200000      # 2 hours (milliseconds)
CONFIG_LWIP_TCP_KEEPALIVE_INTVL=75000       # 75 seconds
CONFIG_LWIP_TCP_KEEPALIVE_COUNT=9

# TCP MSL (Maximum Segment Lifetime)
CONFIG_LWIP_TCP_MSL=60000                   # 60 seconds

# TCP TMR Interval
CONFIG_LWIP_TCP_TMR_INTERVAL=250            # 250ms (default)
```

#### UDP Options

```ini
# UDP TTL
CONFIG_LWIP_UDP_TTL=255

# UDP Receive Checksum
CONFIG_LWIP_UDP_RECVMBOX_SIZE=64            # Already configured
```

#### DHCP Options

```ini
# DHCP Timeouts
CONFIG_LWIP_DHCP_COARSE_TIMER_SECS=1
CONFIG_LWIP_DHCP_FINE_TIMER_MS=500
CONFIG_LWIP_DHCP_MAX_NTP_SERVERS=1

# DHCP Options List
CONFIG_LWIP_DHCP_OPTIONS_LEN=68
```

#### Additional Network Features

```ini
# ARP Table Size
CONFIG_LWIP_ARP_TABLE_SIZE=10               # Default

# Netif API
CONFIG_LWIP_NETIF_API=y

# Socket Options
CONFIG_LWIP_SO_REUSE=y                      # Allow address reuse
CONFIG_LWIP_SO_REUSE_RXTOALL=y              # Deliver to all sockets
CONFIG_LWIP_SO_RCVBUF=y                     # Per-socket receive buffer

# Network Interface Status Callback
CONFIG_LWIP_NETIF_STATUS_CALLBACK=y
```

---

## 4. WiFi Remote Configuration

### Current Configuration (✅ Optimized)

```ini
# Buffer Configuration
CONFIG_WIFI_RMT_STATIC_RX_BUFFER_NUM=16
CONFIG_WIFI_RMT_DYNAMIC_RX_BUFFER_NUM=64
CONFIG_WIFI_RMT_DYNAMIC_TX_BUFFER_NUM=64

# AMPDU Configuration
CONFIG_WIFI_RMT_AMPDU_TX_ENABLED=y
CONFIG_WIFI_RMT_TX_BA_WIN=32
CONFIG_WIFI_RMT_AMPDU_RX_ENABLED=y
CONFIG_WIFI_RMT_RX_BA_WIN=32
```

### Additional WiFi Options from Kconfig

```ini
# WiFi NVS Storage
CONFIG_WIFI_RMT_NVS_FLASH=y

# WiFi Task
CONFIG_WIFI_RMT_TASK_STACK_SIZE=4096

# WiFi Country Code
CONFIG_WIFI_RMT_COUNTRY_CODE_OPERATING_CLASS=0

# WiFi CSI (Channel State Information)
# CONFIG_WIFI_RMT_CSI_ENABLED is not set    # Not needed for bridging
```

---

## 5. FreeRTOS Configuration

### Current Configuration (✅ Optimized)

```ini
# Tick Rate
CONFIG_FREERTOS_HZ=1000                     # 1ms tick

# Stack Sizes
CONFIG_FREERTOS_TIMER_TASK_STACK_DEPTH=3072
CONFIG_FREERTOS_ISR_STACKSIZE=2048
CONFIG_FREERTOS_IDLE_TASK_STACKSIZE=2048

# Performance Monitoring
CONFIG_FREERTOS_USE_TRACE_FACILITY=y
CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS=y
```

### Additional FreeRTOS Options from Kconfig

```ini
# Thread Local Storage
CONFIG_FREERTOS_THREAD_LOCAL_STORAGE_POINTERS=3

# Assert Configuration
CONFIG_FREERTOS_ASSERT_ON_UNTESTED_FUNCTION=y
CONFIG_FREERTOS_CHECK_MUTEX_GIVEN_BY_OWNER=y
CONFIG_FREERTOS_CHECK_PORT_CRITICAL_COMPLIANCE=y

# Idle Hook
# CONFIG_FREERTOS_USE_IDLE_HOOK is not set  # Not needed

# Stack Overflow Check
CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY=y  # Or _PTRVAL

# Task Notification
CONFIG_FREERTOS_TASK_NOTIFICATION_ARRAY_ENTRIES=3

# Queue Configuration
CONFIG_FREERTOS_QUEUE_REGISTRY_SIZE=10

# Timer Configuration
CONFIG_FREERTOS_TIMER_TASK_PRIORITY=1
```

---

## 6. System Configuration

### Current Configuration

```ini
# System Event Task
CONFIG_ESP_SYSTEM_EVENT_TASK_STACK_SIZE=4096

# Main Task
CONFIG_ESP_MAIN_TASK_STACK_SIZE=8192

# Heap Memory
CONFIG_ESP_SYSTEM_ALLOW_RTC_FAST_MEM_AS_HEAP=y
```

### Additional System Options from Kconfig

```ini
# Panic Behavior
CONFIG_ESP_SYSTEM_PANIC_PRINT_REBOOT=y      # Print and reboot
# Or for debugging:
# CONFIG_ESP_SYSTEM_PANIC_GDBSTUB=y        # Start GDB stub

# Brownout Detection
CONFIG_ESP_BROWNOUT_DET=y
CONFIG_ESP_BROWNOUT_DET_LVL=7               # 2.51V

# Stack Smashing Protection
CONFIG_ESP_SYSTEM_CHECK_STACK_SMASHING=y

# Hardware Stack Guard
CONFIG_ESP_SYSTEM_HW_STACK_GUARD=y

# Console Configuration
CONFIG_ESP_CONSOLE_UART_DEFAULT=y
CONFIG_ESP_CONSOLE_UART_NUM=0
CONFIG_ESP_CONSOLE_UART_BAUDRATE=115200
```

---

## 7. Logging Configuration

### Current Configuration

```ini
# Log Version
CONFIG_LOG_VERSION_2=y
CONFIG_LOG_MAXIMUM_LEVEL_VERBOSE=y
```

### Additional Logging Options from Kconfig

```ini
# Default Log Level (Runtime)
CONFIG_LOG_DEFAULT_LEVEL_INFO=y             # Or _ERROR for production

# Log Colors
CONFIG_LOG_COLORS=y

# Log Timestamp
CONFIG_LOG_TIMESTAMP_SOURCE_RTOS=y

# Log Output
CONFIG_ESP_CONSOLE_USB_CDC=n                # Use UART
CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG=n
```

---

## 8. Memory Configuration

### Heap Allocation

```ini
# Multi-Heap
CONFIG_HEAP_POISONING_DISABLED=y            # Production
# Or for debugging:
# CONFIG_HEAP_POISONING_LIGHT=y

# Heap Tracing
# CONFIG_HEAP_TRACING is not set            # Disable in production

# Memory Allocation Checks
CONFIG_HEAP_ABORT_WHEN_ALLOCATION_FAILS=y
```

### Memory Protection

```ini
# IRAM/DRAM Protection
CONFIG_ESP_SYSTEM_MEMPROT_FEATURE=y
CONFIG_ESP_SYSTEM_MEMPROT_FEATURE_LOCK=n    # For debugging
```

---

## 9. Ethernet Configuration

From Kconfig reference, ESP32-P4 Ethernet options:

```ini
# Ethernet PHY Configuration
CONFIG_ETH_ENABLED=y

# PHY Address (depends on your board)
CONFIG_ETH_PHY_ADDR=1

# PHY Type (depends on your PHY chip)
# CONFIG_ETH_PHY_LAN87XX=y
# CONFIG_ETH_PHY_DP83848=y
# CONFIG_ETH_PHY_KSZ80XX=y
# etc.

# RMII Clock Configuration
CONFIG_ETH_RMII_CLK_INPUT=y                 # Or _OUTPUT
CONFIG_ETH_RMII_CLK_IN_GPIO=0

# DMA Configuration (if available)
CONFIG_ETH_DMA_BUFFER_SIZE=1536
CONFIG_ETH_DMA_RX_BUFFER_NUM=10
CONFIG_ETH_DMA_TX_BUFFER_NUM=10
```

---

## 10. Security Recommendations

```ini
# Secure Boot (Production)
# CONFIG_SECURE_BOOT=y

# Flash Encryption (Production)
# CONFIG_SECURE_FLASH_ENC_ENABLED=y

# Disable ROM Basic Console (Production)
CONFIG_ESP_SYSTEM_ROM_BASIC_CONSOLE_DISABLE=y

# JTAG (Disable in Production)
# CONFIG_ESP_SYSTEM_DISABLE_JTAG is not set  # Keep for development
```

---

## Summary of Recommended Additions

### High Priority (Add Now)

1. **Interrupt Watchdog**: `CONFIG_ESP_INT_WDT=y`
2. **TCP Timestamps**: `CONFIG_LWIP_TCP_TIMESTAMPS=y`
3. **SO_REUSE**: `CONFIG_LWIP_SO_REUSE=y`
4. **Stack Overflow Check**: `CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY=y`
5. **Brownout Detection**: `CONFIG_ESP_BROWNOUT_DET=y`

### Medium Priority (Consider Adding)

1. **Core Dump ELF Format**: `CONFIG_ESP_COREDUMP_DATA_FORMAT_ELF=y`
2. **TCP Keep-Alive**: `CONFIG_LWIP_TCP_KEEPALIVE_*` options
3. **Hardware Stack Guard**: `CONFIG_ESP_SYSTEM_HW_STACK_GUARD=y`
4. **Heap Abort on Failure**: `CONFIG_HEAP_ABORT_WHEN_ALLOCATION_FAILS=y`

### Low Priority (Production Hardening)

1. **Disable ROM Console**: `CONFIG_ESP_SYSTEM_ROM_BASIC_CONSOLE_DISABLE=y`
2. **Log Level**: Change to `CONFIG_LOG_DEFAULT_LEVEL_INFO` or `_ERROR`
3. **Heap Poisoning**: Disable for production

---

## Configuration File Structure

The optimized `sdkconfig.defaults.esp32p4` should be organized as:

1. **CPU & Power** (✅ Current)
2. **PSRAM** (✅ Current + ECC)
3. **WiFi Remote** (✅ Current)
4. **LWIP & Network** (✅ Current + proposed additions)
5. **FreeRTOS** (✅ Current + proposed additions)
6. **System** (✅ Current + proposed additions)
7. **Logging** (✅ Current)
8. **Security** (production considerations)

---

## References

- `ESP32_P4_KCONFIG_REFERENCE.md` - Full Kconfig reference
- `PSRAM_CONFIG_RATIONALE.md` - PSRAM configuration rationale
- `KCONFIG_VERIFICATION.md` - Validated configuration options
- ESP-IDF Official Documentation

---

## Testing Checklist

After applying new configurations:

- [ ] Build succeeds without warnings
- [ ] PSRAM initializes correctly (check boot logs)
- [ ] Buffer pool allocates successfully (1.6MB)
- [ ] Network throughput maintained or improved
- [ ] No watchdog timeouts
- [ ] Memory usage within limits
- [ ] System stability over 24+ hours
