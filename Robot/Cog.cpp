#include"Cog.h"

Cog::Cog(byte numRings, byte pinNumberSpiral, byte pinNumberArm, byte pressure){
  ringsStarted = numRings;
  ringsRemaining = numRIngs;
  armPin = pinNumberArm;
  spiralPin = pinNumberSpiral;
  arm.attach(armPin);
  spiral.attach(spiralPin);
  //90 is no movment
  nextRing=NEXT_RING;
  pressurePin = pressure;
  //get nextRing from config file
}

void Cog::dropNextRing(){
  //so...If its 180 it will go in full speed in one direction and 0 is 
  //full speed in the other direction
  //It would probably need to write a position then add 90 or 180 or whatever
  //then write it again
	//TODO: continuous servos are done by time
  spiral.write(pos);
  pos+=90;
  spiral.write(200);
  //probably best if the robot is stuck dropping the ring before it moves
  //maybe a forloop waiting for it to finish

  ringsRemaining--;
  //return true;
}

byte Cog::getNumRings(){
  return (ringsRemaining);
}

bool Cog::stopDrop(){
  if(digitalRead(pressurePin)==HIGH){
    servo.write(0);
    return true;
  }
}

bool Cog::turnArm(int angle){
  
}
 
