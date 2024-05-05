#include "app_main.hpp"
#include "gpio.hpp"


void app_main(void)
{
	Gpio greenLed(12, GPIOD, OUTPUT);
	Gpio redLed(13, GPIOD, OUTPUT);
	Gpio blueLed(14, GPIOD, OUTPUT);
	Gpio yellowLed(15, GPIOD, OUTPUT);

	while(true)
	{
		greenLed.Write(HIGH);
		redLed.Write(HIGH);
		blueLed.Write(HIGH);
		yellowLed.Write(HIGH);
		HAL_Delay(1000);
		greenLed.Write(LOW);
		redLed.Write(LOW);
		blueLed.Write(LOW);
		yellowLed.Write(LOW);
		HAL_Delay(1000);
	}
}
