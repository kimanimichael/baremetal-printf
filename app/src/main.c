#include <stdbool.h>
#include <stdint.h>
#include "../include/bsp.h"
#include "../../common/include/core/uart.h"

int main(){
	BSP_init();
	uart_setup();

	uint32_t start = BSP_Tickr();
	while (true){
		if ((BSP_Tickr() - start) > 100) {
			BSP_blueLedToggle();
			start = BSP_Tickr();
		}

		if(uart_data_available()) {
		uint8_t data = uart_read_byte();
		uart_write_byte(data);
	}
	}
}

