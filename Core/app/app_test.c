/*
 * unit_test.c
 *
 *  Created on: Dec 18, 2019
 *      Author: sam
 */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"


#include "glcd.h"
#include "btn.h"



void test_btn_test(void);










void test_btn_test(void){
	Btn_t	btn;

	MX_TIM1_Init();
	glcd_init();
	glcd_set_font_c(FC_Default_Font_5x8_AlphaNumber);
	Btn_Event_Init(&btn);

	while (1)
	{
		if(Btn_Event_Handle(&btn)){
			glcd_clear_buffer();
			glcd_draw_string_P(5, 30, "BTN PREESED");
			glcd_write();
			HAL_Delay(1000);
			glcd_clear_buffer();
		}
		glcd_draw_string_P(5, 10, "USE BTN");
		glcd_write();
		HAL_Delay(10);
	}

}

