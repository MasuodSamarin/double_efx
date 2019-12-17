/*
 * btn.c
 *
 *  Created on: Dec 11, 2019
 *      Author: sam
 */

#include "btn.h"


#define Btn_Status	((BTN_GPIO_Port)->IDR & BTN_Pin)
#define Time_Now	(HAL_GetTick())
/* Return with status macro */
#define RETURN_WITH_STATUS(b, p)    do { (b)->has_press = p; return p; } while (0)

typedef enum {
	BTN_STATE_START,
	BTN_STATE_PRESSED,
	BTN_STATE_RELEASED,
	BTN_STATE_MAX,
}Btn_State_t;



typedef uint8_t(*Btn_Handle_fp)(Btn_t *btn);

static uint8_t Btn_Hadle_State_Start(Btn_t *btn);
static uint8_t Btn_Hadle_State_Pressed(Btn_t *btn);
static uint8_t Btn_Hadle_State_Released(Btn_t *btn);

static Btn_State_t	state;
static uint32_t	start_time;

static Btn_Handle_fp Btn_Handle_table[BTN_STATE_MAX]={
		Btn_Hadle_State_Start,
		Btn_Hadle_State_Pressed,
		Btn_Hadle_State_Released
};


void Btn_Event_Init(Btn_t *btn){
	/* Button pressed, go to state BTN_STATE_START */
	state = BTN_STATE_START;
	/* Save pressed time */
	start_time = Time_Now;
	/*set the press time to initial value*/
	Btn_Event_Set_Press_time(btn, BTN_NORMAL_PRESS_TIME);
	/*there's no press btn, yet*/
	btn->has_press = 0;
}

uint8_t Btn_Event_Handle(Btn_t *btn){

	return Btn_Handle_table[state](btn);
}

#ifdef	FUNC_VS_DEFINE
void Btn_Event_Set_Press_time(Btn_t *btn, uint32_t time){
	btn->press_time = time;
}
#endif



static uint8_t Btn_Hadle_State_Start(Btn_t *btn){
	/* First state */
	/* Check if pressed */
	if ( Btn_Status == GPIO_PIN_RESET ) {
		/* Button pressed, go to state BTN_STATE_PRESSED */
		state = BTN_STATE_PRESSED;
		/* Save pressed time */
		start_time = Time_Now;
	}

	RETURN_WITH_STATUS(btn, 0);
}

static uint8_t Btn_Hadle_State_Pressed(Btn_t *btn){
	/* Button still pressed */
	/* Check for press time */
	if ( Btn_Status == GPIO_PIN_RESET ) {
		if (( Time_Now - start_time ) > btn->press_time ) {
			/* Button pressed OK, call function */
			/* Call function callback */
			/* Go to stage BUTTON_STATE_WAITRELEASE */
			state = BTN_STATE_RELEASED;
			RETURN_WITH_STATUS(btn, 1);

		}
	}else{
		/* Button pressed, go to state BTN_STATE_START */
		state = BTN_STATE_START;
	}

	RETURN_WITH_STATUS(btn, 0);
}
static uint8_t Btn_Hadle_State_Released(Btn_t *btn){
	/* Wait till button released */
	if (Btn_Status != GPIO_PIN_RESET) {
		/* Button pressed, go to state BTN_STATE_START */
		state = BTN_STATE_START;
	}

	RETURN_WITH_STATUS(btn, 0);
}





