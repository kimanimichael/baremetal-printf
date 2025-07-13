#include <stdbool.h>
#include <stdint.h>
#include "../include/bsp.h"

int main(){
	BSP_init();
while (true){
	BSP_blueLedToggle();
	for (int i = 0; i < 100000; i++) {
	
	}
}
}
