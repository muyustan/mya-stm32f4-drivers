#include "mya_nvic.h"



void mya_nvic_enable(NVIC_n n) {

    NVIC->ISER[n/32] |= (0x01 << (n%32));
    return;
}

/* preemption-priority and sub-priority concepts are not implemented yet */
void mya_nvic_set_priority(NVIC_n n, uint8_t priority) {

    NVIC->IPR[n] = priority << 4; // only most significant 4 bits are used
    return;
}