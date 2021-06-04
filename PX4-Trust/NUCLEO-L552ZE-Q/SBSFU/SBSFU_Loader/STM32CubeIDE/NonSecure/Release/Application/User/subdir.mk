################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/com.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/common.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/fw_update_app.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/low_level_device.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/low_level_flash.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/main.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/system_stm32l5xx.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/tick.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/ymodem.c 

OBJS += \
./Application/User/com.o \
./Application/User/common.o \
./Application/User/fw_update_app.o \
./Application/User/low_level_device.o \
./Application/User/low_level_flash.o \
./Application/User/main.o \
./Application/User/system_stm32l5xx.o \
./Application/User/tick.o \
./Application/User/ymodem.o 

C_DEPS += \
./Application/User/com.d \
./Application/User/common.d \
./Application/User/fw_update_app.d \
./Application/User/low_level_device.d \
./Application/User/low_level_flash.d \
./Application/User/main.d \
./Application/User/system_stm32l5xx.d \
./Application/User/tick.d \
./Application/User/ymodem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/com.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/com.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/com.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/common.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/common.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/common.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/fw_update_app.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/fw_update_app.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/fw_update_app.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/low_level_device.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/low_level_device.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/low_level_device.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/low_level_flash.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/low_level_flash.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/low_level_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/system_stm32l5xx.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/system_stm32l5xx.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/system_stm32l5xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/tick.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/tick.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/tick.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/ymodem.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Loader/NonSecure/Src/ymodem.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DLOCAL_LOADER_CONFIG -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/test/suites/crypto -I../../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../Linker -I../../../Secure_nsclib -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/ymodem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

