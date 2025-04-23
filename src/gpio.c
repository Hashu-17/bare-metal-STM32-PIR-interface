// gpio.c
// Low-level GPIO driver for STM32L433RCT

#include "gpio.h"
#include "stm32l4xx.h"  // CMSIS header for register defs

void gpio_input_init(GPIO_TypeDef *port, uint8_t pin) {
    // Enable GPIO clock
    if (port == GPIOA) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    else if (port == GPIOB) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    else if (port == GPIOC) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    else if (port == GPIOD) RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;
    else if (port == GPIOE) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
    else return;

    // Set pin mode to input (MODER = 00)
    port->MODER &= ~(0x3 << (pin * 2));

    // Optional: Disable pull-up/pull-down
    port->PUPDR &= ~(0x3 << (pin * 2));
}

uint8_t gpio_read_pin(GPIO_TypeDef *port, uint8_t pin) {
    return (port->IDR & (1 << pin)) ? 1 : 0;
}
