#ifndef __BSP__H
#define __BSP__H

//Base RCC register 0x4002 3800 + offset 0x30 to find RCC_AHB1ENR
#define RCC_AHB1ENR (*((unsigned int *)(0x40023830)))

//Base GPIOB register 0x4002 0400 + offset 0x00 to find GPIOB_MODER
#define GPIOB_MODER (*((unsigned int *)(0x40020400)))

//Base GPIOB register 0x4002 0400 + offset 0x14 to find GPIOx_ODR
#define GPIOx_ODR (*((unsigned int *)(0x40020414)))

//Base GPIOA register 0x4002 0000 + offset 0x00 to find GPIOA_MODER
#define GPIOA_MODER (*((unsigned int *)(0x40020000)))

//Base GPIOA register 0x4002 0000 + offset 0x14 to find GPIOx_ODR
#define GPIOA_ODR (*((unsigned int *)(0x40020014)))

/**
 * @brief Initialize board peripherals
 * @author @mikael
*/
void BSP_init();
/**
 * @brief Initialize all onboard leds
 * @author @mikael
*/
void BSP_ledInit();

/**
 * @brief Switches on the blue LED
 * @author @mikael
*/
void BSP_blueLedOn();

/**
 * @brief Toggles the blue LED
 * @author @mikael
*/
void BSP_blueLedToggle();

int main();

#endif
