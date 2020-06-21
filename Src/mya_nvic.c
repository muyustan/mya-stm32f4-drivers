#include "mya_nvic.h"



void mya_nvic_enable(NVIC_x x) {

    NVIC->ISER[x/32] |= (0x01 << (x%32));

}



