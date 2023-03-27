/*
 * LCD.h
 *
 *  Created on: Feb 18, 2023
 *      Author: youssef's
 */

#ifndef HAL_INCLUDES_LCD_H_
#define HAL_INCLUDES_LCD_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"
#include "../../MCAL/includes/DIO_Interface.h"
#include "../../MCAL/includes/DIO_REG.h"
#include "util/delay.h"



#define LCD_DATA_PORT 					   	PORT_A
#define LCD_CONTROL_PORT 				    PORT_B

//control registers
#define RS_SWITCH                       PIN0
#define RW_SWITCH                       PIN1
#define ENABLE_SWITCH                   PIN2

#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_FUNCTION_INITIALLIZE_4BIT_MODE          (0x02)
#define LCD_SHIFT_CURSOR_TO_RIGHT   				(0x06)
#define LCD_DISP_ON_CURSOR_OFF   					(0x0C)
#define LCD_DISP_ON_CURSOR_BLINKING  				(0x0E)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_DISPLAY_LEFT   					(0x18)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_FUNCTION_1LINE_8BIT_MODE                (0x30)
#define LCD_FUNCTION_1LINE_4BIT_MODE                (0x20)









#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_SHIFT   						(0x07)

#define LCD_ENTRY_MODE								(0x06)

void LCD_INIT();
void LCD_WRITE_COMMAND( uint8 command);
void LCD_WRITE_CHAR(uint8 character);
void LCD_WRITE_STRING(uint8 * string);
void LCD_ENABLE_PULSE(void);
void LCD_clear_screen(void);
void LCD_GOTO_XY(uint8 line, uint8  position);


#endif /* HAL_INCLUDES_LCD_H_ */
