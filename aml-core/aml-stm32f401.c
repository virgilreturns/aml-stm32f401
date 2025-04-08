/*
  @filename        "aml-stm32f401.c"
  @author          Anderson Nguyen
  @date            4/8/2025
*/

#include "aml-stm32f401.h"



void AML_GPIO_Init(GPIO_TypeDef* port, GPIO_InitStruct* init) {
	uint16_t temp;

	switch (port) {
	case GPIOA:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		break;
	case GPIOB:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
		break;
	case GPIOC:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
		break;
	case GPIOD:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		break;
	case GPIOE:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
		break;
	default:
		break;
	}

	temp = port->MODER;
	temp &= ~(3 << (init->pin * 2));
	temp |= (init->mode << (init->pin * 2));
	port->MODER = temp;

	temp = port->PUPDR;
	temp &= ~(3 << (init->pin * 2));
	temp |= (init->pull << (init->pin * 2));
	port->PUPDR = temp;

	temp = port->OSPEEDR;
	temp &= ~(3 << (init->pin * 2));
	temp |= (init->speed << (init->pin * 2));
	port->OSPEEDR = temp;

	temp = port->OTYPER;
	temp &= ~(1 << init->pin);
	temp |= (init->output_type << init->pin);
	port->OTYPER = temp;

	
}

static inline GPIO_PinState AML_GPIO_Read(GPIO_TypeDef* port, uint8_t pin) {
	return (port->IDR & (1 << pin)) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}
static inline void AML_GPIO_PIN_Set(GPIO_TypeDef* port, uint8_t pin) {
	port->BSRR = (1 << pin);
}
static inline void AML_GPIO_PIN_Reset(GPIO_TypeDef* port, uint8_t pin) {
	port->BSRR = (1 << (pin + 16));
}
__weak void GPIO_Init() {
	// defined in main.c
	// create GPIO_InitStruct
	// set pin, mode, pull, speed, output_type
	// AML_GPIO_Init(GPIOx, &init);
}




