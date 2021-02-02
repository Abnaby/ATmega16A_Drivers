/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 28 January 2021                                 		      */
/* Version	: V01							  							  */
/**************************************************************************/
#ifndef EXT_INT_interface_H
#define EXT_INT_interface_H
/******************************************************************************
* Includes
*******************************************************************************/


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define GPIO_FIRST_PIN	0
#define GPIO_LAST_PIN	7

/******************************************************************************
* Typedefs
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Func Name   : EXTINT_voidInit();
* Description :	Disable INT0, INT1 and INT2
* Parameters  : void
* Return type : void 
******************************************************************************/
void EXTINT_voidInit();
/******************************************************************************
* Func Name   : EXTINT_voidInit();
* Description :	Enable Interrupts
* Parameters  : copy_u8InterruptID  - INT0, INT1 or INT2 -
                copy_u8InterruptMode - INT0_LOW_LEVEL, INT0_FALLING_EDGE, INT0_RISING_EDGE or INT0_LOGICAL_CHANGE-
                                     - INT1_LOW_LEVEL, INT1_FALLING_EDGE, INT1_RISING_EDGE or INT1_LOGICAL_CHANGE-
                                     - INT2_FALLING_EDGE or INT2_RISING_EDGE -
                Callback : Function that has Interrupt code
* Return type : 1 - successfully
                0 - unsuccessful
******************************************************************************/
void EXTINT_voidEnable(u8 copy_u8InterruptID );
void EXTINT_voidMode(u8 copy_u8InterruptID , u8 copy_u8InterruptMode , void(*copy_funcAddress)(void));
void EXTINT_voidDisable(u8 copy_u8InterruptID );
void EXTINT_voidGlobalIntEnable();

#endif