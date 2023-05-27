/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/

#ifndef WDG_INTERFACE_H
#define WDG_INTERFACE_H

#define WDT_SLEEP_16_3_MS        0b000
#define WDT_SLEEP_32_5_MS        0b001
#define WDT_SLEEP_65_0_MS        0b010
#define WDT_SLEEP_128_0_MS       0b011
#define WDT_SLEEP_256_0_MS       0b100
#define WDT_SLEEP_512_0_MS       0b101
#define WDT_SLEEP_1000_0_MS      0b110
#define WDT_SLEEP_2000_0_MS      0b111




void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidSleep(u8 Copy_u8TimeOut);


#endif