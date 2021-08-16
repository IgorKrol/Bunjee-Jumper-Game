#include "Saw.h"
#include <iostream>
using namespace std;

Saw::Saw(Vector2f position, Color firstColor, Color secondColor, Color thirdColor)
{
	setPosition(position);
	initSaw(position.x, position.y, firstColor, secondColor, thirdColor);
}

Saw::~Saw()
{
}

void Saw::initSaw(int x, int y, Color firstColor, Color secondColor, Color thirdColor)
{
	int radius = 35;
	VertexArray uprightTriangle(sf::Triangles, 3);


	// define the position of the uprightTriangle's points
	uprightTriangle[0].position = sf::Vector2f(x + (-0.866 * radius), y + (-0.5 * radius));
	uprightTriangle[1].position = sf::Vector2f(x + (0.866 * radius), y + (-0.5 * radius));
	uprightTriangle[2].position = sf::Vector2f(x + (0 * radius), y + (1 * radius));

	// define the color of the uprightTriangle's points
	uprightTriangle = colourAsignment(uprightTriangle, firstColor, secondColor, thirdColor);

	VertexArray dowrightTriangle(sf::Triangles, 3);

	// define the position of the dowrightTriangle's points
	dowrightTriangle[0].position = sf::Vector2f(x + (-0.866 * radius), y - (-0.5 * radius));
	dowrightTriangle[1].position = sf::Vector2f(x + (0.866 * radius), y - (-0.5 * radius));
	dowrightTriangle[2].position = sf::Vector2f(x + (0 * radius), y - (1 * radius));

	// define the color of the dowrightTriangle's points
	dowrightTriangle = colourAsignment(dowrightTriangle, firstColor, secondColor, thirdColor);

	VertexArray* unifiedTriangles = new VertexArray[2];
	unifiedTriangles[0] = uprightTriangle;
	unifiedTriangles[1] = dowrightTriangle;
	
	this->saw = unifiedTriangles;
}

VertexArray  Saw::colourAsignment(VertexArray triangleShape, Color firstColor, Color secondColor, Color thirdColor)
{
	triangleShape[0].color = firstColor;
	triangleShape[1].color = secondColor;
	triangleShape[2].color = thirdColor;
	return triangleShape;
}

void Saw::setPosition(Vector2f position)
{
	this->position = position;
}
Vector2f Saw::getPosition()
{
	return this->position;
}

void Saw::render(RenderTarget& target, int rotationDegree, Color firstColor, Color secondColor, Color thirdColor)
{
	sf::Transform transform;
	transform.rotate(rotationDegree, this->getPosition());
	target.draw(this->saw[0], transform);
	target.draw(this->saw[1], transform);

	//saw[0][0] = transform.transformPoint(saw[0][0].position);
	//saw[0][0].color = saw[0][0].color= sf::Color::Red;
	//saw[0][1] = transform.transformPoint(saw[0][1].position);
	//saw[0][1].color = saw[0][1].color = sf::Color::Blue;
	//saw[0][2] = transform.transformPoint(saw[0][2].position);
	//saw[0][2].color = saw[0][2].color = sf::Color::Green;
	//saw[1][0] = transform.transformPoint(saw[1][0].position);
	//saw[1][0].color = saw[1][0].color = sf::Color::Red;
	//saw[1][1] = transform.transformPoint(saw[1][1].position);
	//saw[1][1].color = saw[1][1].color = sf::Color::Blue;
	//saw[1][2] = transform.transformPoint(saw[1][2].position);
	//saw[1][2].color = saw[1][2].color = sf::Color::Green;
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			saw[i][j] = transform.transformPoint(saw[i][j].position);
		}
	}
	saw[0] = colourAsignment(saw[0], firstColor, secondColor, thirdColor);
	saw[1] = colourAsignment(saw[1], firstColor, secondColor, thirdColor);
}