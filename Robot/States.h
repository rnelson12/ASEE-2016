#ifndef STATES_H
#define STATES_H

#include "Drivetrain.h"
#include "SensorGrid.h"

enum Robot1State
{
	Start = 0,
	InitialWest,
	CenteringNorth,
	W24,
	Stopv1,
	Drop2v1,
	TurnS,
	S40,
	Straight,
	S40v2,
	Stopv2,
	Drop2v2,
	TurnE,
	E32,
	Stopv3,
	Drop1v1,
	TurnN,
	N12,
	Stopv4,
	TurnW,
	W12,
	Stopv5,
	TurnNv2,
	N24,
	Straightv2,
	N24v2,
	Stopv6,
	TurnEv2,
	E__,
	Stopv7,
	Drop1v2,
	TurnNv3,
	N12v2,
	Finish,
	ERROR
};

const char* Robot1StateNames[] =
{
	"Start",
	"InitialWest"
	"CenteringNorth"
	"W24",
	"Stopv1",
	"Drop2v1",
	"TurnS",
	"S40",
	"Straight",
	"S40v2",
	"Stopv2",
	"Drop2v2",
	"TurnE",
	"E32",
	"Stopv3",
	"Drop1v1",
	"TurnN",
	"N12",
	"Stopv4",
	"TurnW",
	"W12",
	"Stopv5",
	"TurnNv2",
	"N24",
	"Straightv2",
	"N24v2",
	"Stopv6",
	"TurnEv2",
	"E__",
	"Stopv7",
	"Drop1v2",
	"TurnNv3",
	"N12v2",
	"Finish",
	"ERROR"
};

Robot1State state;
const byte power;
const byte stop;
DriveTrain* drive;
SensorGrid* sensors;
bool turningFlag = true;
unsigned long comparisonTime;
Direction currentDirection;

enum Direction
{
	NORTH, EAST, SOUTH, WEST
};

bool Drop2()
{
	//todo: drop 2 rings
	//return true when finished
}

bool Drop1()
{
	//todo: drop 1 ring
	//return true when finished
}

