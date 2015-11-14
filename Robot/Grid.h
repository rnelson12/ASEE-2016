#ifndef GRID_H
#define GRID_h

typedef unsigned char byte;

#include "Sensor.h"
#include <Arduino.h>
#include "Types.h"

class Grid
{
public:
	Grid();
	~Grid();
	void begin();
	State calculateTurn();
	State checkLine();

private:
	bool atIntersection();
	bool atLeftCorner();
	bool atRightcorner();
	byte numSensors;
	Sensor grid[numSensors];
	bool adjusting;
};

#endif