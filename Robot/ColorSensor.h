#ifndef COLORSENSOR_H
#define COLORSENSOR_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Types.h"

//typedef unsigned char byte;
class ColorSensor
{
public:
	ColorSensor();
	~ColorSensor();
	bool isRed();
private:
	const int redComparisonValue = 0; //Todo: Change value to actual value
};

#endif
