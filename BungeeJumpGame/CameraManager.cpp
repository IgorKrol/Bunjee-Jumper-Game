#include "CameraManager.h"
#include <iostream>

CameraManager::CameraManager(sf::RenderWindow* rw)
{
	this->window = rw;
	auto size = rw->getSize();
	borders = sf::IntRect(400, 300, 3600, 3700);
	this->mainCamera = new sf::View(sf::FloatRect(0, 0, size.x, size.y));

	rw->setView(*mainCamera);
}

CameraManager::~CameraManager()
{
	delete mainCamera;
}

bool CameraManager::Contains(Player& player)
{
	return false;
}

void CameraManager::move(float dirX, float dirY)
{
	mainCamera->move(dirX, dirY);
	BorderCollisionsCorrection();
}

void CameraManager::setPosition(Vector2f pos)
{
	mainCamera->setCenter(pos);
}

void CameraManager::BorderCollisionsCorrection()
{
	//left
	if (mainCamera->getCenter().x < borders.left) {
		mainCamera->setCenter(borders.left, mainCamera->getCenter().y);
	}
	//right
	else if(mainCamera->getCenter().x > borders.width) {
		mainCamera->setCenter(borders.width, mainCamera->getCenter().y);
	}
	//top
	if (mainCamera->getCenter().y < borders.top) {
		mainCamera->setCenter(mainCamera->getCenter().x, borders.top);
	}
	//bottom
	else if(mainCamera->getCenter().y > borders.height){
		mainCamera->setCenter(mainCamera->getCenter().x, borders.height);
	}
}

void CameraManager::update(Player& player)
{
	//std::cout << mainCamera->getCenter().x << "," << mainCamera->getViewport().contains() << std::endl;
	this->window->setView(*mainCamera);
}
