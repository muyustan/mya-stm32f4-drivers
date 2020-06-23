#if !defined(MYA_DELAY_H)
#define MYA_DELAY_H

#include "mya_stm32f407vg.h"

/* ticks cannot exceed 24 bits unsigned value */
#define SysTick_LOAD(ticks) (SysTick->LOAD = (ticks - 1))
    /* the time duration between two consecutive
    SysTick interrupt is (RE)LOAD + 1 */


void mya_delay_ms(uint16_t ms);




#endif // MYA_DELAY_H
