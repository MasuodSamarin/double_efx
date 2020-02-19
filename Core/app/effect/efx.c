/*
 * efx.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#include "efx.h"
#include "link_list.h"
#include "eep.h"
#include "enc.h"
#include "eep_helper.h"
#include "app.h"



#define EFX_LIST_SIZE	99

list_t efx_list;
//node_t nodes[EFX_LIST_SIZE] = {0};
Efx_Memory_t mems[EFX_LIST_SIZE] = {0};
static uint8_t efx_cnt = 0;


/*
 * this is the init of the module, possible?
 * those efx_pushe_list func's must be call before list_make_iterator call
 * make the 16 first effect chain list
 * */
void Effect_List_Init(void){
	efx_list = list_create_static();
	uint8_t span = 0;
	Efx_Preset_t pst = EFX_PRST_1;

	uint32_t vols[VOL_MAX] = {0};
	for (uint8_t cnt = 0; cnt < EFX_LIST_SIZE; ++cnt) {
		//Efx_t *efx = Effect_Creare_Node((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);
		//list_push_back(efx_list, (void*)efx);


		if (Effect_List_Add_Element(cnt+1, pst, vols))
			span++;
		if(pst == EFX_PRST_16)
			pst = EFX_PRST_1;
		else
			pst++;

	}

//	for (Efx_Preset_t pst = EFX_PRST_1; pst < EFX_PRST_MAX; ++pst) {
//		//Efx_t *efx = Effect_Creare_Node((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);
//		//list_push_back(efx_list, (void*)efx);
//		Effect_List_Add_Element((uint8_t)pst+17, pst, vols);
//		span++;
//
//	}
//	for (Efx_Preset_t pst = EFX_PRST_1; pst < EFX_PRST_12; ++pst) {
//		//Efx_t *efx = Effect_Creare_Node((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);
//		//list_push_back(efx_list, (void*)efx);
//		Effect_List_Add_Element((uint8_t)pst+33, pst, vols);
//		span++;
//
//	}


//#define last_efx 41
//	for (int var = 17; var < last_efx; ++var) {
//		Helper_Load_Efx_EEP(var);
//	}
//	at24_HAL_EraseMemFull(&hi2c1);
//	Helper_Load_Efx_EEP(17);


}

//Efx_Memory_t* Effect_List_Create_mem(uint8_t main_num, Efx_Preset_t pst, uint32_t *vols){
//
//	Efx_Memory_t *mem = &mems[efx_cnt++];
//
//	mem->main_num = main_num;
//	mem->pst_num = pst;
//
//	mem->vols[VOL_A] = vols[VOL_A] >> 4;
//	mem->vols[VOL_B] = vols[VOL_B] >> 4;
//	mem->vols[VOL_C] = vols[VOL_C] >> 4;
//	mem->vols[VOL_D] = vols[VOL_D] >> 4;
//
//	return mem;
//
//}

//Efx_t* Effect_List_Create_Element(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint32_t *vols){
//
//	Efx_t *efx = malloc(sizeof(Efx_t));
//	//TODO: check malloc
//	if(!efx){
//		//_Error_Handler(__FILE__, __LINE__);
//		glcd_clear_buffer();
//		glcd_set_font_c(FC_Tekton_Pro_Ext27x28_AlphaNumber);
//		glcd_draw_string(23, 25, "MEM ERR");
//
//
//		glcd_write();
//		HAL_Delay(10000);
//		//return (Efx_t*)NULL;
//	}
//
//	efx->base = Efx_Get_Base(pst);
//	efx->pmode = pmode;
//	efx->mem.pst_num = pst;
//	efx->mem.main_num = number;
//
//	/*
//	 * adc was 12 bit so shift 4bit to the right*/
//	efx->mem.vols[VOL_A] = vols[VOL_A] >> 4;
//	efx->mem.vols[VOL_B] = vols[VOL_B] >> 4;
//	efx->mem.vols[VOL_C] = vols[VOL_C] >> 4;
//	efx->mem.vols[VOL_D] = vols[VOL_D] >> 4;
//
//	return efx;
//}

uint8_t Effect_List_Add_Element(uint8_t main_num, Efx_Preset_t pst, uint32_t *vols){

//	Efx_t *efx = Effect_List_Create_Element(number, pmode, pst, vols);
//	list_push_back(efx_list, (void*)efx);

	if(efx_cnt >= EFX_LIST_SIZE)
		return 0;

	Efx_Memory_t *mem = &mems[efx_cnt];
	//node_t *node = &nodes[efx_cnt];

	Enc_Event_Set_Span(efx_cnt);

	efx_cnt++;

	mem->main_num = main_num;
	mem->pst_num = pst;
	mem->vols[VOL_A] = vols[VOL_A] >> 4;
	mem->vols[VOL_B] = vols[VOL_B] >> 4;
	mem->vols[VOL_C] = vols[VOL_C] >> 4;
	mem->vols[VOL_D] = vols[VOL_D] >> 4;

	//node->element = (void*)mem;

	//list_push_static(&efx_list, node);
	return 1;

}


void Effect_List_Modify_Vol_Element(Efx_t *cur_efx, uint32_t *new_val){
	/*
	 * adc was 12 bit so shift 4bit to the right to save just 8byte on it
	 * */
	cur_efx->mem.vols[VOL_A] = new_val[VOL_A] >> 4;
	cur_efx->mem.vols[VOL_B] = new_val[VOL_B] >> 4;
	cur_efx->mem.vols[VOL_C] = new_val[VOL_C] >> 4;
	cur_efx->mem.vols[VOL_D] = new_val[VOL_D] >> 4;
}

uint8_t Effect_List_Get_EFX_Element(Efx_t* efx, uint8_t number){

	//node_t *node;
	Efx_Memory_t* mem;
	//uint8_t lsize = (uint8_t)Effect_List_Get_List_Size();

	/*
	 * TODO:
	 * 		"list_iter_from_tail()" doesn't work properly?
	 * 		it's need to test it, carefully
	 * */
//	if( (lsize - number) > number )
//		node = list_iter_from_head(&efx_list, number);
//	else
//		node = list_iter_from_tail(&efx_list, (lsize - number));
//
//	if(node == NULL)
//		return 0;

//	mem = (Efx_Memory_t*)(node->element);

	mem = &mems[number];

	efx->mem.main_num = mem->main_num;
	efx->mem.pst_num = mem->pst_num;
	efx->mem.vols[VOL_A] = mem->vols[VOL_A];
	efx->mem.vols[VOL_B] = mem->vols[VOL_B];
	efx->mem.vols[VOL_C] = mem->vols[VOL_C];
	efx->mem.vols[VOL_D] = mem->vols[VOL_D];

	efx->base = Efx_Get_Base(efx->mem.pst_num);
	if(efx->mem.main_num > 16)
		efx->pmode = EFX_USER_PRESET_MODE;
	else
		efx->pmode = EFX_FACT_PRESET_MODE;

	return 1;

}

size_t Effect_List_Get_List_Size(void){
	return (efx_list.size);
}

