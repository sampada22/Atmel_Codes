/* 
* MotorFront.h
*
* Created: 2/18/2017 3:52:15 PM
* Author: Bibek Shrestha
*/


#ifndef __MOTORB_H__
#define __MOTORB_H__

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#include "..\headers.h"


#include "..\PID.h"

class MotorFront 
{
	
	private:
	public:
	int16_t Ocr;
	bool IntFlag;
	bool LowSpeedFlag;
	unsigned int Count;
	uint16_t RPM;
	uint16_t LastRPM;
	uint8_t Overflow;
	PID Controller;

	void ClearCounter();
	void Initialise();
	void InitCounter();
	void InitInterrupt();
	void InitPWM();
	void InitController();
	void SetForwardDirection();
	void SetReverseDirection();
	void StopMotor();
	void SetOcrValue(int x);
	void IncreaseSpeed();
	void DecreaseSpeed();
	bool Operate(unsigned char &rx, unsigned char &Command);

}; //MotorFront

#endif //__MOTORB_H__
