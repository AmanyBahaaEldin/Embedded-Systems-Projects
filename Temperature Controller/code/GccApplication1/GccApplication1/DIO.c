#include <avr/io.h>
#include "DIO.h"
#include "MACROS.h"
#include "TYPE_DEFs.h"
#include "DIO_Cfg.h"

/*base address lookup table*/
const unsigned char PortBaseAddresses[NUM_OF_PORTS] =
{   PORTA_BASE_ADDRESS,
	PORTB_BASE_ADDRESS,
	PORTC_BASE_ADDRESS,
    PORTD_BASE_ADDRESS};


void DIO_SetPINDir(uint8 PORT_ID,uint8 pinnumber,uint8 direction)
{
	
		if(direction==1)
		{
			
			SET_BIT(DDR_REG(PORT_ID),pinnumber);//Set the direction of the given pin in port A as output
		}
		else
		{
			CLR_BIT(DDR_REG(PORT_ID),pinnumber);//Set the direction of the given pin in port A as input
		}
	
	
	
	
}


void DIO_Write(unsigned char PORT_ID,unsigned char pinnumber,unsigned char outputvalue)
{
	
	
		if(outputvalue==1)
		{
			
			SET_BIT(PORT_REG(PORT_ID),pinnumber);//Set the direction of the given pin in port A as output
		}
		else
		{
			CLR_BIT(PORT_REG(PORT_ID),pinnumber);//Set the direction of the given pin in port A as input
		}
	
}


uint8 DIO_Read_PIN(uint8 PORT_ID,uint8 pinnumber, uint8*return_value)
{
	
		*return_value=READ_BIT(PIN_REG(PORT_ID),pinnumber);
}		



void DIO_Connect_Pull_Up(unsigned char PORT_ID,unsigned char pinnumber,unsigned char connect_pullup)
{
	if(connect_pullup==1)
	{
		SET_BIT(PORT_REG(PORT_ID),pinnumber);
	}
	else
	{
		CLR_BIT(PORT_REG(PORT_ID),pinnumber);
	}
}