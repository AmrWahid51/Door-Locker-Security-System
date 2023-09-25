 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzers.h
 *
 * Description: buzzer used as alarm
 *
 * Author: Amr Wahid
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID                      PORTC_ID
#define BUZZER_PIN_ID                       PIN4_ID



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Buzzer_init();
void Buzzer_on(void);
void Buzzer_off(void);

#endif /* BUZZER_H_ */
