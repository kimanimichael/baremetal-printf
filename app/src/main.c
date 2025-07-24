#include <stdbool.h>
#include <stdint.h>
#include "../include/bsp.h"
#include "../../common/include/core/uart.h"
#include <stdio.h>

int __io_putchar(int data) {
	uart_write((uint8_t *)&data, 1);
	return data;
}

int main(){
	BSP_init();
	uart_setup();

	uint32_t start = BSP_Tickr();
	while (true){
		if ((BSP_Tickr() - start) > 1000) {
			BSP_blueLedToggle();
			printf("LED toggled\r\n");
			start = BSP_Tickr();
		}
		for (int i = 0; i<11; i++) {
		  printf("Row: %d\n\r", i);
		  BSP_Delay(500);
	  	}
		printf("\ec");
		printf("\n\n\n\r");
		BSP_Delay(2000);
	}
}

