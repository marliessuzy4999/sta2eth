# Full sta2eth L2 Bridge
# Complete version with all components

idf_component_register(
    SRCS 
        "sta2eth_main.c"
        "ethernet_iface.c"
        "wifi_remote_sta.c"
        "wifi_config_portal.c"
        "c6_ota.c"
    PRIV_REQUIRES 
        esp_wifi
        esp_wifi_remote
        esp_hosted
        esp_wifi_remote_wrapper
        esp_eth
        esp_netif
        nvs_flash
        esp_driver_gpio
        esp_http_server
        protocomm
        wifi_provisioning
    INCLUDE_DIRS ""
)
