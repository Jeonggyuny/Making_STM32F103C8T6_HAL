.code	16		/* The Cortex-M3 is a thumb only processor */

.word	0x20005000	/* Initial MSP location */
.word	Reset_Handler	/* Reset_Handler*/
.word	_Dummy_Handler	/* NMI_Handler*/
.word	_Dummy_Handler	/* HardFault_Handler*/	
.word	_Dummy_Handler	/* MemManage_Handler */
.word	_Dummy_Handler	/* BusFault_Handler */
.word	_Dummy_Handler	/* UsageFault_Handler */
.word	_Dummy_Handler	/* Reserved */
.word	_Dummy_Handler	/* Reserved */
.word	_Dummy_Handler	/* Reserved */
.word	_Dummy_Handler	/* Reserved */
.word	_Dummy_Handler	/* SVCall_Handler */
.word	_Dummy_Handler	/* DebugMon_Handler */
.word	_Dummy_Handler	/* Reserved */
.word	_Dummy_Handler	/* PendSV_Handler */
.word	_Dummy_Handler	/* SysTick_Handler */
.word	_Dummy_Handler	/* 00. WWDG_Handler */
.word	_Dummy_Handler	/* 01. PVD_Handler */
.word	_Dummy_Handler	/* 02. TAMPER_Handler */
.word	_Dummy_Handler	/* 03. RTC_Handler */
.word	_Dummy_Handler	/* 04. FLASH_Handler */
.word	_Dummy_Handler	/* 05. RCC_Handler */
.word	_Dummy_Handler	/* 06. EXTI0_Handler */
.word	_Dummy_Handler	/* 07. EXTI1_Handler */
.word	_Dummy_Handler	/* 08. EXTI2_Handler */
.word	_Dummy_Handler	/* 09. EXTI3_Handler */
.word	_Dummy_Handler	/* 10. EXTI4_Handler */
.word	_Dummy_Handler	/* 11. DMA1_Channel1_Handler */
.word	_Dummy_Handler	/* 12. DMA1_Channel2_Handler */
.word	_Dummy_Handler	/* 13. DMA1_Channel3_Handler */
.word	_Dummy_Handler	/* 14. DMA1_Channel4_Handler */
.word	_Dummy_Handler	/* 15. DMA1_Channel5_Handler */
.word	_Dummy_Handler	/* 16. DMA1_Channel6_Handler */
.word	_Dummy_Handler	/* 17. DMA1_Channel7_Handler */
.word	_Dummy_Handler	/* 18. ADC1_2_Handler */
.word	_Dummy_Handler	/* 19. USB_HP_CAN_TX_Handler */
.word	_Dummy_Handler	/* 20. USB_LP_CAN_RX0_Handler */
.word	_Dummy_Handler	/* 21. CAN_RX1_Handler */
.word	_Dummy_Handler	/* 22. CAN_SCE_Handler */
.word	EXTI7_Handler	/* 23. EXTI9_5_Handler */
.word	_Dummy_Handler	/* 24. TIM1_BRK_Handler */
.word	_Dummy_Handler	/* 25. TIM1_UP_Handler */
.word	_Dummy_Handler	/* 26. TIM1_TRG_COM_Handler */
.word	_Dummy_Handler	/* 27. TIM1_CC_Handler */
.word	TIM2_Handler	/* 28. TIM2_Handler */
.word	_Dummy_Handler	/* 29. TIM3_Handler */
.word	_Dummy_Handler	/* 30. TIM4_Handler */
.word	_Dummy_Handler	/* 31. I2C1_EV_Handler */
.word	_Dummy_Handler	/* 32. I2C1_ER_Handler */
.word	_Dummy_Handler	/* 33. I2C2_EV_Handler */
.word	_Dummy_Handler	/* 34. I2C2_ER_Handler */
.word	_Dummy_Handler	/* 35. SPI1_Handler */
.word	_Dummy_Handler	/* 36. SPI2_Handler */
.word	_Dummy_Handler	/* 37. USART1_Handler */
.word	USART2_Handler	/* 38. USART2_Handler */
.word	_Dummy_Handler	/* 39. USART3_Handler */
.word	_Dummy_Handler	/* 40. EXTI15_10_Handler */
.word	_Dummy_Handler	/* 41. RTCAlarm_Handler */
.word	_Dummy_Handler	/* 42. USBWakeup_Handler */
.word	_Dummy_Handler	/* 43. TIM8_BRK_Handler */
.word	_Dummy_Handler	/* 44. TIM8_UP_Handler */
.word	_Dummy_Handler	/* 45. TIM8_TRG_COM_Handler */
.word	_Dummy_Handler	/* 46. TIM8_CC_Handler */
.word	_Dummy_Handler	/* 47. ADC3_Handler */
.word	_Dummy_Handler	/* 48. FSMC_Handler */
.word	_Dummy_Handler	/* 49. SDIO_Handler */
.word	_Dummy_Handler	/* 50. TIM5_Handler */
.word	_Dummy_Handler	/* 51. SPI3_Handler */
.word	_Dummy_Handler	/* 52. UART4_Handler */
.word	_Dummy_Handler	/* 53. UART5_Handler */
.word	_Dummy_Handler	/* 54. TIM6_Handler */
.word	_Dummy_Handler	/* 55. TIM7_Handler */
.word	_Dummy_Handler	/* 56. DMA2_Channel1_Handler */
.word	_Dummy_Handler	/* 57. DMA2_Channel2_Handler */
.word	_Dummy_Handler	/* 58. DMA2_Channel3_Handler */
.word	_Dummy_Handler	/* 59. DMA2_Channel4_5_Handler */

_Dummy_Handler:
	B	_Dummy_Handler

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
Reset_Handler:
	BL	main
	B	.
