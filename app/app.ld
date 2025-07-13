MEMORY
{
  bootrom  (rx)  : ORIGIN = 0x8000000, LENGTH = 32K
  approm   (rx)  : ORIGIN = 0x8000000, LENGTH = 2048K
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 192K
}

__bootrom_start__ = ORIGIN(bootrom);
__bootrom_size__ = LENGTH(bootrom);
__approm_start__ = ORIGIN(approm);
__approm_size__ = LENGTH(approm);

STACK_SIZE = 0x2000;

/* Section Definitions */
SECTIONS
{
    .text :
    {
        KEEP(*(.bootloader_section))
	    . = ALIGN(512);
	    _stext = .;
        KEEP(*(.vectors .vectors.*))
        *(.text*)
        . = ALIGN(4);
        *(.rodata*)
        . = ALIGN(4);
	 _etext = .;
    } > approm

    /* C++ Static constructors/destructors, also used for __attribute__
	 * ((constructor)) and the likes */
	.preinit_array : {
		. = ALIGN(4);
		__preinit_array_start = .;
		KEEP (*(.preinit_array))
		__preinit_array_end = .;
	} >approm
	.init_array : {
		. = ALIGN(4);
		__init_array_start = .;
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array))
		__init_array_end = .;
	} >approm
	.fini_array : {
		. = ALIGN(4);
		__fini_array_start = .;
		KEEP (*(.fini_array))
		KEEP (*(SORT(.fini_array.*)))
		__fini_array_end = .;
	} >approm

	/*
	 * Another section used by C++ stuff, appears when using newlib with
	 * 64bit (long long) printf support
	 */
	.ARM.extab : {
		*(.ARM.extab*)
	} >approm
	.ARM.exidx : {
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} >approm

	. = ALIGN(4);
	_etext = .;

    /* ram, but not cleared on reset, eg boot/app comms */
	.noinit (NOLOAD) : {
		*(.noinit*)
	} >ram
	. = ALIGN(4);


    /* .bss section which is used for uninitialized data */
    .bss (NOLOAD) :
    {
	_sbss = . ;
        *(.bss*)
        *(COMMON)
	_ebss = . ;
    } > ram

    .data :
    {
	_sdata = .;
        *(.data*);
	_edata = .;
    } > ram AT >approm

    /* stack section */
    .stack (NOLOAD):
    {
        . = ALIGN(8);
        . = . + STACK_SIZE;
        . = ALIGN(8);
    } > ram

    _end = . ;
}
