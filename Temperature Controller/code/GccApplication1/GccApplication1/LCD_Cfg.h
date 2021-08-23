


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "TYPE_DEFs.h"
/*
#define LCD_RS ((unsigned char)4)
#define LCD_RW ((unsigned char)5)
#define LCD_E ((unsigned char)6)
*/

#define LCD_MODE ((unsigned char)4)
typedef struct
{
	uint8 PORT_id;
	uint8 PIN_num;
	
}PIN_cfg;

const PIN_cfg LCD_RS;
const PIN_cfg LCD_RW;
const PIN_cfg LCD_E;
const PIN_cfg DATA_Pins[LCD_MODE];


#endif /* LCD_CFG_H_ */