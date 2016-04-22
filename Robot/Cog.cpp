#include"Cog.h"

Cog::Cog(byte numRings, byte pinNumberSpiral, byte pinNumberArm){
  ringsStarted = numRings;
  armPin = pinNumberArm;
  spiralPin = pinNumberSpiral;
  arm.attach(armPin);
  rightArm.attach(rightArmPin);
  leftSpiral.attach(leftSpiralPin);
  rightSpiral.attach(rightSpiralPin);
  //90 is no movment
  pos=90;
  nextRing=NEXT_RING;
  //get nextRing from config file
}

bool Cog::dropNextRingLeft(){
  //so...If its 180 it will go in full speed in one direction and 0 is 
  //full speed in the other direction
  //It would probably need to write a position then add 90 or 180 or whatever
  //then write it again
	//TODO: continuous servos are done by time
  leftSpiral.write(pos);
  pos+=90;
  //probably best if the robot is stuck dropping the ring before it moves
  //maybe a forloop waiting for it to finish

  ringsRemainingLeft--;
  return true;
}

bool Cog::dropNextRingRight() {
	//so...If its 180 it will go in full speed in one direction and 0 is 
	//full speed in the other direction
	//It would probably need to write a position then add 90 or 180 or whatever
	//then write it again
	//Todo: continous servos done by time
	rightSpiral.write(pos);
	pos += 90;
	//probably best if the robot is stuck dropping the ring before it moves
	//maybe a forloop waiting for it to finish

	ringsRemainingRight--;
	return true;
}

byte Cog::getNumRings(){
  return (ringsRemainingLeft + ringsRemainingRight);
}
