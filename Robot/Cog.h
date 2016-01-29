#ifndef COG_H
#define Cog_H

#include <Arduino.h>
#include <Servo.h>
//#include <CSensor.h>
//#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Configure.h"

//typedef unsigned char byte;

class Cog
{
public:
	Cog(byte numRings,byte pinNumber);
	~Cog();
	void dropNextRing();
	byte getNumRings();

private:
	int rotationalPosition;
	//CSensor *colorSensor;
	int numRingsLeft;
	const int rotateVal = 60;
	byte rings;
    byte ringsLeft;
    byte pin;
    Servo servo;
    int pos;
    int nextRing;

};


#endif
