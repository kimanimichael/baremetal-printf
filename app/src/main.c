#include <stdbool.h>
#include <stdint.h>
#include "../include/bsp.h"

int main(){
	BSP_init();
	while (true){
		BSP_blueLedToggle();
		BSP_Delay(1000);
	}
}

