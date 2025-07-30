cmake -S ./bootloader/  -B bootloader/cmake-build/ -G Ninja
cmake --build bootloader/cmake-build/

cmake -S .  -B cmake-build/ -G Ninja
cmake --build cmake-build/

st-flash write cmake-build/baremetal_app.bin 0x8000000

