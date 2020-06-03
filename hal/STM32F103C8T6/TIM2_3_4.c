#include "stdint.h"

#include "TIM2_3_4.h"

#include "HAL_Timer.h"

extern volatile TIM2_3_4_t * TIM2;

uint32_t internal_1ms_counter;

void TIM2_Handler(void);

void HAL_Timer_init(void)
{
	internal_1ms_counter = 0;

	TIM2->timx_cr1.bits.UDIS = 0b0;		// Update disable (UEV enabled)

	TIM2->timx_cr1.bits.URS = 0b1;		// Update request source
						// Only counter overflow/underflow generates an update interrupt
						// or DMA request if enabled
	 
	TIM2->timx_cr1.bits.DIR = 0b0;		// Direction (Counter used as upcounter)
	TIM2->timx_cr1.bits.ARPE = 0b1;		// Auto-reload preload enable (TIMx_ARR register is bufferd)

	TIM2->timx_smcr.bits.SMS = 0b000;	// Slave mode selection (Slave mode disabled)
						// If CEN = 1 then the prescaler is clocked directly by the int-
						// ernal clock

	TIM2->timx_dier.bits.UIE = 0b1;		// Update interrupt enable
	TIM2->timx_egr.bits.UG = 0b0;		// Update generation
	TIM2->timx_psc.bits.PSC = 35999;	// Prescaler value (36000)
	TIM2->timx_arr.bits.ARR = 2;		// Auto-reload value (2000)

	TIM2->timx_cr1.bits.CEN = 0b1;		// Counter enable (Counter enabled)

}

uint32_t HAL_Timer_get_1ms_counter(void)
{
	return internal_1ms_counter;
}

/* Timer test */
void TIM2_Handler(void)
{
	internal_1ms_counter++;

	TIM2->timx_sr.bits.UIF = 0b0;
	TIM2->timx_sr.bits.CC1IF = 0b0;
	TIM2->timx_sr.bits.CC2IF = 0b0;
	TIM2->timx_sr.bits.CC3IF = 0b0;
	TIM2->timx_sr.bits.CC4IF = 0b0;
}
