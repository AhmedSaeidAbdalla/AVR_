/************************************************
AUTHOR                      Ahmed Saeid Abdalla 
CREATION DATA               22,mar23023
version                     v1.0    
comiler                     GNU GCC
**************************************************

*/

#ifndef BIT_MATH_H 
#define BIT_MATH_H 


/* function like macro to manipulate */


#define SET_BIT(REG_NAME , BIT)                  (REG_NAME |= (1 << BIT)) 
#define CLR_BIT(REG_NAME , BIT)                  REG_NAME = REG_NAME  & ~ (1 << BIT )
#define GET_BIT(REG_NAME , BIT)                  ((REG_NAME >> BIT ) & 0X01)
#define TOG_BIT(REG_NAME , BIT)                  (REG_NAME ^=(1 << BIT))


#define SET_REG(REG_NAME , VALUE)              (REG_NAME = VALUE)
#define GET_REG(REG_NAME)                      (REG_NAME )
#define CLR_REG(REG_NAME)                      (REG_NAME = 0X00)
#define TOG_BIT(REG_NAME, BIT_NUM)             (REG_NAME ^= (1 << BIT_NUM))


#endif