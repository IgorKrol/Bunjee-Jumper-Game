#include "SpinningSawTrap.h"
#include <iostream>

SpinningSawTrap::SpinningSawTrap(Vector2f position, int rotationDegree)
{
	setPosition(position);
	initSprite(position);
	setRotationDegree(rotationDegree);
}

SpinningSawTrap::~SpinningSawTrap()
{

}

void SpinningSawTrap::initSprite(Vector2f position)
{
	saw.setTexture(TextureMap::getInstance().getTexture("Saw_trap"));
	saw.setOrigin(getSize().x / 2.f, getSize().y / 2.f);
	saw.setPosition(position);
	saw.scale(0.5f, 0.5f);
}


void SpinningSawTrap::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f SpinningSawTrap::getPosition()
{
	return this->position ;
}

void SpinningSawTrap::setRotationDegree(int rotationDegree)
{
	this->rotationDegree = rotationDegree;
}

int SpinningSawTrap::getRotationDegree()
{
	return this->rotationDegree;
}


Vector2f SpinningSawTrap::getSize()
{
	FloatRect sawBounds = saw.getGlobalBounds();
	return Vector2f(sawBounds.width, sawBounds.height);
}

void SpinningSawTrap::sawRotate(int rotationDegree)
{
	this->saw.rotate(rotationDegree);
}

vector<Sprite> SpinningSawTrap::getSprites()
{
	vector<Sprite> involvedSprites;
	involvedSprites.push_back(this->saw);
	return involvedSprites;
}

Sprite& SpinningSawTrap::getSprite()
{
	return saw;
}


FloatRect SpinningSawTrap::getGlobalBounding()
{
	FloatRect sawBounds = this->getSprite().getGlobalBounds();
	return sawBounds;
}
//SpinningSawTrap* SpinningSawTrap::getType()
//{
//	return this;
//}

void SpinningSawTrap::render(RenderTarget& target)
{
	sawRotate(getRotationDegree());
	target.draw(this->saw);
}