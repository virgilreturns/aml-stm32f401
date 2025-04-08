/*
  @filename        "aml-stm32f401.h"
  @author          Anderson Nguyen
  @date            4/7/2025
*/

#ifndef AML_STM32F401_H
#define AML_STM32F401_H

#include "stm32f401xe.h"
#define __weak __attribute__((weak))

typedef enum {
  GPIO_PIN_RESET   = 0,
  GPIO_PIN_SET     = 1,
} GPIO_PinState;

typedef enum {
	GPIO_MODE_INPUT = 0x00,
	GPIO_MODE_OUTPUT = 0x01,
	GPIO_MODE_AF = 0x02,
	GPIO_MODE_ANALOG = 0x03,
} GPIO_PinMode;

typedef enum {
	GPIO_PULL_NOPULL = 0x00,
	GPIO_PULL_PULLUP = 0x01,
	GPIO_PULL_PULLDOWN = 0x02,
} GPIO_PinPull;

typedef enum {
	GPIO_SPEED_LOW = 0x00,
	GPIO_SPEED_MEDIUM = 0x01,
	GPIO_SPEED_HIGH = 0x02,
	GPIO_SPEED_VERY_HIGH = 0x03,
} GPIO_PinSpeed;

typedef enum {
	GPIO_OTYPER_PP = 0x00,
	GPIO_OTYPER_OD = 0x01,
} GPIO_OutputType;

typedef struct {
	uint16_t pin;
	GPIO_PinMode mode;
	GPIO_PinPull pull;
	GPIO_PinSpeed speed;
	GPIO_OutputType output_type;

} GPIO_InitStruct;

void AML_GPIO_Init(GPIO_TypeDef* port, GPIO_InitStruct* init);
static inline GPIO_PinState AML_GPIO_Read(GPIO_TypeDef* port, uint8_t pin);
static inline void AML_GPIO_PIN_Set(GPIO_TypeDef* port, uint8_t pin);
static inline void AML_GPIO_PIN_Reset(GPIO_TypeDef* port, uint8_t pin);

/* Sample alias definitions
#define SPI_MOSI_Pin             GPIO_PIN_13
#define SPI_MOSI_GPIO_Port       GPIOA
*/

__weak void GPIO_Init() {
	GPIO_InitStruct init;
	init.pin = 5;
	init.mode = GPIO_MODE_OUTPUT;
	init.pull = GPIO_PULL_NOPULL;
	init.speed = GPIO_SPEED_HIGH;
	init.output_type = GPIO_OTYPER_PP;
	AML_GPIO_Init(GPIOB, &init);
}



#endif // AML_STM32F401_H



