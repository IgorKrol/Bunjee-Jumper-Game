#include "Game.h"
#include <iostream>
#include <thread>

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

	this->window = new RenderWindow(videoMode, "Bungee Game", Style::Default);
	this->window->setFramerateLimit(60);
}

vector<pair<bool, AbstractTrap*>>* Game::traps = new vector<pair<bool, AbstractTrap*>>;

void Game::initBackground()
{
	background = new Background();
}

// first player initializer
void Game::initPlayer()
{
	player = new Player(Vector2u(GLOBAL_BORDERS.width / 2, GLOBAL_BORDERS.height / 2));
}

void Game::initHealthBar()
{
	playerHealth = new PlayerHealth(100);
}



//public

void Game::initView()
{
	this->camera = new CameraManager(this->window);
}

//ctor dtor
Game::Game()
{
	initVariables();
	initWindow();
	initBackground();
	initBorders();
	initPlayer();
	initHealthBar();
	initView();
	//if (PendulumTrap* actualCreatedTrap = dynamic_cast<PendulumTrap*>(pendulum))
	//{
	//	actualCreatedTrap->initInitialAxeRotationDegree(289);
	//	actualCreatedTrap->initInitialBaseRotationDegree(0);
	//}
	//pendulum->initInitialAxeRotationDegree(180);
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

void Game::initBorders()
{
	int topLeftX = float(window->getSize().x) / 2;
	int topLeftY = float(window->getSize().y) / 2;

	int sizeX = background->getSize().x - float(window->getSize().x) / 2;
	int sizeY = background->getSize().y - float(window->getSize().y) / 2;

	GLOBAL_BORDERS = IntRect(topLeftX, topLeftY, sizeX, sizeY);
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
	//boundPlayer();
	camera->keepPlayerContained(*player);

}

// move player depends on key pressed
void Game::movePlayer()
{
	float delta = 0.5f;
	
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player->move(-delta, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		player->move(delta, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		player->move(0.f, -delta);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		player->move(0.f, delta);
	}

	//if (Keyboard::isKeyPressed(Keyboard::A)) {
	//	player->move(-1.f, 0.f);
	//}
	//else if (Keyboard::isKeyPressed(Keyboard::D)) {
	//	player->move(1.f, 0.f);
	//}
	//if (Keyboard::isKeyPressed(Keyboard::W)) {
	//	player->move(0.f, -1.f);
	//}
	//else if (Keyboard::isKeyPressed(Keyboard::S)) {
	//	player->move(0.f, 1.f);
	//}
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
	dt = Clock().restart().asSeconds();

	pollEvents();
	for (auto p : *traps) {
		auto trap = p.second;
		//cout << "dsafa" << endl;
		if (player->checkCollider(*trap)) {
			auto invFrames = player->getInvincibilityFrames();
			if (!invFrames) {
				playerHealth->lowerHealth(1);
				std::thread t([this]() {
					player->setInvincibilityFrames(true);
					//invincibility frames
					sleep(seconds(0.6));
					player->setInvincibilityFrames(false);
					});
				t.detach();
			}
		}
	}


	//if (player->checkCollider(*pendulum)) {
	//	auto invFrames = player->getInvincibilityFrames();
	//	if (!invFrames) {
	//		playerHealth->lowerHealth(1);
	//		std::thread t([this]() {
	//			player->setInvincibilityFrames(true);
	//			//invincibility frames
	//			sleep(seconds(0.6));
	//			player->setInvincibilityFrames(false);
	//			});
	//		t.detach();
	//	}
	//}

	updatePlayerMovement();

	//std::cout << camera->Contains(*player) << std::endl;

	camera->update(*player);

	playerHealth->setPosition(camera->getTopLeftCorner());


}

// clear -> draw -> display
void Game::render()
{
	window->clear();


	background->render(*window);


	random->createRandomTrapOutsideOfView(*window, camera, background, CONST_TRAP_TYPES);

	random->randomCameraMovement(camera);

	player->render(*window);

	playerHealth->render(*window);



	window->display();
}
