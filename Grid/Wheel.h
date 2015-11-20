#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>

class Wheel{

public:
	Wheel(int pin,int wheelOffset);
	void setPower(int power);
private:
	int power;
	int pin;
	int offset;
};

#endif