#include "Game.h"

using namespace sf;

// first global variables initializer
void Game::initVariables()
{
	this->window = nullptr;
	this->player = nullptr;
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



//public

//ctor dtor
Game::Game()
{
	initVariables();
	initWindow();
	initBackground();
	initPlayer();
	
	trap = new SpinningSawTrap(Vector2f(200, 200), sf::Color::Red, sf::Color::Blue, sf::Color::Green);
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
	FloatRect playerPos = player->getPosition();
	Vector2f newPos = Vector2f(playerPos.left, playerPos.top);
	auto windowSize = window->getSize();
	//left
	if (playerPos.left < 0) {
		newPos.x = 0.f;
	}
	//right
	else if (playerPos.left + playerPos.width > windowSize.x) {
		newPos.x = windowSize.x - playerPos.width;
	}
	//top
	if (playerPos.top < 0) {
		newPos.y = 0.f;
	}
	//bottom
	else if (playerPos.top + playerPos.height > windowSize.y) {
		newPos.y = windowSize.y - playerPos.height;
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

	trap->render(*window, sf::Color::Red, sf::Color::Blue, sf::Color::Green);

	window->display();
}
