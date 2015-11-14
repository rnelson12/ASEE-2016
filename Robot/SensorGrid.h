#ifndef SENSORGRID_H
#define SENSORGRID_h

typedef unsigned char byte;


class SensorGrid
{
public:
	SensorGrid();
	~SensorGrid();
	enum calculateTurn();

private:
	bool atIntersection();
	bool atLeftCorner();
	bool atRight();
	byte numSensors;
	Sensor[] sensorArray;
};

#endif