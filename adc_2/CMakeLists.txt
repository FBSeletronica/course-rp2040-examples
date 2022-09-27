# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/fabio/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(adc_2 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(adc_2 adc_2.c )

pico_set_program_name(adc_2 "adc_2")
pico_set_program_version(adc_2 "0.1")

pico_enable_stdio_uart(adc_2 0)
pico_enable_stdio_usb(adc_2 1)

# Add the standard library to the build
target_link_libraries(adc_2 pico_stdlib hardware_adc)

pico_add_extra_outputs(adc_2)

