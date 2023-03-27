/*
 * TIMER1_PWM_interface.h
 *
 * Created: 3/1/2023 2:08:51 PM
 *  Author: youssef's
 */ 


#ifndef TIMER1_PWM_INTERFACE_H_
#define TIMER1_PWM_INTERFACE_H_
#include "TIMER1_PWM_REG.h"

#define  FAST_PWM 0 
#define  PHASE_CORRECT 1

#define  INVERTING 0
#define  NON_INVERTING 1

//configuration
#define PWM_mode PHASE_CORRECT
#define PWM_polarity NON_INVERTING


void PWM_Init(void);
void PWM_Generate_CHANNELA(uint8 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq);
void PWM_Generate_CHANNELB(uint8 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq);




#endif /* TIMER1_PWM_INTERFACE_H_ */