#include "PlayerHealth.h"
#include "TextureMap.h"
#include <iostream>

PlayerHealth::PlayerHealth(int maxHealth)
{

	this->currentHealth = maxHealth;
	this->maxHealth = maxHealth;
	initResourses();
}

PlayerHealth::~PlayerHealth()
{
}

void PlayerHealth::initResourses()
{
	heartShape.setTexture(TextureMap::getInstance().getTexture("Heart"));
	if (!font.loadFromFile("Resources/terminal.ttf")) {
		std::cout << "ERROR::HEALTH::HEALTH::failed to load font" << std::endl;
	}

	heartShape.setPosition(10, 15);
	heartShape.scale(0.25, 0.25);

	text.setFont(font);
	text.setString(std::to_string(currentHealth));
	text.setCharacterSize(60);
	text.setFillColor(Color::White);
	text.setOutlineThickness(1);
	text.setPosition(70, 0);
}

int PlayerHealth::addHealth(int amount)
{
	currentHealth += amount;
	if (currentHealth > maxHealth)
		currentHealth = maxHealth;

	text.setString(std::to_string(currentHealth));
	return currentHealth;
}

int PlayerHealth::lowerHealth(int amount)
{
	currentHealth -= amount;
	if (currentHealth < 0)
		currentHealth = 0;

	text.setString(std::to_string(currentHealth));
	return currentHealth;
}

const int PlayerHealth::getHealth()
{
	return currentHealth;
}

void PlayerHealth::render(RenderTarget& target)
{
	target.draw(heartShape);
	target.draw(text);
}
