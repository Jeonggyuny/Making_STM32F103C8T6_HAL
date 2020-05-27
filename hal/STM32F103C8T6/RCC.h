#ifndef HAL_STM32F103C8T6_RCC_H_
#define HAL_STM32F103C8T6_RCC_H_

/* Clock control register */
typedef union RCC_CR
{
	uint32_t all;
	struct {
		uint32_t HSION:1;	// 0
		uint32_t HSIRDY:1;	// 1
		uint32_t Reserved_0:1;	// 2
		uint32_t HSITRIM:5;	// 7:3
		uint32_t HSICAL:8;	// 15:8
		uint32_t HSEON:1;	// 16
		uint32_t HSERDY:1;	// 17
		uint32_t HSEBYP:1;	// 18
		uint32_t CSSON:1;	// 19
		uint32_t Reserved_1:4;	// 23:20
		uint32_t PLLON:1;	// 24
		uint32_t PLLRDY:1;	// 25
		uint32_t Reserved_2:6;	// 31:26
	} bits;
} RCC_CR_t;

/* Clock configuration register */
typedef union RCC_CFGR
{
	uint32_t all;
	struct {
		uint32_t SW:2;		// 1:0
		uint32_t SWS:2;		// 3:2
		uint32_t HPRE:4;	// 7:4
		uint32_t PPRE1:3;	// 10:8
		uint32_t PPRE2:3;	// 13:11
		uint32_t ADCPRE:2;	// 15:14
		uint32_t PLLSRC:1;	// 16
		uint32_t PLLXTPRE:1;	// 17
		uint32_t PLLMUL:4;	// 21:18
		uint32_t USBPRE:1;	// 22
		uint32_t Reserved_0:1;	// 23
		uint32_t MCO:2;		// 26:24
		uint32_t Reserved_1:5;	// 31:27
	} bits;
} RCC_CFGR_t;

/* Clock interrupt register */
typedef union RCC_CIR
{
	uint32_t all;
} RCC_CIR_t;

/* APB2 peripheral reset register */
typedef union RCC_APB2RSTR
{
	uint32_t all;
} RCC_APB2RSTR_t;

/* APB1 peripheral reset register */
typedef union RCC_APB1RSTR
{
	uint32_t all;
} RCC_APB1RSTR_t;

/* AHB peripheral clock enable register */
typedef union RCC_AHBENR
{
	uint32_t all;
} RCC_AHBENR_t;

/* APB2 peripheral clock enable register */
typedef union RCC_APB2ENR
{
	uint32_t all;
	struct {
		uint32_t AFIOEN:1;	// 0
		uint32_t Reserved_0:1;	// 1
		uint32_t IOPAEN:1;	// 2
		uint32_t IOPBEN:1;	// 3
		uint32_t IOPCEN:1;	// 4
		uint32_t IOPDEN:1;	// 5
		uint32_t IOPEEN:1;	// 6
		uint32_t IOPFEN:1;	// 7
		uint32_t IOPGEN:1;	// 8
		uint32_t ADC1EN:1;	// 9
		uint32_t ADC2EN:1;	// 10
		uint32_t TIM1EN:1;	// 11
		uint32_t SPI1EN:1;	// 12
		uint32_t TIM8EN:1;	// 13
		uint32_t USART1EN:1;	// 14
		uint32_t ADC3EN:1;	// 15
		uint32_t Reserved_1:3;	// 18:16
		uint32_t TIM9EN:1;	// 19
		uint32_t TIM10EN:1;	// 20
		uint32_t TIM11EN:1;	// 21
		uint32_t Reserved_2:10;	// 31:22

	} bits;
} RCC_APB2ENR_t;

/* APB1 peripheral clock enable register */
typedef union RCC_APB1ENR
{
	uint32_t all;
	struct {
		uint32_t TIM2EN:1;	// 0
		uint32_t TIM3EN:1;	// 1
		uint32_t TIM4EN:1;	// 2
		uint32_t TIM5EN:1;	// 3
		uint32_t TIM6EN:1;	// 4
		uint32_t TIM7EN:1;	// 5
		uint32_t TIM12EN:1;	// 6
		uint32_t TIM13EN:1;	// 7
		uint32_t TIM14EN:1;	// 8
		uint32_t Reserved_0:2;	// 10:9
		uint32_t WWDGEN:1;	// 11
		uint32_t Reserved_1:2;	// 13:12
		uint32_t SPI2EN:1;	// 14
		uint32_t SPI3EN:1;	// 15
		uint32_t Reserved_2:1;	// 16
		uint32_t USART2EN:1;	// 17
		uint32_t USART3EN:1;	// 18
		uint32_t USART4EN:1;	// 19
		uint32_t USART5EN:1;	// 20
		uint32_t I2C1EN:1;	// 21
		uint32_t I2C2EN:1;	// 22
		uint32_t USBEN:1;	// 23
		uint32_t Reserved_3:1;	// 24
		uint32_t CANEN:1;	// 25
		uint32_t Reserved_4:1;	// 26
		uint32_t BKPEN:1;	// 27
		uint32_t PWREN:1;	// 28
		uint32_t DACEN:1;	// 29
		uint32_t Reserved_5:2;	// 31:30
	} bits;
} RCC_APB1ENR_t;

/* Backup domain control register */
typedef union RCC_BDCR
{
	uint32_t all;
} RCC_BDCR_t;

/* Control/status register */
typedef union RCC_CSR
{
	uint32_t all;
} RCC_CSR_t;

typedef struct RCC
{
	RCC_CR_t	rcc_cr;		// 0x00
	RCC_CFGR_t	rcc_cfgr;	// 0x04
	RCC_CIR_t	rcc_cir;	// 0x08
	RCC_APB2RSTR_t	rcc_apb2rstr;	// 0x0C
	RCC_APB1RSTR_t	rcc_apb1rstr;	// 0x10
	RCC_AHBENR_t	rcc_ahbenr;	// 0x14
	RCC_APB2ENR_t	rcc_apb2enr;	// 0x18
	RCC_APB1ENR_t	rcc_apb1enr;	// 0x1C
	RCC_BDCR_t	rcc_bdcr;	// 0x20
	RCC_CSR_t	rcc_csr;	// 0x24
} RCC_t;

#define RCC_BASE_ADDRESS 0x40021000

#endif /* HAL_STM32F103C8T6_RCC_H_ */
