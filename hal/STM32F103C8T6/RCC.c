#include "stdint.h"

#include "RCC.h"

#include "HAL_RCC.h"

extern volatile RCC_t * RCC;

void HAL_RCC_init(void)
{
	/* Using HSI Clock (8MHz)
	 * RCC->rcc_cr.bits.HSION = 0b1;	      // Internal high-speed clock enable
	 * while (!(RCC->rcc_cr.bits.HSIRDY));	      // Internal high-speed clcok ready flag
	 *
	 * RCC->rcc_cfgr.bits.PLLSRC = 0b0;	      // PLL entry clock source (HSI oscillator clock / 2 selected)
	 * RCC->rcc_cfgr.bits.PLLMUL = 0b0111;	      // PLL multiplication factor (PLL input clock x 9)
	 * RCC->rcc_cr.bits.PLLON = 0b1;	      // PLL enable
	 * while (!(RCC->rcc_cr.bits.PLLRDY));	      // PLL clock ready flag
	 * 
	 * RCC->rcc_cfgr.bits.SW = 0b10;	      // System clock switch (PLL selected as system clock)
	 * while (!(RCC->rcc_cfgr.bits.SWS == 0b10)); // System clock switch status (PLL used as system clock)
	 * 
	 * RCC->rcc_cfgr.bits.HPRE = 0b0000;	      // AHB prescaler (SYSCLK not divided)
	 * RCC->rcc_cfgr.bits.PPRE1 = 0b000;	      // APB1 low-speed prescaler (HCLK not divided)
	 */

	/* Using HSE Clock (8MHz) */
	RCC->rcc_cr.bits.HSEON = 0b1;	  	   // HSE clock enable
	while (!(RCC->rcc_cr.bits.HSERDY));	   // External high-speed clock ready flag
	
	RCC->rcc_cfgr.bits.PLLXTPRE = 0b0;	   // HSE divider for PLL entry (HSE clock not divided)
	RCC->rcc_cfgr.bits.PLLSRC = 0b1;	   // PLL entry clock source (HSE oscillator clock selected as PLL input clock)
	RCC->rcc_cfgr.bits.PLLMUL = 0b0111;	   // PLL multiplication factor (PLL input clock x 9)
	RCC->rcc_cr.bits.PLLON = 0b1;		   // PLL enable
	while (!(RCC->rcc_cr.bits.PLLRDY));	   // PLL clock ready flag
	
	RCC->rcc_cfgr.bits.SW = 0b10;		   // System clock switch (PLL selected as system clock)
	while (!(RCC->rcc_cfgr.bits.SWS == 0b10)); // System clock switch status (PLL used as system clock)
	
	RCC->rcc_cfgr.bits.HPRE = 0b0000;	   // AHB prescaler (SYSCLK not divided)
	RCC->rcc_cfgr.bits.PPRE1 = 0b100;	   // APB1 low-speed prescaler (HCLK divided by 2)
	RCC->rcc_cfgr.bits.PPRE2 = 0b000;	   // APB2 high-speed prescaler (HCLK not diveded))
	
	RCC->rcc_apb2enr.bits.IOPAEN = 0b1;	   // IO port A clock enable
	RCC->rcc_apb2enr.bits.AFIOEN = 0b1;	   // Alternate function IO clock enable
	RCC->rcc_apb1enr.bits.USART2EN = 0b1;	   // USART2 clock enable
	RCC->rcc_apb1enr.bits.TIM2EN = 0b1;	   // TIM2 timer clock enable
}
