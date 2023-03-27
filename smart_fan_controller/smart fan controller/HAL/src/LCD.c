/*
 * LCD.c
 *
 *  Created on: Feb 18, 2023
 *      Author: youssef's
 */

#include "../includes/LCD.h"

//pulsing the enable
void LCD_ENABLE_PULSE(void){
	DIO_vWritePin(LCD_CONTROL_PORT,ENABLE_SWITCH,HIGH);
	_delay_us(1);
	DIO_vWritePin(LCD_CONTROL_PORT,ENABLE_SWITCH,LOW);
}

void LCD_WRITE_COMMAND( uint8 command){
	DIO_vWritePortValue(LCD_DATA_PORT,((LCD_DATA_PORT & 0x0F)|(command & 0xF0))); //sending the upper nibble
	DIO_vWritePin(LCD_CONTROL_PORT,RS_SWITCH,LOW);
	LCD_ENABLE_PULSE(); //pulsing the enable
	_delay_us(200);
	DIO_vWritePortValue(LCD_DATA_PORT,((LCD_DATA_PORT & 0x0F)|(command <<4))); //sending the lower nibble
	LCD_ENABLE_PULSE();
	_delay_ms(2);
}

void LCD_clear_screen(void){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
	_delay_ms(2);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
}



void LCD_INIT(){

	DIO_vSetPortDirection(LCD_DATA_PORT,OUTPUT); //set data port direction to output
	DIO_vSetPinDirection(LCD_CONTROL_PORT,RS_SWITCH,OUTPUT); //set RS  output
	DIO_vSetPinDirection(LCD_CONTROL_PORT,ENABLE_SWITCH,OUTPUT); //set ENABLE to output
	//DIO_vSetPinDirection(LCD_CONTROL_PORT,RW_SWITCH,OUTPUT); //set ENABLE to output
	DIO_vWritePin(LCD_CONTROL_PORT, ENABLE_SWITCH, LOW);

	_delay_ms(40); //lcd power on delay


	LCD_WRITE_COMMAND(0x32);
	LCD_WRITE_COMMAND(0x20);
	LCD_WRITE_COMMAND(0x0E); // 2 line, 5*7 matrix in 4-bit mode
	LCD_WRITE_COMMAND(0x06); // Display the cursor blinking
	LCD_WRITE_COMMAND(0x01); // clear the screen
	//_delay_ms(2);
	//LCD_WRITE_COMMAND(LCD_SHIFT_CURSOR_TO_RIGHT); //shift the cursor to the right
}




void LCD_WRITE_CHAR(uint8 character){
	DIO_vWritePortValue(LCD_DATA_PORT,((LCD_DATA_PORT	& 0x0F)|(character & 0xF0))); //sending the upper nibble
	DIO_vWritePin(LCD_CONTROL_PORT,RS_SWITCH,HIGH); //RS = HIGH ,writing on data port of lcd
	LCD_ENABLE_PULSE(); //enable pulse
	_delay_us(200);
	DIO_vWritePortValue(LCD_DATA_PORT,((LCD_DATA_PORT	& 0x0F)|(character <<4))); //sending the lower nibble
	LCD_ENABLE_PULSE(); //enable pulse
	_delay_ms(2);
}

void LCD_WRITE_STRING(uint8 * string){
	uint32 i;
	for(i = 0;string[i] != 0;i++){
		LCD_WRITE_CHAR(string[i]);
	}
}





void LCD_GOTO_XY(uint8 line, uint8  position){

}

