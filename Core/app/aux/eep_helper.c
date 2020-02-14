/*
 * eep_helper.c
 *
 *  Created on: Feb 7, 2020
 *      Author: sam
 */

#include "eep_helper.h"


#define eep_offset 16

const uint8_t EEP_ADDR_TABLE[6] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88};

uint8_t Helper_Svae_Efx_EEP(App_Handle_t *handle, uint8_t num){

	Efx_Memory_t mem;
	uint8_t addr, x, y;
	size_t size;

	mem = handle->cur_efx->mem;
	size = sizeof(mem);
	num = num-17;
//	x = num / 2;
//	y = num % 2;

//	if(y)
//		addr = EEP_ADDR_TABLE[x] + 6;
	//else
		addr = EEP_ADDR_TABLE[num];
		return EEPROM24XX_Save(addr, (void*)&mem, size);
	//return HAL_I2C_Mem_Write(&hi2c1, 0xA0, addr, I2C_MEMADD_SIZE_8BIT, (void*)&mem, size, 1000);
	//return EEPROM24XX_Save(addr, (void*)&mem, size);
	//return at24_HAL_WriteBytes(&hi2c1, 0xA0, addr, (void*)&mem, size);
}


uint8_t Helper_Load_Efx_EEP(uint8_t num){

	Efx_Memory_t mem;
	uint8_t addr, x, y;
	size_t size;
	uint32_t vols[4];
	size = sizeof(mem);
	num = num-17;

//	x = num / 2;
//	y = num % 2;

//	if(y)
		addr = EEP_ADDR_TABLE[num];
//	else
//		addr = EEP_ADDR_TABLE[x] + 6;
		//EEPROM24XX_Load(addr, (void*)&mem, size);
		if(EEPROM24XX_Load(addr, (void*)&mem, size) == true){
//			if(HAL_I2C_Mem_Read(&hi2c1, 0xA0, addr, I2C_MEMADD_SIZE_8BIT, (void*)&mem, size, 1000) == HAL_OK){
	//if(at24_HAL_ReadBytes(&hi2c1, 0xA0, addr, (void*)&mem, size)){
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
