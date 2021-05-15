################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/app/glcd/ST7565R.c \
../Core/app/glcd/glcd.c \
../Core/app/glcd/glcd_graphics.c \
../Core/app/glcd/glcd_graphs.c \
../Core/app/glcd/glcd_text.c \
../Core/app/glcd/unit_tests.c 

OBJS += \
./Core/app/glcd/ST7565R.o \
./Core/app/glcd/glcd.o \
./Core/app/glcd/glcd_graphics.o \
./Core/app/glcd/glcd_graphs.o \
./Core/app/glcd/glcd_text.o \
./Core/app/glcd/unit_tests.o 

C_DEPS += \
./Core/app/glcd/ST7565R.d \
./Core/app/glcd/glcd.d \
./Core/app/glcd/glcd_graphics.d \
./Core/app/glcd/glcd_graphs.d \
./Core/app/glcd/glcd_text.d \
./Core/app/glcd/unit_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Core/app/glcd/%.o: ../Core/app/glcd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"/home/sam/w/work/double_effect/code/test_defx/Core/Inc" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/STM32F0xx_HAL_Driver/Inc" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"/home/sam/w/work/double_effect/code/test_defx/Drivers/CMSIS/Include" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/effect" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/event" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/glcd" -I"/home/sam/w/work/double_effect/code/test_defx/Core/app/aux"  -Os -g -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


