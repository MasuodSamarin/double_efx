//----------------------------------------------------------------------------

//

//----------------------------------------------------------------------------

#ifndef SYSTIMER_H
#define SYSTIMER_H


#define SYSTEM_CORE_CLOCK 72000000
#define AHB_CLOCK SYSTEM_CORE_CLOCK
#define APB2_CLOCK SYSTEM_CORE_CLOCK
#define APB1_CLOCK SYSTEM_CORE_CLOCK


typedef enum {
	//STIM_INTERVAL_US = 0,
	STIM_INTERVAL_MS = 0,
	STIM_INTERVAL_SEC,
	STIM_INTERVAL_MIN,
	STIM_INTERVAL_HOUR,
	STIM_INTERVAL_MAX
}SofTimer_IntervalDef;

typedef enum {
	STIM_MODE_ONESHOT = 0,
	STIM_MODE_AUTOREALOAD,
	STIM_MODE_MAX
}SofTimer_ModeDef;

typedef enum {
	STIM_STATE_DISABLE = 0,
	STIM_STATE_ENABLE,
	STIM_STATE_MAX
}SofTimer_StateDef;

typedef struct SofTimer_TypeDef{

	SofTimer_ModeDef Mode;
	uint32_t Interval;
	SofTimer_IntervalDef Interval_t;
	SofTimer_StateDef state;
	uint32_t StartCount;

	uint8_t Tick;

}SofTimer_TypeDef;


void SofTim_Init(SofTimer_TypeDef *stim, SofTimer_ModeDef m, SofTimer_IntervalDef i, uint32_t t);
void SofTim_Start(SofTimer_TypeDef *stim);
void SofTim_Stop(SofTimer_TypeDef *stim);
void SofTim_Reset(SofTimer_TypeDef *stim);
void SofTim_SetInterval(SofTimer_TypeDef *stim, SofTimer_IntervalDef i, uint32_t t);
void SofTim_SetMode(SofTimer_TypeDef *stim, SofTimer_ModeDef m);
void SofTim_Force(SofTimer_TypeDef *stim);
uint8_t SofTim_Over(SofTimer_TypeDef *stim);

void SofTim_Delay_us(uint32_t d);
void SofTim_Delay_ms(uint32_t d);


#endif

