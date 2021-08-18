#include "SpinningSawTrap.h"
#include "Saw.h"
#include <iostream>
using namespace std;

SpinningSawTrap::SpinningSawTrap(Vector2f possition, int sawRotationDegree, int baseRotationDegree, int sawRadius,int baseWidth, int baseHeigth, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor, Color baseFirstColor, Color baseSecondColor, Color baseThirdColor, Color baseForthColor)
{
	setPosition(possition);
	saw = new Saw(possition, sawRotationDegree, sawRadius, sawFirstColor, sawSecondColor, sawThirdColor);
	base = new Base(possition,baseRotationDegree, baseWidth, baseHeigth, baseFirstColor, baseSecondColor, baseThirdColor, baseForthColor);
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

void SpinningSawTrap::render(RenderTarget& target)
{
	
	this->base->render(target);
	this->saw->render(target);
}