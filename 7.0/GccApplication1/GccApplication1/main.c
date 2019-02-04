/*
 * GccApplication1.c
 *
 * Created: 5/21/2017 3:27:34 PM
 * Author : Sampada_Dhakal
 */
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>



int main(){
	DDRC = 0xff;
	PORTC = 0x00;
	while (1){
	}
}


