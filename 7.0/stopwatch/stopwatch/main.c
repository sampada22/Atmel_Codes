/*
 * stopwatch.c
 *
 * Created: 6/13/2017 5:00:11 AM
 * Author : Sampada Dhakal
 */ 


#define F_CPU 16000000UL

#define disp PORTB

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

#define reset PIND2
#define button PIND3 
#define count_speed 1
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void display_time();
void display_stwatch();
void update_time();
void update_stwatch();

int hr;
int min;
int sec;
int sw_hr;
int sw_min;
int sw_sec;

uint16_t count=0;
uint16_t sw_count=0;
uint8_t num [10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
uint8_t select =1;
	
	
int main(){
	TCCR2=(1<<WGM21)|(1<<CS20)|(1<<CS21)|(1<<CS22);                 //set CTC mode and set the prescalar to 1024
	OCR2=156;
	TIMSK=(1<<OCIE2);                                               //enable interrupt on compare
	sei();                                                          //set the global interrupt
	GICR |=(1<<INT0)|(1<<INT1);                                     //set the external interrupts
	DDRD=0x00;    
	DDRA=0xFF;
	DDRB=0xFF;
	disp=0;
	gnd=0b00111111;
	
	while(1){
		if (select){
			display_time();
		}
		else{
		update_stwatch();	
	}
}
}
	ISR(TIMER2_COMP_vect){
	if (select){
		update_time();
	}
	else {
		update_time();
		update_stwatch();
	}
	}
// 	ISR(INT0_vect){
// 		
// 	hr=0;
// 	min=0;
// 	sec=0;
// 	disp=num[sec];	
// 		
// 	}
  	ISR(INT1_vect){
	 		if(select){
				 update_time();
				 
			 }
			else{
				update_time();
				update_stwatch();
			 
	 	 		
	 	 	}
	  }
	void update_time(){
		count++;
		if (count>=count_speed){
			
		sec++;
		}
		if (sec>59){
			sec=0;
		min++;}
		if (min>59){
			min=0;
		hr++;}
		if (hr>12){
		hr=1;}
		
	}
	void update_stwatch(){
		sw_count++;
		if (sw_count>=count_speed){
			sw_sec++;
		}
		if (sw_sec>59){
			sw_sec=0;
		min++;}
		if (sw_min>59){
			sw_min=0;
		sw_hr++;}
		if (sw_hr>12){
		sw_hr=1;}
	}
	void display_time(){
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
		void display_stwatch(){
			if (sw_hr<10){
				disp = num[sw_hr];
				gnd &=~(1<<h1);
				_delay_ms(5);
				gnd|=(1<<h1);
			}
			if (sw_hr>=10){
				disp =num[sw_hr/10];
				gnd &=~(1<<h2);
				_delay_ms(5);
				gnd|=(1<<h2);
				
				disp=num[sw_hr%10];
				gnd &=~(1<<h1);
				_delay_ms(5);
				gnd|=(1<<h1);
			}
			if (sw_min<10){
				disp=num[sw_min];
				gnd &=~(1<<m1);
				_delay_ms(5);
				gnd |=(1<<m1);
			}
			if (sw_min>=10){
				disp=num[sw_min/10];
				gnd  &=~(1<<m2);
				_delay_ms(5);
				gnd |=(1<<m2);
				
				disp=num[sw_min%10];
				gnd &=~(1<<m1);
				_delay_ms(5);
				gnd |=(1<<m1);
			}
			if (sw_sec<10){
				disp=num[sw_sec];
				gnd &=~(1<<s1);
				_delay_ms(5);
				gnd|=(1<<s1);
			}
			if (sw_sec>=10){
				disp=num[sw_sec/10];
				gnd&=~(1<<s2);
				_delay_ms(5);
				gnd|=(1<<s2);
				
				disp=num[sw_sec%10];
				gnd &=~(1<<s1);
				_delay_ms(5);
				gnd|=(1<<s1);
			}
		}