/* 
* MzMotorBack.h
*
* Created: 7/15/2017 8:27:19 AM
* Author: Bibek Shrestha
*/


#ifndef __MZMOTORBACK_H__
#define __MZMOTORBACK_H__


#include "..\headers.h"
#include "EncoderBack.h"

class MzMotorBack
{
	public:
	EncoderBack Encoder;
	
	char Count;
	volatile bool LimitFlag;
	unsigned int TargetCount;
	int Error;
	bool VirginityFlag;

	void Initialise();
	void InitInterrupt();
	void SetForwardDirection();
	void SetReverseDirection();
	void StopMotor();
	void MoveUP();
	void MoveD();
	void PreMoveD();

	bool Operate(bool GoFlag);


	public:
	MzMotorBack();
	~MzMotorBack();

}; //MzMotorBack

#endif //__MZMOTORBACK_H__
