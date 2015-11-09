#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "Types.h"
class Sensor{
  public:
    Sensor(int pin);
    State getValue();
  private:
  State convertToBool(int pin);
  boolean value;
  int pin;
};

#endif
