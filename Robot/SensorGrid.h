#ifndef SENSORGRID_H
#define SENSORGRID_h

#include <Arduino.h>
#include "Types.h"
#include "Sensorbar.h"
#include "Configure.h"
//typedef unsigned char byte;

class SensorGrid
{
public:
	SensorGrid();
	~SensorGrid();
	State calculateTurn();
	int checkLine();
	void begin();

private:
	bool atIntersection();
	bool atLeftCorner();
	bool atRightCorner();
	bool adjusting;
  static const byte numSensors=8;
  SensorBar *sensorBar;
  unsigned int position=50;
  unsigned int error=0;
  unsigned int errSum=0;
  unsigned int dErr=0;
  unsigned int lastError=0;
  unsigned int lastTime=0;
};

#endif
