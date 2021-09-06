#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class PlayerHealth
{
	int maxHealth;
	int currentHealth;
	
	Vector2f pos;
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
	// set new position for UI - based on view
	void setPosition(Vector2f viewTL);

	// update UI location
	void updateLocation();
	// renders health on screen
	void render(RenderTarget& target);

};

