#include "SpinningSawTrap.h"
#include "Saw.h"
#include <iostream>
using namespace std;

SpinningSawTrap::SpinningSawTrap(Vector2f possition, int sawRotationDegree, int baseRotationDegree, int sawRadius,int baseWidth, int baseHeigth, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor, Color baseFirstColor, Color baseSecondColor, Color baseThirdColor, Color baseForthColor)
{
	setPosition(possition);
	saw = new Saw(possition, sawRotationDegree, sawRadius, sawFirstColor, sawSecondColor, sawThirdColor);
	base = new Base(position,baseRotationDegree, baseWidth, baseHeigth, baseFirstColor, baseSecondColor, baseThirdColor, baseForthColor);
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
void SpinningSawTrap::render(RenderTarget& target)
{
	
	this->base->render(target);
	this->saw->render(target);
}