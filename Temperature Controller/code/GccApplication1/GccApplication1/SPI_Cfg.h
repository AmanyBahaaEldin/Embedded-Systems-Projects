
#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/*mode0*/
/* CPOL=0,CPHA=0*/
/*sampling in the  1st edge (rising edge) and wait half clock cycle */
#define mode0 {CLR_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);}
/*mode1*/
/*(CPOL=0,CPHA=1)*/
/*sampling in the 2nd edge (falling edge) and wait clock cycle */
#define mode1	{CLR_BIT(SPCR,CPOL);SET_BIT(SPCR,CPHA);}
/*mode2 */
/*(CPOL=1,CPHA=0)*/
/*sampling in the 1st edge (falling edge) and wait half clock cycle */
#define mode2  {SET_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);}
/*mode3 */
/* (CPOL=1,CPHA=1)*/
/*sampling in the 2nd edge (rising edge) and wait clock cycle */
#define mode3 { SET_BIT(SPCR,CPOL);SET_BIT(SPCR,CPHA);}

#define SPI_NUM_PINS ((unsigned char)4)

typedef  struct{
	unsigned char  Port_id;
	unsigned char pin_number;
	unsigned char pin_direction;
	
	}SPI_Confg_pins; 

extern const SPI_Confg_pins SPI_Pins[SPI_NUM_PINS];
#endif /* SPI_CFG_H_ */