//return true when successfully pointing in that direction
bool isTurned(Direction d)
{
	if (currentDirection == d)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void turnLeftInitial(unsigned long timeStart)
{
	comparisonTime = timeStart;
}

void turnLeft(unsigned long currentTime)
{
	if (currentTime >= (comparisonTime + ROBOT1_LEFT_TURN_TIME))
	{
		currentDirection = (currentDirection - 1) % 4;
	}
}

void turnRightInitial(unsigned long timeStart)
{
	comparisonTime = timeStart;
}

void turnRight(unsigned long currentTime)
{
	if (currentTime >= (comparisonTime + ROBOT1_RIGHT_TURN_TIME))
	{
		currentDirection = (currentDirection + 1) % 4;
	}

}


void robot1tick(unsigned long currentTime)
{
	switch(state)
	{
	case Start:
		currentDirection = WEST;
		//no break -- fallthrough to first state

	//TODO: implement InitialWest
	case InitialWest:
		//if( FRONT SENSORS READ A LINE)
		//		state = CenteringNorth;

		break;
	//TODO: implement CenteringNorth
	case CenteringNorth:
		if(isTurned(NORTH));
		{
			state = W24;
		}
		break;
	case W24:
		drive->drive(power, FORWARD);
		//todo: Move arms to position
		//encoders?
		if (sensors->calculateTurn() == TURN_LEFT)
			state = Stopv1;
		break;
	case Stopv1:
		drive->drive(stop, FORWARD);
		//may need to do braking here
		state = Drop2v1;
		break;
	case Drop2v1:
		if (Drop2())
			state = TurnS;
		break;
	case TurnS:
		
		if (isTurned(SOUTH))
		{
			state = S40;
			turningFlag = true;
		}
		else if (turningFlag) 
		{
			turnLeftInitial(currentTime);
			turningFlag = false;
		} else{
			turnLeft(currentTime);
		}
		break;
	case S40:
		drive->drive(power, FORWARD);
		if (sensors->calculateTurn() == FORWARD)
			state = Straight;
		break;
	case Straight:
		//print statement?
		//no break -- fallthrough to S40v2,
		//unless we need to specifically move past the intersection
	case S40v2:
		drive->drive(power, FORWARD);
		//todo: Move arms to position
		//encoders?
		if (sensors->calculateTurn() == TURN_LEFT)
			state = Stopv2;
		break;
	case Stopv2:
		drive->drive(stop, FORWARD);
		//may need to do braking here
		state = Drop2v2;
		break;
	case Drop2v2:
		if (Drop2())
			state = TurnE;
		break;
	case TurnE:
		if (isTurned(EAST))
		{
			state = E32;
			turningFlag = true;
		}
		else if (turningFlag) {
			turnLeftInitial(currentTime);
			turningFlag = false;
		}
		else {
			turnLeft(currentTime);
		}
		break;
	case E32:
		drive->drive(power, FORWARD);
		//todo: Move arm to position
		//encoders?
		if (sensors->calculateTurn() == TURN_LEFT)
			state = Stopv3;
		break;
	case Stopv3:
		drive->drive(stop, FORWARD);
		//may need to do braking here
		state = Drop1v1;
		break;
	case Drop1v1:
		if (Drop1())
			state = TurnN;
		break;
	case TurnN:
		if (isTurned(NORTH))
		{
			state = N12;
			turningFlag = true;
		}
		else if (turningFlag)
		{
			turnLeftInitial(currentTime);
			turningFlag = false;
		}
		else {
			turnLeft(currentTime);
		}
		break;
	case N12:
		//todo: check that we are looking for the right intersection
		drive->drive(power, FORWARD);
		if (sensors->calculateTurn() == FORWARD)
			state = Stopv4;
		break;
	case Stopv4:
		drive->drive(stop, FORWARD);
		//may need to do braking here
		state = TurnW;
		break;
	case TurnW:
		if (isTurned(WEST))
		{
			state = W12;
			turningFlag = true;
		}
		else if (turningFlag)
		{
			turnLeftInitial(currentTime);
			turningFlag = false;
		}
		else {
			turnLeft(currentTime);
		}
		break;
	case W12:
		//todo: check that we are looking for the right intersection
		drive->drive(power, FORWARD);
		if (sensors->calculateTurn() == TURN_RIGHT)
			state = Stopv6;
		break;
	case Stopv5:
		drive->drive(stop, FORWARD);
		//may need to do braking here
		state = TurnNv2;
		break;
	case TurnNv2:
		if (isTurned(NORTH))
		{
			state = N24;
			turningFlag = true;
		}
		else if (turningFlag)
		{
			turnRightInitial(currentTime);
			turningFlag = false;
		}
		else {
			turnRight(currentTime);
		}
		break;
	case N24:
		drive->drive(power, FORWARD);
		if (sensors->calculateTurn() == FORWARD)
			state = Straightv2;
		break;
	case Straightv2:
		//print statement?
		//no break -- fallthrough to N24v2,
		//unless we need to specifically move past the intersection
	case N24v2:
		drive->drive(power, FORWARD);
		//todo: Move arms to position
		//encoders?
		//are we at an intersection here?
		if (sensors->calculateTurn() == TURN_RIGHT)
			state = Stopv6;
		break;
	case Stopv6:
		drive->drive(stop, FORWARD);
		//may need to do braking here
		state = TurnEv2;
		break;
	case TurnEv2:
		if (isTurned(EAST)) {
			state = E__;
			turningFlag = true;
		}
		else if (turningFlag) {
			turnRightInitial(currentTime);
			turningFlag = false;
		}
		else {
			turnRight(currentTime);
		}
		break;
	case E__:
		drive->drive(power, FORWARD);
		//todo: Move arms to position
		//encoders?
		//are we at an intersection here?
		//NO
		if (turningFlag)
		{
			turningFlag = false;
			comparisonTime = currentTime;
		}
		if (currentTime >= (comparisonTime + ROBOT1_EAST_STRAIGHTAWAY_TIME))
		{
			state = Drop1v2;
		}
		break;
	case Drop1v2:
		if (Drop1())
			state = TurnNv3;
		break;
	case TurnNv3:
		if (isTurned(NORTH)) {
			state = N12v2;
			turningFlag = true;
		}
		else if (turningFlag)
		{
			turnLeftInitial(currentTime);
			turningFlag = false;
		}
		else {
			turnLeft(currentTime);
		}
			
		break;
	case N12v2:
		drive->drive(power, FORWARD);
		//todo: Move arms to finish position
		//encoders?
		//todo: do by time or by crossing line + time
		if (sensors->calculateTurn() == TURN_RIGHT)
			state = Finish;
		break;
	default:
		//todo: print error message
		//fallthrough to finish
	case Finish:
		//todo: make robot stop
		//todo: print robot is stopped (only once?)
		break;
	}
	//todo: print the state? (e.g.:
		//printf(Robot1StateNames[state]);
}
#endif 
