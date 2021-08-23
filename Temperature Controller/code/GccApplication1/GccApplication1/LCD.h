
#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "TYPE_DEFs.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define FOUR_BITS 0x28







void LCD_Init(void);

static void Send_Falling_Edge(void);
void LCD_Send_Cmd(uint8 cmd);
void LCD_Send_Char(uint8 data);
void LCD_Send_String(uint8 *data);
void LCD_ClearScreen(void);
void LCD_Move_Cursor(uint8 row,uint8 coloumn);
#endif /* LCD_H_ */