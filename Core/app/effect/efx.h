/*
 * efx.h
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#ifndef APP_EFFECT_EFX_H_
#define APP_EFFECT_EFX_H_


/*
 * there's only 16 fv1 preset in the eeps
 * */
/*
 * using in the efx_preset array to point to preset effects
 * */
typedef enum {
	EFX_FV1_PRST_1,
	EFX_FV1_PRST_2,
	EFX_FV1_PRST_3,
	EFX_FV1_PRST_4,
	EFX_FV1_PRST_5,
	EFX_FV1_PRST_6,
	EFX_FV1_PRST_7,
	EFX_FV1_PRST_8,
	EFX_FV1_PRST_9,
	EFX_FV1_PRST_10,
	EFX_FV1_PRST_11,
	EFX_FV1_PRST_12,
	EFX_FV1_PRST_13,
	EFX_FV1_PRST_14,
	EFX_FV1_PRST_15,
	EFX_FV1_PRST_16,
	EFX_FV1_PRST_MAX,

}Efx_Preset_t;

/*
 * in the each eep there's a 8 program, it start count from 0b000 to 0b111
 * like this:
 * 			0b00EELABC
 * 			0b00011001
 * 	that means second effect of eep 0
 * 	the L bit define latch bit, fv1 read external eep if this pin was logic 1
 * */
typedef enum {
	FV1_CODE_0 = 0b0000,
	FV1_CODE_1 = 0b0001,
	FV1_CODE_2 = 0b0010,
	FV1_CODE_3 = 0b0011,
	FV1_CODE_4 = 0b0100,
	FV1_CODE_5 = 0b0101,
	FV1_CODE_6 = 0b0110,
	FV1_CODE_7 = 0b0111,
}Fv1_Code_t;

typedef enum {
	FV1_EEP_0 = 0b00010000,
	FV1_EEP_1 = 0b00100000,
}Fv1_EEP_t;

typedef enum {
	EFX_VOL_GROUP_1,
	EFX_VOL_GROUP_2,
	EFX_VOL_GROUP_3,
	EFX_VOL_GROUP_MAX,
}Efx_Vol_Group_t;









//typedef struct Effect_t *Effect_t;

typedef struct Efx_Base_t *Efx_Base_t;
typedef struct Efx_Mem_t *Efx_Mem_t;


#endif /* APP_EFFECT_EFX_H_ */
