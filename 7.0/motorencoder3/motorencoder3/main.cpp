/*
 * motorencoder3.cpp
 *
 * Created: 10/9/2017 8:12:36 PM
 * Author : Sampada Dhakal
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"

#define F_CPU 16000000UL
#define BAUD_RATE 9600

int main(void)
{
	uart_init(UART_BAUD_SELECT(BAUD_RATE,F_CPU));
	uart_puts("MOTORENCODER");
    /* Replace with your application code */
    while (1) 
    {
    }
}

