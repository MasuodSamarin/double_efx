/*
 * event.c
 *
 *  Created on: Dec 11, 2019
 *      Author: sam
 */

#include "event.h"


struct Event_t{

	Event_Mode_t	mode;
	union{
		Btn_t	btn;
		Enc_t	enc;
		Vol_t	vol;
	}instance;
};


