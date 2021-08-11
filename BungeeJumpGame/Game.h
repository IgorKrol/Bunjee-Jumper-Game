#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Game
{

private:
	// Variables
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;


	// Methods

	void initVariables();
	void initWindow();

public:

	// Ctor & Dtor
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Methods
	void pollEvents();
	void update();
	void render();
};
