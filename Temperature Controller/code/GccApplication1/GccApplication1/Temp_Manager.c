
#include "TC72.h"
#include "Temp_Manager.h"
#include "TYPE_DEFs.h"



void get_Temperature(char_t *digit1 ,char_t *digit2){

	char_t result;
	char_t ssd[10]={0,1,2,3,4,5,6,7,8,9};
	char_t msb = temp_read_msb();
	char_t lsb = temp_read_lsb();
	char_t sign=0;
	
	
	
	lsb>>=6;

	if(msb & CHECK_SIGN) {
		msb=(~msb)+1;
		sign=1;
		if(lsb!=0) lsb=75/lsb;
	}
	else {
		sign=0;
		lsb*=25;
	}
	if(msb>=10)
	{
		*digit1=ssd[(msb%100)/10];
	}
	
	else 
	{
		*digit1=ssd[0];
	} 
	
	*digit2=ssd[msb%10];
	
	
	
	
}