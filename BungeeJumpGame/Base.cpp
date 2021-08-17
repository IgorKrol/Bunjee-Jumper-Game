#include "Base.h"
#include <iostream>
using namespace std;

Base::Base(Vector2f position, int rotationDegree, int width, int height, Color firstColor, Color secondColor, Color thirdColor, Color forthColor)
{
	setPosition(position);
	initBase(position.x, position.y, width, height, firstColor, secondColor, thirdColor, forthColor);
	setRotationDegree(rotationDegree);
}

void Base::initBase(int x, int y, int width1, int height1, Color firstColor, Color secondColor, Color thirdColor, Color forthColor)
{
	int height = height1;
	int width = width1;
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

VertexArray  Base::colourAsignment(VertexArray rectangleShape)
{
	Color* colors = getColors();
	for (int i = 0; i < 4; i++)
	{
		rectangleShape[i].color = colors[i];
	}
	return rectangleShape;
}

void Base::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f Base::getPosition()
{
	return this->position;
}

void Base::setColors(Color firstColor, Color secondColor, Color thirdColor, Color forthColor)
{

	this->colors[0] = firstColor;
	this->colors[1] = secondColor;
	this->colors[2] = thirdColor;
	this->colors[3] = forthColor;
}

Color* Base::getColors()
{
	return this->colors;
}

void Base::setRotationDegree(int rotationDegree)
{
	this->rotationDegree = rotationDegree;
}

int Base::getRotationDegree()
{
	return this->rotationDegree;
}
void Base::render(RenderTarget& target)
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