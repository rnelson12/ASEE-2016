#include "DriveTrain.h"

DriveTrain::DriveTrain(int defaultRightPower,int defaultLeftPower){
	powerR=defaultRightPower;
	powerL=defaultLeftPower;
	left=Wheel(5,20);	//needs to get this from the config file
	right=Wheel(6,43);
}

void DriveTrain::drive(int power,State direction){
	switch(direction){
		case TURN_LEFT:
			right.setPower(power+10);
			left.setPower(power);
			break;
		case TURN_RIGHT:
			left.setPower(power+10);
			right.setPower(power);
			break;
		case FORWARD:
			left.setPower(power);
			right.setPower(power);
			break;
			/*if this is handled by the drvie train
				I need to have cases where the drive train
				is adjusting left or right with less power
				going to the wheels.
			*/
	};
}