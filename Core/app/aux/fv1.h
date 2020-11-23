/*
 * fv1.h
 *
 *  Created on: Dec 18, 2019
 *      Author: sam
 */

#ifndef APP_EFFECT_FV1_H_
#define APP_EFFECT_FV1_H_



/*
 * in the each eep there's a 8 program, it start count from 0b000 to 0b111
 * like this:
 * 			0b00EELABC
 * 			0b00011001
 * 	that means second effect of eep 0
 * 	the L bit define latch bit, fv1 read external eep if this pin was logic 1
 * */
typedef enum {
	FV1_CODE_0 = 0b0000,
	FV1_CODE_1 = 0b0001,
	FV1_CODE_2 = 0b0010,
	FV1_CODE_3 = 0b0011,
	FV1_CODE_4 = 0b0100,
	FV1_CODE_5 = 0b0101,
	FV1_CODE_6 = 0b0110,
	FV1_CODE_7 = 0b0111,
	FV1_CODE_T = 0b1000
}Fv1_Code_t;

typedef enum {
	FV1_EEP_0 = 0b00010000,
	FV1_EEP_1 = 0b00100000,
}Fv1_EEP_t;

#define SW_4066_EN	0x40

#endif /* APP_EFFECT_FV1_H_ */
