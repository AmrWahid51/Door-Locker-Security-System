/*
 * DC_motor.h
 *
 *  Created on: May 11, 2023
 *      Author: dabou
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"




#define DC_MOTOR_PORT_ID       PORTB_ID
#define DC_MOTOR_PINA_ID       PIN0_ID
#define DC_MOTOR_PINB_ID       PIN1_ID
#define DC_MOTOR_ENABLE_ID     PIN3_ID

typedef enum DcMotor_State
{STOP,CLOCKWISE,ANTICLOCKWISE
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state);


#endif /* DC_MOTOR_H_ */
