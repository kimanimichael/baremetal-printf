#include "../include/bsp.h"

void BSP_init() {
    
    BSP_ledInit();
}

void BSP_ledInit() {
    //Bitwise OR the second & first bit of RCC_AHB1ENR with 1 to enable GPIOB_EN CLOCK and GPIOA_EN CLOCK
    RCC_AHB1ENR |= (0b01 << 1) | (0b01 << 0);
    //Bitwise AND the 16th bit and 2nd bit of GPIOB_MODER with 0 - CONFIG PB7 & PB0 & PB14 & PB1 as output
    GPIOB_MODER &= (~(0b01 << 15) | ~(0b01 << 1) | ~(0b01 << 29) | ~(0b01 << 3));
    //Bitwise OR the 15th bit and 1st of GPIOB_MODER with 1 - CONFIG PB7 & PB0 & PB14 & PB1 as output
    GPIOB_MODER |= ((0b01 << 14) | (0b01 << 0) | (0b01 << 28) | (0b01 << 2));
    /* Bitwise AND the 15th of GPIOA_MODER with 0 */
    /* @TODO Investigate why this bricks flashing with stlink */
    // GPIOA_MODER &= (0b00 << 25);
    /* Bite wise OR the 14th bit of GPIOA_MODER with 1*/
    GPIOA_MODER |= (0b01 << 24);
}

void BSP_blueLedOn() {
    GPIOx_ODR |= (0b01 << 7);
}

void BSP_blueLedToggle() {
    GPIOx_ODR ^= (0b01 << 7);
}

