/*
 * enc.c
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#include "enc.h"
#include "tim.h"





#define half(x)		( (x) / 2 )
#define nhalf(x)	( (-(x)) / 2 )

static uint32_t cnt;

void Enc_Event_Init(void){

	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	//Enc_Event_Set_Span(16);
	Enc_Event_Set_val(0);
	//enc->direction = Enc_Rotate_Nothing;
	//enc->value = 0;
	//enc->tim_cnt = Enc_Event_Get_val;

}

uint8_t Enc_Event_Handle(void){


	 uint32_t diff = 0;
	//__IO uint32_t span = Enc_Event_Get_Span;

	diff = Enc_Event_Get_val - ( cnt );
	//cnt = Enc_Event_Get_val;
	//diff = cnt - diff;
	//Static_Cnt = Enc_Reading_val;
	cnt = Enc_Event_Get_val;

	/* Enc_Rotate_Nothing*/
	if(0 == diff)//{
		//		enc->direction = Enc_Rotate_Nothing;
		//		enc->value = 0;
		return 0;

	//}
	else
		//{
		return 1;
	//}
//	/* Enc_Rotate_Decrement */
//	else if( diff > half(span) ){
//		enc->direction = Enc_Rotate_Decrement;
//		enc->value = span - diff;
//		return 1;
//
//	}
//	/* Enc_Rotate_Increment */
//	else if( diff < nhalf(span) ){
//		enc->direction = Enc_Rotate_Increment;
//		enc->value = span + diff;
//		return 1;
//
//	}
//	/* Enc_Rotate_Increment */
//	else if( diff > 0 ){
//		enc->direction = Enc_Rotate_Increment;
//		enc->value = diff;
//		return 1;
//	}
//	/* Enc_Rotate_Decrement */
//	else if( diff < 0 ){
//		enc->direction = Enc_Rotate_Decrement;
//		enc->value = (-diff);
//		return 1;
//	}
//	return 0;
}


void Enc_Event_Set_val(uint32_t val){
	__HAL_TIM_SET_COUNTER(&htim1, val);
	cnt = Enc_Event_Get_val;

	//enc->tim_cnt = val;
	//enc->value = 0;
	//enc->direction = Enc_Rotate_Nothing;
}









