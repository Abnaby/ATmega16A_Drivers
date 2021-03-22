/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 22 March 2021                                 		      */
/* Version	: V01	- Under constructions		  					      */
/**************************************************************************/
#ifndef TCC_private_H
#define TCC_private_H



/******************************************************************************
* Private Functions 
*******************************************************************************/
static u16 STK_u16ConfigInterval(u8 copy_u8TimeUnit);
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

#define TCCR0_FOC0      7
#define TCCR0_WGM00     6
#define TCCR0_COM01     5
#define TCCR0_COM00     4
#define TCCR0_WGM01     3
#define TCCR0_CS02      2
#define TCCR0_CS01      1
#define TCCR0_CS00      0   


#define TIMSK_OCIE2     7
#define TIMSK_TOIE2     6
#define TIMSK_TICIE1    5
#define TIMSK_OCIE1A    4
#define TIMSK_OCIE1B    3
#define TIMSK_TOIE1    2
#define TIMSK_OCIE0     1
#define TIMSK_TOIE0     0


#define TIFR_OCF2       7
#define TIFR_TOV2       6
#define TIFR_ICF1       5
#define TIFR_OCF1A       4
#define TIFR_OCF1B      3
#define TIFR_TOV1       2
#define TIFR_OCF0       1
#define TIFR_TOV0       0




#define TCC_GENERATE_1_MS      1000
#define TCC_GENERATE_1_US      1000000







/********************************************************************************************   TIMER0  ************************************************************************/
/*!<*************************** Output Compare Register **********************/
#define TCC_OCR0     *((volatile u8 *) (0x5C))
/*!<*************************** Timer/Counter Interrupt Mask Register **********************/
#define TCC_TIMSK    *((volatile u8 *) (0x59))
/*!<*************************** Timer/Counter Interrupt Flag Register **********************/
#define TCC_TIFR     *((volatile u8 *) (0x58))
/*!<*************************** Timer/Counter Control Register **********************/
#define TCC_TCCR0    *((volatile u8 *) (0x53))
/*!<*************************** Timer/Counter Register **********************/
#define TCC_TCNT0    *((volatile u8 *) (0x52))
/*!<*************************** General Interrupt Control Register **********************/
#define SREG         *((volatile u8 *) (0x5F))


/******************************************************************************
* Configuration Constants
*******************************************************************************/
/*		CTC INTERRUPT		*/
void __vector_19(void) __attribute__(( signal , used ));
/*		OVERFLOW INTERRUPT		*/
void __vector_9(void) __attribute__(( signal , used ));




#endif