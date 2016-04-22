#ifndef COG_H
#define Cog_H

#include <Arduino.h>
#include <Servo.h>
#include "ColorSensor.h"
//#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Configure.h"

//typedef unsigned char byte;

class Cog
{
public:
	Cog(byte numRings, byte pinNumberSpiral, byte pinNumberArm);
	~Cog();
	bool dropNextRingLeft();
	bool dropNextRingRight();
	byte getNumRings();
	bool turnArm(int angle);


private:
	int rotationalPosition;
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

};


#endif
