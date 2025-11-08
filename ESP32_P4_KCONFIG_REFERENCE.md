# ESP-IDF Kconfig Configuration Reference

> Comprehensive configuration options from ESP-IDF official documentation
> For ESP32-P4 and other ESP32 series chips


# Configuration Options Reference


## Build type

- CONFIG_APP_BUILD_TYPE
- CONFIG_APP_BUILD_TYPE_PURE_RAM_APP
- CONFIG_APP_REPRODUCIBLE_BUILD
- CONFIG_APP_NO_BLOBS

CONFIG_APP_BUILD_TYPE

CONFIG_APP_BUILD_TYPE_PURE_RAM_APP

CONFIG_APP_REPRODUCIBLE_BUILD

CONFIG_APP_NO_BLOBS


### CONFIG_APP_BUILD_TYPE

Found in: Build type

CONFIG_APP_BUILD_TYPE_RAM=y CONFIG_VFS_SUPPORT_TERMIOS= CONFIG_LIBC_NEWLIB_NANO_FORMAT=y CONFIG_ESP_SYSTEM_PANIC_PRINT_HALT=y CONFIG_ESP_DEBUG_STUBS_ENABLE= CONFIG_ESP_ERR_TO_NAME_LOOKUP=

Available options:

- Default (binary application + 2nd stage bootloader) (CONFIG_APP_BUILD_TYPE_APP_2NDBOOT)
- Build app runs entirely in RAM (EXPERIMENTAL) (CONFIG_APP_BUILD_TYPE_RAM)


### CONFIG_APP_BUILD_TYPE_PURE_RAM_APP

Found in: Build type


### CONFIG_APP_REPRODUCIBLE_BUILD

Found in: Build type

- No (disabled)


### CONFIG_APP_NO_BLOBS

Found in: Build type

- No (disabled)


## Bootloader config

- Application Rollback
- Bootloader manager
- CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION
- CONFIG_BOOTLOADER_REGION_PROTECTION_ENABLE
- CONFIG_BOOTLOADER_APP_TEST
- CONFIG_BOOTLOADER_FACTORY_RESET
- CONFIG_BOOTLOADER_HOLD_TIME_GPIO
- Log
- Recovery Bootloader and Rollback
- CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC
- Serial Flash Configurations
- CONFIG_BOOTLOADER_SKIP_VALIDATE_ALWAYS
- CONFIG_BOOTLOADER_SKIP_VALIDATE_ON_POWER_ON
- CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP
- CONFIG_BOOTLOADER_WDT_ENABLE
- CONFIG_BOOTLOADER_VDDSDIO_BOOST

CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION

CONFIG_BOOTLOADER_REGION_PROTECTION_ENABLE

CONFIG_BOOTLOADER_APP_TEST

CONFIG_BOOTLOADER_FACTORY_RESET

CONFIG_BOOTLOADER_HOLD_TIME_GPIO

CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC

CONFIG_BOOTLOADER_SKIP_VALIDATE_ALWAYS

CONFIG_BOOTLOADER_SKIP_VALIDATE_ON_POWER_ON

CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP

CONFIG_BOOTLOADER_WDT_ENABLE

CONFIG_BOOTLOADER_VDDSDIO_BOOST


### Bootloader manager

- CONFIG_BOOTLOADER_PROJECT_VER
- CONFIG_BOOTLOADER_COMPILE_TIME_DATE

CONFIG_BOOTLOADER_PROJECT_VER

CONFIG_BOOTLOADER_COMPILE_TIME_DATE


#### CONFIG_BOOTLOADER_COMPILE_TIME_DATE

Found in: Bootloader config > Bootloader manager


#### CONFIG_BOOTLOADER_PROJECT_VER

Found in: Bootloader config > Bootloader manager

- from 0 to 4294967295

- 1


### Application Rollback

- CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE

CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE


#### CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE

Found in: Bootloader config > Application Rollback

- No (disabled)


##### CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

Found in: Bootloader config > Application Rollback > CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE

- No (disabled) if CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE

No (disabled) if CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE


##### CONFIG_BOOTLOADER_APP_SECURE_VERSION

Found in: Bootloader config > Application Rollback > CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE > CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

- 0 if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

0 if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK


##### CONFIG_BOOTLOADER_APP_SEC_VER_SIZE_EFUSE_FIELD

Found in: Bootloader config > Application Rollback > CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE > CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

- from 1 to 16 if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

from 1 to 16 if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

- 16 if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

16 if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK


##### CONFIG_BOOTLOADER_EFUSE_SECURE_VERSION_EMULATE

Found in: Bootloader config > Application Rollback > CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE > CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

- No (disabled) if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK

No (disabled) if CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK


### Recovery Bootloader and Rollback

- CONFIG_BOOTLOADER_RECOVERY_ENABLE

CONFIG_BOOTLOADER_RECOVERY_ENABLE


#### CONFIG_BOOTLOADER_RECOVERY_ENABLE

Found in: Bootloader config > Recovery Bootloader and Rollback

- No (disabled) if SOC_RECOVERY_BOOTLOADER_SUPPORTED


##### CONFIG_BOOTLOADER_RECOVERY_OFFSET

Found in: Bootloader config > Recovery Bootloader and Rollback > CONFIG_BOOTLOADER_RECOVERY_ENABLE

- from 0x0 to 0xFFE000 if CONFIG_BOOTLOADER_RECOVERY_ENABLE

from 0x0 to 0xFFE000 if CONFIG_BOOTLOADER_RECOVERY_ENABLE

- "0x3F0000" if CONFIG_BOOTLOADER_RECOVERY_ENABLE

"0x3F0000" if CONFIG_BOOTLOADER_RECOVERY_ENABLE


##### CONFIG_BOOTLOADER_ANTI_ROLLBACK_ENABLE

Found in: Bootloader config > Recovery Bootloader and Rollback > CONFIG_BOOTLOADER_RECOVERY_ENABLE

- No (disabled) if CONFIG_BOOTLOADER_RECOVERY_ENABLE

No (disabled) if CONFIG_BOOTLOADER_RECOVERY_ENABLE


##### CONFIG_BOOTLOADER_SECURE_VERSION

Found in: Bootloader config > Recovery Bootloader and Rollback > CONFIG_BOOTLOADER_RECOVERY_ENABLE > CONFIG_BOOTLOADER_ANTI_ROLLBACK_ENABLE

- from 0 to 4 if CONFIG_BOOTLOADER_ANTI_ROLLBACK_ENABLE

from 0 to 4 if CONFIG_BOOTLOADER_ANTI_ROLLBACK_ENABLE

- 0 if CONFIG_BOOTLOADER_ANTI_ROLLBACK_ENABLE

0 if CONFIG_BOOTLOADER_ANTI_ROLLBACK_ENABLE


### CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION

Found in: Bootloader config

- The default "Size" setting will add the -Os (-Oz with clang) flag to CFLAGS.
- The "Debug" setting will add the -Og flag to CFLAGS.
- The "Performance" setting will add the -O2 flag to CFLAGS.

Available options:

- Size (-Os with GCC, -Oz with Clang) (CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION_SIZE)
- Debug (-Og) (CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION_DEBUG)
- Optimize for performance (-O2) (CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION_PERF)

Size (-Os with GCC, -Oz with Clang) (CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION_SIZE)

Debug (-Og) (CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION_DEBUG)

Optimize for performance (-O2) (CONFIG_BOOTLOADER_COMPILER_OPTIMIZATION_PERF)


### Log

- CONFIG_BOOTLOADER_LOG_LEVEL
- Format
- CONFIG_BOOTLOADER_LOG_VERSION
- Settings

CONFIG_BOOTLOADER_LOG_LEVEL

CONFIG_BOOTLOADER_LOG_VERSION


#### CONFIG_BOOTLOADER_LOG_VERSION

Found in: Bootloader config > Log

Available options:

- V1 (CONFIG_BOOTLOADER_LOG_VERSION_1)
- V2 (CONFIG_BOOTLOADER_LOG_VERSION_2)

V1 (CONFIG_BOOTLOADER_LOG_VERSION_1)

V2 (CONFIG_BOOTLOADER_LOG_VERSION_2)


#### CONFIG_BOOTLOADER_LOG_LEVEL

Found in: Bootloader config > Log

Available options:

- No output (CONFIG_BOOTLOADER_LOG_LEVEL_NONE)
- Error (CONFIG_BOOTLOADER_LOG_LEVEL_ERROR)
- Warning (CONFIG_BOOTLOADER_LOG_LEVEL_WARN)
- Info (CONFIG_BOOTLOADER_LOG_LEVEL_INFO)
- Debug (CONFIG_BOOTLOADER_LOG_LEVEL_DEBUG)
- Verbose (CONFIG_BOOTLOADER_LOG_LEVEL_VERBOSE)

No output (CONFIG_BOOTLOADER_LOG_LEVEL_NONE)

Error (CONFIG_BOOTLOADER_LOG_LEVEL_ERROR)

Warning (CONFIG_BOOTLOADER_LOG_LEVEL_WARN)

Info (CONFIG_BOOTLOADER_LOG_LEVEL_INFO)

Debug (CONFIG_BOOTLOADER_LOG_LEVEL_DEBUG)

Verbose (CONFIG_BOOTLOADER_LOG_LEVEL_VERBOSE)


#### Format

- CONFIG_BOOTLOADER_LOG_COLORS_SUPPORT
- CONFIG_BOOTLOADER_LOG_TIMESTAMP_SUPPORT
- CONFIG_BOOTLOADER_LOG_COLORS
- CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE

CONFIG_BOOTLOADER_LOG_COLORS_SUPPORT

CONFIG_BOOTLOADER_LOG_TIMESTAMP_SUPPORT

CONFIG_BOOTLOADER_LOG_COLORS

CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE


##### CONFIG_BOOTLOADER_LOG_COLORS

Found in: Bootloader config > Log > Format

- No (disabled)


##### CONFIG_BOOTLOADER_LOG_COLORS_SUPPORT

Found in: Bootloader config > Log > Format

- No (disabled) if CONFIG_BOOTLOADER_LOG_VERSION_2

No (disabled) if CONFIG_BOOTLOADER_LOG_VERSION_2


##### CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE

Found in: Bootloader config > Log > Format

- "None" - The log will only contain the actual log messages themselves without any time-related information. Avoiding timestamps can help conserve processing power and memory. It might useful when you perform log analysis or debugging, sometimes it's more straightforward to work with logs that lack timestamps, especially if the time of occurrence is not critical for understanding the issues. "I log_test: info message"
- "Milliseconds since boot" is calculated from the RTOS tick count multiplied by the tick period. This time will reset after a software reboot. "I (112500) log_test: info message"

Available options:

- None (CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE_NONE)
- Milliseconds Since Boot (CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE_CPU_TICKS)

None (CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE_NONE)

Milliseconds Since Boot (CONFIG_BOOTLOADER_LOG_TIMESTAMP_SOURCE_CPU_TICKS)


##### CONFIG_BOOTLOADER_LOG_TIMESTAMP_SUPPORT

Found in: Bootloader config > Log > Format

- Yes (enabled) if CONFIG_BOOTLOADER_LOG_VERSION_2

Yes (enabled) if CONFIG_BOOTLOADER_LOG_VERSION_2


#### Settings

- CONFIG_BOOTLOADER_LOG_MODE

CONFIG_BOOTLOADER_LOG_MODE


##### CONFIG_BOOTLOADER_LOG_MODE

Found in: Bootloader config > Log > Settings

Available options:

- Text Log Mode (CONFIG_BOOTLOADER_LOG_MODE_TEXT) Enables text-based logging, where log messages are stored in a human-readable format. This mode is useful for development and debugging, as it allows logs to be easily read and interpreted without additional processing.

Text Log Mode (CONFIG_BOOTLOADER_LOG_MODE_TEXT)

Binary Log Mode (CONFIG_BOOTLOADER_LOG_MODE_BINARY)


### Serial Flash Configurations

- CONFIG_BOOTLOADER_FLASH_DC_AWARE
- CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH
- CONFIG_BOOTLOADER_FLASH_XMC_SUPPORT

CONFIG_BOOTLOADER_FLASH_DC_AWARE

CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH

CONFIG_BOOTLOADER_FLASH_XMC_SUPPORT


#### CONFIG_BOOTLOADER_FLASH_DC_AWARE

Found in: Bootloader config > Serial Flash Configurations


#### CONFIG_BOOTLOADER_FLASH_XMC_SUPPORT

Found in: Bootloader config > Serial Flash Configurations

- Yes (enabled)


#### CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH

Found in: Bootloader config > Serial Flash Configurations


### CONFIG_BOOTLOADER_VDDSDIO_BOOST

Found in: Bootloader config

Available options:

- 1.8V (CONFIG_BOOTLOADER_VDDSDIO_BOOST_1_8V)
- 1.9V (CONFIG_BOOTLOADER_VDDSDIO_BOOST_1_9V)

1.8V (CONFIG_BOOTLOADER_VDDSDIO_BOOST_1_8V)

1.9V (CONFIG_BOOTLOADER_VDDSDIO_BOOST_1_9V)


### CONFIG_BOOTLOADER_FACTORY_RESET

Found in: Bootloader config

- No (disabled)


#### CONFIG_BOOTLOADER_NUM_PIN_FACTORY_RESET

Found in: Bootloader config > CONFIG_BOOTLOADER_FACTORY_RESET

- from 0 to 54 if CONFIG_BOOTLOADER_FACTORY_RESET

from 0 to 54 if CONFIG_BOOTLOADER_FACTORY_RESET

- 4 if CONFIG_BOOTLOADER_FACTORY_RESET

4 if CONFIG_BOOTLOADER_FACTORY_RESET


#### CONFIG_BOOTLOADER_FACTORY_RESET_PIN_LEVEL

Found in: Bootloader config > CONFIG_BOOTLOADER_FACTORY_RESET

Available options:

- Reset on GPIO low (CONFIG_BOOTLOADER_FACTORY_RESET_PIN_LOW)
- Reset on GPIO high (CONFIG_BOOTLOADER_FACTORY_RESET_PIN_HIGH)

Reset on GPIO low (CONFIG_BOOTLOADER_FACTORY_RESET_PIN_LOW)

Reset on GPIO high (CONFIG_BOOTLOADER_FACTORY_RESET_PIN_HIGH)


#### CONFIG_BOOTLOADER_OTA_DATA_ERASE

Found in: Bootloader config > CONFIG_BOOTLOADER_FACTORY_RESET


#### CONFIG_BOOTLOADER_DATA_FACTORY_RESET

Found in: Bootloader config > CONFIG_BOOTLOADER_FACTORY_RESET

- "nvs" if CONFIG_BOOTLOADER_FACTORY_RESET

"nvs" if CONFIG_BOOTLOADER_FACTORY_RESET


### CONFIG_BOOTLOADER_APP_TEST

Found in: Bootloader config


#### CONFIG_BOOTLOADER_NUM_PIN_APP_TEST

Found in: Bootloader config > CONFIG_BOOTLOADER_APP_TEST

- from 0 to 54 if CONFIG_BOOTLOADER_APP_TEST

from 0 to 54 if CONFIG_BOOTLOADER_APP_TEST

- 18 if CONFIG_BOOTLOADER_APP_TEST

18 if CONFIG_BOOTLOADER_APP_TEST


#### CONFIG_BOOTLOADER_APP_TEST_PIN_LEVEL

Found in: Bootloader config > CONFIG_BOOTLOADER_APP_TEST

Available options:

- Enter test app on GPIO low (CONFIG_BOOTLOADER_APP_TEST_PIN_LOW)
- Enter test app on GPIO high (CONFIG_BOOTLOADER_APP_TEST_PIN_HIGH)

Enter test app on GPIO low (CONFIG_BOOTLOADER_APP_TEST_PIN_LOW)

Enter test app on GPIO high (CONFIG_BOOTLOADER_APP_TEST_PIN_HIGH)


### CONFIG_BOOTLOADER_HOLD_TIME_GPIO

Found in: Bootloader config

- 5 if CONFIG_BOOTLOADER_FACTORY_RESET || CONFIG_BOOTLOADER_APP_TEST

5 if CONFIG_BOOTLOADER_FACTORY_RESET || CONFIG_BOOTLOADER_APP_TEST


### CONFIG_BOOTLOADER_REGION_PROTECTION_ENABLE

Found in: Bootloader config

- Yes (enabled)


### CONFIG_BOOTLOADER_WDT_ENABLE

Found in: Bootloader config

- Yes (enabled)


#### CONFIG_BOOTLOADER_WDT_DISABLE_IN_USER_CODE

Found in: Bootloader config > CONFIG_BOOTLOADER_WDT_ENABLE

- No (disabled)


#### CONFIG_BOOTLOADER_WDT_TIME_MS

Found in: Bootloader config > CONFIG_BOOTLOADER_WDT_ENABLE

- from 0 to 120000

- 9000


### CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP

Found in: Bootloader config

- No (disabled) if CONFIG_SECURE_BOOT && CONFIG_SECURE_BOOT_INSECURE

No (disabled) if CONFIG_SECURE_BOOT && CONFIG_SECURE_BOOT_INSECURE


### CONFIG_BOOTLOADER_SKIP_VALIDATE_ON_POWER_ON

Found in: Bootloader config

- No (disabled)


### CONFIG_BOOTLOADER_SKIP_VALIDATE_ALWAYS

Found in: Bootloader config

- No (disabled)


### CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC

Found in: Bootloader config

- No (disabled)


#### CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC_IN_CRC

Found in: Bootloader config > CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC

- No (disabled) if CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC

No (disabled) if CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC


#### CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC_SIZE

Found in: Bootloader config > CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC

- 0 if CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC

0 if CONFIG_BOOTLOADER_CUSTOM_RESERVE_RTC


## Security features

- CONFIG_SECURE_BOOT_INSECURE
- CONFIG_SECURE_SIGNED_APPS_SCHEME
- CONFIG_SECURE_SIGNED_ON_BOOT_NO_SECURE_BOOT
- CONFIG_SECURE_FLASH_CHECK_ENC_EN_IN_APP
- CONFIG_SECURE_BOOT_V2_ALLOW_EFUSE_RD_DIS
- CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_SIZE
- CONFIG_SECURE_BOOT_ENABLE_AGGRESSIVE_KEY_REVOKE
- CONFIG_SECURE_FLASH_ENC_ENABLED
- CONFIG_SECURE_BOOT
- CONFIG_SECURE_FLASH_ENCRYPT_ONLY_IMAGE_LEN_IN_APP_PART
- CONFIG_SECURE_BOOT_FLASH_BOOTLOADER_DEFAULT
- CONFIG_SECURE_BOOTLOADER_KEY_ENCODING
- CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC
- Potentially insecure options
- CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT
- CONFIG_SECURE_BOOT_VERIFICATION_KEY
- CONFIG_SECURE_BOOTLOADER_MODE
- CONFIG_SECURE_BOOT_BUILD_SIGNED_BINARIES
- CONFIG_SECURE_UART_ROM_DL_MODE
- CONFIG_SECURE_SIGNED_ON_UPDATE_NO_SECURE_BOOT

CONFIG_SECURE_BOOT_INSECURE

CONFIG_SECURE_SIGNED_APPS_SCHEME

CONFIG_SECURE_SIGNED_ON_BOOT_NO_SECURE_BOOT

CONFIG_SECURE_FLASH_CHECK_ENC_EN_IN_APP

CONFIG_SECURE_BOOT_V2_ALLOW_EFUSE_RD_DIS

CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_SIZE

CONFIG_SECURE_BOOT_ENABLE_AGGRESSIVE_KEY_REVOKE

CONFIG_SECURE_FLASH_ENC_ENABLED

CONFIG_SECURE_BOOT

CONFIG_SECURE_FLASH_ENCRYPT_ONLY_IMAGE_LEN_IN_APP_PART

CONFIG_SECURE_BOOT_FLASH_BOOTLOADER_DEFAULT

CONFIG_SECURE_BOOTLOADER_KEY_ENCODING

CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC

CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT

CONFIG_SECURE_BOOT_VERIFICATION_KEY

CONFIG_SECURE_BOOTLOADER_MODE

CONFIG_SECURE_BOOT_BUILD_SIGNED_BINARIES

CONFIG_SECURE_UART_ROM_DL_MODE

CONFIG_SECURE_SIGNED_ON_UPDATE_NO_SECURE_BOOT


### CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT

Found in: Security features


### CONFIG_SECURE_SIGNED_APPS_SCHEME

Found in: Security features

- Secure boot V1 Legacy custom secure boot scheme. Supported in ESP32 SoC.
- Secure boot V2 RSA based secure boot scheme. Supported in ESP32-ECO3 (ESP32 Chip Revision 3 onwards), ESP32-S2, ESP32-C3, ESP32-S3 SoCs. ECDSA based secure boot scheme. Supported in ESP32-C2 SoC.

- Legacy custom secure boot scheme. Supported in ESP32 SoC.

- RSA based secure boot scheme. Supported in ESP32-ECO3 (ESP32 Chip Revision 3 onwards), ESP32-S2, ESP32-C3, ESP32-S3 SoCs.
- ECDSA based secure boot scheme. Supported in ESP32-C2 SoC.

Available options:

- ECDSA (CONFIG_SECURE_SIGNED_APPS_ECDSA_SCHEME) Embeds the ECDSA public key in the bootloader and signs the application with an ECDSA key. Refer to the documentation before enabling.
- RSA (CONFIG_SECURE_SIGNED_APPS_RSA_SCHEME) Appends the RSA-3072 based Signature block to the application. Refer to <Secure Boot Version 2 documentation link> before enabling.
- ECDSA (V2) (CONFIG_SECURE_SIGNED_APPS_ECDSA_V2_SCHEME) For Secure boot V2 (e.g., ESP32-C2 SoC), appends ECDSA based signature block to the application. Refer to documentation before enabling.

ECDSA (CONFIG_SECURE_SIGNED_APPS_ECDSA_SCHEME)

RSA (CONFIG_SECURE_SIGNED_APPS_RSA_SCHEME)

ECDSA (V2) (CONFIG_SECURE_SIGNED_APPS_ECDSA_V2_SCHEME)


### CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_SIZE

Found in: Security features

- 192 bit key using NISTP192 curve
- 256 bit key using NISTP256 curve (Recommended)
- 384 bit key using NISTP384 curve (Recommended)

Available options:

- Using ECC curve NISTP192 (CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_192_BITS)
- Using ECC curve NISTP256 (Recommended) (CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_256_BITS)
- Using ECC curve NISTP384 (Recommended) (CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_384_BITS)

Using ECC curve NISTP192 (CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_192_BITS)

Using ECC curve NISTP256 (Recommended) (CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_256_BITS)

Using ECC curve NISTP384 (Recommended) (CONFIG_SECURE_BOOT_ECDSA_KEY_LEN_384_BITS)


### CONFIG_SECURE_SIGNED_ON_BOOT_NO_SECURE_BOOT

Found in: Security features

- No (disabled) if CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT && CONFIG_SECURE_SIGNED_APPS_ECDSA_SCHEME

No (disabled) if CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT && CONFIG_SECURE_SIGNED_APPS_ECDSA_SCHEME


### CONFIG_SECURE_SIGNED_ON_UPDATE_NO_SECURE_BOOT

Found in: Security features

- Yes (enabled) if CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT

Yes (enabled) if CONFIG_SECURE_SIGNED_APPS_NO_SECURE_BOOT


### CONFIG_SECURE_BOOT

Found in: Security features

- No (disabled)


#### CONFIG_SECURE_BOOT_VERSION

Found in: Security features > CONFIG_SECURE_BOOT

- RSA based scheme is supported in ESP32 (Revision 3 onwards), ESP32-S2, ESP32-C3 (ECO3), ESP32-S3.
- ECDSA based scheme is supported in ESP32-C2 SoC.

Available options:

- Enable Secure Boot version 1 (CONFIG_SECURE_BOOT_V1_ENABLED) Build a bootloader which enables secure boot version 1 on first boot. Refer to the Secure Boot section of the ESP-IDF Programmer's Guide for this version before enabling.
- Enable Secure Boot version 2 (CONFIG_SECURE_BOOT_V2_ENABLED) Build a bootloader which enables Secure Boot version 2 on first boot. Refer to Secure Boot V2 section of the ESP-IDF Programmer's Guide for this version before enabling.

Enable Secure Boot version 1 (CONFIG_SECURE_BOOT_V1_ENABLED)

Enable Secure Boot version 2 (CONFIG_SECURE_BOOT_V2_ENABLED)


### CONFIG_SECURE_BOOTLOADER_MODE

Found in: Security features

Available options:

- One-time flash (CONFIG_SECURE_BOOTLOADER_ONE_TIME_FLASH) On first boot, the bootloader will generate a key which is not readable externally or by software. A digest is generated from the bootloader image itself. This digest will be verified on each subsequent boot. Enabling this option means that the bootloader cannot be changed after the first time it is booted.
- Reflashable (CONFIG_SECURE_BOOTLOADER_REFLASHABLE) Generate a reusable secure bootloader key, derived (via SHA-256) from the secure boot signing key. This allows the secure bootloader to be re-flashed by anyone with access to the secure boot signing key. This option is less secure than one-time flash, because a leak of the digest key from one device allows reflashing of any device that uses it.

One-time flash (CONFIG_SECURE_BOOTLOADER_ONE_TIME_FLASH)

Reflashable (CONFIG_SECURE_BOOTLOADER_REFLASHABLE)


### CONFIG_SECURE_BOOT_BUILD_SIGNED_BINARIES

Found in: Security features


#### CONFIG_SECURE_BOOT_SIGNING_KEY

Found in: Security features > CONFIG_SECURE_BOOT_BUILD_SIGNED_BINARIES

- "secure_boot_signing_key.pem" if CONFIG_SECURE_BOOT_BUILD_SIGNED_BINARIES

"secure_boot_signing_key.pem" if CONFIG_SECURE_BOOT_BUILD_SIGNED_BINARIES


### CONFIG_SECURE_BOOT_VERIFICATION_KEY

Found in: Security features


### CONFIG_SECURE_BOOT_ENABLE_AGGRESSIVE_KEY_REVOKE

Found in: Security features

- No (disabled) if CONFIG_SECURE_BOOT

No (disabled) if CONFIG_SECURE_BOOT


### CONFIG_SECURE_BOOT_V2_ALLOW_EFUSE_RD_DIS

Found in: Security features

- No (disabled) if CONFIG_SECURE_BOOT_V2_ENABLED

No (disabled) if CONFIG_SECURE_BOOT_V2_ENABLED


### CONFIG_SECURE_BOOT_FLASH_BOOTLOADER_DEFAULT

Found in: Security features

- No (disabled) if CONFIG_SECURE_BOOT_V2_ENABLED

No (disabled) if CONFIG_SECURE_BOOT_V2_ENABLED


### CONFIG_SECURE_BOOTLOADER_KEY_ENCODING

Found in: Security features

Available options:

- No encoding (256 bit key) (CONFIG_SECURE_BOOTLOADER_KEY_ENCODING_256BIT)
- 3/4 encoding (192 bit key) (CONFIG_SECURE_BOOTLOADER_KEY_ENCODING_192BIT)

No encoding (256 bit key) (CONFIG_SECURE_BOOTLOADER_KEY_ENCODING_256BIT)

3/4 encoding (192 bit key) (CONFIG_SECURE_BOOTLOADER_KEY_ENCODING_192BIT)


### CONFIG_SECURE_BOOT_INSECURE

Found in: Security features

- No (disabled) if CONFIG_SECURE_BOOT

No (disabled) if CONFIG_SECURE_BOOT


### CONFIG_SECURE_FLASH_ENC_ENABLED

Found in: Security features

- No (disabled)


#### CONFIG_SECURE_FLASH_ENCRYPTION_KEYSIZE

Found in: Security features > CONFIG_SECURE_FLASH_ENC_ENABLED

- AES-128 uses a 256-bit key (32 bytes) derived from 128 bits (16 bytes) burned in half Efuse key block. Internally, it calculates SHA256(128 bits)
- AES-128 uses a 256-bit key (32 bytes) which occupies one Efuse key block.
- AES-256 uses a 512-bit key (64 bytes) which occupies two Efuse key blocks.

Available options:

- AES-128 key derived from 128 bits (SHA256(128 bits)) (CONFIG_SECURE_FLASH_ENCRYPTION_AES128_DERIVED)
- AES-128 (256-bit key) (CONFIG_SECURE_FLASH_ENCRYPTION_AES128)
- AES-256 (512-bit key) (CONFIG_SECURE_FLASH_ENCRYPTION_AES256)

AES-128 (256-bit key) (CONFIG_SECURE_FLASH_ENCRYPTION_AES128)

AES-256 (512-bit key) (CONFIG_SECURE_FLASH_ENCRYPTION_AES256)


#### CONFIG_SECURE_FLASH_ENCRYPTION_MODE

Found in: Security features > CONFIG_SECURE_FLASH_ENC_ENABLED

Available options:

- Development (NOT SECURE) (CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT)
- Release (CONFIG_SECURE_FLASH_ENCRYPTION_MODE_RELEASE)

Development (NOT SECURE) (CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT)

Release (CONFIG_SECURE_FLASH_ENCRYPTION_MODE_RELEASE)


### Potentially insecure options

- CONFIG_SECURE_BOOT_ALLOW_SHORT_APP_PARTITION
- CONFIG_SECURE_BOOT_ALLOW_JTAG
- CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_ENC
- CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_CACHE
- CONFIG_SECURE_BOOT_ALLOW_UNUSED_DIGEST_SLOTS
- CONFIG_SECURE_FLASH_REQUIRE_ALREADY_ENABLED
- CONFIG_SECURE_FLASH_SKIP_WRITE_PROTECTION_CACHE
- CONFIG_SECURE_BOOT_SKIP_WRITE_PROTECTION_SCA

CONFIG_SECURE_BOOT_ALLOW_SHORT_APP_PARTITION

CONFIG_SECURE_BOOT_ALLOW_JTAG

CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_ENC

CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_CACHE

CONFIG_SECURE_BOOT_ALLOW_UNUSED_DIGEST_SLOTS

CONFIG_SECURE_FLASH_REQUIRE_ALREADY_ENABLED

CONFIG_SECURE_FLASH_SKIP_WRITE_PROTECTION_CACHE

CONFIG_SECURE_BOOT_SKIP_WRITE_PROTECTION_SCA


#### CONFIG_SECURE_BOOT_ALLOW_JTAG

Found in: Security features > Potentially insecure options

- No (disabled) if CONFIG_SECURE_BOOT_INSECURE || CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT

No (disabled) if CONFIG_SECURE_BOOT_INSECURE || CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT


#### CONFIG_SECURE_BOOT_ALLOW_SHORT_APP_PARTITION

Found in: Security features > Potentially insecure options


#### CONFIG_SECURE_BOOT_ALLOW_UNUSED_DIGEST_SLOTS

Found in: Security features > Potentially insecure options

- No (disabled) if CONFIG_SECURE_BOOT_INSECURE

No (disabled) if CONFIG_SECURE_BOOT_INSECURE


#### CONFIG_SECURE_BOOT_SKIP_WRITE_PROTECTION_SCA

Found in: Security features > Potentially insecure options

- Yes (enabled) if CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC && SOC_ECDSA_SUPPORT_CURVE_P384 && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND
- No (disabled) if SOC_ECDSA_SUPPORT_CURVE_P384 && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND

Yes (enabled) if CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC && SOC_ECDSA_SUPPORT_CURVE_P384 && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND


#### CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_ENC

Found in: Security features > Potentially insecure options

- No (disabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT

No (disabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT


#### CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_CACHE

Found in: Security features > Potentially insecure options

- No (disabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT && (SOC_EFUSE_DIS_DOWNLOAD_ICACHE || SOC_EFUSE_DIS_DOWNLOAD_DCACHE)

No (disabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT && (SOC_EFUSE_DIS_DOWNLOAD_ICACHE || SOC_EFUSE_DIS_DOWNLOAD_DCACHE)


#### CONFIG_SECURE_FLASH_REQUIRE_ALREADY_ENABLED

Found in: Security features > Potentially insecure options

- No (disabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT

No (disabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_DEVELOPMENT


#### CONFIG_SECURE_FLASH_SKIP_WRITE_PROTECTION_CACHE

Found in: Security features > Potentially insecure options


### CONFIG_SECURE_FLASH_ENCRYPT_ONLY_IMAGE_LEN_IN_APP_PART

Found in: Security features


### CONFIG_SECURE_FLASH_CHECK_ENC_EN_IN_APP

Found in: Security features

- Yes (enabled) if CONFIG_SECURE_FLASH_ENC_ENABLED

Yes (enabled) if CONFIG_SECURE_FLASH_ENC_ENABLED


### CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC

Found in: Security features

- Yes (enabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_RELEASE && CONFIG_SECURE_FLASH_ENC_ENABLED && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND
- No (disabled) if CONFIG_SECURE_FLASH_ENC_ENABLED && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND

Yes (enabled) if CONFIG_SECURE_FLASH_ENCRYPTION_MODE_RELEASE && CONFIG_SECURE_FLASH_ENC_ENABLED && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND

No (disabled) if CONFIG_SECURE_FLASH_ENC_ENABLED && SOC_FLASH_ENCRYPTION_XTS_AES_SUPPORT_PSEUDO_ROUND


#### CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH

Found in: Security features > CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC

Available options:

- Low (CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH_LOW)
- Medium (CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH_MEDIUM)
- High (CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH_HIGH)

Low (CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH_LOW)

Medium (CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH_MEDIUM)

High (CONFIG_SECURE_FLASH_PSEUDO_ROUND_FUNC_STRENGTH_HIGH)


### CONFIG_SECURE_UART_ROM_DL_MODE

Found in: Security features

Available options:

- UART ROM download mode (Enabled (not recommended)) (CONFIG_SECURE_INSECURE_ALLOW_DL_MODE) This is a potentially insecure option. Enabling this option will allow the full UART download mode to stay enabled. This option SHOULD NOT BE ENABLED for production use cases.


## Application manager

- CONFIG_APP_EXCLUDE_PROJECT_NAME_VAR
- CONFIG_APP_EXCLUDE_PROJECT_VER_VAR
- CONFIG_APP_PROJECT_VER_FROM_CONFIG
- CONFIG_APP_RETRIEVE_LEN_ELF_SHA
- CONFIG_APP_COMPILE_TIME_DATE

CONFIG_APP_EXCLUDE_PROJECT_NAME_VAR

CONFIG_APP_EXCLUDE_PROJECT_VER_VAR

CONFIG_APP_PROJECT_VER_FROM_CONFIG

CONFIG_APP_RETRIEVE_LEN_ELF_SHA

CONFIG_APP_COMPILE_TIME_DATE


### CONFIG_APP_COMPILE_TIME_DATE

Found in: Application manager


### CONFIG_APP_EXCLUDE_PROJECT_VER_VAR

Found in: Application manager

- No (disabled)


### CONFIG_APP_EXCLUDE_PROJECT_NAME_VAR

Found in: Application manager

- No (disabled)


### CONFIG_APP_PROJECT_VER_FROM_CONFIG

Found in: Application manager

- No (disabled)


#### CONFIG_APP_PROJECT_VER

Found in: Application manager > CONFIG_APP_PROJECT_VER_FROM_CONFIG

- 1 if CONFIG_APP_PROJECT_VER_FROM_CONFIG

1 if CONFIG_APP_PROJECT_VER_FROM_CONFIG


### CONFIG_APP_RETRIEVE_LEN_ELF_SHA

Found in: Application manager

- from 8 to 64

- 9


## Boot ROM Behavior

- CONFIG_BOOT_ROM_LOG_SCHEME

CONFIG_BOOT_ROM_LOG_SCHEME


### CONFIG_BOOT_ROM_LOG_SCHEME

Found in: Boot ROM Behavior

Available options:

- Always Log (CONFIG_BOOT_ROM_LOG_ALWAYS_ON) Always print ROM logs, this is the default behavior.
- Permanently disable logging (CONFIG_BOOT_ROM_LOG_ALWAYS_OFF) Don't print ROM logs.
- Log on GPIO High (CONFIG_BOOT_ROM_LOG_ON_GPIO_HIGH) Print ROM logs when GPIO level is high during start up. The GPIO number is chip dependent, e.g. on ESP32-S2, the control GPIO is GPIO46.
- Log on GPIO Low (CONFIG_BOOT_ROM_LOG_ON_GPIO_LOW) Print ROM logs when GPIO level is low during start up. The GPIO number is chip dependent, e.g. on ESP32-S2, the control GPIO is GPIO46.

Always Log (CONFIG_BOOT_ROM_LOG_ALWAYS_ON)

Permanently disable logging (CONFIG_BOOT_ROM_LOG_ALWAYS_OFF)

Log on GPIO High (CONFIG_BOOT_ROM_LOG_ON_GPIO_HIGH)

Log on GPIO Low (CONFIG_BOOT_ROM_LOG_ON_GPIO_LOW)


## Serial flasher config

- CONFIG_ESPTOOLPY_AFTER
- CONFIG_ESPTOOLPY_BEFORE
- CONFIG_ESPTOOLPY_FLASH_MODE_AUTO_DETECT
- CONFIG_ESPTOOLPY_HEADER_FLASHSIZE_UPDATE
- CONFIG_ESPTOOLPY_NO_STUB
- CONFIG_ESPTOOLPY_OCT_FLASH
- CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE
- CONFIG_ESPTOOLPY_FLASHSIZE
- CONFIG_ESPTOOLPY_FLASHMODE
- CONFIG_ESPTOOLPY_FLASHFREQ

CONFIG_ESPTOOLPY_AFTER

CONFIG_ESPTOOLPY_BEFORE

CONFIG_ESPTOOLPY_FLASH_MODE_AUTO_DETECT

CONFIG_ESPTOOLPY_HEADER_FLASHSIZE_UPDATE

CONFIG_ESPTOOLPY_NO_STUB

CONFIG_ESPTOOLPY_OCT_FLASH

CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE

CONFIG_ESPTOOLPY_FLASHSIZE

CONFIG_ESPTOOLPY_FLASHMODE

CONFIG_ESPTOOLPY_FLASHFREQ


### CONFIG_ESPTOOLPY_NO_STUB

Found in: Serial flasher config


### CONFIG_ESPTOOLPY_OCT_FLASH

Found in: Serial flasher config


### CONFIG_ESPTOOLPY_FLASH_MODE_AUTO_DETECT

Found in: Serial flasher config

- If the flash chip is an Octal one, even if one of "QIO", "QOUT", "DIO", "DOUT" options is selected in ESPTOOLPY_FLASHMODE, our code will automatically change the mode to "OPI" and the sample mode will be STR.
- If the flash chip is a Quad one, even if "OPI" is selected in ESPTOOLPY_FLASHMODE, our code will automatically change the mode to "DIO".
- This option is mainly to improve the out-of-box experience of developers. It doesn't guarantee the feature-complete. Some code still rely on ESPTOOLPY_OCT_FLASH. Please do not rely on this option when you are pretty sure that you are using Octal flash. In this case, please enable ESPTOOLPY_OCT_FLASH option, then you can choose DTR sample mode in ESPTOOLPY_FLASH_SAMPLE_MODE. Otherwise, only STR mode is available.
- Enabling this feature reduces available internal RAM size (around 900 bytes). If your IRAM space is insufficient and you're aware of your flash type, disable this option and select corresponding flash type options.


### CONFIG_ESPTOOLPY_FLASHMODE

Found in: Serial flasher config

Available options:

- QIO (CONFIG_ESPTOOLPY_FLASHMODE_QIO)
- QOUT (CONFIG_ESPTOOLPY_FLASHMODE_QOUT)
- DIO (CONFIG_ESPTOOLPY_FLASHMODE_DIO)
- DOUT (CONFIG_ESPTOOLPY_FLASHMODE_DOUT)
- OPI (CONFIG_ESPTOOLPY_FLASHMODE_OPI)

QIO (CONFIG_ESPTOOLPY_FLASHMODE_QIO)

QOUT (CONFIG_ESPTOOLPY_FLASHMODE_QOUT)

DIO (CONFIG_ESPTOOLPY_FLASHMODE_DIO)

DOUT (CONFIG_ESPTOOLPY_FLASHMODE_DOUT)

OPI (CONFIG_ESPTOOLPY_FLASHMODE_OPI)


### CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE

Found in: Serial flasher config

Available options:

- STR Mode (CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_STR)
- DTR Mode (CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_DTR)

STR Mode (CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_STR)

DTR Mode (CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_DTR)


### CONFIG_ESPTOOLPY_FLASHFREQ

Found in: Serial flasher config

Available options:

- 120 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_120M)
- 80 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_80M)
- 40 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_40M)
- 20 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_20M)

120 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_120M)

80 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_80M)

40 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_40M)

20 MHz (CONFIG_ESPTOOLPY_FLASHFREQ_20M)


### CONFIG_ESPTOOLPY_FLASHSIZE

Found in: Serial flasher config

Available options:

- 1 MB (CONFIG_ESPTOOLPY_FLASHSIZE_1MB)
- 2 MB (CONFIG_ESPTOOLPY_FLASHSIZE_2MB)
- 4 MB (CONFIG_ESPTOOLPY_FLASHSIZE_4MB)
- 8 MB (CONFIG_ESPTOOLPY_FLASHSIZE_8MB)
- 16 MB (CONFIG_ESPTOOLPY_FLASHSIZE_16MB)
- 32 MB (CONFIG_ESPTOOLPY_FLASHSIZE_32MB)
- 64 MB (CONFIG_ESPTOOLPY_FLASHSIZE_64MB)
- 128 MB (CONFIG_ESPTOOLPY_FLASHSIZE_128MB)

1 MB (CONFIG_ESPTOOLPY_FLASHSIZE_1MB)

2 MB (CONFIG_ESPTOOLPY_FLASHSIZE_2MB)

4 MB (CONFIG_ESPTOOLPY_FLASHSIZE_4MB)

8 MB (CONFIG_ESPTOOLPY_FLASHSIZE_8MB)

16 MB (CONFIG_ESPTOOLPY_FLASHSIZE_16MB)

32 MB (CONFIG_ESPTOOLPY_FLASHSIZE_32MB)

64 MB (CONFIG_ESPTOOLPY_FLASHSIZE_64MB)

128 MB (CONFIG_ESPTOOLPY_FLASHSIZE_128MB)


### CONFIG_ESPTOOLPY_HEADER_FLASHSIZE_UPDATE

Found in: Serial flasher config


### CONFIG_ESPTOOLPY_BEFORE

Found in: Serial flasher config

Available options:

- Reset to bootloader (CONFIG_ESPTOOLPY_BEFORE_RESET)
- No reset (CONFIG_ESPTOOLPY_BEFORE_NORESET)

Reset to bootloader (CONFIG_ESPTOOLPY_BEFORE_RESET)

No reset (CONFIG_ESPTOOLPY_BEFORE_NORESET)


### CONFIG_ESPTOOLPY_AFTER

Found in: Serial flasher config

Available options:

- Reset after flashing (CONFIG_ESPTOOLPY_AFTER_RESET)
- Stay in bootloader (CONFIG_ESPTOOLPY_AFTER_NORESET)

Reset after flashing (CONFIG_ESPTOOLPY_AFTER_RESET)

Stay in bootloader (CONFIG_ESPTOOLPY_AFTER_NORESET)


## Partition Table

- CONFIG_PARTITION_TABLE_CUSTOM_FILENAME
- CONFIG_PARTITION_TABLE_MD5
- CONFIG_PARTITION_TABLE_OFFSET
- CONFIG_PARTITION_TABLE_TYPE

CONFIG_PARTITION_TABLE_CUSTOM_FILENAME

CONFIG_PARTITION_TABLE_MD5

CONFIG_PARTITION_TABLE_OFFSET

CONFIG_PARTITION_TABLE_TYPE


### CONFIG_PARTITION_TABLE_TYPE

Found in: Partition Table

Available options:

- Single factory app, no OTA (CONFIG_PARTITION_TABLE_SINGLE_APP) This is the default partition table, designed to fit into a 2MB or larger flash with a single 1MB app partition. The corresponding CSV file in the IDF directory is components/partition_table/partitions_singleapp.csv This partition table is not suitable for an app that needs OTA (over the air update) capability.
- Single factory app (large), no OTA (CONFIG_PARTITION_TABLE_SINGLE_APP_LARGE) This is a variation of the default partition table, that expands the 1MB app partition size to 1.5MB to fit more code. The corresponding CSV file in the IDF directory is components/partition_table/partitions_singleapp_large.csv This partition table is not suitable for an app that needs OTA (over the air update) capability.
- Factory app, two OTA definitions (CONFIG_PARTITION_TABLE_TWO_OTA) This is a basic OTA-enabled partition table with a factory app partition plus two OTA app partitions. All are 1MB, so this partition table requires 4MB or larger flash size. The corresponding CSV file in the IDF directory is components/partition_table/partitions_two_ota.csv
- Two large size OTA partitions (CONFIG_PARTITION_TABLE_TWO_OTA_LARGE) This is a basic OTA-enabled partition table with two OTA app partitions. Both app partition sizes are 1700K, so this partition table requires 4MB or larger flash size. The corresponding CSV file in the IDF directory is components/partition_table/partitions_two_ota_large.csv
- Custom partition table CSV (CONFIG_PARTITION_TABLE_CUSTOM) Specify the path to the partition table CSV to use for your project. Consult the Partition Table section in the ESP-IDF Programmers Guide for more information.
- Single factory app, no OTA, encrypted NVS (CONFIG_PARTITION_TABLE_SINGLE_APP_ENCRYPTED_NVS) This is a variation of the default "Single factory app, no OTA" partition table that supports encrypted NVS when using flash encryption. See the Flash Encryption section in the ESP-IDF Programmers Guide for more information. The corresponding CSV file in the IDF directory is components/partition_table/partitions_singleapp_encr_nvs.csv
- Single factory app (large), no OTA, encrypted NVS (CONFIG_PARTITION_TABLE_SINGLE_APP_LARGE_ENC_NVS) This is a variation of the "Single factory app (large), no OTA" partition table that supports encrypted NVS when using flash encryption. See the Flash Encryption section in the ESP-IDF Programmers Guide for more information. The corresponding CSV file in the IDF directory is components/partition_table/partitions_singleapp_large_encr_nvs.csv
- Factory app, two OTA definitions, encrypted NVS (CONFIG_PARTITION_TABLE_TWO_OTA_ENCRYPTED_NVS) This is a variation of the "Factory app, two OTA definitions" partition table that supports encrypted NVS when using flash encryption. See the Flash Encryption section in the ESP-IDF Programmers Guide for more information. The corresponding CSV file in the IDF directory is components/partition_table/partitions_two_ota_encr_nvs.csv
- Single factory app, no OTA, TEE (CONFIG_PARTITION_TABLE_SINGLE_APP_TEE) This is a variation of the default "Single factory app, no OTA" partition table that supports the ESP-TEE framework. See the Trusted Execution Environment (TEE) section in the ESP-IDF Programmers Guide for more information. The corresponding CSV file in the IDF directory is components/partition_table/partitions_singleapp_tee.csv
- Two OTA definitions, TEE (CONFIG_PARTITION_TABLE_TWO_OTA_TEE) This is a basic OTA-enabled partition table with two OTA app partitions each for the TEE and the user (REE) application. The user app partition sizes are 1536K, so this partition table requires 4MB or larger flash size. See the Trusted Execution Environment (TEE) section in the ESP-IDF Programmers Guide for more information. The corresponding CSV file in the IDF directory is components/partition_table/partitions_two_ota_tee.csv

Single factory app, no OTA (CONFIG_PARTITION_TABLE_SINGLE_APP)

Single factory app (large), no OTA (CONFIG_PARTITION_TABLE_SINGLE_APP_LARGE)

Factory app, two OTA definitions (CONFIG_PARTITION_TABLE_TWO_OTA)

Two large size OTA partitions (CONFIG_PARTITION_TABLE_TWO_OTA_LARGE)

Custom partition table CSV (CONFIG_PARTITION_TABLE_CUSTOM)

Single factory app, no OTA, encrypted NVS (CONFIG_PARTITION_TABLE_SINGLE_APP_ENCRYPTED_NVS)

Single factory app, no OTA, TEE (CONFIG_PARTITION_TABLE_SINGLE_APP_TEE)

Two OTA definitions, TEE (CONFIG_PARTITION_TABLE_TWO_OTA_TEE)


### CONFIG_PARTITION_TABLE_CUSTOM_FILENAME

Found in: Partition Table

- "partitions.csv"


### CONFIG_PARTITION_TABLE_OFFSET

Found in: Partition Table

- "0x8000"


### CONFIG_PARTITION_TABLE_MD5

Found in: Partition Table

- Yes (enabled)


## Compiler options

- CONFIG_COMPILER_OPTIMIZATION_ASSERTION_LEVEL
- CONFIG_COMPILER_FLOAT_LIB_FROM
- CONFIG_COMPILER_RT_LIB
- CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR
- CONFIG_COMPILER_DISABLE_DEFAULT_ERRORS
- CONFIG_COMPILER_NO_MERGE_CONSTANTS
- CONFIG_COMPILER_OPTIMIZATION_CHECKS_SILENT
- CONFIG_COMPILER_DISABLE_GCC12_WARNINGS
- CONFIG_COMPILER_DISABLE_GCC13_WARNINGS
- CONFIG_COMPILER_DISABLE_GCC14_WARNINGS
- CONFIG_COMPILER_DISABLE_GCC15_WARNINGS
- CONFIG_COMPILER_DUMP_RTL_FILES
- CONFIG_COMPILER_SAVE_RESTORE_LIBCALLS
- CONFIG_COMPILER_WARN_WRITE_STRINGS
- CONFIG_COMPILER_CXX_EXCEPTIONS
- CONFIG_COMPILER_CXX_RTTI
- CONFIG_COMPILER_STATIC_ANALYZER
- CONFIG_COMPILER_ASSERT_NDEBUG_EVALUATE
- CONFIG_COMPILER_OPTIMIZATION
- CONFIG_COMPILER_ORPHAN_SECTIONS
- CONFIG_COMPILER_HIDE_PATHS_MACROS
- CONFIG_COMPILER_STACK_CHECK_MODE

CONFIG_COMPILER_OPTIMIZATION_ASSERTION_LEVEL

CONFIG_COMPILER_FLOAT_LIB_FROM

CONFIG_COMPILER_RT_LIB

CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR

CONFIG_COMPILER_DISABLE_DEFAULT_ERRORS

CONFIG_COMPILER_NO_MERGE_CONSTANTS

CONFIG_COMPILER_OPTIMIZATION_CHECKS_SILENT

CONFIG_COMPILER_DISABLE_GCC12_WARNINGS

CONFIG_COMPILER_DISABLE_GCC13_WARNINGS

CONFIG_COMPILER_DISABLE_GCC14_WARNINGS

CONFIG_COMPILER_DISABLE_GCC15_WARNINGS

CONFIG_COMPILER_DUMP_RTL_FILES

CONFIG_COMPILER_SAVE_RESTORE_LIBCALLS

CONFIG_COMPILER_WARN_WRITE_STRINGS

CONFIG_COMPILER_CXX_EXCEPTIONS

CONFIG_COMPILER_CXX_RTTI

CONFIG_COMPILER_STATIC_ANALYZER

CONFIG_COMPILER_ASSERT_NDEBUG_EVALUATE

CONFIG_COMPILER_OPTIMIZATION

CONFIG_COMPILER_ORPHAN_SECTIONS

CONFIG_COMPILER_HIDE_PATHS_MACROS

CONFIG_COMPILER_STACK_CHECK_MODE


### CONFIG_COMPILER_OPTIMIZATION

Found in: Compiler options

- The "Debug" setting will add the -Og flag to CFLAGS.
- The "Size" setting will add the -Os flag to CFLAGS (-Oz with Clang).
- The "Performance" setting will add the -O2 flag to CFLAGS.
- The "None" setting will add the -O0 flag to CFLAGS.

Available options:

- Debug (-Og) (CONFIG_COMPILER_OPTIMIZATION_DEBUG)
- Optimize for size (-Os with GCC, -Oz with Clang) (CONFIG_COMPILER_OPTIMIZATION_SIZE)
- Optimize for performance (-O2) (CONFIG_COMPILER_OPTIMIZATION_PERF)
- Debug without optimization (-O0) (CONFIG_COMPILER_OPTIMIZATION_NONE)

Debug (-Og) (CONFIG_COMPILER_OPTIMIZATION_DEBUG)

Optimize for performance (-O2) (CONFIG_COMPILER_OPTIMIZATION_PERF)

Debug without optimization (-O0) (CONFIG_COMPILER_OPTIMIZATION_NONE)


### CONFIG_COMPILER_OPTIMIZATION_ASSERTION_LEVEL

Found in: Compiler options

- Enabled. Failure will print verbose assertion details. This is the default.
- Set to "silent" to save code size (failed assertions will abort() but user needs to use the aborting address to find the line number with the failed assertion.)
- Disabled entirely (not recommended for most configurations.) -DNDEBUG is added to CPPFLAGS in this case.

Available options:

- Enabled (CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_ENABLE) Enable assertions. Assertion content and line number will be printed on failure.
- Silent (saves code size) (CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_SILENT) Enable silent assertions. Failed assertions will abort(), user needs to use the aborting address to find the line number with the failed assertion.
- Disabled (sets -DNDEBUG) (CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_DISABLE) If assertions are disabled, -DNDEBUG is added to CPPFLAGS.

Enabled (CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_ENABLE)

Silent (saves code size) (CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_SILENT)

Disabled (sets -DNDEBUG) (CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_DISABLE)


### CONFIG_COMPILER_ASSERT_NDEBUG_EVALUATE

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_FLOAT_LIB_FROM

Found in: Compiler options

Available options:

- libgcc (CONFIG_COMPILER_FLOAT_LIB_FROM_GCCLIB)
- librvfp (CONFIG_COMPILER_FLOAT_LIB_FROM_RVFPLIB)

libgcc (CONFIG_COMPILER_FLOAT_LIB_FROM_GCCLIB)

librvfp (CONFIG_COMPILER_FLOAT_LIB_FROM_RVFPLIB)


### CONFIG_COMPILER_OPTIMIZATION_CHECKS_SILENT

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_HIDE_PATHS_MACROS

Found in: Compiler options

- Yes (enabled)


### CONFIG_COMPILER_CXX_EXCEPTIONS

Found in: Compiler options

- No (disabled)

- CONFIG_COMPILER_CXX_EXCEPTIONS_EMG_POOL_SIZE

CONFIG_COMPILER_CXX_EXCEPTIONS_EMG_POOL_SIZE


#### CONFIG_COMPILER_CXX_EXCEPTIONS_EMG_POOL_SIZE

Found in: Compiler options > CONFIG_COMPILER_CXX_EXCEPTIONS

- 0 if CONFIG_COMPILER_CXX_EXCEPTIONS

0 if CONFIG_COMPILER_CXX_EXCEPTIONS


### CONFIG_COMPILER_CXX_RTTI

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_STACK_CHECK_MODE

Found in: Compiler options

- In NORMAL mode (GCC flag: -fstack-protector) only functions that call alloca, and functions with buffers larger than 8 bytes are protected.
- STRONG mode (GCC flag: -fstack-protector-strong) is like NORMAL, but includes additional functions to be protected -- those that have local array definitions, or have references to local frame addresses.
- In OVERALL mode (GCC flag: -fstack-protector-all) all functions are protected.

- performance: NORMAL > STRONG > OVERALL
- coverage: NORMAL < STRONG < OVERALL

Available options:

- None (CONFIG_COMPILER_STACK_CHECK_MODE_NONE)
- Normal (CONFIG_COMPILER_STACK_CHECK_MODE_NORM)
- Strong (CONFIG_COMPILER_STACK_CHECK_MODE_STRONG)
- Overall (CONFIG_COMPILER_STACK_CHECK_MODE_ALL)

None (CONFIG_COMPILER_STACK_CHECK_MODE_NONE)

Normal (CONFIG_COMPILER_STACK_CHECK_MODE_NORM)

Strong (CONFIG_COMPILER_STACK_CHECK_MODE_STRONG)

Overall (CONFIG_COMPILER_STACK_CHECK_MODE_ALL)


### CONFIG_COMPILER_NO_MERGE_CONSTANTS

Found in: Compiler options


### CONFIG_COMPILER_WARN_WRITE_STRINGS

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_SAVE_RESTORE_LIBCALLS

Found in: Compiler options


### CONFIG_COMPILER_DISABLE_DEFAULT_ERRORS

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_DISABLE_GCC12_WARNINGS

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_DISABLE_GCC13_WARNINGS

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_DISABLE_GCC14_WARNINGS

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_DISABLE_GCC15_WARNINGS

Found in: Compiler options

- No (disabled)


### CONFIG_COMPILER_DUMP_RTL_FILES

Found in: Compiler options


### CONFIG_COMPILER_RT_LIB

Found in: Compiler options

Available options:

- libgcc (CONFIG_COMPILER_RT_LIB_GCCLIB)
- libclang_rt (CONFIG_COMPILER_RT_LIB_CLANGRT)
- Host (CONFIG_COMPILER_RT_LIB_HOST)

libgcc (CONFIG_COMPILER_RT_LIB_GCCLIB)

libclang_rt (CONFIG_COMPILER_RT_LIB_CLANGRT)

Host (CONFIG_COMPILER_RT_LIB_HOST)


### CONFIG_COMPILER_ORPHAN_SECTIONS

Found in: Compiler options

Available options:

- Fail if orphan sections found (CONFIG_COMPILER_ORPHAN_SECTIONS_ERROR) Fails the link step with an error if orphan sections are detected.
- Place with warning (CONFIG_COMPILER_ORPHAN_SECTIONS_WARNING) Places orphan sections with a warning message.
- Place silently (CONFIG_COMPILER_ORPHAN_SECTIONS_PLACE) Places orphan sections without a warning/error message.

Fail if orphan sections found (CONFIG_COMPILER_ORPHAN_SECTIONS_ERROR)

Place with warning (CONFIG_COMPILER_ORPHAN_SECTIONS_WARNING)

Place silently (CONFIG_COMPILER_ORPHAN_SECTIONS_PLACE)


### CONFIG_COMPILER_STATIC_ANALYZER

Found in: Compiler options


### CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR

Found in: Compiler options

Available options:

- No change (CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR_NO_CHANGE) Use default _GLIBCXX20_CONSTEXPR and _GLIBCXX23_CONSTEXPR defined in libstdc++
- _GLIBCXX2X_CONSTEXPR=__attribute__((cold)) constexpr (CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR_COLD_CONSTEXPR) Define _GLIBCXX20_CONSTEXPR=__attribute__((cold)) constexpr Define _GLIBCXX23_CONSTEXPR=__attribute__((cold)) constexpr
- _GLIBCXX2X_CONSTEXPR=__attribute__((cold)) (CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR_COLD) Define _GLIBCXX20_CONSTEXPR=__attribute__((cold)). Define _GLIBCXX23_CONSTEXPR=__attribute__((cold)).

No change (CONFIG_COMPILER_CXX_GLIBCXX_CONSTEXPR_NO_CHANGE)


## Component config

CONFIG_BLE_MESH


### Bluetooth

- Bluedroid Options
- CONFIG_BT_ENABLED
- Common Options
- Controller Options
- CONFIG_BT_HCI_LOG_DEBUG_EN
- NimBLE Options
- CONFIG_BT_RELEASE_IRAM

CONFIG_BT_ENABLED

CONFIG_BT_HCI_LOG_DEBUG_EN

CONFIG_BT_RELEASE_IRAM


#### CONFIG_BT_ENABLED

Found in: Component config > Bluetooth


##### CONFIG_BT_HOST

Found in: Component config > Bluetooth > CONFIG_BT_ENABLED

Available options:

- Bluedroid - Dual-mode (CONFIG_BT_BLUEDROID_ENABLED) This option is recommended for classic Bluetooth or for dual-mode usecases
- NimBLE - BLE only (CONFIG_BT_NIMBLE_ENABLED) This option is recommended for BLE only usecases to save on memory
- Disabled (CONFIG_BT_CONTROLLER_ONLY) This option is recommended when you want to communicate directly with the controller (without any host) or when you are using any other host stack not supported by Espressif (not mentioned here).

Bluedroid - Dual-mode (CONFIG_BT_BLUEDROID_ENABLED)

NimBLE - BLE only (CONFIG_BT_NIMBLE_ENABLED)

Disabled (CONFIG_BT_CONTROLLER_ONLY)


##### CONFIG_BT_CONTROLLER

Found in: Component config > Bluetooth > CONFIG_BT_ENABLED

Available options:

- Enabled (CONFIG_BT_CONTROLLER_ENABLED) This option is recommended for Bluetooth controller usecases
- Disabled (CONFIG_BT_CONTROLLER_DISABLED) This option is recommended for Bluetooth Host only usecases

Enabled (CONFIG_BT_CONTROLLER_ENABLED)

Disabled (CONFIG_BT_CONTROLLER_DISABLED)


#### Bluedroid Options

- CONFIG_BT_ABORT_WHEN_ALLOCATION_FAILS
- CONFIG_BT_BLUEDROID_MEM_DEBUG
- CONFIG_BT_BTU_TASK_STACK_SIZE
- CONFIG_BT_BTC_TASK_STACK_SIZE
- CONFIG_BT_BLE_ENABLED
- BT DEBUG LOG LEVEL
- CONFIG_BT_ACL_CONNECTIONS
- CONFIG_BT_SMP_MAX_BONDS
- CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST
- CONFIG_BT_CLASSIC_ENABLED
- CONFIG_BT_STACK_NO_LOG
- CONFIG_BT_BLE_42_FEATURES_SUPPORTED
- CONFIG_BT_BLE_50_FEATURES_SUPPORTED
- CONFIG_BT_BLE_FEAT_ISO_EN
- CONFIG_BT_BLE_FEAT_CONN_SUBRATING
- CONFIG_BT_BLE_FEAT_CTE_EN
- CONFIG_BT_BLE_HIGH_DUTY_ADV_INTERVAL
- CONFIG_BT_MULTI_CONNECTION_ENBALE
- CONFIG_BT_BLE_FEAT_PERIODIC_ADV_SYNC_TRANSFER
- CONFIG_BT_BLE_FEAT_POWER_CONTROL
- CONFIG_BT_BLE_VENDOR_HCI_EN
- CONFIG_BT_BLE_FEAT_CREATE_SYNC_ENH
- CONFIG_BT_BLUEDROID_ESP_COEX_VSC
- CONFIG_BT_BLE_FEAT_PERIODIC_ADV_ENH
- CONFIG_BT_MAX_DEVICE_NAME_LEN
- CONFIG_BT_BLE_ACT_SCAN_REP_ADV_SCAN
- CONFIG_BT_BLUEDROID_PINNED_TO_CORE_CHOICE
- CONFIG_BT_BLE_RPA_TIMEOUT
- CONFIG_BT_BLE_DYNAMIC_ENV_MEMORY

CONFIG_BT_ABORT_WHEN_ALLOCATION_FAILS

CONFIG_BT_BLUEDROID_MEM_DEBUG

CONFIG_BT_BTU_TASK_STACK_SIZE

CONFIG_BT_BTC_TASK_STACK_SIZE

CONFIG_BT_BLE_ENABLED

CONFIG_BT_ACL_CONNECTIONS

CONFIG_BT_SMP_MAX_BONDS

CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST

CONFIG_BT_CLASSIC_ENABLED

CONFIG_BT_STACK_NO_LOG

CONFIG_BT_BLE_42_FEATURES_SUPPORTED

CONFIG_BT_BLE_50_FEATURES_SUPPORTED

CONFIG_BT_BLE_FEAT_ISO_EN

CONFIG_BT_BLE_FEAT_CONN_SUBRATING

CONFIG_BT_BLE_FEAT_CTE_EN

CONFIG_BT_BLE_HIGH_DUTY_ADV_INTERVAL

CONFIG_BT_MULTI_CONNECTION_ENBALE

CONFIG_BT_BLE_FEAT_PERIODIC_ADV_SYNC_TRANSFER

CONFIG_BT_BLE_FEAT_POWER_CONTROL

CONFIG_BT_BLE_VENDOR_HCI_EN

CONFIG_BT_BLE_FEAT_CREATE_SYNC_ENH

CONFIG_BT_BLUEDROID_ESP_COEX_VSC

CONFIG_BT_BLE_FEAT_PERIODIC_ADV_ENH

CONFIG_BT_MAX_DEVICE_NAME_LEN

CONFIG_BT_BLE_ACT_SCAN_REP_ADV_SCAN

CONFIG_BT_BLUEDROID_PINNED_TO_CORE_CHOICE

CONFIG_BT_BLE_RPA_TIMEOUT

CONFIG_BT_BLE_DYNAMIC_ENV_MEMORY


##### CONFIG_BT_BTC_TASK_STACK_SIZE

Found in: Component config > Bluetooth > Bluedroid Options

- 3072 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

3072 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLUEDROID_PINNED_TO_CORE_CHOICE

Found in: Component config > Bluetooth > Bluedroid Options

Available options:

- Core 0 (PRO CPU) (CONFIG_BT_BLUEDROID_PINNED_TO_CORE_0)
- Core 1 (APP CPU) (CONFIG_BT_BLUEDROID_PINNED_TO_CORE_1)

Core 0 (PRO CPU) (CONFIG_BT_BLUEDROID_PINNED_TO_CORE_0)

Core 1 (APP CPU) (CONFIG_BT_BLUEDROID_PINNED_TO_CORE_1)


##### CONFIG_BT_BTU_TASK_STACK_SIZE

Found in: Component config > Bluetooth > Bluedroid Options

- 4352 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

4352 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLUEDROID_MEM_DEBUG

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLUEDROID_ESP_COEX_VSC

Found in: Component config > Bluetooth > Bluedroid Options

- Yes (enabled) if (CONFIG_ESP_COEX_SW_COEXIST_ENABLE || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED
- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if (CONFIG_ESP_COEX_SW_COEXIST_ENABLE || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_CLASSIC_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BT_CLASSIC_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BT_CLASSIC_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_ENC_KEY_SIZE_CTRL_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

Available options:

- Supported by standard HCI command (CONFIG_BT_ENC_KEY_SIZE_CTRL_STD)
- Supported by Vendor-specific HCI command (CONFIG_BT_ENC_KEY_SIZE_CTRL_VSC)
- Not supported (CONFIG_BT_ENC_KEY_SIZE_CTRL_NONE)

Supported by standard HCI command (CONFIG_BT_ENC_KEY_SIZE_CTRL_STD)

Supported by Vendor-specific HCI command (CONFIG_BT_ENC_KEY_SIZE_CTRL_VSC)

Not supported (CONFIG_BT_ENC_KEY_SIZE_CTRL_NONE)


##### CONFIG_BT_CLASSIC_BQB_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_A2DP_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_A2DP_USE_EXTERNAL_CODEC

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_A2DP_ENABLE

- No (disabled) if CONFIG_BT_A2DP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_A2DP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### AVRCP Features

- CONFIG_BT_AVRCP_CT_COVER_ART_ENABLED

CONFIG_BT_AVRCP_CT_COVER_ART_ENABLED


##### CONFIG_BT_AVRCP_CT_COVER_ART_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_A2DP_ENABLE > AVRCP Features


##### CONFIG_BT_SPP_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_L2CAP_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_SDP_COMMON_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- Yes (enabled) if CONFIG_BT_L2CAP_ENABLED && CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED
- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_L2CAP_ENABLED && CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_SDP_PAD_LEN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- from to 1024 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from to 1024 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 300 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

300 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_SDP_ATTR_LEN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- from 300 to 1024 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from 300 to 1024 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 300 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

300 if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_HFP_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_HFP_AG_ENABLE
- CONFIG_BT_HFP_AUDIO_DATA_PATH
- CONFIG_BT_HFP_CLIENT_ENABLE
- CONFIG_BT_HFP_USE_EXTERNAL_CODEC
- CONFIG_BT_HFP_WBS_ENABLE

CONFIG_BT_HFP_AG_ENABLE

CONFIG_BT_HFP_AUDIO_DATA_PATH

CONFIG_BT_HFP_CLIENT_ENABLE

CONFIG_BT_HFP_USE_EXTERNAL_CODEC

CONFIG_BT_HFP_WBS_ENABLE


##### CONFIG_BT_HFP_CLIENT_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HFP_ENABLE

- Yes (enabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_HFP_AG_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HFP_ENABLE

- Yes (enabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_HFP_AUDIO_DATA_PATH

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HFP_ENABLE

Available options:

- PCM (CONFIG_BT_HFP_AUDIO_DATA_PATH_PCM)
- HCI (CONFIG_BT_HFP_AUDIO_DATA_PATH_HCI)

PCM (CONFIG_BT_HFP_AUDIO_DATA_PATH_PCM)

HCI (CONFIG_BT_HFP_AUDIO_DATA_PATH_HCI)


##### CONFIG_BT_HFP_USE_EXTERNAL_CODEC

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HFP_ENABLE

- No (disabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_HFP_AUDIO_DATA_PATH_HCI && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_HFP_AUDIO_DATA_PATH_HCI && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_HFP_WBS_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HFP_ENABLE

- Yes (enabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_HFP_AUDIO_DATA_PATH_HCI && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_HFP_ENABLE && CONFIG_BT_HFP_AUDIO_DATA_PATH_HCI && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_HID_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_HID_DEVICE_ENABLED
- CONFIG_BT_HID_HOST_ENABLED
- CONFIG_BT_HID_REMOVE_DEVICE_BONDING_ENABLED

CONFIG_BT_HID_DEVICE_ENABLED

CONFIG_BT_HID_HOST_ENABLED

CONFIG_BT_HID_REMOVE_DEVICE_BONDING_ENABLED


##### CONFIG_BT_HID_HOST_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HID_ENABLED

- No (disabled) if CONFIG_BT_HID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_HID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_HID_DEVICE_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HID_ENABLED


##### CONFIG_BT_HID_REMOVE_DEVICE_BONDING_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_HID_ENABLED

- Yes (enabled) if CONFIG_BT_HID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_HID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_PBAC_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED

- No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_CLASSIC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_PBAC_PREFERRED_MTU
- CONFIG_BT_PBAC_SUPPORTED_FEAT

CONFIG_BT_PBAC_PREFERRED_MTU

CONFIG_BT_PBAC_SUPPORTED_FEAT


##### CONFIG_BT_PBAC_SUPPORTED_FEAT

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_PBAC_ENABLED

- "0x000003FF" if CONFIG_BT_PBAC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

"0x000003FF" if CONFIG_BT_PBAC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_PBAC_PREFERRED_MTU

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_CLASSIC_ENABLED > CONFIG_BT_PBAC_ENABLED

- 0 if CONFIG_BT_PBAC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

0 if CONFIG_BT_PBAC_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options

- Yes (enabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTS_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED

- Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_GATTS_APPEARANCE_WRITABLE
- CONFIG_BT_GATTS_DEVICE_NAME_WRITABLE
- CONFIG_BT_GATTS_PPCP_CHAR_GAP
- CONFIG_BT_GATTS_ROBUST_CACHING_ENABLED
- CONFIG_BT_GATTS_SEND_SERVICE_CHANGE_MODE
- CONFIG_BT_BLE_BLUFI_ENABLE
- CONFIG_BT_GATT_MAX_SR_PROFILES
- CONFIG_BT_GATT_MAX_SR_ATTRIBUTES

CONFIG_BT_GATTS_APPEARANCE_WRITABLE

CONFIG_BT_GATTS_DEVICE_NAME_WRITABLE

CONFIG_BT_GATTS_PPCP_CHAR_GAP

CONFIG_BT_GATTS_ROBUST_CACHING_ENABLED

CONFIG_BT_GATTS_SEND_SERVICE_CHANGE_MODE

CONFIG_BT_BLE_BLUFI_ENABLE

CONFIG_BT_GATT_MAX_SR_PROFILES

CONFIG_BT_GATT_MAX_SR_ATTRIBUTES


##### CONFIG_BT_GATTS_PPCP_CHAR_GAP

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_BLUFI_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATT_MAX_SR_PROFILES

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- from 1 to 32 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 32 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 8 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

8 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATT_MAX_SR_ATTRIBUTES

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- from 1 to 500 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 500 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 100 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

100 if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTS_SEND_SERVICE_CHANGE_MODE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

Available options:

- GATTS manually send service change indication (CONFIG_BT_GATTS_SEND_SERVICE_CHANGE_MANUAL) Manually send service change indication through API esp_ble_gatts_send_service_change_indication()
- GATTS automatically send service change indication (CONFIG_BT_GATTS_SEND_SERVICE_CHANGE_AUTO) Let Bluedroid handle the service change indication internally


##### CONFIG_BT_GATTS_ROBUST_CACHING_ENABLED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTS_DEVICE_NAME_WRITABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTS_APPEARANCE_WRITABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTS_ENABLE

- No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTS_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTC_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED

- Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_GATTC_MAX_CACHE_CHAR
- CONFIG_BT_GATTC_NOTIF_REG_MAX
- CONFIG_BT_GATTC_CACHE_NVS_FLASH
- CONFIG_BT_GATTC_CONNECT_RETRY_COUNT
- CONFIG_BT_BLE_ESTAB_LINK_CONN_TOUT

CONFIG_BT_GATTC_MAX_CACHE_CHAR

CONFIG_BT_GATTC_NOTIF_REG_MAX

CONFIG_BT_GATTC_CACHE_NVS_FLASH

CONFIG_BT_GATTC_CONNECT_RETRY_COUNT

CONFIG_BT_BLE_ESTAB_LINK_CONN_TOUT


##### CONFIG_BT_GATTC_MAX_CACHE_CHAR

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- from 1 to 500 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 500 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

- 40 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

40 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTC_NOTIF_REG_MAX

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- from 1 to 64 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 64 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

- 5 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

5 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTC_CACHE_NVS_FLASH

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- No (disabled) if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_GATTC_CONNECT_RETRY_COUNT

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- from 0 to 255 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

from 0 to 255 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

- 3 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

3 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_ESTAB_LINK_CONN_TOUT

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_GATTC_ENABLE

- from 1 to 60 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 60 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

- 30 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

30 if CONFIG_BT_GATTC_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_SMP_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED

- Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_BLE_SMP_ID_RESET_ENABLE
- CONFIG_BT_BLE_SMP_BOND_NVS_FLASH
- CONFIG_BT_SMP_SLAVE_CON_PARAMS_UPD_ENABLE
- CONFIG_BT_BLE_RPA_SUPPORTED

CONFIG_BT_BLE_SMP_ID_RESET_ENABLE

CONFIG_BT_BLE_SMP_BOND_NVS_FLASH

CONFIG_BT_SMP_SLAVE_CON_PARAMS_UPD_ENABLE

CONFIG_BT_BLE_RPA_SUPPORTED


##### CONFIG_BT_SMP_SLAVE_CON_PARAMS_UPD_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_BLE_SMP_ENABLE

- No (disabled) if CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_SMP_ID_RESET_ENABLE

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_BLE_SMP_ENABLE

- No (disabled) if CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_SMP_BOND_NVS_FLASH

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_BLE_SMP_ENABLE

- Yes (enabled) if CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_RPA_SUPPORTED

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_ENABLED > CONFIG_BT_BLE_SMP_ENABLE

- Yes (enabled) if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_BLE_SMP_ENABLE && CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_STACK_NO_LOG

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### BT DEBUG LOG LEVEL

- CONFIG_BT_LOG_A2D_TRACE_LEVEL
- CONFIG_BT_LOG_APPL_TRACE_LEVEL
- CONFIG_BT_LOG_AVCT_TRACE_LEVEL
- CONFIG_BT_LOG_AVDT_TRACE_LEVEL
- CONFIG_BT_LOG_AVRC_TRACE_LEVEL
- CONFIG_BT_LOG_BLUFI_TRACE_LEVEL
- CONFIG_BT_LOG_BNEP_TRACE_LEVEL
- CONFIG_BT_LOG_BTC_TRACE_LEVEL
- CONFIG_BT_LOG_BTIF_TRACE_LEVEL
- CONFIG_BT_LOG_BTM_TRACE_LEVEL
- CONFIG_BT_LOG_GAP_TRACE_LEVEL
- CONFIG_BT_LOG_GATT_TRACE_LEVEL
- CONFIG_BT_LOG_HCI_TRACE_LEVEL
- CONFIG_BT_LOG_HID_TRACE_LEVEL
- CONFIG_BT_LOG_L2CAP_TRACE_LEVEL
- CONFIG_BT_LOG_MCA_TRACE_LEVEL
- CONFIG_BT_LOG_OSI_TRACE_LEVEL
- CONFIG_BT_LOG_PAN_TRACE_LEVEL
- CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL
- CONFIG_BT_LOG_SDP_TRACE_LEVEL
- CONFIG_BT_LOG_SMP_TRACE_LEVEL

CONFIG_BT_LOG_A2D_TRACE_LEVEL

CONFIG_BT_LOG_APPL_TRACE_LEVEL

CONFIG_BT_LOG_AVCT_TRACE_LEVEL

CONFIG_BT_LOG_AVDT_TRACE_LEVEL

CONFIG_BT_LOG_AVRC_TRACE_LEVEL

CONFIG_BT_LOG_BLUFI_TRACE_LEVEL

CONFIG_BT_LOG_BNEP_TRACE_LEVEL

CONFIG_BT_LOG_BTC_TRACE_LEVEL

CONFIG_BT_LOG_BTIF_TRACE_LEVEL

CONFIG_BT_LOG_BTM_TRACE_LEVEL

CONFIG_BT_LOG_GAP_TRACE_LEVEL

CONFIG_BT_LOG_GATT_TRACE_LEVEL

CONFIG_BT_LOG_HCI_TRACE_LEVEL

CONFIG_BT_LOG_HID_TRACE_LEVEL

CONFIG_BT_LOG_L2CAP_TRACE_LEVEL

CONFIG_BT_LOG_MCA_TRACE_LEVEL

CONFIG_BT_LOG_OSI_TRACE_LEVEL

CONFIG_BT_LOG_PAN_TRACE_LEVEL

CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL

CONFIG_BT_LOG_SDP_TRACE_LEVEL

CONFIG_BT_LOG_SMP_TRACE_LEVEL


##### CONFIG_BT_LOG_HCI_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_HCI_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_HCI_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_HCI_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_HCI_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_HCI_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_HCI_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_HCI_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_HCI_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_HCI_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_HCI_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_HCI_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_HCI_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_HCI_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_HCI_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_BTM_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_BTM_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_BTM_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_BTM_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_BTM_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_BTM_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_BTM_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_BTM_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_BTM_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_BTM_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_BTM_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_BTM_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_BTM_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_BTM_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_BTM_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_L2CAP_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_L2CAP_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_RFCOMM_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_SDP_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_SDP_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_SDP_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_SDP_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_SDP_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_SDP_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_SDP_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_SDP_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_SDP_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_SDP_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_SDP_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_SDP_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_SDP_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_SDP_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_SDP_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_GAP_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_GAP_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_GAP_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_GAP_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_GAP_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_GAP_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_GAP_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_GAP_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_GAP_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_GAP_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_GAP_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_GAP_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_GAP_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_GAP_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_GAP_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_BNEP_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_BNEP_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_PAN_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_PAN_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_PAN_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_PAN_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_PAN_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_PAN_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_PAN_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_PAN_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_PAN_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_PAN_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_PAN_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_PAN_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_PAN_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_PAN_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_PAN_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_A2D_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_A2D_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_A2D_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_A2D_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_A2D_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_A2D_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_A2D_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_A2D_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_A2D_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_A2D_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_A2D_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_A2D_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_A2D_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_A2D_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_A2D_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_AVDT_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_AVDT_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_AVCT_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_AVCT_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_AVRC_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_AVRC_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_MCA_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_MCA_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_MCA_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_MCA_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_MCA_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_MCA_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_MCA_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_MCA_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_MCA_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_MCA_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_MCA_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_MCA_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_MCA_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_MCA_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_MCA_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_HID_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_HID_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_HID_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_HID_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_HID_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_HID_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_HID_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_HID_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_HID_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_HID_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_HID_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_HID_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_HID_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_HID_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_HID_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_APPL_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_APPL_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_APPL_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_APPL_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_APPL_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_APPL_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_APPL_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_APPL_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_APPL_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_APPL_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_APPL_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_APPL_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_APPL_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_APPL_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_APPL_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_GATT_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_GATT_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_GATT_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_GATT_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_GATT_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_GATT_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_GATT_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_GATT_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_GATT_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_GATT_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_GATT_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_GATT_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_GATT_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_GATT_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_GATT_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_SMP_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_SMP_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_SMP_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_SMP_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_SMP_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_SMP_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_SMP_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_SMP_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_SMP_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_SMP_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_SMP_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_SMP_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_SMP_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_SMP_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_SMP_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_BTIF_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_BTIF_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_BTC_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_BTC_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_BTC_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_BTC_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_BTC_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_BTC_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_BTC_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_BTC_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_BTC_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_BTC_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_BTC_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_BTC_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_BTC_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_BTC_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_BTC_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_OSI_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_OSI_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_OSI_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_OSI_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_OSI_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_OSI_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_OSI_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_OSI_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_OSI_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_OSI_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_OSI_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_OSI_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_OSI_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_OSI_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_OSI_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_LOG_BLUFI_TRACE_LEVEL

Found in: Component config > Bluetooth > Bluedroid Options > BT DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_WARNING)
- API (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_API)
- EVENT (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_EVENT)
- DEBUG (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_NONE)

ERROR (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_WARNING)

API (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_API)

EVENT (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_EVENT)

DEBUG (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BT_LOG_BLUFI_TRACE_LEVEL_VERBOSE)


##### CONFIG_BT_ACL_CONNECTIONS

Found in: Component config > Bluetooth > Bluedroid Options

- from 1 to 50 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 50 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 4 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

4 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_MULTI_CONNECTION_ENBALE

Found in: Component config > Bluetooth > Bluedroid Options

- Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_DYNAMIC_ENV_MEMORY

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_SMP_MAX_BONDS

Found in: Component config > Bluetooth > Bluedroid Options


##### CONFIG_BT_BLE_ACT_SCAN_REP_ADV_SCAN

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_MAX_DEVICE_NAME_LEN

Found in: Component config > Bluetooth > Bluedroid Options

- from 32 to 248 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from 32 to 248 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 32 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

32 if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_RPA_TIMEOUT

Found in: Component config > Bluetooth > Bluedroid Options

- from 1 to 3600 if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 3600 if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- 900 if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

900 if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_50_FEATURES_SUPPORTED

Found in: Component config > Bluetooth > Bluedroid Options

- Yes (enabled) if CONFIG_BT_BLE_ENABLED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_50_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_ENABLED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_50_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_BLE_50_DTM_TEST_EN
- CONFIG_BT_BLE_50_EXTEND_ADV_EN
- CONFIG_BT_BLE_50_EXTEND_SCAN_EN

CONFIG_BT_BLE_50_DTM_TEST_EN

CONFIG_BT_BLE_50_EXTEND_ADV_EN

CONFIG_BT_BLE_50_EXTEND_SCAN_EN


##### CONFIG_BT_BLE_50_EXTEND_ADV_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_50_FEATURES_SUPPORTED

- Yes (enabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_50_PERIODIC_ADV_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_50_FEATURES_SUPPORTED > CONFIG_BT_BLE_50_EXTEND_ADV_EN

- Yes (enabled) if CONFIG_BT_BLE_50_EXTEND_ADV_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_50_EXTEND_ADV_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_50_EXTEND_SCAN_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_50_FEATURES_SUPPORTED

- Yes (enabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_50_EXTEND_SYNC_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_50_FEATURES_SUPPORTED > CONFIG_BT_BLE_50_EXTEND_SCAN_EN

- Yes (enabled) if CONFIG_BT_BLE_50_EXTEND_SCAN_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_50_EXTEND_SCAN_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_50_DTM_TEST_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_50_FEATURES_SUPPORTED

- Yes (enabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_PERIODIC_ADV_SYNC_TRANSFER

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_50_PERIODIC_ADV_EN && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_50_PERIODIC_ADV_EN && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_PERIODIC_ADV_ENH

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_50_PERIODIC_ADV_EN && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_50_PERIODIC_ADV_EN && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_CREATE_SYNC_ENH

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_50_EXTEND_SYNC_EN && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLE_50_EXTEND_SYNC_EN && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_42_FEATURES_SUPPORTED

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_BLE_42_ADV_EN
- CONFIG_BT_BLE_42_DTM_TEST_EN
- CONFIG_BT_BLE_42_SCAN_EN

CONFIG_BT_BLE_42_ADV_EN

CONFIG_BT_BLE_42_DTM_TEST_EN

CONFIG_BT_BLE_42_SCAN_EN


##### CONFIG_BT_BLE_42_DTM_TEST_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_42_FEATURES_SUPPORTED

- Yes (enabled) if CONFIG_BT_BLE_42_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_42_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_42_ADV_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_42_FEATURES_SUPPORTED

- Yes (enabled) if CONFIG_BT_BLE_42_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_42_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_42_SCAN_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_42_FEATURES_SUPPORTED

- Yes (enabled) if CONFIG_BT_BLE_42_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_42_FEATURES_SUPPORTED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_ISO_EN

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_AUDIO_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_AUDIO_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER
- CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER
- CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL
- CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL
- CONFIG_BT_BLE_FEAT_ISO_60_EN
- CONFIG_BT_BLE_ISO_BIS_MAX_COUNT
- CONFIG_BT_BLE_ISO_CIS_MAX_COUNT
- CONFIG_BT_BLE_ISO_FLOW_CONTROL

CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER

CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER

CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL

CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL

CONFIG_BT_BLE_FEAT_ISO_60_EN

CONFIG_BT_BLE_ISO_BIS_MAX_COUNT

CONFIG_BT_BLE_ISO_CIS_MAX_COUNT

CONFIG_BT_BLE_ISO_FLOW_CONTROL


##### CONFIG_BT_BLE_FEAT_ISO_60_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- No (disabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_ISO_BIS_MAX_COUNT

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- from 1 to 31 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER || CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER) && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 31 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER || CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER) && CONFIG_BT_BLUEDROID_ENABLED

- 2 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER || CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER) && CONFIG_BT_BLUEDROID_ENABLED

2 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_BIG_BROCASTER || CONFIG_BT_BLE_FEAT_ISO_BIG_SYNCER) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_ISO_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_ISO_CIS_MAX_COUNT

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

- from 1 to 31 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL || CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL) && CONFIG_BT_BLUEDROID_ENABLED

from 1 to 31 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL || CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL) && CONFIG_BT_BLUEDROID_ENABLED

- 2 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL || CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL) && CONFIG_BT_BLUEDROID_ENABLED

2 if CONFIG_BT_BLE_FEAT_ISO_EN && (CONFIG_BT_BLE_FEAT_ISO_CIG_CENTRAL || CONFIG_BT_BLE_FEAT_ISO_CIG_PERIPHERAL) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_ISO_FLOW_CONTROL

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_ISO_EN

Available options:

- ISO standard flow control (CONFIG_BT_BLE_ISO_STD_FLOW_CTRL) Enable ISO standard flow control
- ISO non-standard flow control (CONFIG_BT_BLE_ISO_NON_STD_FLOW_CTRL) Enable ISO non-standard flow control

ISO standard flow control (CONFIG_BT_BLE_ISO_STD_FLOW_CTRL)

ISO non-standard flow control (CONFIG_BT_BLE_ISO_NON_STD_FLOW_CTRL)


##### CONFIG_BT_BLE_FEAT_CTE_EN

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_CTE_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_CTE_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

- CONFIG_BT_BLE_FEAT_CTE_CONNECTION_EN
- CONFIG_BT_BLE_FEAT_CTE_CONNECTIONLESS_EN

CONFIG_BT_BLE_FEAT_CTE_CONNECTION_EN

CONFIG_BT_BLE_FEAT_CTE_CONNECTIONLESS_EN


##### CONFIG_BT_BLE_FEAT_CTE_CONNECTIONLESS_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_CTE_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_CTE_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_CTE_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_CTE_CONNECTION_EN

Found in: Component config > Bluetooth > Bluedroid Options > CONFIG_BT_BLE_FEAT_CTE_EN

- Yes (enabled) if CONFIG_BT_BLE_FEAT_CTE_EN && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_FEAT_CTE_EN && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_POWER_CONTROL

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_POWER_CONTROL_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_POWER_CONTROL_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_FEAT_CONN_SUBRATING

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_SUBRATE_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_50_FEATURES_SUPPORTED && ((CONFIG_BT_CONTROLLER_ENABLED && SOC_BLE_SUBRATE_SUPPORTED) || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_VENDOR_HCI_EN

Found in: Component config > Bluetooth > Bluedroid Options

- Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

Yes (enabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_BLE_HIGH_DUTY_ADV_INTERVAL

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLE_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


##### CONFIG_BT_ABORT_WHEN_ALLOCATION_FAILS

Found in: Component config > Bluetooth > Bluedroid Options

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BT_BLUEDROID_ENABLED


#### NimBLE Options

- BLE 5.x Features
- BLE 6.x Features
- Debugging/Testing
- Extra Features
- GAP / GATT / Device Settings
- General
- Host-controller Transport
- L2CAP
- Memory Settings
- NimBLE Mesh
- Roles and Profiles
- Security (SMP)
- Services
- Vendor / Optimization


##### General

- CONFIG_BT_NIMBLE_MEM_ALLOC_MODE
- CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE
- CONFIG_BT_NIMBLE_PINNED_TO_CORE_CHOICE

CONFIG_BT_NIMBLE_MEM_ALLOC_MODE

CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE

CONFIG_BT_NIMBLE_PINNED_TO_CORE_CHOICE


##### CONFIG_BT_NIMBLE_MEM_ALLOC_MODE

Found in: Component config > Bluetooth > NimBLE Options > General

- Internal DRAM memory only
- External SPIRAM memory only
- Either internal or external memory based on default malloc() behavior in ESP-IDF
- Internal IRAM memory wherever applicable else internal DRAM

Available options:

- Internal memory (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_INTERNAL)
- External SPIRAM (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_EXTERNAL)
- Default alloc mode (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_DEFAULT)
- Internal IRAM (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_IRAM_8BIT) Allows use of IRAM memory region as 8-bit accessible region. Every unaligned (8bit or 16bit) access will result in an exception and incur penalty of certain clock cycles per unaligned read/write.

Internal memory (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_INTERNAL)

External SPIRAM (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_EXTERNAL)

Default alloc mode (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_DEFAULT)

Internal IRAM (CONFIG_BT_NIMBLE_MEM_ALLOC_MODE_IRAM_8BIT)


##### CONFIG_BT_NIMBLE_PINNED_TO_CORE_CHOICE

Found in: Component config > Bluetooth > NimBLE Options > General

Available options:

- Core 0 (PRO CPU) (CONFIG_BT_NIMBLE_PINNED_TO_CORE_0)
- Core 1 (APP CPU) (CONFIG_BT_NIMBLE_PINNED_TO_CORE_1)

Core 0 (PRO CPU) (CONFIG_BT_NIMBLE_PINNED_TO_CORE_0)

Core 1 (APP CPU) (CONFIG_BT_NIMBLE_PINNED_TO_CORE_1)


##### CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE

Found in: Component config > Bluetooth > NimBLE Options > General

- 5120 if CONFIG_BLE_MESH && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED
- 4096 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

5120 if CONFIG_BLE_MESH && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

4096 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### Roles and Profiles

- CONFIG_BT_NIMBLE_ROLE_BROADCASTER
- CONFIG_BT_NIMBLE_ROLE_CENTRAL
- CONFIG_BT_NIMBLE_GATT_CLIENT
- CONFIG_BT_NIMBLE_GATT_SERVER
- CONFIG_BT_NIMBLE_ROLE_OBSERVER
- CONFIG_BT_NIMBLE_ROLE_PERIPHERAL

CONFIG_BT_NIMBLE_ROLE_BROADCASTER

CONFIG_BT_NIMBLE_ROLE_CENTRAL

CONFIG_BT_NIMBLE_GATT_CLIENT

CONFIG_BT_NIMBLE_GATT_SERVER

CONFIG_BT_NIMBLE_ROLE_OBSERVER

CONFIG_BT_NIMBLE_ROLE_PERIPHERAL


##### CONFIG_BT_NIMBLE_ROLE_CENTRAL

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ROLE_PERIPHERAL

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ROLE_BROADCASTER

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ROLE_OBSERVER

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CLIENT

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ROLE_CENTRAL && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ROLE_CENTRAL && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_SERVER

Found in: Component config > Bluetooth > NimBLE Options > Roles and Profiles

- Yes (enabled) if CONFIG_BT_NIMBLE_ROLE_PERIPHERAL && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ROLE_PERIPHERAL && CONFIG_BT_NIMBLE_ENABLED


##### Security (SMP)

- CONFIG_BT_NIMBLE_SECURITY_ENABLE

CONFIG_BT_NIMBLE_SECURITY_ENABLE


##### CONFIG_BT_NIMBLE_SECURITY_ENABLE

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP)

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_ENCRYPTION
- CONFIG_BT_NIMBLE_SM_SC_ONLY
- CONFIG_BT_NIMBLE_SM_LVL
- CONFIG_BT_NIMBLE_SM_LEGACY
- CONFIG_BT_NIMBLE_SM_SC

CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_ENCRYPTION

CONFIG_BT_NIMBLE_SM_SC_ONLY

CONFIG_BT_NIMBLE_SM_LVL

CONFIG_BT_NIMBLE_SM_LEGACY

CONFIG_BT_NIMBLE_SM_SC


##### CONFIG_BT_NIMBLE_SM_LEGACY

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP) > CONFIG_BT_NIMBLE_SECURITY_ENABLE

- Yes (enabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SM_SC

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP) > CONFIG_BT_NIMBLE_SECURITY_ENABLE

- Yes (enabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SM_SC_DEBUG_KEYS

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP) > CONFIG_BT_NIMBLE_SECURITY_ENABLE > CONFIG_BT_NIMBLE_SM_SC

- No (disabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_SM_SC && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_SM_SC && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_ENCRYPTION

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP) > CONFIG_BT_NIMBLE_SECURITY_ENABLE

- Yes (enabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SM_LVL

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP) > CONFIG_BT_NIMBLE_SECURITY_ENABLE

- 0 if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SM_SC_ONLY

Found in: Component config > Bluetooth > NimBLE Options > Security (SMP) > CONFIG_BT_NIMBLE_SECURITY_ENABLE

- 0 if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_SECURITY_ENABLE && CONFIG_BT_NIMBLE_ENABLED


##### GAP / GATT / Device Settings

- CONFIG_BT_NIMBLE_HOST_ALLOW_CONNECT_WITH_SCAN
- CONFIG_BT_NIMBLE_HS_STOP_TIMEOUT_MS
- CONFIG_BT_NIMBLE_HOST_QUEUE_CONG_CHECK
- CONFIG_BT_NIMBLE_WHITELIST_SIZE
- CONFIG_BT_NIMBLE_BLE_GATT_BLOB_TRANSFER
- CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT
- CONFIG_BT_NIMBLE_USE_ESP_TIMER
- CONFIG_BT_NIMBLE_HS_FLOW_CTRL
- CONFIG_BT_NIMBLE_HANDLE_REPEAT_PAIRING_DELETION
- CONFIG_BT_NIMBLE_ATT_MAX_PREP_ENTRIES
- CONFIG_BT_NIMBLE_MAX_BONDS
- CONFIG_BT_NIMBLE_MAX_CCCDS
- CONFIG_BT_NIMBLE_MAX_CONNECTIONS
- CONFIG_BT_NIMBLE_GATT_MAX_PROCS
- CONFIG_BT_NIMBLE_CRYPTO_STACK_MBEDTLS
- CONFIG_BT_NIMBLE_NVS_PERSIST
- CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU
- CONFIG_BT_NIMBLE_SMP_ID_RESET
- CONFIG_BT_NIMBLE_RPA_TIMEOUT

CONFIG_BT_NIMBLE_HOST_ALLOW_CONNECT_WITH_SCAN

CONFIG_BT_NIMBLE_HS_STOP_TIMEOUT_MS

CONFIG_BT_NIMBLE_HOST_QUEUE_CONG_CHECK

CONFIG_BT_NIMBLE_WHITELIST_SIZE

CONFIG_BT_NIMBLE_BLE_GATT_BLOB_TRANSFER

CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT

CONFIG_BT_NIMBLE_USE_ESP_TIMER

CONFIG_BT_NIMBLE_HS_FLOW_CTRL

CONFIG_BT_NIMBLE_HANDLE_REPEAT_PAIRING_DELETION

CONFIG_BT_NIMBLE_ATT_MAX_PREP_ENTRIES

CONFIG_BT_NIMBLE_MAX_BONDS

CONFIG_BT_NIMBLE_MAX_CCCDS

CONFIG_BT_NIMBLE_MAX_CONNECTIONS

CONFIG_BT_NIMBLE_GATT_MAX_PROCS

CONFIG_BT_NIMBLE_CRYPTO_STACK_MBEDTLS

CONFIG_BT_NIMBLE_NVS_PERSIST

CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU

CONFIG_BT_NIMBLE_SMP_ID_RESET

CONFIG_BT_NIMBLE_RPA_TIMEOUT


##### CONFIG_BT_NIMBLE_RPA_TIMEOUT

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- from 1 to 41400 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

from 1 to 41400 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

- 900 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

900 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_WHITELIST_SIZE

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- from 1 to 31 if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED
- from 1 to 15 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

from 1 to 15 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

- 12 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

12 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- Yes (enabled) if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_CONN_REATTEMPT

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings > CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT

- from 1 to 255 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 255 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT && CONFIG_BT_NIMBLE_ENABLED

- 3 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT && CONFIG_BT_NIMBLE_ENABLED

3 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLE_CONN_REATTEMPT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HANDLE_REPEAT_PAIRING_DELETION

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HOST_ALLOW_CONNECT_WITH_SCAN

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings


##### CONFIG_BT_NIMBLE_HOST_QUEUE_CONG_CHECK

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_CONNECTIONS

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- from 1 to 9 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

from 1 to 9 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

- 3 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

3 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_BONDS

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- 3 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

3 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_CCCDS

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- 8 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

8 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_NVS_PERSIST

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SMP_ID_RESET

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- 256 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

256 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ATT_MAX_PREP_ENTRIES

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- 64 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

64 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_MAX_PROCS

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- 4 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

4 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_CRYPTO_STACK_MBEDTLS

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HS_STOP_TIMEOUT_MS

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- 2000 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

2000 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_USE_ESP_TIMER

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_BLE_GATT_BLOB_TRANSFER

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings


##### CONFIG_BT_NIMBLE_HS_FLOW_CTRL

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings


##### CONFIG_BT_NIMBLE_HS_FLOW_CTRL_ITVL

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings > CONFIG_BT_NIMBLE_HS_FLOW_CTRL

- 1000 if CONFIG_BT_NIMBLE_HS_FLOW_CTRL && CONFIG_BT_NIMBLE_ENABLED

1000 if CONFIG_BT_NIMBLE_HS_FLOW_CTRL && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HS_FLOW_CTRL_THRESH

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings > CONFIG_BT_NIMBLE_HS_FLOW_CTRL

- 2 if CONFIG_BT_NIMBLE_HS_FLOW_CTRL && CONFIG_BT_NIMBLE_ENABLED

2 if CONFIG_BT_NIMBLE_HS_FLOW_CTRL && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HS_FLOW_CTRL_TX_ON_DISCONNECT

Found in: Component config > Bluetooth > NimBLE Options > GAP / GATT / Device Settings > CONFIG_BT_NIMBLE_HS_FLOW_CTRL

- Yes (enabled) if CONFIG_BT_NIMBLE_HS_FLOW_CTRL && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_HS_FLOW_CTRL && CONFIG_BT_NIMBLE_ENABLED


##### L2CAP

- CONFIG_BT_NIMBLE_L2CAP_ENHANCED_COC
- CONFIG_BT_NIMBLE_L2CAP_COC_MAX_NUM

CONFIG_BT_NIMBLE_L2CAP_ENHANCED_COC

CONFIG_BT_NIMBLE_L2CAP_COC_MAX_NUM


##### CONFIG_BT_NIMBLE_L2CAP_COC_MAX_NUM

Found in: Component config > Bluetooth > NimBLE Options > L2CAP

- from 0 to 9 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

from 0 to 9 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

- 0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_L2CAP_ENHANCED_COC

Found in: Component config > Bluetooth > NimBLE Options > L2CAP

- 0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_L2CAP_COC_MAX_NUM >= 1 && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_L2CAP_COC_MAX_NUM >= 1 && CONFIG_BT_NIMBLE_ENABLED


##### Memory Settings

- CONFIG_BT_NIMBLE_TRANSPORT_ACL_FROM_LL_COUNT
- CONFIG_BT_NIMBLE_TRANSPORT_EVT_DISCARD_COUNT
- CONFIG_BT_NIMBLE_MSYS_BUF_FROM_HEAP
- CONFIG_BT_NIMBLE_L2CAP_COC_SDU_BUFF_COUNT
- CONFIG_BT_NIMBLE_MSYS_1_BLOCK_COUNT
- CONFIG_BT_NIMBLE_MSYS_1_BLOCK_SIZE
- CONFIG_BT_NIMBLE_MSYS_2_BLOCK_COUNT
- CONFIG_BT_NIMBLE_MSYS_2_BLOCK_SIZE
- CONFIG_BT_NIMBLE_TRANSPORT_ACL_SIZE
- CONFIG_BT_NIMBLE_TRANSPORT_EVT_COUNT
- CONFIG_BT_NIMBLE_TRANSPORT_EVT_SIZE

CONFIG_BT_NIMBLE_TRANSPORT_ACL_FROM_LL_COUNT

CONFIG_BT_NIMBLE_TRANSPORT_EVT_DISCARD_COUNT

CONFIG_BT_NIMBLE_MSYS_BUF_FROM_HEAP

CONFIG_BT_NIMBLE_L2CAP_COC_SDU_BUFF_COUNT

CONFIG_BT_NIMBLE_MSYS_1_BLOCK_COUNT

CONFIG_BT_NIMBLE_MSYS_1_BLOCK_SIZE

CONFIG_BT_NIMBLE_MSYS_2_BLOCK_COUNT

CONFIG_BT_NIMBLE_MSYS_2_BLOCK_SIZE

CONFIG_BT_NIMBLE_TRANSPORT_ACL_SIZE

CONFIG_BT_NIMBLE_TRANSPORT_EVT_COUNT

CONFIG_BT_NIMBLE_TRANSPORT_EVT_SIZE


##### CONFIG_BT_NIMBLE_MSYS_1_BLOCK_COUNT

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 24 if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED

24 if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MSYS_1_BLOCK_SIZE

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 128 if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED

128 if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MSYS_2_BLOCK_COUNT

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 24 if CONFIG_BT_NIMBLE_ENABLED

24 if CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MSYS_2_BLOCK_SIZE

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 320 if CONFIG_BT_NIMBLE_ENABLED

320 if CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MSYS_BUF_FROM_HEAP

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- Yes (enabled) if BT_LE_MSYS_INIT_IN_CONTROLLER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TRANSPORT_ACL_FROM_LL_COUNT

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 24 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

24 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TRANSPORT_ACL_SIZE

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 255 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

255 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TRANSPORT_EVT_SIZE

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 257 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED
- 70 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

257 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

70 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TRANSPORT_EVT_COUNT

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 30 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

30 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TRANSPORT_EVT_DISCARD_COUNT

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 8 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

8 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_L2CAP_COC_SDU_BUFF_COUNT

Found in: Component config > Bluetooth > NimBLE Options > Memory Settings

- 1 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### BLE 5.x Features

- CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT


##### CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && SOC_BLE_50_SUPPORTED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && SOC_BLE_50_SUPPORTED && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_AOA_AOD
- CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_2M_PHY
- CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_CODED_PHY
- CONFIG_BT_NIMBLE_EXT_ADV
- CONFIG_BT_NIMBLE_EXT_SCAN
- CONFIG_BT_NIMBLE_BLE_POWER_CONTROL
- CONFIG_BT_NIMBLE_ISO

CONFIG_BT_NIMBLE_AOA_AOD

CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_2M_PHY

CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_CODED_PHY

CONFIG_BT_NIMBLE_EXT_ADV

CONFIG_BT_NIMBLE_EXT_SCAN

CONFIG_BT_NIMBLE_BLE_POWER_CONTROL

CONFIG_BT_NIMBLE_ISO


##### CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_2M_PHY

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- Yes (enabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_CODED_PHY

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- Yes (enabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_EXT_ADV

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_EXT_ADV_V2

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV

- No (disabled) if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_EXT_ADV_INSTANCES

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV

- from 0 to 4 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 0 to 4 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 1 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED
- 0 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_EXT_ADV_MAX_SIZE

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV

- from 0 to 1650 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 0 to 1650 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 1650 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED
- 0 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

1650 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV

- Yes (enabled) if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_PERIODIC_ADV_ENH

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV > CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV


##### CONFIG_BT_NIMBLE_PERIODIC_ADV_SYNC_TRANSFER

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV > CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_PERIODIC_ADV_WITH_RESPONSES

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_ADV > CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV

- No (disabled) if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV && CONFIG_BT_NIMBLE_EXT_ADV && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_EXT_SCAN

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- Yes (enabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_SCAN

- Yes (enabled) if CONFIG_BT_NIMBLE_EXT_SCAN && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_EXT_SCAN && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_PERIODIC_SYNCS

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_SCAN > CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC

- from 0 to 8 if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 0 to 8 if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 1 if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV && CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED
- 0 if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV && CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MAX_PERIODIC_ADVERTISER_LIST

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_EXT_SCAN > CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC

- from 1 to 5 if SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 5 if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

5 if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_BLE_POWER_CONTROL

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_BLE_POWER_CONTROL_SUPPORTED && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_BLE_POWER_CONTROL_SUPPORTED && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_AOA_AOD

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT

- No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_BLE_CTE_SUPPORTED && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && SOC_BLE_CTE_SUPPORTED && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT


##### CONFIG_BT_NIMBLE_ISO_FLOW_CONTROL

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

Available options:

- Standard (CONFIG_BT_NIMBLE_ISO_STD_FLOW_CTRL) ISO standard flow control
- Non-standard (CONFIG_BT_NIMBLE_ISO_NON_STD_FLOW_CTRL) ISO non-standard flow control

Standard (CONFIG_BT_NIMBLE_ISO_STD_FLOW_CTRL)

Non-standard (CONFIG_BT_NIMBLE_ISO_NON_STD_FLOW_CTRL)


##### CONFIG_BT_NIMBLE_ISO_TEST

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- Yes (enabled) if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_BIG

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- from 1 to 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 1 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_BIS

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_BIS_PER_BIG

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_CIG

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- from 1 to 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 1 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_CIS

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_CIS_PER_CIG

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO

- from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

from 1 to 3 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

- 2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED

2 if CONFIG_BT_NIMBLE_ISO && CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ISO_CIS_ESTAB_V2

Found in: Component config > Bluetooth > NimBLE Options > BLE 5.x Features > CONFIG_BT_NIMBLE_50_FEATURE_SUPPORT > CONFIG_BT_NIMBLE_ISO


##### BLE 6.x Features

- CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT

CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT


##### CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT

Found in: Component config > Bluetooth > NimBLE Options > BLE 6.x Features

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_CHANNEL_SOUNDING
- CONFIG_BT_NIMBLE_MONITOR_ADV

CONFIG_BT_NIMBLE_CHANNEL_SOUNDING

CONFIG_BT_NIMBLE_MONITOR_ADV


##### CONFIG_BT_NIMBLE_CHANNEL_SOUNDING

Found in: Component config > Bluetooth > NimBLE Options > BLE 6.x Features > CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT

- No (disabled) if CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MONITOR_ADV

Found in: Component config > Bluetooth > NimBLE Options > BLE 6.x Features > CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT

- No (disabled) if CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_60_FEATURE_SUPPORT && (SOC_BLE_60_SUPPORTED || CONFIG_BT_CONTROLLER_DISABLED) && CONFIG_BT_NIMBLE_ENABLED


##### Services

- CONFIG_BT_NIMBLE_ANS_SERVICE
- CONFIG_BT_NIMBLE_BAS_SERVICE
- CONFIG_BT_NIMBLE_CTS_SERVICE
- CONFIG_BT_NIMBLE_DIS_SERVICE
- CONFIG_BT_NIMBLE_GAP_SERVICE
- CONFIG_BT_NIMBLE_HTP_SERVICE
- CONFIG_BT_NIMBLE_HR_SERVICE
- CONFIG_BT_NIMBLE_HID_SERVICE
- CONFIG_BT_NIMBLE_IAS_SERVICE
- CONFIG_BT_NIMBLE_IPSS_SERVICE
- CONFIG_BT_NIMBLE_LLS_SERVICE
- CONFIG_BT_NIMBLE_PROX_SERVICE
- CONFIG_BT_NIMBLE_SPS_SERVICE
- CONFIG_BT_NIMBLE_TPS_SERVICE

CONFIG_BT_NIMBLE_ANS_SERVICE

CONFIG_BT_NIMBLE_BAS_SERVICE

CONFIG_BT_NIMBLE_CTS_SERVICE

CONFIG_BT_NIMBLE_DIS_SERVICE

CONFIG_BT_NIMBLE_GAP_SERVICE

CONFIG_BT_NIMBLE_HTP_SERVICE

CONFIG_BT_NIMBLE_HR_SERVICE

CONFIG_BT_NIMBLE_HID_SERVICE

CONFIG_BT_NIMBLE_IAS_SERVICE

CONFIG_BT_NIMBLE_IPSS_SERVICE

CONFIG_BT_NIMBLE_LLS_SERVICE

CONFIG_BT_NIMBLE_PROX_SERVICE

CONFIG_BT_NIMBLE_SPS_SERVICE

CONFIG_BT_NIMBLE_TPS_SERVICE


##### CONFIG_BT_NIMBLE_PROX_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ANS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_CTS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HTP_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_IPSS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TPS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_IAS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_LLS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SPS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HR_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HID_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- No (disabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_SVC_HID_MAX_RPTS
- CONFIG_BT_NIMBLE_SVC_HID_MAX_INSTANCES

CONFIG_BT_NIMBLE_SVC_HID_MAX_RPTS

CONFIG_BT_NIMBLE_SVC_HID_MAX_INSTANCES


##### CONFIG_BT_NIMBLE_SVC_HID_MAX_INSTANCES

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_HID_SERVICE

- 2 if CONFIG_BT_NIMBLE_HID_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

2 if CONFIG_BT_NIMBLE_HID_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_HID_MAX_RPTS

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_HID_SERVICE

- 3 if CONFIG_BT_NIMBLE_HID_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

3 if CONFIG_BT_NIMBLE_HID_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_BAS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_SVC_BAS_BATTERY_LEVEL_NOTIFY

CONFIG_BT_NIMBLE_SVC_BAS_BATTERY_LEVEL_NOTIFY


##### CONFIG_BT_NIMBLE_SVC_BAS_BATTERY_LEVEL_NOTIFY

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_BAS_SERVICE


##### CONFIG_BT_NIMBLE_DIS_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_SVC_DIS_INCLUDED
- CONFIG_BT_NIMBLE_SVC_DIS_FIRMWARE_REVISION
- CONFIG_BT_NIMBLE_SVC_DIS_HARDWARE_REVISION
- CONFIG_BT_NIMBLE_SVC_DIS_MANUFACTURER_NAME
- CONFIG_BT_NIMBLE_SVC_DIS_PNP_ID
- CONFIG_BT_NIMBLE_SVC_DIS_SERIAL_NUMBER
- CONFIG_BT_NIMBLE_SVC_DIS_SOFTWARE_REVISION
- CONFIG_BT_NIMBLE_SVC_DIS_SYSTEM_ID

CONFIG_BT_NIMBLE_SVC_DIS_INCLUDED

CONFIG_BT_NIMBLE_SVC_DIS_FIRMWARE_REVISION

CONFIG_BT_NIMBLE_SVC_DIS_HARDWARE_REVISION

CONFIG_BT_NIMBLE_SVC_DIS_MANUFACTURER_NAME

CONFIG_BT_NIMBLE_SVC_DIS_PNP_ID

CONFIG_BT_NIMBLE_SVC_DIS_SERIAL_NUMBER

CONFIG_BT_NIMBLE_SVC_DIS_SOFTWARE_REVISION

CONFIG_BT_NIMBLE_SVC_DIS_SYSTEM_ID


##### CONFIG_BT_NIMBLE_SVC_DIS_MANUFACTURER_NAME

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_SERIAL_NUMBER

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_HARDWARE_REVISION

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_FIRMWARE_REVISION

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_SOFTWARE_REVISION

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_SYSTEM_ID

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_PNP_ID

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_DIS_INCLUDED

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_DIS_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_DIS_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GAP_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Services

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME
- CONFIG_BT_NIMBLE_SVC_GAP_APPEARANCE
- GAP Appearance write permissions
- CONFIG_BT_NIMBLE_SVC_GAP_CENT_ADDR_RESOLUTION
- GAP device name write permissions
- CONFIG_BT_NIMBLE_SVC_GAP_GATT_SECURITY_LEVEL
- CONFIG_BT_NIMBLE_GAP_DEVICE_NAME_MAX_LEN
- Peripheral Preferred Connection Parameters (PPCP) settings
- CONFIG_BT_NIMBLE_SVC_GAP_RPA_ONLY

CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME

CONFIG_BT_NIMBLE_SVC_GAP_APPEARANCE

CONFIG_BT_NIMBLE_SVC_GAP_CENT_ADDR_RESOLUTION

CONFIG_BT_NIMBLE_SVC_GAP_GATT_SECURITY_LEVEL

CONFIG_BT_NIMBLE_GAP_DEVICE_NAME_MAX_LEN

CONFIG_BT_NIMBLE_SVC_GAP_RPA_ONLY


##### CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE

- "nimble" if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

"nimble" if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GAP_DEVICE_NAME_MAX_LEN

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE

- 31 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

31 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_APPEARANCE

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE

- 0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_GATT_SECURITY_LEVEL

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_RPA_ONLY

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE

- No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_CENT_ADDR_RESOLUTION

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE

- Central Address Resolution characteristic not supported
- Central Address Resolution not supported
- Central Address Resolution supported

Available options:

- Characteristic not supported (CONFIG_BT_NIMBLE_SVC_GAP_CAR_CHAR_NOT_SUPP)
- Central Address Resolution not supported (CONFIG_BT_NIMBLE_SVC_GAP_CAR_NOT_SUPP)
- Central Address Resolution supported (CONFIG_BT_NIMBLE_SVC_GAP_CAR_SUPP)

Characteristic not supported (CONFIG_BT_NIMBLE_SVC_GAP_CAR_CHAR_NOT_SUPP)

Central Address Resolution not supported (CONFIG_BT_NIMBLE_SVC_GAP_CAR_NOT_SUPP)

Central Address Resolution supported (CONFIG_BT_NIMBLE_SVC_GAP_CAR_SUPP)


##### GAP Appearance write permissions

- CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE

CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE


##### CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP Appearance write permissions

- No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE_ENC

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP Appearance write permissions > CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE


##### CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE_AUTHEN

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP Appearance write permissions > CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE


##### CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE_AUTHOR

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP Appearance write permissions > CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE

- No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_APPEAR_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### GAP device name write permissions

- CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE

CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE


##### CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP device name write permissions

- No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE_ENC

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP device name write permissions > CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE

- No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE_AUTHEN

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP device name write permissions > CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE

- No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE_AUTHOR

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > GAP device name write permissions > CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE

- No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_SVC_GAP_NAME_WRITE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### Peripheral Preferred Connection Parameters (PPCP) settings

- CONFIG_BT_NIMBLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL
- CONFIG_BT_NIMBLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL
- CONFIG_BT_NIMBLE_SVC_GAP_PPCP_SLAVE_LATENCY
- CONFIG_BT_NIMBLE_SVC_GAP_PPCP_SUPERVISION_TMO

CONFIG_BT_NIMBLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL

CONFIG_BT_NIMBLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL

CONFIG_BT_NIMBLE_SVC_GAP_PPCP_SLAVE_LATENCY

CONFIG_BT_NIMBLE_SVC_GAP_PPCP_SUPERVISION_TMO


##### CONFIG_BT_NIMBLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > Peripheral Preferred Connection Parameters (PPCP) settings

- 0 if CONFIG_BT_NIMBLE_ROLE_PERIPHERAL && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ROLE_PERIPHERAL && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > Peripheral Preferred Connection Parameters (PPCP) settings

- 0 if CONFIG_BT_NIMBLE_ROLE_PERIPHERAL && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ROLE_PERIPHERAL && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_PPCP_SLAVE_LATENCY

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > Peripheral Preferred Connection Parameters (PPCP) settings

- 0 if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SVC_GAP_PPCP_SUPERVISION_TMO

Found in: Component config > Bluetooth > NimBLE Options > Services > CONFIG_BT_NIMBLE_GAP_SERVICE > Peripheral Preferred Connection Parameters (PPCP) settings

- 0 if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GAP_SERVICE && CONFIG_BT_NIMBLE_GATT_SERVER && CONFIG_BT_NIMBLE_ENABLED


##### Extra Features

- CONFIG_BT_NIMBLE_GATTC_AUTO_PAIR
- CONFIG_BT_NIMBLE_GATT_CACHING_DISABLE_AUTO
- CONFIG_BT_NIMBLE_GATT_CACHING_ASSOC_ENABLE
- CONFIG_BT_NIMBLE_BLUFI_ENABLE
- CONFIG_BT_NIMBLE_DYNAMIC_SERVICE
- CONFIG_BT_NIMBLE_GATT_CACHING
- CONFIG_BT_NIMBLE_INCL_SVC_DISCOVERY
- CONFIG_BT_NIMBLE_SUBRATE
- CONFIG_BT_NIMBLE_ENC_ADV_DATA
- CONFIG_BT_NIMBLE_GATTC_PROC_PREEMPTION_PROTECT
- CONFIG_BT_NIMBLE_GATT_CACHING_MAX_CONNS
- CONFIG_BT_NIMBLE_GATT_CACHING_MAX_CHRS
- CONFIG_BT_NIMBLE_GATT_CACHING_MAX_DSCS
- CONFIG_BT_NIMBLE_EATT_CHAN_NUM
- CONFIG_BT_NIMBLE_GATT_CACHING_MAX_INCL_SVCS
- CONFIG_BT_NIMBLE_GATT_CACHING_MAX_SVCS

CONFIG_BT_NIMBLE_GATTC_AUTO_PAIR

CONFIG_BT_NIMBLE_GATT_CACHING_DISABLE_AUTO

CONFIG_BT_NIMBLE_GATT_CACHING_ASSOC_ENABLE

CONFIG_BT_NIMBLE_BLUFI_ENABLE

CONFIG_BT_NIMBLE_DYNAMIC_SERVICE

CONFIG_BT_NIMBLE_GATT_CACHING

CONFIG_BT_NIMBLE_INCL_SVC_DISCOVERY

CONFIG_BT_NIMBLE_SUBRATE

CONFIG_BT_NIMBLE_ENC_ADV_DATA

CONFIG_BT_NIMBLE_GATTC_PROC_PREEMPTION_PROTECT

CONFIG_BT_NIMBLE_GATT_CACHING_MAX_CONNS

CONFIG_BT_NIMBLE_GATT_CACHING_MAX_CHRS

CONFIG_BT_NIMBLE_GATT_CACHING_MAX_DSCS

CONFIG_BT_NIMBLE_EATT_CHAN_NUM

CONFIG_BT_NIMBLE_GATT_CACHING_MAX_INCL_SVCS

CONFIG_BT_NIMBLE_GATT_CACHING_MAX_SVCS


##### CONFIG_BT_NIMBLE_DYNAMIC_SERVICE

Found in: Component config > Bluetooth > NimBLE Options > Extra Features


##### CONFIG_BT_NIMBLE_GATT_CACHING

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- CONFIG_BT_NIMBLE_GATT_CACHING_INCLUDE_SERVICES

CONFIG_BT_NIMBLE_GATT_CACHING_INCLUDE_SERVICES


##### CONFIG_BT_NIMBLE_GATT_CACHING_INCLUDE_SERVICES

Found in: Component config > Bluetooth > NimBLE Options > Extra Features > CONFIG_BT_NIMBLE_GATT_CACHING

- No (disabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_INCL_SVC_DISCOVERY

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- Yes (enabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_GATT_CACHING_INCLUDE_SERVICES && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_GATT_CACHING_INCLUDE_SERVICES && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_MAX_CONNS

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_MAX_SVCS

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- 64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_MAX_INCL_SVCS

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- 64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_MAX_CHRS

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- 64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_MAX_DSCS

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- 64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

64 if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_DISABLE_AUTO

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- No (disabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATT_CACHING_ASSOC_ENABLE

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- No (disabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_GATT_CACHING && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_BLUFI_ENABLE

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_ENC_ADV_DATA

Found in: Component config > Bluetooth > NimBLE Options > Extra Features


##### CONFIG_BT_NIMBLE_MAX_EADS

Found in: Component config > Bluetooth > NimBLE Options > Extra Features > CONFIG_BT_NIMBLE_ENC_ADV_DATA

- 10 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENC_ADV_DATA && CONFIG_BT_NIMBLE_ENABLED

10 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENC_ADV_DATA && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATTC_PROC_PREEMPTION_PROTECT

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_GATTC_AUTO_PAIR

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_EATT_CHAN_NUM

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- 0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_SUBRATE

Found in: Component config > Bluetooth > NimBLE Options > Extra Features

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### NimBLE Mesh

- CONFIG_BT_NIMBLE_MESH

CONFIG_BT_NIMBLE_MESH


##### CONFIG_BT_NIMBLE_MESH

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

- CONFIG_BT_NIMBLE_MESH_PROVISIONER
- CONFIG_BT_NIMBLE_MESH_PROV
- CONFIG_BT_NIMBLE_MESH_GATT_PROXY
- CONFIG_BT_NIMBLE_MESH_FRIEND
- CONFIG_BT_NIMBLE_MESH_LOW_POWER
- CONFIG_BT_NIMBLE_MESH_PROXY
- CONFIG_BT_NIMBLE_MESH_RELAY
- CONFIG_BT_NIMBLE_MESH_DEVICE_NAME
- CONFIG_BT_NIMBLE_MESH_NODE_COUNT

CONFIG_BT_NIMBLE_MESH_PROVISIONER

CONFIG_BT_NIMBLE_MESH_PROV

CONFIG_BT_NIMBLE_MESH_GATT_PROXY

CONFIG_BT_NIMBLE_MESH_FRIEND

CONFIG_BT_NIMBLE_MESH_LOW_POWER

CONFIG_BT_NIMBLE_MESH_PROXY

CONFIG_BT_NIMBLE_MESH_RELAY

CONFIG_BT_NIMBLE_MESH_DEVICE_NAME

CONFIG_BT_NIMBLE_MESH_NODE_COUNT


##### CONFIG_BT_NIMBLE_MESH_PROXY

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_PROV

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- Yes (enabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_PB_ADV

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH > CONFIG_BT_NIMBLE_MESH_PROV

- Yes (enabled) if CONFIG_BT_NIMBLE_MESH_PROV && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_MESH_PROV && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_PB_GATT

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH > CONFIG_BT_NIMBLE_MESH_PROV

- Yes (enabled) if CONFIG_BT_NIMBLE_MESH_PROV && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_MESH_PROV && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_GATT_PROXY

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- Yes (enabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_RELAY

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_LOW_POWER

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_FRIEND

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_DEVICE_NAME

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- "nimble-mesh-node" if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

"nimble-mesh-node" if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_NODE_COUNT

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- 1 if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_MESH_PROVISIONER

Found in: Component config > Bluetooth > NimBLE Options > NimBLE Mesh > CONFIG_BT_NIMBLE_MESH

- 0 if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED

0 if CONFIG_BT_NIMBLE_MESH && CONFIG_BT_NIMBLE_ENABLED


##### Host-controller Transport

- CONFIG_BT_NIMBLE_TRANSPORT_UART
- CONFIG_BT_NIMBLE_HCI_UART_CTS_PIN
- CONFIG_BT_NIMBLE_USE_HCI_UART_FLOW_CTRL
- CONFIG_BT_NIMBLE_HCI_UART_RTS_PIN

CONFIG_BT_NIMBLE_TRANSPORT_UART

CONFIG_BT_NIMBLE_HCI_UART_CTS_PIN

CONFIG_BT_NIMBLE_USE_HCI_UART_FLOW_CTRL

CONFIG_BT_NIMBLE_HCI_UART_RTS_PIN


##### CONFIG_BT_NIMBLE_TRANSPORT_UART

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport

- Yes (enabled) if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TRANSPORT_UART_PORT

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport > CONFIG_BT_NIMBLE_TRANSPORT_UART

- 1 if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_TRANSPORT_UART && CONFIG_BT_NIMBLE_ENABLED

1 if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_TRANSPORT_UART && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HCI_USE_UART_BAUDRATE

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport > CONFIG_BT_NIMBLE_TRANSPORT_UART

Available options:

- 115200 (CONFIG_UART_BAUDRATE_115200)
- 230400 (CONFIG_UART_BAUDRATE_230400)
- 460800 (CONFIG_UART_BAUDRATE_460800)
- 921600 (CONFIG_UART_BAUDRATE_921600)

115200 (CONFIG_UART_BAUDRATE_115200)

230400 (CONFIG_UART_BAUDRATE_230400)

460800 (CONFIG_UART_BAUDRATE_460800)

921600 (CONFIG_UART_BAUDRATE_921600)


##### CONFIG_BT_NIMBLE_USE_HCI_UART_PARITY

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport > CONFIG_BT_NIMBLE_TRANSPORT_UART

Available options:

- None (CONFIG_UART_PARITY_NONE)
- Odd (CONFIG_UART_PARITY_ODD)
- Even (CONFIG_UART_PARITY_EVEN)

None (CONFIG_UART_PARITY_NONE)

Odd (CONFIG_UART_PARITY_ODD)

Even (CONFIG_UART_PARITY_EVEN)


##### CONFIG_BT_NIMBLE_UART_RX_PIN

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport > CONFIG_BT_NIMBLE_TRANSPORT_UART

- 5 if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_TRANSPORT_UART && CONFIG_BT_NIMBLE_ENABLED

5 if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_TRANSPORT_UART && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_UART_TX_PIN

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport > CONFIG_BT_NIMBLE_TRANSPORT_UART

- 4 if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_TRANSPORT_UART && CONFIG_BT_NIMBLE_ENABLED

4 if CONFIG_BT_CONTROLLER_DISABLED && CONFIG_BT_NIMBLE_TRANSPORT_UART && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_USE_HCI_UART_FLOW_CTRL

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport

Available options:

- Disable (CONFIG_UART_HW_FLOWCTRL_DISABLE)
- Enable hardware flow control (CONFIG_UART_HW_FLOWCTRL_CTS_RTS)

Disable (CONFIG_UART_HW_FLOWCTRL_DISABLE)

Enable hardware flow control (CONFIG_UART_HW_FLOWCTRL_CTS_RTS)


##### CONFIG_BT_NIMBLE_HCI_UART_RTS_PIN

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport

- 19 if CONFIG_BT_NIMBLE_ENABLED

19 if CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HCI_UART_CTS_PIN

Found in: Component config > Bluetooth > NimBLE Options > Host-controller Transport

- 23 if CONFIG_BT_NIMBLE_ENABLED

23 if CONFIG_BT_NIMBLE_ENABLED


##### Debugging/Testing

- CONFIG_BT_NIMBLE_DEBUG
- CONFIG_BT_NIMBLE_PRINT_ERR_NAME
- CONFIG_BT_NIMBLE_LOG_LEVEL
- CONFIG_BT_NIMBLE_TEST_THROUGHPUT_TEST

CONFIG_BT_NIMBLE_DEBUG

CONFIG_BT_NIMBLE_PRINT_ERR_NAME

CONFIG_BT_NIMBLE_LOG_LEVEL

CONFIG_BT_NIMBLE_TEST_THROUGHPUT_TEST


##### CONFIG_BT_NIMBLE_LOG_LEVEL

Found in: Component config > Bluetooth > NimBLE Options > Debugging/Testing

Available options:

- No logs (CONFIG_BT_NIMBLE_LOG_LEVEL_NONE)
- Error logs (CONFIG_BT_NIMBLE_LOG_LEVEL_ERROR)
- Warning logs (CONFIG_BT_NIMBLE_LOG_LEVEL_WARNING)
- Info logs (CONFIG_BT_NIMBLE_LOG_LEVEL_INFO)
- Debug logs (CONFIG_BT_NIMBLE_LOG_LEVEL_DEBUG)

No logs (CONFIG_BT_NIMBLE_LOG_LEVEL_NONE)

Error logs (CONFIG_BT_NIMBLE_LOG_LEVEL_ERROR)

Warning logs (CONFIG_BT_NIMBLE_LOG_LEVEL_WARNING)

Info logs (CONFIG_BT_NIMBLE_LOG_LEVEL_INFO)

Debug logs (CONFIG_BT_NIMBLE_LOG_LEVEL_DEBUG)


##### CONFIG_BT_NIMBLE_PRINT_ERR_NAME

Found in: Component config > Bluetooth > NimBLE Options > Debugging/Testing

- Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

Yes (enabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_DEBUG

Found in: Component config > Bluetooth > NimBLE Options > Debugging/Testing

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_TEST_THROUGHPUT_TEST

Found in: Component config > Bluetooth > NimBLE Options > Debugging/Testing

- No (disabled) if CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_NIMBLE_ENABLED


##### Vendor / Optimization

- CONFIG_BT_NIMBLE_HIGH_DUTY_ADV_ITVL
- CONFIG_BT_NIMBLE_VS_SUPPORT
- CONFIG_BT_NIMBLE_OPTIMIZE_MULTI_CONN

CONFIG_BT_NIMBLE_HIGH_DUTY_ADV_ITVL

CONFIG_BT_NIMBLE_VS_SUPPORT

CONFIG_BT_NIMBLE_OPTIMIZE_MULTI_CONN


##### CONFIG_BT_NIMBLE_VS_SUPPORT

Found in: Component config > Bluetooth > NimBLE Options > Vendor / Optimization


##### CONFIG_BT_NIMBLE_OPTIMIZE_MULTI_CONN

Found in: Component config > Bluetooth > NimBLE Options > Vendor / Optimization

- No (disabled) if SOC_BLE_MULTI_CONN_OPTIMIZATION && CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_NIMBLE_HIGH_DUTY_ADV_ITVL

Found in: Component config > Bluetooth > NimBLE Options > Vendor / Optimization


#### Controller Options


#### CONFIG_BT_RELEASE_IRAM

Found in: Component config > Bluetooth

- No (disabled) if CONFIG_BT_ENABLED && BT_LE_RELEASE_IRAM_SUPPORTED

No (disabled) if CONFIG_BT_ENABLED && BT_LE_RELEASE_IRAM_SUPPORTED


#### Common Options

- BLE Log
- CONFIG_BT_LE_USED_MEM_STATISTICS_ENABLED
- CONFIG_BT_ALARM_MAX_NUM
- CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED
- CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

CONFIG_BT_LE_USED_MEM_STATISTICS_ENABLED

CONFIG_BT_ALARM_MAX_NUM

CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED


##### CONFIG_BT_ALARM_MAX_NUM

Found in: Component config > Bluetooth > Common Options

- 50 if CONFIG_BT_BLUEDROID_ENABLED || CONFIG_BT_NIMBLE_ENABLED

50 if CONFIG_BT_BLUEDROID_ENABLED || CONFIG_BT_NIMBLE_ENABLED


##### BLE Log

- CONFIG_BLE_LOG_ENABLED

CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_ENABLED

Found in: Component config > Bluetooth > Common Options > BLE Log

- No (disabled)


##### CONFIG_BLE_LOG_TASK_STACK_SIZE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 1024 if CONFIG_BLE_LOG_ENABLED

1024 if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_LBM_TRANS_SIZE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 512 if CONFIG_BLE_LOG_ENABLED

512 if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_LBM_ATOMIC_LOCK_TASK_CNT

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 2 if CONFIG_BLE_LOG_ENABLED

2 if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_LBM_ATOMIC_LOCK_ISR_CNT

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 1 if CONFIG_BLE_LOG_ENABLED

1 if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_IS_ESP_CONTROLLER

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- Yes (enabled) if CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BT_CONTROLLER_ENABLED && SOC_ESP_NIMBLE_CONTROLLER && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_IS_ESP_LEGACY_CONTROLLER

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_LL_ENABLED

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- No (disabled) if CONFIG_BT_CONTROLLER_ENABLED && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BT_CONTROLLER_ENABLED && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_LBM_LL_TRANS_SIZE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > CONFIG_BLE_LOG_LL_ENABLED

- 1024 if CONFIG_BLE_LOG_LL_ENABLED && CONFIG_BLE_LOG_ENABLED

1024 if CONFIG_BLE_LOG_LL_ENABLED && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PAYLOAD_CHECKSUM_ENABLED

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- Yes (enabled) if CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_ENH_STAT_ENABLED

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- No (disabled) if CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_TS_ENABLED

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- No (disabled) if CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_SYNC_IO_NUM

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > CONFIG_BLE_LOG_TS_ENABLED

- 0 if CONFIG_BLE_LOG_TS_ENABLED && CONFIG_BLE_LOG_ENABLED

0 if CONFIG_BLE_LOG_TS_ENABLED && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PRPH_CHOICE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

Available options:

- Dummy transport (CONFIG_BLE_LOG_PRPH_DUMMY) Dummy transport (dump only)
- Utilize SPI master DMA driver as transport (CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA) Utilize SPI master DMA driver as transport
- Utilize UART DMA driver as transport (CONFIG_BLE_LOG_PRPH_UART_DMA) Utilize UART DMA driver as transport

Dummy transport (CONFIG_BLE_LOG_PRPH_DUMMY)

Utilize UART DMA driver as transport (CONFIG_BLE_LOG_PRPH_UART_DMA)


##### CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA_MOSI_IO_NUM

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 0 if CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA && CONFIG_BLE_LOG_ENABLED

0 if CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA_SCLK_IO_NUM

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 0 if CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA && CONFIG_BLE_LOG_ENABLED

0 if CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA_CS_IO_NUM

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 0 if CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA && CONFIG_BLE_LOG_ENABLED

0 if CONFIG_BLE_LOG_PRPH_SPI_MASTER_DMA && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PRPH_UART_DMA_PORT

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 0 if CONFIG_BLE_LOG_PRPH_UART_DMA && CONFIG_BLE_LOG_ENABLED

0 if CONFIG_BLE_LOG_PRPH_UART_DMA && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PRPH_UART_DMA_BAUD_RATE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 921600 if CONFIG_BLE_LOG_PRPH_UART_DMA && CONFIG_BLE_LOG_ENABLED

921600 if CONFIG_BLE_LOG_PRPH_UART_DMA && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_LOG_PRPH_UART_DMA_TX_IO_NUM

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED

- 0 if CONFIG_BLE_LOG_PRPH_UART_DMA && CONFIG_BLE_LOG_ENABLED

0 if CONFIG_BLE_LOG_PRPH_UART_DMA && CONFIG_BLE_LOG_ENABLED


##### Settings of BLE Log Compression

- CONFIG_BLE_COMPRESSED_LOG_ENABLE

CONFIG_BLE_COMPRESSED_LOG_ENABLE


##### CONFIG_BLE_COMPRESSED_LOG_ENABLE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression

- No (disabled) if CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE

- No (disabled) if CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_MESH && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_MESH && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

- CONFIG_BLE_MESH_COMPRESSED_LOG_BUFFER_LEN
- Select the net buf log tag to be compressed
- Select the stack log tag to be compressed

CONFIG_BLE_MESH_COMPRESSED_LOG_BUFFER_LEN


##### CONFIG_BLE_MESH_COMPRESSED_LOG_BUFFER_LEN

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE

- 400 if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

400 if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the stack log tag to be compressed

- CONFIG_BLE_MESH_STACK_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_MESH_STACK_ERR_LOG_COMPRESSION
- CONFIG_BLE_MESH_STACK_INFO_LOG_COMPRESSION
- CONFIG_BLE_MESH_STACK_WARN_LOG_COMPRESSION

CONFIG_BLE_MESH_STACK_DEBUG_LOG_COMPRESSION

CONFIG_BLE_MESH_STACK_ERR_LOG_COMPRESSION

CONFIG_BLE_MESH_STACK_INFO_LOG_COMPRESSION

CONFIG_BLE_MESH_STACK_WARN_LOG_COMPRESSION


##### CONFIG_BLE_MESH_STACK_ERR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_ERR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed > CONFIG_BLE_MESH_STACK_ERR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_MESH_STACK_ERR_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_STACK_ERR_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_WARN_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_WARN_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed > CONFIG_BLE_MESH_STACK_WARN_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_MESH_STACK_WARN_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_STACK_WARN_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_INFO_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_INFO_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed > CONFIG_BLE_MESH_STACK_INFO_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_MESH_STACK_INFO_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_MESH_STACK_INFO_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_STACK_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the stack log tag to be compressed > CONFIG_BLE_MESH_STACK_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_MESH_STACK_DEBUG_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_MESH_STACK_DEBUG_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the net buf log tag to be compressed

- CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_MESH_NET_BUF_ERR_LOG_COMPRESSION
- CONFIG_BLE_MESH_NET_BUF_INFO_LOG_COMPRESSION
- CONFIG_BLE_MESH_NET_BUF_WARN_LOG_COMPRESSION

CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_COMPRESSION

CONFIG_BLE_MESH_NET_BUF_ERR_LOG_COMPRESSION

CONFIG_BLE_MESH_NET_BUF_INFO_LOG_COMPRESSION

CONFIG_BLE_MESH_NET_BUF_WARN_LOG_COMPRESSION


##### CONFIG_BLE_MESH_NET_BUF_ERR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_ERR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed > CONFIG_BLE_MESH_NET_BUF_ERR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_MESH_NET_BUF_ERR_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_NET_BUF_ERR_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_WARN_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_WARN_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed > CONFIG_BLE_MESH_NET_BUF_WARN_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_MESH_NET_BUF_WARN_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_NET_BUF_WARN_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_INFO_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_INFO_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed > CONFIG_BLE_MESH_NET_BUF_INFO_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_MESH_NET_BUF_INFO_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_MESH_NET_BUF_INFO_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed

- Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE > Select the net buf log tag to be compressed > CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_MESH_NET_BUF_DEBUG_LOG_COMPRESSION && CONFIG_BLE_MESH_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE

- No (disabled) if CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BT_BLUEDROID_ENABLED && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

- CONFIG_BLE_HOST_COMPRESSED_LOG_BUFFER_LEN
- Select the APPL layer log tag to be compressed
- Select the BTM layer log tag to be compressed
- Select the GAP layer log tag to be compressed
- Select the GATT layer log tag to be compressed
- Select the LA2CAP layer log tag to be compressed
- Select the SMP layer log tag to be compressed

CONFIG_BLE_HOST_COMPRESSED_LOG_BUFFER_LEN


##### CONFIG_BLE_HOST_COMPRESSED_LOG_BUFFER_LEN

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE

- 300 if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

300 if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the BTM layer log tag to be compressed

- CONFIG_BLE_BLUEDROID_BTM_API_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_BTM_API_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_COMPRESSION


##### CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed > CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_BTM_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed > CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_BTM_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed > CONFIG_BLE_BLUEDROID_BTM_API_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_BTM_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_BTM_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed > CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_BTM_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed > CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_BTM_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the BTM layer log tag to be compressed > CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_BTM_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the LA2CAP layer log tag to be compressed

- CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_COMPRESSION


##### CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_L2CAP_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_L2CAP_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the LA2CAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_L2CAP_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the GAP layer log tag to be compressed

- CONFIG_BLE_BLUEDROID_GAP_API_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GAP_API_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_COMPRESSION


##### CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_GAP_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_GAP_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GAP_API_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GAP_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GAP_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GAP_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GAP_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GAP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GAP_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the GATT layer log tag to be compressed

- CONFIG_BLE_BLUEDROID_GATT_API_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GATT_API_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION


##### CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_GATT_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_GATT_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GATT_API_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GATT_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GATT_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GATT_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GATT_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the GATT layer log tag to be compressed > CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_GATT_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the SMP layer log tag to be compressed

- CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_COMPRESSION


##### CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_SMP_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_SMP_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_SMP_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_SMP_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_SMP_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the SMP layer log tag to be compressed > CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_SMP_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### Select the APPL layer log tag to be compressed

- CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_COMPRESSION
- CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_COMPRESSION

CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_COMPRESSION


##### CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_APPL_ERROR_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_COMPRESSION

- Yes (enabled) if CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_BLUEDROID_APPL_WARNING_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_API_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_APPL_API_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_APPL_EVENT_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_APPL_DEBUG_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_COMPRESSION

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed

- Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

Yes (enabled) if CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_PRESERVE

Found in: Component config > Bluetooth > Common Options > BLE Log > CONFIG_BLE_LOG_ENABLED > Settings of BLE Log Compression > CONFIG_BLE_COMPRESSED_LOG_ENABLE > CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE > Select the APPL layer log tag to be compressed > CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_COMPRESSION

- No (disabled) if CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED

No (disabled) if CONFIG_BLE_BLUEDROID_APPL_VERBOSE_LOG_COMPRESSION && CONFIG_BLE_HOST_COMPRESSED_LOG_ENABLE && CONFIG_BLE_COMPRESSED_LOG_ENABLE && CONFIG_BLE_LOG_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

Found in: Component config > Bluetooth > Common Options

- No (disabled)


##### CONFIG_BT_BLE_LOG_SPI_OUT_UL_TASK_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- 512 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

512 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_HCI_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED

1024 if CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_HCI_TASK_CNT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED

- 1 if CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED

1 if CONFIG_BT_BLE_LOG_SPI_OUT_HCI_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_HOST_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED

1024 if CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_HOST_TASK_CNT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED

- 2 if CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED

2 if CONFIG_BT_BLE_LOG_SPI_OUT_HOST_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED && BT_LE_CONTROLLER_LOG_SPI_OUT_ENABLED

No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED && BT_LE_CONTROLLER_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LL_TASK_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

1024 if CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LL_ISR_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

- 512 if CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

512 if CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LL_HCI_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

- 512 if CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED

512 if CONFIG_BT_BLE_LOG_SPI_OUT_LL_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_MOSI_IO_NUM

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- 0 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

0 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_SCLK_IO_NUM

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- 1 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

1 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_CS_IO_NUM

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- 2 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

2 if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_TS_SYNC_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- Yes (enabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

Yes (enabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_SYNC_IO_NUM

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_TS_SYNC_ENABLED

- 3 if CONFIG_BT_BLE_LOG_SPI_OUT_TS_SYNC_ENABLED

3 if CONFIG_BT_BLE_LOG_SPI_OUT_TS_SYNC_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_FLUSH_TIMER_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_FLUSH_TIMEOUT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_FLUSH_TIMER_ENABLED

- 1000 if CONFIG_BT_BLE_LOG_SPI_OUT_FLUSH_TIMER_ENABLED

1000 if CONFIG_BT_BLE_LOG_SPI_OUT_FLUSH_TIMER_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED

1024 if CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_TASK_CNT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED

- 1 if CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED

1 if CONFIG_BT_BLE_LOG_SPI_OUT_LE_AUDIO_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

- No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED

No (disabled) if CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_MESH_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED

1024 if CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED


##### CONFIG_BT_BLE_LOG_SPI_OUT_MESH_TASK_CNT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_SPI_OUT_ENABLED > CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED

- 3 if CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED

3 if CONFIG_BT_BLE_LOG_SPI_OUT_MESH_ENABLED


##### CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

Found in: Component config > Bluetooth > Common Options

- No (disabled)


##### CONFIG_BT_BLE_LOG_UHCI_OUT_UART_PORT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

- 0 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

0 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_UHCI_OUT_LL_TASK_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

1024 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_UHCI_OUT_LL_ISR_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

1024 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_UHCI_OUT_LL_HCI_BUF_SIZE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

- 1024 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

1024 if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

- Yes (enabled) if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED

Yes (enabled) if CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED


##### CONFIG_BT_BLE_LOG_UHCI_OUT_UART_BAUD_RATE

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED > CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT

- 3000000 if CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT

3000000 if CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT


##### CONFIG_BT_BLE_LOG_UHCI_OUT_UART_IO_NUM_TX

Found in: Component config > Bluetooth > Common Options > CONFIG_BT_BLE_LOG_UHCI_OUT_ENABLED > CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT

- 0 if CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT

0 if CONFIG_BT_BLE_LOG_UHCI_OUT_UART_NEED_INIT


##### CONFIG_BT_LE_USED_MEM_STATISTICS_ENABLED

Found in: Component config > Bluetooth > Common Options

- No (disabled)


#### CONFIG_BT_HCI_LOG_DEBUG_EN

Found in: Component config > Bluetooth

- No (disabled) if CONFIG_BT_BLUEDROID_ENABLED || CONFIG_BT_NIMBLE_ENABLED

No (disabled) if CONFIG_BT_BLUEDROID_ENABLED || CONFIG_BT_NIMBLE_ENABLED


##### CONFIG_BT_HCI_LOG_DATA_BUFFER_SIZE

Found in: Component config > Bluetooth > CONFIG_BT_HCI_LOG_DEBUG_EN

- from 1 to 100 if CONFIG_BT_HCI_LOG_DEBUG_EN

from 1 to 100 if CONFIG_BT_HCI_LOG_DEBUG_EN

- 5 if CONFIG_BT_HCI_LOG_DEBUG_EN

5 if CONFIG_BT_HCI_LOG_DEBUG_EN


##### CONFIG_BT_HCI_LOG_ADV_BUFFER_SIZE

Found in: Component config > Bluetooth > CONFIG_BT_HCI_LOG_DEBUG_EN

- from 1 to 100 if CONFIG_BT_HCI_LOG_DEBUG_EN

from 1 to 100 if CONFIG_BT_HCI_LOG_DEBUG_EN

- 8 if CONFIG_BT_HCI_LOG_DEBUG_EN

8 if CONFIG_BT_HCI_LOG_DEBUG_EN


### CONFIG_BLE_MESH

Found in: Component config

CONFIG_BLE_MESH_GATT_PROXY_CLIENT

CONFIG_BLE_MESH_GATT_PROXY_SERVER

CONFIG_BLE_MESH_PROV

CONFIG_BLE_MESH_PROXY

CONFIG_BLE_MESH_NO_LOG

CONFIG_BLE_MESH_IVU_DIVIDER

CONFIG_BLE_MESH_FAST_PROV

CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC

CONFIG_BLE_MESH_EXPERIMENTAL

CONFIG_BLE_MESH_CRPL

CONFIG_BLE_MESH_RX_SDU_MAX

CONFIG_BLE_MESH_MODEL_KEY_COUNT

CONFIG_BLE_MESH_APP_KEY_COUNT

CONFIG_BLE_MESH_MODEL_GROUP_COUNT

CONFIG_BLE_MESH_LABEL_COUNT

CONFIG_BLE_MESH_SUBNET_COUNT

CONFIG_BLE_MESH_TX_SEG_MAX

CONFIG_BLE_MESH_RX_SEG_MSG_COUNT

CONFIG_BLE_MESH_TX_SEG_MSG_COUNT

CONFIG_BLE_MESH_MEM_ALLOC_MODE

CONFIG_BLE_MESH_MSG_CACHE_SIZE

CONFIG_BLE_MESH_NOT_RELAY_REPLAY_MSG

CONFIG_BLE_MESH_ADV_BUF_COUNT

CONFIG_BLE_MESH_PB_GATT

CONFIG_BLE_MESH_PB_ADV

CONFIG_BLE_MESH_IVU_RECOVERY_IVI

CONFIG_BLE_MESH_RELAY

CONFIG_BLE_MESH_SAR_ENHANCEMENT

CONFIG_BLE_MESH_SETTINGS

CONFIG_BLE_MESH_ACTIVE_SCAN

CONFIG_BLE_MESH_DEINIT

CONFIG_BLE_MESH_USE_DUPLICATE_SCAN

CONFIG_BLE_MESH_V11_SUPPORT

CONFIG_BLE_MESH_NODE

CONFIG_BLE_MESH_PROVISIONER

CONFIG_BLE_MESH_FRIEND

CONFIG_BLE_MESH_LOW_POWER

CONFIG_BLE_MESH_PROXY_CLI_SRV_COEXIST

CONFIG_BLE_MESH_HCI_5_0

CONFIG_BLE_MESH_USE_BLE_50

CONFIG_BLE_MESH_RANDOM_ADV_INTERVAL

CONFIG_BLE_MESH_IV_UPDATE_TEST

CONFIG_BLE_MESH_CLIENT_MSG_TIMEOUT

CONFIG_BLE_MESH_USE_UNIFIED_CRYPTO


#### CONFIG_BLE_MESH_HCI_5_0

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_V11_SUPPORT

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_RANDOM_ADV_INTERVAL

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_USE_UNIFIED_CRYPTO

Found in: Component config > CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_USE_BLE_50

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH_EXPERIMENTAL && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_EXPERIMENTAL && CONFIG_BLE_MESH

- CONFIG_BLE_MESH_EXT_ADV
- CONFIG_BLE_MESH_ADV_INST_ID
- CONFIG_BLE_MESH_SUPPORT_MULTI_ADV

CONFIG_BLE_MESH_EXT_ADV

CONFIG_BLE_MESH_ADV_INST_ID

CONFIG_BLE_MESH_SUPPORT_MULTI_ADV


##### CONFIG_BLE_MESH_EXT_ADV

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50

- No (disabled) if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

- CONFIG_BLE_MESH_LONG_PACKET
- CONFIG_BLE_MESH_EXT_ADV_BUF_COUNT
- CONFIG_BLE_MESH_EXT_RELAY_ADV_BUF_COUNT

CONFIG_BLE_MESH_LONG_PACKET

CONFIG_BLE_MESH_EXT_ADV_BUF_COUNT

CONFIG_BLE_MESH_EXT_RELAY_ADV_BUF_COUNT


##### CONFIG_BLE_MESH_EXT_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV

- from 6 to 256 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH

from 6 to 256 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH

- 60 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH

60 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_EXT_RELAY_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV

- from 0 to 256 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

from 0 to 256 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

- 60 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

60 if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LONG_PACKET

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV

- No (disabled) if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_EXT_ADV && CONFIG_BLE_MESH

- CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT
- CONFIG_BLE_MESH_LONG_PACKET_RELAY_ADV_BUF_COUNT
- CONFIG_BLE_MESH_LONG_PACKET_ADV_LEN
- CONFIG_BLE_MESH_LONG_PACKET_RX_SEG_CNT
- CONFIG_BLE_MESH_LONG_PACKET_TX_SEG_CNT

CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT

CONFIG_BLE_MESH_LONG_PACKET_RELAY_ADV_BUF_COUNT

CONFIG_BLE_MESH_LONG_PACKET_ADV_LEN

CONFIG_BLE_MESH_LONG_PACKET_RX_SEG_CNT

CONFIG_BLE_MESH_LONG_PACKET_TX_SEG_CNT


##### CONFIG_BLE_MESH_LONG_PACKET_ADV_LEN

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV > CONFIG_BLE_MESH_LONG_PACKET

- from 30 to 249 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

from 30 to 249 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

- 105 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

105 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV > CONFIG_BLE_MESH_LONG_PACKET

- 20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LONG_PACKET_RELAY_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV > CONFIG_BLE_MESH_LONG_PACKET

- 20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LONG_PACKET_TX_SEG_CNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV > CONFIG_BLE_MESH_LONG_PACKET

- from 1 to if CONFIG_BLE_MESH_TX_SEG_MAX < CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT && CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH
- from 1 to if CONFIG_BLE_MESH_TX_SEG_MAX >= CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT && CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

from 1 to if CONFIG_BLE_MESH_TX_SEG_MAX < CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT && CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

from 1 to if CONFIG_BLE_MESH_TX_SEG_MAX >= CONFIG_BLE_MESH_LONG_PACKET_ADV_BUF_COUNT && CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

- 20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LONG_PACKET_RX_SEG_CNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_EXT_ADV > CONFIG_BLE_MESH_LONG_PACKET

- from 1 to if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

from 1 to if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

- 20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH

20 if CONFIG_BLE_MESH_LONG_PACKET && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_ADV_INST_ID

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50

- from 0 to 3 if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

from 0 to 3 if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SUPPORT_MULTI_ADV

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50

- No (disabled) if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_USE_BLE_50 && CONFIG_BLE_MESH

- CONFIG_BLE_MESH_PROXY_ADV_INST_ID
- CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE
- CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE

CONFIG_BLE_MESH_PROXY_ADV_INST_ID

CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE

CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE


##### CONFIG_BLE_MESH_PROXY_ADV_INST_ID

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_SUPPORT_MULTI_ADV

- from 0 to 3 if CONFIG_BLE_MESH_PROXY && (CONFIG_BLE_MESH_PB_GATT || CONFIG_BLE_MESH_GATT_PROXY_SERVER) && CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH

from 0 to 3 if CONFIG_BLE_MESH_PROXY && (CONFIG_BLE_MESH_PB_GATT || CONFIG_BLE_MESH_GATT_PROXY_SERVER) && CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH_PROXY && (CONFIG_BLE_MESH_PB_GATT || CONFIG_BLE_MESH_GATT_PROXY_SERVER) && CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH_PROXY && (CONFIG_BLE_MESH_PB_GATT || CONFIG_BLE_MESH_GATT_PROXY_SERVER) && CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_SUPPORT_MULTI_ADV

- No (disabled) if CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH_RELAY_ADV_BUF && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH_RELAY_ADV_BUF && CONFIG_BLE_MESH

- CONFIG_BLE_MESH_RELAY_ADV_INST_ID

CONFIG_BLE_MESH_RELAY_ADV_INST_ID


##### CONFIG_BLE_MESH_RELAY_ADV_INST_ID

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_SUPPORT_MULTI_ADV > CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE

- from 0 to 3 if CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE && CONFIG_BLE_MESH

from 0 to 3 if CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_SEPARATE_RELAY_ADV_INSTANCE && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_SUPPORT_MULTI_ADV

- No (disabled) if CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH_SUPPORT_BLE_ADV && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_SUPPORT_MULTI_ADV && CONFIG_BLE_MESH_SUPPORT_BLE_ADV && CONFIG_BLE_MESH

- CONFIG_BLE_MESH_BLE_ADV_INST_ID

CONFIG_BLE_MESH_BLE_ADV_INST_ID


##### CONFIG_BLE_MESH_BLE_ADV_INST_ID

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_USE_BLE_50 > CONFIG_BLE_MESH_SUPPORT_MULTI_ADV > CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE

- from 0 to 3 if CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE && CONFIG_BLE_MESH

from 0 to 3 if CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE && CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_SEPARATE_BLE_ADV_INSTANCE && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_USE_DUPLICATE_SCAN

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_ACTIVE_SCAN

Found in: Component config > CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_MEM_ALLOC_MODE

Found in: Component config > CONFIG_BLE_MESH

- Internal DRAM memory only
- External SPIRAM memory only
- Either internal or external memory based on default malloc() behavior in ESP-IDF
- Internal IRAM memory wherever applicable else internal DRAM

Available options:

- Internal DRAM (CONFIG_BLE_MESH_MEM_ALLOC_MODE_INTERNAL)
- External SPIRAM (CONFIG_BLE_MESH_MEM_ALLOC_MODE_EXTERNAL)
- Default alloc mode (CONFIG_BLE_MESH_MEM_ALLOC_MODE_DEFAULT) Enable this option to use the default memory allocation strategy when external SPIRAM is enabled. See the SPIRAM options for more details.
- Internal IRAM (CONFIG_BLE_MESH_MEM_ALLOC_MODE_IRAM_8BIT) Allows to use IRAM memory region as 8bit accessible region. Every unaligned (8bit or 16bit) access will result in an exception and incur penalty of certain clock cycles per unaligned read/write.

Internal DRAM (CONFIG_BLE_MESH_MEM_ALLOC_MODE_INTERNAL)

External SPIRAM (CONFIG_BLE_MESH_MEM_ALLOC_MODE_EXTERNAL)

Default alloc mode (CONFIG_BLE_MESH_MEM_ALLOC_MODE_DEFAULT)

Internal IRAM (CONFIG_BLE_MESH_MEM_ALLOC_MODE_IRAM_8BIT)


#### CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if ESP32_IRAM_AS_8BIT_ACCESSIBLE_MEMORY && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_MODE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC

Available options:

- External SPIRAM (CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_EXTERNAL) If enabled, BLE Mesh allocates dynamic memory from external SPIRAM for FreeRTOS objects, i.e. mutex, queue, and task stack. External SPIRAM can only be used for task stack when SPIRAM_ALLOW_STACK_EXTERNAL_MEMORY is enabled. See the SPIRAM options for more details.
- Internal IRAM (CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_IRAM_8BIT) If enabled, BLE Mesh allocates dynamic memory from internal IRAM for FreeRTOS objects, i.e. mutex, queue. Note: IRAM region cannot be used as task stack.

External SPIRAM (CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_EXTERNAL)

Internal IRAM (CONFIG_BLE_MESH_FREERTOS_STATIC_ALLOC_IRAM_8BIT)


#### CONFIG_BLE_MESH_DEINIT

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


#### BLE Mesh and BLE coexistence support

- CONFIG_BLE_MESH_SUPPORT_BLE_SCAN
- CONFIG_BLE_MESH_SUPPORT_BLE_ADV

CONFIG_BLE_MESH_SUPPORT_BLE_SCAN

CONFIG_BLE_MESH_SUPPORT_BLE_ADV


##### CONFIG_BLE_MESH_SUPPORT_BLE_ADV

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh and BLE coexistence support

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BLE_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh and BLE coexistence support > CONFIG_BLE_MESH_SUPPORT_BLE_ADV

- from 1 to 255 if CONFIG_BLE_MESH_SUPPORT_BLE_ADV && CONFIG_BLE_MESH

from 1 to 255 if CONFIG_BLE_MESH_SUPPORT_BLE_ADV && CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH_SUPPORT_BLE_ADV && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_SUPPORT_BLE_ADV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SUPPORT_BLE_SCAN

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh and BLE coexistence support

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_FAST_PROV

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_NODE

Found in: Component config > CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_PROVISIONER

Found in: Component config > CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_WAIT_FOR_PROV_MAX_DEV_NUM

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- from 1 to 100 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 100 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MAX_PROV_NODES

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- from 1 to 1000 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 1000 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PBA_SAME_TIME

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- from 1 to 10 if CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 10 if CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PBG_SAME_TIME

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- from 1 to 5 if CONFIG_BLE_MESH_PB_GATT && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 5 if CONFIG_BLE_MESH_PB_GATT && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH_PB_GATT && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH_PB_GATT && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROVISIONER_SUBNET_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- from 1 to 4096 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 4096 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROVISIONER_APP_KEY_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- from 1 to 4096 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 4096 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROVISIONER_RECV_HB

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER

- No (disabled) if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROVISIONER_RECV_HB_FILTER_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROVISIONER > CONFIG_BLE_MESH_PROVISIONER_RECV_HB

- from 1 to 1000 if CONFIG_BLE_MESH_PROVISIONER_RECV_HB && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

from 1 to 1000 if CONFIG_BLE_MESH_PROVISIONER_RECV_HB && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH_PROVISIONER_RECV_HB && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_PROVISIONER_RECV_HB && CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_PROV

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROV_EPA

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROV

- Yes (enabled) if CONFIG_BLE_MESH_PROV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_PROV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_CERT_BASED_PROV

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROV

- No (disabled) if CONFIG_BLE_MESH_PROV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_PROV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RECORD_FRAG_MAX_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PROV > CONFIG_BLE_MESH_CERT_BASED_PROV

- from 1 to 57 if CONFIG_BLE_MESH_CERT_BASED_PROV && CONFIG_BLE_MESH

from 1 to 57 if CONFIG_BLE_MESH_CERT_BASED_PROV && CONFIG_BLE_MESH

- 56 if CONFIG_BLE_MESH_CERT_BASED_PROV && CONFIG_BLE_MESH

56 if CONFIG_BLE_MESH_CERT_BASED_PROV && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_PB_ADV

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_UNPROVISIONED_BEACON_INTERVAL

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_PB_ADV

- from 1 to 100 if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH

from 1 to 100 if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH

- 5 if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH
- 3 if CONFIG_BLE_MESH_FAST_PROV && CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH

5 if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_FAST_PROV && CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_PB_ADV && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_PB_GATT

Found in: Component config > CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_PROXY

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_GATT_PROXY_SERVER

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_NODE_ID_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_SERVER

- from 1 to 60 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

from 1 to 60 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

- 60 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

60 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROXY_FILTER_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_SERVER

- from 1 to 32767 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

from 1 to 32767 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

- 4 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

4 if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROXY_PRIVACY

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_SERVER

- Yes (enabled) if CONFIG_BLE_MESH_PRB_SRV && CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_PRB_SRV && CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROXY_SOLIC_PDU_RX

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_SERVER


##### CONFIG_BLE_MESH_PROXY_SOLIC_RX_CRPL

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_SERVER > CONFIG_BLE_MESH_PROXY_SOLIC_PDU_RX

- from 1 to 65536 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_RX && CONFIG_BLE_MESH

from 1 to 65536 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_RX && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_RX && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_RX && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_PROXY_CLI_SRV_COEXIST

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH_EXPERIMENTAL && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_EXPERIMENTAL && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_GATT_PROXY_CLIENT

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PROXY_SOLIC_PDU_TX

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_CLIENT


##### CONFIG_BLE_MESH_PROXY_SOLIC_TX_SRC_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_GATT_PROXY_CLIENT > CONFIG_BLE_MESH_PROXY_SOLIC_PDU_TX

- from 1 to 16 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_TX && CONFIG_BLE_MESH

from 1 to 16 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_TX && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_TX && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_PROXY_SOLIC_PDU_TX && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_SETTINGS

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_STORE_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- from 0 to 1000000 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

from 0 to 1000000 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SEQ_STORE_RATE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- from 0 to 1000000 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

from 0 to 1000000 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RPL_STORE_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- from 0 to 1000000 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

from 0 to 1000000 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SETTINGS_BACKWARD_COMPATIBILITY

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- No (disabled) if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SPECIFIC_PARTITION

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- No (disabled) if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PARTITION_NAME

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS > CONFIG_BLE_MESH_SPECIFIC_PARTITION

- "ble_mesh" if CONFIG_BLE_MESH_SPECIFIC_PARTITION && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

"ble_mesh" if CONFIG_BLE_MESH_SPECIFIC_PARTITION && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS

- No (disabled) if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_PROVISIONER && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MAX_NVS_NAMESPACE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_SETTINGS > CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE

- from 1 to 255 if CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

from 1 to 255 if CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_USE_MULTIPLE_NAMESPACE && CONFIG_BLE_MESH_SETTINGS && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_SUBNET_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 1 to 4096 if CONFIG_BLE_MESH

from 1 to 4096 if CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_APP_KEY_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 1 to 4096 if CONFIG_BLE_MESH

from 1 to 4096 if CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_MODEL_KEY_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 1 to 4096 if CONFIG_BLE_MESH

from 1 to 4096 if CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_MODEL_GROUP_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 1 to 4096 if CONFIG_BLE_MESH

from 1 to 4096 if CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_LABEL_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 0 to 4096 if CONFIG_BLE_MESH

from 0 to 4096 if CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_CRPL

Found in: Component config > CONFIG_BLE_MESH

- from 2 to 65535 if CONFIG_BLE_MESH

from 2 to 65535 if CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_NOT_RELAY_REPLAY_MSG

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH_EXPERIMENTAL && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_EXPERIMENTAL && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_MSG_CACHE_SIZE

Found in: Component config > CONFIG_BLE_MESH

- from 2 to 65535 if CONFIG_BLE_MESH

from 2 to 65535 if CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 6 to 256 if CONFIG_BLE_MESH

from 6 to 256 if CONFIG_BLE_MESH

- 60 if CONFIG_BLE_MESH

60 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_IVU_DIVIDER

Found in: Component config > CONFIG_BLE_MESH

- from 2 to 96 if CONFIG_BLE_MESH

from 2 to 96 if CONFIG_BLE_MESH

- 4 if CONFIG_BLE_MESH

4 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_IVU_RECOVERY_IVI

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_SAR_ENHANCEMENT

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_TX_SEG_MSG_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 1 to if CONFIG_BLE_MESH

from 1 to if CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_RX_SEG_MSG_COUNT

Found in: Component config > CONFIG_BLE_MESH

- from 1 to 255 if CONFIG_BLE_MESH

from 1 to 255 if CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_RX_SDU_MAX

Found in: Component config > CONFIG_BLE_MESH

- from 36 to 384 if CONFIG_BLE_MESH

from 36 to 384 if CONFIG_BLE_MESH

- 384 if CONFIG_BLE_MESH

384 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_TX_SEG_MAX

Found in: Component config > CONFIG_BLE_MESH

- from 2 to 32 if CONFIG_BLE_MESH

from 2 to 32 if CONFIG_BLE_MESH

- 32 if CONFIG_BLE_MESH

32 if CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_RELAY

Found in: Component config > CONFIG_BLE_MESH

- Yes (enabled) if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_NODE && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RELAY_ADV_BUF

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_RELAY

- No (disabled) if CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RELAY_ADV_BUF_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_RELAY > CONFIG_BLE_MESH_RELAY_ADV_BUF

- from 6 to 256 if CONFIG_BLE_MESH_RELAY_ADV_BUF && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

from 6 to 256 if CONFIG_BLE_MESH_RELAY_ADV_BUF && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

- 60 if CONFIG_BLE_MESH_RELAY_ADV_BUF && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH

60 if CONFIG_BLE_MESH_RELAY_ADV_BUF && CONFIG_BLE_MESH_RELAY && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_LOW_POWER

Found in: Component config > CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_ESTABLISHMENT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- No (disabled) if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_AUTO

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- No (disabled) if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_AUTO_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER > CONFIG_BLE_MESH_LPN_AUTO

- from 0 to 3600 if CONFIG_BLE_MESH_LPN_AUTO && CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 0 to 3600 if CONFIG_BLE_MESH_LPN_AUTO && CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 15 if CONFIG_BLE_MESH_LPN_AUTO && CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

15 if CONFIG_BLE_MESH_LPN_AUTO && CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_RETRY_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 1 to 3600 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 1 to 3600 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 6 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

6 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_RSSI_FACTOR

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 0 to 3 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 0 to 3 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_RECV_WIN_FACTOR

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 0 to 3 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 0 to 3 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_MIN_QUEUE_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 1 to 7 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 1 to 7 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_RECV_DELAY

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 10 to 255 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 10 to 255 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 100 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

100 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_POLL_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 10 to 244735 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 10 to 244735 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 300 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

300 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_INIT_POLL_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 10 to if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 10 to if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_SCAN_LATENCY

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 0 to 50 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 0 to 50 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_GROUPS

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- from 0 to 16384 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

from 0 to 16384 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

- 8 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

8 if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LPN_SUB_ALL_NODES_ADDR

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_LOW_POWER

- No (disabled) if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_LOW_POWER && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_FRIEND

Found in: Component config > CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_FRIEND_RECV_WIN

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FRIEND

- from 1 to 255 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

from 1 to 255 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

- 255 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

255 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_FRIEND_QUEUE_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FRIEND

- from 2 to 65536 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

from 2 to 65536 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

- 16 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

16 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_FRIEND_SUB_LIST_SIZE

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FRIEND

- from 0 to 1023 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

from 0 to 1023 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

- 3 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

3 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_FRIEND_LPN_COUNT

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FRIEND

- from 1 to 1000 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

from 1 to 1000 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_FRIEND_SEG_RX

Found in: Component config > CONFIG_BLE_MESH > CONFIG_BLE_MESH_FRIEND

- from 1 to 1000 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

from 1 to 1000 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH_FRIEND && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_NO_LOG

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH && CONFIG_BLE_MESH


#### BLE Mesh STACK DEBUG LOG LEVEL

- CONFIG_BLE_MESH_STACK_TRACE_LEVEL

CONFIG_BLE_MESH_STACK_TRACE_LEVEL


##### CONFIG_BLE_MESH_STACK_TRACE_LEVEL

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh STACK DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BLE_MESH_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BLE_MESH_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BLE_MESH_TRACE_LEVEL_WARNING)
- INFO (CONFIG_BLE_MESH_TRACE_LEVEL_INFO)
- DEBUG (CONFIG_BLE_MESH_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BLE_MESH_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BLE_MESH_TRACE_LEVEL_NONE)

ERROR (CONFIG_BLE_MESH_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BLE_MESH_TRACE_LEVEL_WARNING)

INFO (CONFIG_BLE_MESH_TRACE_LEVEL_INFO)

DEBUG (CONFIG_BLE_MESH_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BLE_MESH_TRACE_LEVEL_VERBOSE)


#### BLE Mesh NET BUF DEBUG LOG LEVEL

- CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL

CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL


##### CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh NET BUF DEBUG LOG LEVEL

Available options:

- NONE (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_NONE)
- ERROR (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_ERROR)
- WARNING (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_WARNING)
- INFO (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_INFO)
- DEBUG (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_DEBUG)
- VERBOSE (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_VERBOSE)

NONE (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_NONE)

ERROR (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_ERROR)

WARNING (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_WARNING)

INFO (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_INFO)

DEBUG (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_DEBUG)

VERBOSE (CONFIG_BLE_MESH_NET_BUF_TRACE_LEVEL_VERBOSE)


#### CONFIG_BLE_MESH_CLIENT_MSG_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH

- from 100 to 1200000 if CONFIG_BLE_MESH

from 100 to 1200000 if CONFIG_BLE_MESH

- 4000 if CONFIG_BLE_MESH

4000 if CONFIG_BLE_MESH


#### Support for BLE Mesh Foundation models

- CONFIG_BLE_MESH_BRC_CLI
- CONFIG_BLE_MESH_BRC_SRV
- CONFIG_BLE_MESH_CFG_CLI
- CONFIG_BLE_MESH_DF_CLI
- CONFIG_BLE_MESH_DF_SRV
- CONFIG_BLE_MESH_HEALTH_CLI
- CONFIG_BLE_MESH_HEALTH_SRV
- CONFIG_BLE_MESH_LCD_CLI
- CONFIG_BLE_MESH_LCD_SRV
- CONFIG_BLE_MESH_PRB_CLI
- CONFIG_BLE_MESH_PRB_SRV
- CONFIG_BLE_MESH_ODP_CLI
- CONFIG_BLE_MESH_ODP_SRV
- CONFIG_BLE_MESH_AGG_CLI
- CONFIG_BLE_MESH_AGG_SRV
- CONFIG_BLE_MESH_RPR_CLI
- CONFIG_BLE_MESH_RPR_SRV
- CONFIG_BLE_MESH_SAR_CLI
- CONFIG_BLE_MESH_SAR_SRV
- CONFIG_BLE_MESH_SRPL_CLI
- CONFIG_BLE_MESH_SRPL_SRV
- CONFIG_BLE_MESH_COMP_DATA_1
- CONFIG_BLE_MESH_COMP_DATA_128
- CONFIG_BLE_MESH_MODELS_METADATA_0

CONFIG_BLE_MESH_BRC_CLI

CONFIG_BLE_MESH_BRC_SRV

CONFIG_BLE_MESH_CFG_CLI

CONFIG_BLE_MESH_DF_CLI

CONFIG_BLE_MESH_DF_SRV

CONFIG_BLE_MESH_HEALTH_CLI

CONFIG_BLE_MESH_HEALTH_SRV

CONFIG_BLE_MESH_LCD_CLI

CONFIG_BLE_MESH_LCD_SRV

CONFIG_BLE_MESH_PRB_CLI

CONFIG_BLE_MESH_PRB_SRV

CONFIG_BLE_MESH_ODP_CLI

CONFIG_BLE_MESH_ODP_SRV

CONFIG_BLE_MESH_AGG_CLI

CONFIG_BLE_MESH_AGG_SRV

CONFIG_BLE_MESH_RPR_CLI

CONFIG_BLE_MESH_RPR_SRV

CONFIG_BLE_MESH_SAR_CLI

CONFIG_BLE_MESH_SAR_SRV

CONFIG_BLE_MESH_SRPL_CLI

CONFIG_BLE_MESH_SRPL_SRV

CONFIG_BLE_MESH_COMP_DATA_1

CONFIG_BLE_MESH_COMP_DATA_128

CONFIG_BLE_MESH_MODELS_METADATA_0


##### CONFIG_BLE_MESH_CFG_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_HEALTH_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_HEALTH_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BRC_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_BRC_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models

- No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MAX_BRIDGING_TABLE_ENTRY_COUNT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_BRC_SRV

- from 16 to 65535 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 16 to 65535 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 16 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

16 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BRIDGE_CRPL

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_BRC_SRV

- from 1 to 255 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 1 to 255 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 5 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

5 if CONFIG_BLE_MESH_BRC_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PRB_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_PRB_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_ODP_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_ODP_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_SRPL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_SRPL_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_AGG_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_AGG_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_SAR_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_SAR_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_COMP_DATA_1

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_COMP_DATA_128

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_MODELS_METADATA_0

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_MODELS_METADATA_128

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_MODELS_METADATA_0


##### CONFIG_BLE_MESH_LCD_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_LCD_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_RPR_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_RPR_CLI_PROV_SAME_TIME

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_RPR_CLI

- from 1 to 5 if CONFIG_BLE_MESH_RPR_CLI && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 1 to 5 if CONFIG_BLE_MESH_RPR_CLI && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_RPR_CLI && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_RPR_CLI && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RPR_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_RPR_SRV_MAX_SCANNED_ITEMS

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_RPR_SRV

- from 4 to 255 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 4 to 255 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RPR_SRV_ACTIVE_SCAN

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_RPR_SRV


##### CONFIG_BLE_MESH_RPR_SRV_MAX_EXT_SCAN

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_RPR_SRV

- from 1 to 10 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 1 to 10 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH_RPR_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DF_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_DF_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models


##### CONFIG_BLE_MESH_MAX_DISC_TABLE_ENTRY_COUNT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_DF_SRV

- from 2 to 255 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 2 to 255 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MAX_FORWARD_TABLE_ENTRY_COUNT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_DF_SRV

- from 2 to 64 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 2 to 64 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MAX_DEPS_NODES_PER_PATH

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_DF_SRV

- from 2 to 64 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

from 2 to 64 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_PATH_MONITOR_TEST

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_DF_SRV

- No (disabled) if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SUPPORT_DIRECTED_PROXY

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Foundation models > CONFIG_BLE_MESH_DF_SRV

- Yes (enabled) if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_GATT_PROXY_SERVER && CONFIG_BLE_MESH_DF_SRV && CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


#### Support for BLE Mesh Client/Server models

- Binary Larger Object Transfer model
- CONFIG_BLE_MESH_MBT_CLI
- CONFIG_BLE_MESH_MBT_SRV
- Device Firmware Update model
- CONFIG_BLE_MESH_GENERIC_BATTERY_CLI
- CONFIG_BLE_MESH_GENERIC_DEF_TRANS_TIME_CLI
- CONFIG_BLE_MESH_GENERIC_LEVEL_CLI
- CONFIG_BLE_MESH_GENERIC_LOCATION_CLI
- CONFIG_BLE_MESH_GENERIC_ONOFF_CLI
- CONFIG_BLE_MESH_GENERIC_POWER_LEVEL_CLI
- CONFIG_BLE_MESH_GENERIC_POWER_ONOFF_CLI
- CONFIG_BLE_MESH_GENERIC_PROPERTY_CLI
- CONFIG_BLE_MESH_GENERIC_SERVER
- CONFIG_BLE_MESH_LIGHT_CTL_CLI
- CONFIG_BLE_MESH_LIGHT_HSL_CLI
- CONFIG_BLE_MESH_LIGHT_LC_CLI
- CONFIG_BLE_MESH_LIGHT_LIGHTNESS_CLI
- CONFIG_BLE_MESH_LIGHT_XYL_CLI
- CONFIG_BLE_MESH_LIGHTING_SERVER
- CONFIG_BLE_MESH_SCENE_CLI
- CONFIG_BLE_MESH_SCHEDULER_CLI
- CONFIG_BLE_MESH_SENSOR_CLI
- CONFIG_BLE_MESH_SENSOR_SERVER
- CONFIG_BLE_MESH_TIME_SCENE_SERVER
- CONFIG_BLE_MESH_TIME_CLI

CONFIG_BLE_MESH_MBT_CLI

CONFIG_BLE_MESH_MBT_SRV

CONFIG_BLE_MESH_GENERIC_BATTERY_CLI

CONFIG_BLE_MESH_GENERIC_DEF_TRANS_TIME_CLI

CONFIG_BLE_MESH_GENERIC_LEVEL_CLI

CONFIG_BLE_MESH_GENERIC_LOCATION_CLI

CONFIG_BLE_MESH_GENERIC_ONOFF_CLI

CONFIG_BLE_MESH_GENERIC_POWER_LEVEL_CLI

CONFIG_BLE_MESH_GENERIC_POWER_ONOFF_CLI

CONFIG_BLE_MESH_GENERIC_PROPERTY_CLI

CONFIG_BLE_MESH_GENERIC_SERVER

CONFIG_BLE_MESH_LIGHT_CTL_CLI

CONFIG_BLE_MESH_LIGHT_HSL_CLI

CONFIG_BLE_MESH_LIGHT_LC_CLI

CONFIG_BLE_MESH_LIGHT_LIGHTNESS_CLI

CONFIG_BLE_MESH_LIGHT_XYL_CLI

CONFIG_BLE_MESH_LIGHTING_SERVER

CONFIG_BLE_MESH_SCENE_CLI

CONFIG_BLE_MESH_SCHEDULER_CLI

CONFIG_BLE_MESH_SENSOR_CLI

CONFIG_BLE_MESH_SENSOR_SERVER

CONFIG_BLE_MESH_TIME_SCENE_SERVER

CONFIG_BLE_MESH_TIME_CLI


##### CONFIG_BLE_MESH_GENERIC_ONOFF_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_LEVEL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_DEF_TRANS_TIME_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_POWER_ONOFF_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_POWER_LEVEL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_BATTERY_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_LOCATION_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_PROPERTY_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_SENSOR_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_TIME_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_SCENE_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_SCHEDULER_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_LIGHT_LIGHTNESS_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_LIGHT_CTL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_LIGHT_HSL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_LIGHT_XYL_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_LIGHT_LC_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models


##### CONFIG_BLE_MESH_GENERIC_SERVER

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SENSOR_SERVER

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_TIME_SCENE_SERVER

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_LIGHTING_SERVER

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MBT_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

- No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MAX_BLOB_RECEIVERS

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > CONFIG_BLE_MESH_MBT_CLI

- from 1 to 255 if CONFIG_BLE_MESH_MBT_CLI && CONFIG_BLE_MESH

from 1 to 255 if CONFIG_BLE_MESH_MBT_CLI && CONFIG_BLE_MESH

- 2 if CONFIG_BLE_MESH_MBT_CLI && CONFIG_BLE_MESH

2 if CONFIG_BLE_MESH_MBT_CLI && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_MBT_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models

- No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_V11_SUPPORT && CONFIG_BLE_MESH


##### Binary Larger Object Transfer model

- BLOB models common configuration
- CONFIG_BLE_MESH_BLOB_CLI
- CONFIG_BLE_MESH_BLOB_SRV

CONFIG_BLE_MESH_BLOB_CLI

CONFIG_BLE_MESH_BLOB_SRV


##### CONFIG_BLE_MESH_BLOB_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model


##### CONFIG_BLE_MESH_BLOB_SRV_PULL_REQ_COUNT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_SRV

- from 1 to 16 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

from 1 to 16 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

- 4 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

4 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BLOB_SIZE_MAX

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_SRV

- from 1 to 3257617792 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

from 1 to 3257617792 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

- 524288 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

524288 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BLOB_BLOCK_SIZE_MIN

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_SRV

- from 64 to 1048576 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

from 64 to 1048576 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

- 4096 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

4096 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BLOB_BLOCK_SIZE_MAX

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_SRV

- from to 1048576 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

from to 1048576 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

- 4096 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

4096 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BLOB_REPORT_TIMEOUT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_SRV

- from 1 to 31 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

from 1 to 31 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

- 10 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH

10 if CONFIG_BLE_MESH_BLOB_SRV && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_RX_BLOB_CHUNK_SIZE

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_SRV


##### CONFIG_BLE_MESH_BLOB_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model


##### CONFIG_BLE_MESH_BLOB_CLI_BLOCK_RETRIES

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_CLI

- 5 if CONFIG_BLE_MESH_BLOB_CLI && CONFIG_BLE_MESH

5 if CONFIG_BLE_MESH_BLOB_CLI && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_TX_BLOB_CHUNK_SIZE

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_CLI


##### CONFIG_BLE_MESH_TX_BLOB_CHUNK_SEND_INTERVAL

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > CONFIG_BLE_MESH_BLOB_CLI

- from 0 to 2147483647 if CONFIG_BLE_MESH_BLOB_CLI && CONFIG_BLE_MESH

from 0 to 2147483647 if CONFIG_BLE_MESH_BLOB_CLI && CONFIG_BLE_MESH

- 0 if CONFIG_BLE_MESH_BLOB_CLI && CONFIG_BLE_MESH

0 if CONFIG_BLE_MESH_BLOB_CLI && CONFIG_BLE_MESH


##### BLOB models common configuration

- CONFIG_BLE_MESH_ALIGN_CHUNK_SIZE_TO_MAX_SEGMENT
- CONFIG_BLE_MESH_BLOB_CHUNK_COUNT_MAX

CONFIG_BLE_MESH_ALIGN_CHUNK_SIZE_TO_MAX_SEGMENT

CONFIG_BLE_MESH_BLOB_CHUNK_COUNT_MAX


##### CONFIG_BLE_MESH_BLOB_CHUNK_COUNT_MAX

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > BLOB models common configuration

- from 1 to 2992 if CONFIG_BLE_MESH

from 1 to 2992 if CONFIG_BLE_MESH

- 256 if CONFIG_BLE_MESH

256 if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_ALIGN_CHUNK_SIZE_TO_MAX_SEGMENT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Binary Larger Object Transfer model > BLOB models common configuration

- Yes (enabled) if CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH


##### Device Firmware Update model

- CONFIG_BLE_MESH_DFU_SLOTS
- Firmware Update model configuration
- CONFIG_BLE_MESH_DFU_CLI
- CONFIG_BLE_MESH_DFU_SRV

CONFIG_BLE_MESH_DFU_SLOTS

CONFIG_BLE_MESH_DFU_CLI

CONFIG_BLE_MESH_DFU_SRV


##### CONFIG_BLE_MESH_DFU_SRV

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model


##### CONFIG_BLE_MESH_DFU_CLI

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model


##### Firmware Update model configuration

- CONFIG_BLE_MESH_DFU_FWID_MAXLEN
- CONFIG_BLE_MESH_DFU_METADATA_MAXLEN
- CONFIG_BLE_MESH_DFU_URI_MAXLEN
- CONFIG_BLE_MESH_DFU_METADATA

CONFIG_BLE_MESH_DFU_FWID_MAXLEN

CONFIG_BLE_MESH_DFU_METADATA_MAXLEN

CONFIG_BLE_MESH_DFU_URI_MAXLEN

CONFIG_BLE_MESH_DFU_METADATA


##### CONFIG_BLE_MESH_DFU_FWID_MAXLEN

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model > Firmware Update model configuration

- from 0 to 106 if CONFIG_BLE_MESH

from 0 to 106 if CONFIG_BLE_MESH

- 16 if CONFIG_BLE_MESH

16 if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DFU_METADATA_MAXLEN

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model > Firmware Update model configuration

- from 18 to 255 if CONFIG_BLE_MESH_DFU_METADATA && CONFIG_BLE_MESH
- from 0 to 255 if CONFIG_BLE_MESH

from 18 to 255 if CONFIG_BLE_MESH_DFU_METADATA && CONFIG_BLE_MESH

from 0 to 255 if CONFIG_BLE_MESH

- 32 if CONFIG_BLE_MESH

32 if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DFU_METADATA

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model > Firmware Update model configuration


##### CONFIG_BLE_MESH_DFU_URI_MAXLEN

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model > Firmware Update model configuration

- from 0 to 255 if CONFIG_BLE_MESH

from 0 to 255 if CONFIG_BLE_MESH

- 32 if CONFIG_BLE_MESH

32 if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DFU_SLOTS

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model

- Yes (enabled) if CONFIG_BLE_MESH_DFU_CLI && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_DFU_CLI && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DFU_SLOT_CNT

Found in: Component config > CONFIG_BLE_MESH > Support for BLE Mesh Client/Server models > Device Firmware Update model > CONFIG_BLE_MESH_DFU_SLOTS

- from 1 to 32767 if CONFIG_BLE_MESH_DFU_SLOTS && CONFIG_BLE_MESH

from 1 to 32767 if CONFIG_BLE_MESH_DFU_SLOTS && CONFIG_BLE_MESH

- 1 if CONFIG_BLE_MESH_DFU_SLOTS && CONFIG_BLE_MESH

1 if CONFIG_BLE_MESH_DFU_SLOTS && CONFIG_BLE_MESH


#### CONFIG_BLE_MESH_IV_UPDATE_TEST

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


#### BLE Mesh specific test option

- CONFIG_BLE_MESH_DEBUG
- CONFIG_BLE_MESH_SHELL
- CONFIG_BLE_MESH_BQB_TEST
- CONFIG_BLE_MESH_SELF_TEST
- CONFIG_BLE_MESH_TEST_AUTO_ENTER_NETWORK
- CONFIG_BLE_MESH_TEST_USE_WHITE_LIST

CONFIG_BLE_MESH_DEBUG

CONFIG_BLE_MESH_SHELL

CONFIG_BLE_MESH_BQB_TEST

CONFIG_BLE_MESH_SELF_TEST

CONFIG_BLE_MESH_TEST_AUTO_ENTER_NETWORK

CONFIG_BLE_MESH_TEST_USE_WHITE_LIST


##### CONFIG_BLE_MESH_SELF_TEST

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_BQB_TEST

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_TEST_AUTO_ENTER_NETWORK

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option

- Yes (enabled) if CONFIG_BLE_MESH_SELF_TEST && CONFIG_BLE_MESH

Yes (enabled) if CONFIG_BLE_MESH_SELF_TEST && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_TEST_USE_WHITE_LIST

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option

- No (disabled) if CONFIG_BLE_MESH_SELF_TEST && CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH_SELF_TEST && CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_SHELL

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DEBUG

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


##### CONFIG_BLE_MESH_DEBUG_NET

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_TRANS

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_BEACON

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_CRYPTO

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_PROV

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_ACCESS

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_MODEL

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_ADV

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_LOW_POWER

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_FRIEND

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


##### CONFIG_BLE_MESH_DEBUG_PROXY

Found in: Component config > CONFIG_BLE_MESH > BLE Mesh specific test option > CONFIG_BLE_MESH_DEBUG


#### CONFIG_BLE_MESH_EXPERIMENTAL

Found in: Component config > CONFIG_BLE_MESH

- No (disabled) if CONFIG_BLE_MESH

No (disabled) if CONFIG_BLE_MESH


### Console Library

- CONFIG_CONSOLE_SORTED_HELP

CONFIG_CONSOLE_SORTED_HELP


#### CONFIG_CONSOLE_SORTED_HELP

Found in: Component config > Console Library

- No (disabled)


### Legacy Driver Configurations

- Legacy I2C Driver Configurations
- Legacy Touch Sensor Driver Configurations
- Legacy TWAI Driver Configurations


#### Legacy TWAI Driver Configurations

- CONFIG_TWAI_ISR_IN_IRAM_LEGACY
- CONFIG_TWAI_SKIP_LEGACY_CONFLICT_CHECK
- CONFIG_TWAI_SUPPRESS_DEPRECATE_WARN

CONFIG_TWAI_ISR_IN_IRAM_LEGACY

CONFIG_TWAI_SKIP_LEGACY_CONFLICT_CHECK

CONFIG_TWAI_SUPPRESS_DEPRECATE_WARN


##### CONFIG_TWAI_ISR_IN_IRAM_LEGACY

Found in: Component config > Legacy Driver Configurations > Legacy TWAI Driver Configurations

- No (disabled)


##### CONFIG_TWAI_SUPPRESS_DEPRECATE_WARN

Found in: Component config > Legacy Driver Configurations > Legacy TWAI Driver Configurations

- No (disabled)


##### CONFIG_TWAI_SKIP_LEGACY_CONFLICT_CHECK

Found in: Component config > Legacy Driver Configurations > Legacy TWAI Driver Configurations

- No (disabled)


#### Legacy I2C Driver Configurations

- CONFIG_I2C_SKIP_LEGACY_CONFLICT_CHECK
- CONFIG_I2C_SUPPRESS_DEPRECATE_WARN

CONFIG_I2C_SKIP_LEGACY_CONFLICT_CHECK

CONFIG_I2C_SUPPRESS_DEPRECATE_WARN


##### CONFIG_I2C_SUPPRESS_DEPRECATE_WARN

Found in: Component config > Legacy Driver Configurations > Legacy I2C Driver Configurations

- No (disabled)


##### CONFIG_I2C_SKIP_LEGACY_CONFLICT_CHECK

Found in: Component config > Legacy Driver Configurations > Legacy I2C Driver Configurations

- No (disabled)


#### Legacy Touch Sensor Driver Configurations

- CONFIG_TOUCH_SKIP_LEGACY_CONFLICT_CHECK
- CONFIG_TOUCH_SUPPRESS_DEPRECATE_WARN

CONFIG_TOUCH_SKIP_LEGACY_CONFLICT_CHECK

CONFIG_TOUCH_SUPPRESS_DEPRECATE_WARN


##### CONFIG_TOUCH_SUPPRESS_DEPRECATE_WARN

Found in: Component config > Legacy Driver Configurations > Legacy Touch Sensor Driver Configurations

- No (disabled)


##### CONFIG_TOUCH_SKIP_LEGACY_CONFLICT_CHECK

Found in: Component config > Legacy Driver Configurations > Legacy Touch Sensor Driver Configurations

- No (disabled)


### eFuse Bit Manager

- CONFIG_EFUSE_VIRTUAL
- CONFIG_EFUSE_CUSTOM_TABLE

CONFIG_EFUSE_VIRTUAL

CONFIG_EFUSE_CUSTOM_TABLE


#### CONFIG_EFUSE_CUSTOM_TABLE

Found in: Component config > eFuse Bit Manager

- No (disabled)


##### CONFIG_EFUSE_CUSTOM_TABLE_FILENAME

Found in: Component config > eFuse Bit Manager > CONFIG_EFUSE_CUSTOM_TABLE

- "main/esp_efuse_custom_table.csv" if CONFIG_EFUSE_CUSTOM_TABLE

"main/esp_efuse_custom_table.csv" if CONFIG_EFUSE_CUSTOM_TABLE


#### CONFIG_EFUSE_VIRTUAL

Found in: Component config > eFuse Bit Manager

- No (disabled)


##### CONFIG_EFUSE_VIRTUAL_KEEP_IN_FLASH

Found in: Component config > eFuse Bit Manager > CONFIG_EFUSE_VIRTUAL


##### CONFIG_EFUSE_VIRTUAL_LOG_ALL_WRITES

Found in: Component config > eFuse Bit Manager > CONFIG_EFUSE_VIRTUAL


### ESP-TLS

- CONFIG_ESP_TLS_INSECURE
- CONFIG_ESP_TLS_SERVER_CERT_SELECT_HOOK
- CONFIG_ESP_TLS_LIBRARY_CHOOSE
- CONFIG_ESP_TLS_CLIENT_SESSION_TICKETS
- CONFIG_ESP_DEBUG_WOLFSSL
- CONFIG_ESP_TLS_PSK_VERIFICATION
- CONFIG_ESP_TLS_SERVER_SESSION_TICKETS
- CONFIG_ESP_TLS_OCSP_CHECKALL
- CONFIG_ESP_TLS_SERVER_MIN_AUTH_MODE_OPTIONAL
- CONFIG_ESP_TLS_USE_DS_PERIPHERAL
- CONFIG_ESP_TLS_USE_SECURE_ELEMENT

CONFIG_ESP_TLS_INSECURE

CONFIG_ESP_TLS_SERVER_CERT_SELECT_HOOK

CONFIG_ESP_TLS_LIBRARY_CHOOSE

CONFIG_ESP_TLS_CLIENT_SESSION_TICKETS

CONFIG_ESP_DEBUG_WOLFSSL

CONFIG_ESP_TLS_PSK_VERIFICATION

CONFIG_ESP_TLS_SERVER_SESSION_TICKETS

CONFIG_ESP_TLS_OCSP_CHECKALL

CONFIG_ESP_TLS_SERVER_MIN_AUTH_MODE_OPTIONAL

CONFIG_ESP_TLS_USE_DS_PERIPHERAL

CONFIG_ESP_TLS_USE_SECURE_ELEMENT


#### CONFIG_ESP_TLS_LIBRARY_CHOOSE

Found in: Component config > ESP-TLS

Available options:

- mbedTLS (CONFIG_ESP_TLS_USING_MBEDTLS)
- wolfSSL (License info in wolfSSL directory README) (CONFIG_ESP_TLS_USING_WOLFSSL)

mbedTLS (CONFIG_ESP_TLS_USING_MBEDTLS)


#### CONFIG_ESP_TLS_USE_SECURE_ELEMENT

Found in: Component config > ESP-TLS


#### CONFIG_ESP_TLS_USE_DS_PERIPHERAL

Found in: Component config > ESP-TLS

- Yes (enabled)


#### CONFIG_ESP_TLS_CLIENT_SESSION_TICKETS

Found in: Component config > ESP-TLS


#### CONFIG_ESP_TLS_SERVER_SESSION_TICKETS

Found in: Component config > ESP-TLS


##### CONFIG_ESP_TLS_SERVER_SESSION_TICKET_TIMEOUT

Found in: Component config > ESP-TLS > CONFIG_ESP_TLS_SERVER_SESSION_TICKETS

- 86400 if CONFIG_ESP_TLS_SERVER_SESSION_TICKETS

86400 if CONFIG_ESP_TLS_SERVER_SESSION_TICKETS


#### CONFIG_ESP_TLS_SERVER_CERT_SELECT_HOOK

Found in: Component config > ESP-TLS


#### CONFIG_ESP_TLS_SERVER_MIN_AUTH_MODE_OPTIONAL

Found in: Component config > ESP-TLS

- No (disabled)


#### CONFIG_ESP_TLS_PSK_VERIFICATION

Found in: Component config > ESP-TLS


#### CONFIG_ESP_TLS_INSECURE

Found in: Component config > ESP-TLS


##### CONFIG_ESP_TLS_SKIP_SERVER_CERT_VERIFY

Found in: Component config > ESP-TLS > CONFIG_ESP_TLS_INSECURE


#### CONFIG_ESP_DEBUG_WOLFSSL

Found in: Component config > ESP-TLS


#### CONFIG_ESP_TLS_OCSP_CHECKALL

Found in: Component config > ESP-TLS

- Yes (enabled) if CONFIG_ESP_TLS_USING_WOLFSSL

Yes (enabled) if CONFIG_ESP_TLS_USING_WOLFSSL


### ADC and ADC Calibration

- ADC Calibration Configurations
- CONFIG_ADC_CONTINUOUS_ISR_IRAM_SAFE
- CONFIG_ADC_DISABLE_DAC_OUTPUT
- CONFIG_ADC_ENABLE_DEBUG_LOG
- CONFIG_ADC_ONESHOT_CTRL_FUNC_IN_IRAM

CONFIG_ADC_CONTINUOUS_ISR_IRAM_SAFE

CONFIG_ADC_DISABLE_DAC_OUTPUT

CONFIG_ADC_ENABLE_DEBUG_LOG

CONFIG_ADC_ONESHOT_CTRL_FUNC_IN_IRAM


#### CONFIG_ADC_ONESHOT_CTRL_FUNC_IN_IRAM

Found in: Component config > ADC and ADC Calibration

- No (disabled)


#### CONFIG_ADC_CONTINUOUS_ISR_IRAM_SAFE

Found in: Component config > ADC and ADC Calibration

- No (disabled)


#### ADC Calibration Configurations


#### CONFIG_ADC_DISABLE_DAC_OUTPUT

Found in: Component config > ADC and ADC Calibration

- Yes (enabled) if SOC_DAC_SUPPORTED


#### CONFIG_ADC_ENABLE_DEBUG_LOG

Found in: Component config > ADC and ADC Calibration

- No (disabled)


### Wireless Coexistence

- CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE
- CONFIG_ESP_COEX_GPIO_DEBUG
- CONFIG_ESP_COEX_SW_COEXIST_ENABLE
- CONFIG_ESP_COEX_POWER_MANAGEMENT

CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE

CONFIG_ESP_COEX_GPIO_DEBUG

CONFIG_ESP_COEX_SW_COEXIST_ENABLE

CONFIG_ESP_COEX_POWER_MANAGEMENT


#### CONFIG_ESP_COEX_SW_COEXIST_ENABLE

Found in: Component config > Wireless Coexistence


#### CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE

Found in: Component config > Wireless Coexistence


#### CONFIG_ESP_COEX_POWER_MANAGEMENT

Found in: Component config > Wireless Coexistence


#### CONFIG_ESP_COEX_GPIO_DEBUG

Found in: Component config > Wireless Coexistence


##### CONFIG_ESP_COEX_GPIO_DEBUG_DIAG

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

Available options:

- General (CONFIG_ESP_COEX_GPIO_DEBUG_DIAG_GENERAL)
- Wi-Fi (CONFIG_ESP_COEX_GPIO_DEBUG_DIAG_WIFI)

General (CONFIG_ESP_COEX_GPIO_DEBUG_DIAG_GENERAL)

Wi-Fi (CONFIG_ESP_COEX_GPIO_DEBUG_DIAG_WIFI)


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 12 if CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 12 if CONFIG_ESP_COEX_GPIO_DEBUG

- 12 if CONFIG_ESP_COEX_GPIO_DEBUG

12 if CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX0

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 0 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 0 && CONFIG_ESP_COEX_GPIO_DEBUG

- 1 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 0 && CONFIG_ESP_COEX_GPIO_DEBUG

1 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 0 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX1

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 1 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 1 && CONFIG_ESP_COEX_GPIO_DEBUG

- 2 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 1 && CONFIG_ESP_COEX_GPIO_DEBUG

2 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 1 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX2

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 2 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 2 && CONFIG_ESP_COEX_GPIO_DEBUG

- 3 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 2 && CONFIG_ESP_COEX_GPIO_DEBUG

3 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 2 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX3

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 3 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 3 && CONFIG_ESP_COEX_GPIO_DEBUG

- 4 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 3 && CONFIG_ESP_COEX_GPIO_DEBUG

4 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 3 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX4

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 4 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 4 && CONFIG_ESP_COEX_GPIO_DEBUG

- 5 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 4 && CONFIG_ESP_COEX_GPIO_DEBUG

5 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 4 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX5

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 5 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 5 && CONFIG_ESP_COEX_GPIO_DEBUG

- 6 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 5 && CONFIG_ESP_COEX_GPIO_DEBUG

6 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 5 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX6

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 6 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 6 && CONFIG_ESP_COEX_GPIO_DEBUG

- 7 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 6 && CONFIG_ESP_COEX_GPIO_DEBUG

7 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 6 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX7

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 7 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 7 && CONFIG_ESP_COEX_GPIO_DEBUG

- 8 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 7 && CONFIG_ESP_COEX_GPIO_DEBUG

8 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 7 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX8

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 8 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 8 && CONFIG_ESP_COEX_GPIO_DEBUG

- 9 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 8 && CONFIG_ESP_COEX_GPIO_DEBUG

9 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 8 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX9

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 9 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 9 && CONFIG_ESP_COEX_GPIO_DEBUG

- 10 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 9 && CONFIG_ESP_COEX_GPIO_DEBUG

10 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 9 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX10

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 10 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 10 && CONFIG_ESP_COEX_GPIO_DEBUG

- 11 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 10 && CONFIG_ESP_COEX_GPIO_DEBUG

11 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 10 && CONFIG_ESP_COEX_GPIO_DEBUG


##### CONFIG_ESP_COEX_GPIO_DEBUG_IO_IDX11

Found in: Component config > Wireless Coexistence > CONFIG_ESP_COEX_GPIO_DEBUG

- from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 11 && CONFIG_ESP_COEX_GPIO_DEBUG

from 0 to 54 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 11 && CONFIG_ESP_COEX_GPIO_DEBUG

- 12 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 11 && CONFIG_ESP_COEX_GPIO_DEBUG

12 if CONFIG_ESP_COEX_GPIO_DEBUG_IO_COUNT > 11 && CONFIG_ESP_COEX_GPIO_DEBUG


### Common ESP-related

- CONFIG_ESP_ERR_TO_NAME_LOOKUP

CONFIG_ESP_ERR_TO_NAME_LOOKUP


#### CONFIG_ESP_ERR_TO_NAME_LOOKUP

Found in: Component config > Common ESP-related

- Yes (enabled)


### ESP-Driver:Analog Comparator Configurations

- CONFIG_ANA_CMPR_ISR_CACHE_SAFE
- CONFIG_ANA_CMPR_ENABLE_DEBUG_LOG
- CONFIG_ANA_CMPR_CTRL_FUNC_IN_IRAM
- CONFIG_ANA_CMPR_ISR_HANDLER_IN_IRAM

CONFIG_ANA_CMPR_ISR_CACHE_SAFE

CONFIG_ANA_CMPR_ENABLE_DEBUG_LOG

CONFIG_ANA_CMPR_CTRL_FUNC_IN_IRAM

CONFIG_ANA_CMPR_ISR_HANDLER_IN_IRAM


#### CONFIG_ANA_CMPR_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- Yes (enabled)


#### CONFIG_ANA_CMPR_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)


#### CONFIG_ANA_CMPR_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)


#### CONFIG_ANA_CMPR_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:Analog Comparator Configurations

- No (disabled)


### ESP-Driver:BitScrambler Configurations

- CONFIG_BITSCRAMBLER_CTRL_FUNC_IN_IRAM

CONFIG_BITSCRAMBLER_CTRL_FUNC_IN_IRAM


#### CONFIG_BITSCRAMBLER_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:BitScrambler Configurations

- No (disabled)


### ESP-Driver:Camera Controller Configurations

- CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAFE
- CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE
- CONFIG_CAM_CTLR_ISP_DVP_ISR_CACHE_SAFE

CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAFE

CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE

CONFIG_CAM_CTLR_ISP_DVP_ISR_CACHE_SAFE


#### CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Camera Controller Configurations

- No (disabled)


#### CONFIG_CAM_CTLR_ISP_DVP_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Camera Controller Configurations

- No (disabled)


#### CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Camera Controller Configurations

- No (disabled)


### ESP-Driver:DAC Configurations

- CONFIG_DAC_DMA_AUTO_16BIT_ALIGN
- CONFIG_DAC_ISR_IRAM_SAFE
- CONFIG_DAC_ENABLE_DEBUG_LOG
- CONFIG_DAC_CTRL_FUNC_IN_IRAM

CONFIG_DAC_DMA_AUTO_16BIT_ALIGN

CONFIG_DAC_ISR_IRAM_SAFE

CONFIG_DAC_ENABLE_DEBUG_LOG

CONFIG_DAC_CTRL_FUNC_IN_IRAM


#### CONFIG_DAC_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:DAC Configurations

- No (disabled) if SOC_DAC_SUPPORTED


#### CONFIG_DAC_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:DAC Configurations

- No (disabled) if SOC_DAC_SUPPORTED


#### CONFIG_DAC_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:DAC Configurations

- No (disabled) if SOC_DAC_SUPPORTED


#### CONFIG_DAC_DMA_AUTO_16BIT_ALIGN

Found in: Component config > ESP-Driver:DAC Configurations

- Yes (enabled) if SOC_DAC_DMA_16BIT_ALIGN && SOC_DAC_SUPPORTED


### ESP-Driver:GPIO Configurations

- CONFIG_GPIO_CTRL_FUNC_IN_IRAM

CONFIG_GPIO_CTRL_FUNC_IN_IRAM


#### CONFIG_GPIO_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:GPIO Configurations

- No (disabled)


### ESP-Driver:GPTimer Configurations

- CONFIG_GPTIMER_ISR_CACHE_SAFE
- CONFIG_GPTIMER_ENABLE_DEBUG_LOG
- CONFIG_GPTIMER_CTRL_FUNC_IN_IRAM
- CONFIG_GPTIMER_ISR_HANDLER_IN_IRAM

CONFIG_GPTIMER_ISR_CACHE_SAFE

CONFIG_GPTIMER_ENABLE_DEBUG_LOG

CONFIG_GPTIMER_CTRL_FUNC_IN_IRAM

CONFIG_GPTIMER_ISR_HANDLER_IN_IRAM


#### CONFIG_GPTIMER_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:GPTimer Configurations

- Yes (enabled)


#### CONFIG_GPTIMER_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:GPTimer Configurations

- No (disabled)


#### CONFIG_GPTIMER_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:GPTimer Configurations

- No (disabled)


#### CONFIG_GPTIMER_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:GPTimer Configurations

- No (disabled)


### ESP-Driver:I2C Configurations

- CONFIG_I2C_ENABLE_DEBUG_LOG
- CONFIG_I2C_ISR_IRAM_SAFE
- CONFIG_I2C_MASTER_ISR_HANDLER_IN_IRAM

CONFIG_I2C_ENABLE_DEBUG_LOG

CONFIG_I2C_ISR_IRAM_SAFE

CONFIG_I2C_MASTER_ISR_HANDLER_IN_IRAM


#### CONFIG_I2C_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:I2C Configurations

- No (disabled)


#### CONFIG_I2C_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:I2C Configurations

- No (disabled)


#### CONFIG_I2C_MASTER_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:I2C Configurations

- Yes (enabled)


### ESP-Driver:I2S Configurations

- CONFIG_I2S_ENABLE_DEBUG_LOG
- CONFIG_I2S_ISR_IRAM_SAFE
- CONFIG_I2S_CTRL_FUNC_IN_IRAM

CONFIG_I2S_ENABLE_DEBUG_LOG

CONFIG_I2S_ISR_IRAM_SAFE

CONFIG_I2S_CTRL_FUNC_IN_IRAM


#### CONFIG_I2S_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:I2S Configurations

- No (disabled)


#### CONFIG_I2S_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:I2S Configurations

- No (disabled)


#### CONFIG_I2S_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:I2S Configurations

- No (disabled)


### ESP-Driver:I3C Master Configurations

- CONFIG_I3C_MASTER_ENABLE_DEBUG_LOG
- CONFIG_I3C_MASTER_ISR_CACHE_SAFE
- CONFIG_I3C_MASTER_ISR_HANDLER_IN_IRAM

CONFIG_I3C_MASTER_ENABLE_DEBUG_LOG

CONFIG_I3C_MASTER_ISR_CACHE_SAFE

CONFIG_I3C_MASTER_ISR_HANDLER_IN_IRAM


#### CONFIG_I3C_MASTER_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:I3C Master Configurations

- No (disabled)


#### CONFIG_I3C_MASTER_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:I3C Master Configurations

- No (disabled)


#### CONFIG_I3C_MASTER_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:I3C Master Configurations

- No (disabled)


### ESP-Driver:ISP Configurations

- CONFIG_ISP_ISR_IRAM_SAFE
- CONFIG_ISP_CTRL_FUNC_IN_IRAM

CONFIG_ISP_ISR_IRAM_SAFE

CONFIG_ISP_CTRL_FUNC_IN_IRAM


#### CONFIG_ISP_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:ISP Configurations

- No (disabled)


#### CONFIG_ISP_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:ISP Configurations

- No (disabled)


### ESP-Driver:JPEG-Codec Configurations

- CONFIG_JPEG_ENABLE_DEBUG_LOG

CONFIG_JPEG_ENABLE_DEBUG_LOG


#### CONFIG_JPEG_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:JPEG-Codec Configurations

- No (disabled)


### ESP-Driver:LEDC Configurations

- CONFIG_LEDC_CTRL_FUNC_IN_IRAM

CONFIG_LEDC_CTRL_FUNC_IN_IRAM


#### CONFIG_LEDC_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:LEDC Configurations

- No (disabled)


### ESP-Driver:MCPWM Configurations

- CONFIG_MCPWM_ISR_CACHE_SAFE
- CONFIG_MCPWM_ENABLE_DEBUG_LOG
- CONFIG_MCPWM_CTRL_FUNC_IN_IRAM
- CONFIG_MCPWM_ISR_HANDLER_IN_IRAM

CONFIG_MCPWM_ISR_CACHE_SAFE

CONFIG_MCPWM_ENABLE_DEBUG_LOG

CONFIG_MCPWM_CTRL_FUNC_IN_IRAM

CONFIG_MCPWM_ISR_HANDLER_IN_IRAM


#### CONFIG_MCPWM_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:MCPWM Configurations

- Yes (enabled)


#### CONFIG_MCPWM_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:MCPWM Configurations

- No (disabled)


#### CONFIG_MCPWM_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:MCPWM Configurations

- No (disabled)


#### CONFIG_MCPWM_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:MCPWM Configurations

- No (disabled)


### ESP-Driver:Parallel IO Configurations

- CONFIG_PARLIO_RX_ISR_CACHE_SAFE
- CONFIG_PARLIO_TX_ISR_CACHE_SAFE
- CONFIG_PARLIO_ENABLE_DEBUG_LOG
- CONFIG_PARLIO_ISR_IRAM_SAFE
- CONFIG_PARLIO_RX_ISR_HANDLER_IN_IRAM
- CONFIG_PARLIO_TX_ISR_HANDLER_IN_IRAM

CONFIG_PARLIO_RX_ISR_CACHE_SAFE

CONFIG_PARLIO_TX_ISR_CACHE_SAFE

CONFIG_PARLIO_ENABLE_DEBUG_LOG

CONFIG_PARLIO_ISR_IRAM_SAFE

CONFIG_PARLIO_RX_ISR_HANDLER_IN_IRAM

CONFIG_PARLIO_TX_ISR_HANDLER_IN_IRAM


#### CONFIG_PARLIO_TX_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:Parallel IO Configurations

- Yes (enabled)


#### CONFIG_PARLIO_RX_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:Parallel IO Configurations

- Yes (enabled)


#### CONFIG_PARLIO_TX_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Parallel IO Configurations

- No (disabled)


#### CONFIG_PARLIO_RX_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:Parallel IO Configurations

- No (disabled)


#### CONFIG_PARLIO_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:Parallel IO Configurations

- No (disabled)


#### CONFIG_PARLIO_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:Parallel IO Configurations

- No (disabled)


### ESP-Driver:PCNT Configurations

- CONFIG_PCNT_ENABLE_DEBUG_LOG
- CONFIG_PCNT_ISR_IRAM_SAFE
- CONFIG_PCNT_CTRL_FUNC_IN_IRAM

CONFIG_PCNT_ENABLE_DEBUG_LOG

CONFIG_PCNT_ISR_IRAM_SAFE

CONFIG_PCNT_CTRL_FUNC_IN_IRAM


#### CONFIG_PCNT_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:PCNT Configurations

- No (disabled)


#### CONFIG_PCNT_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:PCNT Configurations

- No (disabled)


#### CONFIG_PCNT_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:PCNT Configurations

- No (disabled)


### ESP-Driver:RMT Configurations

- CONFIG_RMT_RX_ISR_CACHE_SAFE
- CONFIG_RMT_TX_ISR_CACHE_SAFE
- CONFIG_RMT_ENABLE_DEBUG_LOG
- CONFIG_RMT_ENCODER_FUNC_IN_IRAM
- CONFIG_RMT_RECV_FUNC_IN_IRAM
- CONFIG_RMT_RX_ISR_HANDLER_IN_IRAM
- CONFIG_RMT_TX_ISR_HANDLER_IN_IRAM
- CONFIG_RMT_ISR_IRAM_SAFE

CONFIG_RMT_RX_ISR_CACHE_SAFE

CONFIG_RMT_TX_ISR_CACHE_SAFE

CONFIG_RMT_ENABLE_DEBUG_LOG

CONFIG_RMT_ENCODER_FUNC_IN_IRAM

CONFIG_RMT_RECV_FUNC_IN_IRAM

CONFIG_RMT_RX_ISR_HANDLER_IN_IRAM

CONFIG_RMT_TX_ISR_HANDLER_IN_IRAM

CONFIG_RMT_ISR_IRAM_SAFE


#### CONFIG_RMT_ENCODER_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:RMT Configurations

- Yes (enabled)


#### CONFIG_RMT_TX_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:RMT Configurations

- Yes (enabled)


#### CONFIG_RMT_RX_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:RMT Configurations

- Yes (enabled)


#### CONFIG_RMT_RECV_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:RMT Configurations

- No (disabled)


#### CONFIG_RMT_TX_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:RMT Configurations

- No (disabled)


#### CONFIG_RMT_RX_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:RMT Configurations

- No (disabled)


#### CONFIG_RMT_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:RMT Configurations

- No (disabled)


#### CONFIG_RMT_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:RMT Configurations

- No (disabled)


### ESP-Driver:Sigma Delta Modulator Configurations

- CONFIG_SDM_ENABLE_DEBUG_LOG
- CONFIG_SDM_CTRL_FUNC_IN_IRAM

CONFIG_SDM_ENABLE_DEBUG_LOG

CONFIG_SDM_CTRL_FUNC_IN_IRAM


#### CONFIG_SDM_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:Sigma Delta Modulator Configurations

- No (disabled)


#### CONFIG_SDM_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:Sigma Delta Modulator Configurations

- No (disabled)


### ESP-Driver:SD Host SDMMC Controller Configurations

- CONFIG_SD_HOST_SDMMC_ISR_CACHE_SAFE

CONFIG_SD_HOST_SDMMC_ISR_CACHE_SAFE


#### CONFIG_SD_HOST_SDMMC_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:SD Host SDMMC Controller Configurations

- No (disabled)


### ESP-Driver:SPI Configurations

- CONFIG_SPI_MASTER_ISR_IN_IRAM
- CONFIG_SPI_SLAVE_ISR_IN_IRAM
- CONFIG_SPI_MASTER_IN_IRAM
- CONFIG_SPI_SLAVE_IN_IRAM

CONFIG_SPI_MASTER_ISR_IN_IRAM

CONFIG_SPI_SLAVE_ISR_IN_IRAM

CONFIG_SPI_MASTER_IN_IRAM

CONFIG_SPI_SLAVE_IN_IRAM


#### CONFIG_SPI_MASTER_IN_IRAM

Found in: Component config > ESP-Driver:SPI Configurations

This configuration won't be available if CONFIG_FREERTOS_IN_IRAM is disabled.

- No (disabled) if CONFIG_FREERTOS_IN_IRAM

No (disabled) if CONFIG_FREERTOS_IN_IRAM


#### CONFIG_SPI_MASTER_ISR_IN_IRAM

Found in: Component config > ESP-Driver:SPI Configurations


#### CONFIG_SPI_SLAVE_IN_IRAM

Found in: Component config > ESP-Driver:SPI Configurations

- No (disabled)


#### CONFIG_SPI_SLAVE_ISR_IN_IRAM

Found in: Component config > ESP-Driver:SPI Configurations

- Yes (enabled)


### ESP-Driver:Touch Sensor Configurations

- CONFIG_TOUCH_ENABLE_DEBUG_LOG
- CONFIG_TOUCH_CTRL_FUNC_IN_IRAM
- CONFIG_TOUCH_SKIP_FSM_CHECK
- CONFIG_TOUCH_ISR_IRAM_SAFE

CONFIG_TOUCH_ENABLE_DEBUG_LOG

CONFIG_TOUCH_CTRL_FUNC_IN_IRAM

CONFIG_TOUCH_SKIP_FSM_CHECK

CONFIG_TOUCH_ISR_IRAM_SAFE


#### CONFIG_TOUCH_CTRL_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:Touch Sensor Configurations

- No (disabled)


#### CONFIG_TOUCH_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:Touch Sensor Configurations

- No (disabled)


#### CONFIG_TOUCH_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:Touch Sensor Configurations

- No (disabled)


#### CONFIG_TOUCH_SKIP_FSM_CHECK

Found in: Component config > ESP-Driver:Touch Sensor Configurations

- No (disabled)


### ESP-Driver:Temperature Sensor Configurations

- CONFIG_TEMP_SENSOR_ENABLE_DEBUG_LOG
- CONFIG_TEMP_SENSOR_ISR_IRAM_SAFE

CONFIG_TEMP_SENSOR_ENABLE_DEBUG_LOG

CONFIG_TEMP_SENSOR_ISR_IRAM_SAFE


#### CONFIG_TEMP_SENSOR_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:Temperature Sensor Configurations

- No (disabled)


#### CONFIG_TEMP_SENSOR_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:Temperature Sensor Configurations

- No (disabled)


### ESP-Driver:TWAI Configurations

- CONFIG_TWAI_ISR_CACHE_SAFE
- CONFIG_TWAI_ENABLE_DEBUG_LOG
- CONFIG_TWAI_IO_FUNC_IN_IRAM
- CONFIG_TWAI_ISR_IN_IRAM

CONFIG_TWAI_ISR_CACHE_SAFE

CONFIG_TWAI_ENABLE_DEBUG_LOG

CONFIG_TWAI_IO_FUNC_IN_IRAM

CONFIG_TWAI_ISR_IN_IRAM


#### CONFIG_TWAI_ISR_IN_IRAM

Found in: Component config > ESP-Driver:TWAI Configurations

- No (disabled)


#### CONFIG_TWAI_IO_FUNC_IN_IRAM

Found in: Component config > ESP-Driver:TWAI Configurations

- No (disabled)


#### CONFIG_TWAI_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:TWAI Configurations

- No (disabled)


#### CONFIG_TWAI_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:TWAI Configurations

- No (disabled)


### ESP-Driver:UART Configurations

- CONFIG_UART_ISR_IN_IRAM

CONFIG_UART_ISR_IN_IRAM


#### CONFIG_UART_ISR_IN_IRAM

Found in: Component config > ESP-Driver:UART Configurations


### ESP-Driver:UHCI Configurations

- CONFIG_UHCI_ISR_CACHE_SAFE
- CONFIG_UHCI_ENABLE_DEBUG_LOG
- CONFIG_UHCI_ISR_HANDLER_IN_IRAM

CONFIG_UHCI_ISR_CACHE_SAFE

CONFIG_UHCI_ENABLE_DEBUG_LOG

CONFIG_UHCI_ISR_HANDLER_IN_IRAM


#### CONFIG_UHCI_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:UHCI Configurations

- No (disabled)


#### CONFIG_UHCI_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:UHCI Configurations

- No (disabled)


#### CONFIG_UHCI_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:UHCI Configurations

- No (disabled)


### ESP-Driver:USB Serial/JTAG Configuration

- CONFIG_USJ_ENABLE_USB_SERIAL_JTAG

CONFIG_USJ_ENABLE_USB_SERIAL_JTAG


#### CONFIG_USJ_ENABLE_USB_SERIAL_JTAG

Found in: Component config > ESP-Driver:USB Serial/JTAG Configuration

- Yes (enabled)


##### CONFIG_USJ_NO_AUTO_LS_ON_CONNECTION

Found in: Component config > ESP-Driver:USB Serial/JTAG Configuration > CONFIG_USJ_ENABLE_USB_SERIAL_JTAG


### Ethernet

- CONFIG_ETH_TRANSMIT_MUTEX
- CONFIG_ETH_USE_ESP32_EMAC
- CONFIG_ETH_USE_OPENETH
- CONFIG_ETH_USE_SPI_ETHERNET

CONFIG_ETH_TRANSMIT_MUTEX

CONFIG_ETH_USE_ESP32_EMAC

CONFIG_ETH_USE_OPENETH

CONFIG_ETH_USE_SPI_ETHERNET


#### CONFIG_ETH_USE_ESP32_EMAC

Found in: Component config > Ethernet

- Yes (enabled)

- CONFIG_ETH_DMA_RX_BUFFER_NUM
- CONFIG_ETH_DMA_TX_BUFFER_NUM
- CONFIG_ETH_IRAM_OPTIMIZATION
- CONFIG_ETH_SOFT_FLOW_CONTROL
- CONFIG_ETH_DMA_BUFFER_SIZE

CONFIG_ETH_DMA_RX_BUFFER_NUM

CONFIG_ETH_DMA_TX_BUFFER_NUM

CONFIG_ETH_IRAM_OPTIMIZATION

CONFIG_ETH_SOFT_FLOW_CONTROL

CONFIG_ETH_DMA_BUFFER_SIZE


##### CONFIG_ETH_DMA_BUFFER_SIZE

Found in: Component config > Ethernet > CONFIG_ETH_USE_ESP32_EMAC

- from 256 to 1600

- 512


##### CONFIG_ETH_DMA_RX_BUFFER_NUM

Found in: Component config > Ethernet > CONFIG_ETH_USE_ESP32_EMAC

- from 3 to 30

- 20


##### CONFIG_ETH_DMA_TX_BUFFER_NUM

Found in: Component config > Ethernet > CONFIG_ETH_USE_ESP32_EMAC

- from 3 to 30

- 10


##### CONFIG_ETH_SOFT_FLOW_CONTROL

Found in: Component config > Ethernet > CONFIG_ETH_USE_ESP32_EMAC

- No (disabled)


##### CONFIG_ETH_IRAM_OPTIMIZATION

Found in: Component config > Ethernet > CONFIG_ETH_USE_ESP32_EMAC

- No (disabled)


#### CONFIG_ETH_USE_SPI_ETHERNET

Found in: Component config > Ethernet

- Yes (enabled)


#### CONFIG_ETH_USE_OPENETH

Found in: Component config > Ethernet

- No (disabled)

- CONFIG_ETH_OPENETH_DMA_RX_BUFFER_NUM
- CONFIG_ETH_OPENETH_DMA_TX_BUFFER_NUM

CONFIG_ETH_OPENETH_DMA_RX_BUFFER_NUM

CONFIG_ETH_OPENETH_DMA_TX_BUFFER_NUM


##### CONFIG_ETH_OPENETH_DMA_RX_BUFFER_NUM

Found in: Component config > Ethernet > CONFIG_ETH_USE_OPENETH

- from 1 to 64 if CONFIG_ETH_USE_OPENETH

from 1 to 64 if CONFIG_ETH_USE_OPENETH

- 4 if CONFIG_ETH_USE_OPENETH

4 if CONFIG_ETH_USE_OPENETH


##### CONFIG_ETH_OPENETH_DMA_TX_BUFFER_NUM

Found in: Component config > Ethernet > CONFIG_ETH_USE_OPENETH

- from 1 to 64 if CONFIG_ETH_USE_OPENETH

from 1 to 64 if CONFIG_ETH_USE_OPENETH

- 1 if CONFIG_ETH_USE_OPENETH

1 if CONFIG_ETH_USE_OPENETH


#### CONFIG_ETH_TRANSMIT_MUTEX

Found in: Component config > Ethernet

- No (disabled)


### Event Loop Library

- CONFIG_ESP_EVENT_LOOP_PROFILING
- CONFIG_ESP_EVENT_POST_FROM_ISR

CONFIG_ESP_EVENT_LOOP_PROFILING

CONFIG_ESP_EVENT_POST_FROM_ISR


#### CONFIG_ESP_EVENT_LOOP_PROFILING

Found in: Component config > Event Loop Library

- No (disabled)


#### CONFIG_ESP_EVENT_POST_FROM_ISR

Found in: Component config > Event Loop Library

- Yes (enabled)


##### CONFIG_ESP_EVENT_POST_FROM_IRAM_ISR

Found in: Component config > Event Loop Library > CONFIG_ESP_EVENT_POST_FROM_ISR

- Yes (enabled)


### GDB Stub

- CONFIG_ESP_GDBSTUB_SUPPORT_TASKS
- CONFIG_ESP_SYSTEM_GDBSTUB_RUNTIME

CONFIG_ESP_GDBSTUB_SUPPORT_TASKS

CONFIG_ESP_SYSTEM_GDBSTUB_RUNTIME


#### CONFIG_ESP_SYSTEM_GDBSTUB_RUNTIME

Found in: Component config > GDB Stub


#### CONFIG_ESP_GDBSTUB_SUPPORT_TASKS

Found in: Component config > GDB Stub

- Yes (enabled)


##### CONFIG_ESP_GDBSTUB_MAX_TASKS

Found in: Component config > GDB Stub > CONFIG_ESP_GDBSTUB_SUPPORT_TASKS

- 32


### ESP HID

- CONFIG_ESPHID_TASK_SIZE_BLE
- CONFIG_ESPHID_TASK_SIZE_BT

CONFIG_ESPHID_TASK_SIZE_BLE

CONFIG_ESPHID_TASK_SIZE_BT


#### CONFIG_ESPHID_TASK_SIZE_BT

Found in: Component config > ESP HID

- from 2048 to 10240

- 2048


#### CONFIG_ESPHID_TASK_SIZE_BLE

Found in: Component config > ESP HID

- from 2048 to 10240

- 4096


### ESP HTTP client

- CONFIG_ESP_HTTP_CLIENT_ENABLE_GET_CONTENT_RANGE
- CONFIG_ESP_HTTP_CLIENT_ENABLE_CUSTOM_TRANSPORT
- CONFIG_ESP_HTTP_CLIENT_ENABLE_BASIC_AUTH
- CONFIG_ESP_HTTP_CLIENT_ENABLE_DIGEST_AUTH
- CONFIG_ESP_HTTP_CLIENT_ENABLE_HTTPS
- CONFIG_ESP_HTTP_CLIENT_PSA_CRYPTO_MIGRATE
- CONFIG_ESP_HTTP_CLIENT_EVENT_POST_TIMEOUT

CONFIG_ESP_HTTP_CLIENT_ENABLE_GET_CONTENT_RANGE

CONFIG_ESP_HTTP_CLIENT_ENABLE_CUSTOM_TRANSPORT

CONFIG_ESP_HTTP_CLIENT_ENABLE_BASIC_AUTH

CONFIG_ESP_HTTP_CLIENT_ENABLE_DIGEST_AUTH

CONFIG_ESP_HTTP_CLIENT_ENABLE_HTTPS

CONFIG_ESP_HTTP_CLIENT_PSA_CRYPTO_MIGRATE

CONFIG_ESP_HTTP_CLIENT_EVENT_POST_TIMEOUT


#### CONFIG_ESP_HTTP_CLIENT_ENABLE_HTTPS

Found in: Component config > ESP HTTP client

- Yes (enabled)


#### CONFIG_ESP_HTTP_CLIENT_ENABLE_BASIC_AUTH

Found in: Component config > ESP HTTP client

- No (disabled)


#### CONFIG_ESP_HTTP_CLIENT_ENABLE_DIGEST_AUTH

Found in: Component config > ESP HTTP client

- No (disabled)


#### CONFIG_ESP_HTTP_CLIENT_ENABLE_CUSTOM_TRANSPORT

Found in: Component config > ESP HTTP client

- No (disabled)


#### CONFIG_ESP_HTTP_CLIENT_ENABLE_GET_CONTENT_RANGE

Found in: Component config > ESP HTTP client

- No (disabled)


#### CONFIG_ESP_HTTP_CLIENT_EVENT_POST_TIMEOUT

Found in: Component config > ESP HTTP client

- 2000


#### CONFIG_ESP_HTTP_CLIENT_PSA_CRYPTO_MIGRATE

Found in: Component config > ESP HTTP client

- Yes (enabled) if CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO

Yes (enabled) if CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO


### HTTP Server

- CONFIG_HTTPD_MAX_REQ_HDR_LEN
- CONFIG_HTTPD_QUEUE_WORK_BLOCKING
- CONFIG_HTTPD_PURGE_BUF_LEN
- CONFIG_HTTPD_LOG_PURGE_DATA
- CONFIG_HTTPD_MAX_URI_LEN
- CONFIG_HTTPD_SERVER_PSA_CRYPTO_MIGRATE
- CONFIG_HTTPD_SERVER_EVENT_POST_TIMEOUT
- CONFIG_HTTPD_ERR_RESP_NO_DELAY
- CONFIG_HTTPD_WS_PRE_HANDSHAKE_CB_SUPPORT
- CONFIG_HTTPD_WS_SUPPORT

CONFIG_HTTPD_MAX_REQ_HDR_LEN

CONFIG_HTTPD_QUEUE_WORK_BLOCKING

CONFIG_HTTPD_PURGE_BUF_LEN

CONFIG_HTTPD_LOG_PURGE_DATA

CONFIG_HTTPD_MAX_URI_LEN

CONFIG_HTTPD_SERVER_PSA_CRYPTO_MIGRATE

CONFIG_HTTPD_SERVER_EVENT_POST_TIMEOUT

CONFIG_HTTPD_ERR_RESP_NO_DELAY

CONFIG_HTTPD_WS_PRE_HANDSHAKE_CB_SUPPORT

CONFIG_HTTPD_WS_SUPPORT


#### CONFIG_HTTPD_MAX_REQ_HDR_LEN

Found in: Component config > HTTP Server

- from 128 to 65536

- 1024


#### CONFIG_HTTPD_MAX_URI_LEN

Found in: Component config > HTTP Server

- 512


#### CONFIG_HTTPD_ERR_RESP_NO_DELAY

Found in: Component config > HTTP Server

- Yes (enabled)


#### CONFIG_HTTPD_PURGE_BUF_LEN

Found in: Component config > HTTP Server

- 32


#### CONFIG_HTTPD_LOG_PURGE_DATA

Found in: Component config > HTTP Server

- No (disabled)


#### CONFIG_HTTPD_WS_SUPPORT

Found in: Component config > HTTP Server

- No (disabled)


#### CONFIG_HTTPD_QUEUE_WORK_BLOCKING

Found in: Component config > HTTP Server


#### CONFIG_HTTPD_SERVER_EVENT_POST_TIMEOUT

Found in: Component config > HTTP Server

- 2000


#### CONFIG_HTTPD_WS_PRE_HANDSHAKE_CB_SUPPORT

Found in: Component config > HTTP Server

- No (disabled) if CONFIG_HTTPD_WS_SUPPORT

No (disabled) if CONFIG_HTTPD_WS_SUPPORT


#### CONFIG_HTTPD_SERVER_PSA_CRYPTO_MIGRATE

Found in: Component config > HTTP Server

- Yes (enabled) if CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO

Yes (enabled) if CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO


### ESP HTTPS OTA

- CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP
- CONFIG_ESP_HTTPS_OTA_ENABLE_PARTIAL_DOWNLOAD
- CONFIG_ESP_HTTPS_OTA_DECRYPT_CB
- CONFIG_ESP_HTTPS_OTA_EVENT_POST_TIMEOUT

CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP

CONFIG_ESP_HTTPS_OTA_ENABLE_PARTIAL_DOWNLOAD

CONFIG_ESP_HTTPS_OTA_DECRYPT_CB

CONFIG_ESP_HTTPS_OTA_EVENT_POST_TIMEOUT


#### CONFIG_ESP_HTTPS_OTA_DECRYPT_CB

Found in: Component config > ESP HTTPS OTA

- No (disabled)


#### CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP

Found in: Component config > ESP HTTPS OTA

- No (disabled)


#### CONFIG_ESP_HTTPS_OTA_EVENT_POST_TIMEOUT

Found in: Component config > ESP HTTPS OTA

- 2000


#### CONFIG_ESP_HTTPS_OTA_ENABLE_PARTIAL_DOWNLOAD

Found in: Component config > ESP HTTPS OTA

- No (disabled)


### ESP HTTPS server

- CONFIG_ESP_HTTPS_SERVER_CERT_SELECT_HOOK
- CONFIG_ESP_HTTPS_SERVER_ENABLE
- CONFIG_ESP_HTTPS_SERVER_EVENT_POST_TIMEOUT

CONFIG_ESP_HTTPS_SERVER_CERT_SELECT_HOOK

CONFIG_ESP_HTTPS_SERVER_ENABLE

CONFIG_ESP_HTTPS_SERVER_EVENT_POST_TIMEOUT


#### CONFIG_ESP_HTTPS_SERVER_ENABLE

Found in: Component config > ESP HTTPS server


#### CONFIG_ESP_HTTPS_SERVER_EVENT_POST_TIMEOUT

Found in: Component config > ESP HTTPS server

- 2000


#### CONFIG_ESP_HTTPS_SERVER_CERT_SELECT_HOOK

Found in: Component config > ESP HTTPS server

- No (disabled)


### Hardware Settings

- 2D-DMA Configurations
- CONFIG_ESP_ENABLE_PVT
- Chip revision
- DCDC Regulator Configurations
- DW_GDMA Configurations
- Event Task Matrix (ETM) Configurations
- GDMA Configurations
- LDO Regulator Configurations
- MAC Config
- Main XTAL Config
- Peripheral Control
- CONFIG_ESP_INTR_IN_IRAM
- Power Supplier
- RTC Clock Config
- Sleep Config

CONFIG_ESP_ENABLE_PVT

CONFIG_ESP_INTR_IN_IRAM


#### Chip revision

- CONFIG_ESP_REV_NEW_CHIP_TEST
- CONFIG_ESP_EFUSE_BLOCK_REV_MIN_FULL
- CONFIG_ESP32P4_REV_MIN
- CONFIG_ESP32P4_SELECTS_REV_LESS_V3

CONFIG_ESP_REV_NEW_CHIP_TEST

CONFIG_ESP_EFUSE_BLOCK_REV_MIN_FULL

CONFIG_ESP32P4_REV_MIN

CONFIG_ESP32P4_SELECTS_REV_LESS_V3


##### CONFIG_ESP32P4_SELECTS_REV_LESS_V3

Found in: Component config > Hardware Settings > Chip revision

- Yes (enabled)


##### CONFIG_ESP32P4_REV_MIN

Found in: Component config > Hardware Settings > Chip revision

Available options:

- Rev v0.0 (CONFIG_ESP32P4_REV_MIN_0)
- Rev v0.1 (CONFIG_ESP32P4_REV_MIN_1)
- Rev v1.0 (CONFIG_ESP32P4_REV_MIN_100)
- Rev v3.0 (CONFIG_ESP32P4_REV_MIN_300)

Rev v0.0 (CONFIG_ESP32P4_REV_MIN_0)

Rev v0.1 (CONFIG_ESP32P4_REV_MIN_1)

Rev v1.0 (CONFIG_ESP32P4_REV_MIN_100)

Rev v3.0 (CONFIG_ESP32P4_REV_MIN_300)


##### CONFIG_ESP_EFUSE_BLOCK_REV_MIN_FULL

Found in: Component config > Hardware Settings > Chip revision

- 0


##### CONFIG_ESP_REV_NEW_CHIP_TEST

Found in: Component config > Hardware Settings > Chip revision

- No (disabled)


#### MAC Config

- CONFIG_ESP_MAC_USE_CUSTOM_MAC_AS_BASE_MAC
- CONFIG_ESP32P4_UNIVERSAL_MAC_ADDRESSES

CONFIG_ESP_MAC_USE_CUSTOM_MAC_AS_BASE_MAC

CONFIG_ESP32P4_UNIVERSAL_MAC_ADDRESSES


##### CONFIG_ESP32P4_UNIVERSAL_MAC_ADDRESSES

Found in: Component config > Hardware Settings > MAC Config

Available options:

- One (CONFIG_ESP32P4_UNIVERSAL_MAC_ADDRESSES_ONE)

One (CONFIG_ESP32P4_UNIVERSAL_MAC_ADDRESSES_ONE)


##### CONFIG_ESP_MAC_USE_CUSTOM_MAC_AS_BASE_MAC

Found in: Component config > Hardware Settings > MAC Config

- No (disabled)


#### Sleep Config

- CONFIG_ESP_SLEEP_GPIO_ENABLE_INTERNAL_RESISTORS
- CONFIG_ESP_SLEEP_CACHE_SAFE_ASSERTION
- CONFIG_ESP_SLEEP_EVENT_CALLBACKS
- CONFIG_ESP_SLEEP_DEBUG
- CONFIG_ESP_SLEEP_WAIT_FLASH_READY_EXTRA_DELAY
- CONFIG_ESP_SLEEP_GPIO_RESET_WORKAROUND
- CONFIG_ESP_SLEEP_POWER_DOWN_FLASH
- CONFIG_ESP_SLEEP_MSPI_NEED_ALL_IO_PU
- CONFIG_ESP_SLEEP_FLASH_LEAKAGE_WORKAROUND
- CONFIG_ESP_SLEEP_PSRAM_LEAKAGE_WORKAROUND

CONFIG_ESP_SLEEP_GPIO_ENABLE_INTERNAL_RESISTORS

CONFIG_ESP_SLEEP_CACHE_SAFE_ASSERTION

CONFIG_ESP_SLEEP_EVENT_CALLBACKS

CONFIG_ESP_SLEEP_DEBUG

CONFIG_ESP_SLEEP_WAIT_FLASH_READY_EXTRA_DELAY

CONFIG_ESP_SLEEP_GPIO_RESET_WORKAROUND

CONFIG_ESP_SLEEP_POWER_DOWN_FLASH

CONFIG_ESP_SLEEP_MSPI_NEED_ALL_IO_PU

CONFIG_ESP_SLEEP_FLASH_LEAKAGE_WORKAROUND

CONFIG_ESP_SLEEP_PSRAM_LEAKAGE_WORKAROUND


##### CONFIG_ESP_SLEEP_POWER_DOWN_FLASH

Found in: Component config > Hardware Settings > Sleep Config


##### CONFIG_ESP_SLEEP_FLASH_LEAKAGE_WORKAROUND

Found in: Component config > Hardware Settings > Sleep Config


##### CONFIG_ESP_SLEEP_PSRAM_LEAKAGE_WORKAROUND

Found in: Component config > Hardware Settings > Sleep Config

- Yes (enabled) if CONFIG_SPIRAM

Yes (enabled) if CONFIG_SPIRAM


##### CONFIG_ESP_SLEEP_MSPI_NEED_ALL_IO_PU

Found in: Component config > Hardware Settings > Sleep Config


##### CONFIG_ESP_SLEEP_GPIO_RESET_WORKAROUND

Found in: Component config > Hardware Settings > Sleep Config

- GPIO needs to be configured as input-mode only
- The pin receives a small electrostatic pulse, and reset occurs when the pulse voltage is higher than 6 V

- Yes (enabled)


##### CONFIG_ESP_SLEEP_WAIT_FLASH_READY_EXTRA_DELAY

Found in: Component config > Hardware Settings > Sleep Config

- from 0 to 5000

- 0


##### CONFIG_ESP_SLEEP_CACHE_SAFE_ASSERTION

Found in: Component config > Hardware Settings > Sleep Config

- No (disabled)


##### CONFIG_ESP_SLEEP_DEBUG

Found in: Component config > Hardware Settings > Sleep Config

- No (disabled)


##### CONFIG_ESP_SLEEP_GPIO_ENABLE_INTERNAL_RESISTORS

Found in: Component config > Hardware Settings > Sleep Config

- Yes (enabled)


##### CONFIG_ESP_SLEEP_EVENT_CALLBACKS

Found in: Component config > Hardware Settings > Sleep Config

- No (disabled) if CONFIG_FREERTOS_USE_TICKLESS_IDLE

No (disabled) if CONFIG_FREERTOS_USE_TICKLESS_IDLE


#### RTC Clock Config

- CONFIG_RTC_CLK_CAL_CYCLES
- CONFIG_RTC_CLK_SRC
- CONFIG_RTC_FAST_CLK_SRC

CONFIG_RTC_CLK_CAL_CYCLES

CONFIG_RTC_CLK_SRC

CONFIG_RTC_FAST_CLK_SRC


##### CONFIG_RTC_CLK_SRC

Found in: Component config > Hardware Settings > RTC Clock Config

Available options:

- Internal 136 kHz RC oscillator (CONFIG_RTC_CLK_SRC_INT_RC)
- External 32 kHz crystal (CONFIG_RTC_CLK_SRC_EXT_CRYS)

Internal 136 kHz RC oscillator (CONFIG_RTC_CLK_SRC_INT_RC)

External 32 kHz crystal (CONFIG_RTC_CLK_SRC_EXT_CRYS)


##### CONFIG_RTC_CLK_CAL_CYCLES

Found in: Component config > Hardware Settings > RTC Clock Config

- 150000 Hz if internal RC oscillator is used as clock source. For this use value 1024.
- 32768 Hz if the 32k crystal oscillator is used. For this use value 3000 or more.In case more value will help improve the definition of the launch of the crystal. If the crystal could not start, it will be switched to internal RC.

- from 0 to 8190 if CONFIG_RTC_CLK_SRC_EXT_CRYS
- from 0 to 32766

from 0 to 8190 if CONFIG_RTC_CLK_SRC_EXT_CRYS

- 3000 if CONFIG_RTC_CLK_SRC_EXT_CRYS
- 1024

3000 if CONFIG_RTC_CLK_SRC_EXT_CRYS


##### CONFIG_RTC_FAST_CLK_SRC

Found in: Component config > Hardware Settings > RTC Clock Config

Available options:

- 20 Mhz RC Fast Clock (CONFIG_RTC_FAST_CLK_SRC_RC_FAST)
- 40 Mhz crystal (increased power consumption during sleep) (CONFIG_RTC_FAST_CLK_SRC_XTAL)

20 Mhz RC Fast Clock (CONFIG_RTC_FAST_CLK_SRC_RC_FAST)


#### Peripheral Control

- CONFIG_ESP_PERIPH_CTRL_FUNC_IN_IRAM
- CONFIG_ESP_REGI2C_CTRL_FUNC_IN_IRAM

CONFIG_ESP_PERIPH_CTRL_FUNC_IN_IRAM

CONFIG_ESP_REGI2C_CTRL_FUNC_IN_IRAM


##### CONFIG_ESP_PERIPH_CTRL_FUNC_IN_IRAM

Found in: Component config > Hardware Settings > Peripheral Control

- No (disabled)


##### CONFIG_ESP_REGI2C_CTRL_FUNC_IN_IRAM

Found in: Component config > Hardware Settings > Peripheral Control

- Yes (enabled)


#### GDMA Configurations

- CONFIG_GDMA_ENABLE_DEBUG_LOG
- CONFIG_GDMA_ENABLE_WEIGHTED_ARBITRATION
- CONFIG_GDMA_CTRL_FUNC_IN_IRAM
- CONFIG_GDMA_ISR_HANDLER_IN_IRAM

CONFIG_GDMA_ENABLE_DEBUG_LOG

CONFIG_GDMA_ENABLE_WEIGHTED_ARBITRATION

CONFIG_GDMA_CTRL_FUNC_IN_IRAM

CONFIG_GDMA_ISR_HANDLER_IN_IRAM


##### CONFIG_GDMA_CTRL_FUNC_IN_IRAM

Found in: Component config > Hardware Settings > GDMA Configurations

- No (disabled)


##### CONFIG_GDMA_ISR_HANDLER_IN_IRAM

Found in: Component config > Hardware Settings > GDMA Configurations

- Yes (enabled)


##### CONFIG_GDMA_ENABLE_DEBUG_LOG

Found in: Component config > Hardware Settings > GDMA Configurations

- No (disabled)


##### CONFIG_GDMA_ENABLE_WEIGHTED_ARBITRATION

Found in: Component config > Hardware Settings > GDMA Configurations

- No (disabled) if SOC_GDMA_SUPPORT_WEIGHTED_ARBITRATION && CONFIG_IDF_EXPERIMENTAL_FEATURES


#### DW_GDMA Configurations

- CONFIG_DW_GDMA_ENABLE_DEBUG_LOG

CONFIG_DW_GDMA_ENABLE_DEBUG_LOG


##### CONFIG_DW_GDMA_ENABLE_DEBUG_LOG

Found in: Component config > Hardware Settings > DW_GDMA Configurations

- No (disabled)


#### 2D-DMA Configurations

- CONFIG_DMA2D_ISR_IRAM_SAFE
- CONFIG_DMA2D_OPERATION_FUNC_IN_IRAM

CONFIG_DMA2D_ISR_IRAM_SAFE

CONFIG_DMA2D_OPERATION_FUNC_IN_IRAM


##### CONFIG_DMA2D_OPERATION_FUNC_IN_IRAM

Found in: Component config > Hardware Settings > 2D-DMA Configurations

- No (disabled)


##### CONFIG_DMA2D_ISR_IRAM_SAFE

Found in: Component config > Hardware Settings > 2D-DMA Configurations

- No (disabled)


#### Event Task Matrix (ETM) Configurations

- CONFIG_ETM_ENABLE_DEBUG_LOG

CONFIG_ETM_ENABLE_DEBUG_LOG


##### CONFIG_ETM_ENABLE_DEBUG_LOG

Found in: Component config > Hardware Settings > Event Task Matrix (ETM) Configurations

- No (disabled)


#### Main XTAL Config

- CONFIG_XTAL_FREQ

CONFIG_XTAL_FREQ


##### CONFIG_XTAL_FREQ

Found in: Component config > Hardware Settings > Main XTAL Config

Available options:

- 40 MHz (CONFIG_XTAL_FREQ_40)

40 MHz (CONFIG_XTAL_FREQ_40)


#### DCDC Regulator Configurations

- CONFIG_ESP_SLEEP_DCM_VSET_VAL_IN_SLEEP

CONFIG_ESP_SLEEP_DCM_VSET_VAL_IN_SLEEP


##### CONFIG_ESP_SLEEP_DCM_VSET_VAL_IN_SLEEP

Found in: Component config > Hardware Settings > DCDC Regulator Configurations

- TI-TLV62569/TLV62569P: 14

- from 0 to 31

- 14


#### LDO Regulator Configurations

- CONFIG_ESP_LDO_RESERVE_PSRAM
- CONFIG_ESP_LDO_RESERVE_SPI_NOR_FLASH

CONFIG_ESP_LDO_RESERVE_PSRAM

CONFIG_ESP_LDO_RESERVE_SPI_NOR_FLASH


##### CONFIG_ESP_LDO_RESERVE_SPI_NOR_FLASH

Found in: Component config > Hardware Settings > LDO Regulator Configurations

- Yes (enabled)


##### CONFIG_ESP_LDO_CHAN_SPI_NOR_FLASH_DOMAIN

Found in: Component config > Hardware Settings > LDO Regulator Configurations > CONFIG_ESP_LDO_RESERVE_SPI_NOR_FLASH

- from 1 to 1

- 1


##### CONFIG_ESP_LDO_VOLTAGE_SPI_NOR_FLASH_DOMAIN

Found in: Component config > Hardware Settings > LDO Regulator Configurations > CONFIG_ESP_LDO_RESERVE_SPI_NOR_FLASH

Available options:

- 3.3V (CONFIG_ESP_LDO_VOLTAGE_SPI_NOR_FLASH_3300_MV)

3.3V (CONFIG_ESP_LDO_VOLTAGE_SPI_NOR_FLASH_3300_MV)


##### CONFIG_ESP_LDO_RESERVE_PSRAM

Found in: Component config > Hardware Settings > LDO Regulator Configurations

- Yes (enabled)


##### CONFIG_ESP_LDO_CHAN_PSRAM_DOMAIN

Found in: Component config > Hardware Settings > LDO Regulator Configurations > CONFIG_ESP_LDO_RESERVE_PSRAM

- from 2 to 2

- 2


##### CONFIG_ESP_LDO_VOLTAGE_PSRAM_DOMAIN

Found in: Component config > Hardware Settings > LDO Regulator Configurations > CONFIG_ESP_LDO_RESERVE_PSRAM

Available options:

- 1.9V (CONFIG_ESP_LDO_VOLTAGE_PSRAM_1900_MV)

1.9V (CONFIG_ESP_LDO_VOLTAGE_PSRAM_1900_MV)


#### Power Supplier

- Brownout Detector
- RTC Backup Battery


##### Brownout Detector

- CONFIG_ESP_BROWNOUT_DET

CONFIG_ESP_BROWNOUT_DET


##### CONFIG_ESP_BROWNOUT_DET

Found in: Component config > Hardware Settings > Power Supplier > Brownout Detector

- Yes (enabled)


##### CONFIG_ESP_BROWNOUT_DET_LVL_SEL

Found in: Component config > Hardware Settings > Power Supplier > Brownout Detector > CONFIG_ESP_BROWNOUT_DET

Available options:

- 2.6V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_7)
- 2.52V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_6)
- 2.42V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_5)

2.6V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_7)

2.52V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_6)

2.42V (CONFIG_ESP_BROWNOUT_DET_LVL_SEL_5)


##### RTC Backup Battery

- CONFIG_ESP_VBAT_INIT_AUTO
- CONFIG_ESP_VBAT_CHARGER_CIRCUIT_RESISTOR_VAL
- CONFIG_ESP_VBAT_WAKEUP_CHIP_ON_VBAT_BROWNOUT

CONFIG_ESP_VBAT_INIT_AUTO

CONFIG_ESP_VBAT_CHARGER_CIRCUIT_RESISTOR_VAL

CONFIG_ESP_VBAT_WAKEUP_CHIP_ON_VBAT_BROWNOUT


##### CONFIG_ESP_VBAT_INIT_AUTO

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery

- Ensure a compatible battery (2.5V ~ 3.6V) is connected to the VBAT pin.
- The VBAT battery provides power to retain RTC state and keep low-power peripherals activeduring deep sleep.
- When this option is disabled, the RTC battery input (VBAT) must not be left floating.

- No (disabled)


##### CONFIG_ESP_VBAT_ISR_CACHE_SAFE

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery > CONFIG_ESP_VBAT_INIT_AUTO

- Yes (enabled) if CONFIG_ESP_VBAT_INIT_AUTO

Yes (enabled) if CONFIG_ESP_VBAT_INIT_AUTO


##### CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery > CONFIG_ESP_VBAT_INIT_AUTO

- No (disabled) if CONFIG_ESP_VBAT_INIT_AUTO

No (disabled) if CONFIG_ESP_VBAT_INIT_AUTO


##### CONFIG_ESP_VBAT_DET_LVL_LOW_SEL

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery > CONFIG_ESP_VBAT_INIT_AUTO > CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY

Available options:

- 2.6V (CONFIG_ESP_VBAT_DET_LVL_LOW_SEL_7)
- 2.52V (CONFIG_ESP_VBAT_DET_LVL_LOW_SEL_6)
- 2.42V (CONFIG_ESP_VBAT_DET_LVL_LOW_SEL_5)

2.6V (CONFIG_ESP_VBAT_DET_LVL_LOW_SEL_7)

2.52V (CONFIG_ESP_VBAT_DET_LVL_LOW_SEL_6)

2.42V (CONFIG_ESP_VBAT_DET_LVL_LOW_SEL_5)


##### CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery > CONFIG_ESP_VBAT_INIT_AUTO > CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY

Available options:

- 2.6V (CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL_7)
- 2.52V (CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL_6)
- 2.42V (CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL_5)

2.6V (CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL_7)

2.52V (CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL_6)

2.42V (CONFIG_ESP_VBAT_DET_LVL_HIGH_SEL_5)


##### CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery > CONFIG_ESP_VBAT_INIT_AUTO

Available options:

- 2.6V (CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL_7)
- 2.52V (CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL_6)
- 2.42V (CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL_5)

2.6V (CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL_7)

2.52V (CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL_6)

2.42V (CONFIG_ESP_VBAT_BROWNOUT_DET_LVL_SEL_5)


##### CONFIG_ESP_VBAT_WAKEUP_CHIP_ON_VBAT_BROWNOUT

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery


##### CONFIG_ESP_VBAT_CHARGER_CIRCUIT_RESISTOR_VAL

Found in: Component config > Hardware Settings > Power Supplier > RTC Backup Battery

- from 1000 to 8500 if CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY

from 1000 to 8500 if CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY

- 1000 if CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY

1000 if CONFIG_ESP_VBAT_USE_RECHARGEABLE_BATTERY


#### CONFIG_ESP_ENABLE_PVT

Found in: Component config > Hardware Settings

- Yes (enabled)


#### CONFIG_ESP_INTR_IN_IRAM

Found in: Component config > Hardware Settings

- Yes (enabled)


### ESP-Driver:LCD Controller Configurations

- CONFIG_LCD_DSI_ISR_CACHE_SAFE
- CONFIG_LCD_RGB_RESTART_IN_VSYNC
- CONFIG_LCD_ENABLE_DEBUG_LOG
- CONFIG_LCD_DSI_ISR_HANDLER_IN_IRAM
- CONFIG_LCD_RGB_ISR_IRAM_SAFE

CONFIG_LCD_DSI_ISR_CACHE_SAFE

CONFIG_LCD_RGB_RESTART_IN_VSYNC

CONFIG_LCD_ENABLE_DEBUG_LOG

CONFIG_LCD_DSI_ISR_HANDLER_IN_IRAM

CONFIG_LCD_RGB_ISR_IRAM_SAFE


#### CONFIG_LCD_RGB_ISR_IRAM_SAFE

Found in: Component config > ESP-Driver:LCD Controller Configurations

- No (disabled)


#### CONFIG_LCD_RGB_RESTART_IN_VSYNC

Found in: Component config > ESP-Driver:LCD Controller Configurations

- No (disabled)


#### CONFIG_LCD_DSI_ISR_HANDLER_IN_IRAM

Found in: Component config > ESP-Driver:LCD Controller Configurations

- Yes (enabled)


#### CONFIG_LCD_DSI_ISR_CACHE_SAFE

Found in: Component config > ESP-Driver:LCD Controller Configurations

- No (disabled)


#### CONFIG_LCD_ENABLE_DEBUG_LOG

Found in: Component config > ESP-Driver:LCD Controller Configurations

- No (disabled)


### LibC

- CONFIG_LIBC_ASSERT_BUFFER_SIZE
- CONFIG_LIBC_NEWLIB_NANO_FORMAT
- CONFIG_LIBC
- CONFIG_LIBC_STDIN_LINE_ENDING
- CONFIG_LIBC_STDOUT_LINE_ENDING
- CONFIG_LIBC_LOCKS_PLACE_IN_IRAM
- CONFIG_LIBC_MISC_IN_IRAM
- CONFIG_LIBC_TIME_SYSCALL
- CONFIG_LIBC_OPTIMIZED_MISALIGNED_ACCESS

CONFIG_LIBC_ASSERT_BUFFER_SIZE

CONFIG_LIBC_NEWLIB_NANO_FORMAT

CONFIG_LIBC

CONFIG_LIBC_STDIN_LINE_ENDING

CONFIG_LIBC_STDOUT_LINE_ENDING

CONFIG_LIBC_LOCKS_PLACE_IN_IRAM

CONFIG_LIBC_MISC_IN_IRAM

CONFIG_LIBC_TIME_SYSCALL

CONFIG_LIBC_OPTIMIZED_MISALIGNED_ACCESS


#### CONFIG_LIBC

Found in: Component config > LibC

Available options:

- NewLib (CONFIG_LIBC_NEWLIB)
- Picolibc (EXPERIMENTAL) (CONFIG_LIBC_PICOLIBC)

NewLib (CONFIG_LIBC_NEWLIB)

Picolibc (EXPERIMENTAL) (CONFIG_LIBC_PICOLIBC)


#### CONFIG_LIBC_MISC_IN_IRAM

Found in: Component config > LibC

- Yes (enabled)


#### CONFIG_LIBC_LOCKS_PLACE_IN_IRAM

Found in: Component config > LibC

- Yes (enabled)


#### CONFIG_LIBC_STDOUT_LINE_ENDING

Found in: Component config > LibC

Available options:

- CRLF (CONFIG_LIBC_STDOUT_LINE_ENDING_CRLF)
- LF (CONFIG_LIBC_STDOUT_LINE_ENDING_LF)
- CR (CONFIG_LIBC_STDOUT_LINE_ENDING_CR)

CRLF (CONFIG_LIBC_STDOUT_LINE_ENDING_CRLF)

LF (CONFIG_LIBC_STDOUT_LINE_ENDING_LF)

CR (CONFIG_LIBC_STDOUT_LINE_ENDING_CR)


#### CONFIG_LIBC_STDIN_LINE_ENDING

Found in: Component config > LibC

Available options:

- CRLF (CONFIG_LIBC_STDIN_LINE_ENDING_CRLF)
- LF (CONFIG_LIBC_STDIN_LINE_ENDING_LF)
- CR (CONFIG_LIBC_STDIN_LINE_ENDING_CR)

CRLF (CONFIG_LIBC_STDIN_LINE_ENDING_CRLF)

LF (CONFIG_LIBC_STDIN_LINE_ENDING_LF)

CR (CONFIG_LIBC_STDIN_LINE_ENDING_CR)


#### CONFIG_LIBC_NEWLIB_NANO_FORMAT

Found in: Component config > LibC


#### CONFIG_LIBC_TIME_SYSCALL

Found in: Component config > LibC

- If both high-resolution (systimer for all targets except ESP32)and RTC timers are used, timekeeping will continue in deep sleep. Time will be reported at 1 microsecond resolution. This is the default, and the recommended option.
- If only high-resolution timer (systimer) is used, gettimeofday willprovide time at microsecond resolution. Time will not be preserved when going into deep sleep mode.
- If only RTC timer is used, timekeeping will continue indeep sleep, but time will be measured at 6.(6) microsecond resolution. Also the gettimeofday function itself may take longer to run.
- If no timers are used, gettimeofday and time functionsreturn -1 and set errno to ENOSYS; they are defined as weak, so they could be overridden. If you want to customize gettimeofday() and other time functions, please choose this option and refer to the 'time.c' source file for the exact prototypes of these functions.
- When RTC is used for timekeeping, two RTC_STORE registers areused to keep time in deep sleep mode.

Available options:

- RTC and high-resolution timer (CONFIG_LIBC_TIME_SYSCALL_USE_RTC_HRT)
- RTC (CONFIG_LIBC_TIME_SYSCALL_USE_RTC)
- High-resolution timer (CONFIG_LIBC_TIME_SYSCALL_USE_HRT)
- None (CONFIG_LIBC_TIME_SYSCALL_USE_NONE)

RTC and high-resolution timer (CONFIG_LIBC_TIME_SYSCALL_USE_RTC_HRT)

RTC (CONFIG_LIBC_TIME_SYSCALL_USE_RTC)

High-resolution timer (CONFIG_LIBC_TIME_SYSCALL_USE_HRT)

None (CONFIG_LIBC_TIME_SYSCALL_USE_NONE)


#### CONFIG_LIBC_OPTIMIZED_MISALIGNED_ACCESS

Found in: Component config > LibC

- memcpy
- memset
- memmove
- str[n]cpy
- str[n]cmp

- Yes (enabled)


#### CONFIG_LIBC_ASSERT_BUFFER_SIZE

Found in: Component config > LibC

- from 100 to 2048

- 200


### ESP-MM: Memory Management Configurations

- CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS

CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS


#### CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS

Found in: Component config > ESP-MM: Memory Management Configurations


##### CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS_MAX_LEN

Found in: Component config > ESP-MM: Memory Management Configurations > CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS

- from 0 to 0x80000 if CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS

from 0 to 0x80000 if CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS

- "0x20000" if CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS

"0x20000" if CONFIG_ESP_MM_CACHE_MSYNC_C2M_CHUNKED_OPS


### ESP NETIF Adapter

- CONFIG_ESP_NETIF_SET_DNS_PER_DEFAULT_NETIF
- CONFIG_ESP_NETIF_LOST_IP_TIMER_ENABLE
- CONFIG_ESP_NETIF_BRIDGE_EN
- CONFIG_ESP_NETIF_L2_TAP
- CONFIG_ESP_NETIF_IP_LOST_TIMER_INTERVAL
- CONFIG_ESP_NETIF_REPORT_DATA_TRAFFIC
- CONFIG_ESP_NETIF_USE_TCPIP_STACK_LIB
- CONFIG_ESP_NETIF_PROVIDE_CUSTOM_IMPLEMENTATION

CONFIG_ESP_NETIF_SET_DNS_PER_DEFAULT_NETIF

CONFIG_ESP_NETIF_LOST_IP_TIMER_ENABLE

CONFIG_ESP_NETIF_BRIDGE_EN

CONFIG_ESP_NETIF_L2_TAP

CONFIG_ESP_NETIF_IP_LOST_TIMER_INTERVAL

CONFIG_ESP_NETIF_REPORT_DATA_TRAFFIC

CONFIG_ESP_NETIF_USE_TCPIP_STACK_LIB

CONFIG_ESP_NETIF_PROVIDE_CUSTOM_IMPLEMENTATION


#### CONFIG_ESP_NETIF_LOST_IP_TIMER_ENABLE

Found in: Component config > ESP NETIF Adapter

- Yes (enabled)


#### CONFIG_ESP_NETIF_IP_LOST_TIMER_INTERVAL

Found in: Component config > ESP NETIF Adapter

- from 0 to 65535

- 120


#### CONFIG_ESP_NETIF_PROVIDE_CUSTOM_IMPLEMENTATION

Found in: Component config > ESP NETIF Adapter

- No (disabled)


#### CONFIG_ESP_NETIF_USE_TCPIP_STACK_LIB

Found in: Component config > ESP NETIF Adapter

Available options:

- LwIP (CONFIG_ESP_NETIF_TCPIP_LWIP) lwIP is a small independent implementation of the TCP/IP protocol suite.
- Loopback (CONFIG_ESP_NETIF_LOOPBACK) Dummy implementation of esp-netif functionality which connects driver transmit to receive function. This option is for testing purpose only

LwIP (CONFIG_ESP_NETIF_TCPIP_LWIP)

Loopback (CONFIG_ESP_NETIF_LOOPBACK)


#### CONFIG_ESP_NETIF_REPORT_DATA_TRAFFIC

Found in: Component config > ESP NETIF Adapter

- Yes (enabled)


#### CONFIG_ESP_NETIF_L2_TAP

Found in: Component config > ESP NETIF Adapter


##### CONFIG_ESP_NETIF_L2_TAP_MAX_FDS

Found in: Component config > ESP NETIF Adapter > CONFIG_ESP_NETIF_L2_TAP

- from 1 to 10 if CONFIG_ESP_NETIF_L2_TAP

from 1 to 10 if CONFIG_ESP_NETIF_L2_TAP

- 5 if CONFIG_ESP_NETIF_L2_TAP

5 if CONFIG_ESP_NETIF_L2_TAP


##### CONFIG_ESP_NETIF_L2_TAP_RX_QUEUE_SIZE

Found in: Component config > ESP NETIF Adapter > CONFIG_ESP_NETIF_L2_TAP

- from 1 to 100 if CONFIG_ESP_NETIF_L2_TAP

from 1 to 100 if CONFIG_ESP_NETIF_L2_TAP

- 20 if CONFIG_ESP_NETIF_L2_TAP

20 if CONFIG_ESP_NETIF_L2_TAP


#### CONFIG_ESP_NETIF_BRIDGE_EN

Found in: Component config > ESP NETIF Adapter

- No (disabled)


#### CONFIG_ESP_NETIF_SET_DNS_PER_DEFAULT_NETIF

Found in: Component config > ESP NETIF Adapter

- No (disabled)


### Partition API Configuration


### PHY

- CONFIG_ESP_PHY_CALIBRATION_MODE
- CONFIG_ESP_PHY_DEBUG
- CONFIG_ESP_PHY_PLL_TRACK_DEBUG
- CONFIG_ESP_PHY_ENABLE_CERT_TEST
- CONFIG_ESP_PHY_IMPROVE_RX_11B
- CONFIG_ESP_PHY_ENABLE_USB
- CONFIG_ESP_PHY_MAX_WIFI_TX_POWER
- CONFIG_ESP_PHY_IRAM_OPT
- CONFIG_ESP_PHY_MAC_BB_PD
- CONFIG_ESP_PHY_RECORD_USED_TIME
- CONFIG_ESP_PHY_REDUCE_TX_POWER
- CONFIG_ESP_PHY_PLL_TRACK_PERIOD_MS
- CONFIG_ESP_PHY_CALIBRATION_AND_DATA_STORAGE
- CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION

CONFIG_ESP_PHY_CALIBRATION_MODE

CONFIG_ESP_PHY_DEBUG

CONFIG_ESP_PHY_PLL_TRACK_DEBUG

CONFIG_ESP_PHY_ENABLE_CERT_TEST

CONFIG_ESP_PHY_IMPROVE_RX_11B

CONFIG_ESP_PHY_ENABLE_USB

CONFIG_ESP_PHY_MAX_WIFI_TX_POWER

CONFIG_ESP_PHY_IRAM_OPT

CONFIG_ESP_PHY_MAC_BB_PD

CONFIG_ESP_PHY_RECORD_USED_TIME

CONFIG_ESP_PHY_REDUCE_TX_POWER

CONFIG_ESP_PHY_PLL_TRACK_PERIOD_MS

CONFIG_ESP_PHY_CALIBRATION_AND_DATA_STORAGE

CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION


#### CONFIG_ESP_PHY_CALIBRATION_AND_DATA_STORAGE

Found in: Component config > PHY


#### CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION

Found in: Component config > PHY

- CONFIG_ESP_PHY_DEFAULT_INIT_IF_INVALID
- CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN

CONFIG_ESP_PHY_DEFAULT_INIT_IF_INVALID

CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN


##### CONFIG_ESP_PHY_DEFAULT_INIT_IF_INVALID

Found in: Component config > PHY > CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION


##### CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN

Found in: Component config > PHY > CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION


##### CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN_EMBED

Found in: Component config > PHY > CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION > CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN


##### CONFIG_ESP_PHY_INIT_DATA_ERROR

Found in: Component config > PHY > CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION > CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN


#### CONFIG_ESP_PHY_MAX_WIFI_TX_POWER

Found in: Component config > PHY


#### CONFIG_ESP_PHY_MAC_BB_PD

Found in: Component config > PHY


#### CONFIG_ESP_PHY_REDUCE_TX_POWER

Found in: Component config > PHY


#### CONFIG_ESP_PHY_ENABLE_USB

Found in: Component config > PHY


#### CONFIG_ESP_PHY_ENABLE_CERT_TEST

Found in: Component config > PHY


#### CONFIG_ESP_PHY_CALIBRATION_MODE

Found in: Component config > PHY

Available options:

- Calibration partial (CONFIG_ESP_PHY_RF_CAL_PARTIAL)
- Calibration none (CONFIG_ESP_PHY_RF_CAL_NONE)
- Calibration full (CONFIG_ESP_PHY_RF_CAL_FULL)

Calibration partial (CONFIG_ESP_PHY_RF_CAL_PARTIAL)

Calibration none (CONFIG_ESP_PHY_RF_CAL_NONE)

Calibration full (CONFIG_ESP_PHY_RF_CAL_FULL)


#### CONFIG_ESP_PHY_IMPROVE_RX_11B

Found in: Component config > PHY


#### CONFIG_ESP_PHY_PLL_TRACK_PERIOD_MS

Found in: Component config > PHY


#### CONFIG_ESP_PHY_PLL_TRACK_DEBUG

Found in: Component config > PHY


#### CONFIG_ESP_PHY_RECORD_USED_TIME

Found in: Component config > PHY


#### CONFIG_ESP_PHY_IRAM_OPT

Found in: Component config > PHY


#### CONFIG_ESP_PHY_DEBUG

Found in: Component config > PHY

- CONFIG_ESP_PHY_DISABLE_PLL_TRACK

CONFIG_ESP_PHY_DISABLE_PLL_TRACK


##### CONFIG_ESP_PHY_DISABLE_PLL_TRACK

Found in: Component config > PHY > CONFIG_ESP_PHY_DEBUG


### Power Management

- CONFIG_PM_LIGHTSLEEP_RTC_OSC_CAL_INTERVAL
- CONFIG_PM_SLP_DISABLE_GPIO
- CONFIG_PM_LIGHT_SLEEP_CALLBACKS
- CONFIG_PM_SLEEP_FUNC_IN_IRAM
- CONFIG_PM_POWER_DOWN_CPU_IN_LIGHT_SLEEP
- CONFIG_PM_POWER_DOWN_PERIPHERAL_IN_LIGHT_SLEEP
- CONFIG_PM_SLP_IRAM_OPT
- CONFIG_PM_RTOS_IDLE_OPT
- Retentive memory alloaction strategy for light sleep
- CONFIG_PM_ENABLE

CONFIG_PM_LIGHTSLEEP_RTC_OSC_CAL_INTERVAL

CONFIG_PM_SLP_DISABLE_GPIO

CONFIG_PM_LIGHT_SLEEP_CALLBACKS

CONFIG_PM_SLEEP_FUNC_IN_IRAM

CONFIG_PM_POWER_DOWN_CPU_IN_LIGHT_SLEEP

CONFIG_PM_POWER_DOWN_PERIPHERAL_IN_LIGHT_SLEEP

CONFIG_PM_SLP_IRAM_OPT

CONFIG_PM_RTOS_IDLE_OPT

CONFIG_PM_ENABLE


#### CONFIG_PM_SLEEP_FUNC_IN_IRAM

Found in: Component config > Power Management

- Yes (enabled)


#### CONFIG_PM_ENABLE

Found in: Component config > Power Management

- No (disabled)


##### CONFIG_PM_DFS_INIT_AUTO

Found in: Component config > Power Management > CONFIG_PM_ENABLE

- No (disabled) if CONFIG_PM_ENABLE

No (disabled) if CONFIG_PM_ENABLE


##### CONFIG_PM_PROFILING

Found in: Component config > Power Management > CONFIG_PM_ENABLE

- No (disabled) if CONFIG_PM_ENABLE

No (disabled) if CONFIG_PM_ENABLE


##### CONFIG_PM_TRACE

Found in: Component config > Power Management > CONFIG_PM_ENABLE

- No (disabled) if CONFIG_PM_ENABLE

No (disabled) if CONFIG_PM_ENABLE


#### CONFIG_PM_SLP_IRAM_OPT

Found in: Component config > Power Management


#### CONFIG_PM_RTOS_IDLE_OPT

Found in: Component config > Power Management


#### CONFIG_PM_SLP_DISABLE_GPIO

Found in: Component config > Power Management


#### CONFIG_PM_LIGHTSLEEP_RTC_OSC_CAL_INTERVAL

Found in: Component config > Power Management

- from 1 to 128 if CONFIG_PM_ENABLE

from 1 to 128 if CONFIG_PM_ENABLE

- 1 if CONFIG_PM_ENABLE

1 if CONFIG_PM_ENABLE


#### CONFIG_PM_POWER_DOWN_CPU_IN_LIGHT_SLEEP

Found in: Component config > Power Management


#### Retentive memory alloaction strategy for light sleep

Available options:

- Dynamically allocate memory (CONFIG_PM_CPU_RETENTION_DYNAMIC) Allocate memory for retention data only when preparing to enter light sleep.
- Statically allocate memory (CONFIG_PM_CPU_RETENTION_STATIC) Pre-allocate all required retention memory during system initialization.

Dynamically allocate memory (CONFIG_PM_CPU_RETENTION_DYNAMIC)

Statically allocate memory (CONFIG_PM_CPU_RETENTION_STATIC)


#### CONFIG_PM_POWER_DOWN_PERIPHERAL_IN_LIGHT_SLEEP

Found in: Component config > Power Management


#### CONFIG_PM_LIGHT_SLEEP_CALLBACKS

Found in: Component config > Power Management

- No (disabled) if CONFIG_FREERTOS_USE_TICKLESS_IDLE

No (disabled) if CONFIG_FREERTOS_USE_TICKLESS_IDLE


### ESP PSRAM

- CONFIG_SPIRAM

CONFIG_SPIRAM


#### CONFIG_SPIRAM

Found in: Component config > ESP PSRAM


##### PSRAM config

- CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY
- CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY
- CONFIG_SPIRAM_XIP_FROM_PSRAM
- CONFIG_SPIRAM_ECC_ENABLE
- CONFIG_SPIRAM_IGNORE_NOTFOUND
- CONFIG_SPIRAM_BOOT_HW_INIT
- CONFIG_SPIRAM_MODE
- CONFIG_SPIRAM_MALLOC_ALWAYSINTERNAL
- CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION
- CONFIG_SPIRAM_MALLOC_RESERVE_INTERNAL
- CONFIG_SPIRAM_MEMTEST
- CONFIG_SPIRAM_SPEED
- CONFIG_SPIRAM_USE
- CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP

CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY

CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY

CONFIG_SPIRAM_XIP_FROM_PSRAM

CONFIG_SPIRAM_ECC_ENABLE

CONFIG_SPIRAM_IGNORE_NOTFOUND

CONFIG_SPIRAM_BOOT_HW_INIT

CONFIG_SPIRAM_MODE

CONFIG_SPIRAM_MALLOC_ALWAYSINTERNAL

CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION

CONFIG_SPIRAM_MALLOC_RESERVE_INTERNAL

CONFIG_SPIRAM_MEMTEST

CONFIG_SPIRAM_SPEED

CONFIG_SPIRAM_USE

CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP


##### CONFIG_SPIRAM_MODE

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config

Available options:

- 16-Line-Mode PSRAM (CONFIG_SPIRAM_MODE_HEX)

16-Line-Mode PSRAM (CONFIG_SPIRAM_MODE_HEX)


##### CONFIG_SPIRAM_SPEED

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config

Available options:

- 200MHz clock speed (CONFIG_SPIRAM_SPEED_200M)
- 80MHz clock speed (CONFIG_SPIRAM_SPEED_80M)
- 20MHz clock speed (CONFIG_SPIRAM_SPEED_20M)

200MHz clock speed (CONFIG_SPIRAM_SPEED_200M)

80MHz clock speed (CONFIG_SPIRAM_SPEED_80M)

20MHz clock speed (CONFIG_SPIRAM_SPEED_20M)


##### CONFIG_SPIRAM_XIP_FROM_PSRAM

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_ECC_ENABLE

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_BOOT_HW_INIT

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_BOOT_INIT

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config > CONFIG_SPIRAM_BOOT_HW_INIT


##### CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_IGNORE_NOTFOUND

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_USE

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config

Available options:

- Integrate RAM into memory map (CONFIG_SPIRAM_USE_MEMMAP)
- Make RAM allocatable using heap_caps_malloc(..., MALLOC_CAP_SPIRAM) (CONFIG_SPIRAM_USE_CAPS_ALLOC)
- Make RAM allocatable using malloc() as well (CONFIG_SPIRAM_USE_MALLOC)

Integrate RAM into memory map (CONFIG_SPIRAM_USE_MEMMAP)


##### CONFIG_SPIRAM_MEMTEST

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_MALLOC_ALWAYSINTERNAL

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_MALLOC_RESERVE_INTERNAL

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


##### CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY

Found in: Component config > ESP PSRAM > CONFIG_SPIRAM > PSRAM config


### ESP Ringbuf

- CONFIG_RINGBUF_PLACE_ISR_FUNCTIONS_INTO_FLASH
- CONFIG_RINGBUF_IN_IRAM

CONFIG_RINGBUF_PLACE_ISR_FUNCTIONS_INTO_FLASH

CONFIG_RINGBUF_IN_IRAM


#### CONFIG_RINGBUF_IN_IRAM

Found in: Component config > ESP Ringbuf

- No (disabled)


#### CONFIG_RINGBUF_PLACE_ISR_FUNCTIONS_INTO_FLASH

Found in: Component config > ESP Ringbuf


### ESP-ROM

- CONFIG_ESP_ROM_PRINT_IN_IRAM

CONFIG_ESP_ROM_PRINT_IN_IRAM


#### CONFIG_ESP_ROM_PRINT_IN_IRAM

Found in: Component config > ESP-ROM

- Yes (enabled)


### ESP Security Specific

- Crypto DPA Protection
- CONFIG_ESP_ECDSA_ENABLE_P192_CURVE
- CONFIG_ESP_CRYPTO_FORCE_ECC_CONSTANT_TIME_POINT_MUL

CONFIG_ESP_ECDSA_ENABLE_P192_CURVE

CONFIG_ESP_CRYPTO_FORCE_ECC_CONSTANT_TIME_POINT_MUL


#### Crypto DPA Protection

- CONFIG_ESP_CRYPTO_DPA_PROTECTION_AT_STARTUP

CONFIG_ESP_CRYPTO_DPA_PROTECTION_AT_STARTUP


##### CONFIG_ESP_CRYPTO_DPA_PROTECTION_AT_STARTUP

Found in: Component config > ESP Security Specific > Crypto DPA Protection

- Yes (enabled) if SOC_CRYPTO_DPA_PROTECTION_SUPPORTED


##### CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL

Found in: Component config > ESP Security Specific > Crypto DPA Protection > CONFIG_ESP_CRYPTO_DPA_PROTECTION_AT_STARTUP

Available options:

- Security level low (CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL_LOW)
- Security level medium (CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL_MEDIUM)
- Security level high (CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL_HIGH)

Security level low (CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL_LOW)

Security level medium (CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL_MEDIUM)

Security level high (CONFIG_ESP_CRYPTO_DPA_PROTECTION_LEVEL_HIGH)


#### CONFIG_ESP_CRYPTO_FORCE_ECC_CONSTANT_TIME_POINT_MUL

Found in: Component config > ESP Security Specific

- No (disabled)


#### CONFIG_ESP_ECDSA_ENABLE_P192_CURVE

Found in: Component config > ESP Security Specific

- No (disabled) if SOC_ECDSA_P192_CURVE_DEFAULT_DISABLED


### ESP-STDIO

- CONFIG_ESP_CONSOLE_UART
- CONFIG_ESP_CONSOLE_SECONDARY
- CONFIG_ESP_CONSOLE_UART_BAUDRATE
- CONFIG_ESP_CONSOLE_UART_NUM
- CONFIG_ESP_CONSOLE_UART_RX_GPIO
- CONFIG_ESP_CONSOLE_UART_TX_GPIO

CONFIG_ESP_CONSOLE_UART

CONFIG_ESP_CONSOLE_SECONDARY

CONFIG_ESP_CONSOLE_UART_BAUDRATE

CONFIG_ESP_CONSOLE_UART_NUM

CONFIG_ESP_CONSOLE_UART_RX_GPIO

CONFIG_ESP_CONSOLE_UART_TX_GPIO


#### CONFIG_ESP_CONSOLE_UART

Found in: Component config > ESP-STDIO

- Default is to use UART0 on pre-defined GPIOs.
- If "Custom" is selected, UART0 or UART1 can be chosen, and any pins can be selected.
- If "None" is selected, there will be no console output on any UART, except for initial output from ROM bootloader. This ROM output can be suppressed by GPIO strapping or EFUSE, refer to chip datasheet for details.
- On chips with USB OTG peripheral, "USB CDC" option redirects output to the CDC port. This option uses the CDC driver in the chip ROM. This option is incompatible with TinyUSB stack.
- On chips with an USB serial/JTAG debug controller, selecting the option for that redirects output to the CDC/ACM (serial port emulation) component of that device.

Available options:

- Default: UART0 (CONFIG_ESP_CONSOLE_UART_DEFAULT)
- USB CDC (CONFIG_ESP_CONSOLE_USB_CDC)
- USB Serial/JTAG Controller (CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG)
- Custom UART (CONFIG_ESP_CONSOLE_UART_CUSTOM)
- None (CONFIG_ESP_CONSOLE_NONE)

Default: UART0 (CONFIG_ESP_CONSOLE_UART_DEFAULT)

USB CDC (CONFIG_ESP_CONSOLE_USB_CDC)

USB Serial/JTAG Controller (CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG)

Custom UART (CONFIG_ESP_CONSOLE_UART_CUSTOM)

None (CONFIG_ESP_CONSOLE_NONE)


#### CONFIG_ESP_CONSOLE_SECONDARY

Found in: Component config > ESP-STDIO

Available options:

- No secondary console (CONFIG_ESP_CONSOLE_SECONDARY_NONE)
- USB_SERIAL_JTAG PORT (CONFIG_ESP_CONSOLE_SECONDARY_USB_SERIAL_JTAG) This option supports output through USB_SERIAL_JTAG port when the UART0 port is not connected. The output currently only supports non-blocking mode without using the console. If you want to output in blocking mode with REPL or input through USB_SERIAL_JTAG port, please change the primary config to ESP_CONSOLE_USB_SERIAL_JTAG above.

No secondary console (CONFIG_ESP_CONSOLE_SECONDARY_NONE)

USB_SERIAL_JTAG PORT (CONFIG_ESP_CONSOLE_SECONDARY_USB_SERIAL_JTAG)


#### CONFIG_ESP_CONSOLE_UART_NUM

Found in: Component config > ESP-STDIO

Available options:

- UART0 (CONFIG_ESP_CONSOLE_UART_CUSTOM_NUM_0)
- UART1 (CONFIG_ESP_CONSOLE_UART_CUSTOM_NUM_1)

UART0 (CONFIG_ESP_CONSOLE_UART_CUSTOM_NUM_0)

UART1 (CONFIG_ESP_CONSOLE_UART_CUSTOM_NUM_1)


#### CONFIG_ESP_CONSOLE_UART_TX_GPIO

Found in: Component config > ESP-STDIO

- from -1 to 54 if CONFIG_ESP_CONSOLE_UART_CUSTOM

from -1 to 54 if CONFIG_ESP_CONSOLE_UART_CUSTOM

- 37 if CONFIG_ESP_CONSOLE_UART_CUSTOM
- "-1" if CONFIG_ESP_CONSOLE_UART_CUSTOM

37 if CONFIG_ESP_CONSOLE_UART_CUSTOM

"-1" if CONFIG_ESP_CONSOLE_UART_CUSTOM


#### CONFIG_ESP_CONSOLE_UART_RX_GPIO

Found in: Component config > ESP-STDIO

- from -1 to 54 if CONFIG_ESP_CONSOLE_UART_CUSTOM

from -1 to 54 if CONFIG_ESP_CONSOLE_UART_CUSTOM

- 38 if CONFIG_ESP_CONSOLE_UART_CUSTOM
- "-1" if CONFIG_ESP_CONSOLE_UART_CUSTOM

38 if CONFIG_ESP_CONSOLE_UART_CUSTOM

"-1" if CONFIG_ESP_CONSOLE_UART_CUSTOM


#### CONFIG_ESP_CONSOLE_UART_BAUDRATE

Found in: Component config > ESP-STDIO

- from 1200 to 1000000 if CONFIG_PM_ENABLE

from 1200 to 1000000 if CONFIG_PM_ENABLE

- 115200


### ESP System Settings

- CONFIG_ESP_BACKTRACING_METHOD
- CONFIG_ESP_SYSTEM_RTC_EXT_XTAL_BOOTSTRAP_CYCLES
- Cache config
- CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ
- CONFIG_ESP_SYSTEM_MEMPROT
- CONFIG_ESP_SYSTEM_ALLOW_RTC_FAST_MEM_AS_HEAP
- CONFIG_ESP_TASK_WDT_EN
- CONFIG_ESP_SYSTEM_EVENT_TASK_STACK_SIZE
- CONFIG_ESP_SYSTEM_HW_PC_RECORD
- CONFIG_ESP_SYSTEM_HW_STACK_GUARD
- CONFIG_ESP_XT_WDT
- CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL
- CONFIG_ESP_INT_WDT
- CONFIG_ESP_MAIN_TASK_AFFINITY
- CONFIG_ESP_MAIN_TASK_STACK_SIZE
- CONFIG_ESP_DEBUG_OCDAWARE
- CONFIG_ESP_MINIMAL_SHARED_STACK_SIZE
- CONFIG_ESP_DEBUG_STUBS_ENABLE
- CONFIG_ESP_SYSTEM_PANIC
- CONFIG_ESP_SYSTEM_PANIC_REBOOT_DELAY_SECONDS
- CONFIG_ESP_PANIC_HANDLER_IRAM
- CONFIG_ESP_SYSTEM_IN_IRAM
- CONFIG_ESP_DEBUG_INCLUDE_OCD_STUB_BINS
- CONFIG_ESP_SYSTEM_EVENT_QUEUE_SIZE

CONFIG_ESP_BACKTRACING_METHOD

CONFIG_ESP_SYSTEM_RTC_EXT_XTAL_BOOTSTRAP_CYCLES

CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ

CONFIG_ESP_SYSTEM_MEMPROT

CONFIG_ESP_SYSTEM_ALLOW_RTC_FAST_MEM_AS_HEAP

CONFIG_ESP_TASK_WDT_EN

CONFIG_ESP_SYSTEM_EVENT_TASK_STACK_SIZE

CONFIG_ESP_SYSTEM_HW_PC_RECORD

CONFIG_ESP_SYSTEM_HW_STACK_GUARD

CONFIG_ESP_XT_WDT

CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL

CONFIG_ESP_INT_WDT

CONFIG_ESP_MAIN_TASK_AFFINITY

CONFIG_ESP_MAIN_TASK_STACK_SIZE

CONFIG_ESP_DEBUG_OCDAWARE

CONFIG_ESP_MINIMAL_SHARED_STACK_SIZE

CONFIG_ESP_DEBUG_STUBS_ENABLE

CONFIG_ESP_SYSTEM_PANIC

CONFIG_ESP_SYSTEM_PANIC_REBOOT_DELAY_SECONDS

CONFIG_ESP_PANIC_HANDLER_IRAM

CONFIG_ESP_SYSTEM_IN_IRAM

CONFIG_ESP_DEBUG_INCLUDE_OCD_STUB_BINS

CONFIG_ESP_SYSTEM_EVENT_QUEUE_SIZE


#### CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ

Found in: Component config > ESP System Settings

Available options:

- 40 MHz (CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_40)
- 360 MHz (CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_360)
- 400 MHz (CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_400)

40 MHz (CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_40)

360 MHz (CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_360)

400 MHz (CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_400)


#### Cache config

- CONFIG_CACHE_L2_CACHE_LINE_SIZE
- CONFIG_CACHE_L2_CACHE_SIZE

CONFIG_CACHE_L2_CACHE_LINE_SIZE

CONFIG_CACHE_L2_CACHE_SIZE


##### CONFIG_CACHE_L2_CACHE_SIZE

Found in: Component config > ESP System Settings > Cache config

Available options:

- 128KB (CONFIG_CACHE_L2_CACHE_128KB)
- 256KB (CONFIG_CACHE_L2_CACHE_256KB)
- 512KB (CONFIG_CACHE_L2_CACHE_512KB)

128KB (CONFIG_CACHE_L2_CACHE_128KB)

256KB (CONFIG_CACHE_L2_CACHE_256KB)

512KB (CONFIG_CACHE_L2_CACHE_512KB)


##### CONFIG_CACHE_L2_CACHE_LINE_SIZE

Found in: Component config > ESP System Settings > Cache config

Available options:

- 64 Bytes (CONFIG_CACHE_L2_CACHE_LINE_64B)
- 128 Bytes (CONFIG_CACHE_L2_CACHE_LINE_128B)

64 Bytes (CONFIG_CACHE_L2_CACHE_LINE_64B)

128 Bytes (CONFIG_CACHE_L2_CACHE_LINE_128B)


#### CONFIG_ESP_SYSTEM_IN_IRAM

Found in: Component config > ESP System Settings

- Yes (enabled)


#### CONFIG_ESP_SYSTEM_PANIC

Found in: Component config > ESP System Settings

Available options:

- Print registers and halt (CONFIG_ESP_SYSTEM_PANIC_PRINT_HALT) Outputs the relevant registers over the serial port and halt the processor. Needs a manual reset to restart.
- Print registers and reboot (CONFIG_ESP_SYSTEM_PANIC_PRINT_REBOOT) Outputs the relevant registers over the serial port and immediately reset the processor.
- Silent reboot (CONFIG_ESP_SYSTEM_PANIC_SILENT_REBOOT) Just resets the processor without outputting anything
- GDBStub on panic (CONFIG_ESP_SYSTEM_PANIC_GDBSTUB) Invoke gdbstub on the serial port, allowing for gdb to attach to it to do a postmortem of the crash.

Print registers and halt (CONFIG_ESP_SYSTEM_PANIC_PRINT_HALT)

Print registers and reboot (CONFIG_ESP_SYSTEM_PANIC_PRINT_REBOOT)

Silent reboot (CONFIG_ESP_SYSTEM_PANIC_SILENT_REBOOT)

GDBStub on panic (CONFIG_ESP_SYSTEM_PANIC_GDBSTUB)


#### CONFIG_ESP_SYSTEM_PANIC_REBOOT_DELAY_SECONDS

Found in: Component config > ESP System Settings

- from 0 to 99

- 0


#### CONFIG_ESP_SYSTEM_RTC_EXT_XTAL_BOOTSTRAP_CYCLES

Found in: Component config > ESP System Settings


#### CONFIG_ESP_SYSTEM_ALLOW_RTC_FAST_MEM_AS_HEAP

Found in: Component config > ESP System Settings

- Yes (enabled)


#### CONFIG_ESP_BACKTRACING_METHOD

Found in: Component config > ESP System Settings

Available options:

- No backtracing (CONFIG_ESP_SYSTEM_NO_BACKTRACE) When selected, no backtracing will be performed at runtime. By using idf.py monitor, it is still possible to get a backtrace when a panic occurs.
- Use CPU Frame Pointer register (CONFIG_ESP_SYSTEM_USE_FRAME_POINTER) This configuration allows the compiler to allocate CPU register s0 as the frame pointer. The main usage of the frame pointer is to be able to generate a backtrace from the panic handler on exception. Enabling this option results in bigger and slightly slower code since all functions will have to populate this register and won't be able to use it as a general-purpose register anymore.

No backtracing (CONFIG_ESP_SYSTEM_NO_BACKTRACE)

Generate and use eh_frame for backtracing (CONFIG_ESP_SYSTEM_USE_EH_FRAME)

Use CPU Frame Pointer register (CONFIG_ESP_SYSTEM_USE_FRAME_POINTER)


#### CONFIG_ESP_SYSTEM_MEMPROT

Found in: Component config > ESP System Settings

- Yes (enabled)


##### CONFIG_ESP_SYSTEM_MEMPROT_MODE

Found in: Component config > ESP System Settings > CONFIG_ESP_SYSTEM_MEMPROT

Available options:

- Enable Permission Control Module (PMS) configurations (CONFIG_ESP_SYSTEM_MEMPROT_PMS) This option enables memory protection using the Permission Control Module (PMS).
- Enable CPU's Physical Memory Protection (PMP) configurations (CONFIG_ESP_SYSTEM_MEMPROT_PMP) This option enables memory protection using CPU PMP.
- Enable Trusted Execution Environment (TEE) configurations (CONFIG_ESP_SYSTEM_MEMPROT_TEE) This option enables the default memory protection provided by TEE.


##### CONFIG_ESP_SYSTEM_MEMPROT_PMS_LOCK

Found in: Component config > ESP System Settings > CONFIG_ESP_SYSTEM_MEMPROT

- Yes (enabled) if CONFIG_ESP_SYSTEM_MEMPROT && CONFIG_ESP_SYSTEM_MEMPROT_PMS

Yes (enabled) if CONFIG_ESP_SYSTEM_MEMPROT && CONFIG_ESP_SYSTEM_MEMPROT_PMS


##### CONFIG_ESP_SYSTEM_MEMPROT_PMP_LP_CORE_RESERVE_MEM_EXEC

Found in: Component config > ESP System Settings > CONFIG_ESP_SYSTEM_MEMPROT

- No (disabled)


#### CONFIG_ESP_SYSTEM_EVENT_QUEUE_SIZE

Found in: Component config > ESP System Settings

- 32


#### CONFIG_ESP_SYSTEM_EVENT_TASK_STACK_SIZE

Found in: Component config > ESP System Settings

- 2304


#### CONFIG_ESP_MAIN_TASK_STACK_SIZE

Found in: Component config > ESP System Settings

- 3584


#### CONFIG_ESP_MAIN_TASK_AFFINITY

Found in: Component config > ESP System Settings

Available options:

- CPU0 (CONFIG_ESP_MAIN_TASK_AFFINITY_CPU0)
- CPU1 (CONFIG_ESP_MAIN_TASK_AFFINITY_CPU1)
- No affinity (CONFIG_ESP_MAIN_TASK_AFFINITY_NO_AFFINITY)

CPU0 (CONFIG_ESP_MAIN_TASK_AFFINITY_CPU0)

CPU1 (CONFIG_ESP_MAIN_TASK_AFFINITY_CPU1)

No affinity (CONFIG_ESP_MAIN_TASK_AFFINITY_NO_AFFINITY)


#### CONFIG_ESP_MINIMAL_SHARED_STACK_SIZE

Found in: Component config > ESP System Settings

- 2048


#### CONFIG_ESP_INT_WDT

Found in: Component config > ESP System Settings

- Yes (enabled)


##### CONFIG_ESP_INT_WDT_TIMEOUT_MS

Found in: Component config > ESP System Settings > CONFIG_ESP_INT_WDT

- from 10 to 10000

- 300


##### CONFIG_ESP_INT_WDT_CHECK_CPU1

Found in: Component config > ESP System Settings > CONFIG_ESP_INT_WDT


#### CONFIG_ESP_TASK_WDT_EN

Found in: Component config > ESP System Settings

- Yes (enabled)


##### CONFIG_ESP_TASK_WDT_INIT

Found in: Component config > ESP System Settings > CONFIG_ESP_TASK_WDT_EN

- Yes (enabled)


##### CONFIG_ESP_TASK_WDT_PANIC

Found in: Component config > ESP System Settings > CONFIG_ESP_TASK_WDT_EN > CONFIG_ESP_TASK_WDT_INIT

- No (disabled)


##### CONFIG_ESP_TASK_WDT_TIMEOUT_S

Found in: Component config > ESP System Settings > CONFIG_ESP_TASK_WDT_EN > CONFIG_ESP_TASK_WDT_INIT

- from 1 to 60

- 5


##### CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU0

Found in: Component config > ESP System Settings > CONFIG_ESP_TASK_WDT_EN > CONFIG_ESP_TASK_WDT_INIT

- Yes (enabled)


##### CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU1

Found in: Component config > ESP System Settings > CONFIG_ESP_TASK_WDT_EN > CONFIG_ESP_TASK_WDT_INIT


#### CONFIG_ESP_XT_WDT

Found in: Component config > ESP System Settings


##### CONFIG_ESP_XT_WDT_TIMEOUT

Found in: Component config > ESP System Settings > CONFIG_ESP_XT_WDT

- from 1 to 255 if CONFIG_ESP_XT_WDT

from 1 to 255 if CONFIG_ESP_XT_WDT

- 200 if CONFIG_ESP_XT_WDT

200 if CONFIG_ESP_XT_WDT


##### CONFIG_ESP_XT_WDT_BACKUP_CLK_ENABLE

Found in: Component config > ESP System Settings > CONFIG_ESP_XT_WDT

- Yes (enabled) if CONFIG_ESP_XT_WDT

Yes (enabled) if CONFIG_ESP_XT_WDT


#### CONFIG_ESP_PANIC_HANDLER_IRAM

Found in: Component config > ESP System Settings

- No (disabled)


#### CONFIG_ESP_DEBUG_STUBS_ENABLE

Found in: Component config > ESP System Settings


#### CONFIG_ESP_DEBUG_INCLUDE_OCD_STUB_BINS

Found in: Component config > ESP System Settings

- No (disabled) if SOC_DEBUG_HAVE_OCD_STUB_BINS


#### CONFIG_ESP_DEBUG_OCDAWARE

Found in: Component config > ESP System Settings

- Yes (enabled)


#### CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL

Found in: Component config > ESP System Settings

Available options:

- Level 5 interrupt (CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL_5) Using level 5 interrupt for Interrupt Watchdog, IPC_ISR and other system checks.
- Level 4 interrupt (CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL_4) Using level 4 interrupt for Interrupt Watchdog, IPC_ISR and other system checks.

Level 5 interrupt (CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL_5)

Level 4 interrupt (CONFIG_ESP_SYSTEM_CHECK_INT_LEVEL_4)


#### CONFIG_ESP_SYSTEM_HW_STACK_GUARD

Found in: Component config > ESP System Settings


#### CONFIG_ESP_SYSTEM_HW_PC_RECORD

Found in: Component config > ESP System Settings

- Yes (enabled)


### IPC (Inter-Processor Call)

- CONFIG_ESP_IPC_TASK_STACK_SIZE
- CONFIG_ESP_IPC_USES_CALLERS_PRIORITY

CONFIG_ESP_IPC_TASK_STACK_SIZE

CONFIG_ESP_IPC_USES_CALLERS_PRIORITY


#### CONFIG_ESP_IPC_TASK_STACK_SIZE

Found in: Component config > IPC (Inter-Processor Call)

- from 2048 to 65536 if APPTRACE_ENABLE

- 2048 if APPTRACE_ENABLE
- 1024


#### CONFIG_ESP_IPC_USES_CALLERS_PRIORITY

Found in: Component config > IPC (Inter-Processor Call)

- Yes (enabled)


### ESP Timer (High Resolution Timer)

- CONFIG_ESP_TIMER_PROFILING
- CONFIG_ESP_TIMER_TASK_AFFINITY
- CONFIG_ESP_TIMER_TASK_STACK_SIZE
- CONFIG_ESP_TIMER_INTERRUPT_LEVEL
- CONFIG_ESP_TIMER_IN_IRAM
- CONFIG_ESP_TIMER_SHOW_EXPERIMENTAL
- CONFIG_ESP_TIMER_SUPPORTS_ISR_DISPATCH_METHOD
- CONFIG_ESP_TIMER_ISR_AFFINITY

CONFIG_ESP_TIMER_PROFILING

CONFIG_ESP_TIMER_TASK_AFFINITY

CONFIG_ESP_TIMER_TASK_STACK_SIZE

CONFIG_ESP_TIMER_INTERRUPT_LEVEL

CONFIG_ESP_TIMER_IN_IRAM

CONFIG_ESP_TIMER_SHOW_EXPERIMENTAL

CONFIG_ESP_TIMER_SUPPORTS_ISR_DISPATCH_METHOD

CONFIG_ESP_TIMER_ISR_AFFINITY


#### CONFIG_ESP_TIMER_IN_IRAM

Found in: Component config > ESP Timer (High Resolution Timer)

- Yes (enabled)


#### CONFIG_ESP_TIMER_PROFILING

Found in: Component config > ESP Timer (High Resolution Timer)

- No (disabled)


#### CONFIG_ESP_TIMER_TASK_STACK_SIZE

Found in: Component config > ESP Timer (High Resolution Timer)

- from 2048 to 65536

- 3584


#### CONFIG_ESP_TIMER_INTERRUPT_LEVEL

Found in: Component config > ESP Timer (High Resolution Timer)

- from 1 to 1

- 1


#### CONFIG_ESP_TIMER_SHOW_EXPERIMENTAL

Found in: Component config > ESP Timer (High Resolution Timer)


#### CONFIG_ESP_TIMER_TASK_AFFINITY

Found in: Component config > ESP Timer (High Resolution Timer)

Available options:

- CPU0 (CONFIG_ESP_TIMER_TASK_AFFINITY_CPU0)
- CPU1 (CONFIG_ESP_TIMER_TASK_AFFINITY_CPU1)
- No affinity (CONFIG_ESP_TIMER_TASK_AFFINITY_NO_AFFINITY)

CPU0 (CONFIG_ESP_TIMER_TASK_AFFINITY_CPU0)

CPU1 (CONFIG_ESP_TIMER_TASK_AFFINITY_CPU1)

No affinity (CONFIG_ESP_TIMER_TASK_AFFINITY_NO_AFFINITY)


#### CONFIG_ESP_TIMER_ISR_AFFINITY

Found in: Component config > ESP Timer (High Resolution Timer)

Available options:

- CPU0 (CONFIG_ESP_TIMER_ISR_AFFINITY_CPU0)
- CPU1 (CONFIG_ESP_TIMER_ISR_AFFINITY_CPU1)
- No affinity (CONFIG_ESP_TIMER_ISR_AFFINITY_NO_AFFINITY)

CPU0 (CONFIG_ESP_TIMER_ISR_AFFINITY_CPU0)

CPU1 (CONFIG_ESP_TIMER_ISR_AFFINITY_CPU1)

No affinity (CONFIG_ESP_TIMER_ISR_AFFINITY_NO_AFFINITY)


#### CONFIG_ESP_TIMER_SUPPORTS_ISR_DISPATCH_METHOD

Found in: Component config > ESP Timer (High Resolution Timer)

- No (disabled)


### ESP Trace Configuration

- Application Level Tracing
- SEGGER SystemView
- CONFIG_ESP_TRACE_LIBRARY
- CONFIG_ESP_TRACE_TIMESTAMP_SOURCE
- CONFIG_ESP_TRACE_TRANSPORT

CONFIG_ESP_TRACE_LIBRARY

CONFIG_ESP_TRACE_TIMESTAMP_SOURCE

CONFIG_ESP_TRACE_TRANSPORT


#### CONFIG_ESP_TRACE_LIBRARY

Found in: Component config > ESP Trace Configuration

Available options:

- SEGGER SystemView (CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW)
- External library from component registry (CONFIG_ESP_TRACE_LIB_EXTERNAL) Use a custom encoder provided by an external component. The trace core system will be enabled but no built-in encoder is included. The external component MUST provide a header file named "esp_trace_freertos_impl.h" in its include directories that defines all required FreeRTOS trace macros.
- Disabled (CONFIG_ESP_TRACE_LIB_NONE)

SEGGER SystemView (CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW)

External library from component registry (CONFIG_ESP_TRACE_LIB_EXTERNAL)

Disabled (CONFIG_ESP_TRACE_LIB_NONE)


#### SEGGER SystemView

- CONFIG_SEGGER_SYSVIEW_DEST_CPU
- CONFIG_SEGGER_SYSVIEW_EVT_ISR_ENTER_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_ISR_EXIT_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_ISR_TO_SCHED_ENABLE
- CONFIG_SEGGER_SYSVIEW_MAX_TASKS
- CONFIG_SEGGER_SYSVIEW_EVT_IDLE_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TASK_CREATE_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TASK_START_EXEC_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TASK_START_READY_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TASK_STOP_EXEC_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TASK_STOP_READY_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TASK_TERMINATE_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TIMER_ENTER_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_TIMER_EXIT_ENABLE
- CONFIG_SEGGER_SYSVIEW_EVT_OVERFLOW_ENABLE
- CONFIG_SEGGER_SYSVIEW_BUF_WAIT_TMO

CONFIG_SEGGER_SYSVIEW_DEST_CPU

CONFIG_SEGGER_SYSVIEW_EVT_ISR_ENTER_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_ISR_EXIT_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_ISR_TO_SCHED_ENABLE

CONFIG_SEGGER_SYSVIEW_MAX_TASKS

CONFIG_SEGGER_SYSVIEW_EVT_IDLE_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TASK_CREATE_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TASK_START_EXEC_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TASK_START_READY_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TASK_STOP_EXEC_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TASK_STOP_READY_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TASK_TERMINATE_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TIMER_ENTER_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_TIMER_EXIT_ENABLE

CONFIG_SEGGER_SYSVIEW_EVT_OVERFLOW_ENABLE

CONFIG_SEGGER_SYSVIEW_BUF_WAIT_TMO


##### CONFIG_SEGGER_SYSVIEW_DEST_CPU

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

Available options:

- CPU0 (CONFIG_SEGGER_SYSVIEW_DEST_CPU_0) Send tracing data for Pro CPU.
- CPU1 (CONFIG_SEGGER_SYSVIEW_DEST_CPU_1) Send tracing data for App CPU.

CPU0 (CONFIG_SEGGER_SYSVIEW_DEST_CPU_0)

CPU1 (CONFIG_SEGGER_SYSVIEW_DEST_CPU_1)


##### CONFIG_SEGGER_SYSVIEW_MAX_TASKS

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- from 1 to 64 if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

from 1 to 64 if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

- 16 if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

16 if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_BUF_WAIT_TMO

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- 500 if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

500 if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_OVERFLOW_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_ISR_ENTER_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_ISR_EXIT_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_ISR_TO_SCHED_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TASK_START_EXEC_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TASK_STOP_EXEC_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TASK_START_READY_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TASK_STOP_READY_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TASK_CREATE_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TASK_TERMINATE_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_IDLE_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TIMER_ENTER_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


##### CONFIG_SEGGER_SYSVIEW_EVT_TIMER_EXIT_ENABLE

Found in: Component config > ESP Trace Configuration > SEGGER SystemView

- Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW

Yes (enabled) if CONFIG_ESP_TRACE_LIB_SEGGER_SYSVIEW


#### CONFIG_ESP_TRACE_TRANSPORT

Found in: Component config > ESP Trace Configuration

Available options:

- ESP-IDF apptrace (CONFIG_ESP_TRACE_TRANSPORT_APPTRACE)
- External transport from component registry (CONFIG_ESP_TRACE_TRANSPORT_EXTERNAL) Use a transport registered by an external component. The trace core system will be enabled but no built-in transport is included.
- None (CONFIG_ESP_TRACE_TRANSPORT_NONE)

ESP-IDF apptrace (CONFIG_ESP_TRACE_TRANSPORT_APPTRACE)

None (CONFIG_ESP_TRACE_TRANSPORT_NONE)


#### Application Level Tracing

- CONFIG_APPTRACE_DESTINATION
- CONFIG_APPTRACE_LOCK_ENABLE
- CONFIG_APPTRACE_BUF_SIZE
- CONFIG_APPTRACE_POSTMORTEM_FLUSH_THRESH
- CONFIG_APPTRACE_ONPANIC_HOST_FLUSH_TMO
- CONFIG_APPTRACE_UART_BAUDRATE
- CONFIG_APPTRACE_DEST_UART_NUM
- CONFIG_APPTRACE_UART_RX_GPIO
- CONFIG_APPTRACE_UART_TASK_PRIO
- CONFIG_APPTRACE_UART_TX_MSG_SIZE
- CONFIG_APPTRACE_UART_TX_GPIO
- CONFIG_APPTRACE_UART_TX_BUFF_SIZE

CONFIG_APPTRACE_DESTINATION

CONFIG_APPTRACE_LOCK_ENABLE

CONFIG_APPTRACE_BUF_SIZE

CONFIG_APPTRACE_POSTMORTEM_FLUSH_THRESH

CONFIG_APPTRACE_ONPANIC_HOST_FLUSH_TMO

CONFIG_APPTRACE_UART_BAUDRATE

CONFIG_APPTRACE_DEST_UART_NUM

CONFIG_APPTRACE_UART_RX_GPIO

CONFIG_APPTRACE_UART_TASK_PRIO

CONFIG_APPTRACE_UART_TX_MSG_SIZE

CONFIG_APPTRACE_UART_TX_GPIO

CONFIG_APPTRACE_UART_TX_BUFF_SIZE


##### CONFIG_APPTRACE_DESTINATION

Found in: Component config > ESP Trace Configuration > Application Level Tracing

Available options:

- JTAG (CONFIG_APPTRACE_DEST_JTAG)
- UART (CONFIG_APPTRACE_DEST_UART)
- All (runtime selection) (CONFIG_APPTRACE_DEST_ALL) Compile both JTAG and UART interfaces in advance (higher IRAM usage). Allows runtime switching between JTAG and UART via esp_apptrace_get_user_params(). If esp_apptrace_get_user_params() is not provided by the application, JTAG is used by default with the default configuration defined in components/app_trace/include/esp_app_trace_config.h.

JTAG (CONFIG_APPTRACE_DEST_JTAG)

UART (CONFIG_APPTRACE_DEST_UART)

All (runtime selection) (CONFIG_APPTRACE_DEST_ALL)


##### CONFIG_APPTRACE_BUF_SIZE

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- 16384 if CONFIG_APPTRACE_DEST_JTAG && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

16384 if CONFIG_APPTRACE_DEST_JTAG && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_DEST_UART_NUM

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 0 to 5 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 0 to 5 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 1 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

1 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_UART_TX_GPIO

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 0 to 46 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 0 to 46 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 12 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

12 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_UART_RX_GPIO

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 0 to 46 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 0 to 46 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 13 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

13 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_UART_BAUDRATE

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 1200 to 8000000 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE
- from 1200 to 1000000 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 1200 to 8000000 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 1200 to 1000000 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 1000000 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

1000000 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_UART_TX_BUFF_SIZE

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 2048 to 32768 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 2048 to 32768 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 4096 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

4096 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_UART_TX_MSG_SIZE

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 64 to 32768 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 64 to 32768 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 128 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

128 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_UART_TASK_PRIO

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 1 to 32 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 1 to 32 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 1 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

1 if CONFIG_APPTRACE_DEST_UART && CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_LOCK_ENABLE

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- No (disabled) if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

No (disabled) if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_ONPANIC_HOST_FLUSH_TMO

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from -1 to 5000 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from -1 to 5000 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- "-1" if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

"-1" if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


##### CONFIG_APPTRACE_POSTMORTEM_FLUSH_THRESH

Found in: Component config > ESP Trace Configuration > Application Level Tracing

- from 0 to 16384 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

from 0 to 16384 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

- 0 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE

0 if CONFIG_ESP_TRACE_TRANSPORT_APPTRACE


#### CONFIG_ESP_TRACE_TIMESTAMP_SOURCE

Found in: Component config > ESP Trace Configuration

Available options:

- CPU cycle counter (CCOUNT) (CONFIG_ESP_TRACE_TS_SOURCE_CCOUNT)
- General Purpose Timer (Timer Group) (CONFIG_ESP_TRACE_TS_SOURCE_GPTIMER)
- esp_timer high resolution timer (CONFIG_ESP_TRACE_TS_SOURCE_ESP_TIMER)

CPU cycle counter (CCOUNT) (CONFIG_ESP_TRACE_TS_SOURCE_CCOUNT)

General Purpose Timer (Timer Group) (CONFIG_ESP_TRACE_TS_SOURCE_GPTIMER)

esp_timer high resolution timer (CONFIG_ESP_TRACE_TS_SOURCE_ESP_TIMER)


### Wi-Fi

CONFIG_ESP_WIFI_WPS_SOFTAP_REGISTRAR

CONFIG_ESP_WIFI_ENABLE_ROAMING_APP

CONFIG_ESP_WIFI_11KV_SUPPORT

CONFIG_ESP_WIFI_11R_SUPPORT

CONFIG_ESP_WIFI_BSS_MAX_IDLE_SUPPORT

CONFIG_ESP_WIFI_DPP_SUPPORT

CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT

CONFIG_ESP_WIFI_MBO_SUPPORT

CONFIG_ESP_WIFI_SUITE_B_192

CONFIG_ESP_WIFI_ENABLE_WPA3_OWE_STA

CONFIG_ESP_WIFI_WAPI_PSK

CONFIG_ESP_WIFI_NAN_SYNC_ENABLE

CONFIG_ESP_WIFI_NAN_USD_ENABLE

CONFIG_ESP_WIFI_ENABLE_DUMP_CTRL_BFRP

CONFIG_ESP_WIFI_ENABLE_DUMP_HESIGB

CONFIG_ESP_WIFI_ENABLE_DUMP_MU_CFO

CONFIG_ESP_WIFI_ENABLE_DUMP_CTRL_NDPA

CONFIG_ESP_WIFI_ENABLE_WIFI_RX_STATS

CONFIG_ESP_WIFI_ENABLE_WIFI_TX_STATS

CONFIG_ESP_WIFI_WPA3_COMPATIBLE_SUPPORT

CONFIG_ESP_WIFI_ENABLE_WPA3_SAE

CONFIG_ESP_HOST_WIFI_ENABLED

CONFIG_ESP_WIFI_SCAN_CACHE

CONFIG_ESP_WIFI_SOFTAP_BEACON_MAX_LEN

CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM

CONFIG_ESP_WIFI_DYNAMIC_RX_BUFFER_NUM

CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER_NUM

CONFIG_ESP_WIFI_RX_MGMT_BUF_NUM_DEF

CONFIG_ESP_WIFI_STATIC_RX_BUFFER_NUM

CONFIG_ESP_WIFI_STATIC_TX_BUFFER_NUM

CONFIG_ESP_WIFI_ESPNOW_MAX_ENCRYPT_NUM

CONFIG_ESP_WIFI_SLP_DEFAULT_MAX_ACTIVE_TIME

CONFIG_ESP_WIFI_SLP_DEFAULT_MIN_ACTIVE_TIME

CONFIG_ESP_WIFI_SLP_DEFAULT_WAIT_BROADCAST_DATA_TIME

CONFIG_ESP_WIFI_STA_DISCONNECTED_PM_ENABLE

CONFIG_ESP_WIFI_DEBUG_PRINT

CONFIG_ESP_WIFI_MGMT_RX_BUFFER

CONFIG_ESP_WIFI_TX_BUFFER

CONFIG_ESP_WIFI_MBEDTLS_CRYPTO

CONFIG_ESP_WIFI_AMPDU_RX_ENABLED

CONFIG_ESP_WIFI_AMPDU_TX_ENABLED

CONFIG_ESP_WIFI_AMSDU_TX_ENABLED

CONFIG_ESP_WIFI_CSI_ENABLED

CONFIG_ESP_WIFI_EXTRA_IRAM_OPT

CONFIG_ESP_WIFI_FTM_ENABLE

CONFIG_ESP_WIFI_GCMP_SUPPORT

CONFIG_ESP_WIFI_GMAC_SUPPORT

CONFIG_ESP_WIFI_IRAM_OPT

CONFIG_ESP_WIFI_MGMT_SBUF_NUM

CONFIG_ESP_WIFI_ENHANCED_LIGHT_SLEEP

CONFIG_ESP_WIFI_NVS_ENABLED

CONFIG_ESP_WIFI_RX_IRAM_OPT

CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

CONFIG_ESP_WIFI_SLP_IRAM_OPT

CONFIG_ESP_WIFI_SOFTAP_SUPPORT

CONFIG_ESP_WIFI_TASK_CORE_ID

CONFIG_ESP_WIFI_TX_HETB_QUEUE_NUM


#### CONFIG_ESP_HOST_WIFI_ENABLED

Found in: Component config > Wi-Fi

- No (disabled)


#### CONFIG_ESP_WIFI_STATIC_RX_BUFFER_NUM

Found in: Component config > Wi-Fi

- from 2 to 128 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

from 2 to 128 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

- 10 if CONFIG_ESP_HOST_WIFI_ENABLED

10 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_DYNAMIC_RX_BUFFER_NUM

Found in: Component config > Wi-Fi

- from 0 to 1024 if CONFIG_LWIP_WND_SCALE && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 1024 if CONFIG_LWIP_WND_SCALE && CONFIG_ESP_HOST_WIFI_ENABLED

- 32 if CONFIG_ESP_HOST_WIFI_ENABLED

32 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_TX_BUFFER

Found in: Component config > Wi-Fi

Available options:

- Static (CONFIG_ESP_WIFI_STATIC_TX_BUFFER)
- Dynamic (CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER)

Static (CONFIG_ESP_WIFI_STATIC_TX_BUFFER)

Dynamic (CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER)


#### CONFIG_ESP_WIFI_STATIC_TX_BUFFER_NUM

Found in: Component config > Wi-Fi

- from 1 to 64 if CONFIG_ESP_WIFI_STATIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 64 if CONFIG_ESP_WIFI_STATIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED

- 16 if CONFIG_ESP_WIFI_STATIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED

16 if CONFIG_ESP_WIFI_STATIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM

Found in: Component config > Wi-Fi


#### CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER_NUM

Found in: Component config > Wi-Fi

- from 1 to 128 if CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 128 if CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED

- 32 if CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED

32 if CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_MGMT_RX_BUFFER

Found in: Component config > Wi-Fi

Available options:

- Static (CONFIG_ESP_WIFI_STATIC_RX_MGMT_BUFFER)
- Dynamic (CONFIG_ESP_WIFI_DYNAMIC_RX_MGMT_BUFFER)

Static (CONFIG_ESP_WIFI_STATIC_RX_MGMT_BUFFER)

Dynamic (CONFIG_ESP_WIFI_DYNAMIC_RX_MGMT_BUFFER)


#### CONFIG_ESP_WIFI_RX_MGMT_BUF_NUM_DEF

Found in: Component config > Wi-Fi

- from 1 to 10 if CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 10 if CONFIG_ESP_HOST_WIFI_ENABLED

- 5 if CONFIG_ESP_HOST_WIFI_ENABLED

5 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_CSI_ENABLED

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_CSI_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_CSI_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_AMPDU_TX_ENABLED

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_TX_BA_WIN

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_AMPDU_TX_ENABLED

- from 2 to 64 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_WIFI_AMPDU_TX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED

from 2 to 64 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_WIFI_AMPDU_TX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED

- 6 if CONFIG_ESP_WIFI_AMPDU_TX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED

6 if CONFIG_ESP_WIFI_AMPDU_TX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_AMPDU_RX_ENABLED

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_RX_BA_WIN

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_AMPDU_RX_ENABLED

- from 2 to 64 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_WIFI_AMPDU_RX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED

from 2 to 64 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_WIFI_AMPDU_RX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED

- 6 if CONFIG_ESP_WIFI_AMPDU_RX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED

6 if CONFIG_ESP_WIFI_AMPDU_RX_ENABLED && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_AMSDU_TX_ENABLED

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM >= 2 && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM >= 2 && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_NVS_ENABLED

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_TASK_CORE_ID

Found in: Component config > Wi-Fi

Available options:

- Core 0 (CONFIG_ESP_WIFI_TASK_PINNED_TO_CORE_0)
- Core 1 (CONFIG_ESP_WIFI_TASK_PINNED_TO_CORE_1)

Core 0 (CONFIG_ESP_WIFI_TASK_PINNED_TO_CORE_0)

Core 1 (CONFIG_ESP_WIFI_TASK_PINNED_TO_CORE_1)


#### CONFIG_ESP_WIFI_SOFTAP_BEACON_MAX_LEN

Found in: Component config > Wi-Fi

- from 752 to 1256 if CONFIG_ESP_HOST_WIFI_ENABLED

from 752 to 1256 if CONFIG_ESP_HOST_WIFI_ENABLED

- 752 if CONFIG_ESP_HOST_WIFI_ENABLED

752 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_MGMT_SBUF_NUM

Found in: Component config > Wi-Fi

- from 6 to 32 if CONFIG_ESP_HOST_WIFI_ENABLED

from 6 to 32 if CONFIG_ESP_HOST_WIFI_ENABLED

- 32 if CONFIG_ESP_HOST_WIFI_ENABLED

32 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_IRAM_OPT

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_EXTRA_IRAM_OPT

Found in: Component config > Wi-Fi

- Yes (enabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED
- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_RX_IRAM_OPT

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_WPA3_SAE

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ENABLE_SAE_H2E

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_WPA3_SAE

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_WPA3_SAE && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_WPA3_SAE && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ENABLE_SAE_PK

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_WPA3_SAE > CONFIG_ESP_WIFI_ENABLE_SAE_H2E

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_SAE_H2E && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_SAE_H2E && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SOFTAP_SAE_SUPPORT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_WPA3_SAE

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_WPA3_SAE && CONFIG_ESP_WIFI_SOFTAP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_WPA3_SAE && CONFIG_ESP_WIFI_SOFTAP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_WPA3_OWE_STA

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_WPA3_COMPATIBLE_SUPPORT

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_SAE_H2E && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_SAE_H2E && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SLP_IRAM_OPT

Found in: Component config > Wi-Fi

- Yes (enabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SLP_DEFAULT_MIN_ACTIVE_TIME

Found in: Component config > Wi-Fi

- from 8 to 60 if CONFIG_ESP_HOST_WIFI_ENABLED

from 8 to 60 if CONFIG_ESP_HOST_WIFI_ENABLED

- 50 if CONFIG_ESP_HOST_WIFI_ENABLED

50 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_BSS_MAX_IDLE_SUPPORT

Found in: Component config > Wi-Fi

- Yes (enabled) if (SOC_WIFI_HE_SUPPORT || CONFIG_ESP_WIFI_WNM_SUPPORT) && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if (SOC_WIFI_HE_SUPPORT || CONFIG_ESP_WIFI_WNM_SUPPORT) && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SLP_DEFAULT_MAX_ACTIVE_TIME

Found in: Component config > Wi-Fi

- from 10 to 60 if CONFIG_ESP_HOST_WIFI_ENABLED

from 10 to 60 if CONFIG_ESP_HOST_WIFI_ENABLED

- 10 if CONFIG_ESP_HOST_WIFI_ENABLED

10 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SLP_DEFAULT_WAIT_BROADCAST_DATA_TIME

Found in: Component config > Wi-Fi

- from 10 to 30 if CONFIG_ESP_HOST_WIFI_ENABLED

from 10 to 30 if CONFIG_ESP_HOST_WIFI_ENABLED

- 15 if CONFIG_ESP_HOST_WIFI_ENABLED

15 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_FTM_ENABLE

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_FTM_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_FTM_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_FTM_INITIATOR_SUPPORT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_FTM_ENABLE

- Yes (enabled) if CONFIG_ESP_WIFI_FTM_ENABLE && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_FTM_ENABLE && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_FTM_RESPONDER_SUPPORT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_FTM_ENABLE

- Yes (enabled) if CONFIG_ESP_WIFI_FTM_ENABLE && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_FTM_ENABLE && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_STA_DISCONNECTED_PM_ENABLE

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_GCMP_SUPPORT

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_GCMP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_GCMP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_GMAC_SUPPORT

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SOFTAP_SUPPORT

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENHANCED_LIGHT_SLEEP

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_PHY_MAC_BB_PD && SOC_PM_SUPPORT_BEACON_WAKEUP && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_PHY_MAC_BB_PD && SOC_PM_SUPPORT_BEACON_WAKEUP && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

Found in: Component config > Wi-Fi


##### CONFIG_ESP_WIFI_SLP_BEACON_LOST_TIMEOUT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

- from 5 to 100 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED

from 5 to 100 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED

- 10 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED

10 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_BEACON_LOST_THRESHOLD

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

- from 0 to 8 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 8 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED

- 3 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED

3 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_PHY_ON_DELTA_EARLY_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

- from 0 to 100 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 100 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED

- 2 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED

2 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_PHY_OFF_DELTA_TIMEOUT_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

- from 0 to 8 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 8 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED

- 2 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED

2 if CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT && SOC_WIFI_SUPPORT_VARIABLE_BEACON_WINDOW && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_POLICY

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT

- "Receive beacon": Keep RF on until a beacon is successfully received.
- "Drop beacon": Turn off RF and skip beacon reception during this period.
- "Auto": Beacon will been dropped only if ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE enabledand expected rx beacon probability stays below the standard.

Available options:

- Receive beacon (CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_RECEIVE)
- Drop beacon (CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_DROP)
- Auto (CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_AUTO)

Receive beacon (CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_RECEIVE)

Drop beacon (CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_DROP)

Auto (CONFIG_ESP_WIFI_SLP_BEACON_LOST_OVER_THRESHOLD_AUTO)


##### CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_SLP_BEACON_LOST_OPT


#### Beacon Sample Configuration Options

- CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_DIFFERENCE_PERCENT
- CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_RESAMPLE_PERIOD
- CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_COUNT
- CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_STANDARD_PERCENT

CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_DIFFERENCE_PERCENT

CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_RESAMPLE_PERIOD

CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_COUNT

CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_STANDARD_PERCENT


##### CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_COUNT

Found in: Component config > Wi-Fi > Beacon Sample Configuration Options

- from 100 to 1200 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

from 100 to 1200 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

- 300 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

300 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_DIFFERENCE_PERCENT

Found in: Component config > Wi-Fi > Beacon Sample Configuration Options

- from 0 to 100 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 100 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

- 20 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

20 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_STANDARD_PERCENT

Found in: Component config > Wi-Fi > Beacon Sample Configuration Options

- from 0 to 100 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 100 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

- 55 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

55 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_RESAMPLE_PERIOD

Found in: Component config > Wi-Fi > Beacon Sample Configuration Options

- from 0 to 255 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 255 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

- 3 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED

3 if CONFIG_ESP_WIFI_SLP_SAMPLE_BEACON_FEATURE && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ESPNOW_MAX_ENCRYPT_NUM

Found in: Component config > Wi-Fi

- from 0 to 17 if CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 17 if CONFIG_ESP_HOST_WIFI_ENABLED

- 7 if CONFIG_ESP_HOST_WIFI_ENABLED

7 if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_NAN_SYNC_ENABLE

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_NAN_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_NAN_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_NAN_USD_ENABLE

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_IDF_EXPERIMENTAL_FEATURES && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_IDF_EXPERIMENTAL_FEATURES && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_MBEDTLS_CRYPTO

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_MBEDTLS_TLS_CLIENT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_MBEDTLS_CRYPTO

- Yes (enabled) if CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT && CONFIG_ESP_WIFI_MBEDTLS_CRYPTO && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT && CONFIG_ESP_WIFI_MBEDTLS_CRYPTO && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_EAP_TLS1_3

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_MBEDTLS_CRYPTO > CONFIG_ESP_WIFI_MBEDTLS_TLS_CLIENT

- No (disabled) if CONFIG_ESP_WIFI_MBEDTLS_TLS_CLIENT && CONFIG_IDF_EXPERIMENTAL_FEATURES && CONFIG_ESP_WIFI_MBEDTLS_CRYPTO && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_MBEDTLS_TLS_CLIENT && CONFIG_IDF_EXPERIMENTAL_FEATURES && CONFIG_ESP_WIFI_MBEDTLS_CRYPTO && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_WAPI_PSK

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_WAPI_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_WAPI_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SUITE_B_192

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT && SOC_WIFI_GCMP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT && SOC_WIFI_GCMP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_11KV_SUPPORT

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_RRM_SUPPORT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_11KV_SUPPORT

- Yes (enabled) if CONFIG_ESP_WIFI_11KV_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_11KV_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_WNM_SUPPORT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_11KV_SUPPORT

- Yes (enabled) if CONFIG_ESP_WIFI_11KV_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_11KV_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_SCAN_CACHE

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_WIFI_RRM_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_RRM_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_MBO_SUPPORT

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_ROAMING_APP

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_IDF_EXPERIMENTAL_FEATURES && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_IDF_EXPERIMENTAL_FEATURES && CONFIG_ESP_HOST_WIFI_ENABLED


##### Configure roaming App

- Blacklist Configuration
- CONFIG_ESP_WIFI_ROAMING_BACKOFF_TIME
- Roaming Methods
- Roaming triggers
- Scan Configuration
- CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING

CONFIG_ESP_WIFI_ROAMING_BACKOFF_TIME

CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING


##### Roaming triggers

- CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR
- CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING

CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR

CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING


##### CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_THRESHOLD

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers > CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING

- from -99 to -30 if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from -99 to -30 if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- "-60" if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

"-60" if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_OFFSET

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers > CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING

- from 0 to 99 if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 99 if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 5 if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

5 if CONFIG_ESP_WIFI_ROAMING_LOW_RSSI_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_THRESHOLD

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers > CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR

- from -99 to -1 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from -99 to -1 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- "-50" if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

"-50" if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_SCAN_MONITOR_INTERVAL

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers > CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR

- from 1 to 1500 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 1500 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 30 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

30 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_SCAN_ROAM_RSSI_DIFF

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming triggers > CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR

- from 0 to 99 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 99 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 15 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

15 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_SCAN_MONITOR && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### Roaming Methods

- CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING
- CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM

CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING

CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM


##### CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming Methods

- Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming Methods

- No (disabled) if CONFIG_ESP_WIFI_WNM_SUPPORT && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_WNM_SUPPORT && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_NETWORK_ASSISTED_ROAMING_RETRY_COUNT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming Methods > CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM

- from 1 to 5 if CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM && CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 5 if CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM && CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 2 if CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM && CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

2 if CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM && CONFIG_ESP_WIFI_ROAMING_LEGACY_ROAMING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_NETWORK_ASSISTED_ROAMING_IP_RENEW_SKIP

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Roaming Methods > CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM

- No (disabled) if CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_ROAMING_NETWORK_ASSISTED_ROAM && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### Scan Configuration

- CONFIG_ESP_WIFI_ROAMING_HOME_CHANNEL_DWELL_TIME
- CONFIG_ESP_WIFI_ROAMING_SCAN_MAX_SCAN_TIME
- CONFIG_ESP_WIFI_ROAMING_SCAN_MIN_SCAN_TIME
- CONFIG_ESP_WIFI_ROAMING_SCAN_CHAN_LIST
- CONFIG_ESP_WIFI_ROAMING_SCAN_EXPIRY_WINDOW

CONFIG_ESP_WIFI_ROAMING_HOME_CHANNEL_DWELL_TIME

CONFIG_ESP_WIFI_ROAMING_SCAN_MAX_SCAN_TIME

CONFIG_ESP_WIFI_ROAMING_SCAN_MIN_SCAN_TIME

CONFIG_ESP_WIFI_ROAMING_SCAN_CHAN_LIST

CONFIG_ESP_WIFI_ROAMING_SCAN_EXPIRY_WINDOW


##### CONFIG_ESP_WIFI_ROAMING_SCAN_MIN_SCAN_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Scan Configuration

- from 0 to 120 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 120 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 30 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

30 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_SCAN_MAX_SCAN_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Scan Configuration

- from 30 to 120 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 30 to 120 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 70 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

70 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_HOME_CHANNEL_DWELL_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Scan Configuration

- from 30 to 150 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 30 to 150 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 30 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

30 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_SCAN_CHAN_LIST

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Scan Configuration

- "None" if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

"None" if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_SCAN_EXPIRY_WINDOW

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Scan Configuration

- from 5 to 20 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 5 to 20 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 10 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

10 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_BACKOFF_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App

- from 0 to 120 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 120 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 15 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

15 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App

- Yes (enabled) if CONFIG_ESP_WIFI_RRM_SUPPORT && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_WIFI_RRM_SUPPORT && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_RRM_MONITOR_TIME

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING

- from 0 to 1500 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 0 to 1500 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 60 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

60 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_RRM_MONITOR_THRESHOLD

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING

- from -99 to 0 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from -99 to 0 if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- "-20" if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

"-20" if CONFIG_ESP_WIFI_ROAMING_PERIODIC_RRM_MONITORING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### Blacklist Configuration

- CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST
- CONFIG_ESP_WIFI_ROAMING_MAX_CANDIDATES
- CONFIG_ESP_WIFI_ROAMING_PREVENT_DOWNGRADE

CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST

CONFIG_ESP_WIFI_ROAMING_MAX_CANDIDATES

CONFIG_ESP_WIFI_ROAMING_PREVENT_DOWNGRADE


##### CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Blacklist Configuration

- No (disabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_AUTO_BLACKLISTING

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Blacklist Configuration > CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST


##### CONFIG_ESP_WIFI_ROAMING_MAX_CONN_FAILURES

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Blacklist Configuration > CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST > CONFIG_ESP_WIFI_ROAMING_AUTO_BLACKLISTING

- from 1 to 10 if CONFIG_ESP_WIFI_ROAMING_AUTO_BLACKLISTING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 10 if CONFIG_ESP_WIFI_ROAMING_AUTO_BLACKLISTING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 3 if CONFIG_ESP_WIFI_ROAMING_AUTO_BLACKLISTING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

3 if CONFIG_ESP_WIFI_ROAMING_AUTO_BLACKLISTING && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_BLACKLIST_TIMEOUT

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Blacklist Configuration > CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST

- from 10 to 3600 if CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 10 to 3600 if CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 300 if CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

300 if CONFIG_ESP_WIFI_ROAMING_BSSID_BLACKLIST && CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_MAX_CANDIDATES

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Blacklist Configuration

- from 1 to 10 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 10 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

- 5 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

5 if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ROAMING_PREVENT_DOWNGRADE

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_ROAMING_APP > Configure roaming App > Blacklist Configuration

- No (disabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_ENABLE_ROAMING_APP && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_DPP_SUPPORT

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_11R_SUPPORT

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_WPS_SOFTAP_REGISTRAR

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_WIFI_SOFTAP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_SOFTAP_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_WIFI_TX_STATS

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_WIFI_RX_STATS

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ENABLE_WIFI_RX_MU_STATS

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENABLE_WIFI_RX_STATS

- No (disabled) if CONFIG_ESP_WIFI_ENABLE_WIFI_RX_STATS && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_ENABLE_WIFI_RX_STATS && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_TX_HETB_QUEUE_NUM

Found in: Component config > Wi-Fi

- from 1 to 4 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

from 1 to 4 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

- 3 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

3 if SOC_WIFI_HE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_DUMP_HESIGB

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_DUMP_MU_CFO

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_DUMP_CTRL_NDPA

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENABLE_DUMP_CTRL_BFRP

Found in: Component config > Wi-Fi

- No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if SOC_WIFI_SUPPORT_5G && CONFIG_ESP_HOST_WIFI_ENABLED


#### WPS Configuration Options

- CONFIG_ESP_WIFI_WPS_PASSPHRASE
- CONFIG_ESP_WIFI_WPS_RECONNECT_ON_FAIL
- CONFIG_ESP_WIFI_WPS_STRICT

CONFIG_ESP_WIFI_WPS_PASSPHRASE

CONFIG_ESP_WIFI_WPS_RECONNECT_ON_FAIL

CONFIG_ESP_WIFI_WPS_STRICT


##### CONFIG_ESP_WIFI_WPS_STRICT

Found in: Component config > Wi-Fi > WPS Configuration Options

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_WPS_PASSPHRASE

Found in: Component config > Wi-Fi > WPS Configuration Options

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_WPS_RECONNECT_ON_FAIL

Found in: Component config > Wi-Fi > WPS Configuration Options

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_DEBUG_PRINT

Found in: Component config > Wi-Fi

- No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_HOST_WIFI_ENABLED


#### CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT

Found in: Component config > Wi-Fi

- Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED

Yes (enabled) if CONFIG_ESP_HOST_WIFI_ENABLED


##### CONFIG_ESP_WIFI_ENT_FREE_DYNAMIC_BUFFER

Found in: Component config > Wi-Fi > CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT

- No (disabled) if CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED

No (disabled) if CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT && CONFIG_ESP_HOST_WIFI_ENABLED


### Core dump

- CONFIG_ESP_COREDUMP_CHECK_BOOT
- CONFIG_ESP_COREDUMP_TO_FLASH_OR_UART
- CONFIG_ESP_COREDUMP_UART_DELAY
- CONFIG_ESP_COREDUMP_FLASH_NO_OVERWRITE
- CONFIG_ESP_COREDUMP_LOGS
- CONFIG_ESP_COREDUMP_DECODE
- CONFIG_ESP_COREDUMP_CAPTURE_DRAM
- CONFIG_ESP_COREDUMP_MAX_TASKS_NUM
- CONFIG_ESP_COREDUMP_STACK_SIZE
- CONFIG_ESP_COREDUMP_SUMMARY_STACKDUMP_SIZE

CONFIG_ESP_COREDUMP_CHECK_BOOT

CONFIG_ESP_COREDUMP_TO_FLASH_OR_UART

CONFIG_ESP_COREDUMP_UART_DELAY

CONFIG_ESP_COREDUMP_FLASH_NO_OVERWRITE

CONFIG_ESP_COREDUMP_LOGS

CONFIG_ESP_COREDUMP_DECODE

CONFIG_ESP_COREDUMP_CAPTURE_DRAM

CONFIG_ESP_COREDUMP_MAX_TASKS_NUM

CONFIG_ESP_COREDUMP_STACK_SIZE

CONFIG_ESP_COREDUMP_SUMMARY_STACKDUMP_SIZE


#### CONFIG_ESP_COREDUMP_TO_FLASH_OR_UART

Found in: Component config > Core dump

Available options:

- Flash (CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH)
- UART (CONFIG_ESP_COREDUMP_ENABLE_TO_UART)
- None (CONFIG_ESP_COREDUMP_ENABLE_TO_NONE)

Flash (CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH)

UART (CONFIG_ESP_COREDUMP_ENABLE_TO_UART)

None (CONFIG_ESP_COREDUMP_ENABLE_TO_NONE)


#### CONFIG_ESP_COREDUMP_CAPTURE_DRAM

Found in: Component config > Core dump


#### CONFIG_ESP_COREDUMP_CHECK_BOOT

Found in: Component config > Core dump

- Yes (enabled) if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

Yes (enabled) if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH


#### CONFIG_ESP_COREDUMP_LOGS

Found in: Component config > Core dump


#### CONFIG_ESP_COREDUMP_MAX_TASKS_NUM

Found in: Component config > Core dump


#### CONFIG_ESP_COREDUMP_UART_DELAY

Found in: Component config > Core dump

- 0 if CONFIG_ESP_COREDUMP_ENABLE_TO_UART

0 if CONFIG_ESP_COREDUMP_ENABLE_TO_UART


#### CONFIG_ESP_COREDUMP_FLASH_NO_OVERWRITE

Found in: Component config > Core dump

- No (disabled) if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

No (disabled) if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH


#### CONFIG_ESP_COREDUMP_STACK_SIZE

Found in: Component config > Core dump


#### CONFIG_ESP_COREDUMP_SUMMARY_STACKDUMP_SIZE

Found in: Component config > Core dump

- from 512 to 4096 if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

from 512 to 4096 if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

- 1024 if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH

1024 if CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH


#### CONFIG_ESP_COREDUMP_DECODE

Found in: Component config > Core dump

Available options:

- Decode and show summary (info_corefile) (CONFIG_ESP_COREDUMP_DECODE_INFO)
- Don't decode (CONFIG_ESP_COREDUMP_DECODE_DISABLE)

Decode and show summary (info_corefile) (CONFIG_ESP_COREDUMP_DECODE_INFO)

Don't decode (CONFIG_ESP_COREDUMP_DECODE_DISABLE)


### FAT Filesystem support

- CONFIG_FATFS_API_ENCODING
- CONFIG_FATFS_VFS_FSTAT_BLKSIZE
- CONFIG_FATFS_IMMEDIATE_FSYNC
- CONFIG_FATFS_USE_FASTSEEK
- CONFIG_FATFS_USE_STRFUNC_CHOICE
- CONFIG_FATFS_FAST_SEEK_BUFFER_SIZE
- CONFIG_FATFS_STRF_ENCODE_CHOICE
- File system free space calculation behavior
- CONFIG_FATFS_LONG_FILENAMES
- CONFIG_FATFS_PRINT_FLOAT
- CONFIG_FATFS_PRINT_LLI
- CONFIG_FATFS_MAX_LFN
- CONFIG_FATFS_FS_LOCK
- CONFIG_FATFS_VOLUME_COUNT
- CONFIG_FATFS_CHOOSE_CODEPAGE
- CONFIG_FATFS_LINK_LOCK
- CONFIG_FATFS_ALLOC_PREFER_EXTRAM
- CONFIG_FATFS_SECTOR_SIZE
- CONFIG_FATFS_TIMEOUT_MS
- CONFIG_FATFS_USE_DYN_BUFFERS
- CONFIG_FATFS_USE_LABEL
- CONFIG_FATFS_PER_FILE_CACHE

CONFIG_FATFS_API_ENCODING

CONFIG_FATFS_VFS_FSTAT_BLKSIZE

CONFIG_FATFS_IMMEDIATE_FSYNC

CONFIG_FATFS_USE_FASTSEEK

CONFIG_FATFS_USE_STRFUNC_CHOICE

CONFIG_FATFS_FAST_SEEK_BUFFER_SIZE

CONFIG_FATFS_STRF_ENCODE_CHOICE

CONFIG_FATFS_LONG_FILENAMES

CONFIG_FATFS_PRINT_FLOAT

CONFIG_FATFS_PRINT_LLI

CONFIG_FATFS_MAX_LFN

CONFIG_FATFS_FS_LOCK

CONFIG_FATFS_VOLUME_COUNT

CONFIG_FATFS_CHOOSE_CODEPAGE

CONFIG_FATFS_LINK_LOCK

CONFIG_FATFS_ALLOC_PREFER_EXTRAM

CONFIG_FATFS_SECTOR_SIZE

CONFIG_FATFS_TIMEOUT_MS

CONFIG_FATFS_USE_DYN_BUFFERS

CONFIG_FATFS_USE_LABEL

CONFIG_FATFS_PER_FILE_CACHE


#### CONFIG_FATFS_VOLUME_COUNT

Found in: Component config > FAT Filesystem support

- from 1 to 10

- 2


#### CONFIG_FATFS_LONG_FILENAMES

Found in: Component config > FAT Filesystem support

Available options:

- No long filenames (CONFIG_FATFS_LFN_NONE)
- Long filename buffer in heap (CONFIG_FATFS_LFN_HEAP)
- Long filename buffer on stack (CONFIG_FATFS_LFN_STACK)

No long filenames (CONFIG_FATFS_LFN_NONE)

Long filename buffer in heap (CONFIG_FATFS_LFN_HEAP)

Long filename buffer on stack (CONFIG_FATFS_LFN_STACK)


#### CONFIG_FATFS_SECTOR_SIZE

Found in: Component config > FAT Filesystem support

Available options:

- 512 (CONFIG_FATFS_SECTOR_512)
- 4096 (CONFIG_FATFS_SECTOR_4096)

512 (CONFIG_FATFS_SECTOR_512)

4096 (CONFIG_FATFS_SECTOR_4096)


#### CONFIG_FATFS_CHOOSE_CODEPAGE

Found in: Component config > FAT Filesystem support

Available options:

- Dynamic (all code pages supported) (CONFIG_FATFS_CODEPAGE_DYNAMIC)
- US (CP437) (CONFIG_FATFS_CODEPAGE_437)
- Arabic (CP720) (CONFIG_FATFS_CODEPAGE_720)
- Greek (CP737) (CONFIG_FATFS_CODEPAGE_737)
- KBL (CP771) (CONFIG_FATFS_CODEPAGE_771)
- Baltic (CP775) (CONFIG_FATFS_CODEPAGE_775)
- Latin 1 (CP850) (CONFIG_FATFS_CODEPAGE_850)
- Latin 2 (CP852) (CONFIG_FATFS_CODEPAGE_852)
- Cyrillic (CP855) (CONFIG_FATFS_CODEPAGE_855)
- Turkish (CP857) (CONFIG_FATFS_CODEPAGE_857)
- Portuguese (CP860) (CONFIG_FATFS_CODEPAGE_860)
- Icelandic (CP861) (CONFIG_FATFS_CODEPAGE_861)
- Hebrew (CP862) (CONFIG_FATFS_CODEPAGE_862)
- Canadian French (CP863) (CONFIG_FATFS_CODEPAGE_863)
- Arabic (CP864) (CONFIG_FATFS_CODEPAGE_864)
- Nordic (CP865) (CONFIG_FATFS_CODEPAGE_865)
- Russian (CP866) (CONFIG_FATFS_CODEPAGE_866)
- Greek 2 (CP869) (CONFIG_FATFS_CODEPAGE_869)
- Japanese (DBCS) (CP932) (CONFIG_FATFS_CODEPAGE_932)
- Simplified Chinese (DBCS) (CP936) (CONFIG_FATFS_CODEPAGE_936)
- Korean (DBCS) (CP949) (CONFIG_FATFS_CODEPAGE_949)
- Traditional Chinese (DBCS) (CP950) (CONFIG_FATFS_CODEPAGE_950)

Dynamic (all code pages supported) (CONFIG_FATFS_CODEPAGE_DYNAMIC)

US (CP437) (CONFIG_FATFS_CODEPAGE_437)

Arabic (CP720) (CONFIG_FATFS_CODEPAGE_720)

Greek (CP737) (CONFIG_FATFS_CODEPAGE_737)

KBL (CP771) (CONFIG_FATFS_CODEPAGE_771)

Baltic (CP775) (CONFIG_FATFS_CODEPAGE_775)

Latin 1 (CP850) (CONFIG_FATFS_CODEPAGE_850)

Latin 2 (CP852) (CONFIG_FATFS_CODEPAGE_852)

Cyrillic (CP855) (CONFIG_FATFS_CODEPAGE_855)

Turkish (CP857) (CONFIG_FATFS_CODEPAGE_857)

Portuguese (CP860) (CONFIG_FATFS_CODEPAGE_860)

Icelandic (CP861) (CONFIG_FATFS_CODEPAGE_861)

Hebrew (CP862) (CONFIG_FATFS_CODEPAGE_862)

Canadian French (CP863) (CONFIG_FATFS_CODEPAGE_863)

Arabic (CP864) (CONFIG_FATFS_CODEPAGE_864)

Nordic (CP865) (CONFIG_FATFS_CODEPAGE_865)

Russian (CP866) (CONFIG_FATFS_CODEPAGE_866)

Greek 2 (CP869) (CONFIG_FATFS_CODEPAGE_869)

Japanese (DBCS) (CP932) (CONFIG_FATFS_CODEPAGE_932)

Simplified Chinese (DBCS) (CP936) (CONFIG_FATFS_CODEPAGE_936)

Korean (DBCS) (CP949) (CONFIG_FATFS_CODEPAGE_949)

Traditional Chinese (DBCS) (CP950) (CONFIG_FATFS_CODEPAGE_950)


#### CONFIG_FATFS_MAX_LFN

Found in: Component config > FAT Filesystem support


#### CONFIG_FATFS_API_ENCODING

Found in: Component config > FAT Filesystem support

Available options:

- API uses ANSI/OEM encoding (CONFIG_FATFS_API_ENCODING_ANSI_OEM)
- API uses UTF-8 encoding (CONFIG_FATFS_API_ENCODING_UTF_8)

API uses ANSI/OEM encoding (CONFIG_FATFS_API_ENCODING_ANSI_OEM)

API uses UTF-8 encoding (CONFIG_FATFS_API_ENCODING_UTF_8)


#### CONFIG_FATFS_FS_LOCK

Found in: Component config > FAT Filesystem support

- from 0 to 65535

- 0


#### CONFIG_FATFS_TIMEOUT_MS

Found in: Component config > FAT Filesystem support

- 10000


#### CONFIG_FATFS_PER_FILE_CACHE

Found in: Component config > FAT Filesystem support

- Yes (enabled)


#### CONFIG_FATFS_ALLOC_PREFER_EXTRAM

Found in: Component config > FAT Filesystem support

- Yes (enabled) if CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC

Yes (enabled) if CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC


#### CONFIG_FATFS_USE_FASTSEEK

Found in: Component config > FAT Filesystem support

- No (disabled)


#### CONFIG_FATFS_USE_STRFUNC_CHOICE

Found in: Component config > FAT Filesystem support

Available options:

- 0:Disable (CONFIG_FATFS_USE_STRFUNC_NONE)
- 1:Enable without LF-CRLF conversion (CONFIG_FATFS_USE_STRFUNC_WITHOUT_CRLF_CONV)
- 2:Enable with LF-CRLF conversion (CONFIG_FATFS_USE_STRFUNC_WITH_CRLF_CONV)

0:Disable (CONFIG_FATFS_USE_STRFUNC_NONE)

1:Enable without LF-CRLF conversion (CONFIG_FATFS_USE_STRFUNC_WITHOUT_CRLF_CONV)

2:Enable with LF-CRLF conversion (CONFIG_FATFS_USE_STRFUNC_WITH_CRLF_CONV)


#### CONFIG_FATFS_PRINT_LLI

Found in: Component config > FAT Filesystem support


#### CONFIG_FATFS_PRINT_FLOAT

Found in: Component config > FAT Filesystem support


#### CONFIG_FATFS_STRF_ENCODE_CHOICE

Found in: Component config > FAT Filesystem support

Available options:

- 0:ANSI/OEM in current CP (CONFIG_FATFS_STRF_ENCODE_ANSI)
- 1:Unicode in UTF-16LE (CONFIG_FATFS_STRF_ENCODE_UTF16LE)
- 2:Unicode in UTF-16BE (CONFIG_FATFS_STRF_ENCODE_UTF16BE)
- 3:Unicode in UTF-8 (CONFIG_FATFS_STRF_ENCODE_UTF8)

0:ANSI/OEM in current CP (CONFIG_FATFS_STRF_ENCODE_ANSI)

1:Unicode in UTF-16LE (CONFIG_FATFS_STRF_ENCODE_UTF16LE)

2:Unicode in UTF-16BE (CONFIG_FATFS_STRF_ENCODE_UTF16BE)

3:Unicode in UTF-8 (CONFIG_FATFS_STRF_ENCODE_UTF8)


#### CONFIG_FATFS_FAST_SEEK_BUFFER_SIZE

Found in: Component config > FAT Filesystem support

- 64 if CONFIG_FATFS_USE_FASTSEEK

64 if CONFIG_FATFS_USE_FASTSEEK


#### CONFIG_FATFS_VFS_FSTAT_BLKSIZE

Found in: Component config > FAT Filesystem support

- 0


#### CONFIG_FATFS_IMMEDIATE_FSYNC

Found in: Component config > FAT Filesystem support

- No (disabled)


#### CONFIG_FATFS_USE_LABEL

Found in: Component config > FAT Filesystem support

- No (disabled)


#### CONFIG_FATFS_LINK_LOCK

Found in: Component config > FAT Filesystem support

- Yes (enabled)


#### CONFIG_FATFS_USE_DYN_BUFFERS

Found in: Component config > FAT Filesystem support

- Yes (enabled)


#### File system free space calculation behavior

- CONFIG_FATFS_DONT_TRUST_LAST_ALLOC
- CONFIG_FATFS_DONT_TRUST_FREE_CLUSTER_CNT

CONFIG_FATFS_DONT_TRUST_LAST_ALLOC

CONFIG_FATFS_DONT_TRUST_FREE_CLUSTER_CNT


##### CONFIG_FATFS_DONT_TRUST_FREE_CLUSTER_CNT

Found in: Component config > FAT Filesystem support > File system free space calculation behavior

- from 0 to 1

- 0


##### CONFIG_FATFS_DONT_TRUST_LAST_ALLOC

Found in: Component config > FAT Filesystem support > File system free space calculation behavior

- from 0 to 1

- 0


### FreeRTOS

- Extra
- Kernel
- Port


#### Kernel

- CONFIG_FREERTOS_CHECK_STACKOVERFLOW
- CONFIG_FREERTOS_ENABLE_BACKWARD_COMPATIBILITY
- CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS
- CONFIG_FREERTOS_MAX_TASK_NAME_LEN
- CONFIG_FREERTOS_IDLE_TASK_STACKSIZE
- CONFIG_FREERTOS_THREAD_LOCAL_STORAGE_POINTERS
- CONFIG_FREERTOS_QUEUE_REGISTRY_SIZE
- CONFIG_FREERTOS_TASK_NOTIFICATION_ARRAY_ENTRIES
- CONFIG_FREERTOS_HZ
- CONFIG_FREERTOS_USE_APPLICATION_TASK_TAG
- CONFIG_FREERTOS_USE_IDLE_HOOK
- CONFIG_FREERTOS_USE_LIST_DATA_INTEGRITY_CHECK_BYTES
- CONFIG_FREERTOS_OPTIMIZED_SCHEDULER
- CONFIG_FREERTOS_USE_TICK_HOOK
- CONFIG_FREERTOS_USE_TICKLESS_IDLE
- CONFIG_FREERTOS_USE_TIMERS
- CONFIG_FREERTOS_USE_TRACE_FACILITY
- CONFIG_FREERTOS_VTASKLIST_INCLUDE_COREID
- CONFIG_FREERTOS_UNICORE

CONFIG_FREERTOS_CHECK_STACKOVERFLOW

CONFIG_FREERTOS_ENABLE_BACKWARD_COMPATIBILITY

CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS

CONFIG_FREERTOS_MAX_TASK_NAME_LEN

CONFIG_FREERTOS_IDLE_TASK_STACKSIZE

CONFIG_FREERTOS_THREAD_LOCAL_STORAGE_POINTERS

CONFIG_FREERTOS_QUEUE_REGISTRY_SIZE

CONFIG_FREERTOS_TASK_NOTIFICATION_ARRAY_ENTRIES

CONFIG_FREERTOS_HZ

CONFIG_FREERTOS_USE_APPLICATION_TASK_TAG

CONFIG_FREERTOS_USE_IDLE_HOOK

CONFIG_FREERTOS_USE_LIST_DATA_INTEGRITY_CHECK_BYTES

CONFIG_FREERTOS_OPTIMIZED_SCHEDULER

CONFIG_FREERTOS_USE_TICK_HOOK

CONFIG_FREERTOS_USE_TICKLESS_IDLE

CONFIG_FREERTOS_USE_TIMERS

CONFIG_FREERTOS_USE_TRACE_FACILITY

CONFIG_FREERTOS_VTASKLIST_INCLUDE_COREID

CONFIG_FREERTOS_UNICORE


##### CONFIG_FREERTOS_UNICORE

Found in: Component config > FreeRTOS > Kernel


##### CONFIG_FREERTOS_HZ

Found in: Component config > FreeRTOS > Kernel

- from 1 to 1000

- 100


##### CONFIG_FREERTOS_OPTIMIZED_SCHEDULER

Found in: Component config > FreeRTOS > Kernel

- Yes (enabled) if CONFIG_FREERTOS_UNICORE

Yes (enabled) if CONFIG_FREERTOS_UNICORE


##### CONFIG_FREERTOS_CHECK_STACKOVERFLOW

Found in: Component config > FreeRTOS > Kernel

Available options:

- No checking (CONFIG_FREERTOS_CHECK_STACKOVERFLOW_NONE) Do not check for stack overflows (configCHECK_FOR_STACK_OVERFLOW = 0)
- Check by stack pointer value (Method 1) (CONFIG_FREERTOS_CHECK_STACKOVERFLOW_PTRVAL) Check for stack overflows on each context switch by checking if the stack pointer is in a valid range. Quick but does not detect stack overflows that happened between context switches (configCHECK_FOR_STACK_OVERFLOW = 1)
- Check using canary bytes (Method 2) (CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY) Places some magic bytes at the end of the stack area and on each context switch, check if these bytes are still intact. More thorough than just checking the pointer, but also slightly slower. (configCHECK_FOR_STACK_OVERFLOW = 2)

No checking (CONFIG_FREERTOS_CHECK_STACKOVERFLOW_NONE)

Check by stack pointer value (Method 1) (CONFIG_FREERTOS_CHECK_STACKOVERFLOW_PTRVAL)

Check using canary bytes (Method 2) (CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY)


##### CONFIG_FREERTOS_THREAD_LOCAL_STORAGE_POINTERS

Found in: Component config > FreeRTOS > Kernel

- from 1 to 256

- 1


##### CONFIG_FREERTOS_IDLE_TASK_STACKSIZE

Found in: Component config > FreeRTOS > Kernel

- ESP-IDF specifies stack sizes in bytes instead of words.
- The default size is enough for most use cases.
- The stack size may need to be increased above the default if the app installs idle or thread local storage cleanup hooks that use a lot of stack memory.
- Conversely, the stack size can be reduced to the minimum if non of the idle features are used.

- from 768 to 32768

- 1536


##### CONFIG_FREERTOS_USE_IDLE_HOOK

Found in: Component config > FreeRTOS > Kernel

- The application must provide the hook function void vApplicationIdleHook( void );
- vApplicationIdleHook() is called from FreeRTOS idle task(s)
- The FreeRTOS idle hook is NOT the same as the ESP-IDF Idle Hook, but both can be enabled simultaneously.

- No (disabled)


##### CONFIG_FREERTOS_USE_TICK_HOOK

Found in: Component config > FreeRTOS > Kernel

- The application must provide the hook function void vApplicationTickHook( void );
- vApplicationTickHook() is called from FreeRTOS's tick handling function xTaskIncrementTick()
- The FreeRTOS tick hook is NOT the same as the ESP-IDF Tick Interrupt Hook, but both can be enabled simultaneously.

- No (disabled)


##### CONFIG_FREERTOS_MAX_TASK_NAME_LEN

Found in: Component config > FreeRTOS > Kernel

- from 1 to 256

- 16


##### CONFIG_FREERTOS_ENABLE_BACKWARD_COMPATIBILITY

Found in: Component config > FreeRTOS > Kernel

- No (disabled)


##### CONFIG_FREERTOS_USE_TIMERS

Found in: Component config > FreeRTOS > Kernel

- Yes (enabled)


##### CONFIG_FREERTOS_TIMER_SERVICE_TASK_NAME

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TIMERS

- "Tmr Svc"


##### CONFIG_FREERTOS_TIMER_SERVICE_TASK_CORE_AFFINITY

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TIMERS

Available options:

- CPU0 (CONFIG_FREERTOS_TIMER_TASK_AFFINITY_CPU0)
- CPU1 (CONFIG_FREERTOS_TIMER_TASK_AFFINITY_CPU1)
- No affinity (CONFIG_FREERTOS_TIMER_TASK_NO_AFFINITY)

CPU0 (CONFIG_FREERTOS_TIMER_TASK_AFFINITY_CPU0)

CPU1 (CONFIG_FREERTOS_TIMER_TASK_AFFINITY_CPU1)

No affinity (CONFIG_FREERTOS_TIMER_TASK_NO_AFFINITY)


##### CONFIG_FREERTOS_TIMER_TASK_PRIORITY

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TIMERS

- from 1 to 25

- 1


##### CONFIG_FREERTOS_TIMER_TASK_STACK_DEPTH

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TIMERS

- from 1536 to 32768

- 2048


##### CONFIG_FREERTOS_TIMER_QUEUE_LENGTH

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TIMERS

- from 5 to 20

- 10


##### CONFIG_FREERTOS_QUEUE_REGISTRY_SIZE

Found in: Component config > FreeRTOS > Kernel

- from 0 to 20

- 0


##### CONFIG_FREERTOS_TASK_NOTIFICATION_ARRAY_ENTRIES

Found in: Component config > FreeRTOS > Kernel

- from 1 to 32

- 1


##### CONFIG_FREERTOS_USE_TRACE_FACILITY

Found in: Component config > FreeRTOS > Kernel

- No (disabled)


##### CONFIG_FREERTOS_USE_STATS_FORMATTING_FUNCTIONS

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TRACE_FACILITY

- No (disabled) if CONFIG_FREERTOS_USE_TRACE_FACILITY

No (disabled) if CONFIG_FREERTOS_USE_TRACE_FACILITY


##### CONFIG_FREERTOS_USE_LIST_DATA_INTEGRITY_CHECK_BYTES

Found in: Component config > FreeRTOS > Kernel

- No (disabled)


##### CONFIG_FREERTOS_VTASKLIST_INCLUDE_COREID

Found in: Component config > FreeRTOS > Kernel

- No (disabled) if CONFIG_FREERTOS_USE_STATS_FORMATTING_FUNCTIONS

No (disabled) if CONFIG_FREERTOS_USE_STATS_FORMATTING_FUNCTIONS


##### CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS

Found in: Component config > FreeRTOS > Kernel

- No (disabled)


##### CONFIG_FREERTOS_RUN_TIME_COUNTER_TYPE

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS

Available options:

- uint32_t (CONFIG_FREERTOS_RUN_TIME_COUNTER_TYPE_U32) configRUN_TIME_COUNTER_TYPE is set to uint32_t
- uint64_t (CONFIG_FREERTOS_RUN_TIME_COUNTER_TYPE_U64) configRUN_TIME_COUNTER_TYPE is set to uint64_t

uint32_t (CONFIG_FREERTOS_RUN_TIME_COUNTER_TYPE_U32)

uint64_t (CONFIG_FREERTOS_RUN_TIME_COUNTER_TYPE_U64)


##### CONFIG_FREERTOS_USE_TICKLESS_IDLE

Found in: Component config > FreeRTOS > Kernel

- No (disabled) if CONFIG_PM_ENABLE

No (disabled) if CONFIG_PM_ENABLE


##### CONFIG_FREERTOS_IDLE_TIME_BEFORE_SLEEP

Found in: Component config > FreeRTOS > Kernel > CONFIG_FREERTOS_USE_TICKLESS_IDLE

- from 2 to 4294967295 if CONFIG_FREERTOS_USE_TICKLESS_IDLE

from 2 to 4294967295 if CONFIG_FREERTOS_USE_TICKLESS_IDLE

- 3 if CONFIG_FREERTOS_USE_TICKLESS_IDLE

3 if CONFIG_FREERTOS_USE_TICKLESS_IDLE


##### CONFIG_FREERTOS_USE_APPLICATION_TASK_TAG

Found in: Component config > FreeRTOS > Kernel

- No (disabled)


#### Port

- CONFIG_FREERTOS_CHECK_MUTEX_GIVEN_BY_OWNER
- CONFIG_FREERTOS_RUN_TIME_STATS_CLK
- CONFIG_FREERTOS_INTERRUPT_BACKTRACE
- CONFIG_FREERTOS_WATCHPOINT_END_OF_STACK
- CONFIG_FREERTOS_TASK_PRE_DELETION_HOOK
- CONFIG_FREERTOS_TLSP_DELETION_CALLBACKS
- CONFIG_FREERTOS_ISR_STACKSIZE
- CONFIG_FREERTOS_PLACE_ISR_FUNCTIONS_INTO_FLASH
- CONFIG_FREERTOS_IN_IRAM
- CONFIG_FREERTOS_CHECK_PORT_CRITICAL_COMPLIANCE
- CONFIG_FREERTOS_CORETIMER
- CONFIG_FREERTOS_TASK_FUNCTION_WRAPPER

CONFIG_FREERTOS_CHECK_MUTEX_GIVEN_BY_OWNER

CONFIG_FREERTOS_RUN_TIME_STATS_CLK

CONFIG_FREERTOS_INTERRUPT_BACKTRACE

CONFIG_FREERTOS_WATCHPOINT_END_OF_STACK

CONFIG_FREERTOS_TASK_PRE_DELETION_HOOK

CONFIG_FREERTOS_TLSP_DELETION_CALLBACKS

CONFIG_FREERTOS_ISR_STACKSIZE

CONFIG_FREERTOS_PLACE_ISR_FUNCTIONS_INTO_FLASH

CONFIG_FREERTOS_IN_IRAM

CONFIG_FREERTOS_CHECK_PORT_CRITICAL_COMPLIANCE

CONFIG_FREERTOS_CORETIMER

CONFIG_FREERTOS_TASK_FUNCTION_WRAPPER


##### CONFIG_FREERTOS_TASK_FUNCTION_WRAPPER

Found in: Component config > FreeRTOS > Port

- Yes (enabled)


##### CONFIG_FREERTOS_WATCHPOINT_END_OF_STACK

Found in: Component config > FreeRTOS > Port

- No (disabled)


##### CONFIG_FREERTOS_TLSP_DELETION_CALLBACKS

Found in: Component config > FreeRTOS > Port

- Yes (enabled)


##### CONFIG_FREERTOS_TASK_PRE_DELETION_HOOK

Found in: Component config > FreeRTOS > Port

- No (disabled)


##### CONFIG_FREERTOS_CHECK_MUTEX_GIVEN_BY_OWNER

Found in: Component config > FreeRTOS > Port

- Yes (enabled)


##### CONFIG_FREERTOS_ISR_STACKSIZE

Found in: Component config > FreeRTOS > Port

- from 1536 to 32768

- 1536


##### CONFIG_FREERTOS_INTERRUPT_BACKTRACE

Found in: Component config > FreeRTOS > Port

- Yes (enabled)


##### CONFIG_FREERTOS_CORETIMER

Found in: Component config > FreeRTOS > Port

Available options:

- Timer 0 (int 6, level 1) (CONFIG_FREERTOS_CORETIMER_0) Select this to use timer 0
- Timer 1 (int 15, level 3) (CONFIG_FREERTOS_CORETIMER_1) Select this to use timer 1
- SYSTIMER 0 (level 1) (CONFIG_FREERTOS_CORETIMER_SYSTIMER_LVL1) Select this to use systimer with the 1 interrupt priority.
- SYSTIMER 0 (level 3) (CONFIG_FREERTOS_CORETIMER_SYSTIMER_LVL3) Select this to use systimer with the 3 interrupt priority.

Timer 0 (int 6, level 1) (CONFIG_FREERTOS_CORETIMER_0)

Timer 1 (int 15, level 3) (CONFIG_FREERTOS_CORETIMER_1)

SYSTIMER 0 (level 1) (CONFIG_FREERTOS_CORETIMER_SYSTIMER_LVL1)

SYSTIMER 0 (level 3) (CONFIG_FREERTOS_CORETIMER_SYSTIMER_LVL3)


##### CONFIG_FREERTOS_RUN_TIME_STATS_CLK

Found in: Component config > FreeRTOS > Port

Available options:

- Use ESP TIMER for run time stats (CONFIG_FREERTOS_RUN_TIME_STATS_USING_ESP_TIMER) ESP Timer will be used as the clock source for FreeRTOS run time stats. The ESP Timer runs at a frequency of 1MHz regardless of Dynamic Frequency Scaling. Therefore the ESP Timer will overflow in approximately 4290 seconds.

Use ESP TIMER for run time stats (CONFIG_FREERTOS_RUN_TIME_STATS_USING_ESP_TIMER)

Use CPU Clock for run time stats (CONFIG_FREERTOS_RUN_TIME_STATS_USING_CPU_CLK)


##### CONFIG_FREERTOS_IN_IRAM

Found in: Component config > FreeRTOS > Port

- No (disabled)


##### CONFIG_FREERTOS_PLACE_ISR_FUNCTIONS_INTO_FLASH

Found in: Component config > FreeRTOS > Port

- No (disabled) if CONFIG_SPI_FLASH_AUTO_SUSPEND

No (disabled) if CONFIG_SPI_FLASH_AUTO_SUSPEND


##### CONFIG_FREERTOS_CHECK_PORT_CRITICAL_COMPLIANCE

Found in: Component config > FreeRTOS > Port

- No (disabled)


#### Extra

- CONFIG_FREERTOS_TASK_CREATE_ALLOW_EXT_MEM

CONFIG_FREERTOS_TASK_CREATE_ALLOW_EXT_MEM


##### CONFIG_FREERTOS_TASK_CREATE_ALLOW_EXT_MEM

Found in: Component config > FreeRTOS > Extra

- Yes (enabled) if CONFIG_SPIRAM

Yes (enabled) if CONFIG_SPIRAM


### Hardware Abstraction Layer (HAL) and Low Level (LL)

- CONFIG_HAL_DEFAULT_ASSERTION_LEVEL
- CONFIG_HAL_LOG_LEVEL
- CONFIG_HAL_GPIO_USE_ROM_IMPL
- CONFIG_HAL_SYSTIMER_USE_ROM_IMPL
- CONFIG_HAL_WDT_USE_ROM_IMPL

CONFIG_HAL_DEFAULT_ASSERTION_LEVEL

CONFIG_HAL_LOG_LEVEL

CONFIG_HAL_GPIO_USE_ROM_IMPL

CONFIG_HAL_SYSTIMER_USE_ROM_IMPL

CONFIG_HAL_WDT_USE_ROM_IMPL


#### CONFIG_HAL_DEFAULT_ASSERTION_LEVEL

Found in: Component config > Hardware Abstraction Layer (HAL) and Low Level (LL)

Available options:

- Same as system assertion level (CONFIG_HAL_ASSERTION_EQUALS_SYSTEM)
- Disabled (CONFIG_HAL_ASSERTION_DISABLE)
- Silent (CONFIG_HAL_ASSERTION_SILENT)
- Enabled (CONFIG_HAL_ASSERTION_ENABLE)

Same as system assertion level (CONFIG_HAL_ASSERTION_EQUALS_SYSTEM)

Disabled (CONFIG_HAL_ASSERTION_DISABLE)

Silent (CONFIG_HAL_ASSERTION_SILENT)

Enabled (CONFIG_HAL_ASSERTION_ENABLE)


#### CONFIG_HAL_LOG_LEVEL

Found in: Component config > Hardware Abstraction Layer (HAL) and Low Level (LL)

Available options:

- No output (CONFIG_HAL_LOG_LEVEL_NONE)
- Error (CONFIG_HAL_LOG_LEVEL_ERROR)
- Warning (CONFIG_HAL_LOG_LEVEL_WARN)
- Info (CONFIG_HAL_LOG_LEVEL_INFO)
- Debug (CONFIG_HAL_LOG_LEVEL_DEBUG)
- Verbose (CONFIG_HAL_LOG_LEVEL_VERBOSE)

No output (CONFIG_HAL_LOG_LEVEL_NONE)

Error (CONFIG_HAL_LOG_LEVEL_ERROR)

Warning (CONFIG_HAL_LOG_LEVEL_WARN)

Info (CONFIG_HAL_LOG_LEVEL_INFO)

Debug (CONFIG_HAL_LOG_LEVEL_DEBUG)

Verbose (CONFIG_HAL_LOG_LEVEL_VERBOSE)


#### CONFIG_HAL_SYSTIMER_USE_ROM_IMPL

Found in: Component config > Hardware Abstraction Layer (HAL) and Low Level (LL)

- Yes (enabled)


#### CONFIG_HAL_WDT_USE_ROM_IMPL

Found in: Component config > Hardware Abstraction Layer (HAL) and Low Level (LL)

- Yes (enabled)


#### CONFIG_HAL_GPIO_USE_ROM_IMPL

Found in: Component config > Hardware Abstraction Layer (HAL) and Low Level (LL)

- Yes (enabled)


### Heap memory debugging

- CONFIG_HEAP_ABORT_WHEN_ALLOCATION_FAILS
- CONFIG_HEAP_TASK_TRACKING
- CONFIG_HEAP_PLACE_FUNCTION_INTO_FLASH
- CONFIG_HEAP_CORRUPTION_DETECTION
- CONFIG_HEAP_TRACING_DEST
- CONFIG_HEAP_TRACING_STACK_DEPTH
- CONFIG_HEAP_USE_HOOKS
- CONFIG_HEAP_TRACE_HASH_MAP
- CONFIG_HEAP_TLSF_USE_ROM_IMPL

CONFIG_HEAP_ABORT_WHEN_ALLOCATION_FAILS

CONFIG_HEAP_TASK_TRACKING

CONFIG_HEAP_PLACE_FUNCTION_INTO_FLASH

CONFIG_HEAP_CORRUPTION_DETECTION

CONFIG_HEAP_TRACING_DEST

CONFIG_HEAP_TRACING_STACK_DEPTH

CONFIG_HEAP_USE_HOOKS

CONFIG_HEAP_TRACE_HASH_MAP

CONFIG_HEAP_TLSF_USE_ROM_IMPL


#### CONFIG_HEAP_CORRUPTION_DETECTION

Found in: Component config > Heap memory debugging

Available options:

- Basic (no poisoning) (CONFIG_HEAP_POISONING_DISABLED)
- Light impact (CONFIG_HEAP_POISONING_LIGHT)
- Comprehensive (CONFIG_HEAP_POISONING_COMPREHENSIVE)

Basic (no poisoning) (CONFIG_HEAP_POISONING_DISABLED)

Light impact (CONFIG_HEAP_POISONING_LIGHT)

Comprehensive (CONFIG_HEAP_POISONING_COMPREHENSIVE)


#### CONFIG_HEAP_TRACING_DEST

Found in: Component config > Heap memory debugging

Available options:

- Disabled (CONFIG_HEAP_TRACING_OFF)
- Standalone (CONFIG_HEAP_TRACING_STANDALONE)
- Host-based (CONFIG_HEAP_TRACING_TOHOST)

Disabled (CONFIG_HEAP_TRACING_OFF)

Standalone (CONFIG_HEAP_TRACING_STANDALONE)

Host-based (CONFIG_HEAP_TRACING_TOHOST)


#### CONFIG_HEAP_TRACE_HASH_MAP

Found in: Component config > Heap memory debugging

- No (disabled) if CONFIG_HEAP_TRACING_STANDALONE

No (disabled) if CONFIG_HEAP_TRACING_STANDALONE


##### CONFIG_HEAP_TRACE_HASH_MAP_IN_EXT_RAM

Found in: Component config > Heap memory debugging > CONFIG_HEAP_TRACE_HASH_MAP

- No (disabled) if CONFIG_SPIRAM && CONFIG_HEAP_TRACE_HASH_MAP

No (disabled) if CONFIG_SPIRAM && CONFIG_HEAP_TRACE_HASH_MAP


##### CONFIG_HEAP_TRACE_HASH_MAP_SIZE

Found in: Component config > Heap memory debugging > CONFIG_HEAP_TRACE_HASH_MAP

- 512 if CONFIG_HEAP_TRACE_HASH_MAP

512 if CONFIG_HEAP_TRACE_HASH_MAP


#### CONFIG_HEAP_TRACING_STACK_DEPTH

Found in: Component config > Heap memory debugging


#### CONFIG_HEAP_USE_HOOKS

Found in: Component config > Heap memory debugging


#### CONFIG_HEAP_TASK_TRACKING

Found in: Component config > Heap memory debugging


##### CONFIG_HEAP_TRACK_DELETED_TASKS

Found in: Component config > Heap memory debugging > CONFIG_HEAP_TASK_TRACKING

- No (disabled) if CONFIG_HEAP_TASK_TRACKING

No (disabled) if CONFIG_HEAP_TASK_TRACKING


#### CONFIG_HEAP_ABORT_WHEN_ALLOCATION_FAILS

Found in: Component config > Heap memory debugging

- No (disabled)


#### CONFIG_HEAP_TLSF_USE_ROM_IMPL

Found in: Component config > Heap memory debugging

- Yes (enabled) if ESP_ROM_HAS_HEAP_TLSF


#### CONFIG_HEAP_PLACE_FUNCTION_INTO_FLASH

Found in: Component config > Heap memory debugging

- No (disabled)


### IEEE 802.15.4

- CONFIG_IEEE802154_TXRX_STATISTIC
- CONFIG_IEEE802154_RECORD_TXRX_FRAME
- CONFIG_IEEE802154_ASSERT
- CONFIG_IEEE802154_ENABLED
- CONFIG_IEEE802154_RECORD
- CONFIG_IEEE802154_RX_BUFFER_STATISTIC

CONFIG_IEEE802154_TXRX_STATISTIC

CONFIG_IEEE802154_RECORD_TXRX_FRAME

CONFIG_IEEE802154_ASSERT

CONFIG_IEEE802154_ENABLED

CONFIG_IEEE802154_RECORD

CONFIG_IEEE802154_RX_BUFFER_STATISTIC


#### CONFIG_IEEE802154_ENABLED

Found in: Component config > IEEE 802.15.4

- Yes (enabled) if SOC_IEEE802154_SUPPORTED


##### CONFIG_IEEE802154_RX_BUFFER_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- from 2 to 100 if CONFIG_IEEE802154_ENABLED

from 2 to 100 if CONFIG_IEEE802154_ENABLED

- 20 if CONFIG_IEEE802154_ENABLED

20 if CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_CCA_MODE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

Available options:

- Carrier sense only (CONFIG_IEEE802154_CCA_CARRIER) configure the CCA mode to Carrier sense only
- Energy above threshold (CONFIG_IEEE802154_CCA_ED) configure the CCA mode to Energy above threshold
- Carrier sense OR energy above threshold (CONFIG_IEEE802154_CCA_CARRIER_OR_ED) configure the CCA mode to Carrier sense OR energy above threshold
- Carrier sense AND energy above threshold (CONFIG_IEEE802154_CCA_CARRIER_AND_ED) configure the CCA mode to Carrier sense AND energy above threshold

Carrier sense only (CONFIG_IEEE802154_CCA_CARRIER)

Energy above threshold (CONFIG_IEEE802154_CCA_ED)

Carrier sense OR energy above threshold (CONFIG_IEEE802154_CCA_CARRIER_OR_ED)

Carrier sense AND energy above threshold (CONFIG_IEEE802154_CCA_CARRIER_AND_ED)


##### CONFIG_IEEE802154_CCA_THRESHOLD

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- from -120 to 0 if CONFIG_IEEE802154_ENABLED

from -120 to 0 if CONFIG_IEEE802154_ENABLED

- "-75" if CONFIG_IEEE802154_ENABLED

"-75" if CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_PENDING_TABLE_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- from 1 to 100 if CONFIG_IEEE802154_ENABLED

from 1 to 100 if CONFIG_IEEE802154_ENABLED

- 20 if CONFIG_IEEE802154_ENABLED

20 if CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_MULTI_PAN_ENABLE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- No (disabled) if CONFIG_IEEE802154_ENABLED

No (disabled) if CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_TIMING_OPTIMIZATION

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- Yes (enabled) if CONFIG_IEEE802154_ENABLED

Yes (enabled) if CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_SLEEP_ENABLE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- No (disabled) if CONFIG_PM_ENABLE && CONFIG_IEEE802154_ENABLED

No (disabled) if CONFIG_PM_ENABLE && CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_DEBUG

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- No (disabled) if CONFIG_IEEE802154_ENABLED

No (disabled) if CONFIG_IEEE802154_ENABLED


##### CONFIG_IEEE802154_DEBUG_ASSERT_MONITOR

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_ENABLED

- No (disabled) if CONFIG_IEEE802154_ENABLED

No (disabled) if CONFIG_IEEE802154_ENABLED


#### CONFIG_IEEE802154_RX_BUFFER_STATISTIC

Found in: Component config > IEEE 802.15.4

- No (disabled) if CONFIG_IEEE802154_DEBUG

No (disabled) if CONFIG_IEEE802154_DEBUG


#### CONFIG_IEEE802154_ASSERT

Found in: Component config > IEEE 802.15.4

- No (disabled) if CONFIG_IEEE802154_DEBUG

No (disabled) if CONFIG_IEEE802154_DEBUG


#### CONFIG_IEEE802154_RECORD

Found in: Component config > IEEE 802.15.4

- No (disabled) if CONFIG_IEEE802154_DEBUG

No (disabled) if CONFIG_IEEE802154_DEBUG


##### CONFIG_IEEE802154_RECORD_EVENT

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD

- No (disabled) if CONFIG_IEEE802154_RECORD

No (disabled) if CONFIG_IEEE802154_RECORD


##### CONFIG_IEEE802154_RECORD_EVENT_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD > CONFIG_IEEE802154_RECORD_EVENT

- from 1 to 50 if CONFIG_IEEE802154_RECORD_EVENT

from 1 to 50 if CONFIG_IEEE802154_RECORD_EVENT

- 30 if CONFIG_IEEE802154_RECORD_EVENT

30 if CONFIG_IEEE802154_RECORD_EVENT


##### CONFIG_IEEE802154_RECORD_STATE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD

- No (disabled) if CONFIG_IEEE802154_RECORD

No (disabled) if CONFIG_IEEE802154_RECORD


##### CONFIG_IEEE802154_RECORD_STATE_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD > CONFIG_IEEE802154_RECORD_STATE

- from 1 to 50 if CONFIG_IEEE802154_RECORD_STATE

from 1 to 50 if CONFIG_IEEE802154_RECORD_STATE

- 10 if CONFIG_IEEE802154_RECORD_STATE

10 if CONFIG_IEEE802154_RECORD_STATE


##### CONFIG_IEEE802154_RECORD_CMD

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD

- No (disabled) if CONFIG_IEEE802154_RECORD

No (disabled) if CONFIG_IEEE802154_RECORD


##### CONFIG_IEEE802154_RECORD_CMD_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD > CONFIG_IEEE802154_RECORD_CMD

- from 1 to 50 if CONFIG_IEEE802154_RECORD_CMD

from 1 to 50 if CONFIG_IEEE802154_RECORD_CMD

- 10 if CONFIG_IEEE802154_RECORD_CMD

10 if CONFIG_IEEE802154_RECORD_CMD


##### CONFIG_IEEE802154_RECORD_ABORT

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD

- No (disabled) if CONFIG_IEEE802154_RECORD

No (disabled) if CONFIG_IEEE802154_RECORD


##### CONFIG_IEEE802154_RECORD_ABORT_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD > CONFIG_IEEE802154_RECORD_ABORT

- from 1 to 50 if CONFIG_IEEE802154_RECORD_ABORT

from 1 to 50 if CONFIG_IEEE802154_RECORD_ABORT

- 10 if CONFIG_IEEE802154_RECORD_ABORT

10 if CONFIG_IEEE802154_RECORD_ABORT


#### CONFIG_IEEE802154_RECORD_TXRX_FRAME

Found in: Component config > IEEE 802.15.4

- No (disabled) if CONFIG_IEEE802154_DEBUG

No (disabled) if CONFIG_IEEE802154_DEBUG


##### CONFIG_IEEE802154_RECORD_TXRX_FRAME_SIZE

Found in: Component config > IEEE 802.15.4 > CONFIG_IEEE802154_RECORD_TXRX_FRAME

- from 1 to 50 if CONFIG_IEEE802154_RECORD_TXRX_FRAME

from 1 to 50 if CONFIG_IEEE802154_RECORD_TXRX_FRAME

- 15 if CONFIG_IEEE802154_RECORD_TXRX_FRAME

15 if CONFIG_IEEE802154_RECORD_TXRX_FRAME


#### CONFIG_IEEE802154_TXRX_STATISTIC

Found in: Component config > IEEE 802.15.4

- No (disabled) if CONFIG_IEEE802154_DEBUG

No (disabled) if CONFIG_IEEE802154_DEBUG


### Log

- Format
- Log Level
- CONFIG_LOG_VERSION
- CONFIG_LOG_IN_IRAM
- Settings

CONFIG_LOG_VERSION

CONFIG_LOG_IN_IRAM


#### CONFIG_LOG_VERSION

Found in: Component config > Log

- "V1": This version integrates log formatting into the format string provided by the user.Logs are processed and formatted during compile time, leading to a larger binary file. Example: ESP_LOGI("boot", "chip revision: v%d.%d", major, minor); Output: I (56) boot: chip revision: v3.0 Note: Log strings are stored in Flash with added formatting characters. Format string on flash: "[0;32mI (%lu) %s: chip revision: v%d.%d [0m"

Available options:

- V1 (CONFIG_LOG_VERSION_1) Select this option to use Log V1. Recommended for projects with strict stack constraints or that prioritize performance over flexibility.
- V2 (CONFIG_LOG_VERSION_2) Select this option to use Log V2. Recommended for projects that require smaller binaries, runtime log formatting configuration, or advanced logging features.

V1 (CONFIG_LOG_VERSION_1)

V2 (CONFIG_LOG_VERSION_2)


#### Log Level

- CONFIG_LOG_DEFAULT_LEVEL
- Level Settings
- CONFIG_LOG_MAXIMUM_LEVEL

CONFIG_LOG_DEFAULT_LEVEL

CONFIG_LOG_MAXIMUM_LEVEL


##### CONFIG_LOG_DEFAULT_LEVEL

Found in: Component config > Log > Log Level

Available options:

- No output (CONFIG_LOG_DEFAULT_LEVEL_NONE)
- Error (CONFIG_LOG_DEFAULT_LEVEL_ERROR)
- Warning (CONFIG_LOG_DEFAULT_LEVEL_WARN)
- Info (CONFIG_LOG_DEFAULT_LEVEL_INFO)
- Debug (CONFIG_LOG_DEFAULT_LEVEL_DEBUG)
- Verbose (CONFIG_LOG_DEFAULT_LEVEL_VERBOSE)

No output (CONFIG_LOG_DEFAULT_LEVEL_NONE)

Error (CONFIG_LOG_DEFAULT_LEVEL_ERROR)

Warning (CONFIG_LOG_DEFAULT_LEVEL_WARN)

Info (CONFIG_LOG_DEFAULT_LEVEL_INFO)

Debug (CONFIG_LOG_DEFAULT_LEVEL_DEBUG)

Verbose (CONFIG_LOG_DEFAULT_LEVEL_VERBOSE)


##### CONFIG_LOG_MAXIMUM_LEVEL

Found in: Component config > Log > Log Level

Available options:

- Same as default (CONFIG_LOG_MAXIMUM_EQUALS_DEFAULT)
- Error (CONFIG_LOG_MAXIMUM_LEVEL_ERROR)
- Warning (CONFIG_LOG_MAXIMUM_LEVEL_WARN)
- Info (CONFIG_LOG_MAXIMUM_LEVEL_INFO)
- Debug (CONFIG_LOG_MAXIMUM_LEVEL_DEBUG)
- Verbose (CONFIG_LOG_MAXIMUM_LEVEL_VERBOSE)

Same as default (CONFIG_LOG_MAXIMUM_EQUALS_DEFAULT)

Error (CONFIG_LOG_MAXIMUM_LEVEL_ERROR)

Warning (CONFIG_LOG_MAXIMUM_LEVEL_WARN)

Info (CONFIG_LOG_MAXIMUM_LEVEL_INFO)

Debug (CONFIG_LOG_MAXIMUM_LEVEL_DEBUG)

Verbose (CONFIG_LOG_MAXIMUM_LEVEL_VERBOSE)


##### Level Settings

- CONFIG_LOG_TAG_LEVEL_CACHE_IMPL
- CONFIG_LOG_DYNAMIC_LEVEL_CONTROL
- CONFIG_LOG_MASTER_LEVEL
- CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_SIZE
- CONFIG_LOG_TAG_LEVEL_IMPL

CONFIG_LOG_TAG_LEVEL_CACHE_IMPL

CONFIG_LOG_DYNAMIC_LEVEL_CONTROL

CONFIG_LOG_MASTER_LEVEL

CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_SIZE

CONFIG_LOG_TAG_LEVEL_IMPL


##### CONFIG_LOG_MASTER_LEVEL

Found in: Component config > Log > Log Level > Level Settings

- No (disabled)


##### CONFIG_LOG_DYNAMIC_LEVEL_CONTROL

Found in: Component config > Log > Log Level > Level Settings

- Yes (enabled)


##### CONFIG_LOG_TAG_LEVEL_IMPL

Found in: Component config > Log > Log Level > Level Settings

Available options:

- None (CONFIG_LOG_TAG_LEVEL_IMPL_NONE) This option disables the ability to set the log level per tag. The ability to change the log level at runtime depends on LOG_DYNAMIC_LEVEL_CONTROL. If LOG_DYNAMIC_LEVEL_CONTROL is disabled, then changing the log level at runtime using esp_log_level_set() is not possible. This implementation is suitable for highly constrained environments.
- Linked List (CONFIG_LOG_TAG_LEVEL_IMPL_LINKED_LIST) Select this option to use the linked list-only implementation (no cache) for log level retrieval. This approach searches the linked list of all tags for the log level, which may be slower for a large number of tags but may have lower memory requirements than the CACHE approach. The linked list approach compares the whole strings of log tags for finding the log level.

None (CONFIG_LOG_TAG_LEVEL_IMPL_NONE)

Linked List (CONFIG_LOG_TAG_LEVEL_IMPL_LINKED_LIST)

Cache + Linked List (CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_AND_LINKED_LIST)


##### CONFIG_LOG_TAG_LEVEL_CACHE_IMPL

Found in: Component config > Log > Log Level > Level Settings

Available options:

- Array (CONFIG_LOG_TAG_LEVEL_CACHE_ARRAY) This option enables the use of a simple array-based cache implementation for storing and retrieving log tag levels. There is no additional code that reorders the cache for fast lookups. Suitable for projects where memory usage optimization is crucial and the simplicity of implementation is preferred.
- Binary Min-Heap (CONFIG_LOG_TAG_LEVEL_CACHE_BINARY_MIN_HEAP) This option enables the use of a binary min-heap-based cache implementation for efficient storage and retrieval of log tag levels. It does automatically optimizing cache for fast lookups. Suitable for projects where speed of lookup is critical and memory usage can accommodate the overhead of maintaining a binary min-heap structure.

Array (CONFIG_LOG_TAG_LEVEL_CACHE_ARRAY)

Binary Min-Heap (CONFIG_LOG_TAG_LEVEL_CACHE_BINARY_MIN_HEAP)


##### CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_SIZE

Found in: Component config > Log > Log Level > Level Settings

- 31


#### Format

- CONFIG_LOG_COLORS_SUPPORT
- CONFIG_LOG_TIMESTAMP_SUPPORT
- CONFIG_LOG_COLORS
- CONFIG_LOG_TIMESTAMP_SOURCE

CONFIG_LOG_COLORS_SUPPORT

CONFIG_LOG_TIMESTAMP_SUPPORT

CONFIG_LOG_COLORS

CONFIG_LOG_TIMESTAMP_SOURCE


##### CONFIG_LOG_COLORS

Found in: Component config > Log > Format

- No (disabled)


##### CONFIG_LOG_COLORS_SUPPORT

Found in: Component config > Log > Format

- No (disabled) if CONFIG_LOG_VERSION_2

No (disabled) if CONFIG_LOG_VERSION_2


##### CONFIG_LOG_TIMESTAMP_SOURCE

Found in: Component config > Log > Format

- "None" - The log will only contain the actual log messages themselves without any time-related information. Avoiding timestamps can help conserve processing power and memory. It might useful when you perform log analysis or debugging, sometimes it's more straightforward to work with logs that lack timestamps, especially if the time of occurrence is not critical for understanding the issues.
- "Milliseconds since boot" is calculated from the RTOS tick count multiplied by the tick period. This time will reset after a software reboot. e.g. (90000)
- "System time (HH:MM:SS.sss)" is taken from POSIX time functions which use the chip's RTC and high resolution timers to maintain an accurate time. The system time is initialized to 0 on startup, it can be set with an SNTP sync, or with POSIX time functions. This time will not reset after a software reboot. e.g. (00:01:30.000)
- "System time (YY-MM-DD HH:MM:SS.sss)" it is the same as the above, but also prints the date as well.
- "Unix time in milliseconds" is the same as the two above, but in Unix time format and in milliseconds. e.g. (1718795571035).
- NOTE: Currently this will not get used in logging from binary blobs (i.e WiFi & Bluetooth libraries), these will always print milliseconds since boot.

Available options:

- None (CONFIG_LOG_TIMESTAMP_SOURCE_NONE)
- Milliseconds Since Boot (CONFIG_LOG_TIMESTAMP_SOURCE_RTOS)
- System Time (HH:MM:SS.sss) (CONFIG_LOG_TIMESTAMP_SOURCE_SYSTEM)
- System Time (YY-MM-DD HH:MM:SS.sss) (CONFIG_LOG_TIMESTAMP_SOURCE_SYSTEM_FULL)
- Unix time in milliseconds (CONFIG_LOG_TIMESTAMP_SOURCE_UNIX)

None (CONFIG_LOG_TIMESTAMP_SOURCE_NONE)

Milliseconds Since Boot (CONFIG_LOG_TIMESTAMP_SOURCE_RTOS)

System Time (HH:MM:SS.sss) (CONFIG_LOG_TIMESTAMP_SOURCE_SYSTEM)

System Time (YY-MM-DD HH:MM:SS.sss) (CONFIG_LOG_TIMESTAMP_SOURCE_SYSTEM_FULL)

Unix time in milliseconds (CONFIG_LOG_TIMESTAMP_SOURCE_UNIX)


##### CONFIG_LOG_TIMESTAMP_SUPPORT

Found in: Component config > Log > Format

- Yes (enabled) if CONFIG_LOG_VERSION_2

Yes (enabled) if CONFIG_LOG_VERSION_2


#### Settings

- CONFIG_LOG_MODE

CONFIG_LOG_MODE


##### CONFIG_LOG_MODE

Found in: Component config > Log > Settings

Available options:

- Text Log Mode (CONFIG_LOG_MODE_TEXT) Enables text-based logging, where log messages are stored in a human-readable format. This mode is useful for development and debugging, as it allows logs to be easily read and interpreted without additional processing.

Text Log Mode (CONFIG_LOG_MODE_TEXT)

Binary Log Mode (CONFIG_LOG_MODE_BINARY)


#### CONFIG_LOG_IN_IRAM

Found in: Component config > Log

- Yes (enabled)


### LWIP

CONFIG_LWIP_CHECK_THREAD_SAFETY

CONFIG_LWIP_DHCP_CHECKS_OFFERED_ADDRESS

CONFIG_LWIP_DHCP_COARSE_TIMER_SECS

CONFIG_LWIP_DHCP_OPTIONS_LEN

CONFIG_LWIP_DHCP_DISABLE_CLIENT_ID

CONFIG_LWIP_DHCP_DISABLE_VENDOR_CLASS_ID

CONFIG_LWIP_DHCP_RESTORE_LAST_IP

CONFIG_LWIP_L2_TO_L3_COPY

CONFIG_LWIP_IPV6_DHCP6

CONFIG_LWIP_IP4_FRAG

CONFIG_LWIP_IP6_FRAG

CONFIG_LWIP_IP_FORWARD

CONFIG_LWIP_NETBUF_RECVINFO

CONFIG_LWIP_IPV4

CONFIG_LWIP_AUTOIP

CONFIG_LWIP_IPV6

CONFIG_LWIP_IPV6_ND6_ROUTE_INFO_OPTION_SUPPORT

CONFIG_LWIP_NETIF_LINK_CALLBACK

CONFIG_LWIP_ESP_LWIP_ASSERT

CONFIG_LWIP_DEBUG

CONFIG_LWIP_IRAM_OPTIMIZATION

CONFIG_LWIP_EXTRA_IRAM_OPTIMIZATION

CONFIG_LWIP_ENABLE

CONFIG_LWIP_STATS

CONFIG_LWIP_TIMERS_ONDEMAND

CONFIG_LWIP_DNS_SUPPORT_MDNS_QUERIES

CONFIG_LWIP_PPP_SUPPORT

CONFIG_LWIP_IP4_REASSEMBLY

CONFIG_LWIP_IP6_REASSEMBLY

CONFIG_LWIP_SLIP_SUPPORT

CONFIG_LWIP_SO_LINGER

CONFIG_LWIP_SO_RCVBUF

CONFIG_LWIP_SO_REUSE

CONFIG_LWIP_NETIF_STATUS_CALLBACK

CONFIG_LWIP_TCPIP_CORE_LOCKING

CONFIG_LWIP_LOCAL_HOSTNAME

CONFIG_LWIP_ND6

CONFIG_LWIP_TCPIP_TASK_PRIO

CONFIG_LWIP_IPV6_ND6_NUM_ROUTERS

CONFIG_LWIP_IPV6_ND6_NUM_DESTINATIONS

CONFIG_LWIP_IPV6_ND6_NUM_NEIGHBORS

CONFIG_LWIP_IPV6_ND6_NUM_PREFIXES

CONFIG_LWIP_IPV6_MEMP_NUM_ND6_QUEUE

CONFIG_LWIP_MAX_SOCKETS

CONFIG_LWIP_BRIDGEIF_MAX_PORTS

CONFIG_LWIP_NUM_NETIF_CLIENT_DATA

CONFIG_LWIP_IPV6_DUP_DETECT_ATTEMPTS

CONFIG_LWIP_ESP_GRATUITOUS_ARP

CONFIG_LWIP_ESP_MLDV6_REPORT

CONFIG_LWIP_USE_ONLY_LWIP_SELECT

CONFIG_LWIP_NETIF_LOOPBACK

CONFIG_LWIP_TCPIP_TASK_AFFINITY

CONFIG_LWIP_TCPIP_TASK_STACK_SIZE

CONFIG_LWIP_TCPIP_RECVMBOX_SIZE

CONFIG_LWIP_IP_REASS_MAX_PBUFS

CONFIG_LWIP_IP_DEFAULT_TTL

CONFIG_LWIP_IPV6_RDNSS_MAX_DNS_SERVERS


#### CONFIG_LWIP_ENABLE

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_LOCAL_HOSTNAME

Found in: Component config > LWIP

- "espressif"


#### CONFIG_LWIP_TCPIP_TASK_PRIO

Found in: Component config > LWIP

- from 1 to 24

- 18


#### CONFIG_LWIP_TCPIP_CORE_LOCKING

Found in: Component config > LWIP

- No (disabled)


##### CONFIG_LWIP_TCPIP_CORE_LOCKING_INPUT

Found in: Component config > LWIP > CONFIG_LWIP_TCPIP_CORE_LOCKING

- No (disabled) if CONFIG_LWIP_TCPIP_CORE_LOCKING

No (disabled) if CONFIG_LWIP_TCPIP_CORE_LOCKING


#### CONFIG_LWIP_CHECK_THREAD_SAFETY

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_DNS_SUPPORT_MDNS_QUERIES

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_L2_TO_L3_COPY

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_IRAM_OPTIMIZATION

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_EXTRA_IRAM_OPTIMIZATION

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_TIMERS_ONDEMAND

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_ND6

Found in: Component config > LWIP

- Yes (enabled)


##### CONFIG_LWIP_FORCE_ROUTER_FORWARDING

Found in: Component config > LWIP > CONFIG_LWIP_ND6

- No (disabled)


#### CONFIG_LWIP_MAX_SOCKETS

Found in: Component config > LWIP

- from 1 to 253

- 10


#### CONFIG_LWIP_USE_ONLY_LWIP_SELECT

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_SO_LINGER

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_SO_REUSE

Found in: Component config > LWIP

- Yes (enabled)


##### CONFIG_LWIP_SO_REUSE_RXTOALL

Found in: Component config > LWIP > CONFIG_LWIP_SO_REUSE

- Yes (enabled)


#### CONFIG_LWIP_SO_RCVBUF

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_NETBUF_RECVINFO

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_IP_DEFAULT_TTL

Found in: Component config > LWIP

- from 1 to 255

- 64


#### CONFIG_LWIP_IP4_FRAG

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_IP6_FRAG

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_IP4_REASSEMBLY

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_IP6_REASSEMBLY

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_IP_REASS_MAX_PBUFS

Found in: Component config > LWIP

- from 10 to 100

- 10


#### CONFIG_LWIP_IPV6_DUP_DETECT_ATTEMPTS

Found in: Component config > LWIP

- from 0 to 7

- 1


#### CONFIG_LWIP_IP_FORWARD

Found in: Component config > LWIP

- No (disabled)


##### CONFIG_LWIP_IPV4_NAPT

Found in: Component config > LWIP > CONFIG_LWIP_IP_FORWARD

- No (disabled) if CONFIG_LWIP_IP_FORWARD

No (disabled) if CONFIG_LWIP_IP_FORWARD


##### CONFIG_LWIP_IPV4_NAPT_PORTMAP

Found in: Component config > LWIP > CONFIG_LWIP_IP_FORWARD > CONFIG_LWIP_IPV4_NAPT

- Yes (enabled) if CONFIG_LWIP_IPV4_NAPT

Yes (enabled) if CONFIG_LWIP_IPV4_NAPT


#### CONFIG_LWIP_STATS

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_ESP_GRATUITOUS_ARP

Found in: Component config > LWIP

- Yes (enabled)


##### CONFIG_LWIP_GARP_TMR_INTERVAL

Found in: Component config > LWIP > CONFIG_LWIP_ESP_GRATUITOUS_ARP

- 60


#### CONFIG_LWIP_ESP_MLDV6_REPORT

Found in: Component config > LWIP

- Yes (enabled)


##### CONFIG_LWIP_MLDV6_TMR_INTERVAL

Found in: Component config > LWIP > CONFIG_LWIP_ESP_MLDV6_REPORT

- 40


#### CONFIG_LWIP_TCPIP_RECVMBOX_SIZE

Found in: Component config > LWIP

- from 6 to 1024 if CONFIG_LWIP_WND_SCALE

from 6 to 1024 if CONFIG_LWIP_WND_SCALE

- 32


#### CONFIG_LWIP_DHCP_CHECKS_OFFERED_ADDRESS

Found in: Component config > LWIP

Available options:

- DHCP provides simple ARP check (CONFIG_LWIP_DHCP_DOES_ARP_CHECK)
- DHCP provides Address Conflict Detection (ACD) (CONFIG_LWIP_DHCP_DOES_ACD_CHECK)
- DHCP does not detect conflict on the offered IP (CONFIG_LWIP_DHCP_DOES_NOT_CHECK_OFFERED_IP)

DHCP provides simple ARP check (CONFIG_LWIP_DHCP_DOES_ARP_CHECK)


#### CONFIG_LWIP_DHCP_DISABLE_CLIENT_ID

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_DHCP_DISABLE_VENDOR_CLASS_ID

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_DHCP_RESTORE_LAST_IP

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_DHCP_OPTIONS_LEN

Found in: Component config > LWIP

- from 69 to 255

- 69


#### CONFIG_LWIP_NUM_NETIF_CLIENT_DATA

Found in: Component config > LWIP

- from 0 to 256

- 0


#### CONFIG_LWIP_DHCP_COARSE_TIMER_SECS

Found in: Component config > LWIP

- from 1 to 10

- 1


#### DHCP server

- CONFIG_LWIP_DHCPS
- CONFIG_LWIP_DHCPS_STATIC_ENTRIES
- CONFIG_LWIP_DHCPS_MAX_HOSTNAME_LEN

CONFIG_LWIP_DHCPS

CONFIG_LWIP_DHCPS_STATIC_ENTRIES

CONFIG_LWIP_DHCPS_MAX_HOSTNAME_LEN


##### CONFIG_LWIP_DHCPS

Found in: Component config > LWIP > DHCP server

- Yes (enabled)


##### CONFIG_LWIP_DHCPS_REPORT_CLIENT_HOSTNAME

Found in: Component config > LWIP > DHCP server > CONFIG_LWIP_DHCPS

- Yes (enabled)


##### CONFIG_LWIP_DHCPS_LEASE_UNIT

Found in: Component config > LWIP > DHCP server > CONFIG_LWIP_DHCPS

- from 1 to 3600

- 60


##### CONFIG_LWIP_DHCPS_MAX_STATION_NUM

Found in: Component config > LWIP > DHCP server > CONFIG_LWIP_DHCPS

- from 1 to 64

- 8


##### CONFIG_LWIP_DHCPS_MAX_HOSTNAME_LEN

Found in: Component config > LWIP > DHCP server

- from 1 to 255

- 64


##### CONFIG_LWIP_DHCPS_STATIC_ENTRIES

Found in: Component config > LWIP > DHCP server

- Yes (enabled)


#### CONFIG_LWIP_AUTOIP

Found in: Component config > LWIP

- No (disabled)

- CONFIG_LWIP_AUTOIP_TRIES
- CONFIG_LWIP_AUTOIP_MAX_CONFLICTS
- CONFIG_LWIP_AUTOIP_RATE_LIMIT_INTERVAL

CONFIG_LWIP_AUTOIP_TRIES

CONFIG_LWIP_AUTOIP_MAX_CONFLICTS

CONFIG_LWIP_AUTOIP_RATE_LIMIT_INTERVAL


##### CONFIG_LWIP_AUTOIP_TRIES

Found in: Component config > LWIP > CONFIG_LWIP_AUTOIP

- from 1 to 100 if CONFIG_LWIP_AUTOIP

from 1 to 100 if CONFIG_LWIP_AUTOIP

- 2 if CONFIG_LWIP_AUTOIP

2 if CONFIG_LWIP_AUTOIP


##### CONFIG_LWIP_AUTOIP_MAX_CONFLICTS

Found in: Component config > LWIP > CONFIG_LWIP_AUTOIP

- from 1 to 100 if CONFIG_LWIP_AUTOIP

from 1 to 100 if CONFIG_LWIP_AUTOIP

- 9 if CONFIG_LWIP_AUTOIP

9 if CONFIG_LWIP_AUTOIP


##### CONFIG_LWIP_AUTOIP_RATE_LIMIT_INTERVAL

Found in: Component config > LWIP > CONFIG_LWIP_AUTOIP

- from 5 to 120 if CONFIG_LWIP_AUTOIP

from 5 to 120 if CONFIG_LWIP_AUTOIP

- 20 if CONFIG_LWIP_AUTOIP

20 if CONFIG_LWIP_AUTOIP


#### CONFIG_LWIP_IPV4

Found in: Component config > LWIP

- Yes (enabled)


#### CONFIG_LWIP_IPV6

Found in: Component config > LWIP

- Yes (enabled)


##### CONFIG_LWIP_IPV6_AUTOCONFIG

Found in: Component config > LWIP > CONFIG_LWIP_IPV6

- No (disabled)


##### CONFIG_LWIP_IPV6_NUM_ADDRESSES

Found in: Component config > LWIP > CONFIG_LWIP_IPV6

- 3


##### CONFIG_LWIP_IPV6_FORWARD

Found in: Component config > LWIP > CONFIG_LWIP_IPV6

- No (disabled)


#### CONFIG_LWIP_IPV6_RDNSS_MAX_DNS_SERVERS

Found in: Component config > LWIP

- 0 if CONFIG_LWIP_IPV6_AUTOCONFIG

0 if CONFIG_LWIP_IPV6_AUTOCONFIG


#### CONFIG_LWIP_IPV6_DHCP6

Found in: Component config > LWIP

- No (disabled) if CONFIG_LWIP_IPV6_AUTOCONFIG

No (disabled) if CONFIG_LWIP_IPV6_AUTOCONFIG


#### CONFIG_LWIP_NETIF_STATUS_CALLBACK

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_NETIF_LINK_CALLBACK

Found in: Component config > LWIP

- No (disabled)


#### CONFIG_LWIP_NETIF_LOOPBACK

Found in: Component config > LWIP

- Yes (enabled)

- CONFIG_LWIP_LOOPBACK_MAX_PBUFS

CONFIG_LWIP_LOOPBACK_MAX_PBUFS


##### CONFIG_LWIP_LOOPBACK_MAX_PBUFS

Found in: Component config > LWIP > CONFIG_LWIP_NETIF_LOOPBACK

- from 0 to 16

- 8


#### TCP

- CONFIG_LWIP_TCP_WND_DEFAULT
- CONFIG_LWIP_TCP_SND_BUF_DEFAULT
- CONFIG_LWIP_TCP_ACCEPTMBOX_SIZE
- CONFIG_LWIP_TCP_RECVMBOX_SIZE
- CONFIG_LWIP_TCP_RTO_TIME
- CONFIG_LWIP_MAX_ACTIVE_TCP
- CONFIG_LWIP_TCP_FIN_WAIT_TIMEOUT
- CONFIG_LWIP_MAX_LISTENING_TCP
- CONFIG_LWIP_TCP_MAXRTX
- CONFIG_LWIP_TCP_SYNMAXRTX
- CONFIG_LWIP_TCP_MSL
- CONFIG_LWIP_TCP_MSS
- CONFIG_LWIP_TCP_OVERSIZE
- CONFIG_LWIP_TCP_QUEUE_OOSEQ
- CONFIG_LWIP_WND_SCALE
- CONFIG_LWIP_TCP_HIGH_SPEED_RETRANSMISSION
- CONFIG_LWIP_TCP_TMR_INTERVAL

CONFIG_LWIP_TCP_WND_DEFAULT

CONFIG_LWIP_TCP_SND_BUF_DEFAULT

CONFIG_LWIP_TCP_ACCEPTMBOX_SIZE

CONFIG_LWIP_TCP_RECVMBOX_SIZE

CONFIG_LWIP_TCP_RTO_TIME

CONFIG_LWIP_MAX_ACTIVE_TCP

CONFIG_LWIP_TCP_FIN_WAIT_TIMEOUT

CONFIG_LWIP_MAX_LISTENING_TCP

CONFIG_LWIP_TCP_MAXRTX

CONFIG_LWIP_TCP_SYNMAXRTX

CONFIG_LWIP_TCP_MSL

CONFIG_LWIP_TCP_MSS

CONFIG_LWIP_TCP_OVERSIZE

CONFIG_LWIP_TCP_QUEUE_OOSEQ

CONFIG_LWIP_WND_SCALE

CONFIG_LWIP_TCP_HIGH_SPEED_RETRANSMISSION

CONFIG_LWIP_TCP_TMR_INTERVAL


##### CONFIG_LWIP_MAX_ACTIVE_TCP

Found in: Component config > LWIP > TCP

- from 1 to 1024

- 16


##### CONFIG_LWIP_MAX_LISTENING_TCP

Found in: Component config > LWIP > TCP

- from 1 to 1024

- 16


##### CONFIG_LWIP_TCP_HIGH_SPEED_RETRANSMISSION

Found in: Component config > LWIP > TCP

- Yes (enabled)


##### CONFIG_LWIP_TCP_MAXRTX

Found in: Component config > LWIP > TCP

- from 3 to 12

- 12


##### CONFIG_LWIP_TCP_SYNMAXRTX

Found in: Component config > LWIP > TCP

- from 3 to 12

- 12


##### CONFIG_LWIP_TCP_MSS

Found in: Component config > LWIP > TCP

- from 536 to 1460

- 1440


##### CONFIG_LWIP_TCP_TMR_INTERVAL

Found in: Component config > LWIP > TCP

- 250


##### CONFIG_LWIP_TCP_MSL

Found in: Component config > LWIP > TCP

- 60000


##### CONFIG_LWIP_TCP_FIN_WAIT_TIMEOUT

Found in: Component config > LWIP > TCP

- 20000


##### CONFIG_LWIP_TCP_SND_BUF_DEFAULT

Found in: Component config > LWIP > TCP

- from 2440 to 1024000 if CONFIG_LWIP_WND_SCALE

from 2440 to 1024000 if CONFIG_LWIP_WND_SCALE

- 5760


##### CONFIG_LWIP_TCP_WND_DEFAULT

Found in: Component config > LWIP > TCP

- from 2440 to 1024000 if CONFIG_LWIP_WND_SCALE

from 2440 to 1024000 if CONFIG_LWIP_WND_SCALE

- 5760


##### CONFIG_LWIP_TCP_RECVMBOX_SIZE

Found in: Component config > LWIP > TCP

- from 6 to 1024 if CONFIG_LWIP_WND_SCALE

from 6 to 1024 if CONFIG_LWIP_WND_SCALE

- 6


##### CONFIG_LWIP_TCP_ACCEPTMBOX_SIZE

Found in: Component config > LWIP > TCP

- from 1 to 255 if CONFIG_LWIP_WND_SCALE

from 1 to 255 if CONFIG_LWIP_WND_SCALE

- 6


##### CONFIG_LWIP_TCP_QUEUE_OOSEQ

Found in: Component config > LWIP > TCP

- Yes (enabled)


##### CONFIG_LWIP_TCP_OOSEQ_TIMEOUT

Found in: Component config > LWIP > TCP > CONFIG_LWIP_TCP_QUEUE_OOSEQ

- from 1 to 30

- 6


##### CONFIG_LWIP_TCP_OOSEQ_MAX_PBUFS

Found in: Component config > LWIP > TCP > CONFIG_LWIP_TCP_QUEUE_OOSEQ

- from 0 to 12

- 4


##### CONFIG_LWIP_TCP_SACK_OUT

Found in: Component config > LWIP > TCP > CONFIG_LWIP_TCP_QUEUE_OOSEQ

- No (disabled)


##### CONFIG_LWIP_TCP_OVERSIZE

Found in: Component config > LWIP > TCP

Available options:

- MSS (CONFIG_LWIP_TCP_OVERSIZE_MSS)
- 25% MSS (CONFIG_LWIP_TCP_OVERSIZE_QUARTER_MSS)
- Disabled (CONFIG_LWIP_TCP_OVERSIZE_DISABLE)

MSS (CONFIG_LWIP_TCP_OVERSIZE_MSS)

25% MSS (CONFIG_LWIP_TCP_OVERSIZE_QUARTER_MSS)

Disabled (CONFIG_LWIP_TCP_OVERSIZE_DISABLE)


##### CONFIG_LWIP_WND_SCALE

Found in: Component config > LWIP > TCP


##### CONFIG_LWIP_TCP_RCV_SCALE

Found in: Component config > LWIP > TCP > CONFIG_LWIP_WND_SCALE

- from 0 to 14 if CONFIG_LWIP_WND_SCALE

from 0 to 14 if CONFIG_LWIP_WND_SCALE

- 0 if CONFIG_LWIP_WND_SCALE

0 if CONFIG_LWIP_WND_SCALE


##### CONFIG_LWIP_TCP_RTO_TIME

Found in: Component config > LWIP > TCP

- 1500


#### UDP

- CONFIG_LWIP_UDP_RECVMBOX_SIZE
- CONFIG_LWIP_MAX_UDP_PCBS

CONFIG_LWIP_UDP_RECVMBOX_SIZE

CONFIG_LWIP_MAX_UDP_PCBS


##### CONFIG_LWIP_MAX_UDP_PCBS

Found in: Component config > LWIP > UDP

- from 1 to 1024

- 16


##### CONFIG_LWIP_UDP_RECVMBOX_SIZE

Found in: Component config > LWIP > UDP

- from 6 to 64

- 6


#### Checksums

- CONFIG_LWIP_CHECKSUM_CHECK_ICMP
- CONFIG_LWIP_CHECKSUM_CHECK_IP
- CONFIG_LWIP_CHECKSUM_CHECK_UDP

CONFIG_LWIP_CHECKSUM_CHECK_ICMP

CONFIG_LWIP_CHECKSUM_CHECK_IP

CONFIG_LWIP_CHECKSUM_CHECK_UDP


##### CONFIG_LWIP_CHECKSUM_CHECK_IP

Found in: Component config > LWIP > Checksums

- No (disabled)


##### CONFIG_LWIP_CHECKSUM_CHECK_UDP

Found in: Component config > LWIP > Checksums

- No (disabled)


##### CONFIG_LWIP_CHECKSUM_CHECK_ICMP

Found in: Component config > LWIP > Checksums

- Yes (enabled)


#### CONFIG_LWIP_TCPIP_TASK_STACK_SIZE

Found in: Component config > LWIP

- from 2048 to 65536

- 3072


#### CONFIG_LWIP_TCPIP_TASK_AFFINITY

Found in: Component config > LWIP

Available options:

- No affinity (CONFIG_LWIP_TCPIP_TASK_AFFINITY_NO_AFFINITY)
- CPU0 (CONFIG_LWIP_TCPIP_TASK_AFFINITY_CPU0)
- CPU1 (CONFIG_LWIP_TCPIP_TASK_AFFINITY_CPU1)

No affinity (CONFIG_LWIP_TCPIP_TASK_AFFINITY_NO_AFFINITY)

CPU0 (CONFIG_LWIP_TCPIP_TASK_AFFINITY_CPU0)

CPU1 (CONFIG_LWIP_TCPIP_TASK_AFFINITY_CPU1)


#### CONFIG_LWIP_IPV6_MEMP_NUM_ND6_QUEUE

Found in: Component config > LWIP

- from 3 to 20

- 3


#### CONFIG_LWIP_IPV6_ND6_NUM_NEIGHBORS

Found in: Component config > LWIP

- from 3 to 10

- 5


#### CONFIG_LWIP_IPV6_ND6_NUM_PREFIXES

Found in: Component config > LWIP

- 5


#### CONFIG_LWIP_IPV6_ND6_NUM_ROUTERS

Found in: Component config > LWIP

- 3


#### CONFIG_LWIP_IPV6_ND6_NUM_DESTINATIONS

Found in: Component config > LWIP

- 10


#### CONFIG_LWIP_IPV6_ND6_ROUTE_INFO_OPTION_SUPPORT

Found in: Component config > LWIP

- No (disabled)


##### CONFIG_LWIP_IPV6_ND6_NUM_ROUTE_INFO

Found in: Component config > LWIP > CONFIG_LWIP_IPV6_ND6_ROUTE_INFO_OPTION_SUPPORT

- 10 if CONFIG_LWIP_IPV6_ND6_ROUTE_INFO_OPTION_SUPPORT

10 if CONFIG_LWIP_IPV6_ND6_ROUTE_INFO_OPTION_SUPPORT


#### CONFIG_LWIP_PPP_SUPPORT

Found in: Component config > LWIP

- No (disabled)

- CONFIG_LWIP_PPP_CHAP_SUPPORT
- CONFIG_LWIP_PPP_ENABLE_IPV4
- CONFIG_LWIP_PPP_ENABLE_IPV6
- CONFIG_LWIP_ENABLE_LCP_ECHO
- CONFIG_LWIP_PPP_MPPE_SUPPORT
- CONFIG_LWIP_PPP_MSCHAP_SUPPORT
- CONFIG_LWIP_PPP_NOTIFY_PHASE_SUPPORT
- CONFIG_LWIP_PPP_PAP_SUPPORT
- CONFIG_LWIP_PPP_DEBUG_ON
- CONFIG_LWIP_PPP_SERVER_SUPPORT
- CONFIG_LWIP_PPP_VJ_HEADER_COMPRESSION
- CONFIG_LWIP_USE_EXTERNAL_MBEDTLS

CONFIG_LWIP_PPP_CHAP_SUPPORT

CONFIG_LWIP_PPP_ENABLE_IPV4

CONFIG_LWIP_PPP_ENABLE_IPV6

CONFIG_LWIP_ENABLE_LCP_ECHO

CONFIG_LWIP_PPP_MPPE_SUPPORT

CONFIG_LWIP_PPP_MSCHAP_SUPPORT

CONFIG_LWIP_PPP_NOTIFY_PHASE_SUPPORT

CONFIG_LWIP_PPP_PAP_SUPPORT

CONFIG_LWIP_PPP_DEBUG_ON

CONFIG_LWIP_PPP_SERVER_SUPPORT

CONFIG_LWIP_PPP_VJ_HEADER_COMPRESSION

CONFIG_LWIP_USE_EXTERNAL_MBEDTLS


##### CONFIG_LWIP_PPP_ENABLE_IPV4

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- Yes (enabled) if CONFIG_LWIP_PPP_SUPPORT && CONFIG_LWIP_IPV4

Yes (enabled) if CONFIG_LWIP_PPP_SUPPORT && CONFIG_LWIP_IPV4


##### CONFIG_LWIP_PPP_ENABLE_IPV6

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- Yes (enabled) if CONFIG_LWIP_PPP_SUPPORT && CONFIG_LWIP_IPV6

Yes (enabled) if CONFIG_LWIP_PPP_SUPPORT && CONFIG_LWIP_IPV6


##### CONFIG_LWIP_PPP_NOTIFY_PHASE_SUPPORT

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_PPP_PAP_SUPPORT

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_PPP_CHAP_SUPPORT

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_PPP_MSCHAP_SUPPORT

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_PPP_MPPE_SUPPORT

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_PPP_SERVER_SUPPORT

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_PPP_VJ_HEADER_COMPRESSION

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- Yes (enabled) if CONFIG_LWIP_PPP_SUPPORT

Yes (enabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_ENABLE_LCP_ECHO

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_LCP_ECHOINTERVAL

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT > CONFIG_LWIP_ENABLE_LCP_ECHO

- from 0 to 1000000 if CONFIG_LWIP_ENABLE_LCP_ECHO

from 0 to 1000000 if CONFIG_LWIP_ENABLE_LCP_ECHO

- 3 if CONFIG_LWIP_ENABLE_LCP_ECHO

3 if CONFIG_LWIP_ENABLE_LCP_ECHO


##### CONFIG_LWIP_LCP_MAXECHOFAILS

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT > CONFIG_LWIP_ENABLE_LCP_ECHO

- from 0 to 100000 if CONFIG_LWIP_ENABLE_LCP_ECHO

from 0 to 100000 if CONFIG_LWIP_ENABLE_LCP_ECHO

- 3 if CONFIG_LWIP_ENABLE_LCP_ECHO

3 if CONFIG_LWIP_ENABLE_LCP_ECHO


##### CONFIG_LWIP_PPP_DEBUG_ON

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT

- No (disabled) if CONFIG_LWIP_PPP_SUPPORT

No (disabled) if CONFIG_LWIP_PPP_SUPPORT


##### CONFIG_LWIP_USE_EXTERNAL_MBEDTLS

Found in: Component config > LWIP > CONFIG_LWIP_PPP_SUPPORT


#### CONFIG_LWIP_SLIP_SUPPORT

Found in: Component config > LWIP

- No (disabled)

- CONFIG_LWIP_SLIP_DEBUG_ON

CONFIG_LWIP_SLIP_DEBUG_ON


##### CONFIG_LWIP_SLIP_DEBUG_ON

Found in: Component config > LWIP > CONFIG_LWIP_SLIP_SUPPORT

- No (disabled) if CONFIG_LWIP_SLIP_SUPPORT

No (disabled) if CONFIG_LWIP_SLIP_SUPPORT


#### ICMP

- CONFIG_LWIP_ICMP
- CONFIG_LWIP_BROADCAST_PING
- CONFIG_LWIP_MULTICAST_PING

CONFIG_LWIP_ICMP

CONFIG_LWIP_BROADCAST_PING

CONFIG_LWIP_MULTICAST_PING


##### CONFIG_LWIP_ICMP

Found in: Component config > LWIP > ICMP

- Yes (enabled)


##### CONFIG_LWIP_MULTICAST_PING

Found in: Component config > LWIP > ICMP

- No (disabled)


##### CONFIG_LWIP_BROADCAST_PING

Found in: Component config > LWIP > ICMP

- No (disabled)


#### LWIP RAW API

- CONFIG_LWIP_MAX_RAW_PCBS

CONFIG_LWIP_MAX_RAW_PCBS


##### CONFIG_LWIP_MAX_RAW_PCBS

Found in: Component config > LWIP > LWIP RAW API

- from 1 to 1024

- 16


#### SNTP

- CONFIG_LWIP_SNTP_STARTUP_DELAY
- CONFIG_LWIP_SNTP_MAX_SERVERS
- CONFIG_LWIP_SNTP_UPDATE_DELAY
- CONFIG_LWIP_DHCP_GET_NTP_SRV

CONFIG_LWIP_SNTP_STARTUP_DELAY

CONFIG_LWIP_SNTP_MAX_SERVERS

CONFIG_LWIP_SNTP_UPDATE_DELAY

CONFIG_LWIP_DHCP_GET_NTP_SRV


##### CONFIG_LWIP_SNTP_MAX_SERVERS

Found in: Component config > LWIP > SNTP

- from 1 to 16

- 1


##### CONFIG_LWIP_DHCP_GET_NTP_SRV

Found in: Component config > LWIP > SNTP

- No (disabled)


##### CONFIG_LWIP_DHCP_MAX_NTP_SERVERS

Found in: Component config > LWIP > SNTP > CONFIG_LWIP_DHCP_GET_NTP_SRV

- from 1 to 16 if CONFIG_LWIP_DHCP_GET_NTP_SRV

from 1 to 16 if CONFIG_LWIP_DHCP_GET_NTP_SRV

- 1 if CONFIG_LWIP_DHCP_GET_NTP_SRV

1 if CONFIG_LWIP_DHCP_GET_NTP_SRV


##### CONFIG_LWIP_SNTP_UPDATE_DELAY

Found in: Component config > LWIP > SNTP

- from 15000 to 4294967295

- 3600000


##### CONFIG_LWIP_SNTP_STARTUP_DELAY

Found in: Component config > LWIP > SNTP

- Yes (enabled)


##### CONFIG_LWIP_SNTP_MAXIMUM_STARTUP_DELAY

Found in: Component config > LWIP > SNTP > CONFIG_LWIP_SNTP_STARTUP_DELAY

- from 100 to 300000

- 5000


#### DNS

- CONFIG_LWIP_FALLBACK_DNS_SERVER_SUPPORT
- CONFIG_LWIP_DNS_SETSERVER_WITH_NETIF
- CONFIG_LWIP_USE_ESP_GETADDRINFO
- CONFIG_LWIP_DNS_MAX_SERVERS
- CONFIG_LWIP_DNS_MAX_HOST_IP

CONFIG_LWIP_FALLBACK_DNS_SERVER_SUPPORT

CONFIG_LWIP_DNS_SETSERVER_WITH_NETIF

CONFIG_LWIP_USE_ESP_GETADDRINFO

CONFIG_LWIP_DNS_MAX_SERVERS

CONFIG_LWIP_DNS_MAX_HOST_IP


##### CONFIG_LWIP_DNS_MAX_HOST_IP

Found in: Component config > LWIP > DNS

- 1


##### CONFIG_LWIP_DNS_MAX_SERVERS

Found in: Component config > LWIP > DNS

- from 1 to 4

- 3


##### CONFIG_LWIP_FALLBACK_DNS_SERVER_SUPPORT

Found in: Component config > LWIP > DNS

- No (disabled)


##### CONFIG_LWIP_FALLBACK_DNS_SERVER_ADDRESS

Found in: Component config > LWIP > DNS > CONFIG_LWIP_FALLBACK_DNS_SERVER_SUPPORT

- "114.114.114.114" if CONFIG_LWIP_FALLBACK_DNS_SERVER_SUPPORT

"114.114.114.114" if CONFIG_LWIP_FALLBACK_DNS_SERVER_SUPPORT


##### CONFIG_LWIP_DNS_SETSERVER_WITH_NETIF

Found in: Component config > LWIP > DNS

- No (disabled)


##### CONFIG_LWIP_USE_ESP_GETADDRINFO

Found in: Component config > LWIP > DNS

- No (disabled)


#### CONFIG_LWIP_BRIDGEIF_MAX_PORTS

Found in: Component config > LWIP

- from 1 to 63

- 7


#### CONFIG_LWIP_ESP_LWIP_ASSERT

Found in: Component config > LWIP


#### Hooks

- CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION
- CONFIG_LWIP_HOOK_DNS_EXTERNAL_RESOLVE
- CONFIG_LWIP_HOOK_ND6_GET_GW
- CONFIG_LWIP_HOOK_IP6_INPUT
- CONFIG_LWIP_HOOK_IP6_ROUTE
- CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR
- CONFIG_LWIP_HOOK_NETCONN_EXTERNAL_RESOLVE
- CONFIG_LWIP_HOOK_TCP_ISN

CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION

CONFIG_LWIP_HOOK_DNS_EXTERNAL_RESOLVE

CONFIG_LWIP_HOOK_ND6_GET_GW

CONFIG_LWIP_HOOK_IP6_INPUT

CONFIG_LWIP_HOOK_IP6_ROUTE

CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR

CONFIG_LWIP_HOOK_NETCONN_EXTERNAL_RESOLVE

CONFIG_LWIP_HOOK_TCP_ISN


##### CONFIG_LWIP_HOOK_TCP_ISN

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_TCP_ISN_NONE)
- Default implementation (CONFIG_LWIP_HOOK_TCP_ISN_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_TCP_ISN_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_TCP_ISN_NONE)

Default implementation (CONFIG_LWIP_HOOK_TCP_ISN_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_TCP_ISN_CUSTOM)


##### CONFIG_LWIP_HOOK_IP6_ROUTE

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_IP6_ROUTE_NONE)
- Default (weak) implementation (CONFIG_LWIP_HOOK_IP6_ROUTE_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_IP6_ROUTE_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_IP6_ROUTE_NONE)

Default (weak) implementation (CONFIG_LWIP_HOOK_IP6_ROUTE_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_IP6_ROUTE_CUSTOM)


##### CONFIG_LWIP_HOOK_ND6_GET_GW

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_ND6_GET_GW_NONE)
- Default (weak) implementation (CONFIG_LWIP_HOOK_ND6_GET_GW_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_ND6_GET_GW_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_ND6_GET_GW_NONE)

Default (weak) implementation (CONFIG_LWIP_HOOK_ND6_GET_GW_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_ND6_GET_GW_CUSTOM)


##### CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR_NONE)
- Default (weak) implementation (CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR_NONE)

Default (weak) implementation (CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_IP6_SELECT_SRC_ADDR_CUSTOM)


##### CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION_NONE)
- Default (weak) implementation (CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION_NONE)

Default (weak) implementation (CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_DHCP_EXTRA_OPTION_CUSTOM)


##### CONFIG_LWIP_HOOK_NETCONN_EXTERNAL_RESOLVE

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_NETCONN_EXT_RESOLVE_NONE)
- Default (weak) implementation (CONFIG_LWIP_HOOK_NETCONN_EXT_RESOLVE_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_NETCONN_EXT_RESOLVE_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_NETCONN_EXT_RESOLVE_NONE)

Default (weak) implementation (CONFIG_LWIP_HOOK_NETCONN_EXT_RESOLVE_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_NETCONN_EXT_RESOLVE_CUSTOM)


##### CONFIG_LWIP_HOOK_DNS_EXTERNAL_RESOLVE

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_DNS_EXT_RESOLVE_NONE)
- Custom implementation (CONFIG_LWIP_HOOK_DNS_EXT_RESOLVE_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_DNS_EXT_RESOLVE_NONE)

Custom implementation (CONFIG_LWIP_HOOK_DNS_EXT_RESOLVE_CUSTOM)


##### CONFIG_LWIP_HOOK_IP6_INPUT

Found in: Component config > LWIP > Hooks

Available options:

- No hook declared (CONFIG_LWIP_HOOK_IP6_INPUT_NONE)
- Default (weak) implementation (CONFIG_LWIP_HOOK_IP6_INPUT_DEFAULT)
- Custom implementation (CONFIG_LWIP_HOOK_IP6_INPUT_CUSTOM)

No hook declared (CONFIG_LWIP_HOOK_IP6_INPUT_NONE)

Default (weak) implementation (CONFIG_LWIP_HOOK_IP6_INPUT_DEFAULT)

Custom implementation (CONFIG_LWIP_HOOK_IP6_INPUT_CUSTOM)


#### CONFIG_LWIP_DEBUG

Found in: Component config > LWIP

- No (disabled)

- CONFIG_LWIP_API_LIB_DEBUG
- CONFIG_LWIP_BRIDGEIF_FDB_DEBUG
- CONFIG_LWIP_BRIDGEIF_FW_DEBUG
- CONFIG_LWIP_BRIDGEIF_DEBUG
- CONFIG_LWIP_DHCP_DEBUG
- CONFIG_LWIP_DHCP_STATE_DEBUG
- CONFIG_LWIP_DNS_DEBUG
- CONFIG_LWIP_ETHARP_DEBUG
- CONFIG_LWIP_ICMP_DEBUG
- CONFIG_LWIP_ICMP6_DEBUG
- CONFIG_LWIP_IP_DEBUG
- CONFIG_LWIP_IP6_DEBUG
- CONFIG_LWIP_NAPT_DEBUG
- CONFIG_LWIP_NETIF_DEBUG
- CONFIG_LWIP_PBUF_DEBUG
- CONFIG_LWIP_SNTP_DEBUG
- CONFIG_LWIP_SOCKETS_DEBUG
- CONFIG_LWIP_TCP_DEBUG
- CONFIG_LWIP_UDP_DEBUG
- CONFIG_LWIP_DEBUG_ESP_LOG

CONFIG_LWIP_API_LIB_DEBUG

CONFIG_LWIP_BRIDGEIF_FDB_DEBUG

CONFIG_LWIP_BRIDGEIF_FW_DEBUG

CONFIG_LWIP_BRIDGEIF_DEBUG

CONFIG_LWIP_DHCP_DEBUG

CONFIG_LWIP_DHCP_STATE_DEBUG

CONFIG_LWIP_DNS_DEBUG

CONFIG_LWIP_ETHARP_DEBUG

CONFIG_LWIP_ICMP_DEBUG

CONFIG_LWIP_ICMP6_DEBUG

CONFIG_LWIP_IP_DEBUG

CONFIG_LWIP_IP6_DEBUG

CONFIG_LWIP_NAPT_DEBUG

CONFIG_LWIP_NETIF_DEBUG

CONFIG_LWIP_PBUF_DEBUG

CONFIG_LWIP_SNTP_DEBUG

CONFIG_LWIP_SOCKETS_DEBUG

CONFIG_LWIP_TCP_DEBUG

CONFIG_LWIP_UDP_DEBUG

CONFIG_LWIP_DEBUG_ESP_LOG


##### CONFIG_LWIP_DEBUG_ESP_LOG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_NETIF_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_PBUF_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_ETHARP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_API_LIB_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_SOCKETS_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_IP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_ICMP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG && CONFIG_LWIP_ICMP

No (disabled) if CONFIG_LWIP_DEBUG && CONFIG_LWIP_ICMP


##### CONFIG_LWIP_DHCP_STATE_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_DHCP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_IP6_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_ICMP6_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_TCP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_UDP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_SNTP_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_DNS_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_NAPT_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG && CONFIG_LWIP_IPV4_NAPT

No (disabled) if CONFIG_LWIP_DEBUG && CONFIG_LWIP_IPV4_NAPT


##### CONFIG_LWIP_BRIDGEIF_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_BRIDGEIF_FDB_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


##### CONFIG_LWIP_BRIDGEIF_FW_DEBUG

Found in: Component config > LWIP > CONFIG_LWIP_DEBUG

- No (disabled) if CONFIG_LWIP_DEBUG

No (disabled) if CONFIG_LWIP_DEBUG


### mbedTLS

- Asymmetric Ciphers
- Certificates
- CONFIG_MBEDTLS_CIPHER_C
- Core Configuration
- CONFIG_MBEDTLS_TLS_ENABLED
- Encoding/Decoding
- Entropy and Random Number Generation
- Hardware Acceleration
- Hash functions
- Stream Cipher
- CONFIG_MBEDTLS_SSL_PROTO_DTLS
- Symmetric Ciphers
- CONFIG_MBEDTLS_USE_CRYPTO_ROM_IMPL
- CONFIG_MBEDTLS_USE_CRYPTO_ROM_IMPL_BOOTLOADER

CONFIG_MBEDTLS_CIPHER_C

CONFIG_MBEDTLS_TLS_ENABLED

CONFIG_MBEDTLS_SSL_PROTO_DTLS

CONFIG_MBEDTLS_USE_CRYPTO_ROM_IMPL

CONFIG_MBEDTLS_USE_CRYPTO_ROM_IMPL_BOOTLOADER


#### Core Configuration

- CONFIG_MBEDTLS_ASYMMETRIC_CONTENT_LEN
- CONFIG_MBEDTLS_COMPILER_OPTIMIZATION
- CONFIG_MBEDTLS_ERROR_STRERROR_DUMMY
- CONFIG_MBEDTLS_ERROR_STRINGS
- CONFIG_MBEDTLS_FS_IO
- CONFIG_MBEDTLS_DEBUG
- CONFIG_MBEDTLS_SELF_TEST
- CONFIG_MBEDTLS_HAVE_TIME
- CONFIG_MBEDTLS_VERSION_FEATURES
- CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO
- CONFIG_MBEDTLS_THREADING_C
- CONFIG_MBEDTLS_VERSION_C
- CONFIG_MBEDTLS_MEM_ALLOC_MODE
- CONFIG_MBEDTLS_SSL_MAX_CONTENT_LEN
- CONFIG_MBEDTLS_DYNAMIC_BUFFER

CONFIG_MBEDTLS_ASYMMETRIC_CONTENT_LEN

CONFIG_MBEDTLS_COMPILER_OPTIMIZATION

CONFIG_MBEDTLS_ERROR_STRERROR_DUMMY

CONFIG_MBEDTLS_ERROR_STRINGS

CONFIG_MBEDTLS_FS_IO

CONFIG_MBEDTLS_DEBUG

CONFIG_MBEDTLS_SELF_TEST

CONFIG_MBEDTLS_HAVE_TIME

CONFIG_MBEDTLS_VERSION_FEATURES

CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO

CONFIG_MBEDTLS_THREADING_C

CONFIG_MBEDTLS_VERSION_C

CONFIG_MBEDTLS_MEM_ALLOC_MODE

CONFIG_MBEDTLS_SSL_MAX_CONTENT_LEN

CONFIG_MBEDTLS_DYNAMIC_BUFFER


##### CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled) if CONFIG_IDF_EXPERIMENTAL_FEATURES

Yes (enabled) if CONFIG_IDF_EXPERIMENTAL_FEATURES


##### CONFIG_MBEDTLS_COMPILER_OPTIMIZATION

Found in: Component config > mbedTLS > Core Configuration

Available options:

- No optimization (CONFIG_MBEDTLS_COMPILER_OPTIMIZATION_NONE)
- Optimize for size (-Os) (CONFIG_MBEDTLS_COMPILER_OPTIMIZATION_SIZE)
- Optimize for performance (-O2) (CONFIG_MBEDTLS_COMPILER_OPTIMIZATION_PERF)

No optimization (CONFIG_MBEDTLS_COMPILER_OPTIMIZATION_NONE)

Optimize for size (-Os) (CONFIG_MBEDTLS_COMPILER_OPTIMIZATION_SIZE)

Optimize for performance (-O2) (CONFIG_MBEDTLS_COMPILER_OPTIMIZATION_PERF)


##### CONFIG_MBEDTLS_FS_IO

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_THREADING_C

Found in: Component config > mbedTLS > Core Configuration

- No (disabled)


##### CONFIG_MBEDTLS_THREADING_ALT

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_THREADING_C

- Yes (enabled) if CONFIG_MBEDTLS_THREADING_C

Yes (enabled) if CONFIG_MBEDTLS_THREADING_C


##### CONFIG_MBEDTLS_THREADING_PTHREAD

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_THREADING_C

- No (disabled) if CONFIG_MBEDTLS_THREADING_C

No (disabled) if CONFIG_MBEDTLS_THREADING_C


##### CONFIG_MBEDTLS_ERROR_STRINGS

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_ERROR_STRERROR_DUMMY

Found in: Component config > mbedTLS > Core Configuration


##### CONFIG_MBEDTLS_VERSION_C

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_HAVE_TIME

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_PLATFORM_TIME_ALT

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_HAVE_TIME

- No (disabled)


##### CONFIG_MBEDTLS_HAVE_TIME_DATE

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_HAVE_TIME

- No (disabled)


##### CONFIG_MBEDTLS_MEM_ALLOC_MODE

Found in: Component config > mbedTLS > Core Configuration

- Internal DRAM memory only
- External SPIRAM memory only
- Either internal or external memory based on default malloc() behavior in ESP-IDF
- Custom allocation mode, by overwriting calloc()/free()using mbedtls_platform_set_calloc_free() function
- Internal IRAM memory wherever applicable else internal DRAM

Available options:

- Internal memory (CONFIG_MBEDTLS_INTERNAL_MEM_ALLOC)
- External SPIRAM (CONFIG_MBEDTLS_EXTERNAL_MEM_ALLOC)
- Default alloc mode (CONFIG_MBEDTLS_DEFAULT_MEM_ALLOC)
- Custom alloc mode (CONFIG_MBEDTLS_CUSTOM_MEM_ALLOC)
- Internal IRAM (CONFIG_MBEDTLS_IRAM_8BIT_MEM_ALLOC) Allows to use IRAM memory region as 8bit accessible region. TLS input and output buffers will be allocated in IRAM section which is 32bit aligned memory. Every unaligned (8bit or 16bit) access will result in an exception and incur penalty of certain clock cycles per unaligned read/write.

Internal memory (CONFIG_MBEDTLS_INTERNAL_MEM_ALLOC)

External SPIRAM (CONFIG_MBEDTLS_EXTERNAL_MEM_ALLOC)

Default alloc mode (CONFIG_MBEDTLS_DEFAULT_MEM_ALLOC)

Custom alloc mode (CONFIG_MBEDTLS_CUSTOM_MEM_ALLOC)

Internal IRAM (CONFIG_MBEDTLS_IRAM_8BIT_MEM_ALLOC)


##### CONFIG_MBEDTLS_SSL_MAX_CONTENT_LEN

Found in: Component config > mbedTLS > Core Configuration


##### CONFIG_MBEDTLS_ASYMMETRIC_CONTENT_LEN

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_IN_CONTENT_LEN

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_ASYMMETRIC_CONTENT_LEN

- from 512 to 16384

- 16384


##### CONFIG_MBEDTLS_SSL_OUT_CONTENT_LEN

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_ASYMMETRIC_CONTENT_LEN

- from 512 to 16384

- 4096


##### CONFIG_MBEDTLS_DYNAMIC_BUFFER

Found in: Component config > mbedTLS > Core Configuration


##### CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_DYNAMIC_BUFFER

- No (disabled) if CONFIG_MBEDTLS_DYNAMIC_BUFFER

No (disabled) if CONFIG_MBEDTLS_DYNAMIC_BUFFER


##### CONFIG_MBEDTLS_DYNAMIC_FREE_CA_CERT

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_DYNAMIC_BUFFER > CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA

- Yes (enabled) if CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA

Yes (enabled) if CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA


##### CONFIG_MBEDTLS_VERSION_FEATURES

Found in: Component config > mbedTLS > Core Configuration

- No (disabled)


##### CONFIG_MBEDTLS_DEBUG

Found in: Component config > mbedTLS > Core Configuration

- No (disabled)


##### CONFIG_MBEDTLS_DEBUG_LEVEL

Found in: Component config > mbedTLS > Core Configuration > CONFIG_MBEDTLS_DEBUG

Available options:

- Warning (CONFIG_MBEDTLS_DEBUG_LEVEL_WARN)
- Info (CONFIG_MBEDTLS_DEBUG_LEVEL_INFO)
- Debug (CONFIG_MBEDTLS_DEBUG_LEVEL_DEBUG)
- Verbose (CONFIG_MBEDTLS_DEBUG_LEVEL_VERBOSE)

Warning (CONFIG_MBEDTLS_DEBUG_LEVEL_WARN)

Info (CONFIG_MBEDTLS_DEBUG_LEVEL_INFO)

Debug (CONFIG_MBEDTLS_DEBUG_LEVEL_DEBUG)

Verbose (CONFIG_MBEDTLS_DEBUG_LEVEL_VERBOSE)


##### CONFIG_MBEDTLS_SELF_TEST

Found in: Component config > mbedTLS > Core Configuration

- Yes (enabled)


#### Certificates

- CONFIG_MBEDTLS_ALLOW_WEAK_CERTIFICATE_VERIFICATION
- CONFIG_MBEDTLS_ASN1_PARSE_C
- CONFIG_MBEDTLS_ASN1_WRITE_C
- CONFIG_MBEDTLS_PK_C
- CONFIG_MBEDTLS_OID_C
- CONFIG_MBEDTLS_X509_TRUSTED_CERT_CALLBACK
- CONFIG_MBEDTLS_CERTIFICATE_BUNDLE
- CONFIG_MBEDTLS_X509_CRT_PARSE_C
- CONFIG_MBEDTLS_X509_USE_C
- CONFIG_MBEDTLS_PEM_PARSE_C
- CONFIG_MBEDTLS_X509_REMOVE_INFO
- CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_CROSS_SIGNED_VERIFY
- CONFIG_MBEDTLS_PEM_WRITE_C
- CONFIG_MBEDTLS_X509_CREATE_C
- CONFIG_MBEDTLS_X509_CRL_PARSE_C
- CONFIG_MBEDTLS_X509_CSR_PARSE_C
- CONFIG_MBEDTLS_X509_RSASSA_PSS_SUPPORT

CONFIG_MBEDTLS_ALLOW_WEAK_CERTIFICATE_VERIFICATION

CONFIG_MBEDTLS_ASN1_PARSE_C

CONFIG_MBEDTLS_ASN1_WRITE_C

CONFIG_MBEDTLS_PK_C

CONFIG_MBEDTLS_OID_C

CONFIG_MBEDTLS_X509_TRUSTED_CERT_CALLBACK

CONFIG_MBEDTLS_CERTIFICATE_BUNDLE

CONFIG_MBEDTLS_X509_CRT_PARSE_C

CONFIG_MBEDTLS_X509_USE_C

CONFIG_MBEDTLS_PEM_PARSE_C

CONFIG_MBEDTLS_X509_REMOVE_INFO

CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_CROSS_SIGNED_VERIFY

CONFIG_MBEDTLS_PEM_WRITE_C

CONFIG_MBEDTLS_X509_CREATE_C

CONFIG_MBEDTLS_X509_CRL_PARSE_C

CONFIG_MBEDTLS_X509_CSR_PARSE_C

CONFIG_MBEDTLS_X509_RSASSA_PSS_SUPPORT


##### CONFIG_MBEDTLS_X509_USE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_PEM_PARSE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_PEM_WRITE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_PK_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_PK_PARSE_C

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_PK_C

- Yes (enabled)


##### CONFIG_MBEDTLS_PK_WRITE_C

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_PK_C

- Yes (enabled)


##### CONFIG_MBEDTLS_X509_REMOVE_INFO

Found in: Component config > mbedTLS > Certificates

- No (disabled)


##### CONFIG_MBEDTLS_X509_CRL_PARSE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_X509_CRT_PARSE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_X509_CSR_PARSE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_X509_CREATE_C

Found in: Component config > mbedTLS > Certificates

- No (disabled)


##### CONFIG_MBEDTLS_X509_CRT_WRITE_C

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_X509_CREATE_C

- Yes (enabled) if CONFIG_MBEDTLS_X509_CREATE_C

Yes (enabled) if CONFIG_MBEDTLS_X509_CREATE_C


##### CONFIG_MBEDTLS_X509_CSR_WRITE_C

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_X509_CREATE_C

- Yes (enabled) if CONFIG_MBEDTLS_X509_CREATE_C

Yes (enabled) if CONFIG_MBEDTLS_X509_CREATE_C


##### CONFIG_MBEDTLS_X509_RSASSA_PSS_SUPPORT

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_X509_TRUSTED_CERT_CALLBACK

Found in: Component config > mbedTLS > Certificates

- No (disabled)


##### CONFIG_MBEDTLS_ASN1_PARSE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_ASN1_WRITE_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_OID_C

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### CONFIG_MBEDTLS_CERTIFICATE_BUNDLE

Found in: Component config > mbedTLS > Certificates

- Yes (enabled)


##### Certificate Bundle Configuration

- CONFIG_MBEDTLS_CUSTOM_CERTIFICATE_BUNDLE
- CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEPRECATED_LIST
- CONFIG_MBEDTLS_DEFAULT_CERTIFICATE_BUNDLE
- CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_MAX_CERTS

CONFIG_MBEDTLS_CUSTOM_CERTIFICATE_BUNDLE

CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEPRECATED_LIST

CONFIG_MBEDTLS_DEFAULT_CERTIFICATE_BUNDLE

CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_MAX_CERTS


##### CONFIG_MBEDTLS_DEFAULT_CERTIFICATE_BUNDLE

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_CERTIFICATE_BUNDLE > Certificate Bundle Configuration

Available options:

- Use the full default certificate bundle (CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_FULL)
- Use only the most common certificates from the default bundles (CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_CMN) Use only the most common certificates from the default bundles, reducing the size with 50%, while still having around 99% coverage.
- Do not use the default certificate bundle (CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_NONE)

Use the full default certificate bundle (CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_FULL)

Do not use the default certificate bundle (CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_NONE)


##### CONFIG_MBEDTLS_CUSTOM_CERTIFICATE_BUNDLE

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_CERTIFICATE_BUNDLE > Certificate Bundle Configuration

- No (disabled)


##### CONFIG_MBEDTLS_CUSTOM_CERTIFICATE_BUNDLE_PATH

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_CERTIFICATE_BUNDLE > Certificate Bundle Configuration > CONFIG_MBEDTLS_CUSTOM_CERTIFICATE_BUNDLE


##### CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEPRECATED_LIST

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_CERTIFICATE_BUNDLE > Certificate Bundle Configuration


##### CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_MAX_CERTS

Found in: Component config > mbedTLS > Certificates > CONFIG_MBEDTLS_CERTIFICATE_BUNDLE > Certificate Bundle Configuration

- 200


##### CONFIG_MBEDTLS_ALLOW_WEAK_CERTIFICATE_VERIFICATION

Found in: Component config > mbedTLS > Certificates

- No (disabled)


##### CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_CROSS_SIGNED_VERIFY

Found in: Component config > mbedTLS > Certificates

- No (disabled)


#### CONFIG_MBEDTLS_TLS_ENABLED

Found in: Component config > mbedTLS

- Yes (enabled)


##### TLS Protocol Configuration

- CONFIG_MBEDTLS_SSL_ALL_ALERT_MESSAGES
- CONFIG_MBEDTLS_SSL_KEYING_MATERIAL_EXPORT
- CONFIG_MBEDTLS_SSL_CONTEXT_SERIALIZATION
- CONFIG_MBEDTLS_SSL_SERVER_NAME_INDICATION
- CONFIG_MBEDTLS_SSL_CACHE_C
- CONFIG_MBEDTLS_SSL_RECORD_SIZE_LIMIT
- CONFIG_MBEDTLS_SSL_MAX_FRAGMENT_LENGTH
- CONFIG_MBEDTLS_SSL_KEEP_PEER_CERTIFICATE
- CONFIG_MBEDTLS_SSL_CID_PADDING_GRANULARITY
- CONFIG_MBEDTLS_SSL_ALPN
- CONFIG_MBEDTLS_SSL_PROTO_GMTSSL1_1
- CONFIG_MBEDTLS_SSL_PROTO_TLS1_2
- CONFIG_MBEDTLS_SSL_PROTO_TLS1_3
- CONFIG_MBEDTLS_SSL_RENEGOTIATION
- TLS Key Exchange Configuration
- CONFIG_MBEDTLS_TLS_MODE
- CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS
- CONFIG_MBEDTLS_SERVER_SSL_SESSION_TICKETS
- CONFIG_MBEDTLS_SSL_VARIABLE_BUFFER_LENGTH

CONFIG_MBEDTLS_SSL_ALL_ALERT_MESSAGES

CONFIG_MBEDTLS_SSL_KEYING_MATERIAL_EXPORT

CONFIG_MBEDTLS_SSL_CONTEXT_SERIALIZATION

CONFIG_MBEDTLS_SSL_SERVER_NAME_INDICATION

CONFIG_MBEDTLS_SSL_CACHE_C

CONFIG_MBEDTLS_SSL_RECORD_SIZE_LIMIT

CONFIG_MBEDTLS_SSL_MAX_FRAGMENT_LENGTH

CONFIG_MBEDTLS_SSL_KEEP_PEER_CERTIFICATE

CONFIG_MBEDTLS_SSL_CID_PADDING_GRANULARITY

CONFIG_MBEDTLS_SSL_ALPN

CONFIG_MBEDTLS_SSL_PROTO_GMTSSL1_1

CONFIG_MBEDTLS_SSL_PROTO_TLS1_2

CONFIG_MBEDTLS_SSL_PROTO_TLS1_3

CONFIG_MBEDTLS_SSL_RENEGOTIATION

CONFIG_MBEDTLS_TLS_MODE

CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS

CONFIG_MBEDTLS_SERVER_SSL_SESSION_TICKETS

CONFIG_MBEDTLS_SSL_VARIABLE_BUFFER_LENGTH


##### CONFIG_MBEDTLS_SSL_PROTO_TLS1_2

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_PROTO_TLS1_3

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled)


##### TLS 1.3 Configuration

- CONFIG_MBEDTLS_SSL_EARLY_DATA
- CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_EPHEMERAL
- CONFIG_MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE
- CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK_EPHEMERAL
- CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK

CONFIG_MBEDTLS_SSL_EARLY_DATA

CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_EPHEMERAL

CONFIG_MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE

CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK_EPHEMERAL

CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK


##### CONFIG_MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 > TLS 1.3 Configuration

- Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 > TLS 1.3 Configuration

- Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_EPHEMERAL

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 > TLS 1.3 Configuration

- Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK_EPHEMERAL

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 > TLS 1.3 Configuration

- Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_EARLY_DATA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 > TLS 1.3 Configuration

- No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS && (CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK || MBEDTLS_SSL_TLS1_3_KEXM_EPHEMER) && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED

No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS && (CONFIG_MBEDTLS_SSL_TLS1_3_KEXM_PSK || MBEDTLS_SSL_TLS1_3_KEXM_EPHEMER) && CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_PROTO_GMTSSL1_1

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled)


##### CONFIG_MBEDTLS_TLS_MODE

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

Available options:

- Server & Client (CONFIG_MBEDTLS_TLS_SERVER_AND_CLIENT)
- Server (CONFIG_MBEDTLS_TLS_SERVER_ONLY)
- Client (CONFIG_MBEDTLS_TLS_CLIENT_ONLY)
- None (CONFIG_MBEDTLS_TLS_DISABLED)

Server & Client (CONFIG_MBEDTLS_TLS_SERVER_AND_CLIENT)

Server (CONFIG_MBEDTLS_TLS_SERVER_ONLY)

Client (CONFIG_MBEDTLS_TLS_CLIENT_ONLY)

None (CONFIG_MBEDTLS_TLS_DISABLED)


##### CONFIG_MBEDTLS_SSL_CID_PADDING_GRANULARITY

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- from 0 to 32 if (CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 || CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID) && CONFIG_MBEDTLS_TLS_ENABLED

from 0 to 32 if (CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 || CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID) && CONFIG_MBEDTLS_TLS_ENABLED

- 16 if (CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 || CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID) && CONFIG_MBEDTLS_TLS_ENABLED

16 if (CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 || CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID) && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_KEEP_PEER_CERTIFICATE

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled)


##### CONFIG_MBEDTLS_SSL_CONTEXT_SERIALIZATION

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled)


##### CONFIG_MBEDTLS_SSL_CACHE_C

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_ALL_ALERT_MESSAGES

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### TLS Key Exchange Configuration

- CONFIG_MBEDTLS_KEY_EXCHANGE_DHE_RSA
- CONFIG_MBEDTLS_KEY_EXCHANGE_ECJPAKE
- CONFIG_MBEDTLS_PSK_MODES
- CONFIG_MBEDTLS_KEY_EXCHANGE_RSA
- CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE

CONFIG_MBEDTLS_KEY_EXCHANGE_DHE_RSA

CONFIG_MBEDTLS_KEY_EXCHANGE_ECJPAKE

CONFIG_MBEDTLS_PSK_MODES

CONFIG_MBEDTLS_KEY_EXCHANGE_RSA

CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE


##### CONFIG_MBEDTLS_PSK_MODES

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration

- No (disabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_PSK

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_PSK_MODES

- No (disabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED

No (disabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_KEY_EXCHANGE_DHE_PSK

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_PSK_MODES

- Yes (enabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_DHM_C && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_DHM_C && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ECDHE_PSK

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_PSK_MODES

- Yes (enabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_ECDH_C && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_ECDH_C && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_KEY_EXCHANGE_RSA_PSK

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_PSK_MODES

- Yes (enabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED

Yes (enabled) if CONFIG_MBEDTLS_PSK_MODES && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_KEY_EXCHANGE_RSA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_DHE_RSA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ECDHE_RSA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ECDH_RSA

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration > CONFIG_MBEDTLS_KEY_EXCHANGE_ELLIPTIC_CURVE

- Yes (enabled)


##### CONFIG_MBEDTLS_KEY_EXCHANGE_ECJPAKE

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration > TLS Key Exchange Configuration

- No (disabled) if CONFIG_MBEDTLS_ECJPAKE_C && CONFIG_MBEDTLS_ECP_DP_SECP256R1_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED

No (disabled) if CONFIG_MBEDTLS_ECJPAKE_C && CONFIG_MBEDTLS_ECP_DP_SECP256R1_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_SERVER_NAME_INDICATION

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_ALPN

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_MAX_FRAGMENT_LENGTH

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_RECORD_SIZE_LIMIT

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED

No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_TLS1_3 && CONFIG_MBEDTLS_TLS_ENABLED


##### CONFIG_MBEDTLS_SSL_VARIABLE_BUFFER_LENGTH

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled)


##### CONFIG_MBEDTLS_SSL_RENEGOTIATION

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SERVER_SSL_SESSION_TICKETS

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_SSL_KEYING_MATERIAL_EXPORT

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_TLS_ENABLED > TLS Protocol Configuration

- No (disabled)


#### CONFIG_MBEDTLS_SSL_PROTO_DTLS

Found in: Component config > mbedTLS

- No (disabled)


##### DTLS-based configurations

- CONFIG_MBEDTLS_SSL_COOKIE_C
- CONFIG_MBEDTLS_SSL_DTLS_SRTP
- CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID

CONFIG_MBEDTLS_SSL_COOKIE_C

CONFIG_MBEDTLS_SSL_DTLS_SRTP

CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID


##### CONFIG_MBEDTLS_SSL_COOKIE_C

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_SSL_PROTO_DTLS > DTLS-based configurations

- Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_DTLS

Yes (enabled) if CONFIG_MBEDTLS_SSL_PROTO_DTLS


##### CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_SSL_PROTO_DTLS > DTLS-based configurations

- No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_DTLS

No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_DTLS


##### CONFIG_MBEDTLS_SSL_CID_IN_LEN_MAX

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_SSL_PROTO_DTLS > DTLS-based configurations > CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID

- from 0 to 32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS

from 0 to 32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS

- 32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS

32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS


##### CONFIG_MBEDTLS_SSL_CID_OUT_LEN_MAX

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_SSL_PROTO_DTLS > DTLS-based configurations > CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID

- from 0 to 32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS

from 0 to 32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS

- 32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS

32 if CONFIG_MBEDTLS_SSL_DTLS_CONNECTION_ID && CONFIG_MBEDTLS_SSL_PROTO_DTLS


##### CONFIG_MBEDTLS_SSL_DTLS_SRTP

Found in: Component config > mbedTLS > CONFIG_MBEDTLS_SSL_PROTO_DTLS > DTLS-based configurations

- No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_DTLS

No (disabled) if CONFIG_MBEDTLS_SSL_PROTO_DTLS


#### CONFIG_MBEDTLS_CIPHER_C

Found in: Component config > mbedTLS

- Yes (enabled)


#### Symmetric Ciphers

- CONFIG_MBEDTLS_AES_C
- CONFIG_MBEDTLS_ARIA_C
- CONFIG_MBEDTLS_BLOWFISH_C
- CONFIG_MBEDTLS_CAMELLIA_C
- CONFIG_MBEDTLS_CIPHER_MODE_CBC
- CONFIG_MBEDTLS_CCM_C
- CONFIG_MBEDTLS_CIPHER_MODE_CFB
- CONFIG_MBEDTLS_CIPHER_PADDING
- CONFIG_MBEDTLS_CIPHER_MODE_CTR
- CONFIG_MBEDTLS_DES_C
- CONFIG_MBEDTLS_CMAC_C
- CONFIG_MBEDTLS_GCM_C
- CONFIG_MBEDTLS_NIST_KW_C
- CONFIG_MBEDTLS_CIPHER_MODE_OFB
- CONFIG_MBEDTLS_AES_ONLY_128_BIT_KEY_LENGTH
- CONFIG_MBEDTLS_AES_ROM_TABLES
- CONFIG_MBEDTLS_AES_FEWER_TABLES
- CONFIG_MBEDTLS_CAMELLIA_SMALL_MEMORY
- CONFIG_MBEDTLS_XTEA_C
- CONFIG_MBEDTLS_CIPHER_MODE_XTS

CONFIG_MBEDTLS_AES_C

CONFIG_MBEDTLS_ARIA_C

CONFIG_MBEDTLS_BLOWFISH_C

CONFIG_MBEDTLS_CAMELLIA_C

CONFIG_MBEDTLS_CIPHER_MODE_CBC

CONFIG_MBEDTLS_CCM_C

CONFIG_MBEDTLS_CIPHER_MODE_CFB

CONFIG_MBEDTLS_CIPHER_PADDING

CONFIG_MBEDTLS_CIPHER_MODE_CTR

CONFIG_MBEDTLS_DES_C

CONFIG_MBEDTLS_CMAC_C

CONFIG_MBEDTLS_GCM_C

CONFIG_MBEDTLS_NIST_KW_C

CONFIG_MBEDTLS_CIPHER_MODE_OFB

CONFIG_MBEDTLS_AES_ONLY_128_BIT_KEY_LENGTH

CONFIG_MBEDTLS_AES_ROM_TABLES

CONFIG_MBEDTLS_AES_FEWER_TABLES

CONFIG_MBEDTLS_CAMELLIA_SMALL_MEMORY

CONFIG_MBEDTLS_XTEA_C

CONFIG_MBEDTLS_CIPHER_MODE_XTS


##### CONFIG_MBEDTLS_AES_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CAMELLIA_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_ARIA_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CAMELLIA_SMALL_MEMORY

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled) if CONFIG_MBEDTLS_CAMELLIA_C

No (disabled) if CONFIG_MBEDTLS_CAMELLIA_C


##### CONFIG_MBEDTLS_DES_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_BLOWFISH_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_XTEA_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_CCM_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_MODE_CBC

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_MODE_CFB

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_MODE_CTR

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_MODE_OFB

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_MODE_XTS

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_GCM_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_NIST_KW_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_CIPHER_PADDING

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_PADDING_PKCS7

Found in: Component config > mbedTLS > Symmetric Ciphers > CONFIG_MBEDTLS_CIPHER_PADDING

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS

Found in: Component config > mbedTLS > Symmetric Ciphers > CONFIG_MBEDTLS_CIPHER_PADDING

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN

Found in: Component config > mbedTLS > Symmetric Ciphers > CONFIG_MBEDTLS_CIPHER_PADDING

- Yes (enabled)


##### CONFIG_MBEDTLS_CIPHER_PADDING_ZEROS

Found in: Component config > mbedTLS > Symmetric Ciphers > CONFIG_MBEDTLS_CIPHER_PADDING

- Yes (enabled)


##### CONFIG_MBEDTLS_AES_ROM_TABLES

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_AES_FEWER_TABLES

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_AES_ONLY_128_BIT_KEY_LENGTH

Found in: Component config > mbedTLS > Symmetric Ciphers

- No (disabled)


##### CONFIG_MBEDTLS_CMAC_C

Found in: Component config > mbedTLS > Symmetric Ciphers

- Yes (enabled)


#### Asymmetric Ciphers

- Elliptic Curve Ciphers Configuration
- CONFIG_MBEDTLS_ECP_C
- CONFIG_MBEDTLS_BIGNUM_C
- CONFIG_MBEDTLS_RSA_C
- Supported Curves

CONFIG_MBEDTLS_ECP_C

CONFIG_MBEDTLS_BIGNUM_C

CONFIG_MBEDTLS_RSA_C


##### CONFIG_MBEDTLS_BIGNUM_C

Found in: Component config > mbedTLS > Asymmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_GENPRIME

Found in: Component config > mbedTLS > Asymmetric Ciphers > CONFIG_MBEDTLS_BIGNUM_C

- Yes (enabled)


##### CONFIG_MBEDTLS_RSA_C

Found in: Component config > mbedTLS > Asymmetric Ciphers

- Yes (enabled)


##### CONFIG_MBEDTLS_ECP_C

Found in: Component config > mbedTLS > Asymmetric Ciphers

- Yes (enabled)


##### Supported Curves

- CONFIG_MBEDTLS_ECP_DP_BP256R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_BP384R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_BP512R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_CURVE25519_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP192K1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP192R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP224K1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP224R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP256K1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP256R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP384R1_ENABLED
- CONFIG_MBEDTLS_ECP_DP_SECP521R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_BP256R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_BP384R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_BP512R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_CURVE25519_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP192K1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP192R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP224K1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP224R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP256K1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP256R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP384R1_ENABLED

CONFIG_MBEDTLS_ECP_DP_SECP521R1_ENABLED


##### CONFIG_MBEDTLS_ECP_DP_SECP192R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_SECP224R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_SECP256R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves

- Yes (enabled)


##### CONFIG_MBEDTLS_ECP_DP_SECP384R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_SECP521R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_SECP192K1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_SECP224K1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_SECP256K1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_BP256R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_BP384R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_BP512R1_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### CONFIG_MBEDTLS_ECP_DP_CURVE25519_ENABLED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Supported Curves


##### Elliptic Curve Ciphers Configuration

- CONFIG_MBEDTLS_DHM_C
- CONFIG_MBEDTLS_ECDH_C
- CONFIG_MBEDTLS_ECDSA_C
- CONFIG_MBEDTLS_ECJPAKE_C
- CONFIG_MBEDTLS_ECDSA_DETERMINISTIC
- CONFIG_MBEDTLS_ECP_FIXED_POINT_OPTIM
- CONFIG_MBEDTLS_ECP_RESTARTABLE
- CONFIG_MBEDTLS_PK_PARSE_EC_COMPRESSED
- CONFIG_MBEDTLS_PK_PARSE_EC_EXTENDED
- CONFIG_MBEDTLS_ECP_NIST_OPTIM
- CONFIG_MBEDTLS_ECDH_LEGACY_CONTEXT

CONFIG_MBEDTLS_DHM_C

CONFIG_MBEDTLS_ECDH_C

CONFIG_MBEDTLS_ECDSA_C

CONFIG_MBEDTLS_ECJPAKE_C

CONFIG_MBEDTLS_ECDSA_DETERMINISTIC

CONFIG_MBEDTLS_ECP_FIXED_POINT_OPTIM

CONFIG_MBEDTLS_ECP_RESTARTABLE

CONFIG_MBEDTLS_PK_PARSE_EC_COMPRESSED

CONFIG_MBEDTLS_PK_PARSE_EC_EXTENDED

CONFIG_MBEDTLS_ECP_NIST_OPTIM

CONFIG_MBEDTLS_ECDH_LEGACY_CONTEXT


##### CONFIG_MBEDTLS_ECP_NIST_OPTIM

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_ECP_FIXED_POINT_OPTIM

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- No (disabled)


##### CONFIG_MBEDTLS_ECDH_LEGACY_CONTEXT

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- No (disabled) if CONFIG_MBEDTLS_ECDH_C && CONFIG_MBEDTLS_ECP_RESTARTABLE && CONFIG_MBEDTLS_ECP_C

No (disabled) if CONFIG_MBEDTLS_ECDH_C && CONFIG_MBEDTLS_ECP_RESTARTABLE && CONFIG_MBEDTLS_ECP_C


##### CONFIG_MBEDTLS_DHM_C

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_ECDH_C

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_ECJPAKE_C

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- No (disabled)


##### CONFIG_MBEDTLS_ECDSA_C

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_PK_PARSE_EC_EXTENDED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_PK_PARSE_EC_COMPRESSED

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_ECDSA_DETERMINISTIC

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- Yes (enabled)


##### CONFIG_MBEDTLS_ECP_RESTARTABLE

Found in: Component config > mbedTLS > Asymmetric Ciphers > Elliptic Curve Ciphers Configuration

- No (disabled)


#### Hash functions

- CONFIG_MBEDTLS_MD_C
- CONFIG_MBEDTLS_RIPEMD160_C
- CONFIG_MBEDTLS_SHA256_SMALLER
- CONFIG_MBEDTLS_SHA512_SMALLER
- CONFIG_MBEDTLS_MD5_C
- CONFIG_MBEDTLS_SHA1_C
- CONFIG_MBEDTLS_SHA224_C
- CONFIG_MBEDTLS_SHA256_C
- CONFIG_MBEDTLS_SHA512_C
- CONFIG_MBEDTLS_SHA384_C
- CONFIG_MBEDTLS_SHA3_C
- CONFIG_MBEDTLS_HKDF_C
- CONFIG_MBEDTLS_POLY1305_C
- CONFIG_MBEDTLS_ROM_MD5

CONFIG_MBEDTLS_MD_C

CONFIG_MBEDTLS_RIPEMD160_C

CONFIG_MBEDTLS_SHA256_SMALLER

CONFIG_MBEDTLS_SHA512_SMALLER

CONFIG_MBEDTLS_MD5_C

CONFIG_MBEDTLS_SHA1_C

CONFIG_MBEDTLS_SHA224_C

CONFIG_MBEDTLS_SHA256_C

CONFIG_MBEDTLS_SHA512_C

CONFIG_MBEDTLS_SHA384_C

CONFIG_MBEDTLS_SHA3_C

CONFIG_MBEDTLS_HKDF_C

CONFIG_MBEDTLS_POLY1305_C

CONFIG_MBEDTLS_ROM_MD5


##### CONFIG_MBEDTLS_HKDF_C

Found in: Component config > mbedTLS > Hash functions

- No (disabled)


##### CONFIG_MBEDTLS_POLY1305_C

Found in: Component config > mbedTLS > Hash functions

- No (disabled)


##### CONFIG_MBEDTLS_RIPEMD160_C

Found in: Component config > mbedTLS > Hash functions

- No (disabled)


##### CONFIG_MBEDTLS_MD_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_MD5_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_SHA1_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_SHA224_C

Found in: Component config > mbedTLS > Hash functions

- No (disabled)


##### CONFIG_MBEDTLS_SHA256_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_SHA384_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_SHA512_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_SHA3_C

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_ROM_MD5

Found in: Component config > mbedTLS > Hash functions

- Yes (enabled)


##### CONFIG_MBEDTLS_SHA256_SMALLER

Found in: Component config > mbedTLS > Hash functions


##### CONFIG_MBEDTLS_SHA512_SMALLER

Found in: Component config > mbedTLS > Hash functions


#### Hardware Acceleration

- CONFIG_MBEDTLS_HARDWARE_ECDSA_VERIFY
- CONFIG_MBEDTLS_HARDWARE_ECDSA_SIGN
- CONFIG_MBEDTLS_TEE_SEC_STG_ECDSA_SIGN
- CONFIG_MBEDTLS_HARDWARE_AES
- CONFIG_MBEDTLS_HARDWARE_ECC
- CONFIG_MBEDTLS_ATCA_HW_ECDSA_SIGN
- CONFIG_MBEDTLS_ATCA_HW_ECDSA_VERIFY
- CONFIG_MBEDTLS_HARDWARE_MPI
- CONFIG_MBEDTLS_HARDWARE_SHA
- CONFIG_MBEDTLS_AES_HW_SMALL_DATA_LEN_OPTIM
- CONFIG_MBEDTLS_PK_RSA_ALT_SUPPORT
- Enable Software Countermeasure for ECDSA signing using on-chip ECDSA peripheral

CONFIG_MBEDTLS_HARDWARE_ECDSA_VERIFY

CONFIG_MBEDTLS_HARDWARE_ECDSA_SIGN

CONFIG_MBEDTLS_TEE_SEC_STG_ECDSA_SIGN

CONFIG_MBEDTLS_HARDWARE_AES

CONFIG_MBEDTLS_HARDWARE_ECC

CONFIG_MBEDTLS_ATCA_HW_ECDSA_SIGN

CONFIG_MBEDTLS_ATCA_HW_ECDSA_VERIFY

CONFIG_MBEDTLS_HARDWARE_MPI

CONFIG_MBEDTLS_HARDWARE_SHA

CONFIG_MBEDTLS_AES_HW_SMALL_DATA_LEN_OPTIM

CONFIG_MBEDTLS_PK_RSA_ALT_SUPPORT


##### CONFIG_MBEDTLS_HARDWARE_ECDSA_VERIFY

Found in: Component config > mbedTLS > Hardware Acceleration


##### Enable Software Countermeasure for ECDSA signing using on-chip ECDSA peripheral


##### CONFIG_MBEDTLS_HARDWARE_ECDSA_SIGN

Found in: Component config > mbedTLS > Hardware Acceleration


##### CONFIG_MBEDTLS_TEE_SEC_STG_ECDSA_SIGN

Found in: Component config > mbedTLS > Hardware Acceleration

- Yes (enabled) if SECURE_ENABLE_TEE


##### CONFIG_MBEDTLS_HARDWARE_ECC

Found in: Component config > mbedTLS > Hardware Acceleration

- Yes (enabled)


##### CONFIG_MBEDTLS_ECC_OTHER_CURVES_SOFT_FALLBACK

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_ECC

- Yes (enabled)


##### CONFIG_MBEDTLS_HARDWARE_SHA

Found in: Component config > mbedTLS > Hardware Acceleration


##### CONFIG_MBEDTLS_HARDWARE_MPI

Found in: Component config > mbedTLS > Hardware Acceleration


##### CONFIG_MBEDTLS_LARGE_KEY_SOFTWARE_MPI

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_MPI

- No (disabled)


##### CONFIG_MBEDTLS_MPI_USE_INTERRUPT

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_MPI

- Yes (enabled)


##### CONFIG_MBEDTLS_MPI_INTERRUPT_LEVEL

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_MPI > CONFIG_MBEDTLS_MPI_USE_INTERRUPT

- from 0 to 3

- 0


##### CONFIG_MBEDTLS_HARDWARE_AES

Found in: Component config > mbedTLS > Hardware Acceleration


##### CONFIG_MBEDTLS_HARDWARE_GCM

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_AES

- Yes (enabled)


##### CONFIG_MBEDTLS_GCM_SUPPORT_NON_AES_CIPHER

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_AES

- Yes (enabled)


##### CONFIG_MBEDTLS_AES_USE_INTERRUPT

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_AES

- Yes (enabled)


##### CONFIG_MBEDTLS_AES_INTERRUPT_LEVEL

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_AES > CONFIG_MBEDTLS_AES_USE_INTERRUPT

- from 0 to 3

- 0


##### CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_AES

- No (disabled)


##### CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH

Found in: Component config > mbedTLS > Hardware Acceleration > CONFIG_MBEDTLS_HARDWARE_AES > CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC

Available options:

- Low (CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH_LOW)
- Medium (CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH_MEDIUM)
- High (CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH_HIGH)

Low (CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH_LOW)

Medium (CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH_MEDIUM)

High (CONFIG_MBEDTLS_AES_USE_PSEUDO_ROUND_FUNC_STRENGTH_HIGH)


##### CONFIG_MBEDTLS_AES_HW_SMALL_DATA_LEN_OPTIM

Found in: Component config > mbedTLS > Hardware Acceleration

- Yes (enabled)


##### CONFIG_MBEDTLS_PK_RSA_ALT_SUPPORT

Found in: Component config > mbedTLS > Hardware Acceleration

- Yes (enabled)


##### CONFIG_MBEDTLS_ATCA_HW_ECDSA_SIGN

Found in: Component config > mbedTLS > Hardware Acceleration

- No (disabled)


##### CONFIG_MBEDTLS_ATCA_HW_ECDSA_VERIFY

Found in: Component config > mbedTLS > Hardware Acceleration

- No (disabled)


#### Entropy and Random Number Generation

- CONFIG_MBEDTLS_CTR_DRBG_C
- CONFIG_MBEDTLS_ENTROPY_C
- CONFIG_MBEDTLS_HMAC_DRBG_C
- CONFIG_MBEDTLS_ENTROPY_FORCE_SHA256

CONFIG_MBEDTLS_CTR_DRBG_C

CONFIG_MBEDTLS_ENTROPY_C

CONFIG_MBEDTLS_HMAC_DRBG_C

CONFIG_MBEDTLS_ENTROPY_FORCE_SHA256


##### CONFIG_MBEDTLS_ENTROPY_C

Found in: Component config > mbedTLS > Entropy and Random Number Generation

- Yes (enabled)


##### CONFIG_MBEDTLS_ENTROPY_FORCE_SHA256

Found in: Component config > mbedTLS > Entropy and Random Number Generation

- No (disabled)


##### CONFIG_MBEDTLS_CTR_DRBG_C

Found in: Component config > mbedTLS > Entropy and Random Number Generation

- Yes (enabled)


##### CONFIG_MBEDTLS_HMAC_DRBG_C

Found in: Component config > mbedTLS > Entropy and Random Number Generation

- Yes (enabled)


#### Encoding/Decoding

- CONFIG_MBEDTLS_BASE64_C
- CONFIG_MBEDTLS_PKCS12_C
- CONFIG_MBEDTLS_PKCS7_C
- CONFIG_MBEDTLS_PKCS1_V15
- CONFIG_MBEDTLS_PKCS1_V21
- CONFIG_MBEDTLS_PKCS5_C

CONFIG_MBEDTLS_BASE64_C

CONFIG_MBEDTLS_PKCS12_C

CONFIG_MBEDTLS_PKCS7_C

CONFIG_MBEDTLS_PKCS1_V15

CONFIG_MBEDTLS_PKCS1_V21

CONFIG_MBEDTLS_PKCS5_C


##### CONFIG_MBEDTLS_BASE64_C

Found in: Component config > mbedTLS > Encoding/Decoding

- Yes (enabled)


##### CONFIG_MBEDTLS_PKCS5_C

Found in: Component config > mbedTLS > Encoding/Decoding

- Yes (enabled)


##### CONFIG_MBEDTLS_PKCS7_C

Found in: Component config > mbedTLS > Encoding/Decoding

- Yes (enabled)


##### CONFIG_MBEDTLS_PKCS12_C

Found in: Component config > mbedTLS > Encoding/Decoding

- Yes (enabled)


##### CONFIG_MBEDTLS_PKCS1_V15

Found in: Component config > mbedTLS > Encoding/Decoding

- Yes (enabled)


##### CONFIG_MBEDTLS_PKCS1_V21

Found in: Component config > mbedTLS > Encoding/Decoding

- Yes (enabled)


#### Stream Cipher

- CONFIG_MBEDTLS_CHACHA20_C
- CONFIG_MBEDTLS_CHACHAPOLY_C

CONFIG_MBEDTLS_CHACHA20_C

CONFIG_MBEDTLS_CHACHAPOLY_C


##### CONFIG_MBEDTLS_CHACHAPOLY_C

Found in: Component config > mbedTLS > Stream Cipher

- No (disabled) if CONFIG_MBEDTLS_CHACHA20_C && CONFIG_MBEDTLS_POLY1305_C

No (disabled) if CONFIG_MBEDTLS_CHACHA20_C && CONFIG_MBEDTLS_POLY1305_C


##### CONFIG_MBEDTLS_CHACHA20_C

Found in: Component config > mbedTLS > Stream Cipher

- No (disabled)


#### CONFIG_MBEDTLS_USE_CRYPTO_ROM_IMPL_BOOTLOADER

Found in: Component config > mbedTLS

- No (disabled) if ESP_ROM_HAS_MBEDTLS_CRYPTO_LIB


#### CONFIG_MBEDTLS_USE_CRYPTO_ROM_IMPL

Found in: Component config > mbedTLS

- No (disabled) if ESP_ROM_HAS_MBEDTLS_CRYPTO_LIB


### ESP-MQTT Configurations

- CONFIG_MQTT_CUSTOM_OUTBOX
- CONFIG_MQTT_TRANSPORT_SSL
- CONFIG_MQTT_TRANSPORT_WEBSOCKET
- CONFIG_MQTT_PROTOCOL_311
- CONFIG_MQTT_PROTOCOL_5
- CONFIG_MQTT_TASK_CORE_SELECTION_ENABLED
- CONFIG_MQTT_TOPIC_PRESENT_ALL_DATA_EVENTS
- CONFIG_MQTT_USE_CUSTOM_CONFIG
- CONFIG_MQTT_OUTBOX_EXPIRED_TIMEOUT_MS
- CONFIG_MQTT_REPORT_DELETED_MESSAGES
- CONFIG_MQTT_SKIP_PUBLISH_IF_DISCONNECTED
- CONFIG_MQTT_OUTBOX_DATA_ON_EXTERNAL_MEMORY
- CONFIG_MQTT_MSG_ID_INCREMENTAL

CONFIG_MQTT_CUSTOM_OUTBOX

CONFIG_MQTT_TRANSPORT_SSL

CONFIG_MQTT_TRANSPORT_WEBSOCKET

CONFIG_MQTT_PROTOCOL_311

CONFIG_MQTT_PROTOCOL_5

CONFIG_MQTT_TASK_CORE_SELECTION_ENABLED

CONFIG_MQTT_TOPIC_PRESENT_ALL_DATA_EVENTS

CONFIG_MQTT_USE_CUSTOM_CONFIG

CONFIG_MQTT_OUTBOX_EXPIRED_TIMEOUT_MS

CONFIG_MQTT_REPORT_DELETED_MESSAGES

CONFIG_MQTT_SKIP_PUBLISH_IF_DISCONNECTED

CONFIG_MQTT_OUTBOX_DATA_ON_EXTERNAL_MEMORY

CONFIG_MQTT_MSG_ID_INCREMENTAL


#### CONFIG_MQTT_PROTOCOL_311

Found in: Component config > ESP-MQTT Configurations

- Yes (enabled)


#### CONFIG_MQTT_PROTOCOL_5

Found in: Component config > ESP-MQTT Configurations

- No (disabled)


#### CONFIG_MQTT_TRANSPORT_SSL

Found in: Component config > ESP-MQTT Configurations

- Yes (enabled)


#### CONFIG_MQTT_TRANSPORT_WEBSOCKET

Found in: Component config > ESP-MQTT Configurations

- Yes (enabled)


##### CONFIG_MQTT_TRANSPORT_WEBSOCKET_SECURE

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_TRANSPORT_WEBSOCKET

- Yes (enabled)


#### CONFIG_MQTT_MSG_ID_INCREMENTAL

Found in: Component config > ESP-MQTT Configurations

- No (disabled)


#### CONFIG_MQTT_SKIP_PUBLISH_IF_DISCONNECTED

Found in: Component config > ESP-MQTT Configurations

- No (disabled)


#### CONFIG_MQTT_REPORT_DELETED_MESSAGES

Found in: Component config > ESP-MQTT Configurations

- No (disabled)


#### CONFIG_MQTT_USE_CUSTOM_CONFIG

Found in: Component config > ESP-MQTT Configurations

- No (disabled)


##### CONFIG_MQTT_TCP_DEFAULT_PORT

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 1883 if CONFIG_MQTT_USE_CUSTOM_CONFIG

1883 if CONFIG_MQTT_USE_CUSTOM_CONFIG


##### CONFIG_MQTT_SSL_DEFAULT_PORT

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 8883 if CONFIG_MQTT_USE_CUSTOM_CONFIG && CONFIG_MQTT_TRANSPORT_SSL

8883 if CONFIG_MQTT_USE_CUSTOM_CONFIG && CONFIG_MQTT_TRANSPORT_SSL


##### CONFIG_MQTT_WS_DEFAULT_PORT

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 80 if CONFIG_MQTT_USE_CUSTOM_CONFIG && CONFIG_MQTT_TRANSPORT_WEBSOCKET

80 if CONFIG_MQTT_USE_CUSTOM_CONFIG && CONFIG_MQTT_TRANSPORT_WEBSOCKET


##### CONFIG_MQTT_WSS_DEFAULT_PORT

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 443 if CONFIG_MQTT_USE_CUSTOM_CONFIG && CONFIG_MQTT_TRANSPORT_WEBSOCKET && CONFIG_MQTT_TRANSPORT_WEBSOCKET_SECURE

443 if CONFIG_MQTT_USE_CUSTOM_CONFIG && CONFIG_MQTT_TRANSPORT_WEBSOCKET && CONFIG_MQTT_TRANSPORT_WEBSOCKET_SECURE


##### CONFIG_MQTT_BUFFER_SIZE

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 1024 if CONFIG_MQTT_USE_CUSTOM_CONFIG

1024 if CONFIG_MQTT_USE_CUSTOM_CONFIG


##### CONFIG_MQTT_TASK_STACK_SIZE

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 6144 if CONFIG_MQTT_USE_CUSTOM_CONFIG

6144 if CONFIG_MQTT_USE_CUSTOM_CONFIG


##### CONFIG_MQTT_DISABLE_API_LOCKS

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- No (disabled) if CONFIG_MQTT_USE_CUSTOM_CONFIG

No (disabled) if CONFIG_MQTT_USE_CUSTOM_CONFIG


##### CONFIG_MQTT_TASK_PRIORITY

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 5 if CONFIG_MQTT_USE_CUSTOM_CONFIG

5 if CONFIG_MQTT_USE_CUSTOM_CONFIG


##### CONFIG_MQTT_POLL_READ_TIMEOUT_MS

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 1000 if CONFIG_MQTT_USE_CUSTOM_CONFIG

1000 if CONFIG_MQTT_USE_CUSTOM_CONFIG


##### CONFIG_MQTT_EVENT_QUEUE_SIZE

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_USE_CUSTOM_CONFIG

- 1 if CONFIG_MQTT_USE_CUSTOM_CONFIG

1 if CONFIG_MQTT_USE_CUSTOM_CONFIG


#### CONFIG_MQTT_TASK_CORE_SELECTION_ENABLED

Found in: Component config > ESP-MQTT Configurations


##### CONFIG_MQTT_TASK_CORE_SELECTION

Found in: Component config > ESP-MQTT Configurations > CONFIG_MQTT_TASK_CORE_SELECTION_ENABLED

Available options:

- Core 0 (CONFIG_MQTT_USE_CORE_0)
- Core 1 (CONFIG_MQTT_USE_CORE_1)

Core 0 (CONFIG_MQTT_USE_CORE_0)

Core 1 (CONFIG_MQTT_USE_CORE_1)


#### CONFIG_MQTT_OUTBOX_DATA_ON_EXTERNAL_MEMORY

Found in: Component config > ESP-MQTT Configurations

- No (disabled) if CONFIG_MQTT_USE_CUSTOM_CONFIG

No (disabled) if CONFIG_MQTT_USE_CUSTOM_CONFIG


#### CONFIG_MQTT_CUSTOM_OUTBOX

Found in: Component config > ESP-MQTT Configurations

- No (disabled)


#### CONFIG_MQTT_OUTBOX_EXPIRED_TIMEOUT_MS

Found in: Component config > ESP-MQTT Configurations

- 30000 if CONFIG_MQTT_USE_CUSTOM_CONFIG

30000 if CONFIG_MQTT_USE_CUSTOM_CONFIG


#### CONFIG_MQTT_TOPIC_PRESENT_ALL_DATA_EVENTS

Found in: Component config > ESP-MQTT Configurations

- No (disabled) if CONFIG_MQTT_USE_CUSTOM_CONFIG

No (disabled) if CONFIG_MQTT_USE_CUSTOM_CONFIG


### NVS

- CONFIG_NVS_LEGACY_DUP_KEYS_COMPATIBILITY
- CONFIG_NVS_ENCRYPTION
- CONFIG_NVS_COMPATIBLE_PRE_V4_3_ENCRYPTION_FLAG
- CONFIG_NVS_ALLOCATE_CACHE_IN_SPIRAM
- CONFIG_NVS_ASSERT_ERROR_CHECK

CONFIG_NVS_LEGACY_DUP_KEYS_COMPATIBILITY

CONFIG_NVS_ENCRYPTION

CONFIG_NVS_COMPATIBLE_PRE_V4_3_ENCRYPTION_FLAG

CONFIG_NVS_ALLOCATE_CACHE_IN_SPIRAM

CONFIG_NVS_ASSERT_ERROR_CHECK


#### CONFIG_NVS_ENCRYPTION

Found in: Component config > NVS

- Yes (enabled) if CONFIG_SECURE_FLASH_ENC_ENABLED

Yes (enabled) if CONFIG_SECURE_FLASH_ENC_ENABLED


#### CONFIG_NVS_COMPATIBLE_PRE_V4_3_ENCRYPTION_FLAG

Found in: Component config > NVS


#### CONFIG_NVS_ASSERT_ERROR_CHECK

Found in: Component config > NVS

- No (disabled)


#### CONFIG_NVS_LEGACY_DUP_KEYS_COMPATIBILITY

Found in: Component config > NVS

- No (disabled)


#### CONFIG_NVS_ALLOCATE_CACHE_IN_SPIRAM

Found in: Component config > NVS

- No (disabled) if CONFIG_SPIRAM && (CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC)

No (disabled) if CONFIG_SPIRAM && (CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC)


### NVS Security Provider

- CONFIG_NVS_SEC_HMAC_EFUSE_KEY_ID
- CONFIG_NVS_SEC_KEY_PROTECTION_SCHEME

CONFIG_NVS_SEC_HMAC_EFUSE_KEY_ID

CONFIG_NVS_SEC_KEY_PROTECTION_SCHEME


#### CONFIG_NVS_SEC_KEY_PROTECTION_SCHEME

Found in: Component config > NVS Security Provider

Available options:

- Using Flash Encryption (CONFIG_NVS_SEC_KEY_PROTECT_USING_FLASH_ENC) Protect the NVS Encryption Keys using Flash Encryption Requires a separate 'nvs_keys' partition (which will be encrypted by flash encryption) for storing the NVS encryption keys
- Using HMAC peripheral (CONFIG_NVS_SEC_KEY_PROTECT_USING_HMAC) Derive and protect the NVS Encryption Keys using the HMAC peripheral Requires the specified eFuse block (NVS_SEC_HMAC_EFUSE_KEY_ID or the v2 API argument) to be empty or pre-written with a key with the purpose ESP_EFUSE_KEY_PURPOSE_HMAC_UP
- None (CONFIG_NVS_SEC_KEY_PROTECT_NONE) Select this option if key derivation/protection is handled by a custom implementation, and not by the nvs_sec_provider component.

Using Flash Encryption (CONFIG_NVS_SEC_KEY_PROTECT_USING_FLASH_ENC)

Using HMAC peripheral (CONFIG_NVS_SEC_KEY_PROTECT_USING_HMAC)

None (CONFIG_NVS_SEC_KEY_PROTECT_NONE)


#### CONFIG_NVS_SEC_HMAC_EFUSE_KEY_ID

Found in: Component config > NVS Security Provider

- from -1 to 5 if CONFIG_NVS_SEC_KEY_PROTECT_USING_HMAC

from -1 to 5 if CONFIG_NVS_SEC_KEY_PROTECT_USING_HMAC

- "-1" if CONFIG_NVS_SEC_KEY_PROTECT_USING_HMAC

"-1" if CONFIG_NVS_SEC_KEY_PROTECT_USING_HMAC


### OpenThread

- CONFIG_OPENTHREAD_DEBUG
- CONFIG_OPENTHREAD_ENABLED
- OpenThread Spinel
- Thread Console
- Thread Core Features
- Thread Extensioned Features
- Thread Log

CONFIG_OPENTHREAD_DEBUG

CONFIG_OPENTHREAD_ENABLED


#### CONFIG_OPENTHREAD_ENABLED

Found in: Component config > OpenThread

- No (disabled)


##### Thread Task Parameters

- CONFIG_OPENTHREAD_TASK_NAME
- CONFIG_OPENTHREAD_TASK_PRIORITY
- CONFIG_OPENTHREAD_TASK_SIZE

CONFIG_OPENTHREAD_TASK_NAME

CONFIG_OPENTHREAD_TASK_PRIORITY

CONFIG_OPENTHREAD_TASK_SIZE


##### CONFIG_OPENTHREAD_TASK_NAME

Found in: Component config > OpenThread > CONFIG_OPENTHREAD_ENABLED > Thread Task Parameters

- "ot_main" if CONFIG_OPENTHREAD_ENABLED

"ot_main" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TASK_SIZE

Found in: Component config > OpenThread > CONFIG_OPENTHREAD_ENABLED > Thread Task Parameters

- 8192 if CONFIG_OPENTHREAD_ENABLED

8192 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TASK_PRIORITY

Found in: Component config > OpenThread > CONFIG_OPENTHREAD_ENABLED > Thread Task Parameters

- 5 if CONFIG_OPENTHREAD_ENABLED

5 if CONFIG_OPENTHREAD_ENABLED


##### Thread Version Message

- CONFIG_OPENTHREAD_PACKAGE_NAME
- CONFIG_OPENTHREAD_PLATFORM_INFO

CONFIG_OPENTHREAD_PACKAGE_NAME

CONFIG_OPENTHREAD_PLATFORM_INFO


##### CONFIG_OPENTHREAD_PACKAGE_NAME

Found in: Component config > OpenThread > CONFIG_OPENTHREAD_ENABLED > Thread Version Message

- "openthread-esp32" if CONFIG_OPENTHREAD_ENABLED

"openthread-esp32" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PLATFORM_INFO

Found in: Component config > OpenThread > CONFIG_OPENTHREAD_ENABLED > Thread Version Message

- "esp32p4" if CONFIG_OPENTHREAD_ENABLED

"esp32p4" if CONFIG_OPENTHREAD_ENABLED


#### Thread Console

- CONFIG_OPENTHREAD_CLI
- CONFIG_OPENTHREAD_CONSOLE_ENABLE
- CONFIG_OPENTHREAD_CONSOLE_COMMAND_PREFIX

CONFIG_OPENTHREAD_CLI

CONFIG_OPENTHREAD_CONSOLE_ENABLE

CONFIG_OPENTHREAD_CONSOLE_COMMAND_PREFIX


##### CONFIG_OPENTHREAD_CONSOLE_ENABLE

Found in: Component config > OpenThread > Thread Console

- Yes (enabled) if CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_CONSOLE_TYPE

Found in: Component config > OpenThread > Thread Console > CONFIG_OPENTHREAD_CONSOLE_ENABLE

Available options:

- OpenThread console type UART (CONFIG_OPENTHREAD_CONSOLE_TYPE_UART)
- OpenThread console type USB Serial/JTAG Controller (CONFIG_OPENTHREAD_CONSOLE_TYPE_USB_SERIAL_JTAG)

OpenThread console type UART (CONFIG_OPENTHREAD_CONSOLE_TYPE_UART)


##### CONFIG_OPENTHREAD_CLI

Found in: Component config > OpenThread > Thread Console

- Yes (enabled)


##### CONFIG_OPENTHREAD_CONSOLE_COMMAND_PREFIX

Found in: Component config > OpenThread > Thread Console

- "ot"


#### Thread Core Features

- CSL Configurations
- CONFIG_OPENTHREAD_BORDER_AGENT_ENABLE
- CONFIG_OPENTHREAD_BORDER_ROUTER
- CONFIG_OPENTHREAD_COMMISSIONER
- CONFIG_OPENTHREAD_CSL_ENABLE
- CONFIG_OPENTHREAD_DIAG
- CONFIG_OPENTHREAD_DNS_CLIENT
- CONFIG_OPENTHREAD_DNS64_CLIENT
- CONFIG_OPENTHREAD_JOINER
- CONFIG_OPENTHREAD_LINK_METRICS
- CONFIG_OPENTHREAD_MACFILTER_ENABLE
- CONFIG_OPENTHREAD_RX_ON_WHEN_IDLE
- CONFIG_OPENTHREAD_PARENT_SEARCH_MTD
- CONFIG_OPENTHREAD_RADIO_STATS_ENABLE
- CONFIG_OPENTHREAD_SRP_CLIENT
- CONFIG_OPENTHREAD_TIME_SYNC
- CONFIG_OPENTHREAD_TIMING_OPTIMIZATION
- OpenThread Stack Parameters
- Parent Search Configurations
- Thread 15.4 Radio Link
- CONFIG_OPENTHREAD_DEVICE_TYPE
- Thread Memory Allocation
- Thread Operational Dataset
- Thread Radio Co-Processor Feature
- Thread Trel Radio Link

CONFIG_OPENTHREAD_BORDER_AGENT_ENABLE

CONFIG_OPENTHREAD_BORDER_ROUTER

CONFIG_OPENTHREAD_COMMISSIONER

CONFIG_OPENTHREAD_CSL_ENABLE

CONFIG_OPENTHREAD_DIAG

CONFIG_OPENTHREAD_DNS_CLIENT

CONFIG_OPENTHREAD_DNS64_CLIENT

CONFIG_OPENTHREAD_JOINER

CONFIG_OPENTHREAD_LINK_METRICS

CONFIG_OPENTHREAD_MACFILTER_ENABLE

CONFIG_OPENTHREAD_RX_ON_WHEN_IDLE

CONFIG_OPENTHREAD_PARENT_SEARCH_MTD

CONFIG_OPENTHREAD_RADIO_STATS_ENABLE

CONFIG_OPENTHREAD_SRP_CLIENT

CONFIG_OPENTHREAD_TIME_SYNC

CONFIG_OPENTHREAD_TIMING_OPTIMIZATION

CONFIG_OPENTHREAD_DEVICE_TYPE


##### Thread Operational Dataset

- CONFIG_OPENTHREAD_NETWORK_EXTPANID
- CONFIG_OPENTHREAD_MESH_LOCAL_PREFIX
- CONFIG_OPENTHREAD_NETWORK_CHANNEL
- CONFIG_OPENTHREAD_NETWORK_MASTERKEY
- CONFIG_OPENTHREAD_NETWORK_NAME
- CONFIG_OPENTHREAD_NETWORK_PANID
- CONFIG_OPENTHREAD_NETWORK_PSKC

CONFIG_OPENTHREAD_NETWORK_EXTPANID

CONFIG_OPENTHREAD_MESH_LOCAL_PREFIX

CONFIG_OPENTHREAD_NETWORK_CHANNEL

CONFIG_OPENTHREAD_NETWORK_MASTERKEY

CONFIG_OPENTHREAD_NETWORK_NAME

CONFIG_OPENTHREAD_NETWORK_PANID

CONFIG_OPENTHREAD_NETWORK_PSKC


##### CONFIG_OPENTHREAD_NETWORK_NAME

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- "OpenThread-ESP" if CONFIG_OPENTHREAD_ENABLED

"OpenThread-ESP" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_MESH_LOCAL_PREFIX

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- "fd00:db8:a0:0::/64" if CONFIG_OPENTHREAD_ENABLED

"fd00:db8:a0:0::/64" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_NETWORK_CHANNEL

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- from 11 to 26 if CONFIG_OPENTHREAD_ENABLED

from 11 to 26 if CONFIG_OPENTHREAD_ENABLED

- 15 if CONFIG_OPENTHREAD_ENABLED

15 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_NETWORK_PANID

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- from 0 to 0xFFFE if CONFIG_OPENTHREAD_ENABLED

from 0 to 0xFFFE if CONFIG_OPENTHREAD_ENABLED

- "0x1234" if CONFIG_OPENTHREAD_ENABLED

"0x1234" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_NETWORK_EXTPANID

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- dead00beef00cafe if CONFIG_OPENTHREAD_ENABLED

dead00beef00cafe if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_NETWORK_MASTERKEY

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- 00112233445566778899aabbccddeeff if CONFIG_OPENTHREAD_ENABLED

00112233445566778899aabbccddeeff if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_NETWORK_PSKC

Found in: Component config > OpenThread > Thread Core Features > Thread Operational Dataset

- 104810e2315100afd6bc9215a6bfac53 if CONFIG_OPENTHREAD_ENABLED

104810e2315100afd6bc9215a6bfac53 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_DEVICE_TYPE

Found in: Component config > OpenThread > Thread Core Features

Available options:

- Full Thread Device (CONFIG_OPENTHREAD_FTD) Select this to enable Full Thread Device which can act as router and leader in a Thread network.
- Minimal Thread Device (CONFIG_OPENTHREAD_MTD) Select this to enable Minimal Thread Device which can only act as end device in a Thread network. This will reduce the code size of the OpenThread stack.
- Radio Only Device (CONFIG_OPENTHREAD_RADIO) Select this to enable Radio Only Device which can only forward 15.4 packets to the host. The OpenThread stack will be run on the host and OpenThread will have minimal footprint on the radio only device.

Full Thread Device (CONFIG_OPENTHREAD_FTD)

Minimal Thread Device (CONFIG_OPENTHREAD_MTD)

Radio Only Device (CONFIG_OPENTHREAD_RADIO)


##### Thread Trel Radio Link

- CONFIG_OPENTHREAD_RADIO_TREL

CONFIG_OPENTHREAD_RADIO_TREL


##### CONFIG_OPENTHREAD_RADIO_TREL

Found in: Component config > OpenThread > Thread Core Features > Thread Trel Radio Link

- No (disabled) if (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TREL_PORT

Found in: Component config > OpenThread > Thread Core Features > Thread Trel Radio Link > CONFIG_OPENTHREAD_RADIO_TREL

- 12390 if CONFIG_OPENTHREAD_RADIO_TREL && (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED

12390 if CONFIG_OPENTHREAD_RADIO_TREL && (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TREL_BUFFER_SIZE

Found in: Component config > OpenThread > Thread Core Features > Thread Trel Radio Link > CONFIG_OPENTHREAD_RADIO_TREL

- from 10 to 255 if CONFIG_OPENTHREAD_RADIO_TREL && (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED

from 10 to 255 if CONFIG_OPENTHREAD_RADIO_TREL && (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED

- 50 if CONFIG_OPENTHREAD_RADIO_TREL && (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED

50 if CONFIG_OPENTHREAD_RADIO_TREL && (EXAMPLE_CONNECT_WIFI || EXAMPLE_CONNECT_ETHERNET) && CONFIG_OPENTHREAD_ENABLED


##### Thread 15.4 Radio Link

- CONFIG_OPENTHREAD_RADIO_TYPE

CONFIG_OPENTHREAD_RADIO_TYPE


##### CONFIG_OPENTHREAD_RADIO_TYPE

Found in: Component config > OpenThread > Thread Core Features > Thread 15.4 Radio Link

Available options:

- Native 15.4 radio (CONFIG_OPENTHREAD_RADIO_NATIVE) Select this to use the native 15.4 radio.
- Connect via UART (CONFIG_OPENTHREAD_RADIO_SPINEL_UART) Select this to connect to a Radio Co-Processor via UART.
- Connect via SPI (CONFIG_OPENTHREAD_RADIO_SPINEL_SPI) Select this to connect to a Radio Co-Processor via SPI.
- Disable the Thread radio based on 15.4 link (CONFIG_OPENTHREAD_RADIO_154_NONE) Select this to disable the Thread radio based on 15.4 link.

Native 15.4 radio (CONFIG_OPENTHREAD_RADIO_NATIVE)

Connect via UART (CONFIG_OPENTHREAD_RADIO_SPINEL_UART)

Connect via SPI (CONFIG_OPENTHREAD_RADIO_SPINEL_SPI)


##### Thread Radio Co-Processor Feature

- CONFIG_OPENTHREAD_NCP_VENDOR_HOOK
- CONFIG_OPENTHREAD_RCP_TRANSPORT

CONFIG_OPENTHREAD_NCP_VENDOR_HOOK

CONFIG_OPENTHREAD_RCP_TRANSPORT


##### CONFIG_OPENTHREAD_RCP_TRANSPORT

Found in: Component config > OpenThread > Thread Core Features > Thread Radio Co-Processor Feature

Available options:

- UART RCP (CONFIG_OPENTHREAD_RCP_UART) Select this to enable UART connection to host.
- SPI RCP (CONFIG_OPENTHREAD_RCP_SPI) Select this to enable SPI connection to host.
- USB RCP (CONFIG_OPENTHREAD_RCP_USB_SERIAL_JTAG) Select this to enable connection to host over USB JTAG serial.

UART RCP (CONFIG_OPENTHREAD_RCP_UART)

SPI RCP (CONFIG_OPENTHREAD_RCP_SPI)

USB RCP (CONFIG_OPENTHREAD_RCP_USB_SERIAL_JTAG)


##### CONFIG_OPENTHREAD_NCP_VENDOR_HOOK

Found in: Component config > OpenThread > Thread Core Features > Thread Radio Co-Processor Feature

- Yes (enabled) if CONFIG_OPENTHREAD_RADIO && CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_RADIO && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_BORDER_ROUTER

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_FTD && CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_FTD && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_COMMISSIONER

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### Commissioner Configurations

- CONFIG_OPENTHREAD_COMM_MAX_JOINER_ENTRIES

CONFIG_OPENTHREAD_COMM_MAX_JOINER_ENTRIES


##### CONFIG_OPENTHREAD_COMM_MAX_JOINER_ENTRIES

Found in: Component config > OpenThread > Thread Core Features > CONFIG_OPENTHREAD_COMMISSIONER > Commissioner Configurations

- 2 if CONFIG_OPENTHREAD_COMMISSIONER && CONFIG_OPENTHREAD_ENABLED

2 if CONFIG_OPENTHREAD_COMMISSIONER && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_JOINER

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_SRP_CLIENT

Found in: Component config > OpenThread > Thread Core Features

- Yes (enabled) if CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_ENABLED


##### SRP Client Configurations

- CONFIG_OPENTHREAD_SRP_CLIENT_MAX_SERVICES

CONFIG_OPENTHREAD_SRP_CLIENT_MAX_SERVICES


##### CONFIG_OPENTHREAD_SRP_CLIENT_MAX_SERVICES

Found in: Component config > OpenThread > Thread Core Features > CONFIG_OPENTHREAD_SRP_CLIENT > SRP Client Configurations

- 5 if CONFIG_OPENTHREAD_SRP_CLIENT && CONFIG_OPENTHREAD_ENABLED

5 if CONFIG_OPENTHREAD_SRP_CLIENT && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_DNS_CLIENT

Found in: Component config > OpenThread > Thread Core Features

- Yes (enabled) if CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_DNS64_CLIENT

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_LWIP_IPV4 && CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_LWIP_IPV4 && CONFIG_OPENTHREAD_ENABLED


##### DNS64 Client Configurations

- CONFIG_OPENTHREAD_DNS_SERVER_ADDR

CONFIG_OPENTHREAD_DNS_SERVER_ADDR


##### CONFIG_OPENTHREAD_DNS_SERVER_ADDR

Found in: Component config > OpenThread > Thread Core Features > CONFIG_OPENTHREAD_DNS64_CLIENT > DNS64 Client Configurations

- "8.8.8.8" if CONFIG_OPENTHREAD_DNS64_CLIENT && CONFIG_OPENTHREAD_ENABLED

"8.8.8.8" if CONFIG_OPENTHREAD_DNS64_CLIENT && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TIMING_OPTIMIZATION

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_LINK_METRICS

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_BORDER_AGENT_ENABLE

Found in: Component config > OpenThread > Thread Core Features

- Yes (enabled) if CONFIG_OPENTHREAD_BORDER_ROUTER && CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_BORDER_ROUTER && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_MACFILTER_ENABLE

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_CSL_ENABLE

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CSL Configurations

- CONFIG_OPENTHREAD_CSL_DEBUG_ENABLE
- CONFIG_OPENTHREAD_CSL_UNCERTAIN
- CONFIG_OPENTHREAD_CSL_ACCURACY

CONFIG_OPENTHREAD_CSL_DEBUG_ENABLE

CONFIG_OPENTHREAD_CSL_UNCERTAIN

CONFIG_OPENTHREAD_CSL_ACCURACY


##### CONFIG_OPENTHREAD_CSL_ACCURACY

Found in: Component config > OpenThread > Thread Core Features > CSL Configurations

- 50 if CONFIG_OPENTHREAD_ENABLED

50 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_CSL_UNCERTAIN

Found in: Component config > OpenThread > Thread Core Features > CSL Configurations

- 0 if CONFIG_OPENTHREAD_ENABLED

0 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_CSL_DEBUG_ENABLE

Found in: Component config > OpenThread > Thread Core Features > CSL Configurations

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TIME_SYNC

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_RADIO_STATS_ENABLE

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED

No (disabled) if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_RX_ON_WHEN_IDLE

Found in: Component config > OpenThread > Thread Core Features

- No (disabled) if (CONFIG_ESP_COEX_SW_COEXIST_ENABLE || CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE) && CONFIG_OPENTHREAD_ENABLED

No (disabled) if (CONFIG_ESP_COEX_SW_COEXIST_ENABLE || CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_DIAG

Found in: Component config > OpenThread > Thread Core Features

- Yes (enabled) if CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PARENT_SEARCH_MTD

Found in: Component config > OpenThread > Thread Core Features

- Yes (enabled) if CONFIG_OPENTHREAD_MTD && CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_MTD && CONFIG_OPENTHREAD_ENABLED


##### Parent Search Configurations

- CONFIG_OPENTHREAD_PARENT_SEARCH_BACKOFF_INTERVAL_MINS
- CONFIG_OPENTHREAD_PARENT_SEARCH_CHECK_INTERVAL_MINS
- CONFIG_OPENTHREAD_PARENT_SEARCH_RESELECT_TIMEOUT_MINS
- CONFIG_OPENTHREAD_PARENT_SEARCH_RSS_MARGIN
- CONFIG_OPENTHREAD_PARENT_SEARCH_RSS_THRESHOLD

CONFIG_OPENTHREAD_PARENT_SEARCH_BACKOFF_INTERVAL_MINS

CONFIG_OPENTHREAD_PARENT_SEARCH_CHECK_INTERVAL_MINS

CONFIG_OPENTHREAD_PARENT_SEARCH_RESELECT_TIMEOUT_MINS

CONFIG_OPENTHREAD_PARENT_SEARCH_RSS_MARGIN

CONFIG_OPENTHREAD_PARENT_SEARCH_RSS_THRESHOLD


##### CONFIG_OPENTHREAD_PARENT_SEARCH_CHECK_INTERVAL_MINS

Found in: Component config > OpenThread > Thread Core Features > Parent Search Configurations

- 9 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED

9 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PARENT_SEARCH_BACKOFF_INTERVAL_MINS

Found in: Component config > OpenThread > Thread Core Features > Parent Search Configurations

- 600 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED

600 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PARENT_SEARCH_RSS_THRESHOLD

Found in: Component config > OpenThread > Thread Core Features > Parent Search Configurations

- "-65" if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED

"-65" if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PARENT_SEARCH_RESELECT_TIMEOUT_MINS

Found in: Component config > OpenThread > Thread Core Features > Parent Search Configurations

- 90 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED

90 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PARENT_SEARCH_RSS_MARGIN

Found in: Component config > OpenThread > Thread Core Features > Parent Search Configurations

- 7 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED

7 if (CONFIG_OPENTHREAD_PARENT_SEARCH_MTD || CONFIG_OPENTHREAD_FTD) && CONFIG_OPENTHREAD_ENABLED


##### Thread Memory Allocation

- CONFIG_OPENTHREAD_PLATFORM_MALLOC_CAP_SPIRAM
- CONFIG_OPENTHREAD_PLATFORM_MSGPOOL_MANAGEMENT

CONFIG_OPENTHREAD_PLATFORM_MALLOC_CAP_SPIRAM

CONFIG_OPENTHREAD_PLATFORM_MSGPOOL_MANAGEMENT


##### CONFIG_OPENTHREAD_PLATFORM_MALLOC_CAP_SPIRAM

Found in: Component config > OpenThread > Thread Core Features > Thread Memory Allocation

- Yes (enabled) if (CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC) && CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if (CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PLATFORM_MSGPOOL_MANAGEMENT

Found in: Component config > OpenThread > Thread Core Features > Thread Memory Allocation

- No (disabled) if (CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC) && CONFIG_OPENTHREAD_ENABLED

No (disabled) if (CONFIG_SPIRAM_USE_CAPS_ALLOC || CONFIG_SPIRAM_USE_MALLOC) && CONFIG_OPENTHREAD_ENABLED


##### OpenThread Stack Parameters

- CONFIG_OPENTHREAD_MAC_MAX_CSMA_BACKOFFS_DIRECT
- CONFIG_OPENTHREAD_PREFERRED_CHANNEL_MASK
- CONFIG_OPENTHREAD_SUPPORTED_CHANNEL_MASK
- CONFIG_OPENTHREAD_XTAL_ACCURACY
- CONFIG_OPENTHREAD_BUS_LATENCY
- CONFIG_OPENTHREAD_NUM_MESSAGE_BUFFERS
- CONFIG_OPENTHREAD_MLE_MAX_CHILDREN
- CONFIG_OPENTHREAD_TMF_ADDR_CACHE_ENTRIES
- CONFIG_OPENTHREAD_UART_BUFFER_SIZE
- Thread Address Query Config

CONFIG_OPENTHREAD_MAC_MAX_CSMA_BACKOFFS_DIRECT

CONFIG_OPENTHREAD_PREFERRED_CHANNEL_MASK

CONFIG_OPENTHREAD_SUPPORTED_CHANNEL_MASK

CONFIG_OPENTHREAD_XTAL_ACCURACY

CONFIG_OPENTHREAD_BUS_LATENCY

CONFIG_OPENTHREAD_NUM_MESSAGE_BUFFERS

CONFIG_OPENTHREAD_MLE_MAX_CHILDREN

CONFIG_OPENTHREAD_TMF_ADDR_CACHE_ENTRIES

CONFIG_OPENTHREAD_UART_BUFFER_SIZE


##### Thread Address Query Config

- CONFIG_OPENTHREAD_ADDRESS_QUERY_RETRY_DELAY
- CONFIG_OPENTHREAD_ADDRESS_QUERY_MAX_RETRY_DELAY
- CONFIG_OPENTHREAD_ADDRESS_QUERY_TIMEOUT

CONFIG_OPENTHREAD_ADDRESS_QUERY_RETRY_DELAY

CONFIG_OPENTHREAD_ADDRESS_QUERY_MAX_RETRY_DELAY

CONFIG_OPENTHREAD_ADDRESS_QUERY_TIMEOUT


##### CONFIG_OPENTHREAD_ADDRESS_QUERY_TIMEOUT

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters > Thread Address Query Config

- 3 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED

3 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_ADDRESS_QUERY_RETRY_DELAY

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters > Thread Address Query Config

- 15 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED

15 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_ADDRESS_QUERY_MAX_RETRY_DELAY

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters > Thread Address Query Config

- 120 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED

120 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_MTD) && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_PREFERRED_CHANNEL_MASK

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- "0x7fff800" if CONFIG_OPENTHREAD_ENABLED

"0x7fff800" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_SUPPORTED_CHANNEL_MASK

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- "0x7fff800" if CONFIG_OPENTHREAD_ENABLED

"0x7fff800" if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_NUM_MESSAGE_BUFFERS

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 65 if CONFIG_OPENTHREAD_ENABLED

65 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_XTAL_ACCURACY

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 10 if CONFIG_OPENTHREAD_ENABLED

10 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_BUS_LATENCY

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 4000 if CONFIG_OPENTHREAD_ENABLED

4000 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_MLE_MAX_CHILDREN

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 10 if CONFIG_OPENTHREAD_ENABLED

10 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_TMF_ADDR_CACHE_ENTRIES

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 20 if CONFIG_OPENTHREAD_ENABLED

20 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_UART_BUFFER_SIZE

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 2048 if CONFIG_OPENTHREAD_ENABLED

2048 if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_MAC_MAX_CSMA_BACKOFFS_DIRECT

Found in: Component config > OpenThread > Thread Core Features > OpenThread Stack Parameters

- 4 if CONFIG_OPENTHREAD_ENABLED

4 if CONFIG_OPENTHREAD_ENABLED


#### Thread Log

- CONFIG_OPENTHREAD_LOG_LEVEL_DYNAMIC
- CONFIG_OPENTHREAD_LOG_LEVEL

CONFIG_OPENTHREAD_LOG_LEVEL_DYNAMIC

CONFIG_OPENTHREAD_LOG_LEVEL


##### CONFIG_OPENTHREAD_LOG_LEVEL_DYNAMIC

Found in: Component config > OpenThread > Thread Log

- Yes (enabled) if CONFIG_OPENTHREAD_ENABLED

Yes (enabled) if CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_LOG_LEVEL

Found in: Component config > OpenThread > Thread Log

Available options:

- No logs (CONFIG_OPENTHREAD_LOG_LEVEL_NONE)
- Error logs (CONFIG_OPENTHREAD_LOG_LEVEL_CRIT)
- Warning logs (CONFIG_OPENTHREAD_LOG_LEVEL_WARN)
- Notice logs (CONFIG_OPENTHREAD_LOG_LEVEL_NOTE)
- Info logs (CONFIG_OPENTHREAD_LOG_LEVEL_INFO)
- Debug logs (CONFIG_OPENTHREAD_LOG_LEVEL_DEBG)

No logs (CONFIG_OPENTHREAD_LOG_LEVEL_NONE)

Error logs (CONFIG_OPENTHREAD_LOG_LEVEL_CRIT)

Warning logs (CONFIG_OPENTHREAD_LOG_LEVEL_WARN)

Notice logs (CONFIG_OPENTHREAD_LOG_LEVEL_NOTE)

Info logs (CONFIG_OPENTHREAD_LOG_LEVEL_INFO)

Debug logs (CONFIG_OPENTHREAD_LOG_LEVEL_DEBG)


#### Thread Extensioned Features

- CONFIG_OPENTHREAD_HEADER_CUSTOM

CONFIG_OPENTHREAD_HEADER_CUSTOM


##### CONFIG_OPENTHREAD_HEADER_CUSTOM

Found in: Component config > OpenThread > Thread Extensioned Features

- No (disabled) if CONFIG_OPENTHREAD_ENABLED

No (disabled) if CONFIG_OPENTHREAD_ENABLED


##### OpenThread Custom Header Config

- CONFIG_OPENTHREAD_CUSTOM_HEADER_FILE_NAME
- CONFIG_OPENTHREAD_CUSTOM_HEADER_PATH

CONFIG_OPENTHREAD_CUSTOM_HEADER_FILE_NAME

CONFIG_OPENTHREAD_CUSTOM_HEADER_PATH


##### CONFIG_OPENTHREAD_CUSTOM_HEADER_PATH

Found in: Component config > OpenThread > Thread Extensioned Features > CONFIG_OPENTHREAD_HEADER_CUSTOM > OpenThread Custom Header Config

- if CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_ENABLED

if CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_ENABLED


##### CONFIG_OPENTHREAD_CUSTOM_HEADER_FILE_NAME

Found in: Component config > OpenThread > Thread Extensioned Features > CONFIG_OPENTHREAD_HEADER_CUSTOM > OpenThread Custom Header Config

- "esp_ot_custom_config.h" if CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_ENABLED

"esp_ot_custom_config.h" if CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_HEADER_CUSTOM && CONFIG_OPENTHREAD_ENABLED


#### OpenThread Spinel

- CONFIG_OPENTHREAD_SPINEL_ONLY
- CONFIG_OPENTHREAD_SPINEL_MAC_MAX_CSMA_BACKOFFS_DIRECT
- CONFIG_OPENTHREAD_SPINEL_RX_FRAME_BUFFER_SIZE

CONFIG_OPENTHREAD_SPINEL_ONLY

CONFIG_OPENTHREAD_SPINEL_MAC_MAX_CSMA_BACKOFFS_DIRECT

CONFIG_OPENTHREAD_SPINEL_RX_FRAME_BUFFER_SIZE


##### CONFIG_OPENTHREAD_SPINEL_ONLY

Found in: Component config > OpenThread > OpenThread Spinel

- No (disabled)


##### CONFIG_OPENTHREAD_SPINEL_RX_FRAME_BUFFER_SIZE

Found in: Component config > OpenThread > OpenThread Spinel

- 1024 if (CONFIG_OPENTHREAD_MTD || CONFIG_OPENTHREAD_RADIO) && (CONFIG_OPENTHREAD_ENABLED || CONFIG_OPENTHREAD_SPINEL_ONLY)
- 2048 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_SPINEL_ONLY) && (CONFIG_OPENTHREAD_ENABLED || CONFIG_OPENTHREAD_SPINEL_ONLY)

1024 if (CONFIG_OPENTHREAD_MTD || CONFIG_OPENTHREAD_RADIO) && (CONFIG_OPENTHREAD_ENABLED || CONFIG_OPENTHREAD_SPINEL_ONLY)

2048 if (CONFIG_OPENTHREAD_FTD || CONFIG_OPENTHREAD_SPINEL_ONLY) && (CONFIG_OPENTHREAD_ENABLED || CONFIG_OPENTHREAD_SPINEL_ONLY)


##### CONFIG_OPENTHREAD_SPINEL_MAC_MAX_CSMA_BACKOFFS_DIRECT

Found in: Component config > OpenThread > OpenThread Spinel

- 4 if CONFIG_OPENTHREAD_SPINEL_ONLY

4 if CONFIG_OPENTHREAD_SPINEL_ONLY


#### CONFIG_OPENTHREAD_DEBUG

Found in: Component config > OpenThread

- No (disabled)

- CONFIG_OPENTHREAD_DUMP_MAC_ON_ASSERT

CONFIG_OPENTHREAD_DUMP_MAC_ON_ASSERT


##### CONFIG_OPENTHREAD_DUMP_MAC_ON_ASSERT

Found in: Component config > OpenThread > CONFIG_OPENTHREAD_DEBUG

- No (disabled) if CONFIG_OPENTHREAD_DEBUG && CONFIG_OPENTHREAD_RADIO_NATIVE && CONFIG_IEEE802154_DEBUG

No (disabled) if CONFIG_OPENTHREAD_DEBUG && CONFIG_OPENTHREAD_RADIO_NATIVE && CONFIG_IEEE802154_DEBUG


### Protocomm

- CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_0
- CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_1
- CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_2

CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_0

CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_1

CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_2


#### CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_0

Found in: Component config > Protocomm

- No (disabled)


#### CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_1

Found in: Component config > Protocomm

- No (disabled)


#### CONFIG_ESP_PROTOCOMM_SUPPORT_SECURITY_VERSION_2

Found in: Component config > Protocomm

- Yes (enabled)


### PThreads

- CONFIG_PTHREAD_TASK_NAME_DEFAULT
- CONFIG_PTHREAD_TASK_CORE_DEFAULT
- CONFIG_PTHREAD_TASK_PRIO_DEFAULT
- CONFIG_PTHREAD_TASK_STACK_SIZE_DEFAULT
- CONFIG_PTHREAD_STACK_MIN

CONFIG_PTHREAD_TASK_NAME_DEFAULT

CONFIG_PTHREAD_TASK_CORE_DEFAULT

CONFIG_PTHREAD_TASK_PRIO_DEFAULT

CONFIG_PTHREAD_TASK_STACK_SIZE_DEFAULT

CONFIG_PTHREAD_STACK_MIN


#### CONFIG_PTHREAD_TASK_PRIO_DEFAULT

Found in: Component config > PThreads

- from 0 to 255

- 5


#### CONFIG_PTHREAD_TASK_STACK_SIZE_DEFAULT

Found in: Component config > PThreads

- 3072


#### CONFIG_PTHREAD_STACK_MIN

Found in: Component config > PThreads

- 768


#### CONFIG_PTHREAD_TASK_CORE_DEFAULT

Found in: Component config > PThreads

Available options:

- No affinity (CONFIG_PTHREAD_DEFAULT_CORE_NO_AFFINITY)
- Core 0 (CONFIG_PTHREAD_DEFAULT_CORE_0)
- Core 1 (CONFIG_PTHREAD_DEFAULT_CORE_1)

No affinity (CONFIG_PTHREAD_DEFAULT_CORE_NO_AFFINITY)

Core 0 (CONFIG_PTHREAD_DEFAULT_CORE_0)

Core 1 (CONFIG_PTHREAD_DEFAULT_CORE_1)


#### CONFIG_PTHREAD_TASK_NAME_DEFAULT

Found in: Component config > PThreads

- "pthread"


### SD Protocol Layer Configuration

- CONFIG_SD_ENABLE_SDIO_SUPPORT

CONFIG_SD_ENABLE_SDIO_SUPPORT


#### CONFIG_SD_ENABLE_SDIO_SUPPORT

Found in: Component config > SD Protocol Layer Configuration

- Yes (enabled)


### SoC Settings

- MMU Config


#### MMU Config


### Main Flash configuration

- Optional and Experimental Features (READ DOCS FIRST)
- SPI Flash behavior when brownout


#### SPI Flash behavior when brownout

- CONFIG_SPI_FLASH_BROWNOUT_RESET_XMC

CONFIG_SPI_FLASH_BROWNOUT_RESET_XMC


##### CONFIG_SPI_FLASH_BROWNOUT_RESET_XMC

Found in: Component config > Main Flash configuration > SPI Flash behavior when brownout


#### Optional and Experimental Features (READ DOCS FIRST)

- CONFIG_SPI_FLASH_AUTO_SUSPEND
- CONFIG_SPI_FLASH_AUTO_CHECK_SUSPEND_STATUS
- CONFIG_SPI_FLASH_DISABLE_SCHEDULER_IN_SUSPEND
- CONFIG_SPI_FLASH_FORCE_ENABLE_C6_H2_SUSPEND
- CONFIG_SPI_FLASH_FORCE_ENABLE_XMC_C_SUSPEND
- CONFIG_SPI_FLASH_HPM
- CONFIG_SPI_FLASH_PLACE_FUNCTIONS_IN_IRAM
- CONFIG_SPI_FLASH_SOFTWARE_RESUME
- CONFIG_SPI_FLASH_SUSPEND_TRS_VAL_US
- CONFIG_SPI_FLASH_SUSPEND_TSUS_VAL_US
- CONFIG_SPI_FLASH_HPM_DC

CONFIG_SPI_FLASH_AUTO_SUSPEND

CONFIG_SPI_FLASH_AUTO_CHECK_SUSPEND_STATUS

CONFIG_SPI_FLASH_DISABLE_SCHEDULER_IN_SUSPEND

CONFIG_SPI_FLASH_FORCE_ENABLE_C6_H2_SUSPEND

CONFIG_SPI_FLASH_FORCE_ENABLE_XMC_C_SUSPEND

CONFIG_SPI_FLASH_HPM

CONFIG_SPI_FLASH_PLACE_FUNCTIONS_IN_IRAM

CONFIG_SPI_FLASH_SOFTWARE_RESUME

CONFIG_SPI_FLASH_SUSPEND_TRS_VAL_US

CONFIG_SPI_FLASH_SUSPEND_TSUS_VAL_US

CONFIG_SPI_FLASH_HPM_DC


##### CONFIG_SPI_FLASH_HPM

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)

Available options:

- Enable (CONFIG_SPI_FLASH_HPM_ENA)
- Auto (Not recommended) (CONFIG_SPI_FLASH_HPM_AUTO)
- Disabled (CONFIG_SPI_FLASH_HPM_DIS)

Enable (CONFIG_SPI_FLASH_HPM_ENA)

Auto (Not recommended) (CONFIG_SPI_FLASH_HPM_AUTO)

Disabled (CONFIG_SPI_FLASH_HPM_DIS)


##### CONFIG_SPI_FLASH_HPM_DC

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)

Available options:

- Auto (Enable when bootloader support enabled (BOOTLOADER_FLASH_DC_AWARE)) (CONFIG_SPI_FLASH_HPM_DC_AUTO)
- Disable (READ DOCS FIRST) (CONFIG_SPI_FLASH_HPM_DC_DISABLE)

Disable (READ DOCS FIRST) (CONFIG_SPI_FLASH_HPM_DC_DISABLE)


##### CONFIG_SPI_FLASH_AUTO_SUSPEND

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_SUSPEND_TSUS_VAL_US

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_SUSPEND_TRS_VAL_US

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_FORCE_ENABLE_XMC_C_SUSPEND

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_FORCE_ENABLE_C6_H2_SUSPEND

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_SOFTWARE_RESUME

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_DISABLE_SCHEDULER_IN_SUSPEND

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)

Disable freertos task scheduler when CONFIG_SPI_FLASH_AUTO_SUSPEND is enabled. Thus only interrupt can trigger a suspend. When SPI_FLASH_AUTO_SUSPEND is enabled, default behavior is not disable the task scheduler, so both interrupt and high priority task can suspend the erase/program operation. When this option is enabled, task scheduler is disabled, only interrupt can suspend erase/program operation.


##### CONFIG_SPI_FLASH_AUTO_CHECK_SUSPEND_STATUS

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


##### CONFIG_SPI_FLASH_PLACE_FUNCTIONS_IN_IRAM

Found in: Component config > Main Flash configuration > Optional and Experimental Features (READ DOCS FIRST)


### SPI Flash driver

- Auto-detect flash chips
- CONFIG_SPI_FLASH_BYPASS_BLOCK_ERASE
- CONFIG_SPI_FLASH_ENABLE_ENCRYPTED_READ_WRITE
- CONFIG_SPI_FLASH_ENABLE_COUNTERS
- CONFIG_SPI_FLASH_YIELD_DURING_ERASE
- CONFIG_SPI_FLASH_CHECK_ERASE_TIMEOUT_DISABLED
- CONFIG_SPI_FLASH_WRITE_CHUNK_SIZE
- CONFIG_SPI_FLASH_OVERRIDE_CHIP_DRIVER_LIST
- CONFIG_SPI_FLASH_SIZE_OVERRIDE
- CONFIG_SPI_FLASH_ROM_IMPL
- CONFIG_SPI_FLASH_VERIFY_WRITE
- CONFIG_SPI_FLASH_DANGEROUS_WRITE

CONFIG_SPI_FLASH_BYPASS_BLOCK_ERASE

CONFIG_SPI_FLASH_ENABLE_ENCRYPTED_READ_WRITE

CONFIG_SPI_FLASH_ENABLE_COUNTERS

CONFIG_SPI_FLASH_YIELD_DURING_ERASE

CONFIG_SPI_FLASH_CHECK_ERASE_TIMEOUT_DISABLED

CONFIG_SPI_FLASH_WRITE_CHUNK_SIZE

CONFIG_SPI_FLASH_OVERRIDE_CHIP_DRIVER_LIST

CONFIG_SPI_FLASH_SIZE_OVERRIDE

CONFIG_SPI_FLASH_ROM_IMPL

CONFIG_SPI_FLASH_VERIFY_WRITE

CONFIG_SPI_FLASH_DANGEROUS_WRITE


#### CONFIG_SPI_FLASH_VERIFY_WRITE

Found in: Component config > SPI Flash driver


##### CONFIG_SPI_FLASH_LOG_FAILED_WRITE

Found in: Component config > SPI Flash driver > CONFIG_SPI_FLASH_VERIFY_WRITE


##### CONFIG_SPI_FLASH_WARN_SETTING_ZERO_TO_ONE

Found in: Component config > SPI Flash driver > CONFIG_SPI_FLASH_VERIFY_WRITE


#### CONFIG_SPI_FLASH_ENABLE_COUNTERS

Found in: Component config > SPI Flash driver

- esp_flash_reset_counters
- esp_flash_dump_counters
- esp_flash_get_counters


#### CONFIG_SPI_FLASH_ROM_IMPL

Found in: Component config > SPI Flash driver

- SPI_FLASH_AUTO_SUSPEND (C3, S3)


#### CONFIG_SPI_FLASH_DANGEROUS_WRITE

Found in: Component config > SPI Flash driver

Available options:

- Aborts (CONFIG_SPI_FLASH_DANGEROUS_WRITE_ABORTS)
- Fails (CONFIG_SPI_FLASH_DANGEROUS_WRITE_FAILS)
- Allowed (CONFIG_SPI_FLASH_DANGEROUS_WRITE_ALLOWED)

Aborts (CONFIG_SPI_FLASH_DANGEROUS_WRITE_ABORTS)

Fails (CONFIG_SPI_FLASH_DANGEROUS_WRITE_FAILS)

Allowed (CONFIG_SPI_FLASH_DANGEROUS_WRITE_ALLOWED)


#### CONFIG_SPI_FLASH_BYPASS_BLOCK_ERASE

Found in: Component config > SPI Flash driver


#### CONFIG_SPI_FLASH_YIELD_DURING_ERASE

Found in: Component config > SPI Flash driver


##### CONFIG_SPI_FLASH_ERASE_YIELD_DURATION_MS

Found in: Component config > SPI Flash driver > CONFIG_SPI_FLASH_YIELD_DURING_ERASE


##### CONFIG_SPI_FLASH_ERASE_YIELD_TICKS

Found in: Component config > SPI Flash driver > CONFIG_SPI_FLASH_YIELD_DURING_ERASE


#### CONFIG_SPI_FLASH_WRITE_CHUNK_SIZE

Found in: Component config > SPI Flash driver


#### CONFIG_SPI_FLASH_SIZE_OVERRIDE

Found in: Component config > SPI Flash driver


#### CONFIG_SPI_FLASH_CHECK_ERASE_TIMEOUT_DISABLED

Found in: Component config > SPI Flash driver


#### CONFIG_SPI_FLASH_OVERRIDE_CHIP_DRIVER_LIST

Found in: Component config > SPI Flash driver


#### Auto-detect flash chips

- CONFIG_SPI_FLASH_SUPPORT_BOYA_CHIP
- CONFIG_SPI_FLASH_SUPPORT_GD_CHIP
- CONFIG_SPI_FLASH_SUPPORT_ISSI_CHIP
- CONFIG_SPI_FLASH_SUPPORT_MXIC_CHIP
- CONFIG_SPI_FLASH_SUPPORT_TH_CHIP
- CONFIG_SPI_FLASH_SUPPORT_WINBOND_CHIP

CONFIG_SPI_FLASH_SUPPORT_BOYA_CHIP

CONFIG_SPI_FLASH_SUPPORT_GD_CHIP

CONFIG_SPI_FLASH_SUPPORT_ISSI_CHIP

CONFIG_SPI_FLASH_SUPPORT_MXIC_CHIP

CONFIG_SPI_FLASH_SUPPORT_TH_CHIP

CONFIG_SPI_FLASH_SUPPORT_WINBOND_CHIP


##### CONFIG_SPI_FLASH_SUPPORT_ISSI_CHIP

Found in: Component config > SPI Flash driver > Auto-detect flash chips


##### CONFIG_SPI_FLASH_SUPPORT_MXIC_CHIP

Found in: Component config > SPI Flash driver > Auto-detect flash chips


##### CONFIG_SPI_FLASH_SUPPORT_GD_CHIP

Found in: Component config > SPI Flash driver > Auto-detect flash chips


##### CONFIG_SPI_FLASH_SUPPORT_WINBOND_CHIP

Found in: Component config > SPI Flash driver > Auto-detect flash chips


##### CONFIG_SPI_FLASH_SUPPORT_BOYA_CHIP

Found in: Component config > SPI Flash driver > Auto-detect flash chips


##### CONFIG_SPI_FLASH_SUPPORT_TH_CHIP

Found in: Component config > SPI Flash driver > Auto-detect flash chips


#### CONFIG_SPI_FLASH_ENABLE_ENCRYPTED_READ_WRITE

Found in: Component config > SPI Flash driver


### SPIFFS Configuration

- Debug Configuration
- CONFIG_SPIFFS_USE_MAGIC
- CONFIG_SPIFFS_GC_STATS
- CONFIG_SPIFFS_PAGE_CHECK
- CONFIG_SPIFFS_FOLLOW_SYMLINKS
- CONFIG_SPIFFS_MAX_PARTITIONS
- CONFIG_SPIFFS_USE_MTIME
- CONFIG_SPIFFS_GC_MAX_RUNS
- CONFIG_SPIFFS_OBJ_NAME_LEN
- CONFIG_SPIFFS_META_LENGTH
- SPIFFS Cache Configuration
- CONFIG_SPIFFS_PAGE_SIZE
- CONFIG_SPIFFS_MTIME_WIDE_64_BITS

CONFIG_SPIFFS_USE_MAGIC

CONFIG_SPIFFS_GC_STATS

CONFIG_SPIFFS_PAGE_CHECK

CONFIG_SPIFFS_FOLLOW_SYMLINKS

CONFIG_SPIFFS_MAX_PARTITIONS

CONFIG_SPIFFS_USE_MTIME

CONFIG_SPIFFS_GC_MAX_RUNS

CONFIG_SPIFFS_OBJ_NAME_LEN

CONFIG_SPIFFS_META_LENGTH

CONFIG_SPIFFS_PAGE_SIZE

CONFIG_SPIFFS_MTIME_WIDE_64_BITS


#### CONFIG_SPIFFS_MAX_PARTITIONS

Found in: Component config > SPIFFS Configuration

- from 1 to 10

- 3


#### SPIFFS Cache Configuration

- CONFIG_SPIFFS_CACHE

CONFIG_SPIFFS_CACHE


##### CONFIG_SPIFFS_CACHE

Found in: Component config > SPIFFS Configuration > SPIFFS Cache Configuration

- Yes (enabled)


##### CONFIG_SPIFFS_CACHE_WR

Found in: Component config > SPIFFS Configuration > SPIFFS Cache Configuration > CONFIG_SPIFFS_CACHE

- Yes (enabled)


##### CONFIG_SPIFFS_CACHE_STATS

Found in: Component config > SPIFFS Configuration > SPIFFS Cache Configuration > CONFIG_SPIFFS_CACHE

- No (disabled)


#### CONFIG_SPIFFS_PAGE_CHECK

Found in: Component config > SPIFFS Configuration

- Yes (enabled)


#### CONFIG_SPIFFS_GC_MAX_RUNS

Found in: Component config > SPIFFS Configuration

- from 1 to 10000

- 10


#### CONFIG_SPIFFS_GC_STATS

Found in: Component config > SPIFFS Configuration

- No (disabled)


#### CONFIG_SPIFFS_PAGE_SIZE

Found in: Component config > SPIFFS Configuration

- from 256 to 1024

- 256


#### CONFIG_SPIFFS_OBJ_NAME_LEN

Found in: Component config > SPIFFS Configuration

- from 1 to 256

- 32


#### CONFIG_SPIFFS_FOLLOW_SYMLINKS

Found in: Component config > SPIFFS Configuration

- No (disabled)


#### CONFIG_SPIFFS_USE_MAGIC

Found in: Component config > SPIFFS Configuration

- Yes (enabled)


##### CONFIG_SPIFFS_USE_MAGIC_LENGTH

Found in: Component config > SPIFFS Configuration > CONFIG_SPIFFS_USE_MAGIC

- Yes (enabled)


#### CONFIG_SPIFFS_META_LENGTH

Found in: Component config > SPIFFS Configuration

- 4


#### CONFIG_SPIFFS_USE_MTIME

Found in: Component config > SPIFFS Configuration

- Yes (enabled)


#### CONFIG_SPIFFS_MTIME_WIDE_64_BITS

Found in: Component config > SPIFFS Configuration

- No (disabled) if CONFIG_SPIFFS_META_LENGTH >= 8

No (disabled) if CONFIG_SPIFFS_META_LENGTH >= 8


#### Debug Configuration

- CONFIG_SPIFFS_DBG
- CONFIG_SPIFFS_API_DBG
- CONFIG_SPIFFS_CACHE_DBG
- CONFIG_SPIFFS_CHECK_DBG
- CONFIG_SPIFFS_TEST_VISUALISATION
- CONFIG_SPIFFS_GC_DBG

CONFIG_SPIFFS_DBG

CONFIG_SPIFFS_API_DBG

CONFIG_SPIFFS_CACHE_DBG

CONFIG_SPIFFS_CHECK_DBG

CONFIG_SPIFFS_TEST_VISUALISATION

CONFIG_SPIFFS_GC_DBG


##### CONFIG_SPIFFS_DBG

Found in: Component config > SPIFFS Configuration > Debug Configuration

- No (disabled)


##### CONFIG_SPIFFS_API_DBG

Found in: Component config > SPIFFS Configuration > Debug Configuration

- No (disabled)


##### CONFIG_SPIFFS_GC_DBG

Found in: Component config > SPIFFS Configuration > Debug Configuration

- No (disabled)


##### CONFIG_SPIFFS_CACHE_DBG

Found in: Component config > SPIFFS Configuration > Debug Configuration

- No (disabled)


##### CONFIG_SPIFFS_CHECK_DBG

Found in: Component config > SPIFFS Configuration > Debug Configuration

- No (disabled)


##### CONFIG_SPIFFS_TEST_VISUALISATION

Found in: Component config > SPIFFS Configuration > Debug Configuration

- No (disabled)


### TCP Transport

- Websocket


#### Websocket

- CONFIG_WS_TRANSPORT

CONFIG_WS_TRANSPORT


##### CONFIG_WS_TRANSPORT

Found in: Component config > TCP Transport > Websocket

- Yes (enabled)


##### CONFIG_WS_BUFFER_SIZE

Found in: Component config > TCP Transport > Websocket > CONFIG_WS_TRANSPORT

- 1024


##### CONFIG_WS_DYNAMIC_BUFFER

Found in: Component config > TCP Transport > Websocket > CONFIG_WS_TRANSPORT

- No (disabled)


### Ultra Low Power (ULP) Co-processor

- CONFIG_ULP_ROM_PRINT_ENABLE
- CONFIG_ULP_COPROC_ENABLED
- CONFIG_ULP_TRAP_WAKEUP
- ULP Debugging Options
- ULP RISC-V Settings

CONFIG_ULP_ROM_PRINT_ENABLE

CONFIG_ULP_COPROC_ENABLED

CONFIG_ULP_TRAP_WAKEUP


#### CONFIG_ULP_COPROC_ENABLED

Found in: Component config > Ultra Low Power (ULP) Co-processor

- No (disabled)


##### CONFIG_ULP_COPROC_TYPE

Found in: Component config > Ultra Low Power (ULP) Co-processor > CONFIG_ULP_COPROC_ENABLED

Available options:

- ULP FSM (Finite State Machine) (CONFIG_ULP_COPROC_TYPE_FSM)
- ULP RISC-V (CONFIG_ULP_COPROC_TYPE_RISCV)
- LP core RISC-V (CONFIG_ULP_COPROC_TYPE_LP_CORE)

ULP FSM (Finite State Machine) (CONFIG_ULP_COPROC_TYPE_FSM)

ULP RISC-V (CONFIG_ULP_COPROC_TYPE_RISCV)

LP core RISC-V (CONFIG_ULP_COPROC_TYPE_LP_CORE)


##### CONFIG_ULP_COPROC_RESERVE_MEM

Found in: Component config > Ultra Low Power (ULP) Co-processor > CONFIG_ULP_COPROC_ENABLED

- from 32 to 31088 if CONFIG_ULP_COPROC_ENABLED

from 32 to 31088 if CONFIG_ULP_COPROC_ENABLED

- 4096 if CONFIG_ULP_COPROC_ENABLED

4096 if CONFIG_ULP_COPROC_ENABLED


#### ULP RISC-V Settings

- CONFIG_ULP_RISCV_UART_BAUDRATE
- CONFIG_ULP_RISCV_INTERRUPT_ENABLE
- CONFIG_ULP_RISCV_I2C_RW_TIMEOUT

CONFIG_ULP_RISCV_UART_BAUDRATE

CONFIG_ULP_RISCV_INTERRUPT_ENABLE

CONFIG_ULP_RISCV_I2C_RW_TIMEOUT


##### CONFIG_ULP_RISCV_INTERRUPT_ENABLE

Found in: Component config > Ultra Low Power (ULP) Co-processor > ULP RISC-V Settings

- No (disabled) if CONFIG_ULP_COPROC_TYPE_RISCV

No (disabled) if CONFIG_ULP_COPROC_TYPE_RISCV


##### CONFIG_ULP_RISCV_UART_BAUDRATE

Found in: Component config > Ultra Low Power (ULP) Co-processor > ULP RISC-V Settings

- 9600 if CONFIG_ULP_COPROC_TYPE_RISCV

9600 if CONFIG_ULP_COPROC_TYPE_RISCV


##### CONFIG_ULP_RISCV_I2C_RW_TIMEOUT

Found in: Component config > Ultra Low Power (ULP) Co-processor > ULP RISC-V Settings

- from -1 to 4294967295 if CONFIG_ULP_COPROC_TYPE_RISCV

from -1 to 4294967295 if CONFIG_ULP_COPROC_TYPE_RISCV

- 500 if CONFIG_ULP_COPROC_TYPE_RISCV

500 if CONFIG_ULP_COPROC_TYPE_RISCV


#### CONFIG_ULP_ROM_PRINT_ENABLE

Found in: Component config > Ultra Low Power (ULP) Co-processor

- Yes (enabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE

Yes (enabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE


#### CONFIG_ULP_TRAP_WAKEUP

Found in: Component config > Ultra Low Power (ULP) Co-processor

- Yes (enabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE

Yes (enabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE


#### ULP Debugging Options

- CONFIG_ULP_NORESET_UNDER_DEBUG
- CONFIG_ULP_PANIC_OUTPUT_ENABLE
- CONFIG_ULP_HP_UART_CONSOLE_PRINT

CONFIG_ULP_NORESET_UNDER_DEBUG

CONFIG_ULP_PANIC_OUTPUT_ENABLE

CONFIG_ULP_HP_UART_CONSOLE_PRINT


##### CONFIG_ULP_PANIC_OUTPUT_ENABLE

Found in: Component config > Ultra Low Power (ULP) Co-processor > ULP Debugging Options

- No (disabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE

No (disabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE


##### CONFIG_ULP_HP_UART_CONSOLE_PRINT

Found in: Component config > Ultra Low Power (ULP) Co-processor > ULP Debugging Options


##### CONFIG_ULP_NORESET_UNDER_DEBUG

Found in: Component config > Ultra Low Power (ULP) Co-processor > ULP Debugging Options

- Yes (enabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE

Yes (enabled) if CONFIG_ULP_COPROC_TYPE_LP_CORE


### Unity unit testing library

- CONFIG_UNITY_ENABLE_COLOR
- CONFIG_UNITY_ENABLE_IDF_TEST_RUNNER
- CONFIG_UNITY_ENABLE_FIXTURE
- CONFIG_UNITY_ENABLE_BACKTRACE_ON_FAIL
- CONFIG_UNITY_ENABLE_64BIT
- CONFIG_UNITY_ENABLE_DOUBLE
- CONFIG_UNITY_ENABLE_FLOAT

CONFIG_UNITY_ENABLE_COLOR

CONFIG_UNITY_ENABLE_IDF_TEST_RUNNER

CONFIG_UNITY_ENABLE_FIXTURE

CONFIG_UNITY_ENABLE_BACKTRACE_ON_FAIL

CONFIG_UNITY_ENABLE_64BIT

CONFIG_UNITY_ENABLE_DOUBLE

CONFIG_UNITY_ENABLE_FLOAT


#### CONFIG_UNITY_ENABLE_FLOAT

Found in: Component config > Unity unit testing library

- Yes (enabled)


#### CONFIG_UNITY_ENABLE_DOUBLE

Found in: Component config > Unity unit testing library

- Yes (enabled)


#### CONFIG_UNITY_ENABLE_64BIT

Found in: Component config > Unity unit testing library

- No (disabled)


#### CONFIG_UNITY_ENABLE_COLOR

Found in: Component config > Unity unit testing library

- No (disabled)


#### CONFIG_UNITY_ENABLE_IDF_TEST_RUNNER

Found in: Component config > Unity unit testing library

- TEST_CASE macro which performs automatic registration of test functions
- Functions to run registered test functions: unity_run_all_tests, unity_run_tests_with_filter, unity_run_single_test_by_name.
- Interactive menu which lists test cases and allows choosing the tests to be run, available via unity_run_menu function.

- Yes (enabled)


#### CONFIG_UNITY_ENABLE_FIXTURE

Found in: Component config > Unity unit testing library

- No (disabled)


#### CONFIG_UNITY_ENABLE_BACKTRACE_ON_FAIL

Found in: Component config > Unity unit testing library

- No (disabled)


### Virtual file system

- CONFIG_VFS_SUPPORT_IO

CONFIG_VFS_SUPPORT_IO


#### CONFIG_VFS_SUPPORT_IO

Found in: Component config > Virtual file system

- Yes (enabled)


##### CONFIG_VFS_SUPPORT_DIR

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO

- Yes (enabled)


##### CONFIG_VFS_SUPPORT_SELECT

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO


##### CONFIG_VFS_SUPPRESS_SELECT_DEBUG_OUTPUT

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO > CONFIG_VFS_SUPPORT_SELECT

- Yes (enabled)


##### CONFIG_VFS_SELECT_IN_RAM

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO > CONFIG_VFS_SUPPORT_SELECT

- No (disabled)


##### CONFIG_VFS_SUPPORT_TERMIOS

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO

- No (disabled)


##### CONFIG_VFS_MAX_COUNT

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO

- from 1 to 20

- 8


##### Host File System I/O (Semihosting)

- CONFIG_VFS_SEMIHOSTFS_MAX_MOUNT_POINTS

CONFIG_VFS_SEMIHOSTFS_MAX_MOUNT_POINTS


##### CONFIG_VFS_SEMIHOSTFS_MAX_MOUNT_POINTS

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO > Host File System I/O (Semihosting)

- 1


##### CONFIG_VFS_INITIALIZE_DEV_NULL

Found in: Component config > Virtual file system > CONFIG_VFS_SUPPORT_IO

- Yes (enabled)


### Wear Levelling

- CONFIG_WL_SECTOR_MODE
- CONFIG_WL_SECTOR_SIZE

CONFIG_WL_SECTOR_MODE

CONFIG_WL_SECTOR_SIZE


#### CONFIG_WL_SECTOR_SIZE

Found in: Component config > Wear Levelling

Available options:

- 512 (CONFIG_WL_SECTOR_SIZE_512)
- 4096 (CONFIG_WL_SECTOR_SIZE_4096)

512 (CONFIG_WL_SECTOR_SIZE_512)

4096 (CONFIG_WL_SECTOR_SIZE_4096)


#### CONFIG_WL_SECTOR_MODE

Found in: Component config > Wear Levelling

- In Performance mode a data will be stored to the RAM and then stored back to the flash. Compared to the Safety mode, this operation is faster, but if power will be lost when erase sector operation is in progress, then the data from complete flash device sector will be lost.
- In Safety mode data from complete flash device sector will be read from flash, modified, and then stored back to flash. Compared to the Performance mode, this operation is slower, but if power is lost during erase sector operation, then the data from full flash device sector will not be lost.

Available options:

- Performance (CONFIG_WL_SECTOR_MODE_PERF)
- Safety (CONFIG_WL_SECTOR_MODE_SAFE)

Performance (CONFIG_WL_SECTOR_MODE_PERF)

Safety (CONFIG_WL_SECTOR_MODE_SAFE)


### Configuration for components not included in the build


## Project configuration for components not included in the build


## CONFIG_IDF_EXPERIMENTAL_FEATURES

- CONFIG_ESPTOOLPY_FLASHFREQ_120M && CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_DTR
- CONFIG_SPIRAM_SPEED_120M && CONFIG_SPIRAM_MODE_OCT
- CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH
- CONFIG_ESP_WIFI_EAP_TLS1_3
- CONFIG_ESP_WIFI_ENABLE_ROAMING_APP
- CONFIG_USB_HOST_EXT_PORT_RESET_ATTEMPTS
- CONFIG_LIBC_PICOLIBC
- CONFIG_GDMA_ENABLE_WEIGHTED_ARBITRATION
- CONFIG_I3C_MASTER_ENABLED
- CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO

CONFIG_ESPTOOLPY_FLASHFREQ_120M && CONFIG_ESPTOOLPY_FLASH_SAMPLE_MODE_DTR

CONFIG_SPIRAM_SPEED_120M && CONFIG_SPIRAM_MODE_OCT

CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH

CONFIG_ESP_WIFI_EAP_TLS1_3

CONFIG_ESP_WIFI_ENABLE_ROAMING_APP

CONFIG_USB_HOST_EXT_PORT_RESET_ATTEMPTS

CONFIG_LIBC_PICOLIBC

CONFIG_GDMA_ENABLE_WEIGHTED_ARBITRATION

CONFIG_I3C_MASTER_ENABLED

CONFIG_MBEDTLS_ESP_IDF_USE_PSA_CRYPTO

- No (disabled)


## Deprecated options and their replacements

CONFIG_A2DP_ENABLE (CONFIG_BT_A2DP_ENABLE)

- CONFIG_A2D_TRACE_LEVEL_NONE
- CONFIG_A2D_TRACE_LEVEL_ERROR
- CONFIG_A2D_TRACE_LEVEL_WARNING
- CONFIG_A2D_TRACE_LEVEL_API
- CONFIG_A2D_TRACE_LEVEL_EVENT
- CONFIG_A2D_TRACE_LEVEL_DEBUG
- CONFIG_A2D_TRACE_LEVEL_VERBOSE

CONFIG_A2D_TRACE_LEVEL_NONE

CONFIG_A2D_TRACE_LEVEL_ERROR

CONFIG_A2D_TRACE_LEVEL_WARNING

CONFIG_A2D_TRACE_LEVEL_API

CONFIG_A2D_TRACE_LEVEL_EVENT

CONFIG_A2D_TRACE_LEVEL_DEBUG

CONFIG_A2D_TRACE_LEVEL_VERBOSE

CONFIG_ADC_DISABLE_DAC (CONFIG_ADC_DISABLE_DAC_OUTPUT)

CONFIG_ANA_CMPR_ISR_IRAM_SAFE (CONFIG_ANA_CMPR_ISR_CACHE_SAFE)

- CONFIG_APPL_TRACE_LEVEL_NONE
- CONFIG_APPL_TRACE_LEVEL_ERROR
- CONFIG_APPL_TRACE_LEVEL_WARNING
- CONFIG_APPL_TRACE_LEVEL_API
- CONFIG_APPL_TRACE_LEVEL_EVENT
- CONFIG_APPL_TRACE_LEVEL_DEBUG
- CONFIG_APPL_TRACE_LEVEL_VERBOSE

CONFIG_APPL_TRACE_LEVEL_NONE

CONFIG_APPL_TRACE_LEVEL_ERROR

CONFIG_APPL_TRACE_LEVEL_WARNING

CONFIG_APPL_TRACE_LEVEL_API

CONFIG_APPL_TRACE_LEVEL_EVENT

CONFIG_APPL_TRACE_LEVEL_DEBUG

CONFIG_APPL_TRACE_LEVEL_VERBOSE

CONFIG_APP_ANTI_ROLLBACK (CONFIG_BOOTLOADER_APP_ANTI_ROLLBACK)

CONFIG_APP_ROLLBACK_ENABLE (CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE)

CONFIG_APP_SECURE_VERSION (CONFIG_BOOTLOADER_APP_SECURE_VERSION)

CONFIG_APP_SECURE_VERSION_SIZE_EFUSE_FIELD (CONFIG_BOOTLOADER_APP_SEC_VER_SIZE_EFUSE_FIELD)

- CONFIG_AVCT_TRACE_LEVEL_NONE
- CONFIG_AVCT_TRACE_LEVEL_ERROR
- CONFIG_AVCT_TRACE_LEVEL_WARNING
- CONFIG_AVCT_TRACE_LEVEL_API
- CONFIG_AVCT_TRACE_LEVEL_EVENT
- CONFIG_AVCT_TRACE_LEVEL_DEBUG
- CONFIG_AVCT_TRACE_LEVEL_VERBOSE

CONFIG_AVCT_TRACE_LEVEL_NONE

CONFIG_AVCT_TRACE_LEVEL_ERROR

CONFIG_AVCT_TRACE_LEVEL_WARNING

CONFIG_AVCT_TRACE_LEVEL_API

CONFIG_AVCT_TRACE_LEVEL_EVENT

CONFIG_AVCT_TRACE_LEVEL_DEBUG

CONFIG_AVCT_TRACE_LEVEL_VERBOSE

- CONFIG_AVDT_TRACE_LEVEL_NONE
- CONFIG_AVDT_TRACE_LEVEL_ERROR
- CONFIG_AVDT_TRACE_LEVEL_WARNING
- CONFIG_AVDT_TRACE_LEVEL_API
- CONFIG_AVDT_TRACE_LEVEL_EVENT
- CONFIG_AVDT_TRACE_LEVEL_DEBUG
- CONFIG_AVDT_TRACE_LEVEL_VERBOSE

CONFIG_AVDT_TRACE_LEVEL_NONE

CONFIG_AVDT_TRACE_LEVEL_ERROR

CONFIG_AVDT_TRACE_LEVEL_WARNING

CONFIG_AVDT_TRACE_LEVEL_API

CONFIG_AVDT_TRACE_LEVEL_EVENT

CONFIG_AVDT_TRACE_LEVEL_DEBUG

CONFIG_AVDT_TRACE_LEVEL_VERBOSE

- CONFIG_AVRC_TRACE_LEVEL_NONE
- CONFIG_AVRC_TRACE_LEVEL_ERROR
- CONFIG_AVRC_TRACE_LEVEL_WARNING
- CONFIG_AVRC_TRACE_LEVEL_API
- CONFIG_AVRC_TRACE_LEVEL_EVENT
- CONFIG_AVRC_TRACE_LEVEL_DEBUG
- CONFIG_AVRC_TRACE_LEVEL_VERBOSE

CONFIG_AVRC_TRACE_LEVEL_NONE

CONFIG_AVRC_TRACE_LEVEL_ERROR

CONFIG_AVRC_TRACE_LEVEL_WARNING

CONFIG_AVRC_TRACE_LEVEL_API

CONFIG_AVRC_TRACE_LEVEL_EVENT

CONFIG_AVRC_TRACE_LEVEL_DEBUG

CONFIG_AVRC_TRACE_LEVEL_VERBOSE

CONFIG_BLE_ACTIVE_SCAN_REPORT_ADV_SCAN_RSP_INDIVIDUALLY (CONFIG_BT_BLE_ACT_SCAN_REP_ADV_SCAN)

CONFIG_BLE_ESTABLISH_LINK_CONNECTION_TIMEOUT (CONFIG_BT_BLE_ESTAB_LINK_CONN_TOUT)

CONFIG_BLE_MESH_GATT_PROXY (CONFIG_BLE_MESH_GATT_PROXY_SERVER)

CONFIG_BLE_SMP_ENABLE (CONFIG_BT_BLE_SMP_ENABLE)

CONFIG_BLUEDROID_MEM_DEBUG (CONFIG_BT_BLUEDROID_MEM_DEBUG)

- CONFIG_BLUEDROID_PINNED_TO_CORE_0
- CONFIG_BLUEDROID_PINNED_TO_CORE_1

CONFIG_BLUEDROID_PINNED_TO_CORE_0

CONFIG_BLUEDROID_PINNED_TO_CORE_1

- CONFIG_BLUFI_TRACE_LEVEL_NONE
- CONFIG_BLUFI_TRACE_LEVEL_ERROR
- CONFIG_BLUFI_TRACE_LEVEL_WARNING
- CONFIG_BLUFI_TRACE_LEVEL_API
- CONFIG_BLUFI_TRACE_LEVEL_EVENT
- CONFIG_BLUFI_TRACE_LEVEL_DEBUG
- CONFIG_BLUFI_TRACE_LEVEL_VERBOSE

CONFIG_BLUFI_TRACE_LEVEL_NONE

CONFIG_BLUFI_TRACE_LEVEL_ERROR

CONFIG_BLUFI_TRACE_LEVEL_WARNING

CONFIG_BLUFI_TRACE_LEVEL_API

CONFIG_BLUFI_TRACE_LEVEL_EVENT

CONFIG_BLUFI_TRACE_LEVEL_DEBUG

CONFIG_BLUFI_TRACE_LEVEL_VERBOSE

CONFIG_BNEP_INITIAL_TRACE_LEVEL (CONFIG_BT_LOG_BNEP_TRACE_LEVEL)

CONFIG_BROWNOUT_DET (CONFIG_ESP_BROWNOUT_DET)

- CONFIG_BROWNOUT_DET_LVL_SEL_7
- CONFIG_BROWNOUT_DET_LVL_SEL_6
- CONFIG_BROWNOUT_DET_LVL_SEL_5

CONFIG_BROWNOUT_DET_LVL_SEL_7

CONFIG_BROWNOUT_DET_LVL_SEL_6

CONFIG_BROWNOUT_DET_LVL_SEL_5

- CONFIG_BTC_TRACE_LEVEL_NONE
- CONFIG_BTC_TRACE_LEVEL_ERROR
- CONFIG_BTC_TRACE_LEVEL_WARNING
- CONFIG_BTC_TRACE_LEVEL_API
- CONFIG_BTC_TRACE_LEVEL_EVENT
- CONFIG_BTC_TRACE_LEVEL_DEBUG
- CONFIG_BTC_TRACE_LEVEL_VERBOSE

CONFIG_BTC_TRACE_LEVEL_NONE

CONFIG_BTC_TRACE_LEVEL_ERROR

CONFIG_BTC_TRACE_LEVEL_WARNING

CONFIG_BTC_TRACE_LEVEL_API

CONFIG_BTC_TRACE_LEVEL_EVENT

CONFIG_BTC_TRACE_LEVEL_DEBUG

CONFIG_BTC_TRACE_LEVEL_VERBOSE

CONFIG_BTC_TASK_STACK_SIZE (CONFIG_BT_BTC_TASK_STACK_SIZE)

- CONFIG_SDP_TRACE_LEVEL_NONE
- CONFIG_SDP_TRACE_LEVEL_ERROR
- CONFIG_SDP_TRACE_LEVEL_WARNING
- CONFIG_SDP_TRACE_LEVEL_API
- CONFIG_SDP_TRACE_LEVEL_EVENT
- CONFIG_SDP_TRACE_LEVEL_DEBUG
- CONFIG_SDP_TRACE_LEVEL_VERBOSE

CONFIG_SDP_TRACE_LEVEL_NONE

CONFIG_SDP_TRACE_LEVEL_ERROR

CONFIG_SDP_TRACE_LEVEL_WARNING

CONFIG_SDP_TRACE_LEVEL_API

CONFIG_SDP_TRACE_LEVEL_EVENT

CONFIG_SDP_TRACE_LEVEL_DEBUG

CONFIG_SDP_TRACE_LEVEL_VERBOSE

- CONFIG_BTIF_TRACE_LEVEL_NONE
- CONFIG_BTIF_TRACE_LEVEL_ERROR
- CONFIG_BTIF_TRACE_LEVEL_WARNING
- CONFIG_BTIF_TRACE_LEVEL_API
- CONFIG_BTIF_TRACE_LEVEL_EVENT
- CONFIG_BTIF_TRACE_LEVEL_DEBUG
- CONFIG_BTIF_TRACE_LEVEL_VERBOSE

CONFIG_BTIF_TRACE_LEVEL_NONE

CONFIG_BTIF_TRACE_LEVEL_ERROR

CONFIG_BTIF_TRACE_LEVEL_WARNING

CONFIG_BTIF_TRACE_LEVEL_API

CONFIG_BTIF_TRACE_LEVEL_EVENT

CONFIG_BTIF_TRACE_LEVEL_DEBUG

CONFIG_BTIF_TRACE_LEVEL_VERBOSE

- CONFIG_BTM_TRACE_LEVEL_NONE
- CONFIG_BTM_TRACE_LEVEL_ERROR
- CONFIG_BTM_TRACE_LEVEL_WARNING
- CONFIG_BTM_TRACE_LEVEL_API
- CONFIG_BTM_TRACE_LEVEL_EVENT
- CONFIG_BTM_TRACE_LEVEL_DEBUG
- CONFIG_BTM_TRACE_LEVEL_VERBOSE

CONFIG_BTM_TRACE_LEVEL_NONE

CONFIG_BTM_TRACE_LEVEL_ERROR

CONFIG_BTM_TRACE_LEVEL_WARNING

CONFIG_BTM_TRACE_LEVEL_API

CONFIG_BTM_TRACE_LEVEL_EVENT

CONFIG_BTM_TRACE_LEVEL_DEBUG

CONFIG_BTM_TRACE_LEVEL_VERBOSE

CONFIG_BTU_TASK_STACK_SIZE (CONFIG_BT_BTU_TASK_STACK_SIZE)

CONFIG_BT_NIMBLE_ACL_BUF_COUNT (CONFIG_BT_NIMBLE_TRANSPORT_ACL_FROM_LL_COUNT)

CONFIG_BT_NIMBLE_ACL_BUF_SIZE (CONFIG_BT_NIMBLE_TRANSPORT_ACL_SIZE)

CONFIG_BT_NIMBLE_HCI_EVT_BUF_SIZE (CONFIG_BT_NIMBLE_TRANSPORT_EVT_SIZE)

CONFIG_BT_NIMBLE_HCI_EVT_HI_BUF_COUNT (CONFIG_BT_NIMBLE_TRANSPORT_EVT_COUNT)

CONFIG_BT_NIMBLE_HCI_EVT_LO_BUF_COUNT (CONFIG_BT_NIMBLE_TRANSPORT_EVT_DISCARD_COUNT)

CONFIG_BT_NIMBLE_MSYS1_BLOCK_COUNT (CONFIG_BT_NIMBLE_MSYS_1_BLOCK_COUNT)

CONFIG_BT_NIMBLE_SM_SC_LVL (CONFIG_BT_NIMBLE_SM_LVL)

CONFIG_BT_NIMBLE_TASK_STACK_SIZE (CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE)

CONFIG_CAM_CTLR_DVP_CAM_ISR_IRAM_SAFE (CONFIG_CAM_CTLR_DVP_CAM_ISR_CACHE_SAFE)

CONFIG_CAM_CTLR_ISP_DVP_ISR_IRAM_SAFE (CONFIG_CAM_CTLR_ISP_DVP_ISR_CACHE_SAFE)

CONFIG_CAM_CTLR_MIPI_CSI_ISR_IRAM_SAFE (CONFIG_CAM_CTLR_MIPI_CSI_ISR_CACHE_SAFE)

CONFIG_CLASSIC_BT_ENABLED (CONFIG_BT_CLASSIC_ENABLED)

- CONFIG_CONSOLE_UART_DEFAULT
- CONFIG_CONSOLE_UART_CUSTOM
- CONFIG_CONSOLE_UART_NONE, CONFIG_ESP_CONSOLE_UART_NONE

CONFIG_CONSOLE_UART_DEFAULT

CONFIG_CONSOLE_UART_CUSTOM

CONFIG_CONSOLE_UART_NONE, CONFIG_ESP_CONSOLE_UART_NONE

CONFIG_CONSOLE_UART_BAUDRATE (CONFIG_ESP_CONSOLE_UART_BAUDRATE)

- CONFIG_CONSOLE_UART_CUSTOM_NUM_0
- CONFIG_CONSOLE_UART_CUSTOM_NUM_1

CONFIG_CONSOLE_UART_CUSTOM_NUM_0

CONFIG_CONSOLE_UART_CUSTOM_NUM_1

CONFIG_CONSOLE_UART_RX_GPIO (CONFIG_ESP_CONSOLE_UART_RX_GPIO)

CONFIG_CONSOLE_UART_TX_GPIO (CONFIG_ESP_CONSOLE_UART_TX_GPIO)

CONFIG_CXX_EXCEPTIONS (CONFIG_COMPILER_CXX_EXCEPTIONS)

CONFIG_CXX_EXCEPTIONS_EMG_POOL_SIZE (CONFIG_COMPILER_CXX_EXCEPTIONS_EMG_POOL_SIZE)

CONFIG_EFUSE_SECURE_VERSION_EMULATE (CONFIG_BOOTLOADER_EFUSE_SECURE_VERSION_EMULATE)

CONFIG_ENABLE_STATIC_TASK_CLEAN_UP_HOOK (CONFIG_FREERTOS_TASK_PRE_DELETION_HOOK)

- CONFIG_ESP32_CORE_DUMP_DECODE_INFO
- CONFIG_ESP32_CORE_DUMP_DECODE_DISABLE

CONFIG_ESP32_CORE_DUMP_DECODE_INFO

CONFIG_ESP32_CORE_DUMP_DECODE_DISABLE

CONFIG_ESP32_CORE_DUMP_MAX_TASKS_NUM (CONFIG_ESP_COREDUMP_MAX_TASKS_NUM)

CONFIG_ESP32_CORE_DUMP_STACK_SIZE (CONFIG_ESP_COREDUMP_STACK_SIZE)

CONFIG_ESP32_CORE_DUMP_UART_DELAY (CONFIG_ESP_COREDUMP_UART_DELAY)

CONFIG_ESP32_DEBUG_STUBS_ENABLE (CONFIG_ESP_DEBUG_STUBS_ENABLE)

CONFIG_ESP32_PHY_CALIBRATION_AND_DATA_STORAGE (CONFIG_ESP_PHY_CALIBRATION_AND_DATA_STORAGE)

CONFIG_ESP32_PHY_DEFAULT_INIT_IF_INVALID (CONFIG_ESP_PHY_DEFAULT_INIT_IF_INVALID)

CONFIG_ESP32_PHY_INIT_DATA_ERROR (CONFIG_ESP_PHY_INIT_DATA_ERROR)

CONFIG_ESP32_PHY_INIT_DATA_IN_PARTITION (CONFIG_ESP_PHY_INIT_DATA_IN_PARTITION)

CONFIG_ESP32_PHY_MAC_BB_PD (CONFIG_ESP_PHY_MAC_BB_PD)

CONFIG_ESP32_PHY_MAX_WIFI_TX_POWER (CONFIG_ESP_PHY_MAX_WIFI_TX_POWER)

CONFIG_ESP32_PTHREAD_STACK_MIN (CONFIG_PTHREAD_STACK_MIN)

- CONFIG_ESP32_DEFAULT_PTHREAD_CORE_NO_AFFINITY
- CONFIG_ESP32_DEFAULT_PTHREAD_CORE_0
- CONFIG_ESP32_DEFAULT_PTHREAD_CORE_1

CONFIG_ESP32_DEFAULT_PTHREAD_CORE_NO_AFFINITY

CONFIG_ESP32_DEFAULT_PTHREAD_CORE_0

CONFIG_ESP32_DEFAULT_PTHREAD_CORE_1

CONFIG_ESP32_PTHREAD_TASK_NAME_DEFAULT (CONFIG_PTHREAD_TASK_NAME_DEFAULT)

CONFIG_ESP32_PTHREAD_TASK_PRIO_DEFAULT (CONFIG_PTHREAD_TASK_PRIO_DEFAULT)

CONFIG_ESP32_PTHREAD_TASK_STACK_SIZE_DEFAULT (CONFIG_PTHREAD_TASK_STACK_SIZE_DEFAULT)

CONFIG_ESP32_REDUCE_PHY_TX_POWER (CONFIG_ESP_PHY_REDUCE_TX_POWER)

CONFIG_ESP32_RTC_XTAL_BOOTSTRAP_CYCLES (CONFIG_ESP_SYSTEM_RTC_EXT_XTAL_BOOTSTRAP_CYCLES)

CONFIG_ESP32_SUPPORT_MULTIPLE_PHY_INIT_DATA_BIN (CONFIG_ESP_PHY_MULTIPLE_INIT_DATA_BIN)

CONFIG_ESP32_WIFI_AMPDU_RX_ENABLED (CONFIG_ESP_WIFI_AMPDU_RX_ENABLED)

CONFIG_ESP32_WIFI_AMPDU_TX_ENABLED (CONFIG_ESP_WIFI_AMPDU_TX_ENABLED)

CONFIG_ESP32_WIFI_AMSDU_TX_ENABLED (CONFIG_ESP_WIFI_AMSDU_TX_ENABLED)

CONFIG_ESP32_WIFI_CACHE_TX_BUFFER_NUM (CONFIG_ESP_WIFI_CACHE_TX_BUFFER_NUM)

CONFIG_ESP32_WIFI_CSI_ENABLED (CONFIG_ESP_WIFI_CSI_ENABLED)

CONFIG_ESP32_WIFI_DYNAMIC_RX_BUFFER_NUM (CONFIG_ESP_WIFI_DYNAMIC_RX_BUFFER_NUM)

CONFIG_ESP32_WIFI_DYNAMIC_TX_BUFFER_NUM (CONFIG_ESP_WIFI_DYNAMIC_TX_BUFFER_NUM)

CONFIG_ESP32_WIFI_ENABLE_WPA3_OWE_STA (CONFIG_ESP_WIFI_ENABLE_WPA3_OWE_STA)

CONFIG_ESP32_WIFI_ENABLE_WPA3_SAE (CONFIG_ESP_WIFI_ENABLE_WPA3_SAE)

CONFIG_ESP32_WIFI_IRAM_OPT (CONFIG_ESP_WIFI_IRAM_OPT)

CONFIG_ESP32_WIFI_MGMT_SBUF_NUM (CONFIG_ESP_WIFI_MGMT_SBUF_NUM)

CONFIG_ESP32_WIFI_NVS_ENABLED (CONFIG_ESP_WIFI_NVS_ENABLED)

CONFIG_ESP32_WIFI_RX_BA_WIN (CONFIG_ESP_WIFI_RX_BA_WIN)

CONFIG_ESP32_WIFI_RX_IRAM_OPT (CONFIG_ESP_WIFI_RX_IRAM_OPT)

CONFIG_ESP32_WIFI_SOFTAP_BEACON_MAX_LEN (CONFIG_ESP_WIFI_SOFTAP_BEACON_MAX_LEN)

CONFIG_ESP32_WIFI_STATIC_RX_BUFFER_NUM (CONFIG_ESP_WIFI_STATIC_RX_BUFFER_NUM)

CONFIG_ESP32_WIFI_STATIC_TX_BUFFER_NUM (CONFIG_ESP_WIFI_STATIC_TX_BUFFER_NUM)

CONFIG_ESP32_WIFI_SW_COEXIST_ENABLE (CONFIG_ESP_COEX_SW_COEXIST_ENABLE)

- CONFIG_ESP32_WIFI_TASK_PINNED_TO_CORE_0
- CONFIG_ESP32_WIFI_TASK_PINNED_TO_CORE_1

CONFIG_ESP32_WIFI_TASK_PINNED_TO_CORE_0

CONFIG_ESP32_WIFI_TASK_PINNED_TO_CORE_1

CONFIG_ESP32_WIFI_TX_BA_WIN (CONFIG_ESP_WIFI_TX_BA_WIN)

- CONFIG_ESP32_WIFI_STATIC_TX_BUFFER
- CONFIG_ESP32_WIFI_DYNAMIC_TX_BUFFER

CONFIG_ESP32_WIFI_STATIC_TX_BUFFER

CONFIG_ESP32_WIFI_DYNAMIC_TX_BUFFER

CONFIG_ESP_GRATUITOUS_ARP (CONFIG_LWIP_ESP_GRATUITOUS_ARP)

CONFIG_ESP_SYSTEM_MEMPROT_FEATURE (CONFIG_ESP_SYSTEM_MEMPROT)

CONFIG_ESP_SYSTEM_MEMPROT_FEATURE_LOCK (CONFIG_ESP_SYSTEM_MEMPROT_PMS_LOCK)

CONFIG_ESP_SYSTEM_MEMPROT_FEATURE_VIA_TEE (CONFIG_ESP_SYSTEM_MEMPROT)

CONFIG_ESP_SYSTEM_PD_FLASH (CONFIG_ESP_SLEEP_POWER_DOWN_FLASH)

CONFIG_ESP_SYSTEM_PMP_IDRAM_SPLIT (CONFIG_ESP_SYSTEM_MEMPROT)

CONFIG_ESP_SYSTEM_PMP_LP_CORE_RESERVE_MEM_EXECUTABLE (CONFIG_ESP_SYSTEM_MEMPROT_PMP_LP_CORE_RESERVE_MEM_EXEC)

CONFIG_ESP_SYSTEM_PM_POWER_DOWN_CPU (CONFIG_PM_POWER_DOWN_CPU_IN_LIGHT_SLEEP)

CONFIG_ESP_TASK_WDT (CONFIG_ESP_TASK_WDT_INIT)

CONFIG_ESP_WIFI_EXTERNAL_COEXIST_ENABLE (CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE)

CONFIG_ESP_WIFI_NAN_ENABLE (CONFIG_ESP_WIFI_NAN_SYNC_ENABLE)

CONFIG_ESP_WIFI_SW_COEXIST_ENABLE (CONFIG_ESP_COEX_SW_COEXIST_ENABLE)

CONFIG_EVENT_LOOP_PROFILING (CONFIG_ESP_EVENT_LOOP_PROFILING)

CONFIG_EXTERNAL_COEX_ENABLE (CONFIG_ESP_COEX_EXTERNAL_COEXIST_ENABLE)

CONFIG_FLASH_ENCRYPTION_ENABLED (CONFIG_SECURE_FLASH_ENC_ENABLED)

CONFIG_FLASH_ENCRYPTION_UART_BOOTLOADER_ALLOW_CACHE (CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_CACHE)

CONFIG_FLASH_ENCRYPTION_UART_BOOTLOADER_ALLOW_ENCRYPT (CONFIG_SECURE_FLASH_UART_BOOTLOADER_ALLOW_ENC)

- CONFIG_GAP_TRACE_LEVEL_NONE
- CONFIG_GAP_TRACE_LEVEL_ERROR
- CONFIG_GAP_TRACE_LEVEL_WARNING
- CONFIG_GAP_TRACE_LEVEL_API
- CONFIG_GAP_TRACE_LEVEL_EVENT
- CONFIG_GAP_TRACE_LEVEL_DEBUG
- CONFIG_GAP_TRACE_LEVEL_VERBOSE

CONFIG_GAP_TRACE_LEVEL_NONE

CONFIG_GAP_TRACE_LEVEL_ERROR

CONFIG_GAP_TRACE_LEVEL_WARNING

CONFIG_GAP_TRACE_LEVEL_API

CONFIG_GAP_TRACE_LEVEL_EVENT

CONFIG_GAP_TRACE_LEVEL_DEBUG

CONFIG_GAP_TRACE_LEVEL_VERBOSE

CONFIG_GARP_TMR_INTERVAL (CONFIG_LWIP_GARP_TMR_INTERVAL)

CONFIG_GATTC_CACHE_NVS_FLASH (CONFIG_BT_GATTC_CACHE_NVS_FLASH)

CONFIG_GATTC_ENABLE (CONFIG_BT_GATTC_ENABLE)

CONFIG_GATTS_ENABLE (CONFIG_BT_GATTS_ENABLE)

- CONFIG_GATTS_SEND_SERVICE_CHANGE_MANUAL
- CONFIG_GATTS_SEND_SERVICE_CHANGE_AUTO

CONFIG_GATTS_SEND_SERVICE_CHANGE_MANUAL

CONFIG_GATTS_SEND_SERVICE_CHANGE_AUTO

- CONFIG_GATT_TRACE_LEVEL_NONE
- CONFIG_GATT_TRACE_LEVEL_ERROR
- CONFIG_GATT_TRACE_LEVEL_WARNING
- CONFIG_GATT_TRACE_LEVEL_API
- CONFIG_GATT_TRACE_LEVEL_EVENT
- CONFIG_GATT_TRACE_LEVEL_DEBUG
- CONFIG_GATT_TRACE_LEVEL_VERBOSE

CONFIG_GATT_TRACE_LEVEL_NONE

CONFIG_GATT_TRACE_LEVEL_ERROR

CONFIG_GATT_TRACE_LEVEL_WARNING

CONFIG_GATT_TRACE_LEVEL_API

CONFIG_GATT_TRACE_LEVEL_EVENT

CONFIG_GATT_TRACE_LEVEL_DEBUG

CONFIG_GATT_TRACE_LEVEL_VERBOSE

CONFIG_GDBSTUB_MAX_TASKS (CONFIG_ESP_GDBSTUB_MAX_TASKS)

CONFIG_GDBSTUB_SUPPORT_TASKS (CONFIG_ESP_GDBSTUB_SUPPORT_TASKS)

CONFIG_GPTIMER_ISR_IRAM_SAFE (CONFIG_GPTIMER_ISR_CACHE_SAFE)

- CONFIG_HCI_TRACE_LEVEL_NONE
- CONFIG_HCI_TRACE_LEVEL_ERROR
- CONFIG_HCI_TRACE_LEVEL_WARNING
- CONFIG_HCI_TRACE_LEVEL_API
- CONFIG_HCI_TRACE_LEVEL_EVENT
- CONFIG_HCI_TRACE_LEVEL_DEBUG
- CONFIG_HCI_TRACE_LEVEL_VERBOSE

CONFIG_HCI_TRACE_LEVEL_NONE

CONFIG_HCI_TRACE_LEVEL_ERROR

CONFIG_HCI_TRACE_LEVEL_WARNING

CONFIG_HCI_TRACE_LEVEL_API

CONFIG_HCI_TRACE_LEVEL_EVENT

CONFIG_HCI_TRACE_LEVEL_DEBUG

CONFIG_HCI_TRACE_LEVEL_VERBOSE

CONFIG_HFP_AG_ENABLE (CONFIG_BT_HFP_AG_ENABLE)

- CONFIG_HFP_AUDIO_DATA_PATH_PCM
- CONFIG_HFP_AUDIO_DATA_PATH_HCI

CONFIG_HFP_AUDIO_DATA_PATH_PCM

CONFIG_HFP_AUDIO_DATA_PATH_HCI

CONFIG_HFP_CLIENT_ENABLE (CONFIG_BT_HFP_CLIENT_ENABLE)

CONFIG_HFP_ENABLE (CONFIG_BT_HFP_ENABLE)

- CONFIG_HID_TRACE_LEVEL_NONE
- CONFIG_HID_TRACE_LEVEL_ERROR
- CONFIG_HID_TRACE_LEVEL_WARNING
- CONFIG_HID_TRACE_LEVEL_API
- CONFIG_HID_TRACE_LEVEL_EVENT
- CONFIG_HID_TRACE_LEVEL_DEBUG
- CONFIG_HID_TRACE_LEVEL_VERBOSE

CONFIG_HID_TRACE_LEVEL_NONE

CONFIG_HID_TRACE_LEVEL_ERROR

CONFIG_HID_TRACE_LEVEL_WARNING

CONFIG_HID_TRACE_LEVEL_API

CONFIG_HID_TRACE_LEVEL_EVENT

CONFIG_HID_TRACE_LEVEL_DEBUG

CONFIG_HID_TRACE_LEVEL_VERBOSE

CONFIG_INT_WDT (CONFIG_ESP_INT_WDT)

CONFIG_INT_WDT_CHECK_CPU1 (CONFIG_ESP_INT_WDT_CHECK_CPU1)

CONFIG_INT_WDT_TIMEOUT_MS (CONFIG_ESP_INT_WDT_TIMEOUT_MS)

CONFIG_IPC_TASK_STACK_SIZE (CONFIG_ESP_IPC_TASK_STACK_SIZE)

- CONFIG_L2CAP_TRACE_LEVEL_NONE
- CONFIG_L2CAP_TRACE_LEVEL_ERROR
- CONFIG_L2CAP_TRACE_LEVEL_WARNING
- CONFIG_L2CAP_TRACE_LEVEL_API
- CONFIG_L2CAP_TRACE_LEVEL_EVENT
- CONFIG_L2CAP_TRACE_LEVEL_DEBUG
- CONFIG_L2CAP_TRACE_LEVEL_VERBOSE

CONFIG_L2CAP_TRACE_LEVEL_NONE

CONFIG_L2CAP_TRACE_LEVEL_ERROR

CONFIG_L2CAP_TRACE_LEVEL_WARNING

CONFIG_L2CAP_TRACE_LEVEL_API

CONFIG_L2CAP_TRACE_LEVEL_EVENT

CONFIG_L2CAP_TRACE_LEVEL_DEBUG

CONFIG_L2CAP_TRACE_LEVEL_VERBOSE

CONFIG_L2_TO_L3_COPY (CONFIG_LWIP_L2_TO_L3_COPY)

CONFIG_LCD_DSI_ISR_IRAM_SAFE (CONFIG_LCD_DSI_ISR_CACHE_SAFE)

- CONFIG_LOG_BOOTLOADER_LEVEL_NONE
- CONFIG_LOG_BOOTLOADER_LEVEL_ERROR
- CONFIG_LOG_BOOTLOADER_LEVEL_WARN
- CONFIG_LOG_BOOTLOADER_LEVEL_INFO
- CONFIG_LOG_BOOTLOADER_LEVEL_DEBUG
- CONFIG_LOG_BOOTLOADER_LEVEL_VERBOSE

CONFIG_LOG_BOOTLOADER_LEVEL_NONE

CONFIG_LOG_BOOTLOADER_LEVEL_ERROR

CONFIG_LOG_BOOTLOADER_LEVEL_WARN

CONFIG_LOG_BOOTLOADER_LEVEL_INFO

CONFIG_LOG_BOOTLOADER_LEVEL_DEBUG

CONFIG_LOG_BOOTLOADER_LEVEL_VERBOSE

CONFIG_MAC_BB_PD (CONFIG_ESP_PHY_MAC_BB_PD)

CONFIG_MAIN_TASK_STACK_SIZE (CONFIG_ESP_MAIN_TASK_STACK_SIZE)

- CONFIG_MCA_TRACE_LEVEL_NONE
- CONFIG_MCA_TRACE_LEVEL_ERROR
- CONFIG_MCA_TRACE_LEVEL_WARNING
- CONFIG_MCA_TRACE_LEVEL_API
- CONFIG_MCA_TRACE_LEVEL_EVENT
- CONFIG_MCA_TRACE_LEVEL_DEBUG
- CONFIG_MCA_TRACE_LEVEL_VERBOSE

CONFIG_MCA_TRACE_LEVEL_NONE

CONFIG_MCA_TRACE_LEVEL_ERROR

CONFIG_MCA_TRACE_LEVEL_WARNING

CONFIG_MCA_TRACE_LEVEL_API

CONFIG_MCA_TRACE_LEVEL_EVENT

CONFIG_MCA_TRACE_LEVEL_DEBUG

CONFIG_MCA_TRACE_LEVEL_VERBOSE

CONFIG_MCPWM_ISR_IRAM_SAFE (CONFIG_MCPWM_ISR_CACHE_SAFE)

CONFIG_NEWLIB_NANO_FORMAT (CONFIG_LIBC_NEWLIB_NANO_FORMAT)

- CONFIG_NEWLIB_STDIN_LINE_ENDING_CRLF
- CONFIG_NEWLIB_STDIN_LINE_ENDING_LF
- CONFIG_NEWLIB_STDIN_LINE_ENDING_CR

CONFIG_NEWLIB_STDIN_LINE_ENDING_CRLF

CONFIG_NEWLIB_STDIN_LINE_ENDING_LF

CONFIG_NEWLIB_STDIN_LINE_ENDING_CR

- CONFIG_NEWLIB_STDOUT_LINE_ENDING_CRLF
- CONFIG_NEWLIB_STDOUT_LINE_ENDING_LF
- CONFIG_NEWLIB_STDOUT_LINE_ENDING_CR

CONFIG_NEWLIB_STDOUT_LINE_ENDING_CRLF

CONFIG_NEWLIB_STDOUT_LINE_ENDING_LF

CONFIG_NEWLIB_STDOUT_LINE_ENDING_CR

- CONFIG_NEWLIB_TIME_SYSCALL_USE_RTC_HRT
- CONFIG_NEWLIB_TIME_SYSCALL_USE_RTC
- CONFIG_NEWLIB_TIME_SYSCALL_USE_HRT
- CONFIG_NEWLIB_TIME_SYSCALL_USE_NONE

CONFIG_NEWLIB_TIME_SYSCALL_USE_RTC_HRT

CONFIG_NEWLIB_TIME_SYSCALL_USE_RTC

CONFIG_NEWLIB_TIME_SYSCALL_USE_HRT

CONFIG_NEWLIB_TIME_SYSCALL_USE_NONE

CONFIG_NIMBLE_ATT_PREFERRED_MTU (CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU)

CONFIG_NIMBLE_CRYPTO_STACK_MBEDTLS (CONFIG_BT_NIMBLE_CRYPTO_STACK_MBEDTLS)

CONFIG_NIMBLE_DEBUG (CONFIG_BT_NIMBLE_DEBUG)

CONFIG_NIMBLE_GAP_DEVICE_NAME_MAX_LEN (CONFIG_BT_NIMBLE_GAP_DEVICE_NAME_MAX_LEN)

CONFIG_NIMBLE_HS_FLOW_CTRL (CONFIG_BT_NIMBLE_HS_FLOW_CTRL)

CONFIG_NIMBLE_HS_FLOW_CTRL_ITVL (CONFIG_BT_NIMBLE_HS_FLOW_CTRL_ITVL)

CONFIG_NIMBLE_HS_FLOW_CTRL_THRESH (CONFIG_BT_NIMBLE_HS_FLOW_CTRL_THRESH)

CONFIG_NIMBLE_HS_FLOW_CTRL_TX_ON_DISCONNECT (CONFIG_BT_NIMBLE_HS_FLOW_CTRL_TX_ON_DISCONNECT)

CONFIG_NIMBLE_L2CAP_COC_MAX_NUM (CONFIG_BT_NIMBLE_L2CAP_COC_MAX_NUM)

CONFIG_NIMBLE_MAX_BONDS (CONFIG_BT_NIMBLE_MAX_BONDS)

CONFIG_NIMBLE_MAX_CCCDS (CONFIG_BT_NIMBLE_MAX_CCCDS)

CONFIG_NIMBLE_MAX_CONNECTIONS (CONFIG_BT_NIMBLE_MAX_CONNECTIONS)

- CONFIG_NIMBLE_MEM_ALLOC_MODE_INTERNAL
- CONFIG_NIMBLE_MEM_ALLOC_MODE_EXTERNAL
- CONFIG_NIMBLE_MEM_ALLOC_MODE_DEFAULT

CONFIG_NIMBLE_MEM_ALLOC_MODE_INTERNAL

CONFIG_NIMBLE_MEM_ALLOC_MODE_EXTERNAL

CONFIG_NIMBLE_MEM_ALLOC_MODE_DEFAULT

CONFIG_NIMBLE_MESH (CONFIG_BT_NIMBLE_MESH)

CONFIG_NIMBLE_MESH_DEVICE_NAME (CONFIG_BT_NIMBLE_MESH_DEVICE_NAME)

CONFIG_NIMBLE_MESH_FRIEND (CONFIG_BT_NIMBLE_MESH_FRIEND)

CONFIG_NIMBLE_MESH_GATT_PROXY (CONFIG_BT_NIMBLE_MESH_GATT_PROXY)

CONFIG_NIMBLE_MESH_LOW_POWER (CONFIG_BT_NIMBLE_MESH_LOW_POWER)

CONFIG_NIMBLE_MESH_PB_ADV (CONFIG_BT_NIMBLE_MESH_PB_ADV)

CONFIG_NIMBLE_MESH_PB_GATT (CONFIG_BT_NIMBLE_MESH_PB_GATT)

CONFIG_NIMBLE_MESH_PROV (CONFIG_BT_NIMBLE_MESH_PROV)

CONFIG_NIMBLE_MESH_PROXY (CONFIG_BT_NIMBLE_MESH_PROXY)

CONFIG_NIMBLE_MESH_RELAY (CONFIG_BT_NIMBLE_MESH_RELAY)

CONFIG_NIMBLE_NVS_PERSIST (CONFIG_BT_NIMBLE_NVS_PERSIST)

- CONFIG_NIMBLE_PINNED_TO_CORE_0
- CONFIG_NIMBLE_PINNED_TO_CORE_1

CONFIG_NIMBLE_PINNED_TO_CORE_0

CONFIG_NIMBLE_PINNED_TO_CORE_1

CONFIG_NIMBLE_ROLE_BROADCASTER (CONFIG_BT_NIMBLE_ROLE_BROADCASTER)

CONFIG_NIMBLE_ROLE_CENTRAL (CONFIG_BT_NIMBLE_ROLE_CENTRAL)

CONFIG_NIMBLE_ROLE_OBSERVER (CONFIG_BT_NIMBLE_ROLE_OBSERVER)

CONFIG_NIMBLE_ROLE_PERIPHERAL (CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)

CONFIG_NIMBLE_RPA_TIMEOUT (CONFIG_BT_NIMBLE_RPA_TIMEOUT)

CONFIG_NIMBLE_SM_LEGACY (CONFIG_BT_NIMBLE_SM_LEGACY)

CONFIG_NIMBLE_SM_SC (CONFIG_BT_NIMBLE_SM_SC)

CONFIG_NIMBLE_SM_SC_DEBUG_KEYS (CONFIG_BT_NIMBLE_SM_SC_DEBUG_KEYS)

CONFIG_NIMBLE_SVC_GAP_APPEARANCE (CONFIG_BT_NIMBLE_SVC_GAP_APPEARANCE)

CONFIG_NIMBLE_SVC_GAP_DEVICE_NAME (CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME)

CONFIG_NIMBLE_TASK_STACK_SIZE (CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE)

CONFIG_NO_BLOBS (CONFIG_APP_NO_BLOBS)

- CONFIG_OPTIMIZATION_ASSERTIONS_ENABLED
- CONFIG_OPTIMIZATION_ASSERTIONS_SILENT
- CONFIG_OPTIMIZATION_ASSERTIONS_DISABLED

CONFIG_OPTIMIZATION_ASSERTIONS_ENABLED

CONFIG_OPTIMIZATION_ASSERTIONS_SILENT

CONFIG_OPTIMIZATION_ASSERTIONS_DISABLED

- CONFIG_OPTIMIZATION_LEVEL_DEBUG, CONFIG_COMPILER_OPTIMIZATION_LEVEL_DEBUG, CONFIG_COMPILER_OPTIMIZATION_DEFAULT
- CONFIG_OPTIMIZATION_LEVEL_RELEASE, CONFIG_COMPILER_OPTIMIZATION_LEVEL_RELEASE

CONFIG_OPTIMIZATION_LEVEL_DEBUG, CONFIG_COMPILER_OPTIMIZATION_LEVEL_DEBUG, CONFIG_COMPILER_OPTIMIZATION_DEFAULT

CONFIG_OPTIMIZATION_LEVEL_RELEASE, CONFIG_COMPILER_OPTIMIZATION_LEVEL_RELEASE

- CONFIG_OSI_TRACE_LEVEL_NONE
- CONFIG_OSI_TRACE_LEVEL_ERROR
- CONFIG_OSI_TRACE_LEVEL_WARNING
- CONFIG_OSI_TRACE_LEVEL_API
- CONFIG_OSI_TRACE_LEVEL_EVENT
- CONFIG_OSI_TRACE_LEVEL_DEBUG
- CONFIG_OSI_TRACE_LEVEL_VERBOSE

CONFIG_OSI_TRACE_LEVEL_NONE

CONFIG_OSI_TRACE_LEVEL_ERROR

CONFIG_OSI_TRACE_LEVEL_WARNING

CONFIG_OSI_TRACE_LEVEL_API

CONFIG_OSI_TRACE_LEVEL_EVENT

CONFIG_OSI_TRACE_LEVEL_DEBUG

CONFIG_OSI_TRACE_LEVEL_VERBOSE

CONFIG_OTA_ALLOW_HTTP (CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP)

- CONFIG_PAN_TRACE_LEVEL_NONE
- CONFIG_PAN_TRACE_LEVEL_ERROR
- CONFIG_PAN_TRACE_LEVEL_WARNING
- CONFIG_PAN_TRACE_LEVEL_API
- CONFIG_PAN_TRACE_LEVEL_EVENT
- CONFIG_PAN_TRACE_LEVEL_DEBUG
- CONFIG_PAN_TRACE_LEVEL_VERBOSE

CONFIG_PAN_TRACE_LEVEL_NONE

CONFIG_PAN_TRACE_LEVEL_ERROR

CONFIG_PAN_TRACE_LEVEL_WARNING

CONFIG_PAN_TRACE_LEVEL_API

CONFIG_PAN_TRACE_LEVEL_EVENT

CONFIG_PAN_TRACE_LEVEL_DEBUG

CONFIG_PAN_TRACE_LEVEL_VERBOSE

CONFIG_PERIPH_CTRL_FUNC_IN_IRAM (CONFIG_ESP_PERIPH_CTRL_FUNC_IN_IRAM)

CONFIG_POST_EVENTS_FROM_IRAM_ISR (CONFIG_ESP_EVENT_POST_FROM_IRAM_ISR)

CONFIG_POST_EVENTS_FROM_ISR (CONFIG_ESP_EVENT_POST_FROM_ISR)

CONFIG_PPP_CHAP_SUPPORT (CONFIG_LWIP_PPP_CHAP_SUPPORT)

CONFIG_PPP_DEBUG_ON (CONFIG_LWIP_PPP_DEBUG_ON)

CONFIG_PPP_MPPE_SUPPORT (CONFIG_LWIP_PPP_MPPE_SUPPORT)

CONFIG_PPP_MSCHAP_SUPPORT (CONFIG_LWIP_PPP_MSCHAP_SUPPORT)

CONFIG_PPP_NOTIFY_PHASE_SUPPORT (CONFIG_LWIP_PPP_NOTIFY_PHASE_SUPPORT)

CONFIG_PPP_PAP_SUPPORT (CONFIG_LWIP_PPP_PAP_SUPPORT)

CONFIG_PPP_SUPPORT (CONFIG_LWIP_PPP_SUPPORT)

CONFIG_REDUCE_PHY_TX_POWER (CONFIG_ESP_PHY_REDUCE_TX_POWER)

- CONFIG_RFCOMM_TRACE_LEVEL_NONE
- CONFIG_RFCOMM_TRACE_LEVEL_ERROR
- CONFIG_RFCOMM_TRACE_LEVEL_WARNING
- CONFIG_RFCOMM_TRACE_LEVEL_API
- CONFIG_RFCOMM_TRACE_LEVEL_EVENT
- CONFIG_RFCOMM_TRACE_LEVEL_DEBUG
- CONFIG_RFCOMM_TRACE_LEVEL_VERBOSE

CONFIG_RFCOMM_TRACE_LEVEL_NONE

CONFIG_RFCOMM_TRACE_LEVEL_ERROR

CONFIG_RFCOMM_TRACE_LEVEL_WARNING

CONFIG_RFCOMM_TRACE_LEVEL_API

CONFIG_RFCOMM_TRACE_LEVEL_EVENT

CONFIG_RFCOMM_TRACE_LEVEL_DEBUG

CONFIG_RFCOMM_TRACE_LEVEL_VERBOSE

CONFIG_SEMIHOSTFS_MAX_MOUNT_POINTS (CONFIG_VFS_SEMIHOSTFS_MAX_MOUNT_POINTS)

- CONFIG_SMP_TRACE_LEVEL_NONE
- CONFIG_SMP_TRACE_LEVEL_ERROR
- CONFIG_SMP_TRACE_LEVEL_WARNING
- CONFIG_SMP_TRACE_LEVEL_API
- CONFIG_SMP_TRACE_LEVEL_EVENT
- CONFIG_SMP_TRACE_LEVEL_DEBUG
- CONFIG_SMP_TRACE_LEVEL_VERBOSE

CONFIG_SMP_TRACE_LEVEL_NONE

CONFIG_SMP_TRACE_LEVEL_ERROR

CONFIG_SMP_TRACE_LEVEL_WARNING

CONFIG_SMP_TRACE_LEVEL_API

CONFIG_SMP_TRACE_LEVEL_EVENT

CONFIG_SMP_TRACE_LEVEL_DEBUG

CONFIG_SMP_TRACE_LEVEL_VERBOSE

CONFIG_SMP_SLAVE_CON_PARAMS_UPD_ENABLE (CONFIG_BT_SMP_SLAVE_CON_PARAMS_UPD_ENABLE)

CONFIG_SPIRAM_ALLOW_STACK_EXTERNAL_MEMORY (CONFIG_FREERTOS_TASK_CREATE_ALLOW_EXT_MEM)

CONFIG_SPI_FLASH_32BIT_ADDR_ENABLE (CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH)

CONFIG_SPI_FLASH_QUAD_32BIT_ADDR_ENABLE (CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH)

- CONFIG_SPI_FLASH_WRITING_DANGEROUS_REGIONS_ABORTS
- CONFIG_SPI_FLASH_WRITING_DANGEROUS_REGIONS_FAILS
- CONFIG_SPI_FLASH_WRITING_DANGEROUS_REGIONS_ALLOWED

CONFIG_SPI_FLASH_WRITING_DANGEROUS_REGIONS_ABORTS

CONFIG_SPI_FLASH_WRITING_DANGEROUS_REGIONS_FAILS

CONFIG_SPI_FLASH_WRITING_DANGEROUS_REGIONS_ALLOWED

- CONFIG_STACK_CHECK_NONE
- CONFIG_STACK_CHECK_NORM
- CONFIG_STACK_CHECK_STRONG
- CONFIG_STACK_CHECK_ALL

CONFIG_STACK_CHECK_NONE

CONFIG_STACK_CHECK_NORM

CONFIG_STACK_CHECK_STRONG

CONFIG_STACK_CHECK_ALL

CONFIG_SUPPORT_TERMIOS (CONFIG_VFS_SUPPORT_TERMIOS)

CONFIG_SUPPRESS_SELECT_DEBUG_OUTPUT (CONFIG_VFS_SUPPRESS_SELECT_DEBUG_OUTPUT)

CONFIG_SW_COEXIST_ENABLE (CONFIG_ESP_COEX_SW_COEXIST_ENABLE)

CONFIG_SYSTEM_EVENT_QUEUE_SIZE (CONFIG_ESP_SYSTEM_EVENT_QUEUE_SIZE)

CONFIG_SYSTEM_EVENT_TASK_STACK_SIZE (CONFIG_ESP_SYSTEM_EVENT_TASK_STACK_SIZE)

CONFIG_TASK_WDT (CONFIG_ESP_TASK_WDT_INIT)

CONFIG_TASK_WDT_CHECK_IDLE_TASK_CPU0 (CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU0)

CONFIG_TASK_WDT_CHECK_IDLE_TASK_CPU1 (CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU1)

CONFIG_TASK_WDT_PANIC (CONFIG_ESP_TASK_WDT_PANIC)

CONFIG_TASK_WDT_TIMEOUT_S (CONFIG_ESP_TASK_WDT_TIMEOUT_S)

CONFIG_TCPIP_RECVMBOX_SIZE (CONFIG_LWIP_TCPIP_RECVMBOX_SIZE)

- CONFIG_TCPIP_TASK_AFFINITY_NO_AFFINITY
- CONFIG_TCPIP_TASK_AFFINITY_CPU0
- CONFIG_TCPIP_TASK_AFFINITY_CPU1

CONFIG_TCPIP_TASK_AFFINITY_NO_AFFINITY

CONFIG_TCPIP_TASK_AFFINITY_CPU0

CONFIG_TCPIP_TASK_AFFINITY_CPU1

CONFIG_TCPIP_TASK_STACK_SIZE (CONFIG_LWIP_TCPIP_TASK_STACK_SIZE)

CONFIG_TCP_MAXRTX (CONFIG_LWIP_TCP_MAXRTX)

CONFIG_TCP_MSL (CONFIG_LWIP_TCP_MSL)

CONFIG_TCP_MSS (CONFIG_LWIP_TCP_MSS)

- CONFIG_TCP_OVERSIZE_MSS
- CONFIG_TCP_OVERSIZE_QUARTER_MSS
- CONFIG_TCP_OVERSIZE_DISABLE

CONFIG_TCP_OVERSIZE_MSS

CONFIG_TCP_OVERSIZE_QUARTER_MSS

CONFIG_TCP_OVERSIZE_DISABLE

CONFIG_TCP_QUEUE_OOSEQ (CONFIG_LWIP_TCP_QUEUE_OOSEQ)

CONFIG_TCP_RECVMBOX_SIZE (CONFIG_LWIP_TCP_RECVMBOX_SIZE)

CONFIG_TCP_SND_BUF_DEFAULT (CONFIG_LWIP_TCP_SND_BUF_DEFAULT)

CONFIG_TCP_SYNMAXRTX (CONFIG_LWIP_TCP_SYNMAXRTX)

CONFIG_TCP_WND_DEFAULT (CONFIG_LWIP_TCP_WND_DEFAULT)

CONFIG_TIMER_QUEUE_LENGTH (CONFIG_FREERTOS_TIMER_QUEUE_LENGTH)

CONFIG_TIMER_TASK_PRIORITY (CONFIG_FREERTOS_TIMER_TASK_PRIORITY)

CONFIG_TIMER_TASK_STACK_DEPTH (CONFIG_FREERTOS_TIMER_TASK_STACK_DEPTH)

CONFIG_TIMER_TASK_STACK_SIZE (CONFIG_ESP_TIMER_TASK_STACK_SIZE)

CONFIG_UDP_RECVMBOX_SIZE (CONFIG_LWIP_UDP_RECVMBOX_SIZE)

CONFIG_WARN_WRITE_STRINGS (CONFIG_COMPILER_WARN_WRITE_STRINGS)

CONFIG_WPA_11KV_SUPPORT (CONFIG_ESP_WIFI_11KV_SUPPORT)

CONFIG_WPA_11R_SUPPORT (CONFIG_ESP_WIFI_11R_SUPPORT)

CONFIG_WPA_DEBUG_PRINT (CONFIG_ESP_WIFI_DEBUG_PRINT)

CONFIG_WPA_DPP_SUPPORT (CONFIG_ESP_WIFI_DPP_SUPPORT)

CONFIG_WPA_MBEDTLS_CRYPTO (CONFIG_ESP_WIFI_MBEDTLS_CRYPTO)

CONFIG_WPA_MBEDTLS_TLS_CLIENT (CONFIG_ESP_WIFI_MBEDTLS_TLS_CLIENT)

CONFIG_WPA_MBO_SUPPORT (CONFIG_ESP_WIFI_MBO_SUPPORT)

CONFIG_WPA_SCAN_CACHE (CONFIG_ESP_WIFI_SCAN_CACHE)

CONFIG_WPA_SUITE_B_192 (CONFIG_ESP_WIFI_SUITE_B_192)

CONFIG_WPA_WAPI_PSK (CONFIG_ESP_WIFI_WAPI_PSK)

CONFIG_WPA_WPS_SOFTAP_REGISTRAR (CONFIG_ESP_WIFI_WPS_SOFTAP_REGISTRAR)

CONFIG_WPA_WPS_STRICT (CONFIG_ESP_WIFI_WPS_STRICT)

- Thank you! We received your feedback.
- If you have any comments, fill in Espressif Documentation Feedback Form.

- We value your feedback.
- Let us know how we can improve this page by filling in Espressif Documentation Feedback Form.

