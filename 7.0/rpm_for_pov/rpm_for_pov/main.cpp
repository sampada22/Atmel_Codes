/*
 * rpm_for_pov.cpp
 *
 * Created: 11/22/2017 7:37:58 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
uint16_t count = 0;
uint16_t sec = 0;
int rps;

#define LED1 PINB1
#define LED2 PINB2
#define LED3 PINB3
#define LED4 PINB4
#define LED5 PINC4
#define LED6 PINC3
#define LED7 PINC2
#define LED8 PINC1


int main(void)
{
	DDRB |=0xFF;
	DDRC |= 0xFF;
	DDRD |= 0x20;
	PORTD |= 0x20;
    sei();
	TCCR1B |= (1<<CS12)|(1<<CS10);
	TCCR1B |= (1<<WGM12);
	TIMSK |= (1<<TOIE1);
	OCR1A = 15625;
	MCUCR |= (1<<ISC10)|(1<<ISC11);
	GICR |= (1<<INT1);
	
    while (1) 
    {
		PORTC |= (0<<PINC1);
		if (rps == 1){
			PORTB |= (1<<PINB1);
		}
		if (rps == 2){
			PORTB |= (1<<PINB2);
		}
		if (rps == 3){
			PORTB |= (1<<PINB3);
		}
		if (rps == 4){
			PORTB |= (1<<PINB4);
		}
		if (rps == 5){
			PORTC |=(1<<PINC4);
		}
		if (rps == 6){
			PORTC |= (1<<PINC3);
		}
		if (rps == 7){
			PORTC |= (1<<PINC2);
		}
		if (rps ==8){
			PORTC |=(1<<PINC1);
		}
    }
}
ISR (INT1_vect){
	PORTC|= (1<<PINC2);
	_delay_ms (100);
	PORTC &= ~(1<<PINC2);
 		count ++;
 	//if (TCNT1 == 15625){
  	//rps = count;
	//TCNT1 == 0;
//}
	
	// if (rps == 9){
		// PORTB 
	 //}
}
//}
ISR (TIMER1_OVF_vect){
	rps = count;
}