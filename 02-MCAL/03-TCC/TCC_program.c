/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 15 February 2021                                 		      */
/* Version	: V01							  							  */
/**************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MAPPING.h"

#include "TCC_interface.h"
#include "TCC_private.h"
#include "TCC_config.h"
static u16 Global_u16PrescalerValue = 1 ;
void TCC_voidInit(void)
{
	/*		DISABLE INTERRUPTS(COMPARE MATCH AND OVERFLOW)		*/
	CLR_BIT(TCC_TIMSK,TIMSK_OCIE0);
	CLR_BIT(TCC_TIMSK,TIMSK_TOIE0);
	/*	Disconned OC pin	*/
	CLR_BIT(TCC_TCCR0,TCCR0_COM00);
	CLR_BIT(TCC_TCCR0,TCCR0_COM01);
	/*		CLEAR FLAGS	(OVF AND OCR)			*/
	TCC_TIFR	= 	0x3 ; 
	/*		CLEAR RCNT AND OCR		*/
	TCC_TCNT0	=	0	;
	TCC_OCR0	=	0	;
}
static u16 STK_u16ConfigInterval(u8 copy_u8TimeUnit)
{
	u32 LOC_u32Clk = 0 ;
	if(Global_u16PrescalerValue > 0 )
	{
		LOC_u32Clk = CPU_CLOCK_FREQ / Global_u16PrescalerValue ;
	}
	if(copy_u8TimeUnit == _IN_MS)
	{
		return LOC_u32Clk / TCC_GENERATE_1_MS ;
	}
	else if (copy_u8TimeUnit == _IN_US)
	{
		return LOC_u32Clk / TCC_GENERATE_1_US ;
	}
	else
	{
		//<!TODO> ERROR STATE : ERROR IN copy_u8TimeUnit
	}
	return 0 ;
}
void TCC_voidCounterInit(u8 copy_u8TimerCounterID, u8 copy_u8CountAt)
{
	switch(copy_u8TimerCounterID)
	{
		case TCC_TimerCounter0 :	
			/*	SET CLK SOURCE	*/
			if(copy_u8CountAt == FALLING_EDGE)
			{
				SET_BIT(TCC_TCCR0,TCCR0_CS02);
				SET_BIT(TCC_TCCR0,TCCR0_CS01);
				CLR_BIT(TCC_TCCR0,TCCR0_CS00);
			}
			else if(copy_u8CountAt == RISING_EDGE)
			{
				SET_BIT(TCC_TCCR0,TCCR0_CS02);
				SET_BIT(TCC_TCCR0,TCCR0_CS01);
				SET_BIT(TCC_TCCR0,TCCR0_CS00);
			}
			else
			{
				//<!TODO> ERROR STATE : ERROR IN COUNTER TYPE
			}
			break;


	}
	/*	INITIALIZE TCNT BY 0	*/
	TCC_TCNT0	=	0	;
	
}
u16 TCC_u16GetCounterValue(u8 copy_u8TimerCounterID)
{
	u16 LOC_u16Counter = 0 ;
	switch(copy_u8TimerCounterID)
	{
		case TCC_TimerCounter0 :	LOC_u16Counter = TCC_TCNT0	; break ;
		case TCC_TimerCounter1 :	break ;
		case TCC_TimerCounter2 :	break ;
	}
	return LOC_u16Counter ;
}

