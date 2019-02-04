/*
 * pov_1.cpp
 *
 * Created: 11/14/2017 7:11:04 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int flag = 0;

void display_first();
void display_second();
int main(void)
{
    DDRB |= 0xFF;
	DDRC |= 0xFF;
	sei();
	TCCR1B |=(1<<CS12)|(1<<CS10);
	TCCR1B |=(1<<WGM12);
	TIMSK|= (1<<OCIE1A);
	OCR1A = 15625*0.1;
    while (1) 
    {
		display_first();
		if (flag == 1){
			display_second();
		}
		
		
		
    }
}
ISR(TIMER1_COMPA_vect){
	flag = 1;
	cli();
}

void display_first(){
	int i;
	int af[]={0x02,0x02,0x02,0x02,0x02,0x02,0x1E};
		for (i=0;i<8;i++){
			PORTB|= af[i];
			_delay_ms(10);
		}
	}
	void display_second(){
		int j;
		int al[]={0x00,0x00,0x00,0x00,0x00,0x00,0x1E};
			for (j=0;j<8;j++){
				PORTC|=al[j];
				_delay_ms(10);
			}
		}