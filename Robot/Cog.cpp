#include"Cog.h"

Cog::Cog(byte rings,byte pinNumber,byte pressure){
  ringsLeft=rings;
  pin=pinNumber;
  servo.attach(pin);
  //90 is no movment
  nextRing=NEXT_RING;
  pressurePin=pressure;
  //get nextRing from config file
}

void Cog::dropNextRing(){
  //so...If its 180 it will go in full speed in one direction and 0 is 
  //full speed in the other direction
  //It would probably need to write a position then add 90 or 180 or whatever
  //then write it again
  servo.write(200);
  //probably best if the robot is stuck dropping the ring before it moves
  //maybe a forloop waiting for it to finish

  ringsLeft--;
}

byte Cog::getNumRings(){
  return ringsLeft;
}

boolean Cog::stopDrop(){
  if(digitalRead(pressurePin)==HIGH){
    servo.write(0);
    return true;
  }
}

