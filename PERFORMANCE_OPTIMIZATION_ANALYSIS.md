# Performance and Stability Optimization Analysis

> Deep analysis of ESP-IDF Kconfig options for sta2eth project
> Based on comprehensive review of ESP32-P4 Kconfig reference

---

## Executive Summary

After analyzing the complete Kconfig reference, we identified the following optimization opportunities:

### Network Category
- Found 194 relevant configuration options
- Top options: CONFIG_LWIP_LCP_ECHOINTERVAL, CONFIG_LWIP_ESP_MLDV, CONFIG_LWIP_CHECK_THREAD_SAFETY, CONFIG_LWIP_DHCPS_MAX_HOSTNAME_LEN, CONFIG_LWIP_WND_SCALE

### WiFi Category
- Found 109 relevant configuration options
- Top options: CONFIG_ESP_WIFI_ENT_FREE_DYNAMIC_BUFFER, CONFIG_ESP_WIFI_SLP_BEACON_LOST_THRESHOLD, CONFIG_ESP_WIFI_MBEDTLS_TLS_CLIENT, CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING, CONFIG_ESP_WIFI_DEBUG_PRINT

### Memory Category
- Found 72 relevant configuration options
- Top options: CONFIG_BOOTLOADER_CACHE_, CONFIG_UHCI_ISR_CACHE_SAFE, CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE, CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP, CONFIG_TWAI_ISR_CACHE_SAFE

### Performance Category
- Found 134 relevant configuration options
- Top options: CONFIG_BOOTLOADER_CACHE_, CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE, CONFIG_MCPWM_CTRL_FUNC_IN_IRAM, CONFIG_ANA_CMPR_CTRL_FUNC_IN_IRAM, CONFIG_SPI_SLAVE_ISR_IN_IRAM

### Stability Category
- Found 43 relevant configuration options
- Top options: CONFIG_ESP_SYSTEM_PANIC, CONFIG_ESP_COREDUMP_LOGS, CONFIG_ESP_COREDUMP_UART_DELAY, CONFIG_ESP_TASK_WDT_PANIC, CONFIG_ESP_COREDUMP_MAX_TASKS_NUM

### Power Category
- Found 39 relevant configuration options
- Top options: CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP, CONFIG_ESP_SLEEP_MSPI_NEED_ALL_IO_PU, CONFIG_PM_POWER_DOWN_CPU_IN_LIGHT_SLEEP, CONFIG_ESP_PHY_REDUCE_TX_POWER, CONFIG_ESP_SLEEP_POWER_DOWN_FLASH

### FreeRTOS Category
- Found 168 relevant configuration options
- Top options: CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE, CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_MODE, CONFIG_SPI_SLAVE_ISR_IN_IRAM, CONFIG_FREERTOS_USE_STATS_FORMATTING_FUNCTIONS, CONFIG_BT_BLE_LOG_SPI_OUT_HCI_TASK_CNT

### System Category
- Found 247 relevant configuration options
- Top options: CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION, CONFIG_ESP_HTTPS_OTA_EVENT_POST_TIMEOUT, CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION, CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION, CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION


---

## Detailed Recommendations by Category


### Network Optimizations

#### CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- No (disabled) if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

#### CONFIG_BOOTLOADER_SKIP_VALIDATE_ALWAYS

Found in: Bootloader config

- No (disabled)

#### CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP

Found in: Bootloader config

- No (disabled) if CONFIG_SECURE_BOOT && CONFIG_SECURE_BOOT_INSECURE

No (disabled) if CONFIG_SECURE_BOOT && CONFIG_SECURE_BOOT_INSECURE

#### CONFIG_BOOTLOADER_SKIP_VALIDATE_ON_POWER_ON

Found in: Bootloader config

- No (disabled)

#### CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

#### CONFIG_BT_NIMBLE_IPSS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

#### CONFIG_BT_NIMBLE_ROLE_PERIPHERAL

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

#### CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Camera Controller Configurations

- No (disabled)

#### CONFIG_ESP_IPC_TASK_STACK_SIZE

