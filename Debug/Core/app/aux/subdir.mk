################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/app/aux/eep.c \
../Core/app/aux/eep_helper.c \
../Core/app/aux/fv1.c \
../Core/app/aux/hc595.c 

OBJS += \
./Core/app/aux/eep.o \
./Core/app/aux/eep_helper.o \
./Core/app/aux/fv1.o \
./Core/app/aux/hc595.o 

C_DEPS += \
./Core/app/aux/eep.d \
./Core/app/aux/eep_helper.d \
./Core/app/aux/fv1.d \
./Core/app/aux/hc595.d 


# Each subdirectory must supply rules for building sources it contributes
Core/app/aux/%.o: ../Core/app/aux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"/home/sam/w/work/double_effect/code/test_defx/Core/Inc" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/STM32F0xx_HAL_Driver/Inc" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/CMSIS/Include" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/effect" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/event" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/glcd" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/aux"  -Os -g -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


