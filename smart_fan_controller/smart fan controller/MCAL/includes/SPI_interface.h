/*
 * SPI_interface.h
 *
 * Created: 3/4/2023 11:18:57 AM
 *  Author: youssef's
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include "SPI_REG.h"

//SPI pin configuration 
#define MISO  6
#define MOSI  5
#define SCK   7
#define SS    4


//SPCR: SPI Control Register PINS
#define SPR0    0 
#define SPR1	1
#define CPHA	2
#define CPOL	3
#define MSTR	4
#define DORD	5
#define SPE		6
#define SPIE	7

//SPSR: SPI Status Register
#define SPI2X	0
#define WCOL	6
#define SPIF	7

//modes of SPI
#define  MASTER 0
#define  SLAVE  1

//SPI operations 
#define  READ  0
#define  WRITE 1

//configuration
#define SPI_MODE SLAVE

//APIs
void SPI_INIT();
uint8 SPI_SEND_RECIEVE(uint8 data);









#endif /* SPI_INTERFACE_H_ */