#include "app_main.hpp"
#include "gpio.hpp"
#include "timer.hpp"
#include "stm32f4xx_hal.h"

volatile uint8_t flag = 0;

extern "C" void TIM7_IRQHandler(void) {

	TIM7->SR = 0;
	flag = 1;
}

void app_main(void)
{
	Gpio greenLed(PIN_12, GPIOD, OUTPUT);
	Gpio redLed(PIN_13, GPIOD, OUTPUT);
	Gpio blueLed(PIN_14, GPIOD, OUTPUT);
	Gpio yellowLed(PIN_15, GPIOD, OUTPUT);

	TimerBasic basic_timer(TIM7,16000-1, 5000);
	basic_timer.start();
	while(true)
	{
		if(flag == 1)
		{
			greenLed.Write(HIGH);
			redLed.Write(HIGH);
			blueLed.Write(HIGH);
			yellowLed.Write(HIGH);
			flag = 0;
			HAL_Delay(1000);
		}else{
			greenLed.Write(LOW);
			redLed.Write(LOW);
			blueLed.Write(LOW);
			yellowLed.Write(LOW);
			HAL_Delay(1000);
		}
		HAL_Delay(1000);
	}
}
