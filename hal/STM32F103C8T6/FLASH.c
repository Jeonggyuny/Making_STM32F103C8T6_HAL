#include "stdint.h"

#include "FLASH.h"

#include "HAL_FLASH.h"

extern volatile FLASH_t * FLASH;

void HAL_FLASH_init(void)
{
	FLASH->flash_acr.bits.LATENCY = 0b010;	// Latency (Two wait state, ...)
}
