/*
 * clock with timer.c
 *
 * Created: 6/8/2017 6:03:37 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL

#define disp PORTB
#define data_dir_LED DDRB 
#define a PINB0 
#define b PINB1 
#define c PINB2 
#define d PINB3 
#define e PINB4 
#define f PINB5 
#define g PINB6 

#define gnd PORTA 
#define  h2 PINA0 
#define h1 PINA1 
#define m2 PINA2 
#define m1 PINA3 
#define s2 PINA4 
#define s1 PINA5 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int hr;
int min;
int sec;

uint16_t count=0;
uint8_t num [10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	
	
int main(){
	TCCR2=(1<<WGM21)|(1<<CS20)|(1<<CS21)|(1<<CS22);                 //set CTC mode and set the prescalar to 1024
	OCR2=156;
	TIMSK=(1<<OCIE2);                                               //enable interrrupt on compare
	sei();                                                          //set the global interrupt
	
	DDRA=0xFF;
	data_dir_LED=0xFF;
	disp=0;
	gnd=0b00111111;
	
	while(1){
		if (sec>59){
			sec=0;
			min++;}
		if (min>59){
			min=0;
			hr++;}	
		if (hr>12){
			hr=1;}
		
		
	if (hr<10){
		disp = num[hr];
		gnd &=~(1<<h1);
		_delay_ms(5);
		gnd|=(1<<h1);
	}
	if (hr>=10){
		disp =num[hr/10];
		gnd &=~(1<<h2);
		_delay_ms(5);
		gnd|=(1<<h2);
		
		disp=num[hr%10];
		gnd &=~(1<<h1);
		_delay_ms(5);
		gnd|=(1<<h1);
	}
	if (min<10){
		disp=num[min];
		gnd &=~(1<<m1);
		_delay_ms(5);
		gnd |=(1<<m1);
	}
	if (min>=10){
		disp=num[min/10];
		gnd  &=~(1<<m2);
		_delay_ms(5);
		gnd |=(1<<m2);
		
		disp=num[min%10];
		gnd &=~(1<<m1);
		_delay_ms(5);
		gnd |=(1<<m1);
	}
	if (sec<10){
		disp=num[sec];
		gnd &=~(1<<s1);
		_delay_ms(5);
		gnd|=(1<<s1);
	}
				 if (sec>=10){
					disp=num[sec/10];
					gnd&=~(1<<s2);
					_delay_ms(5);
					gnd|=(1<<s2);
		
					disp=num[sec%10];
					gnd &=~(1<<s1);
					_delay_ms(5);
					gnd|=(1<<s1);
		
				}
		}
	}
	
	ISR(TIMER2_COMP_vect){
	count++;
	if (count==1){
		sec++;
		count=0;}
	}
	

	
		
		
		
	
	
	
	