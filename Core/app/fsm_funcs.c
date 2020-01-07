/*
 * fsm_funcs.c
 *
 *  Created on: Dec 24, 2019
 *      Author: sam
 */

#include "app.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////
char tmp_str[20];

#define VOL_X		8
#define VOL_Y		30
#define VOL_DIFF	8
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////

void fp_S1_All(App_Handle_t *handle){
	handle->cur_efx = Effect_List_Get_Element(Enc_Event_Get_val);
	glcd_clear_buffer();
	Helper_Draw_Thin_Frame;
	Helper_Print_EFX_Name(handle->cur_efx);
	Helper_Print_EFX_Number(handle->cur_efx);
	Helper_Print_EFX_ADC_Vol(handle->vol, VOL_A);
	Helper_Print_EFX_ADC_Vol(handle->vol, VOL_B);
	Helper_Print_EFX_ADC_Vol(handle->vol, VOL_C);
	Helper_Print_EFX_ADC_Vol(handle->vol, VOL_D);
	glcd_write();
	//HAL_Delay(200);

}

void fp_S2_Not(App_Handle_t *handle){}
void fp_S2_Btn(App_Handle_t *handle){}
void fp_S2_Enc(App_Handle_t *handle){}
void fp_S2_Vol(App_Handle_t *handle){}

void fp_S3_Not(App_Handle_t *handle){}
void fp_S3_Btn(App_Handle_t *handle){}
void fp_S3_Enc(App_Handle_t *handle){}
void fp_S3_Vol(App_Handle_t *handle){}










////////////////////////////////////////////////////////////////////////////////////////////






