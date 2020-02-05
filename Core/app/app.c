/*
 * app.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */


#include "app.h"
//extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim14;



/*
 * function-pointers table for main FSM
 * declare a array of Fsm_Fp_t type
 * fill it by the function prototypes
 *
 *
 */
/* E/S		STATE1				STATE2				STATE3
 *
 * not		fp_S1_All			fp_S2_Not			fp_S3_Not
 * btn		fp_S1_All			fp_S2_Btn			fp_S3_Btn
 * enc		fp_S1_All			fp_S2_Eenc			fp_S3_Eenc
 * vol		fp_S1_All			fp_S2_Evol			fp_S3_Evol
 *
 */

const Fsm_Fp_t fsm_fp_box[EVENT_MAX][STATE_MAX]={

		{ fp_S1_All, fp_S2_Not, fp_S3_Not},
		{ fp_S1_All, fp_S2_Btn, fp_S3_Btn},
		{ fp_S1_All, fp_S2_Enc, fp_S3_Enc},
		{ fp_S1_All, fp_S2_Not, fp_S3_Vol},

};


/*TODO:
 * 	1. add logo to the beginning of the boot-up
 * 	*/

void App_Init(App_Handle_t *handle){

	glcd_init();
	glcd_set_font_c(FC_Default_Font_5x8_AlphaNumber);

	Effect_List_Init();

	Event_Init(&handle->event, &handle->btn, &handle->enc, &handle->vol);

	//HAL_Delay(1000);


	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_ALL);
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1 );
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2 );
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3 );
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4 );

	//fp_S0_Reset(handle);
//	handle->vol.vol_src[VOL_A] = VOL_FROM_ADC;
//	handle->vol.vol_src[VOL_B] = VOL_FROM_ADC;
//	handle->vol.vol_src[VOL_C] = VOL_FROM_ADC;
//	handle->vol.vol_src[VOL_D] = VOL_FROM_ADC;
	handle->state = STATE_1;
	handle->tmp_efx = NULL;
	//handle->cur_efx = Effect_List_Get_Element(Enc_Event_Get_val);


	handle->btn.press_time = BTN_LONG_PRESS_TIME;
	handle->cur_efx = Effect_List_Get_EFX_Element(Enc_Event_Get_val);

	HAL_TIM_Base_Start_IT(&htim14);

}


Fsm_Fp_t func = NULL;

void APP_Exec(App_Handle_t *handle){


	func = fsm_fp_box[handle->event.type][handle->state];
	handle->event.has_e = 0;
	handle->event.type = Event_NOT;

	if(func)
		func(handle);


}
