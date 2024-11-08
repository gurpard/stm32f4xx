// Configure and control the built-in LD2 LED on PA5 with the built-in button on PC13 on the STM32F411RE board

#include "stm32f4xx.h"

int main(void)
{
    RCC->AHB1ENR |= (1 << 0) | (1 << 2); // Enable clocks for GPIOA and GPIOC
    GPIOA->MODER |= 1 << (5 * 2);        // Set PA5 to output mode
    GPIOC->MODER &= ~(3 << (13 * 2));    // Set PC13 to input mode

    while (1)
    {
        if (!(GPIOC->IDR & (1 << 13)))   // Check if the button is pressed
        {
            GPIOA->ODR |= (1 << 5);      // Turn on the LED
        }
        else
        {
            GPIOA->ODR &= ~(1 << 5);     // Turn off the LED
        }
    }
}
