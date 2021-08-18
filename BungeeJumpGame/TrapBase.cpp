#include "TrapBase.h"
#include "BaseParameters.h"
#include <iostream>
using namespace std;

TrapBase::TrapBase(Vector2f position, BaseParameters bp)
{
	setPosition(position);
	initBase(position.x, position.y, bp.baseWidth, bp.baseHeigth, bp.baseFirstColor, bp.baseSecondColor, bp.baseThirdColor, bp.baseFirstColor);
	setRotationDegree(bp.baseRotationDegree);
}

TrapBase::~TrapBase()
{
}

void TrapBase::initBase(int x, int y, int width, int height, Color firstColor, Color secondColor, Color thirdColor, Color forthColor)
{
	setHeight(height);
	setWidth(width);
	setColors(firstColor, secondColor, thirdColor, forthColor);
	sf::VertexArray rectangle(sf::Quads, 4);

	// define the position of the rectangle's points
	rectangle[0].position = sf::Vector2f(x - width / 2, y - height / 2);
	rectangle[1].position = sf::Vector2f(x + width / 2, y - height / 2);
	rectangle[2].position = sf::Vector2f(x + width / 2, y + height / 2);
	rectangle[3].position = sf::Vector2f(x - width / 2, y + height / 2);

	// define the color of the rectangle's points
	rectangle = colourAsignment(rectangle);

	this->base = rectangle;
}

VertexArray  TrapBase::colourAsignment(VertexArray rectangleShape)
{
	Color* colors = getColors();
	for (int i = 0; i < 4; i++)
	{
		rectangleShape[i].color = colors[i];
	}
	return rectangleShape;
}

void TrapBase::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f TrapBase::getPosition()
{
	return this->position;
}
void TrapBase::setHeight(int height)
{
	this->height = height;
}

int TrapBase::getHeight()
{
	return this->height;
}
void TrapBase::setWidth(int width)
{
	this->width = width;
}

int TrapBase::getWidth()
{
	return this->width;
}

void TrapBase::setColors(Color firstColor, Color secondColor, Color thirdColor, Color forthColor)
{

	this->colors[0] = firstColor;
	this->colors[1] = secondColor;
	this->colors[2] = thirdColor;
	this->colors[3] = forthColor;
}

Color* TrapBase::getColors()
{
	return this->colors;
}

void TrapBase::setRotationDegree(int rotationDegree)
{
	this->rotationDegree = rotationDegree;
}

int TrapBase::getRotationDegree()
{
	return this->rotationDegree;
}
void TrapBase::render(RenderTarget& target)
{
	int rotationDegree = getRotationDegree();
	sf::Transform transform;
	transform.rotate(rotationDegree, this->getPosition());
	target.draw(this->base, transform);
	for (int i = 0; i <= 3; i++)
	{
		base[i] = transform.transformPoint(base[i].position);
	}
	base = colourAsignment(base);
}