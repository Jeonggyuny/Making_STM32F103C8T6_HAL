#ifndef HAL_STM32F103C8T6_FLASH_H_
#define HAL_STM32F103C8T6_FLASH_H_

/* Flash access control register */
typedef union FLASH_ACR
{
	uint32_t all;
	struct {
		uint32_t LATENCY:3;	// 2:0
		uint32_t HLFCYA:1;	// 3
		uint32_t PRFTBE:1;	// 4
		uint32_t PRFTBS:1;	// 5
		uint32_t Reserved:26;	// 31:6
	} bits;
} FLASH_ACR_t;

typedef struct FLASH
{
	FLASH_ACR_t	flash_acr;	// 0x00
} FLASH_t;

#define FLASH_BASE_ADDRESS 0x40022000

#endif /* HAL_STM32F103C8T6_FLASH_H_ */

