#ifndef HAL_HAL_INTERRUPT_H_
#define HAL_HAL_INTERRUPT_H_

void HAL_Interrupt_init(void);
void HAL_Interrupt_enable(uint32_t interrupt_num);
void HAL_Interrupt_disable(uint32_t interrupt_num);

void HAL_Ext_Interrupt_init(void);

#endif /* HAL_HAL_INTERRUPT_H_ */
