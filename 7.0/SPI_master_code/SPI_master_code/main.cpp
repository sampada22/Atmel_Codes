/*
 * SPI_master_code.cpp
 *
 * Created: 5/5/2018 1:56:19 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ACK 0x7E
#define LONG_TIME 10000

void spi_init_master(void){
	DDRB|=(1<<PINB5)|(1<<PINB7); //TO SET MOSI AND SCK AS OUTPUT
	SPCR |=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);//ENABLE SPI,SET IT AS MASTER, PRESCALAR = 16, ENABLE INTERRUPTS
	sei(); //set the global interrupts
}

unsigned char spi_tranceiver(unsigned char data){
	SPDR = data;//load data into the buffer
	while(!(SPSR &(1<<SPIF))); //wait until transmission complete
	return (SPDR);
}

void led_blink(uint16_t){
	for(;i>0;--i){
		PORTD |= (1<<PIND0);
		_delay_ms(100);
		PORTD |= (0<<PIND0);
		_delay_ms(100);
	}
}
int main(void)
{
    spi_init_master();
	DDRD |= 0x01;
	
	unsigned char data;
	uint8_t x =0;
	
    while (1) 
    {
		data = 0x00;
		data = spi_tranceiver(++x);
		if (data == ACK){
			led_blink(x);
		}
		else {
			led_blink(LONG_TIME);
		}
		_delay_ms(500);
    }
}

