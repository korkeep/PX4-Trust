################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/main.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/secure_nsc.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/stm32l5xx_hal_msp.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/stm32l5xx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c 

OBJS += \
./Application/User/main.o \
./Application/User/secure_nsc.o \
./Application/User/stm32l5xx_hal_msp.o \
./Application/User/stm32l5xx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/secure_nsc.d \
./Application/User/stm32l5xx_hal_msp.d \
./Application/User/stm32l5xx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/secure_nsc.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/secure_nsc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/secure_nsc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l5xx_hal_msp.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/stm32l5xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/stm32l5xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l5xx_it.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/Secure/Src/stm32l5xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/stm32l5xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/syscalls.o: ../Application/User/syscalls.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/sysmem.o: ../Application/User/sysmem.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

