#ifndef HAL_STM32F103C8T6_GPIOx_H_
#define HAL_STM32F103C8T6_GPIOx_H_

/* Port configuration register low */
typedef union GPIOx_CRL
{
	uint32_t all;
	struct {
		uint32_t MODE0:2;	// 1:0
		uint32_t CNF0:2;	// 3:2
		uint32_t MODE1:2;	// 5:4
		uint32_t CNF1:2;	// 7:6
		uint32_t MODE2:2;	// 9:8
		uint32_t CNF2:2;	// 11:10
		uint32_t MODE3:2;	// 13:12
		uint32_t CNF3:2;	// 15:14
		uint32_t MODE4:2;	// 17:16
		uint32_t CNF4:2;	// 19:18
		uint32_t MODE5:2;	// 21:20
		uint32_t CNF5:2;	// 23:22
		uint32_t MODE6:2;	// 25:24
		uint32_t CNF6:2;	// 27:26
		uint32_t MODE7:2;	// 29:28
		uint32_t CNF7:2;	// 31:30
	} bits;
} GPIOx_CRL_t;

/* Port configuration register high */
typedef union GPIOx_CRH
{
	uint32_t all;
	struct {
		uint32_t MODE8:2;	// 1:0
		uint32_t CNF8:2;	// 3:2
		uint32_t MODE9:2;	// 5:4
		uint32_t CNF9:2;	// 7:6
		uint32_t MODE10:2;	// 9:8
		uint32_t CNF10:2;	// 11:10
		uint32_t MODE11:2;	// 13:12
		uint32_t CNF11:2;	// 15:14
		uint32_t MODE12:2;	// 17:16
		uint32_t CNF12:2;	// 19:18
		uint32_t MODE13:2;	// 21:20
		uint32_t CNF13:2;	// 23:22
		uint32_t MODE14:2;	// 25:24
		uint32_t CNF14:2;	// 27:26
		uint32_t MODE15:2;	// 29:28
		uint32_t CNF15:2;	// 31:30
	} bits;
} GPIOx_CRH_t;


/* Port input data register */
typedef union GPIOx_IDR
{
	uint32_t all;
	struct {
		uint32_t IDRy:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} GPIOx_IDR_t;

/* Port output data register */
typedef union GPIOx_ODR
{
	uint32_t all;
	struct {
		uint32_t ODRy:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} GPIOx_ODR_t;

/* Port bit set/reset register */
typedef union GPIOx_BSRR
{
	uint32_t all;
	struct {
		uint32_t BSy:16;	// 15:0
		uint32_t BRy:16;	// 31:16
	} bits;
} GPIOx_BSRR_t;

/* Port bit reset register */
typedef union GPIOx_BRR
{
	uint32_t all;
} GPIOx_BRR_t;

/* Port configuration lock register */
typedef union GPIOx_LCKR
{
	uint32_t all;
} GPIOx_LCKR_t;

typedef struct GPIOx
{
	GPIOx_CRL_t	gpiox_crl;	// 0x00
	GPIOx_CRH_t	gpiox_crh;	// 0x04
	GPIOx_IDR_t	gpiox_idr;	// 0x08
	GPIOx_ODR_t	gpiox_odr;	// 0x0C
	GPIOx_BSRR_t	gpiox_bsrr;	// 0x10
	GPIOx_BRR_t	gpiox_brr;	// 0x14
	GPIOx_LCKR_t	gpiox_lckr;	// 0x18
} GPIOx_t;

#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000

#endif /* HAL_STM32F103C8T6_GPIOx_H_ */
