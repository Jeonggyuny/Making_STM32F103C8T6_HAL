#ifndef HAL_HAL_GPIOx_H_
#define HAL_HAL_GPIOx_H_

#include "stdbool.h"

void HAL_GPIOA_init(void);
void HAL_GPIOA_digital_write(uint32_t pin, bool value);
bool HAL_GPIOA_digital_read(uint32_t pin);

#define HIGH 1
#define LOW 0

#endif /* HAL_HAL_GPIOx_H_ */
