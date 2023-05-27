#ifndef  DIO_INTERFACE_H
#define  DIO_INTERFACE_H

#define INPUT        0
#define OUTPUT       1

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3


#define LOW          0
#define HIGH         1


#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7


void DIO_voidSetPinState(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State);
void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState);
u8   DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);


void DIO_voidSetPINDIRECTION( u8 portname , u8 pinnumber , u8 state);
void DIO_voidsetportValue(u8 copy_u8portname , u8 copy_u8portvalue);
void DIO_voidsetportSpecifiDireaction( u8 copy_u8portname , u8 copy_specificdireaction);
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);




#endif


