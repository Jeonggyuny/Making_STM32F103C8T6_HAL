#ifndef HAL_STM32F103C8T6_ADC_H_
#define HAL_STM32F103C8T6_ADC_H_

/* ADC status register */
typedef union ADC_SR
{
	uint32_t all;
	struct {
		uint32_t AWD:1;		// 0
		uint32_t EOC:1;		// 1
		uint32_t JEOC:1;	// 2
		uint32_t JSTRT:1;	// 3
		uint32_t STRT:1;	// 4
		uint32_t Reserved:27;	// 31:5
	} bits;
} ADC_SR_t;

/* ADC control register 1 */
typedef union ADC_CR1
{
	uint32_t all;
	struct {
		uint32_t AWDCH:5;	// 4:0
		uint32_t EOCIE:1;	// 5
		uint32_t AWDIE:1;	// 6
		uint32_t JEOCIE:1;	// 7
		uint32_t SCAN:1;	// 8
		uint32_t AWDSGL:1;	// 9
		uint32_t JAUTO:1;	// 10
		uint32_t DISCEN:1;	// 11
		uint32_t JDISCEN:1;	// 12
		uint32_t DISCNUM:3;	// 15:13
		uint32_t DUALMOD:4;	// 19:16
		uint32_t Reserved_0:2;	// 21:20
		uint32_t JAWDEN:1;	// 22
		uint32_t AWDEN:1;	// 23
		uint32_t Reserved_1:8;	// 31:24
	} bits;
} ADC_CR1_t;

/* ADC control register 2 */
typedef union ADC_CR2
{
	uint32_t all;
	struct {
		uint32_t ADON:1;	// 0
		uint32_t CONT:1;	// 1
		uint32_t CAL:1;		// 2
		uint32_t RSTCAL:1;	// 3
		uint32_t Reserved_0:4;	// 7:4
		uint32_t DMA:1;		// 8
		uint32_t Reserved_1:2;	// 10:9
		uint32_t ALIGN:1;	// 11
		uint32_t JEXTSEL:3;	// 14:12
		uint32_t JEXTTRIG:1;	// 15
		uint32_t Reserved_2:1;	// 16
		uint32_t EXTSEL:3;	// 19:17
		uint32_t EXTTRIG:1;	// 20
		uint32_t JSWSTART:1;	// 21
		uint32_t SWSTART:1;	// 22
		uint32_t TSVREFE:1;	// 23
		uint32_t Reserved_3:8;	// 31:24
	} bits;
} ADC_CR2_t;

/* ADC sample time register 1 */
typedef union ADC_SMPR1
{
	uint32_t all;
	struct {
		uint32_t SMPx:24;	// 23:0
		uint32_t Reserved:8;	// 31:24
	} bits;
} ADC_SMPR1_t;

/* ADC sample time register 2 */
typedef union ADC_SMPR2
{
	uint32_t all;
	struct {
		uint32_t SMPx:30;	// 29:0
		uint32_t Reserved:2;	// 31:30
	} bits;
} ADC_SMPR2_t;

/* ADC injected channel data offset register x */
typedef union ADC_JOFRx
{
	uint32_t all;
	struct {
		uint32_t JOFFSETx:12;	// 11:0
		uint32_t Reserved:20;	// 31:12
	} bits;
} ADC_JOFRx_t;

/* ADC watchdog high threshold register */
typedef union ADC_HTR
{
	uint32_t all;
	struct {
		uint32_t HT:12;		// 11:0
		uint32_t Reserved:20;	// 31:12
	} bits;
} ADC_HTR_t;

/* ADC watchdog low threshold register */
typedef union ADC_LTR
{
	uint32_t all;
	struct {
		uint32_t LT:12;		// 11:0
		uint32_t Reserved:20;	// 31:12
	} bits;
} ADC_LTR_t;

