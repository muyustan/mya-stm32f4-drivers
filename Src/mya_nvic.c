#include "mya_nvic.h"



void mya_nvic_enable(NVIC_IRQn NVIC_x) {

	int16_t n = NVIC_x;
    NVIC->ISER[n/32] |= (0x01 << (n%32));
    return;
}

/* preemption-priority and sub-priority concepts are not implemented yet */
void mya_nvic_set_priority(NVIC_IRQn NVIC_x, uint8_t priority) {

	int16_t n = NVIC_x;
    NVIC->IPR[n] = priority << 4; // only most significant 4 bits are used
    return;
}
