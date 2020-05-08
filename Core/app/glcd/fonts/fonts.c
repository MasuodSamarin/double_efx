#include "fonts.h"
#include "../glcd_text.h"



//const glcd_FontConfig_t FC_Segoe_UI_Symbol16x17 = {
//		.font_table = Segoe_UI_Symbol16x17,
//		.width = 16,
//		.height = 17,
//		.start_char = 44,
//		.end_char = 122
//};

//const glcd_FontConfig_t FC_Segoe_UI_Symbol19x18 = {
//		.font_table = Segoe_UI_Symbol19x18,
//		.width = 19,
//		.height = 18,
//		.start_char = 44,
//		.end_char = 122
//};

//const glcd_FontConfig_t FC_Segoe_UI_Symbol20x24 = {
//		.font_table = Segoe_UI_Symbol20x24,
//		.width = 20,
//		.height = 24,
//		.start_char = 44,
//		.end_char = 122
//};
//
//const glcd_FontConfig_t FC_Segoe_UI_Symbol12x12 = {
//		.font_table = Segoe_UI_Symbol12x12,
//		.width = 12,
//		.height = 12,
//		.start_char = 44,
//		.end_char = 122
//};
//
//const glcd_FontConfig_t FC_Nova_SSi12x11 = {
//		.font_table = Nova_SSi12x11,
//		.width = 12,
//		.height = 11,
//		.start_char = 44,
//		.end_char = 122
//};
//
//const glcd_FontConfig_t FC_Helvetica12x12 = {
//		.font_table = Helvetica12x12,
//		.width = 12,
//		.height = 12,
//		.start_char = 44,
//		.end_char = 122
//};
//

//const glcd_FontConfig_t FC_Univers14x17 = {
//		.font_table = Univers14x17,
//		.width = 14,
//		.height = 17,
//		.start_char = 48,
//		.end_char = 57
//};


const glcd_FontConfig_t FC_Helvetica14x15 = {
		.font_table = Helvetica14x15,
		.width = 14,
		.height = 15,
		.start_char = 48,
		.end_char = 90
};

//const glcd_FontConfig_t FC_Univers_Black_Thin16x16 = {
//		.font_table = Univers_Black_Thin16x16,
//		.width = 16,
//		.height = 16,
//		.start_char = 48,
//		.end_char = 57
//};

//const glcd_FontConfig_t FC_Boost_SSi16x16 = {
//		.font_table = Boost_SSi16x16,
//		.width = 16,
//		.height = 16,
//		.start_char = 48,
//		.end_char = 57
//};
//
//const glcd_FontConfig_t FC_One_BitDust_Two16x15 = {
//		.font_table = One_BitDust_Two16x15,
//		.width = 16,
//		.height = 15,
//		.start_char = 48,
//		.end_char = 57
//};

const glcd_FontConfig_t FC_Boost_SSi19x17 = {
		.font_table = Boost_SSi19x17,
		.width = 19,
		.height = 17,
		.start_char = 48,
		.end_char = 57
};


const glcd_FontConfig_t FC_Boost_SSi26x20 = {
		.font_table = Boost_SSi26x20,
		.width = 26,
		.height = 20,
		.start_char = 65,
		.end_char = 90
};


const glcd_FontConfig_t FC_SimplixSSK19x12 = {
		.font_table = SimplixSSK19x12,
		.width = 19,
		.height = 12,
		.start_char = 48,
		.end_char = 90
};

const glcd_FontConfig_t FC_SimplixSSK15x10 = {
		.font_table = SimplixSSK15x10,
		.width = 15,
		.height = 10,
		.start_char = 48,
		.end_char = 90
};

const glcd_FontConfig_t FC_SimplixSSK14x9 = {
		.font_table = SimplixSSK14x9,
		.width = 14,
		.height = 9,
		.start_char = 48,
		.end_char = 90
};

const glcd_FontConfig_t FC_Boost_SSi22x20 = {
		.font_table = Boost_SSi22x20,
		.width = 22,
		.height = 20,
		.start_char = 48,
		.end_char = 57
};

//
//const glcd_FontConfig_t FC_Helvetica_Narrow10x13 = {
//		.font_table = Helvetica_Narrow10x13,
//		.width = 10,
//		.height = 13,
//		.start_char = 44,
//		.end_char = 122
//};
//
//const glcd_FontConfig_t FC_Univers_BoldExt23x15 = {
//		.font_table = Univers_BoldExt23x15,
//		.width = 23,
//		.height = 15,
//		.start_char = 45,
//		.end_char = 122
//};
//
//const glcd_FontConfig_t FC_Univers_BoldExt26x18 = {
//		.font_table = Univers_BoldExt26x18,
//		.width = 23,
//		.height = 15,
//		.start_char = 44,
//		.end_char = 122
//};
//
//const glcd_FontConfig_t FC_Arial10x17 = {
//		.font_table = Arial10x17,
//		.width = 10,
//		.height = 17,
//		.start_char = 48,
//		.end_char = 57
//};
//
//const glcd_FontConfig_t FC_Seas10x14 = {
//		.font_table = Seas10x14,
//		.width = 10,
//		.height = 14,
//		.start_char = 48,
//		.end_char = 57
//};
//
//const glcd_FontConfig_t FC_Univers10x13 = {
//		.font_table = Univers10x13,
//		.width = 10,
//		.height = 13,
//		.start_char = 48,
//		.end_char = 57
//};
//
//const glcd_FontConfig_t FC_Univers12x14 = {
//		.font_table = Univers12x14,
//		.width = 12,
//		.height = 14,
//		.start_char = 48,
//		.end_char = 57
//};


