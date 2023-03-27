/*
 * SPI_REG.h
 *
 * Created: 3/4/2023 11:18:39 AM
 *  Author: youssef's
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_
#include "../../LIB_FOLDER/std_types.h"
#include "../../LIB_FOLDER/common_macros.h"

#define DDRB_REG           *((volatile uint8 *)(0x37))
#define PORTB_REG          *((volatile uint8 *)(0x38))
#define SPDR_REG           *((volatile uint8 *)(0x2F))
#define SPSR_REG           *((volatile uint8 *)(0x2E))
#define SPCR_REG           *((volatile uint8 *)(0x2D))








#endif /* SPI_REG_H_ */