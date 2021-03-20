/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 15 February 2021                                 		      */
/* Version	: V01							  							  */
/**************************************************************************/
#ifndef TCC_interface_H
#define TCC_interface_H
/******************************************************************************
* Includes
*******************************************************************************/


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define _IN_MS  0
#define _IN_US  1
#define TIMER0_RANGE	255
#define TIMER1_RANGE	65535
/******************************************************************************
* Typedefs
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/

/***************************************************************************************************************
* Func Name   : TCC_voidInit(void);
* Description :	Disable Overflow interrupt and Output Compare Interrupt, Clear Flags and Rest TCNT and OCR at 0
* Parameters  : void
* Return type : void 
***************************************************************************************************************/
void TCC_voidInit(void);
/***************************************************************************************************************
* Func Name   : TCC_voidCounterInit(u8 copy_u8TimerCounterID, u8 copy_u8CountAt);
* Description :	Initialize Trigger To Work As Counter
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
                copy_u8CountAt          - FALLING_EDGE or RISING_EDGE   -
* Return type : void 
***************************************************************************************************************/
void TCC_voidCounterInit(u8 copy_u8TimerCounterID, u8 copy_u8CountAt);
/***************************************************************************************************************
* Func Name   : TCC_u16Get6CounterValue(u8 copy_u8TimerCounterID);
* Description :	Get Number Of Counts.
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
* Return type : u16 - Number of counts. 
***************************************************************************************************************/
u16 TCC_u16GetCounterValue(u8 copy_u8TimerCounterID);
/***************************************************************************************************************
* Func Name   : TCC_voidSetCounterValue(u8 copy_u8TimerCounterID,u16 copy_u16CounterValue);
* Description :	Initialize Counts In Register.
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
				copy_u8CounterValue		- Value 0: 255 For Timer/counter0 and 2, Value : 0 : 65535	-
* Return type : void.
***************************************************************************************************************/
void TCC_voidSetCounterValue(u8 copy_u8TimerCounterID,u16 copy_u16CounterValue);
/***************************************************************************************************************
* Func Name   : TCC_voidSetTimerClkSource(u8 copy_u8TimerCounterID,u8 copy_u8ClkPrescaler);
* Description :	Set Input Clk Source For Timer Control Logic.
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
				copy_u8ClkPrescaler		- TCC_NO_CLK_SOURCE, TCC_CLK_SOURCE_OVER_1, TCC_CLK_SOURCE_OVER_8, TCC_CLK_SOURCE_OVER_64 or TCC_CLK_SOURCE_OVER_256, TCC_CLK_SOURCE_OVER_1024-
* Return type : void.
***************************************************************************************************************/

void TCC_voidSetTimerClkSource(u8 copy_u8TimerCounterID,u8 copy_u8ClkPrescaler);

/***************************************************************************************************************
* Func Name   : TCC_voidSetTimerMode(u8 copy_u8TimerCounterID,u8 copy_u8TimerMode);
* Description :	Set Mode For Timer.
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
				copy_u8TimerMode		- TCC_MODE_NORMAL, TCC_MODE_CTC, TCC_MODE_PWM_PHASE_CORRECT or TCC_MODE_FAST_PWM-
* Return type : void.
***************************************************************************************************************/
void TCC_voidSetTimerMode(u8 copy_u8TimerCounterID,u8 copy_u8TimerMode);

/***************************************************************************************************************
* Func Name   : TCC_voidSetOutputComparePinMode(u8 copy_u8TimerCounterID,u8 copy_u8OC_Mode);
* Description :	Set Mode Of T0 (Output compare pin).
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
				copy_u8OC_Mode			-TCC_OC_MODE_DISCONNECTED, TCC_OC_MODE_NOTPWM_TOGGLE, TCC_OC_MODE_NOTPWM_CLEAR, TCC_OC_MODE_NOTPWM_SET
										 TCC_OC_MODE_FPWM_NON_INVERTING_MODE, TCC_OC_MODE_FPWM_INVERTING_MODE
										 TCC_OC_MODE_PCPWM_PWM_CLEAR_UPCOUNTING or TCC_OC_MODE_PCPWM_PWM_SET_DOWNCOUNTRIN-		
* Return type : void.
***************************************************************************************************************/
void TCC_voidSetOutputComparePinMode(u8 copy_u8TimerCounterID,u8 copy_u8OC_Mode);
/***************************************************************************************************************
* Func Name   : TCC_voidSetCTC_CompareValue(u8 copy_u8TimerCounterID,u16 copy_u16CompareValue);
* Description :	Set Value OF Compare Match.
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
				copy_u16CompareValue	- 0-->255 for TIMER0 OR TIMER1
										  0-->65535 for TIMER1-
* Return type : void.
***************************************************************************************************************/
void TCC_voidSetCTC_CompareValue (u8 copy_u8TimerCounterID,u16 copy_u16CompareValue);
/***************************************************************************************************************
* Func Name   : TCC_voidSetCTC_BusyWait(u8 copy_u8TimerCounterID,u16 copy_u16CompareValue);
* Description :	Synchronous Function Like Delay.
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
				copy_u16CompareValue	- 0-->255 for TIMER0 OR TIMER1
										  0-->65535 for TIMER1-
* Return type : void.
***************************************************************************************************************/
u8 TCC_u8setCTC_BusyWait(u8 copy_u8TimerCounterID , u8 copy_u8Time , u8 copy_u8TimeUnit);
/***************************************************************************************************************
* Func Name   : TCC_voidStopTimer(u8 copy_u8TimerCounterID);
* Description :	Disable TIMERx
* Parameters  : copy_u8TimerCounterID   - TCC_TimerCounter0, TCC_TimerCounter1 or TCC_TimerCounter2-
* Return type : void.
***************************************************************************************************************/
void TCC_voidStopTimer(u8 copy_u8TimerCounterID);

#endif