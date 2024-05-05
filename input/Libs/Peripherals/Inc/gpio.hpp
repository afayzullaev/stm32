#ifndef _GPIO_HPP_
#define _GPIO_HPP_
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

enum PIN_STATE{
	LOW = 0,
	HIGH
};

enum PIN_MODE{
	INPUT = 0,
	OUTPUT,
	AF,
	ANALOG
};

enum PIN_PUPDR{
	NO_PULL_UP_DOWN = 0,
	PULL_UP,
	PULL_DOWN,
};


class Gpio
{
private:
	uint16_t mpin;
	GPIO_TypeDef* mport;
	PIN_MODE mmode;
	PIN_PUPDR mpupdr;
	void Enable_Clock(void);
public:
	Gpio(uint16_t pin, GPIO_TypeDef* port, PIN_MODE mode);
	Gpio(uint16_t pin, GPIO_TypeDef* port, PIN_MODE mode, PIN_PUPDR pupdr);
	void Write(PIN_STATE state);
	PIN_STATE Read(void);
};




#ifdef __cplusplus
}
#endif



#endif
