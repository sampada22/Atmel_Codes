/*
 * motor_encoder2.cpp
 *
 * Created: 10/9/2017 1:28:04 PM
 * Author : Sampada Dhakal
 */ 

#include <avr/io.h>
#include "uart.h"

#define F_CPU 16000000UL
#define BAUD_RATE 9600


uint8_t count    = 0;
float  revperMin = 0;
float  revperSec = 0;

ISR (INT0_vect){
	count++;
}

ISR (TIMER1_COMPB_vect){
	revperSec = count;
	revperMin = revperSec/60;
	
	uart_putint(revperMin);
	uart_puts("\n");
	count = 0;
}

int main(void)
{
	uart_init(UART_BAUD_SELECT(BAUD_RATE,F_CPU));
	
	GICR |= (1<<INT0)|(1<<INT1);
	MCUCR |= (1<<ISC00)|(1<<ISC01)|(0<<ISC10)|(0<<ISC11); // INT0 for UPPER  edge detection and INT1 for LOWER edge detection
	TCCR1B|= (1<<CS10)|(1<<CS12);   // enabling the timer having prescalar 1024
	OCR1B = 15625;                                                                                                                                                                                                                                                                       ;
	
	while (1)
	{
		
	}
}

