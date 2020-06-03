#include "stdint.h"
#include "stdlib.h"

#include "HAL_Timer.h"

void delay(uint32_t ms)
{
	uint32_t goal = HAL_Timer_get_1ms_counter() + ms;

	while (goal != HAL_Timer_get_1ms_counter());
}
