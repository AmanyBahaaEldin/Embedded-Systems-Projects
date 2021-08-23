

#ifndef DIO_CFG_H_
#define DIO_CFG_H_


/*start address of each port*/
#define PORTA_BASE_ADDRESS ((unsigned char)0x3B)
#define PORTB_BASE_ADDRESS ((unsigned char)0x38)
#define PORTC_BASE_ADDRESS ((unsigned char)0x35)
#define PORTD_BASE_ADDRESS ((unsigned char)0x32)

/*Port subsystem registers offset*/
#define PORT_REG_OFFSET ((unsigned char)0)
#define DDR_REG_OFFSET ((unsigned char)1)
#define PIN_REG_OFFSET ((unsigned char)2)

#define NUM_OF_PORTS ((unsigned char)4)

/*Registers definitions*/
#define PORT_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - PORT_REG_OFFSET)))
#define DDR_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - DDR_REG_OFFSET)))
#define PIN_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - PIN_REG_OFFSET)))



#endif /* DIO_CFG_H_ */