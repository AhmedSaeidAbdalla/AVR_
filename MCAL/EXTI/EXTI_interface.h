/****************************************************************

Author          Ahmed Saeid Abdalla

Data            29,MAR 2023

Compiler        GNU GCC

Version         v1.0

***************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_INT0   0
#define EXTI_INT1   1
#define EXTI_INT2   2


#define LOW_LEVEL           0
#define ANY_LOGICAL_CHANGE  1
#define FALLING_EDGE        2
#define RISING_EDGE         3


void EXTI_voidInitPinConnectio (u8 copy_u8InterruptNum);
void EXTI_voidTriggerEdge(u8 copy_u8InterruptNum , u8 copy_u8edge );
void EXTI_voidEnable(u8 copy_u8InterruptNum);
void EXTI_voidDisable(u8 copy_u8InterruptNum );



#endif