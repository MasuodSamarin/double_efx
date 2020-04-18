/*
 * fsm_funcs.c
 *
 *  Created on: Dec 24, 2019
 *      Author: sam
 */

#include "app.h"

#include "eep_helper.h"
#include "iwdg.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * HELPER FUNCTION USED IN FSM
 * */
//char tmp_str[10];

//#define VOL_X		8
//#define VOL_Y		31
//#define VOL_DIFF	8
#define VOL_W		53
#define VOL_H		3



uint8_t VOL_Xs[] = {6, 6, 69, 69};
uint8_t VOL_Ys[] = {45, 52, 45, 52};

//#define VOL_DIFF	8
//#define VOL_W		50
//#define VOL_H		3






#define FRAME_X		0
#define FRAME_Y		0
#define FRAME_TX	2
#define FRAME_TY	2
#define FRAME_W		128
#define FRAME_H		64
#define FRAME_COLOR	BLACK

#define N1_X		4
#define N1_Y		5
#define N2_X		4
#define N2_Y		20

#define NUM_X		75
#define NUM_Y		10

#define Helper_Draw_Thin_Frame	glcd_draw_rect(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, FRAME_COLOR)
#define Helper_Draw_Thick_Frame	glcd_draw_rect_thick(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, FRAME_TX, FRAME_TY, FRAME_COLOR)

void Helper_Print_EFX_Name(Efx_t *efx){
	const char *n1 = efx->base->n1;
	const char *n2 = efx->base->n2;

	//print the name of efx
	glcd_set_font_c(FONT_EFX_NAME);
	glcd_draw_string_P(N1_X, N1_Y, &n1[0]);
	glcd_draw_string_P(N2_X, N2_Y, &n2[0]);

}

void Helper_Print_EFX_Number(Efx_t *efx){
	char tmp_str[10];
	int number = efx->mem.main_num;

	//print the number of efx and inert it
	glcd_set_font_c(FONT_EFX_NUMBER);
	sprintf(tmp_str, "%.2d", number);

	glcd_draw_string(NUM_X, NUM_Y, tmp_str);
	//glcd_invert_area(75, 31, 40, 26);


}

//void Helper_Print_Message(void){
//	const char *msg = "Watch DOG";
//
//	//print the name of efx
//	glcd_set_font_c(FC_Tahoma11x13_AlphaNumber);
//	glcd_draw_string_P(7, 7, &msg[0]);
//	glcd_write();
//}
//void Helper_Print_EFX_Mem_Vol(Efx_t *efx, Vol_Name_t name){
//
//	glcd_bar_graph_volume_shape(VOL_X, (VOL_Y + (name*VOL_DIFF)), VOL_W, VOL_H, efx->mem.vols[name]);
//}
//
//void Helper_Print_EFX_ADC_Vol(Vol_t vol, Vol_Name_t name){
//
//	glcd_bar_graph_volume_shape(VOL_X, (VOL_Y + (name*VOL_DIFF)), VOL_W, VOL_H, vol.vol_raw[name]);
//}

void Helper_Print_EFX_Vol(uint32_t Vol_Value, Vol_Name_t name){

	glcd_bar_graph_volume_shape(VOL_Xs[(int)name], VOL_Ys[(int)name] , VOL_W, VOL_H, (uint8_t)(Vol_Value));

}

//uint32_t Helper_Get_Vol_Value(App_Handle_t *handle, Vol_Name_t name){
//
//	//READ VOLUMES VALUES FROM SAVED MEMORY
//	if(handle->vol.vol_src[name]  == VOL_FROM_MEM)
//		return (uint32_t)((handle->cur_efx->mem.vols[name]));
//
//	//READ VOLUMES VALUES FROM ADC ONLINE
//	else
//		return (uint32_t)((handle->vol.vol_raw[name])>>4);
//
//}

