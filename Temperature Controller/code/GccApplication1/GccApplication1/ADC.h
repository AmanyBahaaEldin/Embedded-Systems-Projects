


#ifndef ADC_H_
#define ADC_H_
#include "TYPE_DEFs.h"
#define CHECK_ADIF IS_BIT_CLR(ADCSRA,ADIF)
void ADC_Init(void);
void CONFIG_VREF(void);
void ENABLE_ADC(void);
void START_CONV(void);
void CLR_ADIF(void);

uint8 ADC_Read(void);




#endif /* ADC_H_ */