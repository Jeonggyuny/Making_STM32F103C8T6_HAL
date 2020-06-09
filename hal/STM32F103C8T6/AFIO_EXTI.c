#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

#include "AFIO.h"
#include "EXTI.h"

#include "HAL_Interrupt.h"

extern volatile AFIO_t * AFIO;
extern volatile EXTI_t * EXTI;

void EXTI6_Handler(void);

void HAL_Ext_Interrupt_init(void)
{
	AFIO->afio_exticr2.bits.EXTIx |= (0b0000 << 11); // EXTI 6 configuration (PA[6] pin)

	EXTI->exti_imr.bits.MRx |= (1 << 6);		 // Interrupt Mask on line 6
							 // Interrupt request from Line 6 is not masked
	
	EXTI->exti_ftsr.bits.TRx |= (1 << 6);		 // Falling trigger event configuration bit of line 6
							 // Falling trigger enabled (for Event and Interrupt)
							 // for input line
}

static void HAL_Ext_Interrupt_complete(void)
{
	EXTI->exti_pr.bits.PRx |= (1 << 6);		 // Pending bit (selected trigger request occurred)
}

/* External interrupt test */
void EXTI6_Handler(void)
{
	debug_printf("EXTI6_Handler() called\n");

	HAL_Ext_Interrupt_complete();
}