Found in: Component config > IPC (Inter-Processor Call)

- from 2048 to 65536 if APPTRACE_ENABLE

- 2048 if APPTRACE_ENABLE
- 1024

#### CONFIG_ESP_IPC_USES_CALLERS_PRIORITY

Found in: Component config > IPC (Inter-Processor Call)

- Yes (enabled)


### ESP Timer (High Resolution Timer)

- CONFIG_ESP_TIMER_PROFILING
- CONFIG_ESP_TIMER_TASK_AFFINITY
- CONFIG_ESP_TIMER_TASK_STACK_SIZE
- CONFIG_ESP_TIMER_INTERRUPT_LEVEL
- CONFIG_ESP_TIMER_IN_IRAM
- CONFIG_ESP_TIMER_SHOW_EX...

_...and 184 more network options_


### WiFi Optimizations

#### CONFIG_ESP_HOST_WIFI_ENABLED

Found in: Component config > Wi-Fi

- No (disabled)

#### CONFIG_ESP_PHY_MAX_WIFI_TX_POWER

Found in: Component config > PHY

#### CONFIG_ESP_WIFI_

Found in: Component config > Wi-Fi

- from 2 to 128 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

from 2 to 128 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

- 10 if CONFIG_ESP_HOST_WIFI_ENABLED

10 if CONFIG_ESP_HOST_WIFI_ENABLED

#### CONFIG_ESP_WIFI_AMPDU_RX_ENABLED

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

#### CONFIG_ESP_WIFI_AMPDU_TX_ENABLED

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

#### CONFIG_ESP_WIFI_AMSDU_TX_ENABLED

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM >= 2 && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM >= 2 && CONFIG_ESP_HOST_WIFI_ENABLED

#### CONFIG_ESP_WIFI_BSS_MAX_IDLE_SUPPORT

Found in: Component config > Wi-Fi

- Yes (enabled) if (SOC_WIFI_HE_SUPPORT || CONFIG_ESP_WIFI_WNM_SUPPORT) && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if (SOC_WIFI_HE_SUPPORT || CONFIG_ESP_WIFI_WNM_SUPPORT) && CONFIG_ESP_HOST_WIFI_ENABLED

#### CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM

Found in: Component config > Wi-Fi

#### CONFIG_ESP_WIFI_CSI_ENABLED

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_CSI_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_CSI_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

#### CONFIG_ESP_WIFI_DEBUG_PRINT

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

_...and 99 more wifi options_


### Memory Optimizations

#### CONFIG_ANA_CMPR_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)

#### CONFIG_BLE_MESH_MSG_CACHE_SIZE

Found in: Component config > CONFIG_BLE_MESH

- from 2 to 65535 if CONFIG_BLE_MESH

from 2 to 65535 if CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH

#### CONFIG_BOOTLOADER_CACHE_

Found in: Bootloader config > Serial Flash Configurations

#### CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

#### CONFIG_BT_GATTC_CACHE_NVS_FLASH

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- No (disabled) if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

#### CONFIG_BT_GATTC_MAX_CACHE_CHAR

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- from 1 to 500 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 500 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

- 40 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_B...

#### CONFIG_BT_NIMBLE_MSYS_BUF_FROM_HEAP

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- Yes (enabled) if BT_LE_MSYS_INIT_IN_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED

#### CONFIG_CACHE_L

Found in: Component config > ESP System Settings > Cache config

Available options:

- 128KB (CONFIG_CACHE_L2_CACHE_128KB)
- 256KB (CONFIG_CACHE_L2_CACHE_256KB)
- 512KB (CONFIG_CACHE_L2_CACHE_512KB)

128KB (CONFIG_CACHE_L2_CACHE_128KB)

256KB (CONFIG_CACHE_L2_CACHE_256KB)

