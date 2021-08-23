
#include "Display_Manager.h"
#include "TYPE_DEFs.h"
#include "LCD.h"
#define F_CPU 1000000ul
#include <util/delay.h>
void Welcom_Screen(void)
{
	LCD_Move_Cursor(0,9);
	uint8 data ="Welcome";
	LCD_Send_String(data);
	
	
	
	uint8 i,k,j;
	
	for(i=0;i<3;i++)
	{
		for(k=0;k<2;k++)
		{
			if (k==0)
			{
				for(j=0;j<9;j++)
				{
					_delay_ms(100);
					LCD_Send_Cmd(DISPLAY_SHIFT_L);
				}
				
			}
			else
			{
				for(j=0;j<9;j++)
				{
					_delay_ms(100);
					LCD_Send_Cmd(DISPLAY_SHIFT_R);
				}
			}
		}
	}
	
	
}


void IDLE_Screen(void)
{
	LCD_ClearScreen();
	
	LCD_Send_Cmd(ENTRY_MODE); //entry mode
	
	// set temp
	LCD_Move_Cursor(0,0);
	LCD_Send_String("SET:25");
	/*
	LCD_Move_Cursor(0,4);
	LCD_Send_Char();
	
	LCD_Move_Cursor(0,5);
	LCD_Send_Char(*bit_l);*/
	//Current temp
	LCD_Move_Cursor(0,10);
	LCD_Send_String("CRT:--");
	
	//system state
	LCD_Move_Cursor(1,0);
	LCD_Send_String("STATE:STANDBY");
	
}



void Display_M_L_bit(char_t bit_m, char_t bit_l, uint8 Cursor)
{
	
	char_t conc= (bit_m*10) + bit_l;
	char temp_value[20];
	itoa(conc,temp_value,10);
	if ( bit_m == 0)
	{
		LCD_Move_Cursor(0,Cursor);
		LCD_Send_Char('0');
		LCD_Move_Cursor(0,(Cursor+1));
		LCD_Send_String(temp_value);
	}
	else
	{
		LCD_Move_Cursor(0,Cursor);
		LCD_Send_String(temp_value);
	}
}



void Display_sys_State(uint8 state)
{
	LCD_Move_Cursor(1,6);
	LCD_Send_String(state);
}