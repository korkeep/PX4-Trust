################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_cortex.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_dma.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_dma_ex.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_flash.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_flash_ex.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_gpio.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_gtzc.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_pwr.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_pwr_ex.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_rcc.c \
C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_rcc_ex.c 

OBJS += \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_cortex.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma_ex.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash_ex.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gpio.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gtzc.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr_ex.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc.o \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc_ex.o 

C_DEPS += \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_cortex.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma_ex.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash_ex.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gpio.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gtzc.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr_ex.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc.d \
./Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_cortex.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_cortex.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_cortex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_dma.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma_ex.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_dma_ex.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_dma_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_flash.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash_ex.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_flash_ex.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_flash_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gpio.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_gpio.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gtzc.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_gtzc.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_gtzc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_pwr.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr_ex.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_pwr_ex.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_pwr_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_rcc.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc_ex.o: C:/Users/korke/Desktop/PX4-Trust/PX4-Trust/NUCLEO-L552ZE-Q/PSA-Services/Drivers/STM32L5xx_HAL_Driver/Src/stm32l5xx_hal_rcc_ex.c Drivers/STM32L5xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../Secure/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -Os -ffunction-sections -Wall -mcmse -fstack-usage -MMD -MP -MF"Drivers/STM32L5xx_HAL_Driver/stm32l5xx_hal_rcc_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