512KB (CONFIG_CACHE_L2_CAC...

#### CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Camera Controller Configurations

- No (disabled)


### ESP-Driver:DAC Configurations

- CONFIG_DAC_DMA_AUTO_16BIT_ALIGN
- CONFIG_DAC_ISR_IRAM_SAFE
- CONFIG_DAC_ENABLE_DEBUG_LOG
- CONFIG_DAC_CTRL_FUNC_IN_IRAM

CONFIG_DAC_DMA_AUTO_16BIT_ALIGN

CONFIG_DAC_ISR_I...

#### CONFIG_CAM_CTLR_ISP_DVP_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Camera Controller Configurations

- No (disabled)

_...and 62 more memory options_


### Performance Optimizations

#### CONFIG_ADC_CONTINUOUS_ISR_IRAM_SAFE

Found in: Component config > ADC and ADC Calibration

- No (disabled)


#### ADC Calibration Configurations

#### CONFIG_ADC_ONESHOT_CTRL_FUNC_IN_IRAM

Found in: Component config > ADC and ADC Calibration

- No (disabled)

#### CONFIG_ANA_CMPR_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)

#### CONFIG_ANA_CMPR_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)

#### CONFIG_ANA_CMPR_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- Yes (enabled)

#### CONFIG_BITSCRAMBLER_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:BitScrambler Configurations

- No (disabled)


### ESP-Driver:Camera Controller Configurations

- CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAFE
- CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE
- CONFIG_CAM_CTLR_ISP_DVP_ISR_CACHE_SAFE

CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAF...

#### CONFIG_BLE_MESH_MSG_CACHE_SIZE

Found in: Component config > CONFIG_BLE_MESH

- from 2 to 65535 if CONFIG_BLE_MESH

from 2 to 65535 if CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH

#### CONFIG_BOOTLOADER_CACHE_

Found in: Bootloader config > Serial Flash Configurations

#### CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION

Found in: Bootloader config

- The default "Size" setting will add the -Os (-Oz with clang) flag to CFLAGS.
- The "Debug" setting will add the -Og flag to CFLAGS.
- The "Performance" setting will add the -O2 flag to CFLAGS.

Available options:

- Size (-Os with GCC, -Oz with Clang) (CONFIG_BOOTLOADE...

#### CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

_...and 124 more performance options_


### Stability Optimizations

#### CONFIG_APPTRACE_ONPANIC_HOST_FLUSH_TMO

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from -1 to 5000 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from -1 to 5000 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- "-1" if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

"-1" if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

#### CONFIG_BOOTLOADER_WDT_DISABLE_IN_USER_CODE

Found in: Bootloader config > CONFIG_BOOTLOADER_WDT_ENABLE

- No (disabled)

#### CONFIG_BOOTLOADER_WDT_ENABLE

Found in: Bootloader config

- Yes (enabled)

#### CONFIG_BOOTLOADER_WDT_TIME_MS

Found in: Bootloader config > CONFIG_BOOTLOADER_WDT_ENABLE

- from 0 to 120000

- 9000

#### CONFIG_COMPILER_ASSERT_NDEBUG_EVALUATE

Found in: Compiler options

- No (disabled)

#### CONFIG_COMPILER_OPTIMIZATION_ASSERTION_LEVEL

Found in: Compiler options

- Enabled. Failure will print verbose assertion details. This is the default.
- Set to "silent" to save code size (failed assertions will abort() but user needs to use the aborting address to find the line number with the failed assertion.)
- Disabled entirely (not recomm...

#### CONFIG_ESP_BROWNOUT_DET

Found in: Component config > Hardware Settings > Power Supplier > Brownout Detector

- Yes (enabled)

#### CONFIG_ESP_BROWNOUT_DET_LVL_SEL

Found in: Component config > Hardware Settings > Power Supplier > Brownout Detector > CONFIG_ESP_BROWNOUT_DET

Available options:

- 2.6V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_7)
- 2.52V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_6)
- 2.42V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_5)

2.6V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL...

#### CONFIG_ESP_COREDUMP_CAPTURE_DRAM

Found in: Component config > Core dump

#### CONFIG_ESP_COREDUMP_CHECK_BOOT

Found in: Component config > Core dump

- Yes (enabled) if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

Yes (enabled) if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

