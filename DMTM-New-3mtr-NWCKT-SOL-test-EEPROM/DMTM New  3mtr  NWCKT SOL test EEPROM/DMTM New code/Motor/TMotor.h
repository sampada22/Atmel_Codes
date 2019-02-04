/* 
* TMotor.h
*
* Created: 6/9/2017 6:26:17 PM
* Author: Bibek Shrestha
*/


#ifndef __TMOTOR_H__
#define __TMOTOR_H__



#include <avr/io.h>
#include <avr/interrupt.h>
#include "..\headers.h"


#ifndef __TMOTOR_LIMIT_STATUS__
#define __TMOTOR_LIMIT_STATUS__
	
	#define MIDBACKPOSITION		5
	#define HOMEPOSITION		6
	#define MIDPOSITION			7
	#define UPPOSITION			8
	#define NONPOSITION			0


	#define GOING_UP			1
	#define GOING_MID			2
	#define GOING_HOME			3
	#define GOING_MID_BACK		4
	#define NOTGOINGANYWHERE	0

#endif






class TMotor
{
		public:

		uint16_t Ocr;
		bool LastState;
		volatile bool LimitFlag;
		volatile bool ChangeFlag;
		 
		volatile char Position;
		volatile char Status;
		
		bool ReadyFlag;		
	
		bool ShouldStop;
		bool EnableControl;


		void DoNothing();
		
		void UpdateStatus();
		void ProcessInput(unsigned char);
		void ControlLogic();
			
		void Initialise();
		
		void InitLimitSwitch();
		void SetForwardDirection();
		void SetReverseDirection();
		void StopMotor();
		void MoveForward();
		void MoveBackward();
		

		
		bool Operate(unsigned char Rx);
		
}; //TMotor

#endif //__TMOTOR_H__
