/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:    30 MAR, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/



#ifndef 	MCAL_ADC_ADC_private_H_
#define 	MCAL_ADC_ADC_private_H_

#define     RIGHT_ADJUST            0
#define     LEFT_ADJUST             1

#define     AREF                    0
#define     AVCC                    1
#define     INTERNAL_2v56           2

#define     ENABLE                  1
#define     DISABLE                 0




#define  REF_SEL_BIT_MASK           0b00011111
#define  ADC_Reference_SECTION       AREF

#define   AREF                      0b000000000
#define   AVCC                      0b010000000
#define  INTERNAL_2v56              0b110000000






/*PRE SCALER */
#define PRE_DIV_64                   0b0000110;
#define PRE_DIV_128                  0b0000111;
#define PRE_DIV_2                    0b00000000
#define PRE_DIV_4                    0b00000010
#define PRE_DIV_8                    0b00000011
#define PRE_DIV_16                   0b00000100
#define PRE_DIV_32                   0b00000101

#define PRE_SCALER_BIT_MASK          0b1111000;



/************/


#define  CHANNEL_SELECTION_MASK    0b1110000



/******************************Register Description*******************************/

#define ADMUX    *((volatile u8*)0x27)
#define ADCSRA   *((volatile u8*)0x26)
#define ADCH     *((volatile u8*)0x25)
#define ADCL     *((volatile u8*)0x24)
#define ADC      *((volatile u16*)0x24)     // ACCSES TWO REGESTER WITH ONE POINTER (0X24 AND 0X25)


#define ADMUX_MUX0       0
#define ADMUX_MUX1       1
#define ADMUX_MUX2       2
#define ADMUX_MUX3       3
#define ADMUX_MUX4       4
#define ADMUX_ADLAR      5
#define ADMUX_REFS0      6
#define ADMUX_REFS1      7

#define ADCSRA_ADPS0     0
#define ADCSRA_ADPS1     1
#define ADCSRA_ADPS2     2
#define ADCSRA_ADIE      3
#define ADCSRA_ADIF      4
#define ADCSRA_ADATE     5
#define ADCSRA_ADSC      6
#define ADCSRA_ADEN      7

#define NULL           0X00



#define  CHANNEL_SELECTION_MASK    0b1110000



#endif
