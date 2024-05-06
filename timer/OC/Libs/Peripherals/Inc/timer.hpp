#ifndef _GPIO_HPP_
#define _GPIO_HPP_
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


class Timer {
private:
    TIM_TypeDef* m_timer;
public:
    Timer(TIM_TypeDef* timer);
    void configure(uint32_t prescaler, uint32_t period);
    void start();
    void stop();
};




#ifdef __cplusplus
}
#endif



#endif
