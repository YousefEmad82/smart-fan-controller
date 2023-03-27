/*
 * TIMER0_interface.h
 *
 * Created: 2/25/2023 3:10:20 PM
 *  Author: youssef's
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#include "TIMER0_REG.h"


//modes of the timer0 
#define NORMAL_MODE      0x00
#define CTC_MODE         0x08

//TIMSK REGISTER BITS
//Output compare  interrupt enable  modes 
#define OCIE_ENABLE        0x02
#define OCIE_DISABLE       0x00 
// timer oveflow interrupt enable modes
#define TOIE_ENABLE        0x01
#define TOIE_DISABLE       0x00

//TIFR REGISTER BITS
//bit_0 --->TOV0   //the overflow flag
//bit_1 --->OCF0   //the output compare flag
#define TOV0             0
#define OCF0             1



//clock select 
#define NO_CLK                       0
#define CPU_CLK_NO_PRESCALER         1
#define CPU_CLK_PRESCALER_8          2
#define CPU_CLK_PRESCALER_64         3
#define CPU_CLK_PRESCALER_265        4
#define CPU_CLK_PRESCALER_1024       5
#define EXTERNAL_CLK_FALLING_EDGE    6
#define EXTERNAL_CLK_RISING_EDGE     7





typedef struct {
		uint8 Mode;
		uint8 Enable_Interrupt;	
}Timer_Config;


//function of setting the configurations of the timer
void TIMER0_SetConfig(Timer_Config* Config);

//setting a delay in millisecond with blocking the program 
void TIMER0_Delay_with_Blocking(uint16 Milli_Seconds,Timer_Config* Config);//setting a delay in milliseconds without blocking the program void TIMER0_Delay_MS_Without_Blocking(uint16 Milli_Seconds);//setting a delay in Microsecond without blocking the program
void TIMER0_Delay_MicroS_with_Blocking(uint16 Milli_Seconds,Timer_Config* Config);


#endif /* TIMER0_INTERFACE_H_ */