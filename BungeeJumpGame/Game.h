#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Background.h"
#include "TextureMap.h"
#include "SpinningSawTrap.h"
#include "PendulumTrap.h"
#include "PlayerHealth.h"
#include "CameraManager.h"


using namespace sf;

class Game
{

private:
	// v2u topleft corner, v2u size
	IntRect GLOBAL_BORDERS;
	

	// Variables
	float dt;
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	Player* player;
	Background* background;
	SpinningSawTrap* trap;
	PendulumTrap* pendulum;
	PlayerHealth* playerHealth;
	CameraManager* camera;


	// Methods

	void initVariables();
	void initWindow();
	void initBackground();
	void initPlayer();
	void initHealthBar();
	void initView();
	void initBorders();

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
