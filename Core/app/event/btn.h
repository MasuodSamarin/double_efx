/*
 * btn.h
 *
 *  Created on: Dec 11, 2019
 *      Author: sam
 */

#ifndef APP_EVENT_BTN_H_
#define APP_EVENT_BTN_H_

#include "main.h"


#define BTN_NORMAL_PRESS_TIME	500
#define BTN_LONG_PRESS_TIME		5000



typedef struct Btn_t{
	uint32_t	press_time;
	uint8_t		has_press;
}Btn_t;


void 	Btn_Event_Init(Btn_t *btn);
uint8_t Btn_Event_Handle(Btn_t *btn);

/*
 * which one is better?*/
#define Btn_Event_Set_time_define
#ifdef	Btn_Event_Set_time_define
void Btn_Event_Set_time(Btn_t *btn, uint32_t time);
#else
#define Btn_Event_Set_time(btn, time)	(btn->press_time = time)
#endif




#endif /* APP_EVENT_BTN_H_ */
