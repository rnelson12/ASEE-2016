#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>

class Wheel{
public:
	Wheel(int pinNumber,int wheelOffset);
	void setPower(int pwr);
private:
	int power;
	int pin;
	int offset;
};

#endif
