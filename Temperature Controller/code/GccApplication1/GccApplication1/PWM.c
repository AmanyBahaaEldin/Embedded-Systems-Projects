#include "MACROS.h"#include <avr/io.h>#include "PWM.h"#define F_CPU 1000000ul


void timer_pwm(double ocr_value)
{
	/* set OC0 as output pin */	SET_BIT(DDRB,3);
	
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	OCR0=ocr_value ;
	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//SET_BIT(TCCR0,CS01);
	
	SET_BIT(TCCR0,COM01);
	
	
}