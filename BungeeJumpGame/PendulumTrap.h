#pragma once
#include"TextureMap.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class PendulumTrap
{
public:
	PendulumTrap(Vector2f position, int rotationDegree);
	virtual ~PendulumTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setRotationDegree(double rotationDegree);
	double getRotationDegree();
	Vector2f getSize();
	void pendulumRotate();
	Sprite& getSprite();
	void render(RenderTarget& target);

private: Vector2f position;
	   Sprite axe;
	   Sprite base;
	   Vector2f centerPointOfTheAxe;
	   double rotationDegree;
	   bool changeRotationIncrementationSigh = false;
	   void initAxe(Vector2f position);
	   void initBase(Vector2f position);
};

