/*
 * main.c
 *
 * Created: 2/23/2023 1:03:19 PM
 *  Author: youssef's
 */ 
//includes
#include "../includes/FUNCTIONS.h"



/************************************************************************/
/*                                APIs                                  */
/************************************************************************/

//the initialization function 
void INIT(void){
	LM35_init();
	MOTOR_B_INIT();
	LCD_INIT();
}

//the system start function 
void TEMP_DC_MOTOR_START(void){	
	uint8 string_data[16];
		uint8 temperature = LM35_READ();
		uint8 speed;
		if(temperature<25){
			MOTOR_B_ROTATE(CLOCK_WISE,0,0);
			speed =0;
		}
		else if(temperature<30){
			MOTOR_B_ROTATE(CLOCK_WISE,30,5000);
			speed = 30;
		}
		else if(temperature<35){
			MOTOR_B_ROTATE(CLOCK_WISE,50,10000);
			speed = 50;
		}
		else{
			MOTOR_B_ROTATE(CLOCK_WISE,80,20000);
			speed = 80;
		}
		sprintf(string_data,"T=%d SPEED=%d%  ",temperature,speed);
		LCD_WRITE_COMMAND(0x80); //return the cursor to the right
		LCD_WRITE_STRING(string_data);
}
	
	
	
