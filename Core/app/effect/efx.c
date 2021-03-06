/*
 * efx.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#include "efx.h"

#include "eep.h"
#include "enc.h"
#include "eep_helper.h"
#include "app.h"


#define EFX_LIST_SIZE	99
#define EFX_FACT_SIZE	16

Efx_Memory_t mems[EFX_LIST_SIZE] = {0};
static uint8_t efx_cnt = 0;


/*
 * this is the init of the module, possible?
 * those efx_pushe_list func's must be call before list_make_iterator call
 * make the 16 first effect chain list
 * */
void Effect_List_Init(void){

	Efx_Preset_t pst = EFX_PRST_1;
	uint32_t vols[VOL_MAX] = {0};

	for (uint8_t main_num = 1; main_num < EFX_FACT_SIZE + 1; ++main_num) {

		if (Effect_List_Add_Element(main_num, pst, vols) == 0)
			break;

		if(pst == EFX_PRST_16)
			pst = EFX_PRST_1;
		else
			pst++;
	}

	//Helper_Erase_EEP();
	Helper_Load_Efx_EEP();
	//uint32_t num = ;
	Enc_Event_Set_val(Helper_Load_Last_Efx_EEP());
	//Enc_Event_Set_val(1);
}

uint8_t Effect_List_Add_Element(uint8_t main_num, Efx_Preset_t pst, uint32_t *vols){

	if(efx_cnt >= EFX_LIST_SIZE)
		return 0;

	Efx_Memory_t *mem = &mems[efx_cnt];
	Enc_Event_Set_Span(efx_cnt);
	efx_cnt++;

	mem->main_num = main_num;
	mem->pst_num = pst;
	mem->vols[VOL_A] = vols[VOL_A] >> 4;
	mem->vols[VOL_B] = vols[VOL_B] >> 4;
	mem->vols[VOL_C] = vols[VOL_C] >> 4;
	mem->vols[VOL_D] = vols[VOL_D] >> 4;

	return 1;
}

void Effect_List_Modify_Vol_Element(Efx_t *cur_efx, Vol_t vol){
	/*
	 * adc was 12 bit so shift 4bit to the right to save just 8byte on it
	 * */
	Efx_Memory_t* mem = &mems[cur_efx->mem.main_num-1];

	if(vol.vol_src[VOL_A] == VOL_FROM_ADC){
		mem->vols[VOL_A] = vol.vol_raw[VOL_A] >> 4;
		cur_efx->mem.vols[VOL_A] = vol.vol_raw[VOL_A] >> 4;
	}

	if(vol.vol_src[VOL_B] == VOL_FROM_ADC){
		mem->vols[VOL_B] = vol.vol_raw[VOL_B] >> 4;
		cur_efx->mem.vols[VOL_B] = vol.vol_raw[VOL_B] >> 4;
	}

	if(vol.vol_src[VOL_C] == VOL_FROM_ADC){
		mem->vols[VOL_C] = vol.vol_raw[VOL_C] >> 4;
		cur_efx->mem.vols[VOL_C] = vol.vol_raw[VOL_C] >> 4;
	}

	if(vol.vol_src[VOL_D] == VOL_FROM_ADC){
		mem->vols[VOL_D] = vol.vol_raw[VOL_D] >> 4;
		cur_efx->mem.vols[VOL_D] = vol.vol_raw[VOL_D] >> 4;
	}
}

uint8_t Effect_List_Get_EFX_Element(Efx_t* efx, uint8_t number){

	Efx_Memory_t* mem;

	if (number > efx_cnt)
		return 0;

	mem = &mems[number];

	efx->mem.main_num = mem->main_num;
	efx->mem.pst_num = mem->pst_num;
	efx->mem.vols[VOL_A] = mem->vols[VOL_A];
	efx->mem.vols[VOL_B] = mem->vols[VOL_B];
	efx->mem.vols[VOL_C] = mem->vols[VOL_C];
	efx->mem.vols[VOL_D] = mem->vols[VOL_D];

	efx->base = Efx_Get_Base(efx->mem.pst_num);

//	if(efx->mem.main_num > 16)
//		efx->pmode = EFX_USER_PRESET_MODE;
//	else
//		efx->pmode = EFX_FACT_PRESET_MODE;

	return 1;
}

//size_t Effect_List_Get_List_Size(void){
//	return efx_cnt;
//}

