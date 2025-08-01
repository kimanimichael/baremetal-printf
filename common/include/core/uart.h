#ifndef UART_H
#define UART_H

#include "stdint.h"
#include "stdbool.h"

void uart_setup(void);

void uart_write(uint8_t *data, const uint32_t length);

void uart_write_byte(uint8_t data);

uint32_t uart_read(uint8_t *data, const uint32_t length);

uint8_t uart_read_byte(void);

bool uart_data_available(void);

void usart3_isr(void);

#endif

