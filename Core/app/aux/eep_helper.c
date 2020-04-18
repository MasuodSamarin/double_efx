/*
 * eep_helper.c
 *
 *  Created on: Feb 7, 2020
 *      Author: sam
 */

#include "eep_helper.h"


#define eep_offset 16
#define eep_saved_addr 7


uint8_t Helper_Svae_Efx_EEP(App_Handle_t *handle, uint8_t num){

	Efx_Memory_t mem;
	uint8_t addr,size;

	mem = handle->cur_efx->mem;
	num = num-17;
	addr = num * 8;
	size = num+1;

	EEPROM24XX_Save(eep_saved_addr, (void*)&size, sizeof(size));
	return EEPROM24XX_Save(addr, (void*)&mem, sizeof(mem));
}


//uint8_t Helper_Load_Efx_EEP(uint8_t num){
//
//	Efx_Memory_t mem;
//	uint8_t addr,size;
//	uint32_t vols[4];
//
//	num = num-17;
//	addr = num * 8;
//
//	EEPROM24XX_Load(eep_saved_addr, (void*)&size, sizeof(size));
//	if(EEPROM24XX_Load(addr, (void*)&mem, sizeof(mem)) == 1){
//
//		//Enc_Event_Set_Span(Enc_Event_Get_Span + 1);
//
//		vols[0] = mem.vols[0]<<4;
//		vols[1] = mem.vols[1]<<4;
//		vols[2] = mem.vols[2]<<4;
//		vols[3] = mem.vols[3]<<4;
//		Effect_List_Add_Element(mem.main_num, mem.pst_num, vols);
//		return 1;
//	}
//	return 0;
//
//}


void Helper_Load_Efx_EEP(void){

	Efx_Memory_t mem;
	uint8_t addr,size;
	uint32_t vols[4];



	EEPROM24XX_Load(eep_saved_addr, (void*)&size, sizeof(size));

	for (int var = 0; var < size; ++var) {

		addr = var * 8;

		if(EEPROM24XX_Load(addr, (void*)&mem, sizeof(mem)) == 1){

			//Enc_Event_Set_Span(Enc_Event_Get_Span + 1);

			vols[0] = mem.vols[0]<<4;
			vols[1] = mem.vols[1]<<4;
			vols[2] = mem.vols[2]<<4;
			vols[3] = mem.vols[3]<<4;
			Effect_List_Add_Element(mem.main_num, mem.pst_num, vols);
		}
	}

}

void Helper_Erase_EEP(void){
	uint8_t zeros[16] = {0xFF};
	uint8_t addr;

	for (int val = 0; val < 64; ++val) {

		addr = val * 16;

		EEPROM24XX_Save(addr, (void*)&zeros, sizeof(zeros));


	}

}