/*
 * number only fonts
 * */
//const glcd_FontConfig_t FC_Bebas_Neue18x36_Numbers = {
//		.font_table = Bebas_Neue18x36_Numbers,
//		.width = 18,
//		.height = 36,
//		.start_char = 46,
//		.end_char = 57,
//};
//const glcd_FontConfig_t FC_Tahoma11x13_AlphaNumber = {
//		.font_table = Tahoma11x13,
//		.width = 11,
//		.height = 13,
//		.start_char = 32,
//		.end_char = 127,
//
//};
//
//const glcd_FontConfig_t FC_Tekton_Pro_Ext27x28_AlphaNumber = {
//		.font_table = Tekton_Pro_Ext27x28,
//		.width = 27,
//		.height = 28,
//		.start_char = 32,
//		.end_char = 127,
//
//};

//const glcd_FontConfig_t FC_FONT1 = {
//		.font_table = font1,
//		.width = 15,
//		.height = 12,
//		.start_char = 32,
//		.end_char = 90,
//};
////const glcd_FontConfig_t FC_FONT2 = {
//		.font_table = font2,
//		.width = 14,
//		.height = 18,
//		.start_char = 48,
//		.end_char = 57,
//};
//const glcd_FontConfig_t FC_FONT3 = {
//		.font_table = font3,
//		.width = 22,
//		.height = 20,
//		.start_char = 48,
//		.end_char = 86,
//};
//const glcd_FontConfig_t FC_FONT4 = {
//		.font_table = font4,
//		.width = 46,
//		.height = 46,
//		.start_char = 48,
//		.end_char = 57,
//};
//const glcd_FontConfig_t FC_FONT5 = {
//		.font_table = font5,
//		.width = 24,
//		.height = 27,
//		.start_char = 46,
//		.end_char = 57,
//};
//const glcd_FontConfig_t FC_FONT6 = {
//		.font_table = font6,
//		.width = 26,
//		.height = 28,
//		.start_char = 46,
//		.end_char = 57,
//};
//const glcd_FontConfig_t FC_FONT7 = {
//		.font_table = font7,
//		.width = 28,
//		.height = 29,
//		.start_char = 46,
//		.end_char = 57,
//};
/*const glcd_FontConfig_t FC_Arial36x38_Number = {
		.font_table = Arial36x38,
		.width = 17,
		.height = 40,
		.start_char = 46,
		.end_char = 57,
};*/
//const glcd_FontConfig_t FC_Bebas_Neue20x36_Bold_Numbers = {
//		.font_table = Bebas_Neue20x36_Bold_Numbers,
//		.width = 20,
//		.height = 36,
//		.start_char = 46,
//		.end_char = 57,
//
//};
//
//const glcd_FontConfig_t FC_Liberation_Sans11x14_Numbers = {
//		.font_table = Liberation_Sans11x14_Numbers,
//		.width = 11,
//		.height = 14,
//		.start_char = 46,
//		.end_char = 57,
//
//};
//const glcd_FontConfig_t FC_Liberation_Sans15x21_Numbers = {
//		.font_table = Liberation_Sans15x21_Numbers,
//		.width = 15,
//		.height = 21,
//		.start_char = 46,
//		.end_char = 57,
//
//};
//
//const glcd_FontConfig_t FC_Liberation_Sans20x28_Numbers = {
//		.font_table = Liberation_Sans20x28_Numbers,
//		.width = 20,
//		.height = 28,
//		.start_char = 46,
//		.end_char = 57,
//
//};
//const glcd_FontConfig_t FC_Liberation_Sans27x36_Numbers = {
//		.font_table = Liberation_Sans27x36_Numbers,
//		.width = 27,
//		.height = 36,
//		.start_char = 46,
//		.end_char = 57,
//
//};
//
///*
// * alfa-numbers fonts
// * */
//const glcd_FontConfig_t FC_Liberation_Sans17x17_Alpha = {
//		.font_table = Liberation_Sans17x17_Alpha,
//		.width = 17,
//		.height = 17,
//		.start_char = 46,
//		.end_char = 90,
//};

//const glcd_FontConfig_t FC_Default_Font_5x8_AlphaNumber = {
//		.font_table = Font5x8,
//		.width = 5,
//		.height = 8,
//		.start_char = 32,
//		.end_char = 127,
//
//};
