/*
 * micros().cpp
 *
 * Created: 3/8/2018 8:52:25 AM
 * Author : Sampada Dhakal
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

class SystemTime{
	private:
	unsigned long ovfCount = 0;
	
	public:
	SystemTime();
	void Overflow();
	uint32_t Micro();
	void Reset();
	};
	
	SystemTime::SystemTime(){
		TCCR0B |=(0<<CS00)|(1<<CS01)|(0<<CS02); //set the pre-scale to 8
		TIMSK0 |=(1<<TOIE0); // enable the overflow interrupt
		sei();  //enable global interrupts
	}
	
	void SystemTime::Overflow(){
		this->ovfCount++;    //increase the overflow count
	}
	void SystemTime::Reset(){
		this->ovfCount = 0;
		TCNT0 = 0;         
	}
	
	uint32_t SystemTime::Micro(){
		uint32_t t;
		t = (TCNT0*0.5)+((this->ovfCount*255)*0.5);
		return t;
	}
	SystemTime sysTime;
	
	ISR(TIMER0_OVF_vect){
		sysTime.Overflow();
	}
	