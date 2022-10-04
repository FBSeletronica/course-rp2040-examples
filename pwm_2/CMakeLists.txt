# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CURRENT_PROJECT_VERSION "0.1")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "../../../pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pwm_2 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.c)

pico_set_program_name(${PROJECT_NAME} ${PROJECT_NAME})
pico_set_program_version(${PROJECT_NAME} ${CURRENT_PROJECT_VERSION})

pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)

# Add the standard library to the build
target_link_libraries(${PROJECT_NAME} 
                        pico_stdlib
                        hardware_pwm
                        hardware_gpio
)
pico_add_extra_outputs(${PROJECT_NAME})

