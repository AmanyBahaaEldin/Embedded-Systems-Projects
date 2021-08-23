
#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterTransmit( char Data);
char SPI_MasterReceive(void);
unsigned char SPI_SlaveReceive(unsigned char Data);
#endif /* SPI_H_ */