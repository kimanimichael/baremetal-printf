# BAREMETAL ARM PRINTF
This is a bring up of a simple baremetal application using STM32 upto using printf for debugging

## Hardware Requirements

1. [NUCLEO-F429ZI board](https://www.st.com/en/evaluation-tools/nucleo-f429zi.html#samplebuy-scroll)
2. USB-X to USB 2.0 Micro B cable

Although this project is built for the NUCLEO-F429ZI development board, users can modify it, if they can, to fit other development boards


## Installation
### Prerequisites
The following are required to build this program:
1. [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm)
2. [Python](https://www.python.org/downloads/)

The following are required to flash this program onto a microcontroller
1. [stlink](https://github.com/stlink-org/stlink)

## Build
Ensure all prerequisites are met.

If building for the first time, clone the project and then from the root of the repository run the following command to give the build shell script file permission ot run:

```console
chmod + x build.sh
```
The above command should only require to be run once.

Run the following command to build:
```console
./build.sh
```
## Build and Flash

If building and flashing for the first time, clone the project and then from the root of the repository run the following command to give the build shell script file permission ot run:

```console
chmod + x build_flash.sh
```
The above command should only require to be run once.


Run the following command to build and flash:
```console
./build_flash.sh
```

