/*
 * SPI_slave_code.cpp
 *
 * Created: 5/5/2018 2:11:32 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"

#define ACK 0x7E
void spi_init_slave(void)
{
	DDRB |= (1<<PINB6); //SET MISO AS OUTPUT
	SPCR |= (1<<SPE);   //ENABLE SPI
	
}
unsigned char spi_tranceiver(unsigned char data){
	SPDR = data;//load data into the buffer
	while(!(SPSR &(1<<SPIF))); //wait until transmission complete
	return (SPDR);
}
int main(void)
{
    lcd_init();
	spi_init_slave();
	unsigned char data, buffer[10];
	DDRA = 0x00;
	PORTA = 0xFF;

    while (1) 
    {
		lcd_puts("Testing");
		lcd_gotoxy(0,1);
		data = spi_tranceiver(ACK);
		lcd_puts(buffer);
		_delay_ms(20);
    }
}

