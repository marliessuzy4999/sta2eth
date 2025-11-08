# ESP32-P4 + ESP32-C6 sta2eth bridge components

idf_component_register(
    SRCS 
        "sta2eth_main.c"
        "ethernet_iface.c"
        "wifi_remote_sta.c"
        "wifi_config_portal.c"
    PRIV_REQUIRES 
        esp_wifi_remote
        esp_hosted
        esp_timer
        esp_eth
        esp_http_server
        nvs_flash
        esp_driver_gpio
    INCLUDE_DIRS ""
)
