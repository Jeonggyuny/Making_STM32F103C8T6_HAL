#include "stdint.h"
#include "memio.h"

#include "NVIC.h"

#include "HAL_Interrupt.h"

extern volatile NVIC_ISERx_t * NVIC_ISERx;
extern volatile NVIC_ICERx_t * NVIC_ICERx;

void HAL_Interrupt_init(void)
{
}

void HAL_Interrupt_enable(uint32_t interrupt_num)
{
	if ((interrupt_num < NVIC_POSITION_BEGIN)  || (interrupt_num > NVIC_POSITION_END)) {
		return;
	}

	int q = interrupt_num / 32;
	int r = interrupt_num % 32;

	switch (q) {
		case 0:
			SET_BIT(NVIC_ISERx->nvic_iser0.bits.SETENA, r);

			break;

		case 1:
			SET_BIT(NVIC_ISERx->nvic_iser1.bits.SETENA, r);

			break;

		case 2:
			SET_BIT(NVIC_ISERx->nvic_iser2.bits.SETENA, r);

			break;
	}
}

void HAL_Interrupt_disable(uint32_t interrupt_num)
{
	if ((interrupt_num < NVIC_POSITION_BEGIN) || (interrupt_num > NVIC_POSITION_END)) {
		return;
	}

	int q = interrupt_num / 32;
	int r = interrupt_num % 32;

	switch (q) {
		case 0:
			SET_BIT(NVIC_ICERx->nvic_icer0.bits.CLRENA, r);

			break;

		case 1:
			SET_BIT(NVIC_ICERx->nvic_icer1.bits.CLRENA, r);

			break;

		case 2:
			SET_BIT(NVIC_ICERx->nvic_icer2.bits.CLRENA, r);

			break;
	}
}
