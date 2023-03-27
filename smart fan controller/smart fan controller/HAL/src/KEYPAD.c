/*
 * keypad.c
 *
 *  Created on: Feb 18, 2023
 *      Author: youssef's
 */
#include "../includes/KEYPAD.h"



uint8 KEYPAD_Keys[N_Row][N_Col] = KEYPAD_KEYS;
uint8 KEYPAD_RowsPins[N_Row] = KEYPAD_ROWS;
uint8 KEYPAD_ColsPins[N_Col] = KEYPAD_COLS;

void keypad_init() {

	/* Set Columns direction to Output */
	DIO_vSetPinDirection(KEYPAD_PORT_OUTPUT, C0, OUTPUT);
	DIO_vSetPinDirection(KEYPAD_PORT_OUTPUT, C1, OUTPUT);
	DIO_vSetPinDirection(KEYPAD_PORT_OUTPUT, C2, OUTPUT);
	DIO_vSetPinDirection(KEYPAD_PORT_OUTPUT, C3, OUTPUT);

	/* Set Rows direction to Input */
	DIO_vSetPinDirection(KEYPAD_PORT_INPUT, R0, INPUT_WITH_PULLUP);
	DIO_vSetPinDirection(KEYPAD_PORT_INPUT, R1, INPUT_WITH_PULLUP);
	DIO_vSetPinDirection(KEYPAD_PORT_INPUT, R2, INPUT_WITH_PULLUP);
	DIO_vSetPinDirection(KEYPAD_PORT_INPUT, R3, INPUT_WITH_PULLUP);

	/* Set Column Initial Values to 1111 */
	DIO_vWritePin(KEYPAD_PORT_OUTPUT, C0, HIGH);
	DIO_vWritePin(KEYPAD_PORT_OUTPUT, C1, HIGH);
	DIO_vWritePin(KEYPAD_PORT_OUTPUT, C2, HIGH);
	DIO_vWritePin(KEYPAD_PORT_OUTPUT, C3, HIGH);

}

//returns either the pressed key or -1 if no key is pressed
void keypad_get_pressed(uint8  * value) {
	uint8 row, col, pin_value, key_value = 1, flag = 0;
	while(1){
	for (col = 0; col < N_Col; col++) {
		//setting all columns pins to high
		DIO_vWritePin(KEYPAD_PORT_OUTPUT, C0, HIGH);
		DIO_vWritePin(KEYPAD_PORT_OUTPUT, C1, HIGH);
		DIO_vWritePin(KEYPAD_PORT_OUTPUT, C2, HIGH);
		DIO_vWritePin(KEYPAD_PORT_OUTPUT, C3, HIGH);

		//setting one pin of the column to low
		DIO_vWritePin(KEYPAD_PORT_OUTPUT, col+4, LOW);
		for (row = 0; row < N_Row; row++) {
			if (!DIO_u8GetPinValue(KEYPAD_PORT_INPUT, KEYPAD_RowsPins[row])) {
				*value = KEYPAD_Keys[row][col];
				return ;
				 //break;
				 
			}
		}
	}
	
	* value = -1;
	}
}
