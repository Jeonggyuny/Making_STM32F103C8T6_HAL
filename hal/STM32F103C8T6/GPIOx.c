#include "stdint.h"

#include "GPIOx.h"

#include "HAL_GPIOx.h"

extern volatile GPIOx_t * GPIOA;

void HAL_GPIOA_init(void)
{
	GPIOA->gpiox_crl.bits.MODE2 = 0b11;	// Port A2/TX mode bit (Output mode, max speed 50MHz)
	GPIOA->gpiox_crl.bits.CNF2 = 0b10;	// Port A2/TX configuration bit (Alternate function output push-pull)
	GPIOA->gpiox_crl.bits.MODE3 = 0b00;	// Port A3/RX mode bit (Input mode)
	GPIOA->gpiox_crl.bits.CNF3 = 0b01;	// Port A3/RX configuration bit (Floating input)
}
