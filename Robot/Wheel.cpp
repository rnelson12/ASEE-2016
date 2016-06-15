#include "Wheel.h"

Wheel::Wheel(byte motorForward, byte motorBackward, byte radius, byte power)
{
	_motorPinForward = motorForward;
	_motorPinBackward = motorBackward;
	_radius = radius;
	_power = power;
}

Wheel::~Wheel()
{
}

void Wheel::setPower(byte powerValue,bool forward)
{
  byte power=map(powerValue,0,100,0,225);
	_power = powerValue;
  if(forward){
    analogWrite(_motorPinForward,power);
  }else{
    analogWrite(_motorPinBackward,power);
  }
}

int Wheel::calculateDistance()
{
	return 0;
}
