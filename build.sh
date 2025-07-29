cmake -S ./bootloader/  -B bootloader/cmake-build/ -G Ninja
cmake --build bootloader/cmake-build/

cmake -S ./app/  -B app/cmake-build/ -G Ninja
cmake --build app/cmake-build/