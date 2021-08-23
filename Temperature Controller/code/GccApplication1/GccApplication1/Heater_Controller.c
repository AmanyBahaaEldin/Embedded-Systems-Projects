#include "ADC.h"
#include "TYPE_DEFs.h"
#include "PWM.h"
#define F_CPU 1000000ul
#include <util/delay.h>

#include "LCD.h"
double Target_v(uint8 Set_temp, uint8 curr_temp)
{
	double v_t;
	if (Set_temp >curr_temp)
	{
		double step1= (Set_temp - curr_temp)/100.0;
		v_t= step1 * 10;
	}
	else
	{
		v_t = 0;
	}
	
	return v_t;
}

double adc_map_volt(void)
{
	double adc_val= ADC_Read();
	double Adc_maped_val = (adc_val/255.0)*5;
	return Adc_maped_val;
	
}
void pwm(uint8 Set_temp, uint8 curr_temp)
{
	double V_t=Target_v(Set_temp , curr_temp);
	double V_r= adc_map_volt();
	double duty_cycle_percentage = (((V_r *2 )/10.0)*V_t)/10.0;
	double ocr_val= 256 * duty_cycle_percentage;
	
	timer_pwm(ocr_val );
	
}
