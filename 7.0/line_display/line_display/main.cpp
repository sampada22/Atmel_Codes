/*
 * line_display.cpp
 *
 * Created: 11/12/2017 4:05:59 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main(){
	DDRB   = 0x0F;
	DDRC = 0xFF;
	PORTB  = 0x06;
	PORTB = 0x46;
	 
// 	int i;
// 	int af[] = {0x1E,0x02,0x02,0x02,0x02};
// 	int al[] = {0b0011110,0b0000000,0b0000000,0b0000000,0b0000000};	
// 	DDRB |= 0xFF;
// 	DDRC|= 0xFF;
// 	while (1){
// 		for (i=0;i<5;i++){
// 			PORTB =af[i];
// 		
// 			PORTC = al[i]; 
// 			_delay_ms(200);
// 			}
// 	}
// 	
 }