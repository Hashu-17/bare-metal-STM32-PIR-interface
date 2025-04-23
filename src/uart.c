// uart.c
// Minimal UART2 driver for STM32L433RCT (PA2 TX, PA3 RX)

#include "uart.h"
#include "stm32l4xx.h"

#define USART_BAUDRATE 9600
#define SYS_CLK_FREQ   16000000U  // Assuming HSI @ 16 MHz

void uart2_init(void) {
    // Enable GPIOA and USART2 clocks
    RCC->AHB2ENR  |= RCC_AHB2ENR_GPIOAEN;
    RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;

    // Set PA2 (TX) to AF mode
    GPIOA->MODER   &= ~(0x3 << (2 * 2));  // Clear MODER2
    GPIOA->MODER   |=  (0x2 << (2 * 2));  // AF mode
    GPIOA->AFR[0]  |=  (0x7 << (4 * 2));  // AF7 (USART2) on PA2

    // Set PA3 (RX) to AF mode
    GPIOA->MODER   &= ~(0x3 << (3 * 2));
    GPIOA->MODER   |=  (0x2 << (3 * 2));
    GPIOA->AFR[0]  |=  (0x7 << (4 * 3));

    // Configure USART2: 9600 8N1
    USART2->BRR = SYS_CLK_FREQ / USART_BAUDRATE;  // Set baud rate
    USART2->CR1 = USART_CR1_TE | USART_CR1_RE;    // Enable TX, RX
    USART2->CR1 |= USART_CR1_UE;                  // Enable USART
}

void uart2_send_char(char c) {
    while (!(USART2->ISR & USART_ISR_TXE));  // Wait until TX empty
    USART2->TDR = c;
}

void uart2_send_string(const char *str) {
    while (*str) {
        uart2_send_char(*str++);
    }
}
