ENTRY(ResetISR)

HEAP_SIZE = 1024;

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

SECTIONS
{
    .text :
    {
        _text = .;
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        KEEP(*(.init))
		KEEP(*(.fini))
        _etext = .;
    } > FLASH

    .ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > FLASH

	.ARM :
	{
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} > FLASH

	__end_code = .;

    .data : AT(__end_code)
    {
        _data = .;
        *(vtable)
        *(.data*)
        _edata = .;
    } > SRAM

    .bss :
    {
        _bss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > SRAM

    .heap : AT(_ebss)
	{
		. = ALIGN(8);
		__end__ = .;
		PROVIDE(end = .);
		__HeapBase = .;
		. += HEAP_SIZE;
		__HeapLimit = .;
	} > SRAM
}
