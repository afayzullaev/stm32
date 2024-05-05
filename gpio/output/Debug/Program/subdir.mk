################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Program/app_main.cpp 

OBJS += \
./Program/app_main.o 

CPP_DEPS += \
./Program/app_main.d 


# Each subdirectory must supply rules for building sources it contributes
Program/%.o Program/%.su Program/%.cyclo: ../Program/%.cpp Program/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"F:/Projects/stm32/stm32/basic_peripherals/gpio/output/Program" -I"F:/Projects/stm32/stm32/basic_peripherals/gpio/output/Libs/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Program

clean-Program:
	-$(RM) ./Program/app_main.cyclo ./Program/app_main.d ./Program/app_main.o ./Program/app_main.su

.PHONY: clean-Program

