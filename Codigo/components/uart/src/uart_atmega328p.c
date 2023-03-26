/******************************************************************************
 * Copyright (C) 2023 by Cristian Chacha
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software.
 *
 *****************************************************************************/

/**
 * @file uart_atmega328p.c
 * @brief Abstraction uart device, implementation
 *
 * This header file provides an abstraction to write and read throw uart
 * using atmega328p. This HAL in only for atmega328p, since has hardware
 * dependecy.
 *
 * Function has dependeci of F_CPU
 *
 * @author Cristian chacha
 * @date March 2023
 *
 */

#include "uart_atmega328p.h"

void init_uart(uint32_t baudrate)
{
    // Operation mode Async
    UCSR0C &= ~(1 << UMSEL00);
    UCSR0C &= ~(1 << UMSEL01);

    // Not parity
    UCSR0C &= ~(1 << UPM00);
    UCSR0C &= ~(1 << UPM01);

    // One stop bit
    UCSR0C &= ~(1 << USBS0);

    // Frame 8bits
    UCSR0C |= (1 << UCSZ00);
    UCSR0C |= (1 << UCSZ01);
    UCSR0B &= ~(1 << UCSZ02);

    // Double speed
    UCSR0A |= (1 << U2X0);
    // Baudrate
    UBRR0 = (F_CPU / 8 / baudrate) - 1;

    // Enable TX Y RX
    UCSR0B |= (1 << TXEN0);
    UCSR0B |= (1 << RXEN0);
}
