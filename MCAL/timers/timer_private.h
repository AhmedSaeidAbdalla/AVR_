/*
**********************************************
Author       Ahmed saeid Abdalla

Data        7Abril,2023

Compiler    GNU GCC
**********************************************
*/




/* register for timers */

#define    TCCR0   *((volatile u8 *)(0X53))

#define    TCCR0_CS00    0
#define    TCCR0_CS01    1
#define    TCCR0_CS02    2
#define    TCCR0_WGM01   3
#define    TCCR0_COM00   4
#define    TCCR0_COM01   5
#define    TCCR0_WGM00   6
#define    TCCR0_FOC0    7


#define     OCR0   *((volatile u8 *)(0x5C))	 //output comper register
#define    TCNT0   *((volatile u8 *) (0X52))


#define    TIMSK   *((volatile u8 *) (0X59))

#define     TIMSK_TOIE0       0				// Timer Overflow Interrupt Enable
#define     TIMSK_OCIE0       1   
#define     TIMSK_TICIE1      5   


#define   TOIE0     0
#define   OCIE      1
#define   TOIE1     2
#define   OCIE1B    3
#define   OCIE1A    4
#define   TICIE1    5
#define   TOIE2     6
#define   OCIE2     7


#define    TIFR      *((volatile u8 *)(0X58))

#define   TIFR_TOVO     0
#define   TIFR_OCF0     1
#define   TIFR_ICFI     5    //CHEAK IF ITS OK 

#define    NULL     '\0'

/*TIMER (1)*/


#define TCCR1A   *((volatile u8 *)(0x4F))
#define TCCR1B   *((volatile u8 *)(0x4E))

#define TCNT1H   *((volatile u8 *)(0x4D))
#define TCNT1L   *((volatile u8 *)(0x4C))
#define OCR1AH   *((volatile u8 *)(0x4B))
#define OCR1AL   *((volatile u8 *)(0x4A))
#define OCR1BH   *((volatile u8 *)(0x49))
#define OCR1BL   *((volatile u8 *)(0x48))
#define ICR1H    *((volatile u8 *)(0x47))
#define ICR1L    *((volatile u8 *)(0x46))
#define TCNT1   *((volatile u16 *)(0x4C))
#define OCR1A   *((volatile u16 *)(0x4A))
#define OCR1B   *((volatile u16 *)(0x48))
#define ICR1    *((volatile u16 *)(0x46))


/*PINS FOR TCCR1A */

#define TCCR1A_WGM10     0
#define TCCR1A_WGM11     1
#define TCCR1A_FOC1B     2
#define TCCR1A_FOC1A     3
#define TCCR1A_COM1B0    4
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1A1    7


/*pins for TCCR1B */

#define TCCR1B_CS10      0
#define TCCR1B_CS11      1   
#define TCCR1B_CS12      2
#define TCCR1B_WGM12     3
#define TCCR1B_WGM13     4
#define TCCR1B_ICES1     6
#define TCCR1B_ICNC1     7

#define BIT_MASK_TIMER1   
