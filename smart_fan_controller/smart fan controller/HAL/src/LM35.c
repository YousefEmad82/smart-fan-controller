/*
 * LM35.c
 *
 * Created: 3/2/2023 7:41:21 PM
 *  Author: youssef's
 */ 

#include "../includes/LM35.h"
void  LM35_init(){
	ADC_INIT(ADC0);
}

uint8 LM35_READ(){
	return (ADC_READ(ADC0)*5*100)/1023;
}