#ifndef SENSORGRID_H
#define SENSORGRID_h

#include <Arduino.h>
#include "Types.h"
#include "Sensor.h"
#include "Sensorbar.h"
//typedef unsigned char byte;


class SensorGrid
{
public:
	SensorGrid();
	~SensorGrid();
	State calculateTurn();
	State checkLine();
	void begin();

private:
	bool atIntersection();
	bool atLeftCorner();
	bool atRightCorner();
	bool adjusting;
  static const byte numSensors=8;
  Sensor grid[numSensors];
  SensorBar *sensorBar;
};

#endif
