# PSRAM Configuration Rationale for sta2eth

## Overview

This document explains the PSRAM configuration options added to `sdkconfig.defaults.esp32p4` and the rationale behind each choice.

## Project Requirements

The sta2eth project has unique PSRAM requirements due to:
- **Speed mismatch**: ESP32-P4 Ethernet (100Mbps) is faster than ESP32-C6 WiFi/SDIO (~50Mbps)
- **Large buffers**: 1.6MB PSRAM buffer pool (1024 buffers × 1600 bytes)
- **Critical allocation**: WiFi/LWIP buffers also allocated in PSRAM
- **Performance**: 200MHz PSRAM for maximum bandwidth

## Configuration Options Added

### 1. CONFIG_SPIRAM_MODE_HEX=y
**Purpose**: Explicitly set 16-line (hexadecimal) mode for PSRAM

**Rationale**:
- ESP32-P4 supports 16-line mode PSRAM for maximum bandwidth
- Provides higher throughput for large buffer operations
- Makes the configuration explicit and clear

**Impact**: Better performance for the 1.6MB packet buffer pool operations

---

### 2. CONFIG_SPIRAM_BOOT_INIT=y
**Purpose**: Initialize PSRAM during system startup

**Rationale**:
- **CRITICAL**: Ensures PSRAM is available before any buffer allocations
- The packet buffer pool is allocated early in the boot process
- Without this, PSRAM might not be initialized in time
- Also enables memory protection for PSRAM regions

**Impact**: 
- Guarantees PSRAM availability for early allocations
- Prevents allocation failures during initialization
- Automatically enables CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION

---

### 3. CONFIG_SPIRAM_MALLOC_RESERVE_INTERNAL=32768
**Purpose**: Reserve 32KB of internal RAM for DMA and critical operations

**Rationale**:
- When PSRAM fills up, internal RAM can be exhausted
- DMA operations require internal RAM (cannot use PSRAM)
- Ethernet/SDIO DMA buffers need guaranteed allocation
- 32KB is sufficient for typical DMA buffer requirements

**Impact**:
- Prevents DMA allocation failures under memory pressure
- Ensures critical system operations continue when PSRAM is full
- Improves system stability

**Value Choice**: 32KB (32768 bytes) is a balanced value:
- Large enough for typical DMA needs
- Small enough to not waste internal RAM

---

### 4. CONFIG_SPIRAM_MALLOC_ALWAYSINTERNAL=16384
**Purpose**: Allocate small objects (<16KB) in internal RAM

**Rationale**:
- Small, frequently-accessed data benefits from faster internal RAM
- PSRAM access is slower than internal RAM
- Reduces PSRAM bus contention
- Optimizes overall performance

**Impact**:
- Faster access for small objects (task stacks, small buffers, etc.)
- Better cache utilization
- Reduced PSRAM bandwidth usage for small allocations

**Value Choice**: 16KB (16384 bytes) threshold:
- Standard system allocations (stacks, control structures) stay in internal RAM
- Large packet buffers (1600 bytes each) go to PSRAM
- Good balance between speed and PSRAM utilization

---

### 5. # CONFIG_SPIRAM_MEMTEST is not set
**Purpose**: Disable PSRAM memory test during boot

**Rationale**:
- Memory test adds ~1 second to boot time
- Not necessary in production after testing
- Faster boot improves user experience

**Impact**: Boot time reduced by ~1 second

**Note**: Can be re-enabled during development/debugging by commenting out this line

---

## Options Considered but NOT Added

### CONFIG_SPIRAM_XIP_FROM_PSRAM (Execute in Place)
**Why NOT added**:
- Moves code execution from flash to PSRAM
- Would increase PSRAM bus load significantly
- Could interfere with packet buffer operations
- Uncertain performance benefit for this use case
- **Risk too high for the potential benefit**

---

### CONFIG_SPIRAM_ECC_ENABLE (Error Correction)
**Why NOT added**:
- Uses 1/8 of PSRAM for error correction codes
- Reduces 32MB PSRAM to ~28MB usable
- May not leave enough space for 1.6MB buffer pool + WiFi buffers + growth
- **Need maximum PSRAM capacity for buffering**

ESP32-P4 PSRAM is generally reliable, and the project can tolerate occasional errors better than reduced capacity.

---

### CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION
**Why NOT added explicitly**:
- Automatically enabled when CONFIG_SPIRAM_BOOT_INIT=y
- No need to set it explicitly
- Would be redundant

---

### CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY
**Why NOT added**:
- Allows placing uninitialized variables in PSRAM
- Not used by this project
- No benefit for our use case

---

### CONFIG_SPIRAM_BOOT_HW_INIT
**Why NOT added**:
- Lower-level option that only initializes hardware
- CONFIG_SPIRAM_BOOT_INIT includes this functionality plus more
- Using BOOT_INIT is more comprehensive

---

### CONFIG_SPIRAM_IGNORE_NOTFOUND
**Why NOT added**:
- Would allow boot to continue if PSRAM is not found
- This project REQUIRES PSRAM to function
- Better to fail fast and clearly if PSRAM is missing
- Helps catch hardware issues early

---

## Summary

### Added (Critical for this project):
1. ✅ CONFIG_SPIRAM_MODE_HEX=y - Maximum bandwidth
2. ✅ CONFIG_SPIRAM_BOOT_INIT=y - Early initialization
3. ✅ CONFIG_SPIRAM_MALLOC_RESERVE_INTERNAL=32768 - DMA buffer protection
4. ✅ CONFIG_SPIRAM_MALLOC_ALWAYSINTERNAL=16384 - Performance optimization
5. ✅ # CONFIG_SPIRAM_MEMTEST is not set - Faster boot

### Not Added (Good reasons):
- ❌ CONFIG_SPIRAM_XIP_FROM_PSRAM - Too risky
- ❌ CONFIG_SPIRAM_ECC_ENABLE - Reduces capacity
- ❌ CONFIG_SPIRAM_PRE_CONFIGURE_MEMORY_PROTECTION - Auto-enabled
- ❌ CONFIG_SPIRAM_ALLOW_NOINIT_SEG_EXTERNAL_MEMORY - Not needed
- ❌ CONFIG_SPIRAM_BOOT_HW_INIT - BOOT_INIT is better
- ❌ CONFIG_SPIRAM_IGNORE_NOTFOUND - Want to fail if missing

## Expected Benefits

After these changes, the system should have:
1. **More reliable PSRAM initialization** - BOOT_INIT ensures early availability
2. **Better DMA stability** - Reserved internal RAM prevents allocation failures
3. **Improved performance** - Small allocations stay in fast internal RAM
4. **Faster boot** - Disabled memory test
5. **Maximum capacity** - No ECC overhead, all 32MB available

## Testing Recommendations

After applying these changes:
1. Verify boot completes successfully with PSRAM detection messages
2. Check available PSRAM with `heap_caps_get_free_size(MALLOC_CAP_SPIRAM)`
3. Monitor internal RAM usage under load
4. Test packet buffer allocation (1.6MB pool should succeed)
5. Run throughput tests (Ethernet ↔ WiFi)
6. Monitor for any DMA allocation failures
7. Check boot time improvement (should be ~1 second faster)

## References

- ESP-IDF PSRAM Documentation: [Kconfig Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32p4/api-reference/kconfig-reference.html)
- Project Summary: [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)
- Kconfig Verification: [KCONFIG_VERIFICATION.md](KCONFIG_VERIFICATION.md)
