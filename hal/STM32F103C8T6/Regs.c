#include "stdint.h"

#include "FLASH.h"
#include "RCC.h"
#include "GPIOx.h"
#include "USART.h"

volatile FLASH_t * FLASH = (FLASH_t *)FLASH_BASE_ADDRESS;
volatile RCC_t * RCC = (RCC_t *)RCC_BASE_ADDRESS;
volatile GPIOx_t * GPIOA = (GPIOx_t *)GPIOA_BASE_ADDRESS;
volatile USART_t * USART2 = (USART_t *)USART2_BASE_ADDRESS;
