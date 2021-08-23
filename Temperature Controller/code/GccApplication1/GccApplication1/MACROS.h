/*
 * MACROS.h
 *
 * Created: 6/8/2021 12:19:25 PM
 *  Author: Mostafa Elt7awy
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)



#endif /* MACROS_H_ */