//HANDLE VOLUMES ON FACTORY PRESET MODE
//void Helper_Fp_S2_Not_F0(App_Handle_t *handle){
////	//hold temp volume val
////	uint32_t vol_val;
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_1){
////		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_A])>>4);
////		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
////		Helper_Print_EFX_Vol(vol_val, VOL_A);
////	}
////
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_2){
////		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_B])>>4);
////		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_2, vol_val);
////		Helper_Print_EFX_Vol(vol_val, VOL_B);
////	}
////
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_3){
////		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_C])>>4);
////		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_3, vol_val);
////		Helper_Print_EFX_Vol(vol_val, VOL_C);
////	}
////
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_4){
////		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_D])>>4);
////		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_4, vol_val);
////		Helper_Print_EFX_Vol(vol_val, VOL_D);
////	}
////	glcd_write();
//}

//HANDLE VOLUMES ON USER PRESET MODE
//void Helper_Fp_S2_Not_F1(App_Handle_t *handle){
//	//hold temp volume val
//	uint32_t vol_val;
//	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_1){
//		if(handle->vol.vol_src[VOL_A]  == VOL_FROM_MEM)
//			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_A]));
//		else
//			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_A])>>4);
//		//vol_val = Helper_Get_Vol_Value(handle, VOL_A);
//
//		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
//		Helper_Print_EFX_Vol(vol_val, VOL_A);
//	}
//
//
//	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_2){
//		if(handle->vol.vol_src[VOL_B]  == VOL_FROM_MEM)
//			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_B]));
//		else
//			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_B])>>4);
//		//vol_val = Helper_Get_Vol_Value(handle, VOL_B);
//		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_2, vol_val);
//		Helper_Print_EFX_Vol(vol_val, VOL_B);
//	}
//
//	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_3){
//		if(handle->vol.vol_src[VOL_C]  == VOL_FROM_MEM)
//			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_C]));
//		else
//			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_C])>>4);
//		//vol_val = Helper_Get_Vol_Value(handle, VOL_C);
//		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_3, vol_val);
//		Helper_Print_EFX_Vol(vol_val, VOL_C);
//	}
//
//	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_4){
//		if(handle->vol.vol_src[VOL_D]  == VOL_FROM_MEM)
//			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_D]));
//		else
//			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_D])>>4);
//		//vol_val = Helper_Get_Vol_Value(handle, VOL_D);
//		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_4, vol_val);
//		Helper_Print_EFX_Vol(vol_val, VOL_D);
//	}
//	glcd_write();
//
//}
//
//


//#define MAX_EFX_USER_LIST_SIZE	50
//#define MAX_EFX_FACTORY_LIST_SIZE	16

//HANDLE SAVE EFX ON LINK-LIST AND EEP'S
//void Helper_Fp_S2_Btn_F0(App_Handle_t *handle){
//	//check efx number not > from link-list size
//	//theres no space to make new efx
////	if(Effect_List_Get_List_Size() >= (MAX_EFX_USER_LIST_SIZE + MAX_EFX_FACTORY_LIST_SIZE)){
////
////		//#TODO:
////		//show a warning message on the screen because we dont have any memory for new efx
////		// nothing change t all.
////		return;
////	}
//
//	/*
//	 * TODO:
//	 * 		1. show message on the lcd for SAVING EFX
//	 *		2. save actual efx to the EEP
//	 * 	*/
//	//Enc_Event_Set_Span(Enc_Event_Get_Span + 1);
//	Effect_List_Add_Element(Enc_Event_Get_Span+2, handle->cur_efx->mem.pst_num, handle->vol.vol_raw);
//	Enc_Event_Set_val(&handle->enc, Enc_Event_Get_Span);
//	Effect_List_Get_EFX_Element(handle->cur_efx, Enc_Event_Get_val);
//	handle->state = STATE_1;
//
//
//	// show SAVE message on screen
//	if(Helper_Svae_Efx_EEP(handle, handle->cur_efx->mem.main_num) == 1){
//		glcd_clear_buffer();
//		Helper_Draw_Thin_Frame;
//		glcd_set_font_c(FC_Tekton_Pro_Ext27x28_AlphaNumber);
//		glcd_draw_string(23, 25, "SAVE");
//	}else{
//		glcd_clear_buffer();
//		Helper_Draw_Thin_Frame;
//		glcd_set_font_c(FC_Tekton_Pro_Ext27x28_AlphaNumber);
//		glcd_draw_string(23, 25, "ERROR");
//	}
//
//	glcd_write();
//	HAL_Delay(1000);
//
//}
//
////HANDLE UPDATE EFX ON LINK-LIST AND EEP'S
//void Helper_Fp_S2_Btn_F1(App_Handle_t *handle){
//	/*
//	 * TODO:
//	 * 		1. show message on the lcd for MODIFY/UPDATE current EFX
//	 * 		2. update actual EFX on EEp
//	 *
//	 * */
//	Effect_List_Modify_Vol_Element(handle->cur_efx, handle->vol);
//	handle->state = STATE_1;
//
//	/*
//	 * show update message on screen*
//	*/
//	if(Helper_Svae_Efx_EEP(handle, handle->cur_efx->mem.main_num) == 1){
//		glcd_clear_buffer();
//		Helper_Draw_Thin_Frame;
//		glcd_set_font_c(FC_Tekton_Pro_Ext27x28_AlphaNumber);
//		glcd_draw_string(3, 25, "UPDATE");
//	}else{
//		glcd_clear_buffer();
//		Helper_Draw_Thin_Frame;
//		glcd_set_font_c(FC_Tekton_Pro_Ext27x28_AlphaNumber);
//		glcd_draw_string(23, 25, "ERROR");
//	}
//
//
//
//	glcd_write();
//	HAL_Delay(1000);
//
//
//}



//////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * ACTUAL FSM FUNCTION
 * ALL OF THE GAME
 * */


/*
 * Reset state:
 * 	1. INIT handle ADT
 * 	2, load vital values from EEP
 * 	3, make link-list from EEP data chain
 * 	4, set handle->cur_efx to the last enabled effect
 * 	TODO:
 * 		there's some development
 * */
//void fp_S0_Reset(App_Handle_t *handle){
//
//	/*TODO:
//	 * 	it's not finished yet.
//	 * */
//
////	handle->state = STATE_1;
////	handle->tmp_efx = NULL;
////	handle->cur_efx = Effect_List_Get_Element(Enc_Event_Get_val);
//}

/*
 * State 1: All Events
 * 	1. important parameter is handle->cur_efx
 * 	2. set HC595 shift register values
 * 	3. set PWM values
 * 	4. refresh LCD
 * 		A. effect name
 * 		B, effect number
 * 		C, effect volumes value like horizontal bar with small pin
 * 	5. button push time = Long push time
 * 	6. goto straight STATE 2
 * 	TODO:
 * 		there's some development
 * */
void fp_S1_All(App_Handle_t *handle){

	//set the most important field of handle --CUR_EFX--
	Effect_List_Get_EFX_Element(handle->cur_efx, Enc_Event_Get_val);
	//2. set HC595 shift register values

	glcd_clear_buffer();
	Helper_Draw_Thin_Frame;
	Helper_Print_EFX_Name(handle->cur_efx);
	Helper_Print_EFX_Number(handle->cur_efx);

	//ON USER MODE
	if(handle->cur_efx->mem.main_num > 16){
		Vol_Event_Reset_Vols(&(handle->vol));

		handle->vol.vol_src[VOL_A] = VOL_FROM_MEM;
		handle->vol.vol_src[VOL_B] = VOL_FROM_MEM;
		handle->vol.vol_src[VOL_C] = VOL_FROM_MEM;
		handle->vol.vol_src[VOL_D] = VOL_FROM_MEM;
	}
	else{
		handle->vol.vol_src[VOL_A] = VOL_FROM_ADC;
		handle->vol.vol_src[VOL_B] = VOL_FROM_ADC;
		handle->vol.vol_src[VOL_C] = VOL_FROM_ADC;
		handle->vol.vol_src[VOL_D] = VOL_FROM_ADC;
	}

	/*
	 * set FV1 effect
	 * we clear the 4th bit off and then on
	 * */
	HC595_SendByte(0x00);
	HAL_Delay(1);
	HC595_SendByte((handle->cur_efx->base->code) | 0x08);

	handle->state = STATE_2;
	handle->btn.press_time = BTN_LONG_PRESS_TIME;
}




/*
 * State 2:	Not Events
 * 	1. Is it FACTORY-MODE effects?
 * 		yes:
 * 			1. all volumes refresh it's value. reading their value's from ADC
 * 			2. update PWM's
 * 			3. update LCD. volume's view
 * 		no:
 * 			1. if any volume changes its default value, do PWM and LCD update accordingly
 * 	2. note that a desire volume must been in effect group volumes
 * */
void fp_S2_Not(App_Handle_t *handle){
	//hold temp volume val
	uint32_t vol_val;
	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_1){
		if(handle->vol.vol_src[VOL_A]  == VOL_FROM_MEM)
			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_A]));
		else
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_A])>>4);
		//vol_val = Helper_Get_Vol_Value(handle, VOL_A);

		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(vol_val, VOL_A);
	}


	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_2){
		if(handle->vol.vol_src[VOL_B]  == VOL_FROM_MEM)
			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_B]));
		else
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_B])>>4);
		//vol_val = Helper_Get_Vol_Value(handle, VOL_B);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_2, vol_val);
		Helper_Print_EFX_Vol(vol_val, VOL_B);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_3){
		if(handle->vol.vol_src[VOL_C]  == VOL_FROM_MEM)
			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_C]));
		else
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_C])>>4);
		//vol_val = 250;
		//vol_val = Helper_Get_Vol_Value(handle, VOL_C);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_3, vol_val);
		Helper_Print_EFX_Vol(vol_val, VOL_C);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_4){
		if(handle->vol.vol_src[VOL_D]  == VOL_FROM_MEM)
			vol_val = (uint32_t)((handle->cur_efx->mem.vols[VOL_D]));
		else
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_D])>>4);
		//vol_val = Helper_Get_Vol_Value(handle, VOL_D);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_4, vol_val);
		Helper_Print_EFX_Vol(vol_val, VOL_D);
	}
	glcd_write();

}

