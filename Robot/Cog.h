#ifndef COG_H
#define Cog_H

#include <Arduino.h>
//#include <CSensor.h>
#include <EEPROM.h>
#include <EEPROMAnything.h>

typedef unsigned char byte;

class Cog
{
public:
	Cog(byte numRings);
	~Cog();
	void dropNextRing();

private:
	int rotationalPosition;
	//CSensor *colorSensor;
	int numRingsLeft;
	const int rotateVal = 60;

};


#endif