################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/com.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/common.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/flash_if.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/fw_update_app.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/main.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/mpu_armv8m_drv.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/stm32l5xx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/test_protections.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/ymodem.c 

OBJS += \
./Application/User/com.o \
./Application/User/common.o \
./Application/User/flash_if.o \
./Application/User/fw_update_app.o \
./Application/User/main.o \
./Application/User/mpu_armv8m_drv.o \
./Application/User/stm32l5xx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/test_protections.o \
./Application/User/ymodem.o 

C_DEPS += \
./Application/User/com.d \
./Application/User/common.d \
./Application/User/flash_if.d \
./Application/User/fw_update_app.d \
./Application/User/main.d \
./Application/User/mpu_armv8m_drv.d \
./Application/User/stm32l5xx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/test_protections.d \
./Application/User/ymodem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/com.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/com.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/com.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/common.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/common.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/common.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/flash_if.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/flash_if.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/flash_if.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/fw_update_app.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/fw_update_app.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/fw_update_app.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mpu_armv8m_drv.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/mpu_armv8m_drv.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mpu_armv8m_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l5xx_it.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/stm32l5xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32l5xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/syscalls.o: ../Application/User/syscalls.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/sysmem.o: ../Application/User/sysmem.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/test_protections.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/test_protections.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/test_protections.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/ymodem.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Appli/NonSecure/Src/ymodem.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DBL2 -c -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../NonSecure/Inc -I../../../Secure_nsclib -I../../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/ymodem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

