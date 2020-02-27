




#ifndef	_EEPROM_24XX_H
#define	_EEPROM_24XX_H

#include "main.h"


#define		_EEPROM_SIZE_KBIT				8
#define		_EEPROM24XX_I2C					hi2c1
#define		_EEPROM_FREERTOS_IS_ENABLE		0
#define		_EEPROM_USE_WP_PIN				0

#if (_EEPROM_USE_WP_PIN==1)
#define		_EEPROM_WP_GPIO											EE_WP_GPIO_Port
#define		_EEPROM_WP_PIN											EE_WP_Pin
#endif



// 	eeprom 24cxxx library				version 1V01
//	"Nima Askari"								www.github.com/NimaLTD

//#include <stdbool.h>
//#include <stddef.h>
//#include <stdint.h>


uint8_t	EEPROM24XX_IsConnected(void);
uint8_t	EEPROM24XX_Save(uint16_t Address,void *data,size_t size_of_data);
uint8_t	EEPROM24XX_Load(uint16_t Address,void *data,size_t size_of_data);





#endif
