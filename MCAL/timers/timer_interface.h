/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/

#ifndef TIMER_INTERFACE_H   
#define TIMER_INTERFACE_H


#define NORMAL_MODE      0
#define CTC_MODE         1

#define     RAISNG_EDGE       1
#define     FALLING_EDGE      0
#define     ICU_ENABLE        1
#define     ICU_DISABLE       0



void TIMER0_voidInit(void);
void timer1_voidInit(void);

void TIMER1_voidSetICRValue(u16 copy_u8value);
void TIMER0_voidSetBusyWaitMS_OCMode(u32 copy_u32time);
void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time);
void TIMER1_VoidSetPreLoadValue1(u16 copy_u8value);

void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);
void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void));
void ICU_voidSetRegistterSignal(u8 copy_u8TriggerSignal);
u16 ICUu16GETICRRegister(void);
void ICU_voidSertCallBack(void (*notification)(void));








#endif
