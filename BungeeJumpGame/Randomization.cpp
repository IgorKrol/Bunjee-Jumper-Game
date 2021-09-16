#include "Randomization.h"
Randomization::Randomization()
{

}

Randomization::~Randomization()
{

}

float Randomization::getRundomNumber(int lowerLimit, int upperLimit, bool timeGeneration)
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	if(timeGeneration)
	{
		std::uniform_int_distribution<int>  distr(lowerLimit, upperLimit);
		return distr(generator);
	}
	else 
	{
		std::uniform_real_distribution<float>  distr(lowerLimit, upperLimit);
		return distr(generator);
	}
}

//void Randomization::createRandomTrapOutsideOfView(CameraManager* view, Background* wholeMap, std::vector<AbstractTrap*> trapTypes)
//{
//	Vector2f viewTopLeftCorner = view->getTopLeftCorner();
//	Vector2f viewBottomRightCorner = view->getBottomRightCorner();
//	Vector2u mapSize = wholeMap->getSize();
//	//trapTypes//no instanceof
//}