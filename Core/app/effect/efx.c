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

Efx_Base_t *Efx_Get_Base(Efx_Preset_t pst);


list_t *efx_list;




/*
 * this is the init of the module, possible?
 * those efx_pushe_list func's must be call before list_make_iterator call
 * make the 16 first effect chain list
 * */
void Effect_List_Init(void){
	efx_list = list_create();
	Enc_Event_Set_Span(16);

	uint32_t vols[VOL_MAX] = {0};
	for (Efx_Preset_t pst = EFX_PRST_1; pst < EFX_PRST_MAX; ++pst) {
		//Efx_t *efx = Effect_Creare_Node((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);
		//list_push_back(efx_list, (void*)efx);
		Effect_List_Add_Element((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);

	}
//	at24_HAL_EraseMemFull(&hi2c1);
	Helper_Load_Efx_EEP(17);
	Helper_Load_Efx_EEP(18);
//	Helper_Load_Efx_EEP(19);
//	Helper_Load_Efx_EEP(20);

}

static Efx_t* Effect_List_Create_Element(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint32_t *vols){

	Efx_t *efx = malloc(sizeof(Efx_t));
	//TODO: check malloc
	if(!efx){
		//_Error_Handler(__FILE__, __LINE__);
		return (Efx_t*)NULL;
	}

	efx->base = Efx_Get_Base(pst);
	efx->pmode = pmode;
	efx->mem.pst_num = pst;
	efx->mem.main_num = number;

	/*
	 * adc was 12 bit so shift 4bit to the right*/
	efx->mem.vols[VOL_A] = vols[VOL_A] >> 4;
	efx->mem.vols[VOL_B] = vols[VOL_B] >> 4;
	efx->mem.vols[VOL_C] = vols[VOL_C] >> 4;
	efx->mem.vols[VOL_D] = vols[VOL_D] >> 4;

	return efx;
}

void Effect_List_Add_Element(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint32_t *vols){

	Efx_t *efx = Effect_List_Create_Element(number, pmode, pst, vols);
	list_push_back(efx_list, (void*)efx);
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

Efx_t* Effect_List_Get_EFX_Element(uint8_t number){

	node_t *node;
	uint8_t lsize = (uint8_t)Effect_List_Get_List_Size();

	/*
	 * TODO:
	 * 		"list_iter_from_tail()" doesn't work properly?
	 * 		it's need to test it, carefully
	 * */
	if( (lsize - number) > number )
		node = list_iter_from_head(efx_list, number);
	else
		node = list_iter_from_tail(efx_list, (lsize - number));

	if(node == NULL)
		return NULL;
	return (node->element);
}

size_t Effect_List_Get_List_Size(void){
	return (efx_list->size);
}

