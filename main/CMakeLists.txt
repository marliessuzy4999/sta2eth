# Minimal sta2eth test (based on eth2ap example)
# Simplified version for driver testing

idf_component_register(
    SRCS 
        "sta2eth_minimal.c"
        "ethernet_iface.c"
    PRIV_REQUIRES 
        esp_wifi
        esp_wifi_remote
        esp_hosted
        esp_wifi_remote_wrapper
        esp_eth
        nvs_flash
        esp_driver_gpio
    INCLUDE_DIRS ""
)
