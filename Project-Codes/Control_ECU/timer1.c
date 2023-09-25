/*
 * timer1.c
 *
 *  Created on: Jun 26, 2023
 *      Author: dabou
 */

#include "timer1.h"
#include "common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	SREG |= (1<<7);

	TCNT1 = Config_Ptr->initial_value;

	if(Config_Ptr->mode == COMPARE)
	{
		OCR1A = Config_Ptr ->compare_value;
		TIMSK = (1<<OCIE1A);
		TCCR1A = (1<<FOC1A);
		TCCR1B = (1<<WGM12)|(Config_Ptr->prescaler);
	}
	else if (Config_Ptr->mode == NORMAL)
	{
		TIMSK = (1<<TOIE1);
		TCCR1A = (1<<FOC1A);
		TCCR1B = (Config_Ptr->prescaler);

	}
}

void Timer1_deInit(void)
{
	TCNT1 = 0;
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK = 0;
}

void Timer1_setCallBack(void(*a_ptr)(void))
{

	g_callBackPtr = a_ptr;
}

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}

}

ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}

}
