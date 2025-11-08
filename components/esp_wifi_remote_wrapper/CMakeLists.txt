idf_component_register(
    SRCS "wifi_remote_wrapper.c"
         "packet_buffer_pool.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_wifi esp_netif esp_event driver nvs_flash
    PRIV_REQUIRES esp_timer
)
