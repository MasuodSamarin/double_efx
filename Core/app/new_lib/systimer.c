#include "main.h"
#include "systimer.h"

#define CLK_PER_US (SYSTEM_CORE_CLOCK / 1000000)
#define CLK_PER_MS (SYSTEM_CORE_CLOCK / 1000)

#define MS_PER_S	(1000)
#define MS_PER_MIN  (60000)
#define MS_PER_HOUR (3600000)


void SofTim_Init(SofTimer_TypeDef *stim, SofTimer_ModeDef mode, SofTimer_IntervalDef i, uint32_t t){

	stim->Mode = mode;
	stim->Interval_t = i;
	stim->Interval = t;
	stim->state = STIM_STATE_DISABLE;

	//stim->StartCount = HAL_GetTick();
	//stim->Tick = 0;
}

void SofTim_Start(SofTimer_TypeDef *stim){

	stim->StartCount = HAL_GetTick();
	stim->state = STIM_STATE_ENABLE;
}

void SofTim_Stop(SofTimer_TypeDef *stim){

	stim->StartCount = 0;
	stim->state = STIM_STATE_DISABLE;
}

void SofTim_Reset(SofTimer_TypeDef *stim){

	stim->StartCount = HAL_GetTick();
}

void SofTim_SetInterval(SofTimer_TypeDef *stim, SofTimer_IntervalDef i, uint32_t t){

	stim->Interval_t = i;

	switch (stim->Interval_t) {

		case STIM_INTERVAL_MS:
			stim->Interval = t;
			break;
		case STIM_INTERVAL_SEC:
			stim->Interval = t * MS_PER_S;
			break;
		case STIM_INTERVAL_MIN:
			stim->Interval = t * MS_PER_MIN;
			break;
		case STIM_INTERVAL_HOUR:
			stim->Interval = t * MS_PER_HOUR;
			break;
		default:
			break;
	}
}

void SofTim_SetMode(SofTimer_TypeDef *stim, SofTimer_ModeDef mode){

	stim->Mode = mode;
}

void SofTim_Force(SofTimer_TypeDef *stim){

	stim->StartCount = HAL_GetTick() - stim->Interval;
}

uint8_t SofTim_Over(SofTimer_TypeDef *stim){

	uint8_t event;

	if (stim->state == STIM_STATE_DISABLE)
		return 0;

	event = HAL_GetTick() - stim->StartCount >= stim->Interval;

	if(event){
		switch (stim->Mode) {

			case STIM_MODE_ONESHOT:
				SofTim_Stop(stim);
				break;

			case STIM_MODE_AUTOREALOAD:
				SofTim_Reset(stim);
				break;
			default:
				break;
		}
	}
	return(event);
}

void SofTim_Delay_us(uint32_t d){

	uint32_t DelayStart = SysTick->VAL;
	uint32_t DelayTicks = d * CLK_PER_US;
	__IO int32_t Delta;

	do {
		Delta = DelayStart - SysTick->VAL;
		if (Delta < 0) Delta += CLK_PER_MS;
	} while (Delta < DelayTicks);
}

void SofTim_Delay_ms(uint32_t d){

	uint32_t DelayStart = HAL_GetTick();
	while (HAL_GetTick() - DelayStart < d);
}
