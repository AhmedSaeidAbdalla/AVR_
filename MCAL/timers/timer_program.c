/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/

#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/BIT_MATH.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_configer.h"

static void (*Global_pvOVFNotificationFunction)(void) = NULL;
static void (*Global_pvOCNotificationFunction)(void) =  NULL;


void TIMER0_voidInit(void)
{

/*SET THE MODE TO BE FAST BWM*/
SET_BIT(TCCR0,TCCR0_WGM00);
SET_BIT(TCCR0,TCCR0_WGM01);

/*SET THE NON_INVERTED MODE SRT ON TOP , CLEAR ON COMPERE*/

CLR_BIT(TCCR0,TCCR0_COM00);
SET_BIT(TCCR0,TCCR0_COM01);

/* SET Normal Mode*/

CLR_BIT(TCCR0,TCCR0_WGM00);
CLR_BIT(TCCR0,TCCR0_WGM01);

/*Set CTC Mode*/
CLR_BIT(TCCR0,TCCR0_WGM00);
SET_BIT(TCCR0,TCCR0_WGM01);

/* NON INVERTED MODE*/
CLR_BIT(TCCR0, TCCR0_COM00);
SET_BIT(TCCR0, TCCR0_COM01);
/*Set Prescaller TO BE 8 */
CLR_BIT(TCCR0,TCCR0_CS00);
SET_BIT(TCCR0,TCCR0_CS01);
CLR_BIT(TCCR0,TCCR0_CS02);

}
void timer1_voidInit(void)
{

	/* SET THE TIMER 1 TO BE NORMAL MODE*/

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	/*Set Timer(1) In MOde 14 Fast PMW With Top Value = ICR1*/

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/* SET THE NON_INVERTED MODE*/

	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	/*SET THE PRESCAULLER TO BE 8*/

	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);


}

void TIMER1_voidSetICRValue(u16 copy_u8value)
{
   ICR1 = copy_u8value;
}

void  TIMER1_VoidSetPreLoadValue1(u16 copy_u8value)
{
	OCR1A =copy_u8value;
}



void TIMER0_voidSetBusyWaitMS_OCMode(u32 copy_u32time)
{

    /*set prescauller 8 */

    CLR_BIT(TCCR0,TCCR0_CS00);
    SET_BIT(TCCR0,TCCR0_CS02);
    CLR_BIT(TCCR0,TCCR0_CS01);

    TIMER0_voidSetOCMatchValue(Compare_MatchValue);

    u32 NUMBER_OF_OCFLAGS;
    u32 counter =0;
     NUMBER_OF_OCFLAGS = ((u32)(1000*copy_u32time)) / 250;
    while(counter <= NUMBER_OF_OCFLAGS )
    {
        while(GET_BIT(TIFR , TIFR_OCF0) == 0);
		SET_BIT(TIFR , TIFR_OCF0);
		counter++;
    }
}
void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetPreloadValue(PreLoad_Value);
	u32 Number_of_OVF = ((u32)(Copy_u32Time*1000)) / 250;

	u32 Counter = 0;

	while(Counter < Number_of_OVF)
	{
		while(GET_BIT(TIFR , TIFR_OCF0) == 0);
		SET_BIT(TIFR , TIFR_OCF0);
		Counter++;
		TIMER0_voidSetOCMatchValue(6);
	}
}
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		CLR_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		CLR_BIT(TIMSK,TIMSK_OCIE0);
	}
}
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		SET_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		SET_BIT(TIMSK,TIMSK_OCIE0);
	}
}
ER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		SET_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		SET_BIT(TIMSK,TIMSK_OCIE0);
	}
}
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOVFNotificationFunction = pvNotificationFunction;
}
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOCNotificationFunction = pvNotificationFunction;
}

void ICU_voidSetRegistterSignal(u8 copy_u8TriggerSignal)
{
	switch(copy_u8TriggerSignal)
	{
		case RAISNG_EDGE:
		SET_BIT(TCCR1B,TCCR1B_ICES1);
		break;
		case FALLING_EDGE:
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
		break;
	}
}

u16 ICUu16GETICRRegister(void)
{
	return ICR1;
}

static void (*ICU_NotifactionFunction)(void) = NULL;
void ICU_voidSertCallBack(void (*notification)(void))
{
	ICU_NotifactionFunction=notification;
}
void__vector_6(void)__attribute__((signal));
void__vector_6(void)
{
	if(ICU_NotifactionFunction !=NULL)
	{
      ICU_NotifactionFunction();
	}
	else{
		// DO NOTHING
	}
}
void ICU_INTERUUPTCONTROL(u8 copy_interupustate)
{
	switch(copy_interupustate)
	{
		case ICU_ENABLE :
		SET_BIT(TIMSK,TIMSK_TICIE1);
		break;
		case ICU_DISABLE :
		CLR_BIT(TIMSK,TIMSK_TICIE1);
		break;
	}
}
