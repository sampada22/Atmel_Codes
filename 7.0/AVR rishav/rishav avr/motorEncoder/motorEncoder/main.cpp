/*
 * motorEncoder.cpp
 *
 * Created: 9/26/2017 2:57:25 PM
 * Author : Rishav 
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"

#define BAUD_RATE 9600
#define PRE_SCALE 256
#define PPR 24

uint16_t counter    = 0;
uint8_t  count      = 0;
uint8_t  revperMin  = 0;
float  countperSec= 0;
	count       = counter;

ISR(TIMER1_OVF_vect){
	//countperSec = count/(0.004096);
// 	revperMin   = ((countperSec/PPR)*60) ;
	uart_putint((count/24)*60);
	uart_puts("\n\r");
	counter     = 0;
	}

ISR(INT0_vect){
	counter++;
}
  
int main(void)
{   
	
	uart_init(UART_BAUD_SELECT(BAUD_RATE,F_CPU));
	
    MCUCR  |= (1<<ISC00)|(1<<ISC01); //Triggering state for Timer0 interrupt 
	MCUCR  |= (0<<ISC10)|(0<<ISC11); //Triggering state for Timer1 interrupt
	MCUCSR |= (0<<ISC2);             //Triggering state for TImer2 interrupt 
	sei();
	GICR |= (1<<INT0);                
	GICR |= (0<<INT1);
	GICR |= (0<<INT2);

    TCCR1B |= (1<<CS12)|(0<<CS11)|(0<<CS10); 
    TIMSK  |= (1<<TOIE1);
    sei();

     while (1) 
    {
    }
}



