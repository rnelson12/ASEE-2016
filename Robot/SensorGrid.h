#ifndef SensorGrid_h
#define SensorGrid_h

#include <Arduino.h>
#include "Types.h"
#include "Sensorbar.h"
#include "Configure.h"

class SensorGrid
{
public:
	SensorGrid();
	~SensorGrid();
	State calculateTurn();
	State checkLine();

private:
	bool atIntersection();
	bool atLeftCorner();
	bool atRightCorner();
	bool adjusting;
  static const byte numSensors=8;
  SensorBar sensorBar;
  unsigned int position=50;
  unsigned int error=0;
  unsigned int errSum=0;
  unsigned int dErr=0;
  unsigned int lastError=0;
  unsigned int lastTime=0;
};

#endif
