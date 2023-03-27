/*
 * TIMER__PWM.c
 *
 * Created: 3/1/2023 9:26:32 PM
 *  Author: youssef's
 */ 

#include "../includes/TIMER1_PWM_interface.h"



/************************************************************************/
/*								APIs                                    */
/************************************************************************/
void PWM_Init(void){
	#if(PWM_mode == FAST_PWM)	
	//channel A	
	CLEAR_BIT(TCCR1A,WGM10_PIN);
	SET_BIT(TCCR1A,WGM11_PIN);
	//channel B
	SET_BIT(TCCR1B,WGM12_PIN);
    SET_BIT(TCCR1B,WGM13_PIN);
	#elif (PWM_mode == PHASE_CORRECT)
	//channel A
	CLEAR_BIT(TCCR1A,WGM10_PIN);
	SET_BIT(TCCR1A,WGM11_PIN);
	//channel B
	CLEAR_BIT(TCCR1B,WGM12_PIN);
	SET_BIT(TCCR1B,WGM13_PIN);
	#endif
}

void PWM_Generate_CHANNELA(uint8 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq){
	uint16 TOP;
	SET_BIT(PWM_OUTPUT_REG,5); //setting portD bit5 as output 
	
	#if (PWM_polarity == NON_INVERTING)
	SET_BIT(TCCR1A,COM1A1_PIN);
	CLEAR_BIT(TCCR1A,COM1A0_PIN);
	#elif (PWM_polarity == INVERTING)
	SET_BIT(TCCR1A,COM1A1_PIN);
	SET_BIT(TCCR1A,COM1A0_PIN);
	#endif
	
	#if (PWM_mode == FAST_PWM)
		if (Copy_u8Dutyfreq <=1000)
		{
			TOP = (F_CPU - 64*Copy_u8Dutyfreq)/(Copy_u8Dutyfreq*64);
			SET_BIT(TCCR1B,CS10_PIN);
			SET_BIT(TCCR1B,CS11_PIN);
			CLEAR_BIT(TCCR1B,CS12_PIN);
		}
		else if(Copy_u8Dutyfreq <10000){
			TOP = (F_CPU - 8*Copy_u8Dutyfreq)/(Copy_u8Dutyfreq*8);
			CLEAR_BIT(TCCR1B,CS10_PIN);
			SET_BIT(TCCR1B,CS11_PIN);
			CLEAR_BIT(TCCR1B,CS12_PIN);
		}
		else{
			TOP = (F_CPU - Copy_u8Dutyfreq)/(Copy_u8Dutyfreq);
			SET_BIT(TCCR1B,CS10_PIN);
			CLEAR_BIT(TCCR1B,CS11_PIN);
			CLEAR_BIT(TCCR1B,CS12_PIN);
		}
		ICR1_REG = TOP;
		OCR1A_REG = ((Copy_u8DutyCycle)*(TOP+1))/100; 
		
	#elif (PWM_mode == PHASE_CORRECT)
		SET_BIT(PWM_OUTPUT_REG,4); //setting portD bit4 as output 
		
		if (Copy_u8Dutyfreq <=500)
		{
			TOP = (F_CPU)/(Copy_u8Dutyfreq*2*64);
			SET_BIT(TCCR1B,CS10_PIN);
			SET_BIT(TCCR1B,CS11_PIN);
			CLEAR_BIT(TCCR1B,CS12_PIN);
		}
		else if(Copy_u8Dutyfreq <5000){
			TOP = (F_CPU)/(Copy_u8Dutyfreq*2*8);
			CLEAR_BIT(TCCR1B,CS10_PIN);
			SET_BIT(TCCR1B,CS11_PIN);
			CLEAR_BIT(TCCR1B,CS12_PIN);
		}
		else{
			TOP = (F_CPU)/(Copy_u8Dutyfreq*2);
			SET_BIT(TCCR1B,CS10_PIN);
			CLEAR_BIT(TCCR1B,CS11_PIN);
			CLEAR_BIT(TCCR1B,CS12_PIN);
		}
		ICR1_REG = TOP;
		OCR1A_REG = ((Copy_u8DutyCycle)*(TOP))/100;
	#endif
}
void PWM_Generate_CHANNELB(uint8 Copy_u8DutyCycle, uint32 Copy_u8Dutyfreq){
	uint16 TOP;
	SET_BIT(PWM_OUTPUT_REG,5); //setting portD bit5 as output
	
	#if (PWM_polarity == NON_INVERTING)
	SET_BIT(TCCR1A,COM1B1_PIN);
	CLEAR_BIT(TCCR1A,COM1B0_PIN);
	#elif (PWM_polarity == INVERTING)
	SET_BIT(TCCR1A,COM1B1_PIN);
	SET_BIT(TCCR1A,COM1B0_PIN);
	#endif
	
	#if (PWM_mode == FAST_PWM)
	if (Copy_u8Dutyfreq <=1000)
	{
		TOP = (F_CPU - 64*Copy_u8Dutyfreq)/(Copy_u8Dutyfreq*64);
		SET_BIT(TCCR1B,CS10_PIN);
		SET_BIT(TCCR1B,CS11_PIN);
		CLEAR_BIT(TCCR1B,CS12_PIN);
	}
	else if(Copy_u8Dutyfreq <10000){
		TOP = (F_CPU - 8*Copy_u8Dutyfreq)/(Copy_u8Dutyfreq*8);
		CLEAR_BIT(TCCR1B,CS10_PIN);
		SET_BIT(TCCR1B,CS11_PIN);
		CLEAR_BIT(TCCR1B,CS12_PIN);
	}
	else{
		TOP = (F_CPU - Copy_u8Dutyfreq)/(Copy_u8Dutyfreq);
		SET_BIT(TCCR1B,CS10_PIN);
		CLEAR_BIT(TCCR1B,CS11_PIN);
		CLEAR_BIT(TCCR1B,CS12_PIN);
	}
	ICR1_REG = TOP;
	OCR1B_REG = ((Copy_u8DutyCycle)*(TOP+1))/100;
	
	#elif (PWM_mode == PHASE_CORRECT)
	SET_BIT(PWM_OUTPUT_REG,4); //setting portD bit4 as output
	
	if (Copy_u8Dutyfreq <=500)
	{
		TOP = (F_CPU)/(Copy_u8Dutyfreq*2*64);
		SET_BIT(TCCR1B,CS10_PIN);
		SET_BIT(TCCR1B,CS11_PIN);
		CLEAR_BIT(TCCR1B,CS12_PIN);
	}
	else if(Copy_u8Dutyfreq <5000){
		TOP = (F_CPU)/(Copy_u8Dutyfreq*2*8);
		CLEAR_BIT(TCCR1B,CS10_PIN);
		SET_BIT(TCCR1B,CS11_PIN);
		CLEAR_BIT(TCCR1B,CS12_PIN);
	}
	else{
		TOP = (F_CPU)/(Copy_u8Dutyfreq*2);
		SET_BIT(TCCR1B,CS10_PIN);
		CLEAR_BIT(TCCR1B,CS11_PIN);
		CLEAR_BIT(TCCR1B,CS12_PIN);
	}
	ICR1_REG = TOP;
	OCR1B_REG = ((Copy_u8DutyCycle)*(TOP))/100;
	#endif
}
