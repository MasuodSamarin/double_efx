################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/dma.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/iwdg.c \
../Core/Src/main.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f0xx.c \
../Core/Src/tim.c 

OBJS += \
./Core/Src/adc.o \
./Core/Src/dma.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/iwdg.o \
./Core/Src/main.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f0xx.o \
./Core/Src/tim.o 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/dma.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/iwdg.d \
./Core/Src/main.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f0xx.d \
./Core/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"/home/sam/w/work/double_effect/code/test_defx/Core/Inc" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/STM32F0xx_HAL_Driver/Inc" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/CMSIS/Include" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/effect" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/event" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/glcd" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/aux"  -Os -g -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


