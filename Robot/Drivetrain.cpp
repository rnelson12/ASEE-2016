#include "DriveTrain.h"

DriveTrain::DriveTrain(int defaultLeftPower,int defaultRightPower){
  rightPower=defaultRightPower;
  leftPower=defaultLeftPower;
  left=new Wheel(LEFT_WHEEL_PIN,LEFT_REVERSE_PIN,LEFT_WHEEL_OFFSET,LEFT_MOTOR_POWER);
  right=new Wheel(RIGHT_WHEEL_PIN,RIGHT_REVERSE_PIN,RIGHT_WHEEL_OFFSET,RIGHT_MOTOR_POWER);
  sensorBar=new SensorBar(SENSOR_BAR_ADDRESS);
}

void DriveTrain::drive(byte power, State direction){
  if(direction==TURN_LEFT){
    right->setPower(power);
    left->setPower(-power);
  }else if(direction==TURN_RIGHT){
    left->setPower(power);
    right->setPower(-power);
  }else if(direction==FORWARD){
    right->setPower(power);
    left->setPower(power); //probably need to either have a set direction
    //or make this a signed int so negative is in the oposite direction
  }else if(direction==ADJUST_LEFT){
    right->setPower(power+RIGHT_ADJUSTMENT);
    left->setPower(power);
  }else if(direction==ADJUST_RIGHT){
    right->setPower(power);
    left->setPower(power+ADJUST_LEFT);
  }
}

