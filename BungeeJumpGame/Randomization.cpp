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