/*
 * app.h
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "main.h"
#include "glcd.h"
#include "efx.h"
#include "event.h"
#include "hc595.h"
#include "eep.h"

typedef enum State_t{
	STATE_1,
	STATE_2,
	STATE_3,
	STATE_MAX,
}State_t;

typedef struct App_Handle_t{
	Efx_t *cur_efx;
	Efx_t *tmp_efx;

	Event_t event;
	State_t state;

	Enc_t enc;
	Btn_t btn;
	Vol_t vol;

	uint8_t blink_timer;
	uint32_t tick_timer;
}App_Handle_t;



/*
 * typedef the fp to use in the table based array
 * */
typedef void (*Fsm_Fp_t)(App_Handle_t *handle);


/* main FSM function:
 *
 * S1 has only one function which runs on the every event
 * */
void fp_S0_Reset(App_Handle_t *handle);


void fp_S1_All(App_Handle_t *handle);

void fp_S2_Not(App_Handle_t *handle);
void fp_S2_Btn(App_Handle_t *handle);
void fp_S2_Enc(App_Handle_t *handle);
void fp_S2_Vol(App_Handle_t *handle);

void fp_S3_Not(App_Handle_t *handle);
void fp_S3_Btn(App_Handle_t *handle);
void fp_S3_Enc(App_Handle_t *handle);
void fp_S3_Vol(App_Handle_t *handle);

void fp_Service_Menu(void);


void App_Init(App_Handle_t *handle);
void APP_Exec(App_Handle_t *handle);



#endif /* APP_APP_H_ */
