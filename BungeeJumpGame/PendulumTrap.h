#pragma once
#include"TextureMap.h"
#include "AbstractTrap.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class PendulumTrap : public AbstractTrap//<PendulumTrap>
{
public:
	PendulumTrap(Vector2f position, int rotationDegree);
	virtual ~PendulumTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setRotationDegree(double rotationDegree);
	double getRotationDegree();
	void initInitialAxeRotationDegree(double initialRotationDegree);
	double getInitialAxeRotationDegree();
	void initInitialBaseRotationDegree(double initialBaseRotationDegree);
	double getInitialBaseRotationDegree();
	Vector2f getSize(Sprite shape);
	vector<Sprite> getSprites();
	FloatRect getGlobalBounding();
	void pendulumRotate();
	//PendulumTrap* getType();
	void render(RenderTarget& target);

private: Vector2f position;
	   Sprite axe;
	   Sprite base;
	   Vector2f centerPointOfTheAxe;
	   double rotationDegree;
	   double initialAxeRotationDegree=0;
	   double initialBaseRotationDegree = 0;
	   bool changeRotationIncrementationSigh = false;
	   void initAxe(Vector2f position);
	   void initBase(Vector2f position);
	   void setInitialAxeRotationDegree(double initialRotationDegree);
	   void setInitialBaseRotationDegree(double initialBaseRotationDegree);
	   Sprite getAxe();
};

