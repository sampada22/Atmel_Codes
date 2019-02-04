/* 
* MotorSide.h
*
* Created: 7/21/2017 6:32:55 PM
* Author: Bibek Shrestha
*/


#ifndef __SIDEMOTOR_H__
#define __SIDEMOTOR_H__





#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "..\headers.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#include "..\PID.h"


class MotorSide
{
	
	
	public:
	
	int16_t Ocr;
	bool IntFlag;
	bool LowSpeedFlag;
	uint8_t TimerPrescalar;
	unsigned int Count;

	uint16_t RPM;
	
	
	uint16_t LastRPM;
	uint8_t Overflow;
	int16_t OCR;

	PID Controller;


	void ClearCounter();
	void Initialise();
	void InitCounter();
	void InitPWM();
	void InitInterrupt();
	void InitController();
	void SetForwardDirection();
	void SetReverseDirection();
	void StopMotor();
	void SetOcrValue(int x);
	void IncreaseSpeed();
	void DecreaseSpeed();
	bool Operate(unsigned char &rx, unsigned char &Command);

};

#endif //__SIDEMOTOR_H__
