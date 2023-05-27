
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include  <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_voidInit(void)
{
DIO_voidSetPinDirection(KPD_Rows_PORT , KPD_Row0_PIN ,INPUT);
DIO_voidSetPinDirection(KPD_Rows_PORT , KPD_Row1_PIN ,INPUT);
DIO_voidSetPinDirection(KPD_Rows_PORT , KPD_Row2_PIN ,INPUT);
DIO_voidSetPinDirection(KPD_Rows_PORT , KPD_Row3_PIN ,INPUT);

DIO_voidSetPinValue(KPD_Rows_PORT, KPD_Row0_PIN , PULLUP);
DIO_voidSetPinValue(KPD_Rows_PORT, KPD_Row1_PIN , PULLUP);
DIO_voidSetPinValue(KPD_Rows_PORT, KPD_Row2_PIN , PULLUP);
DIO_voidSetPinValue(KPD_Rows_PORT, KPD_Row3_PIN , PULLUP);


DIO_voidSetPinDirection(KPD_Rows_PORT , KEY_Colume0_PIN ,OUTPUT);
DIO_voidSetPinDirection(KPD_Rows_PORT , KEY_Colume1_PIN ,OUTPUT);
DIO_voidSetPinDirection(KPD_Rows_PORT , KEY_Colume2_PIN ,OUTPUT);
DIO_voidSetPinDirection(KPD_Rows_PORT , KEY_Colume3_PIN ,OUTPUT);

DIO_voidSetPinValue(KPD_Rows_PORT, KEY_Colume0_PIN, HIGH);
DIO_voidSetPinValue(KPD_Rows_PORT, KEY_Colume1_PIN, HIGH);
DIO_voidSetPinValue(KPD_Rows_PORT, KEY_Colume2_PIN, HIGH);
DIO_voidSetPinValue(KPD_Rows_PORT, KEY_Colume3_PIN, HIGH);

}
u8 KPD_u8GetPressedKey(void)
{
    static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COULMNS_NUM] = KPD_ARR_VAL;
    static u8 Local_u8KPDColumnsArray[KPD_COULMNS_NUM] = {KEY_Colume0_PIN, KEY_Colume1_PIN, KEY_Colume2_PIN, KEY_Colume3_PIN};
    static u8 Local_u8KPDRowsArray[KPD_ROWS_NUM] = {KPD_Row0_PIN, KPD_Row1_PIN, KPD_Row2_PIN, KPD_Row3_PIN};
    u8 Local_u8RowValue;
    u8 Local_u8ColumnsIterator;
    u8 Local_u8RowsIterator;
    u8 Local_u8PressedKey = KPD_NOT_PRESSED_VAL;
    for(Local_u8ColumnsIterator = 0; Local_u8ColumnsIterator < KPD_COULMNS_NUM; Local_u8ColumnsIterator++)
    {
        /*Activate A Column , Activate (Ground)*/
        DIO_voidSetPinValue(KPD_CLOUMS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], LOW);
        /*Iterate On The KPD Rows */
        for(Local_u8RowsIterator = 0; Local_u8RowsIterator < KPD_ROWS_NUM; Local_u8RowsIterator++)
        {
            /*Get The Row Value*/
            Local_u8RowValue = DIO_u8GetPinValue(KPD_Rows_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
            if(Local_u8RowValue == LOW)
            {
                /*Get The Pressed Key*/
                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowsIterator][Local_u8ColumnsIterator];
                /*Polling (busy wait) till the key is released*/
                while(Local_u8RowValue == LOW)
                {
                    Local_u8RowValue = DIO_u8GetPinValue(KPD_Rows_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
                }
                /*Return The Pressed Key*/
                return Local_u8PressedKey;
            }
        }
        /*Deactivate A Column , Deactivate (VCC)*/
        DIO_voidSetPinValue(KPD_CLOUMS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], HIGH);
    }
    /*Return The Default Value*/
    return Local_u8PressedKey;





}
u16 u16KPD_Add(u8 Local_u8PressedKey )
{
    u8 local_u8numer1;
    u8 local_u8numer2;
    u8 operation;
    u8 local_FinalResult;
 
   local_u8numer1 = KPD_u8GetPressedKey();
    operation     = KPD_u8GetPressedKey();
   local_u8numer2 = KPD_u8GetPressedKey();
    LCD_voidSendData(local_u8numer1);
    LCD_voidSendData(local_u8numer2);
     LCD_voidSendData(operation);

   if (operation == '+')
   {

      local_FinalResult = local_u8numer1 + local_u8numer2 ;
      LCD_voidSendData(local_FinalResult);
   }
     local_u8numer1 =    KPD_u8GetPressedKey();
     operation     = KPD_u8GetPressedKey();
     local_u8numer2 = KPD_u8GetPressedKey();
     LCD_voidSendData(local_u8numer1);
    LCD_voidSendData(local_u8numer2);
     LCD_voidSendData(operation);
   else if ( operation == '-')
   {
      local_FinalResult = local_u8numer1 - local_u8numer2 ;
      LCD_voidSendData(local_FinalResult);
   }
local_u8numer1 = KPD_u8GetPressedKey();
    operation     = KPD_u8GetPressedKey();
   local_u8numer2 = KPD_u8GetPressedKey();
   LCD_voidSendData(local_u8numer1);
    LCD_voidSendData(local_u8numer2);
     LCD_voidSendData(operation);
   else if (operation == '/')
   {
      local_FinalResult = local_u8numer1 / local_u8numer2 ;
      LCD_voidSendData(local_FinalResult);
   }
   local_u8numer1 = KPD_u8GetPressedKey();
    operation     = KPD_u8GetPressedKey();
   local_u8numer2 = KPD_u8GetPressedKey();
   LCD_voidSendData(local_u8numer1);
    LCD_voidSendData(local_u8numer2);
     LCD_voidSendData(operation);
   else if (operation == '*')
   {
      local_FinalResult = local_u8numer1 * local_u8numer2 ;
      LCD_voidSendData(local_FinalResult);
   }


    


}
