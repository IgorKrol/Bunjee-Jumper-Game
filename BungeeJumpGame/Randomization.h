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
	bool firstCreation = true;
public:
	Randomization();
	~Randomization();
	float getRundomNumber(int lowerLimit, int upperLimit, bool intGeneration);
	void randomCameraMovement(CameraManager* view);
	void createRandomTrapOutsideOfView(RenderTarget& target, CameraManager* view, Background* wholeMap, const vector<string> trapTypes);
	void setConcorrentGeneratedTrapLimit(int concorrentGeneratedTrapLimit);
	int getConcorrentGeneratedTrapLimit();
	void setFramesBetweenTrapGenerations(int framesBetweenTrapGenerations);
	int getFramesBetweenTrapGenerations();
};

