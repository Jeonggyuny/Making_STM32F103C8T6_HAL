.code 16		/* The Cortex-M3 is a thumb only processor */

.word	0x20005000	/* Initial MSP location */
.word	_reset_handler	/* 01. Reset_Handler */
.word	_dummy_handler	/* 02. NMI_Handler */
.word	_dummy_handler	/* 03. HardFault_Handler */
.word	_dummy_handler	/* 04. MemManage_Handler */
.word	_dummy_handler	/* 05. BusFlault_Handler */
.word	_dummy_handler	/* 06. UsageFault_Handler */
.word	_dummy_handler	/* 07. Reserved */
.word	_dummy_handler	/* 08. Reserved */
.word	_dummy_handler	/* 09. Reserved */
.word	_dummy_handler	/* 10. Reserved */
.word	_dummy_handler	/* 11. SVC_Handler */
.word	_dummy_handler	/* 12. DebugMon_Handler */
.word	_dummy_handler	/* 13. Reserved */
.word	_dummy_handler	/* 14. DebugMon_Handler */
.word	_dummy_handler	/* 15. SysTick_Handler */
.word	_dummy_handler	/* 16. IRQ0 */
.word	_dummy_handler	/* 17. IRQ1 */
.word	_dummy_handler	/* 18. IRQ2 */
.word	_dummy_handler	/* 19. IRQ3 */
			/* 19. IRQn */

_dummy_handler:
	B	_dummy_handler

/* .thumb_func
 *
 * This directive specifies that the following symbol is the name of a Thumb en-
 * coded function. This information is necessary in order to allow the assembler
 * and linker to generate correct code for interworking between Arm and Thumb
 * instructions and should be used even if interworking is not going to be per-
 * formed. The presence of this directive also implies .thumb
 *
 * This directive is not necessary when generating EABI objects. On these targets
 * the encoding is implicit when generating Thumb code.
 */
.thumb_func
_reset_handler:
	BL	main
	B	.
