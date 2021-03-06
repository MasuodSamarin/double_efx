/**
   \file glcd.h
   \brief GLCD Library main header file. This file must be included into project.
   \author Andy Gock
 */ 

/*
	Copyright (c) 2012, Andy Gock

	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
		  notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
		  notice, this list of conditions and the following disclaimer in the
		  documentation and/or other materials provided with the distribution.
 * Neither the name of Andy Gock nor the
		  names of its contributors may be used to endorse or promote products
		  derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL ANDY GOCK BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _GLCD_H
#define _GLCD_H

/**
 * \name LCD Dimensions
 * @{
 */

/*
 * Set to custom value, or leave at 0 for automatic assignment.
 * For custom dimensions, users can define this in their compiler options.
 */


#define GLCD_LCD_WIDTH 128
#define GLCD_LCD_HEIGHT 64
/*
 * GLCD_NUMBER_OF_BANKS is typically GLCD_LCD_HEIGHT/8
 * Don't adjust these below unless required.
 */
#define GLCD_NUMBER_OF_BANKS (GLCD_LCD_WIDTH / 8)   // its 128/8 = 16
#define GLCD_NUMBER_OF_COLS  GLCD_LCD_WIDTH			// its 128

/**@}*/

/**
 * \name Colour Constants
 * @{
 */
#define BLACK 1
#define WHITE 0
/**@}*/

#define GLCD_RESET_TIME 10

//#include "stm32f0xx_hal.h"
#include "main.h"
//#include <stdint.h>

//#include "_STM32F10x.h"

#include "fonts/fonts.h"

#include "ST7565R.h"


#include "glcd_graphics.h"
#include "glcd_graphs.h"
#include "glcd_text.h"
//#include "unit_tests.h"


/* Macros */

#define swap(a, b) { uint8_t t = a; a = b; b = t; }

/* Defining new types */



/**
 * Bounding box for pixels that need to be updated
 */
typedef struct {
	uint8_t x_min;
	uint8_t y_min;
	uint8_t x_max;
	uint8_t y_max;
} glcd_BoundingBox_t;



/* Global variables used for GLCD library */
extern uint8_t glcd_buffer[GLCD_LCD_WIDTH * GLCD_LCD_HEIGHT / 8]; //its uses 1024B = 1KB of ram for handle lcd screen
extern glcd_BoundingBox_t glcd_bbox;
extern uint8_t *glcd_buffer_selected;
//extern glcd_BoundingBox_t *glcd_bbox_selected;




/** \name Base Functions 
 *  @{
 */

/**
 * Update bounding box.
 *
 * The bounding box defines a rectangle in which needs to be refreshed next time
 * glcd_write() is called. glcd_write() only writes to those pixels inside the bounding box plus any
 * surrounding pixels which are required according to the bank/column write method of the controller.
 *
 * Define a rectangle here, and it will be <em>added</em> to the existing bounding box.
 *
 * \param xmin Minimum x value of rectangle
 * \param ymin Minimum y value of rectangle
 * \param xmax Maximum x value of rectangle
 * \param ymax Maximum y value of rectangle
 * \see glcd_bbox
 * \see glcd_bbox_selected
 */
void glcd_update_bbox(uint8_t xmin, uint8_t ymin, uint8_t xmax, uint8_t ymax);

/**
 * Reset the bounding box.
 * After resetting the bounding box, no pixels are marked as needing refreshing.
 */
void glcd_reset_bbox(void);

/**
 * Same as glcd_reset_bbox()
 */
void glcd_bbox_reset(void);

/**
 * Marks the entire display for re-writing.
 */
void glcd_bbox_refresh(void);

/**
 * Clear the display. This will clear the buffer and physically write and commit it to the LCD
 */
void glcd_clear(void);

/**
 * Clear the display buffer only. This does not physically write the changes to the LCD
 */
void glcd_clear_buffer(void);

/**
 * Select screen buffer and bounding box structure.
 * This should be selected at initialisation. There are future plans to support multiple screen buffers
 * but this not yet available.
 * \param buffer Pointer to screen buffer
 * \param bbox   Pointer to bounding box object.
 * \see glcd_BoundingBox_t
 */
//void glcd_select_buffer(uint8_t *buffer);

/**
 * Scroll entire screne buffer by x and y pixels. (not implemented yet)
 * \note Items scrolled off the extents of the display dimensions will be lost.
 *
 * \param x X distance to scroll
 * \param y Y distance to scroll
 */
void glcd_scroll(int8_t x, int8_t y);

/**
 * Scroll screen buffer up by 8 pixels.
 * This is designed to be used in conjunciton with tiny text functions which are 8 bits high.
 * top is first line from top of lcd
 * \see Tiny Text
 */
void glcd_scroll_line(uint8_t top);

/** @}*/


//extern uint8_t *glcd_buffer_selected;
//extern glcd_BoundingBox_t *glcd_bbox_selected;

#endif
