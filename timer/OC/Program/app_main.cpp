#include "app_main.hpp"
#include "gpio.hpp"

volatile uint8_t flag = 0;

extern "C" void EXTI0_IRQHandler(void) {
    // Your interrupt handling code for pin 0
    // This function will be called when the interrupt for pin 0 occurs
    // Clear the interrupt flag
    EXTI->PR |= 0x1UL << PIN_0;
    flag = 1;
}


void app_main(void)
{
	Gpio userBtn(PIN_0, GPIOA, INPUT, NO_PULL);
	userBtn.AttachInterupt(ANY_EDGE);

	Gpio greenLed(PIN_12, GPIOD, OUTPUT);
	Gpio redLed(PIN_13, GPIOD, OUTPUT);
	Gpio blueLed(PIN_14, GPIOD, OUTPUT);
	Gpio yellowLed(PIN_15, GPIOD, OUTPUT);
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
	}
}
