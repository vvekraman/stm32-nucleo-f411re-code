/*
 * stm32CustomHeader.h
 *
 *  Created on: Sep 2, 2025
 *      Author: vivek
 */

#ifndef STM32CUSTOMHEADER_H_
#define STM32CUSTOMHEADER_H_

// Struct for RCC
typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;
} RCC_TypeDef;

// Struct for GPIO
// To blink the LED, we have to write to the output data register
// which would be the GPIOx_ODR - output data register
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t DUMMY[3];
	volatile uint32_t IDR;
	volatile uint32_t ODR;
} GPIO_TypeDef;

#endif /* STM32CUSTOMHEADER_H_ */
