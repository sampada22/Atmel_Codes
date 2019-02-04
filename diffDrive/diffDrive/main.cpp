/*
 * diffDrive.cpp
 *
 * Created: 2/1/2018 2:28:46 PM
 * Author : Sherlock
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include "headers.h"
#include "Motor.h"
#include "uart.h"

int robotVelocity;
int VelX;
int Yaw;
int V1,V2;
Motor M1,M2;

void initAll(){
	 M1.Initialise(1);
	 M2.Initialise(2);

	 robotVelocity = 100;
	 VelX = 0;
	 Yaw = 0;

	 uart0_init(UART_BAUD_SELECT(38400,F_CPU));
	 sei();

}

void recieveControlCharacter(){
	char data = uart0_getc();

	switch(data){
		case 'F':{
			VelX = robotVelocity;
			Yaw = 0;
			break;
		}

		case 'B':{
			VelX = -robotVelocity;
			Yaw = 0;
			break;
		}
		case 'L':{
			Yaw = robotVelocity;
			VelX = 0;
			break;
		}
		case 'R':{
			 Yaw = -robotVelocity;
			 VelX = 0;
			 break;
		}
		case 'S':{
			Yaw = 0;
			VelX = 0;
			break;
		}
		case 'I':{
			 robotVelocity += 10;

			 break;
		}
		case 'G':{
			 robotVelocity -= 10;

			 break;

		}
		case 'H':{
			robotVelocity -= 10;



	}


}

void updateVelocity(){

	    V1 = 0.5*(VelX+Yaw);
	    V2 = 0.5*(VelX-Yaw);

	    M1.SetOcrValue(V1);
	    M2.SetOcrValue(V2);

}



int main(void)
{
      initAll();




    while (1)
    {

	 recieveControlCharacter();
	 updateVelocity();

    }
}

