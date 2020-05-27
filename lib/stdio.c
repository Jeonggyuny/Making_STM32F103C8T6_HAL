#include "stdint.h"
#include "stdio.h"

#include "HAL_USART.h"

uint32_t putstr(const char * s)
{
	uint32_t c = 0;

	while (*s) {
		HAL_USART2_put_char(*s++);
		
		c++;
	}

	return c;
}
