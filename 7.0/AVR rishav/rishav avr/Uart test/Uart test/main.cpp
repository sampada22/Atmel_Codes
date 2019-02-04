/*
 * Uart test.cpp
 *
 * Created: 10/9/2017 10:37:14 AM
 * Author : Sherlock
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "uart.h"

int main(void)

{  DDRD = 0xff;
	 int a =45;
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
	uart_puts("Hello");
	
    while (1) 
    {
    }
}

