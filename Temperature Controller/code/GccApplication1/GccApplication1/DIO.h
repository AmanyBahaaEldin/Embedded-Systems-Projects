#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED
#include "TYPE_DEFs.h"
void DIO_SetPINDir(unsigned char PORT_ID,unsigned char pinnumber,unsigned char direction);
void DIO_Write(unsigned char PORT_ID,unsigned char pinnumber,unsigned char outputvalue);
void DIO_Connect_Pull_Up(unsigned char PORT_ID,unsigned char pinnumber,unsigned char connect_pullup);
uint8 DIO_Read_PIN(uint8 portname,uint8 pinnumber, uint8 *return_value);

#endif // DIO_H_INCLUDED
