
#ifndef HEATER_CONTROLLER_H_
#define HEATER_CONTROLLER_H_
#include "TYPE_DEFs.h"

double Target_v(uint8 Set_temp, uint8 curr_temp);
double adc_map_volt(void);
void pwm(uint8 Set_temp, uint8 curr_temp);



#endif /* HEATER_CONTROLLER_H_ */