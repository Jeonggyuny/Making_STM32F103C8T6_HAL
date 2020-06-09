#include "stdint.h"

#include "ADC.h"

#include "HAL_ADC.h"

extern volatile ADC_t * ADC1;

void HAL_ADC1_init(void)
{
	ADC1->adc_cr2.bits.CONT = 0b0;			// Continuous conversion (Continuous conversion mode)
	ADC1->adc_cr2.bits.EXTSEL = 0b111;		// External event select for regular group (SWSTART)
	ADC1->adc_cr2.bits.EXTTRIG = 0b1;		// External trigger conversion mode for regular channels (Con-
							// version on external event enabled)

	ADC1->adc_smpr2.all |= (0b111 << 21);		// Channel 8 Sample time selection (239.5 cycles)
							// Where speed is not an issue, it is best to choose the long-
							// est sample time that is feasible
	
	ADC1->adc_sqr1.bits.L = 0b000;			// Regular Channel sequence length (1 conversion)
	ADC1->adc_sqr3.bits.SQ1 = 7;			// First conversion in regular sequence

	ADC1->adc_cr2.bits.ADON = 0b1;			// A/D converter ON / OFF (Enable ADC and to start conversion)

	ADC1->adc_cr2.bits.CAL = 0b1;			// A/D Calibration			
	while (ADC1->adc_cr2.bits.CAL);			// This bit is set by software to start the calibration. It is
							// reset by hardware after calibration is complete
}

uint32_t HAL_ADC1_analog_read(void)
{
	ADC1->adc_cr2.bits.SWSTART = 0b1;		// Start conversion of regular channels
	while (ADC1->adc_cr2.bits.SWSTART);		// This bit is set by software to start conversion and cleared
							// by hardware as soon as conversion starts

	while (!(ADC1->adc_sr.bits.EOC));		// End of conversion (Conversion complete)
							// This bit is set by hardware at the end of a group channel
							// conversion. It is cleared by software or by reading the ADC_
							// DR

	return ADC1->adc_dr.bits.DATA;			// Regular data
}
