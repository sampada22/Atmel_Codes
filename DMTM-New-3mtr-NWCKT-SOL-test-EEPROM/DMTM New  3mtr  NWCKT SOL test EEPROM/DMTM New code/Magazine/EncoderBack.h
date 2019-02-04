/*
 * EncoderBack.h
 *
 * Created: 5/27/2017 7:36:01 AM
 *  Author: Rajesh
 */ 


#ifndef ENCODER1_H_
#define ENCODER1_H_



#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "..\headers.h"

#define PPR					180



class EncoderBack
{
  public:
	long Count;
	bool UpFlag;
  
  public:
		void Initialise();				      	
};




#endif /* ENCODERFRONT_H_ */