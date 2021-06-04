################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/bl2_nv_services.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/boot_hal.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/low_level_com.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/low_level_device.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/low_level_flash.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/mpu_armv8m_drv.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/sha256_alt.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/system_stm32l5xx.c \
C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/tfm_low_level_security.c 

OBJS += \
./Application/User/bl2_nv_services.o \
./Application/User/boot_hal.o \
./Application/User/low_level_com.o \
./Application/User/low_level_device.o \
./Application/User/low_level_flash.o \
./Application/User/mpu_armv8m_drv.o \
./Application/User/sha256_alt.o \
./Application/User/system_stm32l5xx.o \
./Application/User/tfm_low_level_security.o 

C_DEPS += \
./Application/User/bl2_nv_services.d \
./Application/User/boot_hal.d \
./Application/User/low_level_com.d \
./Application/User/low_level_device.d \
./Application/User/low_level_flash.d \
./Application/User/mpu_armv8m_drv.d \
./Application/User/sha256_alt.d \
./Application/User/system_stm32l5xx.d \
./Application/User/tfm_low_level_security.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/bl2_nv_services.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/bl2_nv_services.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/bl2_nv_services.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/boot_hal.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/boot_hal.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/boot_hal.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/low_level_com.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/low_level_com.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/low_level_com.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/low_level_device.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/low_level_device.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/low_level_device.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/low_level_flash.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/low_level_flash.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/low_level_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mpu_armv8m_drv.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/mpu_armv8m_drv.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/mpu_armv8m_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/sha256_alt.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/sha256_alt.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/sha256_alt.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/system_stm32l5xx.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/system_stm32l5xx.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/system_stm32l5xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/tfm_low_level_security.o: C:/Users/korke/Desktop/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/SBSFU/SBSFU_Boot/Src/tfm_low_level_security.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -g3 -DSTM32L552xx -DUSE_HAL_DRIVER -DNDEBUG -DTFM_DEV_MODE '-DMCUBOOT_TARGET_CONFIG=<flash_layout.h>' '-DMBEDTLS_CONFIG_FILE=<config-boot.h>' -DMCUBOOT_DOUBLE_SIGN_VERIF -DBL2 -c -I../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../Middlewares/Third_Party/trustedfirmware -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/common -I../../../../../../../Middlewares/Third_Party/trustedfirmware/platform/ext/driver -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/include -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot -I../../../../../../../Middlewares/Third_Party/trustedfirmware/bl2/ext/mcuboot/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/include -I../../../../../../../Middlewares/Third_Party/mcuboot/boot/bootutil/src -I../../../../../../../Middlewares/Third_Party/mcuboot/ext/tinycrypt/lib/include -I../../../../../../../Middlewares/Third_Party/mbed-crypto/include -I../../../Linker -Os -ffunction-sections -fdata-sections -Wall -fshort-enums -fshort-wchar -funsigned-char -mcmse -Wall -Wno-format -Wno-return-type -fstack-usage -MMD -MP -MF"Application/User/tfm_low_level_security.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

