#include <stdbool.h>
#include <stdint.h>
#include "../include/bsp.h"
#include "../../common/include/core/uart.h"

int main(){
	BSP_init();
	uart_setup();
	while (true){
		BSP_blueLedToggle();
		BSP_Delay(100);

		if(uart_data_available()) {
		uint8_t data = uart_read_byte();
		uart_write_byte(data);
	}
	}
}

