#include "PendulumTrap.h"
#include <iostream>
using namespace std;

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
	axe.setOrigin((getSize().x / 2.f), 0);
	axe.setPosition(position.x+5,position.y);
	axe.scale(0.5f, 0.5f);
}

void PendulumTrap::initBase(Vector2f position)
{
	base.setTexture(TextureMap::getInstance().getTexture("Base_trap"));
	base.setOrigin((axe.getOrigin().x),(axe.getOrigin().y + getSize().y / 2.f));
	base.rotate(-90);
	base.setPosition(position);
	base.scale(0.2f, 0.2f);
}

void PendulumTrap::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f PendulumTrap::getPosition()
{
	return this->position;
}

void PendulumTrap::setRotationDegree(int rotationDegree)
{
	this->rotationDegree = rotationDegree;
}

int PendulumTrap::getRotationDegree()
{
	return this->rotationDegree;
}

Vector2f PendulumTrap::getSize()
{
	FloatRect sawBounds = axe.getGlobalBounds();
	return Vector2f(sawBounds.width, sawBounds.height);
}

void PendulumTrap::pendulumRotate()
{
	int rotationDegree = getRotationDegree();
	this->axe.rotate(rotationDegree);
	if ((this->axe.getRotation() == 0))
	{
		changeRotationIncrementationSigh = !changeRotationIncrementationSigh;
	}
	else
	{
		if (changeRotationIncrementationSigh)
		{
			setRotationDegree(rotationDegree + 1);
		}
		else
		{
			setRotationDegree(rotationDegree - 1);
		}
	}
}

Sprite& PendulumTrap::getSprite()
{
	return axe;
}

void PendulumTrap::render(RenderTarget& target)
{
	pendulumRotate();
	target.draw(this->base);
	target.draw(this->axe);
}