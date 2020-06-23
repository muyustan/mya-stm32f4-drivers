#include "mya_delay.h"

volatile uint32_t t_ms = 0x00; // volatile!

void SysTick_Handler(){

    t_ms--;

    return;
}
    

void mya_delay_ms(uint16_t ms) {
    
    SysTick->CTRL = 0x00; // disable the SysTick
    // also sets clock for SysTick to AHB/8

    /* for now, the system clock AHB freq. is taken as 
    constant and 168 MHz */
    /* So, clock for SysTick is at 168/8 = 21 MHz */
    
    SysTick_LOAD(21000);

    SysTick->VAL = 0x00; // clear the counter current value

    t_ms = (uint32_t) ms; // modify the global variable

    SysTick->CTRL |= (SysTick_CTRL_ENABLE | SysTick_CTRL_TICKINT);
    // enable both the counter and interrupt

    while (t_ms)
    {
        ; // do nothing, dummy loop
    }
    
    SysTick->CTRL = 0x00; // we are done, disable the SysTick counter

    return;
}