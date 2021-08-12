#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

using namespace sf;

class Game
{

private:
	// Variables
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	Player* player;


	// Methods

	void initVariables();
	void initWindow();
	void initPlayer();

public:

	// Ctor & Dtor
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Methods
	void pollEvents();
	void updatePlayerMovement();
	void movePlayer();
	void boundPlayer();

	void update();
	void render();
};
