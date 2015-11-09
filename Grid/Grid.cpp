#include "Grid.h"
#include "Sensor.h"
#include <Arduino.h>

void Grid::begin(){
  for(byte i=0;i<numSensors;i++){
    grid[i]=Sensor(i);  //may need to change to like i+4
  }
}

/*
 * in this method, I may need to have the robot look to see if it is in mid-
 * turn...because it could possibly think that it is at an intersection when
 * in reality it is just turning...
 */
State Grid::calculateTurn(){
  if(atLeftCorner()){
    return TURN_LEFT;
  }else if(atRightCorner()){
    return TURN_RIGHT;
  }else if(atIntersection()){
    //most likly go forward...not sure if it needs to turn or not...
    return FORWARD;
  }
  return CONTINUE;
}

State Grid::checkLine(){
  /*0=left outside
   * 1=left inside
   * 2=right inside
   * 3=right outside
   */
   if(grid[1].getValue()==BLACK&&grid[2].getValue()==BLACK){
    //should be centered on line...don't think I even need this...
    return NO_ADJUST;
   }else if(grid[0].getValue()==BLACK||grid[2].getValue()==WHITE){
    return ADJUST_LEFT;
   }else if(grid[3].getValue()==BLACK||grid[1].getValue()==WHITE){
    return ADJUST_RIGHT;
   }
   return NO_ADJUST;
}

boolean Grid::atIntersection(){
  for(byte i=0;i<numSensors;i++){
    if(grid[i].getValue()==WHITE){
      return false;
    }
  }
  return true;
}

boolean Grid::atLeftCorner(){
  if(grid[0].getValue()==BLACK){
    return true;
  }
  return false;
}

boolean Grid::atRightCorner(){
  if(grid[3].getValue()==BLACK){
    return true;
  }
  return false;
}
