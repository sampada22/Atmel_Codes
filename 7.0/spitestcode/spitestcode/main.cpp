/*
 * spitestcode.cpp
 *
 * Created: 5/5/2018 1:20:34 PM
 * Author : Sampada Dhakal
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

void spi_init_master(void){
	DDRB|=(1<<PINB5)|(1<<PINB7); //TO SET MOSI AND SCK AS OUTPUT
	SPCR |=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);//ENABLE SPI,SET IT AS MASTER, PRESCALAR = 16, ENABLE INTERRUPTS
	sei(); //set the global interrupts
	
}
void spi_init_slave(void){
	DDRB |= (1<<PINB6); //SET MISO AS OUTPUT
	SPCR |= (1<<SPE);   //ENABLE SPI
	
}
unsigned char spi_tranceiver(unsigned char data){
	SPDR = data;//load data into the buffer
	while(!(SPSR &(1<<SPIF))); //wait until transmission complete
	return (SPDR);
}