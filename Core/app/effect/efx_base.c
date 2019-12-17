/*
 * efx_base.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */


#include "main.h"
#include "efx.h"





struct Efx_Base_t{

	const	char			*name;
	const	uint8_t			code;
	const	Efx_Vol_Group_t	grp;
};


struct Efx_Base_t *efx_base_box[EFX_FV1_PRST_MAX] = {
		&((struct Efx_Base_t){.name="MONO ECHO 1",		.code=(FV1_EEP_0 | FV1_CODE_0),		.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="MONO ECHO 2", 		.code=(FV1_EEP_0 | FV1_CODE_1), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="MONO ECHO 3", 		.code=(FV1_EEP_0 | FV1_CODE_2), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="MONO ECHO 4", 		.code=(FV1_EEP_0 | FV1_CODE_3), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="MULTI PONG", 		.code=(FV1_EEP_0 | FV1_CODE_4), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="PING PONG", 		.code=(FV1_EEP_0 | FV1_CODE_5), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="ECHO + DELAY", 	.code=(FV1_EEP_0 | FV1_CODE_6), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="ECHO + REVERB", 	.code=(FV1_EEP_0 | FV1_CODE_7), 	.grp=EFX_VOL_GROUP_1}),

		&((struct Efx_Base_t){.name="VOICE DELAY", 		.code=(FV1_EEP_1 | FV1_CODE_0), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="HALL REVERB", 		.code=(FV1_EEP_1 | FV1_CODE_1), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="REVERB + FLNG", 	.code=(FV1_EEP_1 | FV1_CODE_2), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="ECHO + FLANG", 	.code=(FV1_EEP_1 | FV1_CODE_3), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="VOICE FLANG", 		.code=(FV1_EEP_1 | FV1_CODE_4), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="VOICE FLANG", 		.code=(FV1_EEP_1 | FV1_CODE_5), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="VOICE CHUOROS", 	.code=(FV1_EEP_1 | FV1_CODE_6), 	.grp=EFX_VOL_GROUP_1}),
		&((struct Efx_Base_t){.name="VOICE REVERB", 	.code=(FV1_EEP_1 | FV1_CODE_7), 	.grp=EFX_VOL_GROUP_1})

};