/* ADC regular sequence register 1 */
typedef union ADC_SQR1
{
	uint32_t all;
	struct {
		uint32_t SQ13:5;	// 4:0
		uint32_t SQ14:5;	// 9:5
		uint32_t SQ15:5;	// 14:10
		uint32_t SQ16:5;	// 19:15
		uint32_t L:4;		// 23:20
		uint32_t Reserved:8;	// 31:24
	} bits;
} ADC_SQR1_t;

/* ADC regular sequence register 2 */
typedef union ADC_SQR2
{
	uint32_t all;
	struct {
		uint32_t SQ7:5;		// 4:0
		uint32_t SQ8:5;		// 9:5
		uint32_t SQ9:5;		// 14:10
		uint32_t SQ10:5;	// 19:15
		uint32_t SQ11:5;	// 24:20
		uint32_t SQ12:5;	// 29:25
		uint32_t Reserved:2;	// 31:30
	} bits;
} ADC_SQR2_t;

/* ADC regular sequence register 3 */
typedef union ADC_SQR3
{
	uint32_t all;
	struct {
		uint32_t SQ1:5;		// 4:0
		uint32_t SQ2:5;		// 9:5
		uint32_t SQ3:5;		// 14:10
		uint32_t SQ4:5;		// 19:15
		uint32_t SQ5:5;		// 24:20
		uint32_t SQ6:5;		// 29:25
		uint32_t Reserved:2;	// 31:30
	} bits;
} ADC_SQR3_t;

/* ADC injected sequence register */
typedef union ADC_JSQR
{
	uint32_t all;
	struct {
		uint32_t JSQ1:5;	// 4:0
		uint32_t JSQ2:5;	// 9:5
		uint32_t JSQ3:5;	// 14:10
		uint32_t JSQ4:5;	// 19:15
		uint32_t JL:2;		// 21:20
		uint32_t Reserved:10;	// 31:22
	} bits;
} ADC_JSQR_t;

/* ADC injected data register */
typedef union ADC_JDRx
{
	uint32_t all;
	struct {
		uint32_t JDATA:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} ADC_JDRx_t;

/* ADC regular data register */
typedef union ADC_DR
{
	uint32_t all;
	struct {
		uint32_t DATA:16;	// 15:0
		uint32_t ADC2DATA:16;	// 31:16
	} bits;
} ADC_DR_t;

typedef struct ADC
{
	ADC_SR_t	adc_sr;		// 0x00
	ADC_CR1_t	adc_cr1;	// 0x04
	ADC_CR2_t	adc_cr2;	// 0x08
	ADC_SMPR1_t	adc_smpr1;	// 0x0C
	ADC_SMPR2_t	adc_smpr2;	// 0x10
	ADC_JOFRx_t	adc_jofr1;	// 0x14
	ADC_JOFRx_t	adc_jofr2;	// 0x18
	ADC_JOFRx_t	adc_jofr3;	// 0x1C
	ADC_JOFRx_t	adc_jofr4;	// 0x20
	ADC_HTR_t	adc_htr;	// 0x24
	ADC_LTR_t	adc_ltr;	// 0x28
	ADC_SQR1_t	adc_sqr1;	// 0x2C
	ADC_SQR2_t	adc_sqr2;	// 0x30
	ADC_SQR3_t	adc_sqr3;	// 0x34
	ADC_JSQR_t	adc_jsqr;	// 0x38
	ADC_JDRx_t	adc_jdr1;	// 0x3C
	ADC_JDRx_t	adc_jdr2;	// 0x40
	ADC_JDRx_t	adc_jdr3;	// 0x44
	ADC_JDRx_t	adc_jdr4;	// 0x48
	ADC_DR_t	adc_dr;		// 0x4C
} ADC_t;

#define ADC1_BASE_ADDRESS 0x40012400
#define ADC2_BASE_ADDRESS 0x40012800

#endif /* HAL_STM32F103C8C6_ADC_H_ */
