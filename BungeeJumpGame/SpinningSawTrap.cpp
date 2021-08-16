#include "SpinningSawTrap.h"
#include "Saw.h"
#include <iostream>
using namespace std;

SpinningSawTrap::SpinningSawTrap(Vector2f possition, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor)
{
	setPosition(possition);
	initBase(position.x, position.y);
	saw = new Saw(possition, sawFirstColor, sawSecondColor, sawThirdColor);
}

SpinningSawTrap::~SpinningSawTrap()
{

}

 void SpinningSawTrap::initBase(int x, int y)
{
	sf::VertexArray rectangle(sf::Quads, 4);

	// define the position of the rectangle's points
	rectangle[0].position = sf::Vector2f(x - 25.f, y - 25.f);
	rectangle[1].position = sf::Vector2f(x + 25.f, y - 25.f);
	rectangle[2].position = sf::Vector2f(x + 25.f, y + 25.f);
	rectangle[3].position = sf::Vector2f(x - 25.f, y + 25.f);

	// define the color of the rectangle's points
	rectangle[0].color = sf::Color::Black;
	rectangle[1].color = sf::Color::Red;
	rectangle[2].color = sf::Color::Black;
	rectangle[3].color = sf::Color::Red;

	this->base = rectangle;
}

void SpinningSawTrap::setPosition(Vector2f position)
{
	this->position = position;
}
Vector2f SpinningSawTrap::getPosition()
{
	return this->position ;
}
void SpinningSawTrap::render(RenderTarget& target, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor)
{
	
	target.draw(this->base);
	this->saw->render(target, 10, sawFirstColor, sawSecondColor, sawThirdColor);
}