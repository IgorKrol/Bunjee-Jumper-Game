#pragma once
#include <random>
#include "AbstractTrap.h"
#include "Background.h"
#include "CameraManager.h"
class Randomization
{
public:
	Randomization();
	~Randomization();
	float getRundomNumber(int lowerLimit, int upperLimit, bool timeGeneration);
	//void createRandomTrapOutsideOfView(CameraManager* view, Background* wholeMap, std::vector<AbstractTrap*> trapTypes);
};

