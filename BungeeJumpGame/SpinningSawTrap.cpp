#include "SpinningSawTrap.h"
#include <iostream>
using namespace std;

SpinningSawTrap::SpinningSawTrap(Vector2f position, BaseParameters bp, SawParameters sp)
{
	setPosition(position);
	saw = new Saw(position, sp);
	base = new TrapBase(position, bp);
}

SpinningSawTrap::~SpinningSawTrap()
{

}

void SpinningSawTrap::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f SpinningSawTrap::getPosition()
{
	return this->position ;
}

Vector2f* SpinningSawTrap::getTrapDimensions()
{
	Vector2f possition = this->getPosition();
	Vector2f* diagonalCoordinatesUpperFirst= new Vector2f[2];
	int sawRadius = this->saw->getRadius();
	int baseHeight = this->base->getHeight();
	int baseWidth = this->base->getWidth();
	if (abs(possition.y + sawRadius) < abs(possition.y + baseHeight/2))
	{
		diagonalCoordinatesUpperFirst[0].y = possition.y - baseHeight / 2;
		diagonalCoordinatesUpperFirst[1].y = possition.y + baseHeight / 2;
	}
	else
	{
		diagonalCoordinatesUpperFirst[0].y = possition.y - sawRadius;
		diagonalCoordinatesUpperFirst[1].y = possition.y + sawRadius;
	}
	if (abs(possition.x + sawRadius) < abs(possition.x + baseWidth / 2))
	{
		diagonalCoordinatesUpperFirst[0].x = possition.x - baseWidth / 2;
		diagonalCoordinatesUpperFirst[1].x = possition.x + baseWidth / 2;
	}
	else
	{
		diagonalCoordinatesUpperFirst[0].x = possition.x- sawRadius;
		diagonalCoordinatesUpperFirst[1].x = possition.x + sawRadius;
	}
	return diagonalCoordinatesUpperFirst;
}

Vector2f SpinningSawTrap::getSize()
{
	auto td = getTrapDimensions();
	Vector2f corner1 = td[0];
	Vector2f corner2 = td[1];

	int width = abs(corner1.x - corner2.x);
	int height = abs(corner1.y - corner2.y);

	return Vector2f(width, height);
}

void SpinningSawTrap::render(RenderTarget& target)
{
	
	this->base->render(target);
	this->saw->render(target);
}