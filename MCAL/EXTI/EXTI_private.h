/****************************************************************

Author          Ahmed Saeid Abdalla

Data            29,MAR 2023

Compiler        GNU GCC

Version         v1.0

***************************************************************/



#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H



#define INTERNAL_PULLUP             0
#define EXTERNAL_PULLUP             1
#define EXTERNAL_PULLDOWN           2

/* PINS COnnection To Hardware*/

#define EXTI0_PORT     DIO_PORTD
#define EXTI0_PIN      PIN2

#define EXTI1_PORT     DIO_PORTD
#define EXTI1_PIN      PIN3

#define EXTI2_PORT     DIO_PORTB
#define EXTI2_PIN      PIN2

#define NULL           *((volatile u8 * ) 0)


/* MCU Control And Status Register*/

#define  MCUCSR   *((volatile u8 * ) 0x54)
#define  MCUCSR_ISC2      6

/* GICR Genral Interupt Conrtol Register*/

#define GICR    *((volatile u8 * ) 0x5B)

#define GICR_INT2    5
#define GICR_INT0    6
#define GICR_INT1    7


/*MCU Control Register */

#define  MCUCR      *((volatile u8 * ) 0x55)

#define MCUCR_ISC00    0
#define MCUCR_ISC01    1
#define MCUCR_ISC10    2
#define MCUCR_ISC11    3




#endif