_...and 33 more stability options_


### Power Optimizations

#### CONFIG_BLE_MESH_DEBUG_LOW_POWER

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG

#### CONFIG_BLE_MESH_GENERIC_POWER_LEVEL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

#### CONFIG_BLE_MESH_GENERIC_POWER_ONOFF_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

#### CONFIG_BLE_MESH_LOW_POWER

Found in: Component config > CONFIG_BLE_MESH

#### CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP

Found in: Bootloader config

- No (disabled) if CONFIG_SECURE_BOOT && CONFIG_SECURE_BOOT_INSECURE

No (disabled) if CONFIG_SECURE_BOOT && CONFIG_SECURE_BOOT_INSECURE

#### CONFIG_BOOTLOADER_SKIP_VALIDATE_ON_POWER_ON

Found in: Bootloader config

- No (disabled)

#### CONFIG_BT_BLE_FEAT_POWER_CONTROL

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_POWER_CONTROL_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPOR...

#### CONFIG_BT_NIMBLE_BLE_POWER_CONTROL

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_BLE_POWER_CONTROL_SUPPORTED && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_N...

#### CONFIG_BT_NIMBLE_MESH_LOW_POWER

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

#### CONFIG_ESP_COEX_POWER_MANAGEMENT

Found in: Component config > Wireless Coexistence

_...and 29 more power options_


### FreeRTOS Optimizations

#### CONFIG_ADC_CONTINUOUS_ISR_IRAM_SAFE

Found in: Component config > ADC and ADC Calibration

- No (disabled)


#### ADC Calibration Configurations

#### CONFIG_ANA_CMPR_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)

#### CONFIG_ANA_CMPR_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- Yes (enabled)

#### CONFIG_APPTRACE_UART_TASK_PRIO

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 1 to 32 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 1 to 32 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 1 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE...

#### CONFIG_BLE_LOG_LBM_ATOMIC_LOCK_ISR_CNT

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 1 if CONFIG_BLE_LOG_ENABLED

1 if CONFIG_BLE_LOG_ENABLED

#### CONFIG_BLE_LOG_LBM_ATOMIC_LOCK_TASK_CNT

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 2 if CONFIG_BLE_LOG_ENABLED

2 if CONFIG_BLE_LOG_ENABLED

#### CONFIG_BLE_LOG_TASK_STACK_SIZE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 1024 if CONFIG_BLE_LOG_ENABLED

1024 if CONFIG_BLE_LOG_ENABLED

#### CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if ESP32_IRAM_AS_8BIT_ACCESSIBLE_MEMORY && CONFIG_BLE_MESH

#### CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_MODE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC

Available options:

- External SPIRAM (CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_EXTERNAL) If enabled, BLE Mesh allocates dynamic memory from external SPIRAM for FreeRTOS objects, i.e. mutex, queue, and task stack. Ext...

#### CONFIG_BLE_MESH_FRIEND_QUEUE_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FRIEND

- from 2 to 65536 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

from 2 to 65536 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

- 16 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

16 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

_...and 158 more freertos options_


### System Optimizations

#### CONFIG_ADC_ENABLE_DEBUG_LOG

Found in: Component config > ADC and ADC Calibration

- No (disabled)


### Wireless Coexistence

- CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE
- CONFIG_ESP_COEX_GPIO_DEBUG
- CONFIG_ESP_COEX_SW_COEXIST_ENABLE
- CONFIG_ESP_COEX_POWER_MANAGEMENT

CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE

CONFIG_ESP_COEX_G...

#### CONFIG_ANA_CMPR_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)


### ESP-Driver:BitScrambler Configurations

- CONFIG_BITSCRAMBLER_CTRL_FUNC_IN_IRAM

CONFIG_BITSCRAMBLER_CTRL_FUNC_IN_IRAM

#### CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_...

#### CONFIG_BLE_BLUEDROID_APPL_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION

- ...

#### CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_...

#### CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION

...

#### CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_...

#### CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION

...

#### CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_...

#### CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION

...

_...and 237 more system options_

