#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class PlayerHealth
{
	int maxHealth;
	int currentHealth;
	
	Sprite heartShape;
	Font font;
	Text text;


public:
	PlayerHealth(int maxHealth);
	~PlayerHealth();

	// init resourses + text
	void initResourses();
	// heals player, returns remain health
	int addHealth(int amount);
	// damages player, returns remain health
	int lowerHealth(int amount);
	// return number of health
	const int getHealth();

	// renders health on screen
	void render(RenderTarget& target);

};

