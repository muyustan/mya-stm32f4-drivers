#include "mya_exti.h"

/* EXTI should be enabled/initialized befor using */
void mya_exti_init(){

	RCC_SYSCFG_EN(); // activate SYSCFG clock
    // Clock for EXTI is always enabled

    return;
}


/* for external interrupt from pin Pyx, 
    use EXTIx line with port name as y */

/* do not use multiple EXTIx values at once! */

void mya_exti_config(EXTI_EXTIx EXTIx, EXTI_PORT_x Port, EXTI_TRIG_Type TrigEdge){

    uint8_t x = 0x00;
    uint32_t temp = EXTIx >> 1;

    while(temp) {
        temp = temp >> 1;
        x++;
    }


	EXTI->IMR |= EXTIx; // unmask EXTIx
    SYSCFG->EXTICR[x/4] &= ~((0x0F << ((x%4)*4))); // first clear the bitfield
	SYSCFG->EXTICR[x/4] |= (Port << ((x%4)*4)); // choose Pyx for EXTIx line

    if (TrigEdge == EXTI_TRIG_RISING) {

        EXTI->RTSR |= EXTIx;
    }

    else if (TrigEdge == EXTI_TRIG_FALLING) {

        EXTI->FTSR |= EXTIx;
    }

    else if(TrigEdge == EXTI_TRIG_RISING_FALLING) {

    EXTI->RTSR |= EXTIx;
    EXTI->FTSR |= EXTIx;

    }

    else {
        /* throw error */
        ;
    }

    return;
}

void mya_exti_clear_pending_it(EXTI_EXTIx EXTIx) {

    EXTI->PR |= EXTIx; // clear pending bit by writing 1
    
    return;
}