/*
 * State 2: Button Press Event
 * 	1. Is it FACTORY-MODE effects?
 * 		yes:
 * 			1. save the new effect on tail of link-list
 * 		no:
 * 			1. update volume's value to the already exist effect
 * 	2. goto the actual effect
 * 	3. update the EEP value
 * 	4. goto the STATE 1
 * 	#TODO:
 * 		complete EEP section
 * */
void fp_S2_Btn(App_Handle_t *handle){

	//	Fsm_Fp_t func = NULL;

	if(handle->cur_efx->mem.main_num <= 16)

	{
		//check efx number not > from link-list size
		//theres no space to make new efx
		//	if(Effect_List_Get_List_Size() >= (MAX_EFX_USER_LIST_SIZE + MAX_EFX_FACTORY_LIST_SIZE)){
		//
		//		//#TODO:
		//		//show a warning message on the screen because we dont have any memory for new efx
		//		// nothing change t all.
		//		return;
		//	}

		/*
		 * TODO:
		 * 		1. show message on the lcd for SAVING EFX
		 *		2. save actual efx to the EEP
		 * 	*/
		//Enc_Event_Set_Span(Enc_Event_Get_Span + 1);
		Effect_List_Add_Element(Enc_Event_Get_Span+2, handle->cur_efx->mem.pst_num, handle->vol.vol_raw);
		Enc_Event_Set_val( Enc_Event_Get_Span);
		Effect_List_Get_EFX_Element(handle->cur_efx, Enc_Event_Get_val);
		handle->state = STATE_1;


		// show SAVE message on screen
		if(Helper_Svae_Efx_EEP(handle, handle->cur_efx->mem.main_num) == 1){
			glcd_clear_buffer();
			Helper_Draw_Thin_Frame;
			glcd_set_font_c(FONT_EFX_MSG);
			glcd_draw_string(23, 25, "SAVE");
		}else{
			glcd_clear_buffer();
			Helper_Draw_Thin_Frame;
			glcd_set_font_c(FONT_EFX_MSG);
			glcd_draw_string(23, 25, "ERROR");
		}

		glcd_write();
		HAL_Delay(1000);
	}
	else
	{
		/*
		 * TODO:
		 * 		1. show message on the lcd for MODIFY/UPDATE current EFX
		 * 		2. update actual EFX on EEp
		 *
		 * */
		Effect_List_Modify_Vol_Element(handle->cur_efx, handle->vol);
		handle->state = STATE_1;

		/*
		 * show update message on screen*
		 */
		if(Helper_Svae_Efx_EEP(handle, handle->cur_efx->mem.main_num) == 1){
			glcd_clear_buffer();
			Helper_Draw_Thin_Frame;
			glcd_set_font_c(FONT_EFX_MSG);
			glcd_draw_string(3, 25, "UPDATE");
		}else{
			glcd_clear_buffer();
			Helper_Draw_Thin_Frame;
			glcd_set_font_c(FONT_EFX_MSG);
			glcd_draw_string(23, 25, "ERROR");
		}



		glcd_write();
		HAL_Delay(1000);


	}
	//	func(handle);
	//glcd_write();

	//	#TODO * 	2. goto the effect
	//	 * 	3. update the EEP value


}

