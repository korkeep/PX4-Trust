################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Application/Startup/startup_stm32l5xx_bl2.S 

OBJS += \
./Application/Startup/startup_stm32l5xx_bl2.o 

S_UPPER_DEPS += \
./Application/Startup/startup_stm32l5xx_bl2.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Startup/startup_stm32l5xx_bl2.o: ../Application/Startup/startup_stm32l5xx_bl2.S Application/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m33 -c -x assembler-with-cpp -MMD -MP -MF"Application/Startup/startup_stm32l5xx_bl2.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

