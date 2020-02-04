/*
 * enc.h
 *
 *  Created on: Dec 12, 2019
 *      Author: sam
 */

#ifndef APP_EVENT_ENC_H_
#define APP_EVENT_ENC_H_
#include "main.h"
#include "tim.h"




/**
 * @brief  Rotary encoder rotation status
 */
typedef enum {
	Enc_Rotate_Increment, /*!< Encoder was incremented */
	Enc_Rotate_Decrement, /*!< Encoder was decremented */
	Enc_Rotate_Nothing    /*!< Encoder stop at it was before */
}Enc_Rotate_t;


typedef struct Enc_t{
	Enc_Rotate_t	direction;	/*!< user turn encoder to 'rotate' direction */
	__IO uint32_t	value;		/*!< User turn encoder exactly 'value' time */
	__IO uint32_t	tim_cnt;	/*!< Timer_Counter value*/
}Enc_t;



void	Enc_Event_Init(Enc_t *enc);
uint8_t Enc_Event_Handle(Enc_t *enc);
void Enc_Event_Set_val(Enc_t *enc, uint32_t val);

#define Enc_Event_Get_val			( __HAL_TIM_GET_COUNTER(&htim1) )
//#define Enc_Event_Set_val(val)		__HAL_TIM_SET_COUNTER(&htim1, val)

#define Enc_Event_Get_Span			( __HAL_TIM_GET_AUTORELOAD(&htim1) )
#define Enc_Event_Set_Span(span)	__HAL_TIM_SET_AUTORELOAD(&htim1, span)


#endif /* APP_EVENT_ENC_H_ */
