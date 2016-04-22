#include "SensorGrid.h"

/*
	need to make sure that the first 4 are line followers
	and the rest are the turning calculators.
*/
void SensorGrid::begin(){
  sensorBar=new SensorBar(SENSOR_BAR_ADDRESS);
  sensorBar->setBarStrobe();
  sensorBar->clearInvertBits();
  uint8_t returnStatus=sensorBar->begin();
  if(returnStatus){
    //log("IR Bar communication OK");
  }else{
    //log("IR Bar communication failed :(");
  }
}

SensorGrid::SensorGrid()
{
  //Todo: 
}

SensorGrid::~SensorGrid()
{
}

/*
 * in this method, I may need to have the robot look to see if it is in mid-
 * turn...because it could possibly think that it is at an intersection when
 * in reality it is just turning...
 */
State SensorGrid::calculateTurn(){
  if(atLeftCorner()){
    return TURN_LEFT;
  }else if(atRightCorner()){
    return TURN_RIGHT;
  }else if(atIntersection()){
    //most likly go forward...not sure if it needs to turn or not...
    //this needs to be expanded, there will be turns here too.
    return FORWARD;
  }
  return CONTINUE;
}

/*
	checks to make sure it is still following the line
  returns motorSpeed so I think thats just something that you plug into
  the left or right motors...
*/
int SensorGrid::checkLine(){

    uint8_t raw=sensorBar->getPosition();
    position=0;
    for(byte i=0;i<7;i++){
      if(bitRead(raw,i)){
        position+=10;
      }
    }

    unsigned long now=millis();
    unsigned long timeChange=(now-lastTime);

    error=TARGET-position;
    errSum+=(error*timeChange);
    dErr=(error-lastError)/timeChange;

    lastError=error;
    lastTime=now;
    
    return kp*error+ki*errSum+kd*dErr;
}

/*
	for now, just checking to see if the turning sensors
	are going off...may need to change to check the inner
	linefollowing leds as well.
*/
bool SensorGrid::atIntersection(){
  /*
  if(grid[6].getValue()==BLACK&&grid[7].getValue()==BLACK){
	  return true;
  }
  */
  uint8_t raw=sensorBar->getRaw();
  //should be the very left bit
  if(bitRead(raw,0)&&bitRead(raw,7)){
    return true;
  }
  return false;
}


boolean SensorGrid::atLeftCorner(){
  /*if(grid[6].getValue()==BLACK){
    return true;
  }*/
  if(sensorBar->getPosition()<-50){
    return true;
  }
  return false;
}


boolean SensorGrid::atRightCorner(){
  /*if(grid[7].getValue()==BLACK){
    return true;
  }*/
  if(sensorBar->getPosition()>50){
    return true;
  }
  return false;
}
