
#ifndef TC72_DRIVER_H_
#define TC72_DRIVER_H_
#include "TYPE_DEFs.h"
#define CONTROL_REG_WRITE  0x80
#define CONTROL_REG_READ   0x00
#define READ_LSB_TEMP      0x01
#define READ_MSB_TEMP      0x02

void tc72Init(void);
char_t temp_read_msb(void);
char_t temp_read_lsb(void);


#endif /* TC72_DRIVER_H_ */