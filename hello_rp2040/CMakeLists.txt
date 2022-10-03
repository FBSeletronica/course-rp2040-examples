# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "../../../pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(hello_rp2040 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(hello_rp2040 hello_rp2040.c )

pico_set_program_name(hello_rp2040 "hello_rp2040")
pico_set_program_version(hello_rp2040 "0.1")

pico_enable_stdio_uart(hello_rp2040 0)
pico_enable_stdio_usb(hello_rp2040 1)

# Add the standard library to the build
target_link_libraries(hello_rp2040 pico_stdlib)

pico_add_extra_outputs(hello_rp2040)

