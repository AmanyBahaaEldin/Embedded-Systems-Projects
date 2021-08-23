#include "KEYPAD_Cfg.h"
#include "TYPE_DEFs.h"



const keypad_PIN_cfg Rows[NUM_ROWS]=
{
	{
		//row1
		2,
		0,
		1,
		0
	},
	{
		2,
		1,
		1,
		0
	},
	{
		2,
		2,
		1,
		0
	},
	{
		2,
		3,
		1,
		0
	},
};

const keypad_PIN_cfg Cols[NUM_COLS]=
{
	{
		2,
		4,
		0,
		1
	},
	{
		2,
		5,
		0, 
		1
	},
	{
		2,
		6,
		0,
		1
	},
};