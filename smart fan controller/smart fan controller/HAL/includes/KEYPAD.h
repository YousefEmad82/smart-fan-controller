/*
 * KEYPAD.h
 *
 *  Created on: Feb 18, 2023
 *      Author: youssef's
 */

#ifndef HAL_INCLUDES_KEYPAD_H_
#define HAL_INCLUDES_KEYPAD_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../MCAL/includes/DIO_Interface.h"
#include "../../LIB_FOLDER/std_types.h"

//ports used for columns and rows of keypad
#define KEYPAD_PORT_INPUT      PORT_C
#define KEYPAD_PORT_OUTPUT     PORT_C

//number of rows and columns of the keypad
#define N_Col 4
#define N_Row 4

//keypad keys
#define KEYPAD_KEYS   {    {'7', '8', '9', '/'}, \
						   {'4', '5', '6', '*'}, \
						   {'1', '2', '3', '-'}, \
						   {'r', '0', '=', '+'}}
//row pins
#define R0 0
#define R1 1
#define R2 2
#define R3 3

//columns pins
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_COLS  {C0, C1, C2, C3}
#define KEYPAD_ROWS  {R0, R1, R2, R3}

//functions of the keypad
void keypad_init();
void keypad_get_pressed(uint8  * value);


#endif /* HAL_INCLUDES_KEYPAD_H_ */
