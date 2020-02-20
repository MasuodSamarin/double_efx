/*
 * eep_helper.h
 *
 *  Created on: Feb 7, 2020
 *      Author: sam
 */

#ifndef APP_AUX_EEP_HELPER_H_
#define APP_AUX_EEP_HELPER_H_

#include "main.h"

#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_i2c.h"

#include "i2c.h"
#include "app.h"
#include "efx.h"



//uint8_t Helper_Load_Efx_EEP(uint8_t main_num);
uint8_t Helper_Svae_Efx_EEP(App_Handle_t *handle, uint8_t num);
void Helper_Load_Efx_EEP(void);
void Helper_Erase_EEP(void);

#endif /* APP_AUX_EEP_HELPER_H_ */
