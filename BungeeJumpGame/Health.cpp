#include "Health.h"
#include "TextureMap.h"
#include <iostream>

Health::Health(int maxHealth)
{

	this->currentHealth = maxHealth;
	this->maxHealth = maxHealth;
	initResourses();
}

Health::~Health()
{
}

void Health::initResourses()
{
	heartShape.setTexture(TextureMap::getInstance().getTexture("Heart"));
	if (!font.loadFromFile("Resourses/terminal.ttf")) {
		std::cout << "ERROR::HEALTH::HEALTH::failed to load font" << std::endl;
	}

	heartShape.setPosition(10, 15);
	heartShape.scale(0.25, 0.25);

	text.setFont(font);
	text.setString(to_string(currentHealth));
	text.setCharacterSize(60);
	text.setFillColor(Color::White);
	text.setOutlineThickness(1);
	text.setPosition(70, 0);
}

int Health::addHealth(int amount)
{
	currentHealth += amount;
	if (currentHealth > maxHealth)
		currentHealth = maxHealth;
	return currentHealth;
}

int Health::lowerHealth(int amount)
{
	currentHealth -= amount;
	if (currentHealth < 0)
		currentHealth = 0;
	return currentHealth;
}

const int Health::getHealth()
{
	return currentHealth;
}

void Health::render(RenderTarget& target)
{
	target.draw(heartShape);
	target.draw(text);
}
