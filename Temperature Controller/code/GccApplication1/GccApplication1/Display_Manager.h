
#ifndef DISPLAY_MANAGER_H_
#define DISPLAY_MANAGER_H_
#include "TYPE_DEFs.h"
#define DISPLAY_SHIFT_R 0X1C
#define DISPLAY_SHIFT_L 0X18



void Welcom_Screen(void);
void IDLE_Screen(void);
void Display_M_L_bit(char_t bit_m, char_t bit_l, uint8 Cursor);
void Display_sys_State(uint8 state);
#endif /* DISPLAY_MANAGER_H_ */