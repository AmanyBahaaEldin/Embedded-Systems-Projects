#include "DIO.h"
#include "KEYPAD.h"
#include "KEYPAD_Cfg.h"
#include "TYPE_DEFs.h"
static const uint8 KeyValues[NUM_ROWS][NUM_COLS] = {{1,2,3} , {4,5,6} , {7,8,9} , {'*',0,'#'}};

	


void Key_Pad_init(void)
{
	uint8 Row;
	for (Row = (unsigned char)0 ; Row < NUM_ROWS ; Row++)
	{
		
		DIO_SetPINDir(Rows[Row].PORT_id,Rows[Row].PIN_num, Rows[Row].PIN_dir);
		DIO_Connect_Pull_Up(Rows[Row].PORT_id,Rows[Row].PIN_num, Rows[Row].Pull_up);
	}
	
	uint8 col;
	for (col = (unsigned char)0 ; col < NUM_COLS ; col++)
	{
		
		DIO_SetPINDir(Cols[col].PORT_id,Cols[col].PIN_num, Cols[col].PIN_dir);
		DIO_Connect_Pull_Up(Cols[col].PORT_id,Cols[col].PIN_num, Cols[col].Pull_up);
	}
}
void Keypad_CheckPress (uint8 *butt_press)
{
	*butt_press = 'N';
	
	uint8 Row;
	uint8 Column;
	uint8 PressValue;
	//uint8 Data;
	uint8 Loop;
	for (Row = (unsigned char)0 ; Row < NUM_ROWS ; Row++)
	{
		
		for (Loop = (unsigned char)0 ; Loop < NUM_ROWS ; Loop++)
		{
			
			DIO_Write(Rows[Loop].PORT_id,Rows[Loop].PIN_num,1);
		}
		
		DIO_Write(Rows[Row].PORT_id,Rows[Row].PIN_num,0);
		for (Column = (unsigned char)0 ; Column<NUM_COLS ; Column++)
		{
			DIO_Read_PIN(Cols[Column].PORT_id,Cols[Column].PIN_num , &PressValue);
			if (PressValue == 0)
			{
				*butt_press = KeyValues[Row][Column];
				break;
			}
		}
		if (PressValue == 0)
		{
			break;
		}
		
	}
	
	
}