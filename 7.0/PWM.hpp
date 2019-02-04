/*
 * PWM.h
 *
 * Created: 3/7/2018 5:10:52 PM
 *  Author: RMS
 *   email: 073bex433.rishav@gmail.com
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "basics/AVR.hpp"
#include "PWM_Params.hpp"

class CTC
{
	public:
	template <u8 channel>
	void set_duty_cycle(const PWM_Params & pwm_ , const u16 duty_cycle){
		/*static_assert(channel == 0, "DutyCycle is 50% by default for CTC mode.");*/
	}
	protected:
	private:
};


template <class Mode>
class HardwarePWM
{
private:
	PWM_Params pwm_;

public:
	
	template <typename T, size_t N>
	HardwarePWM(T(&arr)[N]): pwm_(arr){}		
	
	void initialize() const {
		Mode::initialize();
	}
	void setPreScale(){
		Mode::setPreScale();
	}
	void setPin(const u8 pin){
		pinMode(pin, DDR::OUTPUT);
	}
	
	template <u8 channel>
	void set_duty_cycle(const u16 duty_cycle){
		Mode::set_duty_cycle<channel>(pwm_, duty_cycle);
	}
 	void setFrequency(){
		Mode::setFrequency();
	}
	
};

// class Fast_PWM
// {
// public:
// 	u8 initialize(const PWM_Params & pwm_ ) const{
// 		*(pwm_.tccra_) |= _bv(WGM11);
// 		*(pwm_.tccrb)  |= _bv(WGM13) | _bv(WGM12);
// 	}
// protected:
// private:
// };



class Phase_PWM
{
public:
	void initialize(const PWM_Params & pwm_ ) const{
    *(pwm_.tccra_) |= _bv(WGM11);
	*(pwm_.tccrb_)  |= _bv(WGM13);		
	}
			
	void setPreScale(u16 setValue, const PWM_Params & pwm_){
		u16 preScale = setValue;
		switch (setValue)
		{
		case 0:
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx0)| _bv(PWM::csx1)| _bv(PWM::csx2));
			 break;
		
		case 1:
			*(pwm_.tccrb_) |= _bv(PWM::csx0);
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx1)|_bv(PWM::csx2));
			break;
		
		case 8:
			*(pwm_.tccrb_) |= _bv(PWM::csx1);
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx0)|_bv(PWM::csx2));
			break;
		
		case 64:
			*(pwm_.tccrb_) |= _bv(PWM::csx0)|_bv(PWM::csx1);
			*(pwm_.tccrb_) &= ~_bv(PWM::csx2);
			break;
		
		case 256:
			*(pwm_.tccrb_) |= _bv(PWM::csx2);
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx0)|_bv(PWM::csx1));
			break;
		
		case 1024:
			*(pwm_.tccrb_) |= _bv(PWM::csx0)|_bv(PWM::csx2);
			*(pwm_.tccrb_) &= ~ _bv(PWM::csx1);
			break;
		
		}
	}
	
	
// 	void setPin(const PWM_Params & pwm_){
// 		switch (ocx)
// 		{
// 		case  :
// 			*(pwm_.tccra_) |= _bv(PWM::comxa1);
// 			*(pwm_.tccra_) &= ~(_bv(PWM::comxa0));
// 			break;
// 		
// 		case 'B' :
// 			*(pwm_.tccra_) |= _bv(PWM::comxb1);
// 			*(pwm_.tccra_) &= ~(_bv(PWM::comxb0));
// 			break;			
// 					
// 		case 'C' :
// 			*(pwm_.tccra_) |= _bv(PWM::comxc1);
// 			*(pwm_.tccra_) &= ~(_bv(PWM::comxc0));
// 			break;				
// 		}
// 	}
	
	void setDutyCycle(u16 setValue, const PWM_Params & pwm_,u8 channel ){
		*(pwm_.ocrha_) = u8(setValue>>8);
		*(pwm_.ocrla_) = u8(setValue); 
	}
	
	void setFrequency(u16 setValue, const PWM_Params & pwm_){
		
		u16 icrValue = (F_CPU/(setValue*preScale)-1);
		*(pwm_.icrh_) = u8(icrValue>>8);
		*(pwm_.icrl_) = u8(icrValue);
	}
		
protected:
private:
	
};

class Fast_PWM
{
	public:
	void initialize(const PWM_Params & pwm_ ) const{
		*(pwm_.tccra_) |= _bv(PWM::wgmx1);
		*(pwm_.tccra_) &= ~_bv(PWM::wgmx0);
		*(pwm_.tccrb_) |= _bv(PWM::wgmx2) | _bv(PWM::wgmx3);
	}
	
	void setPreScale(u16 setValue, const PWM_Params & pwm_){
		u16 preScale = setValue;
		switch (setValue)
		{
			case 0:
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx0)| _bv(PWM::csx1)| _bv(PWM::csx2));
			break;
			
			case 1:
			*(pwm_.tccrb_) |= _bv(PWM::csx0);
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx1)|_bv(PWM::csx2));
			break;
			
			case 8:
			*(pwm_.tccrb_) |= _bv(PWM::csx1);
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx0)|_bv(PWM::csx2));
			break;
			
			case 64:
			*(pwm_.tccrb_) |= _bv(PWM::csx0)|_bv(PWM::csx1);
			*(pwm_.tccrb_) &= ~_bv(PWM::csx2);
			break;
			
			case 256:
			*(pwm_.tccrb_) |= _bv(PWM::csx2);
			*(pwm_.tccrb_) &= ~(_bv(PWM::csx0)|_bv(PWM::csx1));
			break;
			
			case 1024:
			*(pwm_.tccrb_) |= _bv(PWM::csx0)|_bv(PWM::csx2);
			*(pwm_.tccrb_) &= ~ _bv(PWM::csx1);
			break;
			
		}
	}
					
					
					
#endif /* PWM_H_ */					
					
								