################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/Startup/startup_stm32l552zetxq.s 

OBJS += \
./Application/Startup/startup_stm32l552zetxq.o 

S_DEPS += \
./Application/Startup/startup_stm32l552zetxq.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Startup/startup_stm32l552zetxq.o: ../Application/Startup/startup_stm32l552zetxq.s Application/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m33 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Application/Startup/startup_stm32l552zetxq.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

