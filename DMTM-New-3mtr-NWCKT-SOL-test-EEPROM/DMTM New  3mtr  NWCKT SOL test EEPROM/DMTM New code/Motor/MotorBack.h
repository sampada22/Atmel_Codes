/*
 * starter.h
 *
 * Created: 2/11/2017 9:47:14 PM
 *  Author: asus
 */ 


#ifndef MOTORA_H_
#define MOTORA_H_

#include "..\headers.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#include "..\PID.h"


class MotorBack 
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



#endif /* STARTER_H_ */