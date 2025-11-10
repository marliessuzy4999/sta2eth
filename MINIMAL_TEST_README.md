# Minimal sta2eth Test Branch

This branch contains a simplified sta2eth implementation based directly on the eth2ap example pattern.

## Purpose

To isolate and test whether issues are caused by:
- Driver/hardware problems
- Code complexity in the full sta2eth implementation

## Key Simplifications

1. **Hardcoded WiFi credentials**:
   - SSID: `xinxin`
   - Password: `19840226`

2. **No config portal, OTA, or monitoring** - Just pure bridging

3. **Matches eth2ap pattern exactly**:
   - FreeRTOS queue (40 depth)
   - Retry loop with progressive timeout (timeout += 2ms)
   - Zero-copy for Ethernet RX
   - Direct WiFi→Eth transmission (no queue)
   - 2KB task stack
   - Priority: tskIDLE_PRIORITY + 2

4. **Promiscuous mode enabled** on Ethernet interface

## What's Included

- `main/sta2eth_minimal.c` - Complete minimal implementation (~250 lines)
- `main/ethernet_iface.c` - Ethernet initialization (from original)
- No MAC spoofing, no DHCP modification, no complex buffer management

## Build and Flash

```bash
idf.py build
idf.py flash monitor
```

## Expected Behavior

1. Boots and initializes WiFi + Ethernet
2. Connects to WiFi AP "xinxin"
3. Waits for Ethernet link
4. Bridges packets between Ethernet and WiFi with retry logic

## Testing

Connect an Ethernet device and observe:
- Can the device get DHCP?
- Can it access the internet through WiFi?
- Are there any "send packet failed" errors?
- Does it run stably for extended periods?

## Comparison

If this minimal version works well but the full version has issues, the problem is in the additional complexity (MAC spoofing, DHCP modification, buffer management, etc.).

If this minimal version also has issues, the problem is more likely driver/hardware related.
