#ifndef COG_H
#define Cog_H

#include <Arduino.h>
#include <Servo.h>
#include "ColorSensor.h"
#include "Configure.h"

class Cog
{
public:
	Cog(byte numRings,byte pinNumber,byte pressure);
	~Cog();
	void dropNextRing();
	byte getNumRings();
  boolean stopDrop();

private:
	//CSensor *colorSensor;
	int numRingsLeft;
	const int rotateVal = 60;
	byte rings;
  byte ringsLeft;
  byte pin;
  Servo servo;
  int pos;
  int nextRing;
  byte pressurePin;

};


#endif
