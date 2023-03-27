/*
 * TIMERS.h
 *
 * Created: 2/25/2023 3:08:33 PM
 *  Author: youssef's
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"

/***************************************************************************************************************/
/***************************************TCCR0 DESCRIPTION************************************************************/
/*bits 2:0 are used to select the source of the clock
000 ------> no clock source
001 ------> cpu clock is used
010 ------> cpu clock/8 (from prescaler)
011 ------> cpu clock/64 (from prescaler)
100 ------> cpu clock/256 (from prescaler)
101 ------> cpu clock/1024 (from prescaler)
110 ------> external clock on T0 pin is used on falling edge
111 ------> external clock on T0 pin is used on rising edge 
*********************************************************************************************************************
pins 6,3
00 ------> normal mode
01 ------> PWM, phase correct mode
10 ------> CTC mode
11 ------> Fast PWM mode
*/



/***************************************************************************************************************/
/***************************************TIFR DESCRIPTION************************************************************/
/*bits 1:0 are used to check the interrupt flags
bit0 -----> output compare flag
bit1 -----> overflow flag
if the bit is 1 then set it to 1  */

#define TCNT0                 *(volatile uint8 *)(0x52) //timer counter register 
#define TCCR0                 *(volatile uint8 *)(0x53) //timer counter control register
#define OCR0                  *(volatile uint8 *)(0x5C) //timer output compare register
#define TIFR                  *(volatile uint8 *)(0x58) //timer interrupt flag register 
#define TIMSK                 *(volatile uint8 *)(0x59) //timer interrupt mask register


#endif /* TIMERS_H_ */