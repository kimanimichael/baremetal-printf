#include <inttypes.h>
#include "../include/bsp.h"

extern int _stext;
extern int _sdata;
extern int _etext;
extern int _edata;
extern int _sbss;
extern int _ebss;

void NMI_Handler(void);
void HardFault_Handler(void);
void Reset_Handler(void);

void SystemInit(void);

unsigned int *vectors[] __attribute__((section(".vectors"))) = 
{
    (unsigned int *)0x20030000, //Pointer to the top of our stack memory
    (unsigned int *)Reset_Handler, // Pointer to our reset handler - also our startup code
    (unsigned int *)NMI_Handler, //NMI
    (unsigned int *)HardFault_Handler, //HardFault
};

void Reset_Handler(void) {
	SystemInit();
	SystemCoreClockUpdate();
	/* Set the vector table base address */
	uint32_t *vector_table = (uint32_t *) &_stext;
	uint32_t *vtor = (uint32_t *)0xE000ED08;
	*vtor = ((uint32_t) vector_table & 0xFFFFFFF8);
	
	uint32_t *init_values_ptr = (uint32_t *) &_etext;
	uint32_t *data_ptr = (uint32_t *) &_sdata;

	if (data_ptr != init_values_ptr) {
		for (; data_ptr < (uint32_t *) &_edata;) {
			*data_ptr++ = *init_values_ptr++;
		}
	}
	
	for (uint32_t *bss_ptr = (uint32_t *) &_sbss; bss_ptr < (uint32_t *)&_ebss;) {
		*bss_ptr++ = 0;
	}

	main();

	while(1);
}

void HardFault_Handler (void)
{
    #ifdef DEBUG
    __BKPT(0);
    #endif
    while (1)
    {
        /* code */
        
    }

}

void NMI_Handler (void)
{
    while (1)
    {
        /* code */
        
    }

}

