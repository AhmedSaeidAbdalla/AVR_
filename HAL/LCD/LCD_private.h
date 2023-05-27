/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define     LCD_ALL_OUTPUT     0xFF
#define     EIGHT_BIT_MODE     1
#define     FOUR_BIT_MODE      0

#define     FUNCTION_SET_CMD        0x38 //0b00111000
#define     DISPLAY_ON_OFF_CMD      0x0F
#define     DISPLAY_CLEAR_CMD       0x01

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif