// Configure and turn on the built-in LD2 LED connected to PA5 on the STM32F411RE board

#include "stm32f4xx.h"

int main(void)
{
    RCC->AHB1ENR |= 1 << 0;          // Enable IO port A clock
    GPIOA->MODER |= 1 << (5 * 2);    // Turn on output mode for MODER5
    GPIOA->PUPDR &= ~(3 << (5 * 2)); // Clear PUPDR5
    GPIOA->PUPDR |= 1 << (5 * 2);    // Set pull-up mode for PA5 pin
    GPIOA->ODR |= 1 << 5;            // Set PA5 high to turn on LD2 LED
}
