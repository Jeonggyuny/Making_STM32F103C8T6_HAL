#include "stdint.h"

#include "FLASH.h"
#include "RCC.h"
#include "GPIOx.h"
#include "USART.h"
#include "NVIC.h"
#include "TIM2_3_4.h"
#include "AFIO.h"
#include "EXTI.h"

volatile FLASH_t * FLASH = (FLASH_t *)FLASH_BASE_ADDRESS;
volatile RCC_t * RCC = (RCC_t *)RCC_BASE_ADDRESS;
volatile GPIOx_t * GPIOA = (GPIOx_t *)GPIOA_BASE_ADDRESS;
volatile USART_t * USART2 = (USART_t *)USART2_BASE_ADDRESS;
volatile NVIC_ISERx_t * NVIC_ISERx = (NVIC_ISERx_t *)NVIC_ISERx_BASE_ADDRESS;
volatile NVIC_ICERx_t * NVIC_ICERx = (NVIC_ICERx_t *)NVIC_ICERx_BASE_ADDRESS;
volatile TIM2_3_4_t * TIM2 = (TIM2_3_4_t *)TIM2_BASE_ADDRESS;
volatile AFIO_t * AFIO = (AFIO_t *)AFIO_BASE_ADDRESS;
volatile EXTI_t * EXTI = (EXTI_t *)EXTI_BASE_ADDRESS;
