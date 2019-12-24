/*
 * app.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */


#include "app.h"



/*
 * function-pointers table for main FSM
 * declare a array of Fsm_Fp_t type
 * fill it by the function prototypes
 *
 *
 */
/* E/S		STATE1				STATE2				STATE3
 *
 * not		fp_S1_All			fp_S2_Enot			fp_S3_Enot
 * btn		fp_S1_All			fp_S2_Ebtn			fp_S3_Ebtn
 * enc		fp_S1_All			fp_S2_Eenc			fp_S3_Eenc
 * vol		fp_S1_All			fp_S2_Evol			fp_S3_Evol
 *
 */

const Fsm_Fp_t fsm_fp_box[EVENT_MAX][STATE_MAX]={

		{ fp_S1_All, fp_S2_Enot, fp_S3_Enot},
		{ fp_S1_All, fp_S2_Ebtn, fp_S3_Ebtn},
		{ fp_S1_All, fp_S2_Eenc, fp_S3_Eenc},
		{ fp_S1_All, fp_S2_Evol, fp_S3_Evol}

};




void App_Init(App_Handle_t *handle){}
void APP_Exec(App_Handle_t *handle){}
