#include <stdbool.h>
#include <stdint.h>
#include "../include/bsp.h"
#include "../../common/include/core/uart.h"

static uint8_t tiny_strlen(const char *s) {
    uint8_t len = 0;
    while (*s++ && (len < UINT8_MAX)) {
        len++;
    }
    return len;
}

static void mk_logging(const char * log) {
	uart_write((uint8_t *)log, tiny_strlen(log));
	uart_write((uint8_t *)"\r\n", 2);  
}

int main(){
	BSP_init();
	uart_setup();

	uint32_t start = BSP_Tickr();
	while (true){
		if ((BSP_Tickr() - start) > 1000) {
			BSP_blueLedToggle();
			mk_logging("LED toggled");
			start = BSP_Tickr();
		}

		if(uart_data_available()) {
		uint8_t data = uart_read_byte();
		uart_write_byte(data);
	}
	}
}

