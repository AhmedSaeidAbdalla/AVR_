/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:    30 MAR, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/


#ifndef 	MCAL_ADC_ADC_config_H_
#define 	MCAL_ADC_ADC_config_H_


/*
    ORTIONS:
    RIGHT_ADJUST
    LEFT_ADJUST
*/
#define     ADC_ADJUST_RESULT       LEFT_ADJUST

/*
    ORTIONS:
    AREF
    AVCC
    INTERNAL_2v56
*/
#define     ADC_Reference_SECTION       AREF

/*
    ORTIONS:
    ENABLE
    DISABLE
*/
#define     ADC_INTERRUPT_STATUS      ENABLE

/*
    ORTIONS:
    ENABLE
    DISABLE
*/
#define         ADC_ENABLE              ENABLE


/*
OPTION 
PRE_DIV_64
PRE_DIV_128
 PRE_DIV_2  
 PRE_DIV_4  
 PRE_DIV_8  
 PRE_DIV_16 
 PRE_DIV_32 

*/
#define  PRE_SCALER_BIT          PRE_DIV_64                          

#endif