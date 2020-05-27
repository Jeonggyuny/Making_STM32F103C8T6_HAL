MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 64K
	SRAM (wail) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.text*)
	} > FLASH
	.bss :
	{
		*(.bss*)
	} > SRAM
}
