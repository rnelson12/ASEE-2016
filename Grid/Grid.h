#ifndef GRID_H
#define GRID_H

#include "Sensor.h"
#include <Arduino.h>

class Grid{
  public:
    void begin();
    State calculateTurn();
    State checkLine();
  private:
    static const int numSensors=8;
    Sensor grid[numSensors];
    boolean atIntersection();
    boolean atLeftCorner();
    boolean atRightCorner();
};

#endif
