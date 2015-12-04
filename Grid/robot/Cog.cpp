#include"Cog.h"

Cog::Cog(byte rings,byte pinNumber){
  ringsLeft=rings;
  pin=pinNumber;
  servo.attach(pin);
  pos=0;
  //get nextRing from config file
}

void Cog::dropNextRing(){
  //I think I need to check to see if it is over 360 first...
  pos+=nextRing;
  servo.write(pos);
}

byte Cog::getNumRings(){
  return ringsLeft;
}

