# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/fabio/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(gpio_input C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(gpio_input gpio_input.c )

pico_set_program_name(gpio_input "gpio_iput")
pico_set_program_version(gpio_input "0.1")

pico_enable_stdio_uart(gpio_input 0)
pico_enable_stdio_usb(gpio_input 1)

# Add the standard library to the build
target_link_libraries(gpio_input pico_stdlib)

pico_add_extra_outputs(gpio_input)

