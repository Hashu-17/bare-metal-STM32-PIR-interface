// main.c
// Bare-metal STM32L433RCT project: PIR sensor + UART output

#include "gpio.h"
#include "uart.h"
#include "delay.h"

#define PIR_INPUT_PIN  (5)   // Example: PA5 connected to PIR OUT
#define PIR_INPUT_PORT GPIOA

int main(void) {
    // Initialize GPIO for PIR sensor
    gpio_input_init(PIR_INPUT_PORT, PIR_INPUT_PIN);

    // Initialize UART2 (e.g., TX on PA2, RX on PA3)
    uart2_init();

    uart2_send_string("System Ready.\r\n");

    while (1) {
        if (gpio_read_pin(PIR_INPUT_PORT, PIR_INPUT_PIN)) {
            uart2_send_string("Motion detected!\r\n");
            delay_ms(1000);  // Debounce
        }
    }
}
