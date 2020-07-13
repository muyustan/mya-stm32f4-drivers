#include "mya_stm32f407vg.h"

void mya_usart_init(USART_Type* USARTx, uint32_t baudRate, uint8_t UsartClockSpeedMHz);

void mya_usart_transmit_data(USART_Type* USARTx, const uint8_t* dataBuffer);

void mya_usart_transmit_byte(USART_Type* USARTx, const uint8_t byte);
