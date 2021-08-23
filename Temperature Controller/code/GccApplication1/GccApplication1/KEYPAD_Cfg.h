
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#include "TYPE_DEFs.h"

#define NUM_ROWS ((unsigned char) 4)
#define NUM_COLS ((unsigned char) 3)
#define GROUNDED_ROW ((unsigned char) 0x00)

typedef struct
{
	uint8 PORT_id;
	uint8 PIN_num;
	uint8 PIN_dir;
	uint8 Pull_up;
	
}keypad_PIN_cfg;

 
const keypad_PIN_cfg Rows[NUM_ROWS];
const keypad_PIN_cfg Cols[NUM_COLS];


#endif /* KEYPAD_CFG_H_ */