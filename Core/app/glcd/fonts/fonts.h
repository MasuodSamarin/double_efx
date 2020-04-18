#ifndef _FONTS_H_
#define _FONTS_H_
#include "stm32f0xx_hal.h"

//typedef uint8_t (*glcd_draw_char_fp)(uint8_t, uint8_t, char);

/**
 * Font table type
 */
/*
typedef enum {
	STANG,
	MIKRO,
	GLCD_UTILS
} font_table_type_t;
 */

typedef struct {
	const char *font_table;
	uint8_t width;
	uint8_t height;
	char start_char;
	char end_char;

} glcd_FontConfig_t;

extern glcd_FontConfig_t font_current;


//#include "Bebas_Neue20x36_Bold_Numbers.h"
//#include "Liberation_Sans11x14_Numbers.h"
//#include "Liberation_Sans15x21_Numbers.h"
//#include "Liberation_Sans17x17_Alpha.h"
//#include "Liberation_Sans20x28_Numbers.h"
//#include "Liberation_Sans27x36_Numbers.h"
//
//#include "Font5x8.h"
//#include "Tahoma11x13.h"
//#include "Bebas_Neue18x36_Numbers.h"
//#include "Tekton_Pro_Ext27x28.h"
#include "font1.h"
#include "Segoe_UI_Symbol16x17.h"
#include "Segoe_UI_Symbol19x18.h"
#include "Segoe_UI_Symbol20x24.h"
#include "Segoe_UI_Symbol12x12.h"

#include "Nova_SSi12x11.h"
#include "Helvetica12x12.h"
#include "Helvetica14x15.h"
#include "Helvetica_Narrow10x13.h"
#include "Univers_BoldExt23x15.h"
#include "Univers_BoldExt26x18.h"
#include "Arial10x17.h"
#include "Seas10x14.h"
#include "Univers10x13.h"
#include "Univers12x14.h"
#include "Univers14x17.h"
#include "Univers_Black_Thin16x16.h"
//#include "font2.h"
//#include "font3.h"
//#include "font4.h"
//#include "font5.h"
//#include "font6.h"
//#include "font7.h"
//#include "Arial36x38.h"
/*TODO: this font not working good*/
/*bad font*/
//extern const glcd_FontConfig_t FC_Liberation_Sans17x17_Alpha;
//
///*show some extra point between numbers*/
//extern const glcd_FontConfig_t FC_Liberation_Sans11x14_Numbers;
//extern const glcd_FontConfig_t FC_Liberation_Sans15x21_Numbers;
//extern const glcd_FontConfig_t FC_Bebas_Neue20x36_Bold_Numbers;
//
//extern const glcd_FontConfig_t FC_Liberation_Sans20x28_Numbers;
//extern const glcd_FontConfig_t FC_Liberation_Sans27x36_Numbers;
//
//extern const glcd_FontConfig_t FC_Default_Font_5x8_AlphaNumber;



extern const glcd_FontConfig_t FC_Tekton_Pro_Ext27x28_AlphaNumber;
extern const glcd_FontConfig_t FC_Bebas_Neue18x36_Numbers;
extern const glcd_FontConfig_t FC_Tahoma11x13_AlphaNumber;
extern const glcd_FontConfig_t FC_FONT1;

//extern const glcd_FontConfig_t FC_FONT2;
//extern const glcd_FontConfig_t FC_FONT3;
//extern const glcd_FontConfig_t FC_FONT4;
//extern const glcd_FontConfig_t FC_FONT5;
//extern const glcd_FontConfig_t FC_FONT6;
//extern const glcd_FontConfig_t FC_FONT7;
//extern const glcd_FontConfig_t FC_Arial36x38_Number;




//extern  const glcd_FontConfig_t FC_Segoe_UI_Symbol16x17;
//extern const glcd_FontConfig_t FC_Segoe_UI_Symbol19x18;
//extern const glcd_FontConfig_t FC_Segoe_UI_Symbol20x24;
//extern const glcd_FontConfig_t FC_Segoe_UI_Symbol12x12;
//
//extern const glcd_FontConfig_t FC_Nova_SSi12x11;
//extern const glcd_FontConfig_t FC_Helvetica12x12;
extern const glcd_FontConfig_t FC_Helvetica14x15;
//extern const glcd_FontConfig_t FC_Helvetica_Narrow10x13;
//extern const glcd_FontConfig_t FC_Univers_BoldExt23x15;
//extern const glcd_FontConfig_t FC_Univers_BoldExt26x18;
//extern const glcd_FontConfig_t FC_Arial10x17;
//extern const glcd_FontConfig_t FC_Seas10x14;
//extern const glcd_FontConfig_t FC_Univers10x13;
//extern const glcd_FontConfig_t FC_Univers12x14;
//extern const glcd_FontConfig_t FC_Univers14x17;
extern const glcd_FontConfig_t FC_Univers_Black_Thin16x16;



#define FONT_EFX_NAME FC_Helvetica14x15
#define FONT_EFX_NUMBER FC_Univers_Black_Thin16x16
#define FONT_EFX_MSG FC_Helvetica14x15


#endif //_FONTS_H_
