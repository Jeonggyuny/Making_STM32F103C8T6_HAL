#include "stdint.h"
#include "stdio.h"

#include "HAL_USART.h"

void main(void)
{
	HAL_USART2_init();

	uint32_t i = 100;
	while (i--) {
		HAL_USART2_put_char('N');
	}
	HAL_USART2_put_char('\n');

	putstr("Hello World!\n");

	i = 100;
	while (i--) {
		uint8_t ch = HAL_USART2_get_char();
	
		HAL_USART2_put_char(ch);
	}
}
