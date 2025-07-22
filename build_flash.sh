arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -c -o bootloader/build/bootloader.o bootloader/src/bootloader.c
arm-none-eabi-ld -Map bootloader/build/bootloader.map -T bootloader/bootloader.ld -o bootloader/build/bootloader.elf bootloader/build/bootloader.o
arm-none-eabi-objcopy -O binary bootloader/build/bootloader.elf --pad-to=0x8008000 --gap-fill=0Xff bootloader/build/bootloader.bin

arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard --specs=nano.specs -mfpu=fpv4-sp-d16 -c -o app/build/system_stm32f4xx.o common/core/system_stm32f4xx.c
arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard --specs=nano.specs -mfpu=fpv4-sp-d16 -c -o app/build/bsp.o app/src/bsp.c
arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard --specs=nano.specs -mfpu=fpv4-sp-d16 -c -o app/build/main.o app/src/main.c
arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard --specs=nano.specs -mfpu=fpv4-sp-d16 -c -o app/build/startup.o app/src/startup.c
arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard --specs=nano.specs -mfpu=fpv4-sp-d16 -c -o app/build/syscalls.o app/src/syscalls.c
arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -c -o app/build/bootloader.o app/src/bootloader.S
arm-none-eabi-gcc -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard --specs=nano.specs -mfpu=fpv4-sp-d16 -c -o app/build/uart.o common/core/uart.c
# arm-none-eabi-ld --specs=nosys.specs -Map app/build/main.map -T app/app.ld -o app/build/main.elf app/build/bootloader.o app/build/startup.o app/build/bsp.o app/build/system_stm32f4xx.o app/build/uart.o app/build/main.o

arm-none-eabi-gcc -o app/build/main.elf app/build/bootloader.o app/build/startup.o app/build/syscalls.o app/build/bsp.o app/build/system_stm32f4xx.o app/build/uart.o app/build/main.o   -mcpu=cortex-m4 -T app/app.ld --specs=nosys.specs -Wl,-Map=app/build/main.map -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group

arm-none-eabi-objcopy -O binary app/build/main.elf app/build/main.bin

st-flash write app/build/main.bin 0x8000000

