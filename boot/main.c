#include "stdint.h"
#include "stdio.h"

#include "HAL_FLASH.h"
#include "HAL_RCC.h"
#include "HAL_GPIOx.h"
#include "HAL_USART.h"
#include "HAL_Interrupt.h"

/* Interrupt test */
void USART2_Handler(void)
{
	uint8_t ch = HAL_USART2_get_char();

	HAL_USART2_put_char(ch);
}

void main(void)
{
	HAL_FLASH_init();
	HAL_RCC_init();
	HAL_GPIOA_init();
	HAL_USART2_init();

	/* HAL_USART2_put_char() test */
	uint32_t i = 100;
	while (i--) {
		HAL_USART2_put_char('N');
	}
	HAL_USART2_put_char('\n');

	/* putstr() test */
	putstr("Hello World!\n");

	/* debug_printf() test */
	char * str = "printf pointer test";
	char * nullptr = 0;
	i = 5;

	debug_printf("%s\n", "Hello printf");
	debug_printf("output string pointer: %s\n", str);
	debug_printf("%s is null pointer, %u number\n", nullptr, 10);
	debug_printf("%u = 5\n", i);
	debug_printf("dec = %u, hex = %x\n", 0xFF, 0xFF);
	debug_printf("print zero %u\n", 0);

	/* Interrupt test */
	HAL_Interrupt_enable(38);	// 38: USART2 NVIC Postion

	while (1);

	/* HAL_USART2_get_char() test */
	i = 100;
	while (i--) {
		uint8_t ch = HAL_USART2_get_char();
	
		HAL_USART2_put_char(ch);
	}
}
