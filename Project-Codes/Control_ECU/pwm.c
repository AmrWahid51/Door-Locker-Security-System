/*
 * pwm.c
 *
 *  Created on: May 13, 2023
 *      Author: dabou
 */
#include "std_types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "DC_motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void PWM_Timer0_Start(void)
{
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_ENABLE_ID, PIN_OUTPUT);

	TCNT0 = 0; // Set Timer Initial Value to 0

	OCR0  = 255; // Set Compare Value

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
