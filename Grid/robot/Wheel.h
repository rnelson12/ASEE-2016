#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>

class Wheel{
public:
	Wheel(int forwardPin,int backPin,int wheelOffset);
	void setPower(int pwr);
private:
	int power;
	int pin;
  int reversePin;
	int offset;
};

#endif
