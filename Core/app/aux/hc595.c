/*
 * hc595.c
 *
 *  Created on: Dec 24, 2019
 *      Author: sam
 */


#include "hc595.h"


#define LATCH_Port			GPIOB
#define LATCH_Pin			12
#define CLOCK_Port			GPIOB
#define CLOCK_Pin			13
#define DATA_Port			GPIOB
#define DATA_Pin			14



/*
 * 74HC595.c
 *
 *  Created on: 19.05.2019
 *      Author: Admin
 *
 *	LATCH    - PB12 (General output PP)
 *  CLOCK    - PB13 (General output PP)
 *  DATA     - PB14 (General output PP)
 *
 *	NSS      - PA4 (General purpose output push-pull)	(not used)
 *  SCK      - PA5 (Alternate function push-pull)
 *  MISO     - PA6 (Input floating / Input pull-up)		(not used)
 *  MOSI     - PA7 (Alternate function push-pull)
 */




void HC595_Init(void){

	/*
	 * init the gpio as output pushpull
	 * */
}

void HC595_SendByte(uint8_t byte){

	//uint16_t clock_timeout = 10000;
	//uint16_t latch_timeout = 1000;

	for (int8_t i = 7; i >= 0; --i) {

		uint8_t bit = byte & (0x1 << i);							// Read bit
		GPIO_WritePin(SHR_DATA_GPIO_Port, SHR_DATA_Pin, bit);		// Send bit

		// Toggle clock
		GPIO_WritePin(SHR_CLK_GPIO_Port, SHR_CLK_Pin, 1);
		//while(clock_timeout--);
		GPIO_WritePin(SHR_CLK_GPIO_Port, SHR_CLK_Pin, 0);
	}

	// Toggle latch
	GPIO_WritePin(SHR_LATCH_GPIO_Port, SHR_LATCH_Pin, 1);
	//while (latch_timeout--);
	GPIO_WritePin(SHR_LATCH_GPIO_Port, SHR_LATCH_Pin, 0);
}
