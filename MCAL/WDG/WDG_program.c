/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDG_interface.h"
#include "WDG_private.h"
#include "WDG_configer.h"



void WDT_voidEnable(void)
{
    /*Set The WDG Bit To Enable The WatchDog Timer*/
    SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidSleep(u8 Copy_u8TimeOut)
{
    /*Mask  WDTCR (WDP2:0)  TO CLREAR*/
    WDTCR &= 0b11111000 ;
    /*Set The TimE FOR WDG*/
    WDTCR |= Copy_u8TimeOut;
}

void WDT_voidDisable(void)
{
    /*  WDG DISABLE: */
   WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
   WDTCR = 0;
}