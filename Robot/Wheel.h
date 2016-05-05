#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>

typedef unsigned char byte;

class Wheel
{
public:
	Wheel(byte motorForward, byte motorBackward, byte radius, byte power);
	~Wheel();
	void setPower(byte powerValue,bool forward);//1 forward, 0 backward
	int calculateDistance();
private:
	byte _radius;
	byte _power;
	byte _motorPinForward;
	byte _motorPinBackward;

};



#endif // !WHEEL_H