/*
 * State 2: Encoder Changes Event
 * 	1. set handle->tmp_efx to next or previous effect on the link-list
 * 	2. button push time = Normal push time
 * 	3. goto the State 3
 * 	4. reset blink and TICK-timer
 * */
void fp_S2_Enc(App_Handle_t *handle){

	Effect_List_Get_EFX_Element(handle->tmp_efx, Enc_Event_Get_val);;
	handle->btn.press_time = BTN_NORMAL_PRESS_TIME;
	handle->state = STATE_3;
	handle->tick_timer = HAL_GetTick();
	handle->blink_timer = 0;
}

/*
 * State 2: Volume Changes Event
 * 	1. is volume belong to the Volume-Group?
 * 		yes:
 * 			1. mark that volume to online or VOL_FROM_ADC
 * 		no:
 * 			1. there's nothing to do
 * 	note:
 * 		probably vol_handle interrupt take care of it
 * */
//void fp_S2_Vol(App_Handle_t *handle){
//
//	/**/
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_1){
////		handle->vol.vol_src[VOL_A] = VOL_FROM_ADC;
////	}
////
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_2){
////		handle->vol.vol_src[VOL_B] = VOL_FROM_ADC;
////	}
////
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_3){
////		handle->vol.vol_src[VOL_C] = VOL_FROM_ADC;
////	}
////
////	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_4){
////		handle->vol.vol_src[VOL_D] = VOL_FROM_ADC;
////	}
//
//}




/*
 * State 3:	Not Events
 * 	1. important parameter is handle->tmp_efx
 * 	2. show TMP effect on the LCD.
 * 		A)name	B)Number	C)volume group
 * 	3. the B section blinks every 100ms
 * 	4. after some time-out:
 * 		A) change Encoder TIM value to handle->cur_efx
 * 		B) goto State 1
 * */
void fp_S3_Not(App_Handle_t *handle){
	uint32_t vol_val;

	glcd_clear_buffer();
	Helper_Draw_Thin_Frame;
	Helper_Print_EFX_Name(handle->tmp_efx);

	/* start point show number*/
	if(handle->blink_timer < 15){
		Helper_Print_EFX_Number(handle->tmp_efx);
		handle->blink_timer = handle->blink_timer + 1;
	}
	/* repeat still show number*/
	else if(handle->blink_timer < 30){
		Helper_Print_EFX_Number(handle->tmp_efx);
		handle->blink_timer = handle->blink_timer + 1;
	}
	/* remove number*/
	else if(handle->blink_timer < 50){
		glcd_draw_rect_fill(79, 22, 40, 37, 0);
		handle->blink_timer = handle->blink_timer + 1;
	}
	/* reset loop goto repeat section*/
	else{
		handle->blink_timer = 15;
	}

	/*show volumes on LCD*/
	if ((handle->tmp_efx->base->vgrp) & VOL_GROUP_1){
		if(handle->tmp_efx->mem.main_num <= 16)
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_A])>>4);
		else
			vol_val = (uint32_t)((handle->tmp_efx->mem.vols[VOL_A]));

		Helper_Print_EFX_Vol(vol_val, VOL_A);
	}

	if ((handle->tmp_efx->base->vgrp) & VOL_GROUP_2){
		if(handle->tmp_efx->mem.main_num <= 16)
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_B])>>4);
		else
			vol_val = (uint32_t)((handle->tmp_efx->mem.vols[VOL_B]));

		Helper_Print_EFX_Vol(vol_val, VOL_B);
	}

	if ((handle->tmp_efx->base->vgrp) & VOL_GROUP_3){
		if(handle->tmp_efx->mem.main_num <= 16)
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_C])>>4);
		else
			vol_val = (uint32_t)((handle->tmp_efx->mem.vols[VOL_C]));

		Helper_Print_EFX_Vol(vol_val, VOL_C);
	}

	if ((handle->tmp_efx->base->vgrp) & VOL_GROUP_4){
		if(handle->tmp_efx->mem.main_num <= 16)
			vol_val = (uint32_t)((handle->vol.vol_raw[VOL_D])>>4);
		else
			vol_val = (uint32_t)((handle->tmp_efx->mem.vols[VOL_D]));

		Helper_Print_EFX_Vol(vol_val, VOL_D);
	}

	glcd_write();

	/* this is time-out section*/
	if(HAL_GetTick() - handle->tick_timer > 5000){
		Enc_Event_Set_val(handle->cur_efx->mem.main_num-1);
		handle->state = STATE_1;
		handle->btn.press_time = BTN_LONG_PRESS_TIME;

	}
}

