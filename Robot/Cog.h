#ifndef COG_H
#define Cog_H

#include <Arduino.h>
#include <Servo.h>
#include "ColorSensor.h"
#include "Configure.h"

class Cog
{
public:
	Cog(byte numRings, byte pinNumberSpiral, byte pinNumberArm, byte pressure);
	void dropNextRing();
	byte getNumRings();
	bool turnArm(int angle);
  bool stopDrop();

private:
	//CSensor *colorSensor;
	int numRingsLeft;
	const int rotateVal = 60;
	byte ringsStarted;
  byte ringsRemaining;
  byte armPin;
	byte spiralPin;
  Servo arm;
	Servo spiral;
  int pos;
  int nextRing;
  byte pressurePin;
};


#endif
