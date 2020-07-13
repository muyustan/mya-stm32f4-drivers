#include "mya_usart.h"

/* do not use PA9 for USART1 Tx on F4-DISC boards */
/* pins for Rx and Tx must be pulled up internally or externally */
/* mya_gpio_pin_config(GPIOB, GPIO_PIN_6, GPIO_Mode_AF, GPIO_OType_PushPull, GPIO_PuPd_UP, GPIO_OSpeed_VeryHigh); */
/* the above is one working example */ 

/* this function does not enable the clock signal for USARTx */
void mya_usart_init(USART_Type* USARTx, uint32_t baudRate, uint8_t UsartClockSpeedMHz) {

// only for USART1 & USART6 clock speeds for now

    float usart_div;

    usart_div = (float)UsartClockSpeedMHz * 1000000.0f / (8.0f * (2 - (uint8_t)(bool)(USARTx->CR1 & USART_CR1_OVER8)) * (float)baudRate);
    
    USARTx->BRR |= ((uint32_t)usart_div << 4) | (uint32_t) round(((usart_div - (uint32_t)usart_div) * 16)) ; // separate integer part and decimal part

    // USARTx->CR1 &= ~USART_CR1_M; // this is reset value already

    /* Rx, Tx, and USART enable */
    USARTx->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;  

    /* enable Rx and Tx buffer interrupts */
    USARTx->CR1 |= USART_CR1_RXNEIE;
    // USARTx->CR1 |= USART_CR1_TXEIE; 
    return;
}

void mya_usart_transmit_byte(USART_Type* USARTx, const uint8_t byte) {

        USARTx->DR = byte;
		while(!(USARTx->SR & USART_SR_TC)) {;} // w8 for transmission completed

    return;
}

void mya_usart_transmit_str(USART_Type* USARTx, const uint8_t* dataBuffer) {

    uint16_t i = 0;

    while (dataBuffer[i]) // string constants are null('\0') terminated.
    {
        USARTx->DR = dataBuffer[i++];
		while(!(USARTx->SR & USART_SR_TC)) {;}

    }
    

    return;
}
