#include "MACROS.h"
#include <avr/io.h>
#include <avr/interrupt.h>
void Timer_2_CTC_Init_Interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
	/* load a value in OCR0 */
	OCR0=0x62;   //initiate interrupt each 10ms
	/* select timer clock */
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	SET_BIT(TCCR2,CS21);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE2);
}



void Timer_2_CTC_off(void)
{
	//CLR_BIT(TIMSK,OCIE0);
	CLR_BIT(TIMSK,OCIE2);
}