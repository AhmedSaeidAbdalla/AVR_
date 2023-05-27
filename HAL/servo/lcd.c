/*code that control 7 segment*/

#include<util/delay.h>
#include"../LIB/BIT_MATH.h"
#include"../LIB/STD_TYPES.h"

#include"../MCAL/DIO/DIO_interface.h"

int main(void)
{
	u8 local_u8segment[]={

			0b00111111,
			0b00000110,
			0b01011011,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111,

	                     };

	u8 counter=0;
	DIO_voidSetPortSpecificDirection(DIO_PORTA,OUTPUT);
	_delay_ms(1000);

	while(1)
	{
		while(counter<10)
		{
			DIO_voidSetPortSpecificValue(DIO_PORTA,local_u8segment[counter]);
		_delay_ms(1000);
		counter++;
		}
	}
}

