/*
  @filename        "aml-stm32f401.h"
  @author          Anderson Nguyen
  @date            4/7/2025
*/

#ifndef AML_STM32F401_H
#define AML_STM32F401_H

#include "stm32f401xe.h"

typedef enum {
  GPIO_PIN_RESET   = 0,
  GPIO_PIN_SET     = 1,
} GPIO_PinState;

typedef struct {
  uint16_t pin,
  uint16_t 
} GPIO_InitStruct;

static inline void AML_GPIO_Init(GPIO_TypeDef){
  
};
static inline GPIO_PinState AML_GPIO_Read(GPIO_TypeDef* port, uint8_t pin);{
  return port->
}
static inline void AML_GPIO_Write(GPIO_TypeDef* port, uint8_t pin);


/* Sample alias definitions
#define SPI_MOSI_Pin             GPIO_PIN_13
#define SPI_MOSI_GPIO_Port       GPIOA
*/

#endif // AML_STM32F401_H



