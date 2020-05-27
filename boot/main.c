#include "stdint.h"

#include "HAL_USART.h"

void main(void)
{
	HAL_USART2_init();

	uint32_t i = 1000;
	while (i--) {
		HAL_USART2_put_char('N');
	}
}
