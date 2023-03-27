/*
 * main.c
 *
 * Created: 2/23/2023 1:03:19 PM
 *  Author: youssef's
 */ 

//includes
#include "APP/includes/FUNCTIONS.h"

int main(void)
{	
	INIT();
	while(1){
		TEMP_DC_MOTOR_START();	
	}
}