/*
 * efx_mem.c
 *
 *  Created on: Dec 16, 2019
 *      Author: sam
 */


#include "main.h"
#include "efx.h"

struct Efx_Mem_t{
	uint8_t	main_num;
	uint8_t	base_num;
	uint8_t	vols[4];
	/*TODO:
	 * use vol_max instead magic number
	 * */
};

