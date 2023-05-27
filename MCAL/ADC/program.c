/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:    30 MAR, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "interface.h"
#include "configer.h"
#include "private.h"

u8 Local_u8DigitalValue;
static void (*ADC_pvoidNotificationFunction)(void) = NULL;
volatile u16 ADC_u16DigitalResult = 0;

void ADC_voidInit(void)
{
    /* ADC Enable */
    #if ADC_ENABLE == ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADEN);
    #elif ADC_ENABLE == DISABLE
        CLR_BIT(ADCSRA, ADCSRA_ADEN);
    #else
        #error("Error, ADC_ENABLE Configuration error")
    #endif
    
    
    /* ADC Interrupt Enable */
        /* Pre Build */
    #if ADC_INTERRUPT_STATUS == ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADIE);
    #elif ADC_INTERRUPT_STATUS == DISABLE
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    #else
        #error("Error, ADC_INTERRUPT_STATUS Configuration error")
    #endif


    /* Reference voltage choose */
    #if ADC_Reference_SECTION == AREF
        CLR_BIT(ADMUX, ADMUX_REFS0);
        CLR_BIT(ADMUX, ADMUX_REFS1);
    #elif ADC_Reference_SECTION == AVCC
        SET_BIT(ADMUX, ADMUX_REFS0);
        CLR_BIT(ADMUX, ADMUX_REFS1);
    #elif ADC_Reference_SECTION == INTERNAL_2v56
        SET_BIT(ADMUX, ADMUX_REFS0);
        SET_BIT(ADMUX, ADMUX_REFS1);    
    #else
        #error("Error, ADC_Reference_SECTION Configuration error")
    #endif

    /* Adjust Result */
    #if ADC_ADJUST_RESULT == RIGHT_ADJUST
        CLR_BIT(ADMUX, ADMUX_ADLAR);
    #elif ADC_ADJUST_RESULT == LEFT_ADJUST
        SET_BIT(ADMUX, ADMUX_ADLAR);
    #else
        #error("Error, ADC_ADJUST_RESULT Configuration error")
    #endif







    ADCSRA &= PRE_SCALER_BIT_MASK;
    ADCSRA |= PRE_SCALER_BIT;

}


void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus)
{
    /*Post Build*/
    switch (Copy_u8InterruptStatus)
    {
    case ADC_INTERRUPT_DISABLE:
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
        break;
    case ADC_INTERRUPT_ENABLE:
        SET_BIT(ADCSRA, ADCSRA_ADIE);
        break;
    default:
        /* Do Nothing */
        break;
    }
}






//
u8 ADC_StartConversion_synchrones(u8 copy_u8cchannelNumber) //  POOLING MECHANICESM
{

/*set channel of ADC*/

ADMUX &=CHANNEL_SELECTION_MASK;
ADMUX |=copy_u8cchannelNumber;
/*START ADC CONVERT THE INPUT ANALOG SIGNAL*/
SET_BIT(ADCSRA,ADCSRA_ADSC);
/*POLLING (BUSY WAIT) TILL THE FALG IS RAISED*/
while(GET_BIT(ADCSRA,ADCSRA));
/*CLEAR THE FAALG*/

SET_BIT(ADCSRA,ADCSRA); //TO CLEAR FLAG PUT 1 IN IT;
#if ADC_ADJUST_RESULT == LEFT_ADJUST
Local_u8DigitalValue = ADCH;
/*RETURN THE DIGITAL VALUE*/

#elif ADC_ADJUST_RESULT== RIGHT_ADJUST
Local_u8DigitalValue = ADCL;

#endif
return Local_u8DigitalValue;
}



void ADC_StartConversion_Asynchrones(u8 copy_u8cchannelNumber, void (*notificationFunc)(void))
{
/*
/*set channel of ADC*/
ADMUX &=CHANNEL_SELECTION_MASK;
ADMUX |=copy_u8cchannelNumber;
ADC_pvoidNotificationFunction = notificationFunc;
/*START ADC CONVERT THE INPUT ANALOG SIGNAL*/
SET_BIT(ADCSRA,ADCSRA_ADSC);

}

void__vector_16(void)__attribute__((signal));
void__vector_16(void)
{
	ADC_u16DigitalResult = ADCH;
    ADC_voidInteruptControl(DISABLE);
    if(ADC_pvoidNotificationFunction != NULL)

    {
        ADC_PvoidNotifiFunction();
    }
    else
    {


    }
	   ADC_voidInterruptControl(ENABLE);
}
