#ifndef COLORSENSOR_H
#define COLORSENSOR_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Types.h"
#include "SparkFunISL29125.h"
#include "Configure.h"

//typedef unsigned char byte;
class ColorSensor
{
public:
	ColorSensor();
	~ColorSensor();
	bool isRed();
private:
	const int redComparisonValue = 0; //Todo: Change value to actual value
  SFE_ISL29125 RGB_sensor;
};

#endif
