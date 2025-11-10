# sta2eth L2 Bridge using Official Bridge API
# Uses esp_netif_br_glue for stable L2 bridging

idf_component_register(
    SRCS 
        "sta2eth_bridge.c"
        "wifi_config_portal.c"
        "c6_ota.c"
    PRIV_REQUIRES 
        esp_wifi
        esp_wifi_remote
        esp_hosted
        esp_eth
        esp_netif
        nvs_flash
        esp_driver_gpio
        esp_http_server
        protocomm
        wifi_provisioning
        ethernet_init
    INCLUDE_DIRS ""
)
