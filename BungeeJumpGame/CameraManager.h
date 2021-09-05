#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class CameraManager
{
	// variables
	sf::RenderWindow* window;
	sf::View* mainCamera;
	sf::IntRect borders;

public:
	CameraManager(sf::RenderWindow* rw);
	~CameraManager();

	bool Contains(Player& player);
	void move(float dirX, float dirY);
	void setPosition(Vector2f pos);
	void BorderCollisionsCorrection();
	void update(Player& player);
	void keepPlayerContained(Player& player);


};

