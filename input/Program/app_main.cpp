#include "app_main.hpp"
#include "gpio.hpp"


void app_main(void)
{
	Gpio userBtn(0, GPIOA, INPUT, NO_PULL_UP_DOWN);
	Gpio greenLed(12, GPIOD, OUTPUT);
	Gpio redLed(13, GPIOD, OUTPUT);
	Gpio blueLed(14, GPIOD, OUTPUT);
	Gpio yellowLed(15, GPIOD, OUTPUT);
	PIN_STATE state;
	while(true)
	{
		state = userBtn.Read();
		if(state == HIGH)
		{
			greenLed.Write(HIGH);
			redLed.Write(HIGH);
			blueLed.Write(HIGH);
			yellowLed.Write(HIGH);
		}else{
			greenLed.Write(LOW);
			redLed.Write(LOW);
			blueLed.Write(LOW);
			yellowLed.Write(LOW);
		}


	}
}
