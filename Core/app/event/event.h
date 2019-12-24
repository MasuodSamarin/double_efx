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
}Event_Mode_t;


typedef struct Event_t{

	Event_Mode_t mode;
	union{
		Btn_t btn;
		Enc_t enc;
		Vol_t vol;
	};
}Event_t;

#endif /* APP_EVENT_EVENT_H_ */
