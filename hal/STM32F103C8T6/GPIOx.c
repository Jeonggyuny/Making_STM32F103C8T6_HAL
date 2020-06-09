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

	GPIOA->gpiox_crl.bits.MODE4 = 0b11;	// Port A4/GPIOx mode bit (Output mode, max speed 50MHz)
	GPIOA->gpiox_crl.bits.CNF4 = 0b00;	// Port A4/GPIOx configuration bit (General purpose output push-pull)

	GPIOA->gpiox_crl.bits.MODE5 = 0b00;	// Port A5/GPIOx mode bit (Input mode)
	GPIOA->gpiox_crl.bits.CNF5 = 0b01;	// Port A5/GPIOx configuration bit (Floating input)

	GPIOA->gpiox_crl.bits.MODE6 = 0b00;	// Port A6/EXTI mode bit (Input mode)
	GPIOA->gpiox_crl.bits.CNF6 = 0b01;	// Port A6/EXTI configuration bit (Floating input)

	GPIOA->gpiox_crl.bits.MODE7 = 0b00;	// Port A7/ADC mode bit (Input mode)
	GPIOA->gpiox_crl.bits.CNF7 = 0b00;	// Port A7/ADC mode configuration bit (Analog mode)
}

void HAL_GPIOA_digital_write(uint32_t pin, bool value)
{
	GPIOA->gpiox_bsrr.all |= (1 << (pin + 16));
	GPIOA->gpiox_bsrr.all |= (value << pin);
}

bool  HAL_GPIOA_digital_read(uint32_t pin)
{
	return GPIOA->gpiox_idr.all & (1 << pin);
}
