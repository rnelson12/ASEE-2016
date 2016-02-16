#include "SensorGrid.h"
#include "Sensor.h"

/*
	need to make sure that the first 4 are line followers
	and the rest are the turning calculators.
*/
void SensorGrid::begin(){
  for(byte i=0;i<numSensors;i++){
    grid[i]=Sensor(i);  //may need to change to like i+4
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
*/
State SensorGrid::checkLine(){
  /*
	pin assignments
	0=left outside
    1=left inside
    2=right inside
    3=right outside
	4=back left
	5=back right
	6=left turn sensor
	7=right turn sensor
	need to add support for back line following leds...
	finite adjustments...
   */
	if(grid[0].getValue()==BLACK||grid[2].getValue()==WHITE){
		adjusting=true;
		return ADJUST_LEFT;
   	}else if(grid[3].getValue()==BLACK||grid[1].getValue()==WHITE){
	   	adjusting=true;
	   	return ADJUST_RIGHT;
   	}
   
   	if(adjusting){
		return RETURN_TO_NORMAL;
	}
    return NO_ADJUST;
}

/*
	for now, just checking to see if the turning sensors
	are going off...may need to change to check the inner
	linefollowing leds as well.
*/
bool SensorGrid::atIntersection(){
  if(grid[6].getValue()==BLACK&&grid[7].getValue()==BLACK){
	  return true;
  }
  return false;
}

bool SensorGrid::atLeftCorner(){
  if(grid[6].getValue()==BLACK){
    return true;
  }
  return false;
}

bool SensorGrid::atRightCorner(){
  if(grid[7].getValue()==BLACK){
    return true;
  }
  return false;
}
