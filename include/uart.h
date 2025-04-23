// uart.h
// Header for UART2 low-level driver

#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart2_init(void);
void uart2_send_char(char c);
void uart2_send_string(const char *str);

#endif
