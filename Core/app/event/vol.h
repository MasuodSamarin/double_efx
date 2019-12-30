/*
 * vol.h
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#ifndef APP_EVENT_VOL_H_
#define APP_EVENT_VOL_H_

#include "main.h"


/*
 * there's 4 of volumes consume 4 channel ADC
 * */
typedef enum {
	VOL_A,
	VOL_B,
	VOL_C,
	VOL_D,
	VOL_MAX
}Vol_Name_t;


/*
 * each EFFECT has its specific sets of volumes
 * for example:
 *  fefx1 has (volA and volB) but in efx2 we have four of them
 *  */
typedef enum {
	VOL_GROUP_1 = 0x01,
	VOL_GROUP_2	= 0x02,
	VOL_GROUP_3	= 0x04,
	VOL_GROUP_4	= 0x08,
	VOL_GROUP_MAX,
}Vol_Group_t;


typedef enum {
	VOL_FROM_ADC,
	VOL_FROM_MEM
}vol_src_t;


typedef struct Vol_t{
	uint32_t	vol_raw[VOL_MAX];
	uint32_t	vol_pre[VOL_MAX];
	vol_src_t	vol_src[VOL_MAX];
	Vol_Name_t 	name;
}Vol_t;










void 	Vol_Event_Init(Vol_t *vol);
uint8_t Vol_Event_Handle(Vol_t *vol);






#endif /* APP_EVENT_VOL_H_ */
