/*
 * eep_helper.c
 *
 *  Created on: Feb 7, 2020
 *      Author: sam
 */

#include "eep_helper.h"


#define eep_offset 16


uint8_t Helper_Svae_Efx_EEP(App_Handle_t *handle, uint8_t num){

	Efx_Memory_t mem;
	uint8_t addr;
	size_t size;

	mem = handle->cur_efx->mem;
	size = sizeof(mem);
	num = num-17;
	addr = num * 8;

	return EEPROM24XX_Save(addr, (void*)&mem, size);
}


uint8_t Helper_Load_Efx_EEP(uint8_t num){

	Efx_Memory_t mem;
	uint8_t addr;
	size_t size;
	uint32_t vols[4];

	size = sizeof(mem);
	num = num-17;
	addr = num * 8;

	if(EEPROM24XX_Load(addr, (void*)&mem, size) == 1){

		Enc_Event_Set_Span(Enc_Event_Get_Span + 1);

		vols[0] = mem.vols[0]<<4;
		vols[1] = mem.vols[1]<<4;
		vols[2] = mem.vols[2]<<4;
		vols[3] = mem.vols[3]<<4;
		Effect_List_Add_Element(mem.main_num, EFX_USER_PRESET_MODE, mem.pst_num, vols);
		return 1;
	}
	return 0;

}
