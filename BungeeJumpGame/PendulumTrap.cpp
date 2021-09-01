#include "PendulumTrap.h"
#include <iostream>

PendulumTrap::PendulumTrap(Vector2f position, int rotationDegree)
{
	setPosition(position);
	initAxe(position);
	initBase(position);
	setRotationDegree(rotationDegree);
}

PendulumTrap::~PendulumTrap()
{

}

void PendulumTrap::initAxe(Vector2f position)
{
	axe.setTexture(TextureMap::getInstance().getTexture("Axe_trap"));
	axe.setOrigin((getSize(axe).x / 2.f), 0);
	axe.rotate(0);
	axe.setPosition(position.x,position.y);
	axe.scale(0.5f, 0.5f);
}

void PendulumTrap::initBase(Vector2f position)
{
	base.setTexture(TextureMap::getInstance().getTexture("Base_trap"));
	base.setOrigin((axe.getOrigin().x),(axe.getOrigin().y + getSize(base).y / 2.f));
	base.rotate(-90);
	base.setPosition(position);
	base.scale(0.2f, 0.2f);
}

void PendulumTrap::initInitialAxeRotationDegree(double initialAxeRotationDegree)
{
	setInitialAxeRotationDegree(initialAxeRotationDegree);
	axe.rotate(initialAxeRotationDegree);
}

void PendulumTrap::initInitialBaseRotationDegree(double initialBaseRotationDegree)
{
	setInitialBaseRotationDegree(initialBaseRotationDegree);
	base.rotate(initialBaseRotationDegree);
}

void PendulumTrap::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f PendulumTrap::getPosition()
{
	return this->position;
}

void PendulumTrap::setRotationDegree(double rotationDegree)
{
	this->rotationDegree = rotationDegree;
}

double PendulumTrap::getRotationDegree()
{
	return this->rotationDegree;
}

void PendulumTrap::setInitialAxeRotationDegree(double initialAxeRotationDegree)
{
	this->initialAxeRotationDegree = initialAxeRotationDegree;
}

double PendulumTrap::getInitialAxeRotationDegree()
{
	return this->initialAxeRotationDegree;
}

void PendulumTrap::setInitialBaseRotationDegree(double initialBaseRotationDegree)
{
	this->initialBaseRotationDegree = initialBaseRotationDegree;
}

double PendulumTrap::getInitialBaseRotationDegree()
{
	return this->initialBaseRotationDegree;
}

Vector2f PendulumTrap::getSize(Sprite shape)
{
	FloatRect axeBounds = shape.getGlobalBounds();
	return Vector2f(axeBounds.width, axeBounds.height);
}

vector<Sprite> PendulumTrap::getSprites()
{
	vector<Sprite> involvedSprites = {};
	involvedSprites.push_back(this->axe);
	involvedSprites.push_back(this->base);
	return involvedSprites;
}

void PendulumTrap::pendulumRotate()
{
	double rotationDegree = getRotationDegree();
	if (rotationDegree == (int)rotationDegree)
	{
		this->axe.rotate(rotationDegree);
	}
	if ((this->axe.getRotation() == getInitialAxeRotationDegree()))
	{
		changeRotationIncrementationSigh = !changeRotationIncrementationSigh;
	}
	else
	{
		if (changeRotationIncrementationSigh)
		{
			setRotationDegree(rotationDegree + 0.5);
		}
		else
		{
			setRotationDegree(rotationDegree - 0.5);
		}
	}
	
}

void PendulumTrap::render(RenderTarget& target)
{
	pendulumRotate();
	target.draw(this->base);
	target.draw(this->axe);
}