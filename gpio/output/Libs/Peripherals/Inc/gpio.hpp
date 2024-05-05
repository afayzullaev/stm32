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


class Gpio
{
private:
	uint16_t mpin;
	GPIO_TypeDef* mport;
	PIN_MODE mmode;
	void Enable_Clock(void);
public:
	Gpio(uint16_t pin, GPIO_TypeDef* port, PIN_MODE mode);
	void Write(PIN_STATE state);
};




#ifdef __cplusplus
}
#endif



#endif
