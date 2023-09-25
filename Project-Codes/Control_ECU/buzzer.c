/*
 * buzzer.c
 *
 *  Created on: Jun 23, 2023
 *      Author: dabou
 */

#include "gpio.h"
#include "buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void Buzzer_init()
{

	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);

}
void Buzzer_on(void)
{

	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}
void Buzzer_off(void)
{

	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
