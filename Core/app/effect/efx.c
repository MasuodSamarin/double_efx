/*
 * efx.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#include "main.h"
#include "efx.h"
#include "link_list.h"



list_t *efx_list;

/*
 * this is the init of the module, possible?
 * those efx_pushe_list func's must be call before list_make_iterator call
 * make the 16 first effect chain list
 * */
void Effect_List_Init(void){
	efx_list = list_create();

	uint16_t vols[VOL_MAX] = {0};
	for (Efx_Preset_t pst = EFX_PRST_1; pst < EFX_PRST_MAX; ++pst) {
		//Efx_t *efx = Effect_Creare_Node((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);
		//list_push_back(efx_list, (void*)efx);
		Effect_List_Add_Node((uint8_t)pst+1, EFX_FACT_PRESET_MODE, pst, vols);

	}
}

Efx_t* Effect_Creare_Node(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint16_t *vols){

	Efx_t *efx = malloc(sizeof(Efx_t));
	//TODO: check malloc
	if(!efx){
		_Error_Handler(__FILE__, __LINE__);
		return (Efx_t*)NULL;
	}

	efx->base = effect_get_base(pst);
	efx->pmode = pmode;
	efx->mem.pst_num = pst;
	efx->mem.main_num = number;

	efx->mem.vols[VOL_A] = vols[VOL_A];
	efx->mem.vols[VOL_B] = vols[VOL_B];
	efx->mem.vols[VOL_C] = vols[VOL_C];
	efx->mem.vols[VOL_D] = vols[VOL_D];

	return efx;
}

void Effect_List_Add_Node(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint16_t *vols){

	Efx_t *efx = Effect_Creare_Node(number, pmode, pst, vols);
	list_push_back(efx_list, (void*)efx);
}

Efx_t* Effect_Get_Node(uint8_t number){

	node_t *efx;
	uint8_t lsize = (uint8_t)efx_list->size;

	/*
	 * TODO:
	 * 		"list_iter_from_tail()" doesn't work properly?
	 * 		it's need to test it, carefully
	 * */
	if( (lsize - number) > number )
		*efx = list_iter_from_head(efx_list, number);
	else
		*efx = list_iter_from_tail(efx_list, (lsize - number));

	if(efx == NULL)
		return NULL;
	return (efx->element);
}

size_t Effect_Get_List_Size(void){
	return (efx_list->size);
}

