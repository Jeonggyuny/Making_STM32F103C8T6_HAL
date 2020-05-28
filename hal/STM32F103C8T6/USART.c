#include "stdint.h"

#include "FLASH.h"
#include "RCC.h"
#include "GPIOx.h"
#include "USART.h"
#include "HAL_USART.h"

extern volatile FLASH_t * FLASH;
extern volatile RCC_t * RCC;
extern volatile GPIOx_t * GPIOA;
extern volatile USART_t * USART2;

void _HAL_FLASH_init(void)
{
	FLASH->flash_acr.bits.LATENCY = 0b010;	// Latency (Two wait state, ...)
}

void _HAL_RCC_init(void)
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
	
}

void _HAL_GPIOA_init(void)
{
	RCC->rcc_apb2enr.bits.IOPAEN = 0b1;	// IO port A clock enable
	RCC->rcc_apb2enr.bits.AFIOEN = 0b1;	// Alternate function IO clock enable

	GPIOA->gpiox_crl.bits.MODE2 = 0b11;	// Port A2/TX mode bit (Output mode, max speed 50MHz)
	GPIOA->gpiox_crl.bits.CNF2 = 0b10;	// Port A2/TX configuration bit (Alternate function output push-pull)
	GPIOA->gpiox_crl.bits.MODE3 = 0b00;	// Port A3/RX mode bit (Input mode)
	GPIOA->gpiox_crl.bits.CNF3 = 0b01;	// Port A3/RX configuration bit (Floating input)
}

void HAL_USART2_init(void)
{
	_HAL_FLASH_init();
	_HAL_RCC_init();
	_HAL_GPIOA_init();

	RCC->rcc_apb1enr.bits.USART2EN = 0b1;	// USART2 clock enable

	USART2->usart_cr1.bits.UE = 0b1;	// USART enable
	USART2->usart_cr1.bits.M = 0b0;		// Word length (1 Start bit, 8 Data bits, n Stop bit)
	USART2->usart_cr2.bits.STOP = 0b00;	// STOP bits (1 Stop bit)
	USART2->usart_cr3.bits.DMAT = 0b0;	// DMA enable transmitter (DMA mode is disabled for transmission)
	USART2->usart_cr3.bits.DMAR = 0b0;	// DMA enable receiver (DMA mode is disabled for reception)

	/* Tx/Rx baud = fck/(16 * USARTDIV)
	 * USARTDIV = DIV_Mantissa + (DIV_Fraction\16)
	 * fck - Input clock to the peripheral
	 *
	 * 9600 = 36M/(16 * USARTDIV)
	 * 1/USARTDIV = (9600 * 16)/36M
	 * USARTDIV = 234.375
	 *
	 * 115200 = 36M/(16 * USARTDIV)
	 * 1/USARTDIV = (115200 * 16)/36M
	 * USARTDIV = 19.53125
	 */
	USART2->usart_brr.bits.DIV_Mantissa = 0b10011; // mantissa of USARTDIV
	USART2->usart_brr.bits.DIV_Fraction = 0b1000;  // fraction of USARTDIV
	
	USART2->usart_cr1.bits.TE = 0b1;	// Transmitter enable
	USART2->usart_cr1.bits.RE = 0b1;	// eceiver enable
}

void HAL_USART2_put_char(uint8_t ch)
{
	USART2->usart_dr.bits.DR = (ch & 0xFF);	    // Data value
	
	// USART2->usart_cr1.bits.UE = 0b0;	    // USART disable
	while (!(USART2->usart_sr.bits.TC == 0b1)); // Transmission complete
	// USART2->usart_cr1.bits.UE = 0b1; 	    // USART enable
}

uint8_t HAL_USART2_get_char(void)
{
	while (!(USART2->usart_sr.bits.RXNE == 0b1)); // Read data register not empty
	
	/* Check for an error flag and Receive data */
	/* if (USART2->usart_sr.all & 0x0000001F) {      // Error occured
	 *	 // It is cleared by a software sequence
	 *	 // (an read to the USART_SR register foll-
	 *	 // owed by a read to the USART_DR register)	
	 *	uint32_t data = USART2->usart_dr.bits.DR;
	 *
	 *	return 0;
	 * } else {
	 *	uint32_t data = USART2->usart_dr.bits.DR;
	 *
	 *	return (uint8_t)(data & 0x000000FF);
	 * }
	 */

	uint32_t data = USART2->usart_dr.bits.DR;

	return (uint8_t)(data & 0x000000FF);
}
