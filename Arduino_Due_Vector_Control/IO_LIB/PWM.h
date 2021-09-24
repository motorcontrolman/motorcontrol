
#ifndef PWM_H_INCLUDE
#define PWM_H_INCLUDE

extern uint16_t CounterPeriod;


void pwmInit();
void pwmWrite(uint16_t uDuty, uint16_t vDuty, uint16_t wDuty);

#endif