/*
 * event.c
 *
 *  Created on: Dec 11, 2019
 *      Author: sam
 */

#include "event.h"


void Event_Init(Event_t *event, Btn_t *btn, Vol_t *vol){
	event->type = Event_NOT;
	//event->btn = NULL;
	//event->has_e = 0;

	Btn_Event_Init(btn);
	Enc_Event_Init();
	Vol_Event_Init(vol);
}

void Event_Handle(Event_t *event, Btn_t *btn, Vol_t *vol){

//	if (event->has_e)
//		return;

	if (Btn_Event_Handle(btn)){
		//event->has_e = 1;
		event->type = Event_BTN;
		event->btn = btn;
		return;

	}

	if (Enc_Event_Handle()){
		//event->has_e = 1;
		event->type = Event_ENC;
		//event->enc = enc;
		return;
	}

	if (Vol_Event_Handle(vol)){
		//event->has_e = 1;
		event->type = Event_VOL;
		event->vol = vol;
		return;
	}

	event->type = Event_NOT;
	event->btn = NULL;
	//event->has_e = 0;
}


