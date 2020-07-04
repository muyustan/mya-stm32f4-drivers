/*
 * mya_gpio.h
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#ifndef MYA_GPIO_H_
#define MYA_GPIO_H_

#include "mya_stm32f407vg.h"

#define GPIO_PIN_0  0x00000001U
#define GPIO_PIN_1  0x00000002U
#define GPIO_PIN_2  0x00000004U
#define GPIO_PIN_3  0x00000008U
#define GPIO_PIN_4  0x00000010U
#define GPIO_PIN_5  0x00000020U
#define GPIO_PIN_6  0x00000040U
#define GPIO_PIN_7  0x00000080U
#define GPIO_PIN_8  0x00000100U
#define GPIO_PIN_9  0x00000200U
#define GPIO_PIN_10 0x00000400U
#define GPIO_PIN_11 0x00000800U
#define GPIO_PIN_12 0x00001000U
#define GPIO_PIN_13 0x00002000U
#define GPIO_PIN_14 0x00004000U
#define GPIO_PIN_15 0x00008000U

#define GPIOA_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN)
#define GPIOB_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN)
#define GPIOC_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN)
#define GPIOD_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN)
#define GPIOE_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN)
#define GPIOF_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN) 
#define GPIOG_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN)
#define GPIOH_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN)
#define GPIOI_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN)
#define GPIOJ_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN)
#define GPIOK_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN)

/* alternate function configurations */


#define GPIO_AF_MCO1				(uint8_t)0x00U
#define GPIO_AF_JTMS_SWDIO			(uint8_t)0x00U
#define GPIO_AF_JTMS_SWCLK			(uint8_t)0x00U
#define GPIO_AF_JTDI_TRACESWO		(uint8_t)0x00U
#define GPIO_AF_NJTRST				(uint8_t)0x00U
#define GPIO_AF_RTC_REFIN			(uint8_t)0x00U
#define GPIO_AF_MCO2				(uint8_t)0x00U
#define GPIO_AF_TRACECLK			(uint8_t)0x00U
#define GPIO_AF_TRACED0				(uint8_t)0x00U
#define GPIO_AF_TRACED1				(uint8_t)0x00U
#define GPIO_AF_TRACED2				(uint8_t)0x00U
#define GPIO_AF_TRACED3				(uint8_t)0x00U


#define GPIO_AF_TIM2_CH1_ETR		(uint8_t)0x01U
#define GPIO_AF_TIM2_CH1			(uint8_t)0x01U
#define GPIO_AF_TIM2_CH2			(uint8_t)0x01U
#define GPIO_AF_TIM2_CH3			(uint8_t)0x01U
#define GPIO_AF_TIM2_CH4			(uint8_t)0x01U
#define GPIO_AF_TIM1_BKIN			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH1N			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH1			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH2			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH3			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH4			(uint8_t)0x01U
#define GPIO_AF_TIM1_ETR			(uint8_t)0x01U
#define GPIO_AF_TIM2_ETR			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH2N			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH3N			(uint8_t)0x01U



//#define GPIO_AF_MCO1	(uint8_t)0x08U
//#define GPIO_AF_MCO1	(uint8_t)0x09U
//#define GPIO_AF_MCO1	(uint8_t)0x0AU
//#define GPIO_AF_MCO1	(uint8_t)0x0BU
//#define GPIO_AF_MCO1	(uint8_t)0x0CU
//#define GPIO_AF_MCO1	(uint8_t)0x0DU
//#define GPIO_AF_MCO1	(uint8_t)0x0EU
//#define GPIO_AF_MCO1	(uint8_t)0x0FU







/* end alternate function configurations */



typedef enum MODE {

	GPIO_Mode_INPUT = 0b00,
	GPIO_Mode_OUTPUT = 0b01,
	GPIO_Mode_AF = 0b10,
	GPIO_Mode_ANALOG = 0b11

} GPIO_Mode;

typedef enum OTYPE {

	GPIO_PuPd_NOPULL= 0b00,
	GPIO_PuPd_UP = 0b01,
	GPIO_PuPd_DOWN = 0b10
	// 0x03 is reserved

} GPIO_PuPd;

typedef enum PIN_STATE {

	GPIO_PinState_LOW = 0,
	GPIO_PinState_HIGH = 1

} GPIO_PinState;


void mya_gpio_pin_config (GPIO_Type* GPIOx, uint32_t GPIO_PIN_x, GPIO_Mode Mode, GPIO_PuPd PuPd);

uint8_t mya_gpio_pin_read (GPIO_Type* GPIOx, uint16_t GPIO_PIN_x);

void mya_gpio_pin_write (GPIO_Type* GPIOx, uint16_t GPIO_PIN_x, GPIO_PinState State);

void mya_gpio_pin_toggle (GPIO_Type* GPIOx, uint16_t GPIO_PIN_x);

void mya_gpio_alternate_func_config(GPIO_Type* GPIOx, uint8_t pinNumber, uint8_t GPIO_AF_x);


#endif /* MYA_GPIO_H_ */
