#ifndef MYA_STM32F407VG_H
#define MYA_STM32F407VG_H

#include <stdint.h>


/************ RCC ***********/

#define RCC_BASE 0x40023800

typedef struct {

	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED_0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVED_1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED_2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED_3[2];

} RCC_Type;

#define RCC ((RCC_Type*) RCC_BASE)

/********** END RCC *********/


/******* GPIO ********/

#define GPIO_BASE 0x40020000
#define GPIO_MEM_SIZE 0x0400

typedef struct {

	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2]; // AFRL and AFRH


} GPIO_Type;

#define GPIOA ((GPIO_Type*) GPIO_BASE)
#define GPIOB ((GPIO_Type*) (GPIO_BASE + GPIO_MEM_SIZE))
#define GPIOC ((GPIO_Type*) (GPIO_BASE + 2 * GPIO_MEM_SIZE))
#define GPIOD ((GPIO_Type*) (GPIO_BASE + 3 * GPIO_MEM_SIZE))
#define GPIOE ((GPIO_Type*) (GPIO_BASE + 4 * GPIO_MEM_SIZE))
#define GPIOF ((GPIO_Type*) (GPIO_BASE + 5 * GPIO_MEM_SIZE))
#define GPIOG ((GPIO_Type*) (GPIO_BASE + 6 * GPIO_MEM_SIZE))
#define GPIOH ((GPIO_Type*) (GPIO_BASE + 7 * GPIO_MEM_SIZE))
#define GPIOI ((GPIO_Type*) (GPIO_BASE + 8 * GPIO_MEM_SIZE))
#define GPIOJ ((GPIO_Type*) (GPIO_BASE + 9 * GPIO_MEM_SIZE))
#define GPIOK ((GPIO_Type*) (GPIO_BASE + 10 * GPIO_MEM_SIZE))

/*********** END GPIO *************/



#endif
