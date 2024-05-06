#include "timer.hpp"

Timer::Timer(TIM_TypeDef* timer) : m_timer(timer) {}

void Timer::configure(uint32_t prescaler, uint32_t period) {
    // Enable Timer clock
    if (m_timer == TIM2) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    } else if (m_timer == TIM3) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    } // Add more cases for other timers as needed

    // Timer configuration
    m_timer->PSC = prescaler - 1; // Prescaler
    m_timer->ARR = period - 1; // Auto-reload register
}

void Timer::start() {
    // Start the timer
    m_timer->CR1 |= TIM_CR1_CEN;
}

void Timer::stop() {
    // Stop the timer
    m_timer->CR1 &= ~TIM_CR1_CEN;
}
