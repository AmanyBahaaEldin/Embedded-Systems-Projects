#include "SPI_Cfg.h"

const SPI_Confg_pins SPI_Pins[SPI_NUM_PINS]=
{ 
	{ /*Set SS as output pins for master*/
		1,4,1
		
	},
	{
		/*Set MOSI as output pins for master*/
		1,5,1
		
	},
	{
		/*Set MISO as output pins for Slave */
		1,6,1
	},
	{
		
		/*Set SCK as output pins for master*/
		1,7,1
	},
};