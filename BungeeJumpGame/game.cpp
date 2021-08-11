
#include "Game.h"

using namespace sf;


// private


void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	videoMode.width = 800;
	videoMode.height = 600;

	this->window = new RenderWindow(videoMode, "Bunjee Game", Style::Default);
}


//public

//ctor dtor
Game::Game()
{
	initVariables();
	initWindow();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return window->isOpen();
}


void Game::pollEvents()
{
	while (window->pollEvent(ev)) {

		switch (ev.type) {
		case Event::Closed():
			window->close();
			break;
		}

	}
}

// methods
void Game::update()
{
	pollEvents();
}

// clear -> draw -> display
void Game::render()
{
	window->clear(Color::Blue);

	window->display();
}
