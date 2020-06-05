#ifndef HAL_STM32F103C8T6_EXTI_H_
#define HAL_STM32F103C8T6_EXTI_H_

/* Interrupt mask register */
typedef union EXTI_IMR
{
	uint32_t all;
	struct {
		uint32_t MRx:20;	// 19:0
		uint32_t Reserved:12;	// 31:20
	} bits;
} EXTI_IMR_t;

/* Event mask register */
typedef union EXTI_EMR
{
	uint32_t all;
	struct {
		uint32_t MRx:20;	// 19:0
		uint32_t Reserved:12;	// 31:20
	} bits;
} EXTI_EMR_t;

/* Rising trigger selection register */
typedef union EXTI_RTSR
{
	uint32_t all;
	struct {
		uint32_t TRx:20;	// 19:0
		uint32_t Reserved:12;	// 31:20
	} bits;
} EXTI_RTSR_t;

/* Falling trigger selection register */
typedef union EXTI_FTSR
{
	uint32_t all;
	struct {
		uint32_t TRx:20;	// 19:0
		uint32_t Reserved:12;	// 31:20
	} bits;
} EXTI_FTSR_t;

/* Software interrupt event register */
typedef union EXTI_SWIER
{
	uint32_t all;
	struct {
		uint32_t SWIERx:20;	// 19:0
		uint32_t Reserved:12;	// 31:20
	} bits;
} EXTI_SWIER_t;

/* Pending register */
typedef union EXTI_PR
{
	uint32_t all;
	struct {
		uint32_t PRx:20;	// 19:0
		uint32_t Reserved:12;	// 31:20
	} bits;
} EXTI_PR_t;

typedef struct EXTI
{
	EXTI_IMR_t	exti_imr;	// 0x00
	EXTI_EMR_t	exti_emr;	// 0x04
	EXTI_RTSR_t	exti_rtsr;	// 0x08
	EXTI_FTSR_t	exti_ftsr;	// 0x0C
	EXTI_SWIER_t	exti_swier;	// 0x10
	EXTI_PR_t	exti_pr;	// 0x14
} EXTI_t;

#define EXTI_BASE_ADDRESS 0x40010400

#endif /* HAL_STM32F103C8T6_EXTI_H_ */
