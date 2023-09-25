 /******************************************************************************
 *
 * Module: timer1
 *
 * File Name: Timer1.h
 *
 * Description: Header file for timer1 Driver
 *
 * Author: Amr Wahid
 *
 *******************************************************************************/
#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"


/*******************************************************************************
 *                      Structures and enums                                   *
 *******************************************************************************/
typedef enum{

	CLOCK_NULL,CLOCK_1,CLOCK_8,CLOCK_64,CLOCK_256,CLOCK_1024,CLOCK_EXT_FALLING,CLOCK_EXT_RISING
}Timer1_Prescaler;

typedef enum{

	COMPARE,NORMAL

} Timer1_Mode;

typedef struct {
 uint16 initial_value;
 uint16 compare_value; // it will be used in compare mode only.
 Timer1_Prescaler prescaler;
 Timer1_Mode mode;
} Timer1_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Timer1_init(const Timer1_ConfigType * Config_Ptr);
void Timer1_deInit(void);
void Timer1_setCallBack(void(*a_ptr)(void));




#endif /* TIMER1_H_ */