/*
 * State 3: Button Press Event
 * 	1. set handle->cur_efx = handle->tmp_efx
 * 	2. goto State 1
 * */
void fp_S3_Btn(App_Handle_t *handle){

	Enc_Event_Set_val( handle->tmp_efx->mem.main_num-1);
	handle->state = STATE_1;
	//handle->cur_efx = handle->tmp_efx;


}

/*
 * State 3: Encoder Changes Event
 * 	1. set handle->tmp_efx to next or previous effect on the link-list
 * 	2. set blink timer
 * */
void fp_S3_Enc(App_Handle_t *handle){

	Effect_List_Get_EFX_Element(handle->tmp_efx, Enc_Event_Get_val);;
	handle->tick_timer = HAL_GetTick();
	handle->blink_timer = 0;
}

/*
 * State 3: Volume Changes Event
 * 	1. change Encoder tim value to handle->cur_efx
 * 	2. goto State 1
 * */
//void fp_S3_Vol(App_Handle_t *handle){
////
////	Enc_Event_Set_val(&handle->enc, (uint8_t)handle->cur_efx->mem.main_num);
////	handle->state = STATE_1;
//}

#define X_YES		20
#define Y_YES		12
#define X_YES_BOX	X_YES-3
#define Y_YES_BOX	Y_YES-2
#define W_YES_BOX	29
#define H_YES_BOX	15
#define X_NO		30
#define Y_NO		20
#define X_NO_BOX	X_NO-5
#define Y_NO_BOX	Y_MARK
#define W_NO_BOX	25
#define H_NO_BOX	15
#define X_MARK		30
#define Y_MARK		30

