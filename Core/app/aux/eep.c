
#include "i2c.h"
#include "eep.h"
#if (_EEPROM_FREERTOS_IS_ENABLE==1)
#include "cmsis_os.h"
#endif
//##########################################################################
uint8_t EEPROM24XX_IsConnected(void)
{
#if	(_EEPROM_USE_WP_PIN==1)
	HAL_GPIO_WritePin(_EEPROM_WP_GPIO,_EEPROM_WP_PIN,GPIO_PIN_SET);
#endif
	if(HAL_I2C_IsDeviceReady(&_EEPROM24XX_I2C,0xa0,1,100)==HAL_OK)
		return 1;
	else
		return 0;
}
//##########################################################################
uint8_t	EEPROM24XX_Save(uint16_t Address,void *data,size_t size_of_data)
{
#if ((_EEPROM_SIZE_KBIT==1) || (_EEPROM_SIZE_KBIT==2))
	if(size_of_data > 8)
		return false;
#elif ((_EEPROM_SIZE_KBIT==4) || (_EEPROM_SIZE_KBIT==8) || (_EEPROM_SIZE_KBIT==16))
	if(size_of_data > 16)
		return 0;
#else
	if(size_of_data > 32)
		return false;
#endif

#if	(_EEPROM_USE_WP_PIN==1)
	HAL_GPIO_WritePin(_EEPROM_WP_GPIO,_EEPROM_WP_PIN,GPIO_PIN_RESET);
#endif

#if ((_EEPROM_SIZE_KBIT==1) || (_EEPROM_SIZE_KBIT==2))
	if(HAL_I2C_Mem_Write(&_EEPROM24XX_I2C,0xa0,Address,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#elif	(_EEPROM_SIZE_KBIT==4)
		if(HAL_I2C_Mem_Write(&_EEPROM24XX_I2C,0xa0|(Address&0x0001),Address>>1,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#elif	(_EEPROM_SIZE_KBIT==8)
			uint16_t devAddr, memAddr;
	devAddr = 0xA0 | ((Address >> 7) & 0x01);
	memAddr = Address & 0x00FF;
	if(HAL_I2C_Mem_Write(&_EEPROM24XX_I2C,devAddr,memAddr,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
		//if(HAL_I2C_Mem_Write(&_EEPROM24XX_I2C,0xa0,Address,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#elif	(_EEPROM_SIZE_KBIT==16)
		if(HAL_I2C_Mem_Write(&_EEPROM24XX_I2C,0xa0|(Address&0x0007),Address>>3,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#else
			if(HAL_I2C_Mem_Write(&_EEPROM24XX_I2C,0xa0,Address,I2C_MEMADD_SIZE_16BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#endif
			{
#if (_EEPROM_FREERTOS_IS_ENABLE==1)
				osDelay(7);
#else
				HAL_Delay(7);
#endif
#if	(_EEPROM_USE_WP_PIN==1)
				HAL_GPIO_WritePin(_EEPROM_WP_GPIO,_EEPROM_WP_PIN,GPIO_PIN_SET);
#endif
				return 1;
			}
			else
			{
#if	(_EEPROM_USE_WP_PIN==1)
				HAL_GPIO_WritePin(_EEPROM_WP_GPIO,_EEPROM_WP_PIN,GPIO_PIN_SET);
#endif
				return 0;
			}
}
//##########################################################################
uint8_t	EEPROM24XX_Load(uint16_t Address,void *data,size_t size_of_data)
{
#if	(_EEPROM_USE_WP_PIN==1)
	HAL_GPIO_WritePin(_EEPROM_WP_GPIO,_EEPROM_WP_PIN,GPIO_PIN_SET);
#endif
#if ((_EEPROM_SIZE_KBIT==1) || (_EEPROM_SIZE_KBIT==2))
	if(HAL_I2C_Mem_Read(&_EEPROM24XX_I2C,0xa0,Address,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#elif (_EEPROM_SIZE_KBIT==4)
		if(HAL_I2C_Mem_Read(&_EEPROM24XX_I2C,0xa0|(Address&0x0001),Address>>1,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#elif (_EEPROM_SIZE_KBIT==8)
			uint16_t devAddr, memAddr;
	devAddr = 0xA0 | ((Address >> 7) & 0x01);
	memAddr = Address & 0x00FF;
	if(HAL_I2C_Mem_Read(&_EEPROM24XX_I2C,devAddr,memAddr,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#elif (_EEPROM_SIZE_KBIT==16)
		if(HAL_I2C_Mem_Read(&_EEPROM24XX_I2C,0xa0|(Address&0x0007),Address>>3,I2C_MEMADD_SIZE_8BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#else
			if(HAL_I2C_Mem_Read(&_EEPROM24XX_I2C,0xa0,Address,I2C_MEMADD_SIZE_16BIT,(uint8_t*)data,size_of_data,100) == HAL_OK)
#endif
				return 1;
			else
				return 0;
}
