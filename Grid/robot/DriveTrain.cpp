#include "DriveTrain.h"

DriveTrain::DriveTrain(int defaultLeftPower,int defaultRightPower){
  rightPower=defaultRightPower;
  leftPower=defaultLeftPower;
  left(LEFT_WHEEL_PIN,LEFT_WHEEL_OFFSET);
  right(RIGHT_WHEEL_PIN,RIGHT_WHEEL_OFFSET);
}

void DriveTrain::drive(int power, State direction){
  
}

