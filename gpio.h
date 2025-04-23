// gpio.h
// Header for low-level GPIO driver

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "stm32l4xx.h"

void gpio_input_init(GPIO_TypeDef *port, uint8_t pin);
uint8_t gpio_read_pin(GPIO_TypeDef *port, uint8_t pin);

#endif
