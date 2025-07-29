cmake_minimum_required(VERSION 3.19.0 FATAL_ERROR)

set(CMAKE_ASM_COMPILER "arm-none-eabi-as")
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_LINKER "arm-none-eabi-gcc")

set (APP_TARGET baremetal_printf)
