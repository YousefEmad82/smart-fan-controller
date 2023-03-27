/*
 * TIMERS.c
 *
 * Created: 2/25/2023 3:08:47 PM
 *  Author: youssef's
 */ 
#include "../includes/TIMER0_REG.h"
#include "../includes/TIMER0_interface.h"




/************************************************************************/
/*								APIs                                    */
/************************************************************************/
//function of setting the configurations of the timer
void TIMER0_SetConfig(Timer_Config* Config){
	TCCR0 |= Config->Mode;          //setting the timer  mode 
	
	TIMSK |= Config->Enable_Interrupt;	 //setting the interrupt 
}

//setting a delay in millisecond with blocking the program
void TIMER0_Delay_MS_with_Blocking(uint16 Milli_Seconds,Timer_Config* Config){