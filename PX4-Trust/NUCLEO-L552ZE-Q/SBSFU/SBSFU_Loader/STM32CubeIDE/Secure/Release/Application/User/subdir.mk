################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/low_level_device.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/low_level_flash.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/main.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/secure_nsc.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/system_stm32l5xx.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/tick.c 

OBJS += \
./Application/User/low_level_device.o \
./Application/User/low_level_flash.o \
./Application/User/main.o \
./Application/User/secure_nsc.o \
./Application/User/system_stm32l5xx.o \
./Application/User/tick.o 

C_DEPS += \
./Application/User/low_level_device.d \
./Application/User/low_level_flash.d \
./Application/User/main.d \
./Application/User/secure_nsc.d \
./Application/User/system_stm32l5xx.d \
./Application/User/tick.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/low_level_device.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/low_level_device.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Application/User/low_level_device.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/low_level_flash.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/low_level_flash.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Application/User/low_level_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/secure_nsc.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/secure_nsc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Application/User/secure_nsc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/system_stm32l5xx.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/system_stm32l5xx.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Application/User/system_stm32l5xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/tick.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/Secure/Src/tick.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Application/User/tick.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

