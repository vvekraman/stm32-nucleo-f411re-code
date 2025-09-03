#include "stm32f4xx.h"	// loads all the structs for the stm32f411re

#define GPIOAEN			(1U<<0)
#define GPIOCEN			(1U<<2)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5
#define PIN13			(1U<<13)
#define BTN_PIN			PIN13

int main(void)
{

	RCC->AHB1ENR |= GPIOAEN;	// enable clock access
	RCC->AHB1ENR |= GPIOCEN;

	// PA5 - 01: General purpose output mode
	GPIOA->MODER &=~ (1U<<11);	// 11th bit to 0
	GPIOA->MODER |= (1U<<10);	// 10th bit to 1

	// Set PC13 as input - 00
	GPIOC->MODER &=~ (1U<<27);	// 27th bit to 0
	GPIOC->MODER &=~ (1U<<26);	// 26th bit to 0

	while(1)
	{
		if (!(GPIOC->IDR & BTN_PIN))
		{
			// bit set-reset register
			// bit 5 to 1 -> set -> LED ON
			GPIOA->BSRR |= LED_PIN;
		}
		else
		{
			// bit 21 to 1 -> reset -> LED OFF
			GPIOA->BSRR |= (1U<<21);
		}

	}
}