void Helper_Service_Menu(void){

	volatile uint8_t answer, value, prevalue;
	const char *yes = "YES";
	const char *no = "NO";
	const char *mark = "<< --- >>";
	const char *quest = "RESET FACTORY?";
	const char *javab = "CLEAR EEPROM";
	//const char *menu = "RELEASE BTN PLZ";

	if ( HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_SET )
		return;
	HAL_Delay(1000);
	if ( HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_SET )
		return;

	answer = 1;
	prevalue = 3;
	Enc_Event_Set_Span(1);

	glcd_set_font_c(FONT_EFX_MSG);
	glcd_clear();
	Helper_Draw_Thin_Frame;
	glcd_draw_string_P(12, 12, &quest[0]);
	glcd_write();

	while(HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET){
	  	/* IF WATCH-DOG TURN ON SO, ---> RESET THE DEVICE */
	    if(HAL_IWDG_Refresh(&hiwdg) != HAL_OK)
	    	Error_Handler();
	}

	while(answer == 1){
		value = Enc_Event_Get_val;

		if(value != prevalue)
		{
			prevalue = value;

			glcd_clear();
			Helper_Draw_Thin_Frame;
			glcd_draw_string_P(12, 12, &quest[0]);

			if(value == 1){
				glcd_draw_string_P(X_YES, Y_YES, &yes[0]);
				glcd_draw_string_P(X_NO, Y_NO, &no[0]);
				glcd_draw_string_P(X_MARK, Y_MARK, &mark[0]);
				glcd_invert_area(X_YES_BOX, Y_YES_BOX, W_YES_BOX, H_YES_BOX);
			}
			else if(value == 0){
				glcd_draw_string_P(X_YES, Y_YES, &yes[0]);
				glcd_draw_string_P(X_NO, Y_NO, &no[0]);
				glcd_draw_string_P(X_MARK, Y_MARK, &mark[0]);
				glcd_invert_area(X_NO_BOX, Y_YES_BOX, W_NO_BOX, H_NO_BOX);
			}

			glcd_write();

		}

		if ( HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET ){
			HAL_Delay(100);
			if ( HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET )
				answer = 0;
		}
	  	/* IF WATCH-DOG TURN ON SO, ---> RESET THE DEVICE */
	    if(HAL_IWDG_Refresh(&hiwdg) != HAL_OK)
	    	Error_Handler();

	}

	if(value == 1){
		glcd_clear();

		glcd_draw_string_P(7, 7, &javab[0]);
		glcd_write();

		Helper_Erase_EEP();

	}
	while(HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET){
	  	/* IF WATCH-DOG TURN ON SO, ---> RESET THE DEVICE */
	    if(HAL_IWDG_Refresh(&hiwdg) != HAL_OK)
	    	Error_Handler();
	}

}

