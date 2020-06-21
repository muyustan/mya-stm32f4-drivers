#include "mya_stm32f407vg.h"
#include "mya_rcc.h"

typedef enum LINE {

    EXTI_EXTI0 = 0x01,
    EXTI_EXTI1 = 0x02,
    EXTI_EXTI2 = 0x04,
    EXTI_EXTI3 = 0x08,
    EXTI_EXTI4 = 0x10,
    EXTI_EXTI5 = 0x20,
    EXTI_EXTI6 = 0x40,
    EXTI_EXTI7 = 0x80,
    EXTI_EXTI8 = 0x100,
    EXTI_EXTI9 = 0x200,
    EXTI_EXTI10 = 0x400,
    EXTI_EXTI11 = 0x800,
    EXTI_EXTI12 = 0x1000,
    EXTI_EXTI13 = 0x2000,
    EXTI_EXTI14 = 0x4000,
    EXTI_EXTI15 = 0x8000,
    EXTI_EXTI16 = 0x10000,
    EXTI_EXTI17 = 0x20000,
    EXTI_EXTI18 = 0x40000,
    EXTI_EXTI19 = 0x80000,
    EXTI_EXTI20 = 0x100000,
    EXTI_EXTI21 = 0x200000,
    EXTI_EXTI22 = 0x400000

} EXTI_EXTIx;

typedef enum PORT {

    EXTI_PORT_A = 0x00,
    EXTI_PORT_B = 0x01,
    EXTI_PORT_C = 0x02,
    EXTI_PORT_D = 0x03,
    EXTI_PORT_E = 0x04,
    EXTI_PORT_F = 0x05,
    EXTI_PORT_G = 0x06,
    EXTI_PORT_H = 0x07,
    EXTI_PORT_I = 0x08,
    // EXTI_PORT_J = 0x09,
    // EXTI_PORT_K = 0x0A,

} EXTI_PORT_x;

typedef enum TRIGGER_EDGE {


    EXTI_TRIG_RISING,
    EXTI_TRIG_FALLING,
    EXTI_TRIG_RISING_FALLING

} EXTI_TRIG_Type;



void mya_exti_init();
void mya_exti_config(EXTI_EXTIx EXTIx, EXTI_PORT_x Port, EXTI_TRIG_Type TrigEdge);