#include "Saw.h"
#include <iostream>
using namespace std;

Saw::Saw(Vector2f position, int rotationDegree, int radius, Color firstColor, Color secondColor, Color thirdColor)
{
	setPosition(position);
	initSaw(position.x, position.y, radius, firstColor, secondColor, thirdColor);
	setRotationDegree(rotationDegree);
}

Saw::~Saw()
{

}

void Saw::initSaw(int x, int y, int radius, Color firstColor, Color secondColor, Color thirdColor)
{
	setRadius(radius);
	setColors(firstColor, secondColor, thirdColor);
	VertexArray uprightTriangle(sf::Triangles, 3);


	// define the position of the uprightTriangle's points
	uprightTriangle[0].position = sf::Vector2f(x + (-0.866 * radius), y + (-0.5 * radius));
	uprightTriangle[1].position = sf::Vector2f(x + (0.866 * radius), y + (-0.5 * radius));
	uprightTriangle[2].position = sf::Vector2f(x + (0 * radius), y + (1 * radius));

	// define the color of the uprightTriangle's points
	uprightTriangle = colourAsignment(uprightTriangle);

	VertexArray dowrightTriangle(sf::Triangles, 3);

	// define the position of the dowrightTriangle's points
	dowrightTriangle[0].position = sf::Vector2f(x + (-0.866 * radius), y - (-0.5 * radius));
	dowrightTriangle[1].position = sf::Vector2f(x + (0.866 * radius), y - (-0.5 * radius));
	dowrightTriangle[2].position = sf::Vector2f(x + (0 * radius), y - (1 * radius));

	// define the color of the dowrightTriangle's points
	dowrightTriangle = colourAsignment(dowrightTriangle);

	VertexArray* unifiedTriangles = new VertexArray[2];
	unifiedTriangles[0] = uprightTriangle;
	unifiedTriangles[1] = dowrightTriangle;
	
	this->saw = unifiedTriangles;
}

VertexArray  Saw::colourAsignment(VertexArray triangleShape)
{
	Color* colors = getColors();
	for (int i = 0; i < 3; i++)
	{
		triangleShape[i].color = colors[i];
	}
	return triangleShape;
}
void Saw::setRadius(int radius)
{
	this->radius = radius;
}

int Saw::getRadius()
{
	return this->radius;
}

void Saw::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f Saw::getPosition()
{
	return this->position;
}

void Saw::setColors(Color firstColor, Color secondColor, Color thirdColor)
{
	
	this->colors[0] = firstColor;
	this->colors[1] = secondColor;
	this->colors[2] = thirdColor;
}

Color* Saw::getColors()
{
	return this->colors;
}

void Saw::setRotationDegree(int rotationDegree)
{
	this->rotationDegree = rotationDegree;
}

int Saw::getRotationDegree()
{
	return this->rotationDegree;
}

void Saw::render(RenderTarget& target)
{
	int rotationDegree = getRotationDegree();
	sf::Transform transform;
	transform.rotate(rotationDegree, this->getPosition());
	target.draw(this->saw[0], transform);
	target.draw(this->saw[1], transform);
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			saw[i][j] = transform.transformPoint(saw[i][j].position);
		}
	}
	saw[0] = colourAsignment(saw[0]);
	saw[1] = colourAsignment(saw[1]);
}