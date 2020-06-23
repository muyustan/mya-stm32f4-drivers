#if !defined(MYA_NVIC_H)
#define MYA_NVIC_H


#include "mya_stm32f407vg.h"


typedef enum IRQn {
    
    NVIC_WWDG = 0x00,
    NVIC_PVD = 0x01,
    NVIC_TAMP_STAMP = 0x02,
    NVIC_RTC_WKUP = 0x03,
    NVIC_FLASH = 0x04,
    NVIC_RCC = 0x05,
    NVIC_EXTI0 = 0x06,
    NVIC_EXTI1 = 0x07,
    NVIC_EXTI2 = 0x08,
    NVIC_EXTI3 = 0x09,
    NVIC_EXTI4 = 0x0A,
    NVIC_DMA1_Stream0 = 0x0B,
    NVIC_DMA1_Stream1 = 0x0C,
    NVIC_DMA1_Stream2 = 0x0D,
    NVIC_DMA1_Stream3 = 0x0E,
    NVIC_DMA1_Stream4 = 0x0F,
    NVIC_DMA1_Stream5 = 0x10,
    NVIC_DMA1_Stream6 = 0x11,
    NVIC_ADC = 0x12, // ADC1, ADC2 and ADC3 global interrupts
    // to be continued...

} NVIC_n;



void mya_nvic_enable(NVIC_n n);

#endif // MYA_NVIC_H
