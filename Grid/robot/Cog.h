#ifndef COG_h
#define COG_h

#include<Arduino.h>
#include <Servo.h>

class Cog{
  public:
    Cog(byte rings,byte pinNumber);
    void dropNextRing();
    byte getNumRings();
  private:
    byte rings;
    int rotationalPosition;
    byte ringsLeft;
    byte pin;
    Servo servo;
    int pos;
    int nextRing;
};

#endif
