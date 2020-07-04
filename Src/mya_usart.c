#include "mya_usart.h"



/* this function does not enable the clock signal for USARTx */
void mya_usart_init(USART_Type* USARTx, uint32_t baudRate, uint8_t UsartClockSpeedMHz) {

// only for USART1 & USART6 clock speeds for now
    float usart_div;

    usart_div = (float)UsartClockSpeedMHz * 1000000.0f / (8.0f * (2 - (uint8_t)(bool)(USARTx->CR1 & USART_CR1_OVER8)) * (float)baudRate);
    
   USARTx->BRR |= ((uint32_t)usart_div << 4) | (uint32_t) round(((usart_div - (uint32_t)usart_div) * 16)) ; // seperate integer part and decimal part

//    // USARTx->CR1 &= ~USART_CR1_M; // this is reset value already

    USARTx->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE; // Rx, Tx, and USART enable

    return;
}
