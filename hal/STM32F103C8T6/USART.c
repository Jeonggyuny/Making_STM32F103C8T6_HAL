#include "stdint.h"

#include "USART.h"

#include "HAL_USART.h"

extern volatile USART_t * USART2;

void USART2_Handler(void);

void HAL_USART2_init(void)
{
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
	USART2->usart_cr1.bits.RE = 0b1;	// Receiver enable

	USART2->usart_cr1.bits.RXNEIE = 0b1;	// RXNE interrupt enable
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

/* Interrupt test */
void USART2_Handler(void)
{
	uint8_t ch = HAL_USART2_get_char();

	HAL_USART2_put_char(ch);
}
