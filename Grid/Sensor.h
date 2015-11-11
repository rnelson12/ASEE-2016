#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "Types.h"

#define WHITE 42
#define BLACK 1020

class Sensor{
  public:
    Sensor(int pin);
    State getValue();
  private:
  State convertToBool(int value);
  boolean value;
  int pin;
};

#endif
