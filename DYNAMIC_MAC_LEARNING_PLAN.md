# Dynamic MAC Learning Implementation Plan

## User Requirements

Implement a new initialization sequence:
1. Initialize Ethernet (using IP101 PHY)
2. Wait for Ethernet link up
3. Wait for first Ethernet packet from PC
4. Learn PC's MAC address from the packet
5. Initialize C6 WiFi with static IP
6. Set C6 WiFi MAC = PC MAC
7. Connect WiFi to AP (with static IP)
8. Create bridge after WiFi connection succeeds
9. Enable transparent packet forwarding (including DHCP)

## Implementation Strategy

### Phase 1: Ethernet Initialization & MAC Learning
- Initialize Ethernet with IP101 PHY
- Set Ethernet to promiscuous mode immediately
- Register packet receive callback to capture first packet
- Extract source MAC from first Ethernet frame
- Store PC MAC address

### Phase 2: WiFi Initialization with PC MAC
- Initialize esp_wifi_remote
- Set WiFi STA MAC = PC MAC (learned from Ethernet)
- Configure WiFi with static link-local IP (169.254.0.2)
- Connect to WiFi AP

### Phase 3: Bridge Creation
- Wait for WiFi connection success
- Create bridge netif
- Add Ethernet and WiFi ports to bridge
- Start bridge operation

### Phase 4: Packet Forwarding
- Bridge API handles all L2 forwarding automatically
- FDB learns MAC-to-port mappings
- Transparent DHCP forwarding works because WiFi MAC = PC MAC

## Key Changes from Current Implementation

**Current:**
- Bridge created immediately at startup
- All MACs set to Ethernet's default MAC
- No dynamic learning

**New:**
- Ethernet initialized first, waits for packet
- MAC learned dynamically from PC
- WiFi initialized after MAC learning
- Bridge created after WiFi connects
- Truly transparent for single PC scenario

## Code Structure

```c
// Global state
static uint8_t s_pc_mac[6] = {0};
static bool s_mac_learned = false;
static bool s_wifi_connected = false;

// Initialization sequence
void app_main(void) {
    // 1. Init Ethernet
    init_ethernet();
    
    // 2. Wait for MAC learning
    wait_for_pc_mac();
    
    // 3. Init WiFi with PC MAC
    init_wifi_with_pc_mac();
    
    // 4. Wait for WiFi connection
    wait_for_wifi_connected();
    
    // 5. Create bridge
    create_bridge();
}
```

## Benefits

1. **True Transparency**: WiFi MAC = PC MAC means WiFi can receive PC's packets
2. **Single Device Optimization**: Perfect for 1 PC + 1 WiFi scenario
3. **DHCP Works**: PC can get DHCP from router because WiFi accepts dst=PC_MAC
4. **Official Bridge API**: Still uses esp_netif_br_glue for stability

## Limitations

- Still only supports single PC (one MAC address)
- PC must send a packet before bridge becomes active
- Changing PC requires restart or re-learning

## Testing Plan

1. Connect single PC to Ethernet
2. Verify MAC learning from first packet
3. Verify WiFi connects with PC's MAC
4. Verify bridge creation
5. Verify PC can get DHCP IP
6. Verify bidirectional network connectivity
