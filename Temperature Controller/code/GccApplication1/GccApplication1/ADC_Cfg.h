


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

typedef struct
{
	unsigned char PORT_ID ;
	unsigned char PIN_NUM ;
	unsigned char Port_Direction;
}ADC_ConfigParamType;

extern const ADC_ConfigParamType ADC_ConfigParam;

#endif /* ADC_CFG_H_ */