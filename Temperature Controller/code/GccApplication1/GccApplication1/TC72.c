#include <avr/io.h>
#include "DIO.h"
#include "MACROS.h"
#include "TC72.h"
#include "SPI.h"
#include "TC72_Cfg.h"
#include "TYPE_DEFs.h"
#include "LCD.h"
#define F_CPU 1000000UL
#include <util/delay.h>


void tc72Init(void){
	 SPI_MasterInit();
	/* make CE to TC72 as 1 */
	SET_BIT(PORTB,4);
	/*Select Control Register*/
	SPI_MasterTransmit(CONTROL_REG_WRITE); /* to make write operation on TC72 sensor */
	/*Select Continuous temperature Conversion*/
	SPI_MasterTransmit(CONTINUOUS_TEMPERATURE_CONVERSION);
	
	/* make CE to TC72 as 0 */
	CLR_BIT(PORTB,4);
	_delay_ms(200);

}


char_t temp_read_msb(void){
	char_t msb;
	SET_BIT(PORTB,4);
	/*Read the MSB*/
	SPI_MasterTransmit(READ_MSB_TEMP );
	/*Issue one more clock frame to force data out*/
	SPI_MasterTransmit(CONTROL_REG_READ);
	CLR_BIT( PORTB,4);
	//_delay_ms(1);
	_delay_us(100);
	msb=SPI_MasterReceive();

	SET_BIT(PORTB,4);
	return msb;
	
	
}

char_t temp_read_lsb(void)
{
	/*Read The LSB*/
	char_t lsb;
	SET_BIT(PORTB,4);
	/*Read The LSB*/
	SPI_MasterTransmit( READ_LSB_TEMP );
	/*Issue one more clock frame to force data out*/
	SPI_MasterTransmit(CONTROL_REG_READ);
	CLR_BIT( PORTB,4);
	// _delay_ms(1);
	_delay_us(100);
	lsb=SPI_MasterReceive();
	return lsb;
	
}


