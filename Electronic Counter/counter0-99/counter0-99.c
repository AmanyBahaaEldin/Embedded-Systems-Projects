/*
 * counter0_99.c
 *
 * Created: 2021-04-10 3:57:25 PM
 *  Author: Amany Bahaa El-Din
 */ 


//functions prototypes
void seven_segment_write(unsigned char counter);
unsigned char counter_inc(unsigned char counter);
unsigned char btn_read(unsigned char portname , unsigned char pinnumber);

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

//defining some useful macros
#define SET_BIT(reg,pin) reg|=(1<<pin)
#define CLR_BIT(reg,pin) reg&=(~(1<<pin))
#define READ_BIT(reg,pin) ((reg&(1<<pin))>>pin)

//defining global variables
unsigned char btn =0;
unsigned char counter=0;

int main(void)
{
	
	DDRB |= (1<<PINB0) |(1<<PINB1) |(1<<PINB2) |(1<<PINB4) |(1<<PINB5) |(1<<PINB6);
	CLR_BIT(DDRB , PINB3);
	
	
	SET_BIT(PORTB , PINB5);
	SET_BIT(PORTB , PINB6);
	
    while(1)
    {
		btn= btn_read(PINB , PINB3);
		if (btn ==1 && counter <100)
		{
			counter += 1;
		}			
			
		for (int i=0 ; i<10 ; i++)
		{
			
			seven_segment_write(counter%10);
			SET_BIT(PORTB , PINB5);
			//delay for displaying the units on the seven segment before displaying the tenths on the other seven segment
			_delay_ms(10);
			CLR_BIT(PORTB , PINB5);
			
			seven_segment_write(counter/10);
			SET_BIT(PORTB , PINB6);
			//delay for displaying the tenths on the seven segment before displaying the units on the other seven segment
			_delay_ms(10);
			CLR_BIT(PORTB , PINB6);
		}
			
	    //to restart counting after writing 99 on the seven segments
		 if(counter>= 100)
		{
			counter=0;	
		}	 
    }
	
}
//function for setting and clearing the required pins responsible for writing each number on each seven segment
void seven_segment_write(unsigned char counter)
{
	//for writing '0' on the seven segment
	if (counter == 0)
	{
		CLR_BIT(PORTB , PINB0);
		CLR_BIT(PORTB , PINB1);
		CLR_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '1' on the seven segment
	else if (counter ==1)
	{
		SET_BIT(PORTB , PINB0);
		CLR_BIT(PORTB , PINB1);
		CLR_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '2' on the seven segment
	else if (counter ==2)
	{
		CLR_BIT(PORTB , PINB0);
		SET_BIT(PORTB , PINB1);
		CLR_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '3' on the seven segment
	else if (counter ==3)
	{
		SET_BIT(PORTB , PINB0);
		SET_BIT(PORTB , PINB1);
		CLR_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '4' on the seven segment
	else if (counter ==4)
	{
		CLR_BIT(PORTB , PINB0);
		CLR_BIT(PORTB , PINB1);
		SET_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '5' on the seven segment
	else if (counter ==5)
	{
		SET_BIT(PORTB , PINB0);
		CLR_BIT(PORTB , PINB1);
		SET_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '6' on the seven segment
	else if (counter ==6)
	{
		CLR_BIT(PORTB , PINB0);
		SET_BIT(PORTB , PINB1);
		SET_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '7' on the seven segment
	else if (counter ==7)
	{
		SET_BIT(PORTB , PINB0);
		SET_BIT(PORTB , PINB1);
		SET_BIT(PORTB , PINB2);
		CLR_BIT(PORTB , PINB4);
	}
	//for writing '8' on the seven segment
	else if (counter ==8)
	{
		CLR_BIT(PORTB , PINB0);
		CLR_BIT(PORTB , PINB1);
		CLR_BIT(PORTB , PINB2);
		SET_BIT(PORTB , PINB4);
	}
	//for writing '9' on the seven segment
	else if (counter ==9)
	{
		SET_BIT(PORTB , PINB0);
		CLR_BIT(PORTB , PINB1);
		CLR_BIT(PORTB , PINB2);
		SET_BIT(PORTB , PINB4);
	}
	
}

//function for reading the value on the pin connected to the button 
//to check if the button is on or off
unsigned char btn_read(unsigned char portname , unsigned char pinnumber)
{
	unsigned char x =0;
	x =READ_BIT(portname , pinnumber);
	return x;
	
}
