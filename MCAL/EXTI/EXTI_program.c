
/****************************************************************

Author          Ahmed Saeid Abdalla

Data            29,MAR 2023

Compiler        GNU GCC

Version         v1.0

***************************************************************/

/****************************************************************

Author          Ahmed Saeid Abdalla

Data            29,MAR 2023

Compiler        GNU GCC

Version         v1.0

***************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "../DIO/DIO_interface.h"
static void(*EXTI_pvoidINT0Notification) (void) = NULL;

void EXTI_voidInitPinConnectio (u8 copy_u8InterruptNum)
{

switch(copy_u8InterruptNum)
{
case EXTI_INT0:
#if INT0_PIN_CONNECTION == INTERNAL_PULLUP
DIO_voidSetPinDirection( EXTI0_PORT,EXTI0_PIN,INPUT) ;
DIO_voidSetPinValue(EXTI0_PORT,EXTI0_PIN,HIGH);
#elif INT0_PIN_CONNECTION == EXTERNAL_PULLUP 
   DIO_voidSetPinDirection(EXTI0_PORT,EXTI0_PIN,INPUT);
#elif INT0_PIN_CONNECTION == EXTERNAL_PULLDOWN 
DIO_voidSetPinDirection( EXTI0_PORT,EXTI0_PIN,INPUT) ;
#endif
break;

case EXTI_INT1 :
#if INT1_PIN_CONNECTION == INTERNAL_PULLUP
DIO_voidSetPinDirection( EXTI1_PORT,EXTI0_PIN,INPUT) ;
DIO_voidSetPinValue(EXTI1_PORT,EXTI1_PIN,HIGH);
#elif INT1_PIN_CONNECTION == EXTERNAL_PULLUP 
DIO_voidSetPinDirection(EXTI1_PORT,EXTI1_PIN,INPUT);
#elif INT1_PIN_CONNECTION == EXTERNAL_PULLDOWN 
DIO_voidSetPinDirection( EXTI1_PORT,EXTI1_PIN,INPUT) ;
#endif
break;

case EXTI_INT2:
#if INT2_PIN_CONNECTION == INTERNAL_PULLUP
DIO_voidSetPinDirection( EXTI2_PORT,EXTI2_PIN,INPUT) ;
DIO_voidSetPinValue(EXTI2_PORT,EXTI2_PIN,HIGH);
#elif INT2_PIN_CONNECTION == EXTERNAL_PULLUP 
DIO_voidSetPinDirection( EXTI2_PORT,EXTI2_PIN,INPUT) ;
#elif INT2_PIN_CONNECTION == EXTERNAL_PULLDOWN 
DIO_voidSetPinDirection( EXTI2_PORT,EXTI2_PIN,INPUT) ;
#endif

break;
}
}

void EXTI_voidTriggerEdge(u8 copy_u8InterruptNum , u8 copy_u8edge )
{
  switch(copy_u8InterruptNum)
 {
    case EXTI_INT0 :
    switch (copy_u8edge)
    {
        case LOW_LEVEL:
        CLR_BIT ( MCUCR , MCUCR_ISC00);
        CLR_BIT ( MCUCR , MCUCR_ISC01);
        break;

        case ANY_LOGICAL_CHANGE:
        SET_BIT(MCUCR , MCUCR_ISC00);
        CLR_BIT ( MCUCR , MCUCR_ISC01);
        break;

        case FALLING_EDGE :
        CLR_BIT ( MCUCR , MCUCR_ISC00);
        SET_BIT(MCUCR , MCUCR_ISC01);
        break;
         case RISING_EDGE :
        CLR_BIT ( MCUCR , MCUCR_ISC01);
        SET_BIT(MCUCR , MCUCR_ISC00);
        break;



    }
    break;

    case EXTI_INT1 :
    switch (copy_u8edge)
    {
        case LOW_LEVEL:
        CLR_BIT ( MCUCR , MCUCR_ISC10);
        CLR_BIT ( MCUCR , MCUCR_ISC11);
        break;

        case ANY_LOGICAL_CHANGE:
        SET_BIT(MCUCR , MCUCR_ISC10);
        CLR_BIT ( MCUCR , MCUCR_ISC11);
        break;

        case FALLING_EDGE :
        CLR_BIT ( MCUCR , MCUCR_ISC10);
        SET_BIT(MCUCR , MCUCR_ISC11);
        break;
         case RISING_EDGE :
        SET_BIT ( MCUCR , MCUCR_ISC10);
        SET_BIT(MCUCR , MCUCR_ISC11);
        break;
 }
    break;

    case EXTI_INT2 :
    switch(copy_u8edge)
    {
        case FALLING_EDGE:
        CLR_BIT( MCUCSR , MCUCSR_ISC2);
        break;
        case RISING_EDGE:
        SET_BIT(MCUCSR , MCUCSR_ISC2);
        break;

    }

    break;
 }
}

void EXTI_voidEnable(u8 copy_u8InterruptNum)
{

switch(copy_u8InterruptNum)
	{
		case EXTI_INT0:
			SET_BIT(GICR,GICR_INT0);
			break;
		case EXTI_INT1:
		    SET_BIT(GICR,GICR_INT1);
			break;
		case EXTI_INT2:
			SET_BIT(GICR,GICR_INT2);
			break;
	}

}

void EXTI_voidDisable(u8 copy_u8InterruptNum )
{

switch(copy_u8InterruptNum)
		{
		case EXTI_INT0:
			CLR_BIT(GICR,GICR_INT0);
			break;
		case EXTI_INT1:
			CLR_BIT(GICR,GICR_INT1);
			break;
		case EXTI_INT2:
			CLR_BIT(GICR,GICR_INT2);
			break;
		}
}


void EXTI_voidINT0SetCallBack(void(*Notificationfunction)(void))
{
    EXTI_pvoidINT0Notification = Notificationfunction;
}

/* ISR FOR INT0 */

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(EXTI_pvoidINT0Notification != NULL)
    {
        /*INVOKE THE GLOBAL POINTER TO FUNCTION*/
        EXTI_pvoidINT0Notification ();
    }
    else 
    {
        /*Do Nothing*/
    }


    
}

