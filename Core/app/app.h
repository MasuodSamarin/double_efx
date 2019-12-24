/*
 * app.h
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "main.h"
#include "efx.h"
#include "event.h"

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

}App_Handle_t;



/*
 * typedef the fp to use in the table based array
 * */
typedef void (*Fsm_Fp_t)(App_Handle_t *handle);


/* main FSM function:
 *
 * S1 has only one function which runs on the every event
 * */

void fp_S1_All(App_Handle_t *handle);

void fp_S2_Enot(App_Handle_t *handle);
void fp_S2_Ebtn(App_Handle_t *handle);
void fp_S2_Eenc(App_Handle_t *handle);
void fp_S2_Evol(App_Handle_t *handle);

void fp_S3_Enot(App_Handle_t *handle);
void fp_S3_Ebtn(App_Handle_t *handle);
void fp_S3_Eenc(App_Handle_t *handle);
void fp_S3_Evol(App_Handle_t *handle);





void App_Init(App_Handle_t *handle);
void APP_Exec(App_Handle_t *handle);



#endif /* APP_APP_H_ */
