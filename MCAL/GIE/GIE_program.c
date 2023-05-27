/****************************************************************

Author          Ahmed Saeid Abdalla

Data            29,MAR 2023

Compiler        GNU GCC

Version         v1.0

***************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"



void GIE_voidEnableGlobleInterrupt(void)
{
SET_BIT(SREG , SREG_I);
}


void GIE_voidDisableGlobleInterrupt(void)
{
CLR_BIT(SREG , SREG_I);
}