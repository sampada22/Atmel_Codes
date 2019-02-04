/*
 * Compass.cpp
 *
 * Created: 1/10/2018 8:22:09 PM
 * Author : Prakash Chaudhary
 */ 
#include <ctype.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "Compass.h"

Compass C1;

int main(void)
{
	uint8_t Quotient = 0, Remainder = 0;
	
	sei();
	uart0_init(UART_BAUD_SELECT(38400,F_CPU));
	C1.init_compass();
    /* Replace with your application code */
    while (1) 
    {
		C1.read_Compass();
		Quotient = C1.Angle/10;
		Remainder = C1.Angle%10;
		uart0_putc(Quotient);
    }
}