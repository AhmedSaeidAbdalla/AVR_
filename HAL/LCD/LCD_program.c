/*********************************************
/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"




void LCD_voidInit(void)
{
    #if LCD_INIT_MODE == EIGHT_BIT_MODE
    /*Initialize Data Port*/
    DIO_voidSetPortSpecificDirection(LCD_DATA_PORT, LCD_ALL_OUTPUT);
    /*Initialize Control Pins*/
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);

    // Wait For More Than 30 ms
    _delay_ms(40);

    /*Send Function Set Command*/
    LCD_voidSendCommand(FUNCTION_SET_CMD);
    /*Send Display On/Off Control Command*/
    LCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
    /*Send Display Clear Command*/
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);


    #elif LCD_INIT_MODE == FOUR_BIT_MODE

    #else
        #error("LCD_INIT_MODE Configuration Error")
    #endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    // Set The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    // Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    // Set The Command On The Data/Command Port
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    /*Send Enable Pulse*/
    /*Low*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    /*High For (2) msec*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    /*Low*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);


    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
   
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);

}

void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);
}

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8CharacterAddress = 0;
    
    if(Copy_u8XPos == 0)
    {
        
        Local_u8CharacterAddress = Copy_u8YPos;
    }
    else if (Copy_u8XPos == 1)
    {
      
        Local_u8CharacterAddress = Copy_u8YPos + 0x40;
    }
    else
    {
        //  an error 
    }
   
    SET_BIT(Local_u8CharacterAddress, 7);
   
    LCD_voidSendCommand(Local_u8CharacterAddress);  
}

void LCD_voidSendString(u8 * Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter = 0 ;
    
    while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        
        LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
    u8 Local_u8ArrayNumber[10];
    s8 Local_s8LoopCounter = 0;
    while(Copy_u32Number != 0)
    {
        Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--;
    while(Local_s8LoopCounter >= 0)
    {
        LCD_voidSendData(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }
}


void LCD_voidSendCustomCharacter(u8 * Copy_pu8CharacterArray,
                                 u8 Copy_u8PatternNumber,
                                 u8 Copy_u8XPosition,
                                 u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter;
    u8 Local_u8CGRAMAddress = 0;
    
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
    
    SET_BIT(Local_u8CGRAMAddress, 6);
   
    LCD_voidSendCommand(Local_u8CGRAMAddress);
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
       
        LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }
   
    LCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);
    
    LCD_voidSendData(Copy_u8PatternNumber);
}

