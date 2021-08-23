#include "DIO.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "TYPE_DEFs.h"
#define F_CPU 1000000ul
#include <util/delay.h>


void LCD_Init(void)
{
	_delay_ms(31);
	
	uint8 Loop;
	for(Loop=(unsigned char)0 ; Loop < LCD_MODE ; Loop++)
	{
		DIO_SetPINDir(DATA_Pins[Loop].PORT_id,DATA_Pins[Loop].PIN_num, 1);
	}
	
	DIO_SetPINDir(LCD_RS.PORT_id, LCD_RS.PIN_num, 1);
	DIO_SetPINDir(LCD_RW.PORT_id,LCD_RW.PIN_num, 1);
	DIO_SetPINDir(LCD_E.PORT_id,LCD_E.PIN_num, 1);
	
	DIO_Write(LCD_RW.PORT_id, LCD_RW.PIN_num ,0);
	LCD_Send_Cmd(RETURN_HOME); //return home
	//_delay_ms(10);
	LCD_Send_Cmd(FOUR_BITS); //4bit mode
	//_delay_ms(1);
	LCD_Send_Cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	//_delay_ms(1);
	LCD_Send_Cmd(CLR_SCREEN);//clear the screen
	_delay_ms(3);
	LCD_Send_Cmd(ENTRY_MODE); //entry mode
	//_delay_ms(1);
}
	
static void Send_Falling_Edge(void)
{
	DIO_Write(LCD_E.PORT_id, LCD_E.PIN_num,1);
	_delay_ms(2);
	DIO_Write(LCD_E.PORT_id, LCD_E.PIN_num,0);
	//_delay_ms(2);
}

void LCD_Send_Cmd(uint8 cmd)
{
	uint8 pins_M;
	uint8 pins_L;
	for (pins_M = (unsigned char)0; pins_M < LCD_MODE; pins_M++)
	{
		uint8 PinValue;
		PinValue = (cmd & (1 << (pins_M + 4))) >> (pins_M + 4);
		
		DIO_Write(DATA_Pins[pins_M].PORT_id, DATA_Pins[pins_M].PIN_num , PinValue);
	}
	
	
	DIO_Write(LCD_RS.PORT_id,LCD_RS.PIN_num, 0);
	Send_Falling_Edge();
	for (pins_L = (unsigned char)0; pins_L < LCD_MODE; pins_L++)
	{
		uint8 PinValue;
		PinValue = (cmd & (1 << pins_L)) >> pins_L;
		
		DIO_Write(DATA_Pins[pins_L].PORT_id, DATA_Pins[pins_L].PIN_num , PinValue);
	}
	
	
	DIO_Write(LCD_RS.PORT_id,LCD_RS.PIN_num,0);
	Send_Falling_Edge();
	_delay_ms(1);

}


void LCD_Send_Char(uint8 data)
{
	
	
	uint8 pins_M;
	uint8 pins_L;
	for (pins_M = (unsigned char)0; pins_M < LCD_MODE; pins_M++)
	{
		uint8 PinValue;
		PinValue = (data & (1 << (pins_M + 4))) >> (pins_M + 4);
		
		DIO_Write(DATA_Pins[pins_M].PORT_id, DATA_Pins[pins_M].PIN_num , PinValue);
	}
	
	
	DIO_Write(LCD_RS.PORT_id,LCD_RS.PIN_num, 1);
	Send_Falling_Edge();
	for (pins_L = (unsigned char)0; pins_L < LCD_MODE; pins_L++)
	{
		uint8 PinValue;
		PinValue = (data & (1 << pins_L)) >> pins_L;
		
		DIO_Write(DATA_Pins[pins_L].PORT_id, DATA_Pins[pins_L].PIN_num , PinValue);
	}
	
	
	DIO_Write(LCD_RS.PORT_id,LCD_RS.PIN_num,1);
	Send_Falling_Edge();
	_delay_ms(1);

	
}

void LCD_Send_String(uint8 *data)
{
	while((*data)!='\0')
	{
		LCD_Send_Char(*data);
		data++;
	}
}


void LCD_ClearScreen(void)
{
	LCD_Send_Cmd(CLR_SCREEN);
	//_delay_ms(3);
}


void LCD_Move_Cursor(uint8 row,uint8 coloumn)
{
	uint8 data ;
	if(row>1||row<0||coloumn>15||coloumn<0)
	{
		data=0x80;
	}
	else if(row==0)
	{
		data=0x80+coloumn ;
	}
	else if (row==1)
	{
		data=0xc0+coloumn;
	}
	LCD_Send_Cmd(data);
	_delay_ms(1);
}

