#include <avr/io.h>
#include <avr/interrupt.h>

#include "DIO.h"
#include "LCD.h"
#include "TYPE_DEFs.h"
#include "Display_Manager.h"
#include "Temp_Manager.h"
#include "KEYPAD.h"
#include "MACROS.h"
#include "ADC.h"
#include "ADC_Cfg.h"
#include "Timer_2.h"
#include "Heater_Controller.h"
#define F_CPU 1000000ul
#include <util/delay.h>

#define STANDBY "STANDBY  "
#define OPERATIONAL "OPERATION"
#define NORMAL "NORMAL   "
#define ERROR "ERROR    "

volatile long int counter1=0;
volatile uint8 counter2=0;
void main(void)
{
	volatile uint8 bit_M= 2;
	volatile uint8 bit_L= 5;
	volatile uint8 Butt_pressed = 'N';
	volatile uint8 data_flag = 0;
	volatile uint8 from_stand_to_oper_flag = 0;
	volatile uint8 Set_temp=25;
	volatile uint8 current_temp=0;
	volatile uint8 system_state = STANDBY;
	LCD_Init();
	tc72Init();
	Key_Pad_init();
	ADC_Init();
	Welcom_Screen();
	IDLE_Screen();
	
	
		
    while(1)
    {
		Keypad_CheckPress(&Butt_pressed);
		if (system_state == STANDBY)
		{
			
			timer_pwm(0);

			if ((Butt_pressed != '#') && (Butt_pressed != '*') && (Butt_pressed != 'N'))
			{
				if(data_flag==0)
				{
					
					bit_M = 0;
					bit_L = Butt_pressed;
					Butt_pressed ='N';
					Display_M_L_bit(bit_M, bit_L, 4);
					
					data_flag=1;

					_delay_ms(250);
				}
				else{
					
					bit_M = bit_L;
					bit_L = Butt_pressed;
					Butt_pressed ='N';
					Display_M_L_bit(bit_M, bit_L, 4);
					
					data_flag=0;
					_delay_ms(250);
					
				}
				Set_temp = (bit_M*10) + bit_L;
				}
				
		}
		if (system_state == OPERATIONAL || system_state== NORMAL)
		{
			char_t D_M;
			char_t D_L;
			get_Temperature(&D_M ,&D_L);
			Display_M_L_bit( D_M,D_L,14);
			
			current_temp = (D_M * 10) + D_L;
			uint8 normal_cond = abs(Set_temp - current_temp);
			Keypad_CheckPress(&Butt_pressed);
			Timer_2_CTC_Init_Interrupt();
			
			if (normal_cond <= 5)
			{
				system_state = NORMAL;
				timer_pwm(0);
				Display_sys_State(system_state);
				_delay_ms(200);
				
				
			}
			else if((current_temp-Set_temp )> 10)
			{
				system_state = ERROR;
			}
			else if((Set_temp - current_temp)> 5 )
			{
				system_state = OPERATIONAL;
				pwm(Set_temp ,current_temp);
				Display_sys_State(system_state);
				
				Timer_2_CTC_Init_Interrupt();
				
				if(counter1>130000)      
				{
					system_state= ERROR;
					counter1=0;
					Timer_2_CTC_off();
					timer_pwm(0);
				}
				
				
				
				
			}		
		}
		
		if (system_state == ERROR)	
		{
			Display_sys_State(system_state);
			timer_pwm(0);
			LCD_Move_Cursor(0,14);
			LCD_Send_String("--");
			_delay_ms(200);
			while(1){}
			
		}							
				
		if (Butt_pressed == '#')
		{
			
			if (from_stand_to_oper_flag==0)
			{
				system_state = OPERATIONAL;
				from_stand_to_oper_flag=1;
				Butt_pressed ='N';
				Display_sys_State(system_state);
				_delay_ms(200);
				//Timer_2_over_flow_Init_Interrupt();
				//Timer_2_over_flow_off();
				
				
				
				
			}
			else
			{
				system_state = STANDBY;
				Display_sys_State(system_state);
				LCD_Move_Cursor(0,14);
				LCD_Send_String("--");
				_delay_ms(200);
				from_stand_to_oper_flag=0;
				Butt_pressed ='N';
			}
		}
		
		
		
	 
	
	
	
}
}

	
ISR(TIMER2_COMP_vect)
{
	counter1++;
	
}
