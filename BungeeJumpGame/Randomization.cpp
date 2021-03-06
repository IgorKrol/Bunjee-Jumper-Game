#include "Randomization.h"
#include "Game.h"
Randomization::Randomization(): generatedTraps(*Game::traps)
{

}

Randomization::~Randomization()
{

}

float Randomization::getRundomNumber(int lowerLimit, int upperLimit, bool intGeneration)
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	if(intGeneration)
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


void Randomization::createRandomTrapOutsideOfView(RenderTarget& target,CameraManager* view, Background* wholeMap, const vector<string> trapTypes)
{
	pair<bool, AbstractTrap*> trapAndTriger;
	Vector2f viewTopLeftCorner = view->getTopLeftCorner();
	Vector2f viewBottomRightCorner = view->getBottomRightCorner();
	Vector2u mapSize = wholeMap->getSize();
	AbstractTrap* generatedTrap;
	bool unacceptableTrapCreationPoint = true;
	bool createdTrapsBoundingsCollidedWithNewCreationPoint = false;
	int i = (int)getRundomNumber(0,10000,true)% trapTypes.size();
	int x = (int)getRundomNumber(0, mapSize.x, true);
	int y = (int)getRundomNumber(0, mapSize.y, true);

	if ((framescounter == this->framesBetweenTrapGenerations) && (generatedTraps.size() != this->concorrentGeneratedTrapLimit))
	{
		
		while (unacceptableTrapCreationPoint)
		{
			if (((viewTopLeftCorner.x < x) && (x < viewBottomRightCorner.x)) && ((viewTopLeftCorner.y < y) && (y < viewBottomRightCorner.y)))
			{
				x = (int)getRundomNumber(0, mapSize.x, true);
				y = (int)getRundomNumber(0, mapSize.y, true);
			}
			else
			{
				if (firstCreation == false)
				{
					createdTrapsBoundingsCollidedWithNewCreationPoint = false;
					for (int i = 0; i < generatedTraps.size(); i++)
					{
						if ((((generatedTraps[i].second->getGlobalBounding().left - 200.f < x) && (x < (generatedTraps[i].second->getGlobalBounding().left + generatedTraps[i].second->getGlobalBounding().width) + 200.f))
							&& ((generatedTraps[i].second->getGlobalBounding().top - 200.f < y) && (y < (generatedTraps[i].second->getGlobalBounding().top + generatedTraps[i].second->getGlobalBounding().height) + 200.f))))
						{
							x = (int)getRundomNumber(0, mapSize.x, true);
							y = (int)getRundomNumber(0, mapSize.y, true);
							createdTrapsBoundingsCollidedWithNewCreationPoint = true;
							i = generatedTraps.size();
						}
					}
					if (createdTrapsBoundingsCollidedWithNewCreationPoint == false)
					{
						unacceptableTrapCreationPoint = false;
					}
				}
				else
				{
					firstCreation = false;
					unacceptableTrapCreationPoint = false;
				}

			}
		}

		AbstractTrap* generatedTrap = AbstractTrap::Create(trapTypes[i], Vector2f(x, y), 13);
		this->framescounter = 0;

		if (PendulumTrap* actualCreatedTrap = dynamic_cast<PendulumTrap*>(generatedTrap))
		{
			actualCreatedTrap->initInitialAxeRotationDegree((int)getRundomNumber(0, 360, true));
			actualCreatedTrap->initInitialBaseRotationDegree(getRundomNumber(0, 360, false));
		}

		trapAndTriger.first = false;
		trapAndTriger.second = generatedTrap;
		generatedTraps.push_back(trapAndTriger);
	}
	else
	{
		this->framescounter = ++framescounter;

		if (framescounter > this->framesBetweenTrapGenerations)
		{
			this->framescounter = 0;
		}
	}

	for (int i = 0; i < generatedTraps.size(); i++)
	{
		if(((viewTopLeftCorner.x < generatedTraps[i].second->getPosition().x) 
			&& (generatedTraps[i].second->getPosition().x < viewBottomRightCorner.x))
			&& ((viewTopLeftCorner.y < generatedTraps[i].second->getPosition().y) 
			&& (generatedTraps[i].second->getPosition().y < viewBottomRightCorner.y)))
		{
			generatedTraps[i].first = true;
			generatedTraps[i].second->render(target);
		}

		if ((((viewTopLeftCorner.x > generatedTraps[i].second->getPosition().x)
			|| (generatedTraps[i].second->getPosition().x > viewBottomRightCorner.x)) 
			|| ((viewTopLeftCorner.y > generatedTraps[i].second->getPosition().y)
			|| (generatedTraps[i].second->getPosition().y > viewBottomRightCorner.y)))
			&& (generatedTraps[i].first==true))
		{
			std::cout << generatedTraps[i].first << std::endl;
			 generatedTraps.erase(generatedTraps.begin() + i); //why generatedTraps.begin() + i and not just i
		}
		else
		{
			generatedTraps[i].second->render(target);
		}
		
	}
}


void Randomization::randomCameraMovement(CameraManager* view)
{
	if (view->getCounterToTime() >= view->getTime())
	{
		view->setTime((int)getRundomNumber(1000, 3000, true));
		view->setMovementDelta(Vector2f(getRundomNumber(-10, 10, false),getRundomNumber(-4, 4, false)));
		view->setCounterToTime(0);
	}
	else
	{
		view->move(view->getMovementDelta().x, view->getMovementDelta().y);
		view->setCounterToTime(view->getCounterToTime() + 1);
	}
}

void Randomization::setConcorrentGeneratedTrapLimit(int concorrentGeneratedTrapLimit)
{
	this->concorrentGeneratedTrapLimit = concorrentGeneratedTrapLimit;
}

int Randomization::getConcorrentGeneratedTrapLimit()
{
	return this->concorrentGeneratedTrapLimit;
}

void Randomization::setFramesBetweenTrapGenerations(int framesBetweenTrapGenerations)
{
	this->concorrentGeneratedTrapLimit = framesBetweenTrapGenerations;
}

int Randomization::getFramesBetweenTrapGenerations()
{
	return this->framesBetweenTrapGenerations;
}

