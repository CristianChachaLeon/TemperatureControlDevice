#define F_CPU 16000000

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,
                                         _FDEV_SETUP_WRITE);
static int
uart_putchar(char c, FILE *stream)
{
    if (c == '\n')
        uart_putchar('\r', stream);
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return 0;
}
void init_uart()
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
    UBRR0 = (F_CPU / 8 / 9600) - 1;

    // Enable TX Y RX
    UCSR0B |= (1 << TXEN0);
    UCSR0B |= (1 << RXEN0);
}
int main(void)
{
    init_uart();
    stdout = &mystdout;

    while (1)
    {
        printf("Hello, world !!,Windows 10\n");
        _delay_ms(500);
    }
    return 0;
}