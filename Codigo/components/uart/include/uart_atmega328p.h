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
 * @file uart_atmega328p.h
 * @brief Abstraction uart device
 *
 * This header file provides an abstraction to write and read throw uart
 * using atmega328p. This HAL in only for atmega328p, since has hardware
 * dependecy
 *
 * @author Cristian chacha
 * @date March 2023
 *
 */

#ifndef __UART_ATMEGA328P__
#define __UART_ATMEGA328P__

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <stdint.h>
#include <avr/io.h>

/**
 * @brief init uart basic configuration with especific
 * baudrate.
 *
 * Activate send and recevie bit.
 *
 * @param baudrate
 *
 * @return void
 *
 *
 *
 */

void init_uart(uint32_t baudrate);

#endif