/*
 * SPI.c
 *
 * Created: 3/4/2023 11:18:17 AM
 *  Author: youssef's
 */ 
#include "../includes/SPI_interface.h"



/************************************************************************/
/*								APIs                                    */
/************************************************************************/
void SPI_INIT(){
	#if (SPI_MODE == MASTER)
		//making those three pins as output 
		SET_BIT(DDRB_REG,MOSI);
		SET_BIT(DDRB_REG,SCK);
		SET_BIT(DDRB_REG,SS);
		
		//making the MISO pin as input 
		CLEAR_BIT(DDRB_REG,MISO);
		
		//set SS
		SET_BIT(PORTB_REG,SS);
		
		//enabling SPI
		SET_BIT(SPCR_REG,SPE);
		
		//setting SPI to master
		SET_BIT(SPCR_REG,MSTR);
		
		
		//selecting the clock prescaler
		SET_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,SPR1);
		CLEAR_BIT(SPSR_REG,SPI2X);
		
		

	#elif (SPI_MODE == SLAVE)
		//making these pins as input
		CLEAR_BIT(DDRB_REG,MOSI);
		CLEAR_BIT(DDRB_REG,SCK);
		CLEAR_BIT(DDRB_REG,SS);
		
		//making the MISO pin as output
		SET_BIT(DDRB_REG,MISO);
		
		//enabling SPI
		SET_BIT(SPCR_REG,SPE);
		//setting SPI to slave
		CLEAR_BIT(SPCR_REG,MSTR);
		
		//clearing bit CPHA
		CLEAR_BIT(SPCR_REG,CPHA);
		//clearing CPOL 
		CLEAR_BIT(SPCR_REG,CPOL);
		
		//selecting the clock prescaler
		SET_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,SPR1);
		CLEAR_BIT(SPSR_REG,SPI2X);
	#endif
}


uint8 SPI_SEND_RECIEVE(uint8 data){
			if(SPI_MODE ==MASTER)
			CLEAR_BIT(PORTB_REG,SS);
			SPDR_REG  = data;
			while(READ_BIT(SPSR_REG,SPIF)==0);
			if(SPI_MODE ==MASTER)
			SET_BIT(PORTB_REG,SS);
			return SPDR_REG;
		}




