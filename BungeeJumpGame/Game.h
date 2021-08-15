#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Background.h"
#include "TextureMap.h"
#include "SpinningSawTrap.h"

using namespace sf;

class Game
{

private:
	// Variables
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	Player* player;
	Background* background;
	SpinningSawTrap* trap;


	// Methods

	void initVariables();
	void initWindow();
	void initBackground();
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
