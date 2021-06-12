################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/system_stm32l5xx_ns.c 

OBJS += \
./Drivers/CMSIS/system_stm32l5xx_ns.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l5xx_ns.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l5xx_ns.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/system_stm32l5xx_ns.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/system_stm32l5xx_ns.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

