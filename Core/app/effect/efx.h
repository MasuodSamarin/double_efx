/*
 * efx.h
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#ifndef APP_EFFECT_EFX_H_
#define APP_EFFECT_EFX_H_

#include "main.h"
#include "vol.h"

/*
 * there's only 16 fv1 preset in the eeps
 * */
/*
 * using in the efx_preset to point to preset effects
 * */
typedef enum {
	/*the first bank on the first eep*/
	EFX_PRST_1,
	EFX_PRST_2,
	EFX_PRST_3,
	EFX_PRST_4,
	EFX_PRST_5,
	EFX_PRST_6,
	EFX_PRST_7,
	EFX_PRST_8,
	/*the second bank on the second eep*/
	EFX_PRST_9,
	EFX_PRST_10,
	EFX_PRST_11,
	EFX_PRST_12,
	EFX_PRST_13,
	EFX_PRST_14,
	EFX_PRST_15,
	EFX_PRST_16,

	EFX_PRST_MAX,
}Efx_Preset_t;


/*effect (1 to 16) is a factory preset, so don't have prefix volume value
 * but for every other (from 17 to 99) there's a group of volumes, the value of vol-grp
 * save on the external storage.
 * */
typedef enum {
	EFX_USER_PRESET_MODE,
	EFX_FACT_PRESET_MODE
}Efx_Preset_Mode_t;


typedef struct Efx_Base_t{
	const char *name;
	const uint8_t code;
	const uint8_t vgrp;

}Efx_Base_t;


typedef struct Efx_Memory_t{
	uint8_t			main_num;
	Efx_Preset_t	pst_num;
	uint8_t			vols[VOL_MAX];

}Efx_Memory_t;

typedef struct Efx_t{
	Efx_Base_t 			*base;
	Efx_Memory_t 		mem;
	Efx_Preset_Mode_t 	pmode;
}Efx_t;





Efx_Base_t *Efx_get_base(Efx_Preset_t pst);

void Effect_List_Init(void);
Efx_t* Effect_Creare_Node(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint16_t *vols);
void Effect_List_Add_Node(uint8_t number, Efx_Preset_Mode_t pmode, Efx_Preset_t pst, uint16_t *vols);
Efx_t* Effect_Get_Node(uint8_t number);
size_t Effect_Get_List_Size(void);









#endif /* APP_EFFECT_EFX_H_ */
