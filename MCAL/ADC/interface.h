/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:    30 MAR, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/



#ifndef 	MCAL_ADC_ADC_interface_H_
#define 	MCAL_ADC_ADC_interface_H_


#define     ADC_INTERRUPT_ENABLE                  1
#define     ADC_INTERRUPT_DISABLE                 0


#define     ADC_channel_0  0b0000000
#define     ADC_channel_1  0b0000001
#define     ADC_channel_2  0b0000011
#define     ADC_channel_3  0b0000100
#define     ADC_channel_4  0b0000101
#define     ADC_channel_5  0b0000000
#define     ADC_channel_6  0b0000110
#define     ADC_channel_7  0b0000111



void ADC_voidInit(void);
void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);
void ADC_StartConversion_Asynchrones(u8 copy_u8cchannelNumber, void (*notificationFunc)(void));
u8   ADC_StartConversion_synchrones(u8 copy_u8cchannelNumber);                                        //  POOLING MECHANICESM



#endif
