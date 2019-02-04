/*
 * compasssss.cpp
 *
 * Created: 2/1/2018 12:51:20 PM
 * Author : Sampada Dhakal
 */ 

#include <avr/io.h>
#include "TWI.h"
#include "uart.h"

#define writeAddress 0x3C
#define readAddress 0x3D

class Compass{
	private:
	int16_t rawX;
	int16_t rawY;
	int16_t rawZ;
	uint16_t angle;
	
	public:
	Compass(void);
	void initCompass();
	void readCompass();
	 int16_t readRawX(void){return rawX;}
	 int16_t readRawY(void){return rawY;}
	int16_t getAngle(void){return angle;}	 
	};
	
	Compass::Compass(void){
	i2c_init();
	rawX = 0;
	rawY = 0;
	angle = 0;
	
	}
	
	void Compass::initCompass(void){
	i2c_start(writeAddress);
	i2c_write(0x00);    //pointer to address of configuration register A
	i2c_write(0x70);    //DO2=1,DO1=0,DO0=0=>data otuput rate=15Hz,  MA0 =1,MA1=1=>8 samples per measurement output 
	i2c_stop();	
	
	i2c_start(writeAddress);
	i2c_write(0x01);   //pointer to address of configuration register B
	i2c_write(0xA0);   
	i2c_stop();
	
	i2c_start(writeAddress);
	i2c_write(0x02);    //pointer to address of Mode register
	i2c_write(0x00);    //continuous measurement mode
	i2c_stop();
		
	}
	
	void Compass::readCompass(void){
		i2c_start(writeAddress);
		i2c_write(0x03);    //pointer to data output X MSB register
		i2c_stop();
		i2c_rep_start(readAddress);
		
		rawX = ((uint8_t)i2c_readAck())<<8|i2c_readAck();
		rawY = ((uint8_t)i2c_readAck())<<8|i2c_readNak();
		i2c_stop();
		
		angle = (atan((double)rawY,(double)rawX)*180/3.14159265+180.0);
		
		
		
	}
	
	

int main(void)
{
Compass C1;
  uint8_t quotient = 0;
  uint8_t remainder = 0;
  sei();
  uart0_init(UART_BAUD_SELECT(38400,F_CPU));
  C1.initCompass();
    while (1) 
    {
		C1.readCompass();
		quotient = C1.angle/10;
		remainder = C1.angle%10;
		uart0_putc(quotient);
    }
}

