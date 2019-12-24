/*
 * vol.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */


#include "vol.h"



int abs(int j){
     return (j < 0 ? -j : j);
}

#define abs2(j) (j < 0 ? -j : j)






void 	Vol_Event_Init(Vol_t *vol){}
uint8_t Vol_Event_Handle(Vol_t *vol){return 0;}
