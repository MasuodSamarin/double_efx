/*
 * vol.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */


#include "vol.h"
#include "adc.h"

#define VOL_MAX_TOLERANCE	10
#define VOL_MIN_TOLERANCE	10
#define VOL_TOLERANCE		20
#define VOL_TOLERANCE_BIT	6


//int abs(int j){
//     return (j < 0 ? -j : j);
//}

//#define _abs(j) ((j) < 0 ? (-(j)) : (j))






void 	Vol_Event_Init(Vol_t *vol){
	HAL_ADC_Start_DMA(&hadc, vol->vol_raw, VOL_MAX);
}

uint8_t Vol_Event_Handle(Vol_t *vol){

	if(vol->vol_src[VOL_A] == VOL_FROM_MEM){
		if (abs( vol->vol_raw[VOL_A] - vol->vol_pre[VOL_A] ) >= VOL_TOLERANCE){
			vol->vol_pre[VOL_A] = vol->vol_raw[VOL_A];
			//vol->name = VOL_A;
			vol->vol_src[VOL_A] = VOL_FROM_ADC;
			return 1;
		}
	}
	if(vol->vol_src[VOL_B] == VOL_FROM_MEM){
		if (abs( vol->vol_raw[VOL_B] - vol->vol_pre[VOL_B] ) >= VOL_TOLERANCE){
			vol->vol_pre[VOL_B] = vol->vol_raw[VOL_B];
			//vol->name = VOL_B;
			vol->vol_src[VOL_B] = VOL_FROM_ADC;
			return 1;
		}
	}
	if(vol->vol_src[VOL_C] == VOL_FROM_MEM){
		if (abs( vol->vol_raw[VOL_C] - vol->vol_pre[VOL_C] ) >= VOL_TOLERANCE){
			vol->vol_pre[VOL_C] = vol->vol_raw[VOL_C];
			//vol->name = VOL_C;
			vol->vol_src[VOL_C] = VOL_FROM_ADC;
			return 1;
		}
	}
	if(vol->vol_src[VOL_D] == VOL_FROM_MEM){
		if (abs( vol->vol_raw[VOL_D] - vol->vol_pre[VOL_D] ) >= VOL_TOLERANCE){
			vol->vol_pre[VOL_D] = vol->vol_raw[VOL_D];
			//vol->name = VOL_D;
			vol->vol_src[VOL_D] = VOL_FROM_ADC;
			return 1;
		}
	}
	return 0;
}


void Vol_Event_Reset_Vols(Vol_t *vol){
	vol->vol_pre[VOL_A] = vol->vol_raw[VOL_A];
	vol->vol_pre[VOL_B] = vol->vol_raw[VOL_B];
	vol->vol_pre[VOL_C] = vol->vol_raw[VOL_C];
	vol->vol_pre[VOL_D] = vol->vol_raw[VOL_D];

}













