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
void TIMER0_Delay_MS_with_Blocking(uint16 Milli_Seconds,Timer_Config* Config){	if(Config->Mode == CTC_MODE){		OCR0 = 250;		/*******************************************************************************		*********************************assuming that CPU  frequency is 16MHZ *********		this means that the tick takes 1/16*10^6  (0.25 microsecond) , by multiplying this		 by the prescaler  (64) this increases  the time of  each tick so that i can set 		 the OCR0 by 250 at CCT MODE and setting the TCNT0 by 5 ***************************/				TCCR0 |= CPU_CLK_PRESCALER_64; //setting the clock  used in the timer to be with prescaler 64  that will make the timer start counting 		while(Milli_Seconds>0)		{			while((TIFR&OCF0) == 0 ); //if the flag is set by 1 then the counter is done 			SET_BIT(TIFR,OCF0); //setting the flag by 1 again to reset the flag 			Milli_Seconds--;		}	}	else if(Config->Mode == NORMAL_MODE){				while(Milli_Seconds>0)		{	TCNT0 = 5;			while((TIFR&TOV0) == 0); //if the flag is set by 1 then the counter is done			SET_BIT(TIFR,TOV0); //setting the flag by 1 again to reset the flag 			Milli_Seconds--;		}	}	TCCR0 &= 0xF8; //turning the timer off after delaying the nedded milliseconds }//setting a delay in microsecond with blocking the programvoid TIMER0_Delay_MicroS_with_Blocking(uint16 Milli_Seconds,Timer_Config* Config){	if(Config->Mode == CTC_MODE){		OCR0 = 16;		TCCR0 |= CPU_CLK_NO_PRESCALER; //setting the clock  used in the timer to be with prescaler 64  that will make the timer start counting 		while(Milli_Seconds>0)		{			while((TIFR&OCF0) == 0 ); //if the flag is set by 1 then the counter is done 			SET_BIT(TIFR,OCF0); //setting the flag by 1 again to reset the flag 			Milli_Seconds--;		}	}	else if(Config->Mode == NORMAL_MODE){				while(Milli_Seconds>0)		{	TCNT0 = 239;			while((TIFR&TOV0) == 0); //if the flag is set by 1 then the counter is done			SET_BIT(TIFR,TOV0); //setting the flag by 1 again to reset the flag 			Milli_Seconds--;		}	}	TCCR0 &= 0xF8; //turning the timer off after delaying the needed milliseconds }	//setting a delay in milliseconds without blocking the programvoid TIMER0_Delay_Without_Blocking(uint16 Milli_Seconds){	}