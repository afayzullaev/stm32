#ifndef _TIMER_HPP_
#define _TIMER_HPP_
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/**
 * basic: TIM6/7, general:TIM2/3/4/5, advanced:TIM1/8
 */
class TimerBasic {
private:
	TIM_TypeDef* mtimer;
	uint16_t mPsc;
	uint16_t mArr;
public:
    TimerBasic(TIM_TypeDef* timer);
    TimerBasic(TIM_TypeDef* timer, uint16_t PSC, uint16_t ARR);

    void set_prescaler(uint16_t prescaler);
    void set_arr(uint16_t arr);
    void set_arr_force(uint16_t arr);
    void start();
    void stop();
private:
    void Enable_Clock(void);
};


#ifdef __cplusplus
}
#endif

#endif