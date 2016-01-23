#ifndef SENSORGRID_H
#define SENSORGRID_h

typedef unsigned char byte;


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
	bool atRight();
	byte numSensors;
	Sensor[] sensorArray;
	boolean adjusting;
    static const int numSensors=8;
    Sensor grid[numSensors];
};

#endif