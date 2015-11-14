#include "Cog.h"

Cog::Cog(byte numRings)
{
	rotationalPosition = 0;
	numRingsLeft = numRings;
}

Cog::~Cog()
{
	//delete colorSensor
	//colorSensor = nullptr;
}

void Cog::dropNextRing()
{
}
