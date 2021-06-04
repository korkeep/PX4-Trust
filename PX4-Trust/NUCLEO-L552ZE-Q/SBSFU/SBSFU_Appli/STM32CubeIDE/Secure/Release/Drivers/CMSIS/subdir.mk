################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/system_stm32l5xx_s.c 

OBJS += \
./Drivers/CMSIS/system_stm32l5xx_s.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l5xx_s.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l5xx_s.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/system_stm32l5xx_s.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Drivers/CMSIS/system_stm32l5xx_s.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

