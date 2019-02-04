/*
 * LCD and Motorencoder.cpp
 *
 * Created: 10/11/2017 11:54:24 AM
 * Author : Sampada Dhakal
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"

#define F_CPU 16000000UL
/*#define PPR 24
#define BAUD_RATE 9600


volatile long signed count  = 0;
volatile long signed countperSec = 0;
volatile float revperMin = 0;
volatile float revperSec = 0;
volatile float distance =0; 


ISR (INT0_vect){
count++;
}

ISR (TIMER1_COMPA_vect){
	countperSec = count;
    revperSec  = count/PPR;
    revperMin = revperSec*60;  
	lcd_gotoxy(7,2);
	lcd_putint(revperMin);
	//velocity = revperMIn*distance;
	count = 0;
	
	
}*/
int main(void)
{
    lcd_init();
	//sei();
	//DDRD |= (0<<INT0)|(1<<PIND7);
	//TCCR1B |= (1<<CS12)|(1<<CS10);     //set the prescalar to 1024
	//TCCR1B |= (1<<WGM12);              //set the CTC mode
    //TIMSK  |= (1<<OCIE1B);
	//OCR1A  = 15625;
	//MCUCR |= (1<<ISC00)|(1<<ISC01);   // set the INTO to trigger high value
    //GICR |= (1<<INT0); 	
	lcd_gotoxy(5,1);
	lcd_puts("RPM:");
    while (1) 
    {
    }
}


