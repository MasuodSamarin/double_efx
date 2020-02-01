/*
 * fsm_funcs.c
 *
 *  Created on: Dec 24, 2019
 *      Author: sam
 */

#include "app.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * HELPER FUNCTION USED IN FSM
 * */
char tmp_str[20];

#define VOL_X		8
#define VOL_Y		27
#define VOL_DIFF	9
#define VOL_W		65
#define VOL_H		3

#define FRAME_X		0
#define FRAME_Y		0
#define FRAME_TX	2
#define FRAME_TY	2
#define FRAME_W		128
#define FRAME_H		64
#define FRAME_COLOR	BLACK

#define Helper_Draw_Thin_Frame	glcd_draw_rect(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, FRAME_COLOR)
#define Helper_Draw_Thick_Frame	glcd_draw_rect_thick(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, FRAME_TX, FRAME_TY, FRAME_COLOR)

static void Helper_Print_EFX_Name(Efx_t *efx){
 	const char *name = efx->base->name;

 	//print the name of efx
 	glcd_set_font_c(FC_Tahoma11x13_AlphaNumber);
 	glcd_draw_string_P(7, 7, &name[0]);

}

static void Helper_Print_EFX_Number(Efx_t *efx){
 	int number = efx->mem.main_num;

  	//print the number of efx and inert it
 	glcd_set_font_c(FC_Bebas_Neue18x36_Numbers);
 	sprintf(tmp_str, "%.2d", number);

 	glcd_draw_string(80, 23, tmp_str);
 	//glcd_invert_area(75, 31, 40, 26);


}

void Helper_Print_EFX_Mem_Vol(Efx_t *efx, Vol_Name_t name){

	glcd_bar_graph_volume_shape(VOL_X, (VOL_Y + (name*VOL_DIFF)), VOL_W, VOL_H, efx->mem.vols[name]);
}

void Helper_Print_EFX_ADC_Vol(Vol_t vol, Vol_Name_t name){

	glcd_bar_graph_volume_shape(VOL_X, (VOL_Y + (name*VOL_DIFF)), VOL_W, VOL_H, vol.vol_raw[name]);
}

void Helper_Print_EFX_Vol(uint32_t Vol_Value, Vol_Name_t name, ){

	glcd_bar_graph_volume_shape(VOL_X, (VOL_Y + (name*VOL_DIFF)), VOL_W, VOL_H, Vol_Value);

}

uint32_t Helper_Get_Vol_Value(App_Handle_t *handle, Vol_Name_t name){

	//READ VOLUMES VALUES FROM SAVED MEMORY
	if(handle->vol.vol_src[name]  == VOL_FROM_MEM){
		return (uint32_t)((handle->cur_efx->mem.vols[name]) << 4);
	}
	//READ VOLUMES VALUES FROM ADC ONLINE
	else
		return (uint32_t)((handle->vol.vol_raw[name]) << 4);

}

//HANDLE VOLUMES ON FACTORY PRESET MODE
void Helper_Fp_S2_Not_F0(App_Handle_t *handle){
	//hold temp volume val
	uint32_t vol_val;
	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_1){
		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_A]) << 4 );
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_A,vol_val);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_2){
		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_B]) << 4 );
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_B,vol_val);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_3){
		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_C]) << 4 );
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_C,vol_val);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_4){
		vol_val = (uint32_t)((handle->vol.vol_raw[VOL_D]) << 4 );
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_D,vol_val);
	}

	glcd_write();
}

//HANDLE VOLUMES ON USER PRESET MODE
void Helper_Fp_S2_Not_F1(App_Handle_t *handle){
	//hold temp volume val
	uint32_t vol_val;
	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_1){
		vol_val = Helper_Get_Vol_Value(handle, VOL_A);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_A,vol_val);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_2){
		vol_val = Helper_Get_Vol_Value(handle, VOL_B);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_B,vol_val);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_3){
		vol_val = Helper_Get_Vol_Value(handle, VOL_C);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_C,vol_val);
	}

	if ((handle->cur_efx->base->vgrp) & VOL_GROUP_4){
		vol_val = Helper_Get_Vol_Value(handle, VOL_D);
		__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, vol_val);
		Helper_Print_EFX_Vol(VOL_D,vol_val);
	}
}

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
void fp_S0_Reset(App_Handle_t *handle){

	/*TODO:
	 * 	it's not finished yet.
	 * */

//	handle->state = STATE_1;
//	handle->tmp_efx = NULL;
//	handle->cur_efx = Effect_List_Get_Element(Enc_Event_Get_val);
}

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
	//2. set HC595 shift register values
	HC595_SendByte(handle->cur_efx->base->code);

	glcd_clear_buffer();
	Helper_Draw_Thin_Frame;
	Helper_Print_EFX_Name(handle->cur_efx);
	Helper_Print_EFX_Number(handle->cur_efx);

	//ON USER MODE
	if(handle->cur_efx->pmode == EFX_USER_PRESET_MODE){
		handle->vol.vol_src[VOL_A] = VOL_FROM_MEM;
		handle->vol.vol_src[VOL_B] = VOL_FROM_MEM;
		handle->vol.vol_src[VOL_C] = VOL_FROM_MEM;
		handle->vol.vol_src[VOL_D] = VOL_FROM_MEM;
	}


	//ON USER MODE
	Helper_Fp_S2_Not_F1(handle);
