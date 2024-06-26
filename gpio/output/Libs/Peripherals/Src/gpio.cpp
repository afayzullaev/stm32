#include "gpio.hpp"

Gpio::Gpio(uint16_t pin, GPIO_TypeDef* port, PIN_MODE mode) : mpin(pin), mport(port), mmode(mode)
{
	Enable_Clock();
	switch(mmode)
	{
		case INPUT:
			mport->MODER &= ~(3UL << (mpin*2));
			break;
		case OUTPUT:
			mport->MODER &= ~(3UL << (mpin*2));
			mport->MODER |= (1UL << (mpin*2));
			break;
		case AF:
			mport->MODER &= ~(3UL << (mpin*2));
			mport->MODER |= (2UL << (mpin*2));
			break;
		case ANALOG:
			mport->MODER &= ~(3UL << (mpin*2));
			mport->MODER |= (3UL << (mpin*2));
			break;
		default:
			break;
	}

}

void Gpio::Enable_Clock(void)
{
	if (mport == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	else if (mport == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	else if (mport == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	else if (mport == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	else if (mport == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	else if (mport == GPIOF) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	else if (mport == GPIOG) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	else if (mport == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	else if (mport == GPIOI) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
}


void Gpio::Write(PIN_STATE state)
{
	switch (state) {
		case LOW:
			mport->ODR &= ~(1 << mpin);
			break;
		case HIGH:
			mport->ODR |= 1 << mpin;
			break;
		default:
			break;
	}
}

