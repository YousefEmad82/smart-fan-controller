/*
 * TIMER1_PWM_REG.h
 *
 * Created: 3/1/2023 2:09:09 PM
 *  Author: youssef's
 */ 


#ifndef TIMER1_PWM_REG_H_
#define TIMER1_PWM_REG_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"

#define TCCR1A          *((volatile uint8*)0x4F)
#define TCCR1B          *((volatile uint8*)0x4E)

#define TCNT1_REG       *((volatile uint16*)0x4C) //all the 16 bits 
#define TCNT1L          *((volatile uint8*)0x4C)
#define TCNT1H          *((volatile uint8*)0x4D)

#define OCR1A_REG       *((volatile uint16*)0x4A) //all the  16 bits
#define OCR1AL          *((volatile uint8*)0x4A)
#define OCR1AH          *((volatile uint8*)0x4B)

#define OCR1B_REG       *((volatile uint16*)0x48) //all the  16 bits
#define OCR1BL          *((volatile uint8*)0x48)
#define OCR1BH          *((volatile uint8*)0x48)

#define ICR1_REG        *((volatile uint16*)0x46) //all the 16 bits
#define ICR1H_REG       *((volatile uint8*)0x47)
#define ICR1L_REG       *((volatile uint8*)0x46)

//interrupt registers


#define PWM_OUTPUT_REG  *((volatile uint8*)0x31) //DDRD





//TIMER1 TIMSK_REG PINS
#define TOIE1_PIN    2
#define OCIE1B_PIN   3
#define OCIE1A_PIN   4
#define TICIE1_PIN   5

//TIMER1 TIFR_REG PINS
#define TOV1_PIN    2
#define OCF1B_PIN   3
#define OCF1A_PIN   4
#define ICF1_PIN   5

//TIMER1 TCCRA1_REG PINS
#define WGM10_PIN    0
#define WGM11_PIN    1
#define FOC1B_PIN    2
#define FOC1A_PIN    3
#define COM1B0_PIN   4
#define COM1B1_PIN   5
#define COM1A0_PIN   6
#define COM1A1_PIN   7

//TIMER1 TCCRB1_REG PINS
#define CS10_PIN    0
#define CS11_PIN    1
#define CS12_PIN    2
#define WGM12_PIN   3
#define WGM13_PIN   4
#define ICES1_PIN   6
#define ICNC1_PIN   7


#define OC1A 5
#define OC1B 4



#endif /* TIMER1_PWM_REG_H_ */