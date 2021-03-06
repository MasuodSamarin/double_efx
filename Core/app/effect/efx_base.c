/*
 * efx_base.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */


#include "efx.h"
#include "fv1.h"
#include "vol.h"



Efx_Base_t *efx_base_box[EFX_PRST_MAX] = {
		/*this is efx_box 	NAME		     CODE SHR595							VOLUMES GROUP*/
		&((Efx_Base_t){ "ECHO:1", "MONO",		( FV1_EEP_0 | FV1_CODE_0 ),					( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "ECHO:2", "MONO", 		( FV1_EEP_0 | FV1_CODE_1 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "ECHO:3", "MONO", 		( FV1_EEP_0 | FV1_CODE_2 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "ECHO:4", "MONO", 		( FV1_EEP_0 | FV1_CODE_3 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "ECHO:L","ECHO:R", 		( FV1_EEP_0 | FV1_CODE_4 | SW_4066_EN), 	( VOL_GROUP_1 | VOL_GROUP_2 | VOL_GROUP_3 | VOL_GROUP_4 )}),
		&((Efx_Base_t){ "PING", "PONG",		 	( FV1_EEP_0 | FV1_CODE_5 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "MOLTI", "PONG", 		( FV1_EEP_0 | FV1_CODE_6 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "ECHO", "REVERB",		( FV1_EEP_0 | FV1_CODE_7 ), 				( VOL_GROUP_1 | VOL_GROUP_2 | VOL_GROUP_3)}),

		&((Efx_Base_t){ "VOICE", "SPEECH", 		( FV1_EEP_1 | FV1_CODE_0 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "REVERB", "VOCAL", 		( FV1_EEP_1 | FV1_CODE_1 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "REVERB", "HALL", 		( FV1_EEP_1 | FV1_CODE_2 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "REVERB", "ROOM", 		( FV1_EEP_1 | FV1_CODE_3 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "ECHO", "FLANG", 		( FV1_EEP_1 | FV1_CODE_4 ), 				( VOL_GROUP_1 | VOL_GROUP_2 | VOL_GROUP_3 )}),
		&((Efx_Base_t){ "REVERB", "FLANGE", 	( FV1_EEP_1 | FV1_CODE_5 ), 				( VOL_GROUP_1 | VOL_GROUP_2 | VOL_GROUP_3 )}),
		&((Efx_Base_t){ "CHORUS", "PITCH", 		( FV1_EEP_1 | FV1_CODE_6 ), 				( VOL_GROUP_1 | VOL_GROUP_2 )}),
		&((Efx_Base_t){ "CHORUS", "REVERB", 	( FV1_EEP_1 | FV1_CODE_7 ), 				( VOL_GROUP_1 | VOL_GROUP_2 | VOL_GROUP_3 )})

};


Efx_Base_t* Efx_Get_Base(Efx_Preset_t pst){

	return efx_base_box[pst];
}



