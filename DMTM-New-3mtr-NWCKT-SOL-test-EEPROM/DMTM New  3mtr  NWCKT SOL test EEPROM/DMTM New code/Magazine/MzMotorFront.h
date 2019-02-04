/* 
* MzMotor.h
*
* Created: 7/14/2017 4:49:32 PM
* Author: Bibek Shrestha
*/


#ifndef __MZMOTORFRONT_H__
#define __MZMOTORFRONT_H__


#include "..\headers.h"
#include "EncoderFront.h"

class MzMotorFront
{
	public:
	char Count;
	int Error;
	volatile bool LimitFlag;
	unsigned int TargetCount;
	EncoderFront Encoder;
	bool VirginityFlag;

	void Initialise();
	void InitInterrupt();
	void SetForwardDirection();
	void SetReverseDirection();
	void StopMotor();
	void MoveUP();
	void MoveD();
	void PreMoveD();

	bool Operate(bool Goflag);


	public:
		MzMotorFront();
		~MzMotorFront();

}; //MzMotor

#endif //__MZMOTORFRONT_H__
