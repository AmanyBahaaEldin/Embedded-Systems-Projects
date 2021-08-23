#include "SPI.h"

#include <avr/io.h>
#include "DIO.h"
#include "MACROS.h"
#include "SPI_Cfg.h"
#define F_CPU 1000000UL
#include <util/delay.h>



void SPI_MasterInit(void)
{
	/*Set SS / MOSI / SCK  as output pins for master*/
	 DIO_SetPINDir(SPI_Pins[0].Port_id,SPI_Pins[0].pin_number,SPI_Pins[0].pin_direction);
	 DIO_SetPINDir(SPI_Pins[1].Port_id,SPI_Pins[1].pin_number,SPI_Pins[1].pin_direction);
	 DIO_SetPINDir(SPI_Pins[3].Port_id,SPI_Pins[3].pin_number,SPI_Pins[3].pin_direction);
	
	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	
	/*Set clock to fosc/128*/
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	 
	// sample at falling edge
	mode1;
	
	/*Enable SPI*/
    SET_BIT(SPCR,SPE);
	/*set SS to high */
	DIO_Write(1,4,1);
	
}

void SPI_SlaveInit(void)
{
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*Set MISO as output*/
	DIO_SetPINDir(SPI_Pins[2].Port_id,SPI_Pins[2].pin_number,SPI_Pins[2].pin_direction);
}



void SPI_MasterTransmit( char Data)
{
	/*Start the transmission*/
	/*Put data on SPDR*/
	SPDR=Data;
	/*Wait until the transmission is finished*/
    while(!(SPSR&(1<<SPIF)));	 
}


char SPI_MasterReceive(void){
 /*Wait for the SPI buffer's full*/
 /* Wait for reception complete */ 
 while(!(SPSR&(1<<SPIF)));
 /*return SPI Buffer (data register)*/
 return SPDR;
}
unsigned char SPI_SlaveReceive(unsigned char Data)
{
	/*Put data on SPDR*/
	SPDR=Data;
	/*Wait until data is received in SPI register*/
	while(READ_BIT(SPSR,SPIF)==0);
	/*read the received data*/
	return SPDR ;
}


