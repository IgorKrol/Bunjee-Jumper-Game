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

	static PlayerHealth* instance;

public:
	PlayerHealth(int maxHealth);
	~PlayerHealth();

	PlayerHealth(PlayerHealth& other) = delete;
	void operator=(const PlayerHealth&) = delete;

	static PlayerHealth& getInstace() {
		if (instance == nullptr) {
			instance = new PlayerHealth(100);
		}
		return *instance;
	}

	// init resources + text
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

