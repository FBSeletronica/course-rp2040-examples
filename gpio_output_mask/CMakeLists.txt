# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(gpio_output_mask C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(gpio_output_mask gpio_output_mask.c )

pico_set_program_name(gpio_output_mask "gpio_output_mask")
pico_set_program_version(gpio_output_mask "0.1")

pico_enable_stdio_uart(gpio_output_mask 0)
pico_enable_stdio_usb(gpio_output_mask 1)

# Add the standard library to the build
target_link_libraries(gpio_output_mask pico_stdlib)

pico_add_extra_outputs(gpio_output_mask)

