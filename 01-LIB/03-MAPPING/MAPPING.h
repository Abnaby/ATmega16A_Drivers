<<<<<<< HEAD
/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 15 February 2021                                 		      */
/* Version	: V02							  							  */
/**************************************************************************/

#ifndef MAPPING_H
#define MAPPING_H
/****************************************************      CPU CLK          *********************************************/
#define CPU_CLOCK_FREQ          (16000000UL)                    
/****************************************************      NULL DEF.          *********************************************/
#define NULL 0
/****************************************************      GPIOS          *********************************************/
/*  PORT AND PINS IN ATmage16A  */
#define	PORTA  0
#define	PORTB  1
#define	PORTC  2
#define	PORTD  3

#define	PIN0  0
#define	PIN1  1
#define	PIN2  2
#define	PIN3  3
#define	PIN4  4
#define	PIN5  5
#define	PIN6  6
#define	PIN7  7
/*  GPIO MODES  */
#define INPUT_FLOAT		0
#define INPUT_PULLUP	2
#define OUTPUT			1
/*  OUTPUT MODE */
#define LOW		0
#define HIGH	1

/*  SET AND CLEAR   */
#define SET 0Xff 
#define CLR 0X00 
/****************************************************      INTERRUPTS          *********************************************/
/*      EXTERNAL INTERRUPTS SENSE     */
#define EXT_INT0                    0
#define EXT_INT0_LOW_LEVEL          3
#define EXT_INT0_FALLING_EDGE       6
#define EXT_INT0_RISING_EDGE        9
#define EXT_INT0_LOGICAL_CHANGE     12

#define EXT_INT1                    15
#define EXT_INT1_LOW_LEVEL          18
#define EXT_INT1_FALLING_EDGE       21
#define EXT_INT1_RISING_EDGE        24
#define EXT_INT1_LOGICAL_CHANGE     27
#define EXT_INT2                    30
#define EXT_INT2_FALLING_EDGE       33
#define EXT_INT2_RISING_EDGE        36

/****************************************************      TIMERS          *********************************************/
/*  Trigger Type    */
#define FALLING_EDGE                                                   0
#define RISING_EDGE                                                    1
/*  TCC ID  */
#define TCC_TimerCounter0                                              0
#define TCC_TimerCounter1                                              1
#define TCC_TimerCounter2                                              2
/*      TIMER MODE      */
#define TCC_MODE_NORMAL                                                1
#define TCC_MODE_CTC                                                   2
#define TCC_MODE_PWM_PHASE_CORRECT                                     3
#define TCC_MODE_FAST_PWM                                              4
/*  OC PIN  */
#define TCC_OC_MODE_DISCONNECTED                                       0
/*      OC IN NON PWM MODE      */
#define TCC_OC_MODE_NOTPWM_TOGGLE                                      1
#define TCC_OC_MODE_NOTPWM_CLEAR                                       2
#define TCC_OC_MODE_NOTPWM_SET                                         3
/*      OC IN FAST PWM MODE      */
#define TCC_OC_MODE_FPWM_NON_INVERTING_MODE                            2
#define TCC_OC_MODE_FPWM_INVERTING_MODE                                3
/*      OC IN PHASE CORRECT PWM MODE      */
#define TCC_OC_MODE_PCPWM_PWM_CLEAR_UPCOUNTING                            2
#define TCC_OC_MODE_PCPWM_PWM_SET_DOWNCOUNTRIN                            3

/* TCC CLK SELECT           */
#define TCC_NO_CLK_SOURCE                                              0
#define TCC_CLK_SOURCE_OVER_1                                          1
#define TCC_CLK_SOURCE_OVER_8                                          2
#define TCC_CLK_SOURCE_OVER_64                                         3
#define TCC_CLK_SOURCE_OVER_256                                        4
#define TCC_CLK_SOURCE_OVER_1024                                       5
#define TCC_COUNT_AT_FALLING_EDGE                                      6
#define TCC_COUNT_AT_RASING_EDGE                                       7





