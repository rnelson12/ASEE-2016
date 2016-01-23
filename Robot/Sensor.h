#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Types.h"

typedef unsigned char byte;
#define WHITE 42
#define BLACK 1020

class Sensor
{
public:
	Sensor(int pin);
	~Sensor();
	State getValue();

private:
	bool value;
	State convertToBool(int value);
	int pin;
};

#endif
