#include <avr/io.h>
#define rps rps

int main(){
	TCCR2 |=(1<<CS20)|(1<<CS22);
	TIMSK |= (1<<OCIE2);
	OCR2 = ((1/rps)/360)*7;
	
}
	ISR(TIMER2_COMP_vect){
		PORTB &= ~0XFF;
		PORTC &= ~0xff;
	}p