void Helper_Security_Check(void){

	union uid_t{
		uint32_t uid_32[3];
		uint8_t	uid_8[12];
	}uid, uid_load;

	uint16_t addr_uid = 63 * 16 + 1;
	uint16_t addr_set = 63 * 16;
	uint8_t uid_set;

	uid.uid_32[0] = HAL_GetUIDw0();
	uid.uid_32[1] = HAL_GetUIDw1();
	uid.uid_32[2] = HAL_GetUIDw2();


	//	char tmp_str[10];
	// 	int number;
	//
	//  	//print the number of efx and inert it
	// 	glcd_set_font_c(FC_Tahoma11x13_AlphaNumber);
	//
	// 	sprintf(tmp_str, "%08x", uid.uid_32[2]);
	// 	glcd_draw_string(10, 5, tmp_str);
	//
	// 	sprintf(tmp_str, "%02X", uid.uid_8[8]);
	// 	glcd_draw_string(10, 20, tmp_str);
	// 	sprintf(tmp_str, "%02X", uid.uid_8[9]);
	// 	glcd_draw_string(50, 20, tmp_str);
	// 	sprintf(tmp_str, "%02X", uid.uid_8[10]);
	// 	glcd_draw_string(10, 40, tmp_str);
	// 	sprintf(tmp_str, "%02X", uid.uid_8[11]);
	// 	glcd_draw_string(50, 40, tmp_str);
	//
	// 	glcd_write();
	// 	while(1);

	glcd_set_font_c(FC_FONT1);

	//	for (int var = 0; var < 12; ++var) {
	//
	//		EEPROM24XX_Save(addr_uid+var, (void*)&uid.uid_8[var], sizeof(uint8_t));
	//
	//	}



	EEPROM24XX_Load(addr_set, (void*)&uid_set, sizeof(uid_set));

	if(uid_set == 0xFF)
	{
		for (int var = 0; var < 12; ++var) {

			EEPROM24XX_Load(addr_uid+var, (void*)&uid_load.uid_8[var], sizeof(uint8_t));

		}

		if( (uid.uid_32[0] != uid_load.uid_32[0]) || (uid.uid_32[1] != uid_load.uid_32[1]) || (uid.uid_32[2] != uid_load.uid_32[2]) ){

			glcd_draw_string(10, 5, "uid != uid_load");
			glcd_write();

			while(1);
		}
		//	 	glcd_draw_string(10, 5, "uid == uid_load");
		//	 	glcd_write();



	}
	else
	{
		for (int var = 0; var < 12; ++var) {

			EEPROM24XX_Save(addr_uid+var, (void*)&uid.uid_8[var], sizeof(uint8_t));

		}

		uid_set = 0xFF;
		EEPROM24XX_Save(addr_set, (void*)&uid_set, sizeof(uid_set));
		glcd_draw_string(10, 5, "Saving UID");
		glcd_write();
		while(1);


	}


	//			while(1);

	//	uid_set = 0xFF;
	//	EEPROM24XX_Save(addr_uid+3, (void*)&uid_set, sizeof(uint8_t));
}






