#include "Saw.h"
#include <iostream>
using namespace std;

Saw::Saw(Vector2f position) 
{
	setPosition(position);
	initSaw(position.x, position.y);
}

Saw::~Saw()
{
}

void Saw::initSaw(int x, int y)
{
	int radius = 35;
	VertexArray uprightTriangle(sf::Triangles, 3);


	// define the position of the uprightTriangle's points
	uprightTriangle[0].position = sf::Vector2f(x + (-0.866 * radius), y + (-0.5 * radius));
	uprightTriangle[1].position = sf::Vector2f(x + (0.866 * radius), y + (-0.5 * radius));
	uprightTriangle[2].position = sf::Vector2f(x + (0 * radius), y + (1 * radius));

	// define the color of the uprightTriangle's points
	uprightTriangle[0].color = sf::Color::Red;
	uprightTriangle[1].color = sf::Color::Blue;
	uprightTriangle[2].color = sf::Color::Green;

	VertexArray dowrightTriangle(sf::Triangles, 3);

	// define the position of the dowrightTriangle's points
	dowrightTriangle[0].position = sf::Vector2f(x + (-0.866 * radius), y - (-0.5 * radius));
	dowrightTriangle[1].position = sf::Vector2f(x + (0.866 * radius), y - (-0.5 * radius));
	dowrightTriangle[2].position = sf::Vector2f(x + (0 * radius), y - (1 * radius));

	// define the color of the dowrightTriangle's points
	dowrightTriangle[0].color = sf::Color::Red;
	dowrightTriangle[1].color = sf::Color::Blue;
	dowrightTriangle[2].color = sf::Color::Green;

	VertexArray* unifiedTriangles = new VertexArray[2];
	unifiedTriangles[0] = uprightTriangle;
	unifiedTriangles[1] = dowrightTriangle;
	
	this->saw = unifiedTriangles;
}

void Saw::setPosition(Vector2f position)
{
	this->position = position;
}
Vector2f Saw::getPosition()
{
	return this->position;
}

void Saw::render(RenderTarget& target, int rotationDegree)
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
	saw[0][0].color = saw[0][0].color = sf::Color::Red;
	saw[0][1].color = saw[0][1].color = sf::Color::Blue;
	saw[0][2].color = saw[0][2].color = sf::Color::Green;
	saw[1][0].color = saw[1][0].color = sf::Color::Red;
	saw[1][1].color = saw[1][1].color = sf::Color::Blue;
	saw[1][2].color = saw[1][2].color = sf::Color::Green;

	
}