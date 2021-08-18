#include "Game.h"
#include "BaseParameters.h"
#include "SawParameters.h"
#include <iostream>

using namespace sf;

// first global variables initializer
void Game::initVariables()
{
	this->window = nullptr;
	this->player = nullptr;
	background = nullptr;
	playerHealth = nullptr;
}

// first initilizer for window
void Game::initWindow()
{
	videoMode.width = 800;
	videoMode.height = 600;

	this->window = new RenderWindow(videoMode, "Bunjee Game", Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initBackground()
{
	background = new Background();
}

// first player initializer
void Game::initPlayer()
{
	player = new Player();
}

void Game::initHealthBar()
{
	playerHealth = new Health(100);
}



//public

//ctor dtor
Game::Game()
{
	initVariables();
	initWindow();
	initBackground();
	initPlayer();
	initHealthBar();
	trap = new SpinningSawTrap(Vector2f(200, 200), BaseParameters::Default(), SawParameters::Default());
}

Game::~Game()
{
	delete this->window;
	delete this->player;

}


const bool Game::running() const
{
	return window->isOpen();
}

// basic event handler for window -> closing for now.
void Game::pollEvents()
{
	while (window->pollEvent(ev)) {

		switch (ev.type) {
		case Event::Closed():
			window->close();
			break;
		case Event::KeyPressed:
			if (ev.Event::key.code == Keyboard::Escape)
				window->close();
			break;
		}
	}
}

// update player movement based on key pressed and correct if collides with window
void Game::updatePlayerMovement()
{
	//player movement
	movePlayer();

	// global window player collisions corrections
	boundPlayer();
}

// move player depends on key pressed
void Game::movePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player->move(-1.f, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		player->move(1.f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		player->move(0.f, -1.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		player->move(0.f, 1.f);
	}
}

// correct collisions with window
void Game::boundPlayer()
{
	Vector2f playerPos = player->getPosition();
	auto windowSize = window->getSize();
	Vector2f newPos = Vector2f(playerPos.x, playerPos.y);

	// correction from origin center point to shape's bounds
	auto correctX = player->getSize().x / 2;
	auto correctY = player->getSize().y / 2;

	//left
	if (playerPos.x < 0 + correctX) {
		newPos.x = 0.f + correctX;
	}
	//right
	else if (playerPos.x > windowSize.x - correctX) {
		newPos.x = windowSize.x - correctX;
	}
	//top
	if (playerPos.y < 0 + correctY) {
		newPos.y = 0.f + correctY;
	}
	//bottom
	else if (playerPos.y > windowSize.y - correctY) {
		newPos.y = windowSize.y - correctY;
	}
	player->setPosition(newPos);

}

// methods
void Game::update()
{
	pollEvents();

	updatePlayerMovement();

}

// clear -> draw -> display
void Game::render()
{
	window->clear();

	background->render(*window);

	player->render(*window);

	trap->render(*window);

	playerHealth->render(*window);

	window->display();
}