void TCC_voidSetCounterValue(u8 copy_u8TimerCounterID,u16 copy_u16CounterValue)
{
	switch(copy_u8TimerCounterID)
	{
		case TCC_TimerCounter0 :	
			if(copy_u16CounterValue >=0 && copy_u16CounterValue <= TIMER0_RANGE)
			{
				TCC_TCNT0 = copy_u16CounterValue	; 
			}
			else
			{
				//<!TODO> ERROR STATE : OUT OF 8-BIT COUNTER RANGE
			}
			break ;			
		case TCC_TimerCounter1 :	break ;
		case TCC_TimerCounter2 :	break ;
	}
}
void TCC_voidSetTimerClkSource(u8 copy_u8TimerCounterID,u8 copy_u8ClkPrescaler)
{
	if(copy_u8TimerCounterID  == TCC_TimerCounter0)
	{
		switch(copy_u8ClkPrescaler)
		{
			case TCC_NO_CLK_SOURCE : 
				Global_u16PrescalerValue = 0 ;
				CLR_BIT(TCC_TCCR0,TCCR0_CS00);
				CLR_BIT(TCC_TCCR0,TCCR0_CS01);
				CLR_BIT(TCC_TCCR0,TCCR0_CS02);
				break ; 
			case TCC_CLK_SOURCE_OVER_1	:
				Global_u16PrescalerValue = 1 ;
				SET_BIT(TCC_TCCR0,TCCR0_CS00);
				CLR_BIT(TCC_TCCR0,TCCR0_CS01);
				CLR_BIT(TCC_TCCR0,TCCR0_CS02);
				break ;
			case TCC_CLK_SOURCE_OVER_8 :
				Global_u16PrescalerValue = 8; 
				CLR_BIT(TCC_TCCR0,TCCR0_CS00);
				SET_BIT(TCC_TCCR0,TCCR0_CS01);
				CLR_BIT(TCC_TCCR0,TCCR0_CS02);
				break;
			case TCC_CLK_SOURCE_OVER_64 :
				Global_u16PrescalerValue = 64 ;
				SET_BIT(TCC_TCCR0,TCCR0_CS00);
				SET_BIT(TCC_TCCR0,TCCR0_CS01);
				CLR_BIT(TCC_TCCR0,TCCR0_CS02);
				break ;
			case TCC_CLK_SOURCE_OVER_256 : 
				Global_u16PrescalerValue =256 ;
				CLR_BIT(TCC_TCCR0,TCCR0_CS00);
				CLR_BIT(TCC_TCCR0,TCCR0_CS01);
				SET_BIT(TCC_TCCR0,TCCR0_CS02);
				break ;
			case TCC_CLK_SOURCE_OVER_1024 :
				Global_u16PrescalerValue = 1024 ; 
				SET_BIT(TCC_TCCR0,TCCR0_CS00);
				CLR_BIT(TCC_TCCR0,TCCR0_CS01);
				SET_BIT(TCC_TCCR0,TCCR0_CS02);
				break ;
			default : 
				//<!TODO> ERROR STATE : OUT OF Prescaler Range.
				break;
		}
	}
	else if (copy_u8TimerCounterID == TCC_TimerCounter1)
	{

	}
	else if (copy_u8TimerCounterID == TCC_TimerCounter2)
	{
		
	}
	else
	{
		//<!TODO> ERROR STATE : OUT OF Timer Options.
	}

}
void TCC_voidSetTimerMode(u8 copy_u8TimerCounterID,u8 copy_u8TimerMode)
{
	if(copy_u8TimerCounterID  == TCC_TimerCounter0)
	{
		switch(copy_u8TimerMode)
		{
			case TCC_MODE_NORMAL : 
				CLR_BIT(TCC_TCCR0,TCCR0_WGM00);
				CLR_BIT(TCC_TCCR0,TCCR0_WGM01);
				break ; 
			case TCC_MODE_CTC	:
				CLR_BIT(TCC_TCCR0,TCCR0_WGM00);
				SET_BIT(TCC_TCCR0,TCCR0_WGM01);
				break ;
			case TCC_MODE_PWM_PHASE_CORRECT :
				SET_BIT(TCC_TCCR0,TCCR0_WGM00);
				CLR_BIT(TCC_TCCR0,TCCR0_WGM01);			
				break;
			case TCC_MODE_FAST_PWM :
				SET_BIT(TCC_TCCR0,TCCR0_WGM00);
				SET_BIT(TCC_TCCR0,TCCR0_WGM01);
				break ;
			default : 
				//<!TODO> ERROR STATE : OUT OF Timer Mode Options.
				break;
		}
	}
	else if (copy_u8TimerCounterID == TCC_TimerCounter1)
	{

	}
	else if (copy_u8TimerCounterID == TCC_TimerCounter2)
	{
		
	}
	else
	{
		//<!TODO> ERROR STATE : OUT OF Timer Options.
	}
}
void TCC_voidSetOutputComparePinMode(u8 copy_u8TimerCounterID,u8 copy_u8OC_Mode)
{
	if(copy_u8TimerCounterID == TCC_TimerCounter0)
	{
		switch(copy_u8OC_Mode)
		{
			case TCC_OC_MODE_DISCONNECTED :
				/*	Disconned OC pin	*/
				CLR_BIT(TCC_TCCR0,TCCR0_COM00);
				CLR_BIT(TCC_TCCR0,TCCR0_COM01);
				break;
			case TCC_OC_MODE_NOTPWM_TOGGLE : 
				SET_BIT(TCC_TCCR0,TCCR0_COM00);
				CLR_BIT(TCC_TCCR0,TCCR0_COM01);			
				break;
			case TCC_OC_MODE_NOTPWM_CLEAR :
			//case TCC_OC_MODE_FPWM_NON_INVERTING_MODE :
		//	case TCC_OC_MODE_PCPWM_PWM_CLEAR_UPCOUNTING :
				CLR_BIT(TCC_TCCR0,TCCR0_COM00);
				SET_BIT(TCC_TCCR0,TCCR0_COM01);
				break ;
			case TCC_OC_MODE_NOTPWM_SET :
			//case TCC_OC_MODE_FPWM_INVERTING_MODE :
		//	case TCC_OC_MODE_PCPWM_PWM_SET_DOWNCOUNTRIN :
				SET_BIT(TCC_TCCR0,TCCR0_COM00);
				SET_BIT(TCC_TCCR0,TCCR0_COM01);
			default:
				//<!TODO> ERROR STATE : OUT OF OC pin Options.
				break;
		}
	}
	else if (copy_u8TimerCounterID == TCC_TimerCounter1)
	{

	}
	else if (copy_u8TimerCounterID == TCC_TimerCounter2)
	{
		
	}
	else
	{
		//<!TODO> ERROR STATE : OUT OF Timer Options.
	}


}
void TCC_voidSetCTC_CompareValue (u8 copy_u8TimerCounterID,u16 copy_u16CompareValue)
{
	if(copy_u8TimerCounterID == TCC_TimerCounter0)
	{
		if(copy_u16CompareValue >=0 && copy_u16CompareValue <= TIMER0_RANGE)
		{
			TCC_OCR0 = copy_u16CompareValue ;
		}
		else
		{

		}

	}
	
}
u8 TCC_u8setCTC_BusyWait(u8 copy_u8TimerCounterID , u8 copy_u8Time , u8 copy_u8TimeUnit)
{
	u16 LOC_u16Count = 0 ;
	u8 LOC_u8ErrorState = 0 ;
	if(copy_u8TimerCounterID == TCC_TimerCounter0)
	{
		LOC_u16Count = (STK_u16ConfigInterval(copy_u8TimeUnit)*copy_u8Time) -1;
		//LOC_u16Count = ((CPU_CLOCK_FREQ /Global_u16PrescalerValue ) * (copy_u8Time / 1000.0) ) -1 ;
		if (LOC_u16Count>=0 && LOC_u16Count <=TIMER0_RANGE)
		{
			TCC_OCR0 = 0 ;
			TCC_TCNT0 = 0 ;
			TCC_OCR0 = LOC_u16Count ;
			/* Monitor OCF0 flag */
			//	while(!(GET_BIT(TCC_TIFR,TIFR_OCF0)));
			while(TCC_TIFR & (1<<TIFR_OCF0) == 0) ; 
			LOC_u8ErrorState = 1 ;
			/*	Clear Flag	*/
			SET_BIT(TCC_TIFR,TIFR_OCF0);
		} 
	}
	return LOC_u8ErrorState ;
}
void TCC_voidStopTimer(u8 copy_u8TimerCounterID)
{
	if(copy_u8TimerCounterID == TCC_TimerCounter0)
	{
		CLR_BIT(TCC_TCCR0,TCCR0_CS00);
		CLR_BIT(TCC_TCCR0,TCCR0_CS01);
		CLR_BIT(TCC_TCCR0,TCCR0_CS02);
	}
}
/*
void __vector_1(void)
{
	Callback_INT0();	
}

void __vector_2(void)
{
		Callback_INT1();
	
		
}

void __vector_18(void)
{
	Callback_INT2();
}*/