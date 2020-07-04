








/* fCLK_counter = fCLK_prescaler/(PSC+1) */

/* Counter overflow period = (1+ARR) * Counter Clock Period */

/* PWM Mode 1 (Low-True) 

    Output is HIGH if counter < CCR
    Output is LOW if counter >= CCR

    Duty cycle = CCR / (ARR + 1)

*/

/* PWM Mode 2 (High-True) 

    Output is LOW if counter < CCR
    Output is HIGH if counter >= CCR

    Duty cycle = 1 - CCR / (ARR + 1)

*/