//	if(handle->cur_efx->pmode == EFX_USER_PRESET_MODE){
//		if ( (handle->cur_efx->base->vgrp) & VOL_GROUP_1){
//			Helper_Print_EFX_Mem_Vol(handle->cur_efx, VOL_A);
//			__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, (handle->cur_efx->mem.vols[VOL_A]) << 4 );
//		}
//		if ( (handle->cur_efx->base->vgrp) & VOL_GROUP_2){
//			Helper_Print_EFX_Mem_Vol(handle->cur_efx, VOL_B);
//			__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, (handle->cur_efx->mem.vols[VOL_B]) << 4 );
//		}
//		if ( (handle->cur_efx->base->vgrp) & VOL_GROUP_3){
//			Helper_Print_EFX_Mem_Vol(handle->cur_efx, VOL_C);
//			__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, (handle->cur_efx->mem.vols[VOL_C]) << 4 );
//		}
//		if ( (handle->cur_efx->base->vgrp) & VOL_GROUP_4){
//			Helper_Print_EFX_Mem_Vol(handle->cur_efx, VOL_D);
//			__HAL_TIM_SET_COMPARE( &htim3, TIM_CHANNEL_1, (handle->cur_efx->mem.vols[VOL_D]) << 4 );
//		}
//
//	}

	handle->state = STATE_2;
	handle->btn.press_time = BTN_LONG_PRESS_TIME;


	glcd_write();


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

	Fsm_Fp_t func = NULL;

	if(handle->cur_efx->pmode == EFX_FACT_PRESET_MODE)
		func =  Helper_Fp_S2_Not_F0;
	else
		func =  Helper_Fp_S2_Not_F1;
	func(handle);
	glcd_write();
}




/*
 * State 2: Button Press Event
 * 	1. Is it FACTORY-MODE effects?
 * 		yes:
 * 			1. save the new effect on tail of link-list
 * 		no:
 * 			1. update volume's value to the already exist effect
 * 	2. goto the effect
 * 	3. update the EEP value
 * 	4. goto the STATE 1
 * */
void fp_S2_Btn(App_Handle_t *handle){}




/*
 * State 2: Encoder Changes Event
 * 	1. set handle->tmp_efx to next or previous effect on the link-list
 * 	2. button push time = Normal push time
 * 	3. goto the State 3
 * */
void fp_S2_Enc(App_Handle_t *handle){}




/*
 * State 2: Volume Changes Event
 * 	1. is volume belong to the Volume-Group?
 * 		yes:
 * 			1. mark that volume to online or free vol
 * 		no:
 * 			1. there's nothing to do
 * */
void fp_S2_Vol(App_Handle_t *handle){}



/*
 * State 3:	Not Events
 * 	1. important parameter is handle->tmp_efx
 * 	2. show tmp effect on the LCD.
 * 		A)name	B)Number	C)volume group
 * 	3. the B section blinks every 100ms
 * 	4. after some time-out:
 * 		A) change Encoder tim value to handle->cur_efx
 * 		B) goto State 2
 * */
void fp_S3_Not(App_Handle_t *handle){}




/*
 * State 3: Button Press Event
 * 	1. set handle->cur_efx =  handle->tmp_efx
 * 	2. goto State 1
 * */
void fp_S3_Btn(App_Handle_t *handle){}




/*
 * State 3: Encoder Changes Event
 * 	1. set handle->tmp_efx to next or previous effect on the link-list
 * 	2. set blink timer
 * */
void fp_S3_Enc(App_Handle_t *handle){}




/*
 * State 3: Volume Changes Event
 * 	1. change Encoder tim value to handle->cur_efx
 * 	2. goto State 2
 * */
void fp_S3_Vol(App_Handle_t *handle){}










////////////////////////////////////////////////////////////////////////////////////////////






