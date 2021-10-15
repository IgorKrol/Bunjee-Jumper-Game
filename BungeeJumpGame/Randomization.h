#pragma once
#include <random>
#include <iostream>
#include "AbstractTrap.h"
#include "PendulumTrap.h"
#include "SpinningSawTrap.h"
#include "Background.h"
#include "CameraManager.h"
class Randomization
{
private:
	vector<pair<bool,AbstractTrap*>> generatedTraps;
	int framesBetweenTrapGenerations = 360;
	int concorrentGeneratedTrapLimit = 10;
	int framescounter = 0;
	bool firstCreation = true;
	Background* background;

public:
	Randomization();
	~Randomization();
	float getRundomNumber(int lowerLimit, int upperLimit, bool intGeneration);
	void createRandomTrapOutsideOfView(RenderTarget& target, CameraManager* view, Background* wholeMap, const vector<string> trapTypes);
	void randomCameraMovement(CameraManager* view);//, RenderWindow* window);
	void setConcorrentGeneratedTrapLimit(int concorrentGeneratedTrapLimit);
	int getConcorrentGeneratedTrapLimit();
	void setFramesBetweenTrapGenerations(int framesBetweenTrapGenerations);
	int getFramesBetweenTrapGenerations();
	//void backgroundUpdate(RenderWindow* window);
};