=======
/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 15 February 2021                                 		      */
/* Version	: V02							  							  */
/**************************************************************************/

#ifndef MAPPING_H
#define MAPPING_H
/****************************************************      CPU CLK          *********************************************/
#define CPU_CLOCK_FREQ          (16000000UL)                    
/****************************************************      NULL DEF.          *********************************************/
#define NULL 0
/****************************************************      GPIOS          *********************************************/
/*  PORT AND PINS IN ATmage16A  */
#define	PORTA  0
#define	PORTB  1
#define	PORTC  2
#define	PORTD  3

#define	PIN0  0
#define	PIN1  1
#define	PIN2  2
#define	PIN3  3
#define	PIN4  4
#define	PIN5  5
#define	PIN6  6
#define	PIN7  7
/*  GPIO MODES  */
#define INPUT_FLOAT		0
#define INPUT_PULLUP	2
#define OUTPUT			1
/*  OUTPUT MODE */
#define LOW		0
#define HIGH	1

/*  SET AND CLEAR   */
#define SET 0Xff 
#define CLR 0X00 
/****************************************************      INTERRUPTS          *********************************************/
/*      EXTERNAL INTERRUPTS SENSE     */
#define EXT_INT0                    0
#define EXT_INT0_LOW_LEVEL          3
#define EXT_INT0_FALLING_EDGE       6
#define EXT_INT0_RISING_EDGE        9
#define EXT_INT0_LOGICAL_CHANGE     12

#define EXT_INT1                    15
#define EXT_INT1_LOW_LEVEL          18
#define EXT_INT1_FALLING_EDGE       21
#define EXT_INT1_RISING_EDGE        24
#define EXT_INT1_LOGICAL_CHANGE     27
#define EXT_INT2                    30
#define EXT_INT2_FALLING_EDGE       33
#define EXT_INT2_RISING_EDGE        36

/****************************************************      TIMERS          *********************************************/
/*  Trigger Type    */
#define FALLING_EDGE                                                   0
#define RISING_EDGE                                                    1
/*  TCC ID  */
#define TCC_TimerCounter0                                              0
#define TCC_TimerCounter1                                              1
#define TCC_TimerCounter2                                              2
/*      TIMER MODE      */
#define TCC_MODE_NORMAL                                                1
#define TCC_MODE_CTC                                                   2
#define TCC_MODE_PWM_PHASE_CORRECT                                     3
#define TCC_MODE_FAST_PWM                                              4
/*  OC PIN  */
#define TCC_OC_MODE_DISCONNECTED                                       0
/*      OC IN NON PWM MODE      */
#define TCC_OC_MODE_NOTPWM_TOGGLE                                      1
#define TCC_OC_MODE_NOTPWM_CLEAR                                       2
#define TCC_OC_MODE_NOTPWM_SET                                         3
/*      OC IN FAST PWM MODE      */
#define TCC_OC_MODE_FPWM_NON_INVERTING_MODE                            2
#define TCC_OC_MODE_FPWM_INVERTING_MODE                                3
/*      OC IN PHASE CORRECT PWM MODE      */
#define TCC_OC_MODE_PCPWM_PWM_CLEAR_UPCOUNTING                            2
#define TCC_OC_MODE_PCPWM_PWM_SET_DOWNCOUNTRIN                            3

/* TCC CLK SELECT           */
#define TCC_NO_CLK_SOURCE                                              0
#define TCC_CLK_SOURCE_OVER_1                                          1
#define TCC_CLK_SOURCE_OVER_8                                          2
#define TCC_CLK_SOURCE_OVER_64                                         3
#define TCC_CLK_SOURCE_OVER_256                                        4
#define TCC_CLK_SOURCE_OVER_1024                                       5
#define TCC_COUNT_AT_FALLING_EDGE                                      6
#define TCC_COUNT_AT_RASING_EDGE                                       7





>>>>>>> 821481ee74b2235c8cfee9a07fcd85056c4f2ee1
#endif