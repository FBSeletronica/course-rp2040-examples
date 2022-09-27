# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/fabio/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(adc_dma C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(adc_dma adc_dma.c )

pico_set_program_name(adc_dma "adc_dma")
pico_set_program_version(adc_dma "0.1")

pico_enable_stdio_uart(adc_dma 0)
pico_enable_stdio_usb(adc_dma 1)

# Add the standard library to the build
target_link_libraries(adc_dma pico_stdlib hardware_adc hardware_dma)

pico_add_extra_outputs(adc_dma)

