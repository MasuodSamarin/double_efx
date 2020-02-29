/*
 * event.h
 *
 *  Created on: Dec 11, 2019
 *      Author: sam
 */

#ifndef APP_EVENT_EVENT_H_
#define APP_EVENT_EVENT_H_


#include "btn.h"
#include "enc.h"
#include "vol.h"


typedef enum{
	Event_NOT = 0,
	Event_BTN,
	Event_ENC,
	Event_VOL,
	EVENT_MAX
}Event_Type_t;


typedef struct Event_t{

	//uint8_t has_e;
	Event_Type_t type;
	union{
		Btn_t *btn;
		//Enc_t *enc;
		Vol_t *vol;
	};
}Event_t;



void Event_Init(Event_t *event, Btn_t *btn, Vol_t *vol);
void Event_Handle(Event_t *event, Btn_t *btn, Vol_t *vol);






#endif /* APP_EVENT_EVENT_H_ */
