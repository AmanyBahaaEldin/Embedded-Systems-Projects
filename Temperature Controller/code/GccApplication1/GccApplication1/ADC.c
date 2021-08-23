/*
 * ADC.c
*/ 
#include <avr/io.h>
#include "MACROS.h"
#include "TYPE_DEFs.h"
#include "DIO.h"
#include "ADC.h"
#include "ADC_Cfg.h"

void ADC_Init(void)
{
	CONFIG_VREF();
	ENABLE_ADC();
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}

void CONFIG_VREF(void)
{
	SET_BIT(ADMUX,REFS0);
}

void ENABLE_ADC(void)
{
	SET_BIT(ADCSRA,ADEN);	
}


void START_CONV(void)
{
	SET_BIT(ADCSRA,ADSC);
}


void CLR_ADIF(void)
{
	SET_BIT(ADCSRA,ADIF);
}

uint8 ADC_Read(void)
{
	uint8 ReadValue;
	START_CONV();
	while(CHECK_ADIF);
	CLR_ADIF();
	ReadValue = (ADCL);
	ReadValue |= (ADCH << 8);
	return ReadValue;
}