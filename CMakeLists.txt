# ESP32-P4 sta2eth Bridge with ESP32-C6 via SDIO
cmake_minimum_required(VERSION 3.16)

# Set the target to ESP32-P4
set(IDF_TARGET esp32p4)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(sta2eth_p4_c6)
