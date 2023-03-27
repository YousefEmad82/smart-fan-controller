/*
 * L298N.c
 *
 * Created: 3/2/2023 7:50:33 PM
 *  Author: youssef's
 */ 
#include "../includes/L298N.h"

void MOTOR_A_INIT(){
	DIO_vSetPinDirection(INPUT1,OUTPUT);
	DIO_vSetPinDirection(INPUT2,OUTPUT);
	PWM_Init();

}
void MOTOR_A_ROTATE(uint8 direcion,uint8 duty_cycle, uint32 freq ){
	if(direcion == CLOCK_WISE){
		DIO_vWritePin(INPUT1,HIGH);
		DIO_vWritePin(INPUT2,LOW);
	}
	else if(direcion == ANTI_CLOCK_WISE){
		DIO_vWritePin(INPUT1,LOW);
		DIO_vWritePin(INPUT2,HIGH);
	}
	PWM_Generate_CHANNELA(duty_cycle,freq);
}

void MOTOR_B_INIT(){
	DIO_vSetPinDirection(INPUT3,OUTPUT);
	DIO_vSetPinDirection(INPUT4,OUTPUT);
	PWM_Init();
}
void MOTOR_B_ROTATE(uint8 direcion,uint8 duty_cycle, uint32 freq){
	if(direcion == CLOCK_WISE){
		DIO_vWritePin(INPUT3,HIGH);
		DIO_vWritePin(INPUT4,LOW);
	}
	else if(direcion == ANTI_CLOCK_WISE){
		DIO_vWritePin(INPUT3,LOW);
		DIO_vWritePin(INPUT4,HIGH);
	}
	PWM_Generate_CHANNELB(duty_cycle,freq);
}