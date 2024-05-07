#include "timer.hpp"

TimerBasic::TimerBasic(TIM_TypeDef* timer, uint16_t PSC, uint16_t ARR)
: mtimer(timer),
  mPsc(PSC),
  mArr(ARR)
{
	Enable_Clock();

	mtimer->CR1 &= ~(0x1UL << TIM_CR1_OPM_Pos);//disable one pulse

	mtimer->CR1 &= ~(0x1UL << TIM_CR1_URS_Pos);//Only counter overflow generates event
	mtimer->CR1 &= ~(0x1UL << TIM_CR1_UDIS_Pos);//Update Event enabled

	mtimer->CR2 &= ~(7UL << TIM_CR2_MMS_Pos);//Master mode --> Reset
	mtimer->CR1 |= 0x1UL << TIM_CR1_ARPE_Pos; // buffered
	mtimer->PSC = mPsc;
	mtimer->ARR = mArr;

	mtimer->SR = 0;//Clear Update Event Interrupt

	mtimer->DIER |= 0x1UL << TIM_DIER_UIE_Pos;//Enable Update interrupt

	mtimer->EGR |= (0x1UL<<TIM_EGR_UG_Pos);//UG: Update generation. Re-initializes the counter and updates registers
	if (mtimer == TIM6) {
		NVIC_EnableIRQ(TIM6_DAC_IRQn);
		NVIC_SetPriority(TIM6_DAC_IRQn, 5);
	} else if (mtimer == TIM7) {
		NVIC_EnableIRQ(TIM7_IRQn);
		NVIC_SetPriority(TIM7_IRQn, 5);
	}


}

void TimerBasic::Enable_Clock(void)
{
	// Enable Timer clock
	if (mtimer == TIM6) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	} else if (mtimer == TIM7) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	}
}
void TimerBasic::set_prescaler(uint16_t prescaler) {
    // Start the timer
	mPsc = prescaler;
	mtimer->ARR = mArr;
}

void TimerBasic::set_arr(uint16_t arr) {
    // Start the timer
	mArr = arr;
	mtimer->PSC = mPsc;
}

void TimerBasic::set_arr_force(uint16_t arr) {
    // Start the timer
	mtimer->CR1 &= ~(0x1UL << TIM_CR1_ARPE_Pos); // Not buffered
	mArr = arr;
	mtimer->PSC = mPsc;
}

void TimerBasic::start() {
    // Start the timer
    mtimer->CR1 |= TIM_CR1_CEN;
}

void TimerBasic::stop() {
    // Stop the timer
    mtimer->CR1 &= ~TIM_CR1_CEN;
}