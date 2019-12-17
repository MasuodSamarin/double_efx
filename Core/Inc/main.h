/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define mas 1
#define MIDI_RX_Pin GPIO_PIN_4
#define MIDI_RX_GPIO_Port GPIOA
#define BTN_Pin GPIO_PIN_5
#define BTN_GPIO_Port GPIOA
#define PWM_CH1_Pin GPIO_PIN_6
#define PWM_CH1_GPIO_Port GPIOA
#define PWM_CH2_Pin GPIO_PIN_7
#define PWM_CH2_GPIO_Port GPIOA
#define PWM_CH3_Pin GPIO_PIN_0
#define PWM_CH3_GPIO_Port GPIOB
#define PWM_CH4_Pin GPIO_PIN_1
#define PWM_CH4_GPIO_Port GPIOB
#define ENC_CH1_Pin GPIO_PIN_8
#define ENC_CH1_GPIO_Port GPIOA
#define ENC_CH2_Pin GPIO_PIN_9
#define ENC_CH2_GPIO_Port GPIOA
#define SHR_LATCH_Pin GPIO_PIN_10
#define SHR_LATCH_GPIO_Port GPIOA
#define SHR_CLK_Pin GPIO_PIN_11
#define SHR_CLK_GPIO_Port GPIOA
#define SHR_DATA_Pin GPIO_PIN_12
#define SHR_DATA_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_15
#define LCD_RST_GPIO_Port GPIOA
#define LCD_SCL_Pin GPIO_PIN_3
#define LCD_SCL_GPIO_Port GPIOB
#define LCD_A0_Pin GPIO_PIN_4
#define LCD_A0_GPIO_Port GPIOB
#define LCD_SI_Pin GPIO_PIN_5
#define LCD_SI_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
