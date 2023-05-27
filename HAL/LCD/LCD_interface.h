/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidClearDisplay(void);
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
void LCD_voidSendNumber(u32 Copy_u32Number);
void LCD_voidSendString(u8 * Copy_pu8StringArray);
void LCD_voidSendCustomCharacter(u8 * Copy_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

#endif