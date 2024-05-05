################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Libs/Peripherals/Src/gpio.cpp 

OBJS += \
./Libs/Peripherals/Src/gpio.o 

CPP_DEPS += \
./Libs/Peripherals/Src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/Peripherals/Src/%.o Libs/Peripherals/Src/%.su Libs/Peripherals/Src/%.cyclo: ../Libs/Peripherals/Src/%.cpp Libs/Peripherals/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"F:/Projects/stm32/stm32/basic_peripherals/gpio/output/Program" -I"F:/Projects/stm32/stm32/basic_peripherals/gpio/output/Libs/Peripherals/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-Peripherals-2f-Src

clean-Libs-2f-Peripherals-2f-Src:
	-$(RM) ./Libs/Peripherals/Src/gpio.cyclo ./Libs/Peripherals/Src/gpio.d ./Libs/Peripherals/Src/gpio.o ./Libs/Peripherals/Src/gpio.su

.PHONY: clean-Libs-2f-Peripherals-2f-Src

