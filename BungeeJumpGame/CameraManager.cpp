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

// return false if view does NOT contains player, otherwise return true.
bool CameraManager::Contains(Player& player)
{
	auto tl = mainCamera->getCenter() - (mainCamera->getSize() / 2.f);
	auto br = mainCamera->getCenter() + (mainCamera->getSize() / 2.f);

	auto playerTl = player.getPosition() - (player.getSize() / 2.f);
	auto playerBr = player.getPosition() + (player.getSize() / 2.f);

	if (tl.x > playerTl.x || br.x < playerBr.x
		|| tl.y > playerTl.y || br.y < playerBr.y) {
		return false;

	}

	return true;
}

// move +dirX,+dirY
void CameraManager::move(float dirX, float dirY)
{
	mainCamera->move(dirX, dirY);
	BorderCollisionsCorrection();
}

void CameraManager::setMovementDelta(Vector2f movementDelta)
{
	this->movementDelta = movementDelta;
}
Vector2f CameraManager::getMovementDelta()
{
	return this->movementDelta;
}

void CameraManager::setTime(int time)
{
	this->time = time;
}
int CameraManager::getTime()
{
	return this->time;
}

void CameraManager::setCounterToTime(int counterToTime)
{
	this->counterToTime = counterToTime;
}
int CameraManager::getCounterToTime()
{
	return this->counterToTime;
}

// set view position : pos = view's center point
void CameraManager::setPosition(Vector2f pos)
{
	mainCamera->setCenter(pos);
}

// return top left corner cordinates of this view
Vector2f CameraManager::getTopLeftCorner()
{
	return mainCamera->getCenter() - (mainCamera->getSize() / 2.f);
}

Vector2f CameraManager::getBottomRightCorner()
{
	return mainCamera->getCenter() + (mainCamera->getSize() / 2.f);
}


// limit view to stay inside background domain
void CameraManager::BorderCollisionsCorrection()
{
	//left
	if (mainCamera->getCenter().x < borders.left) {
		mainCamera->setCenter(borders.left, mainCamera->getCenter().y);
		setMovementDelta(Vector2f(-getMovementDelta().x, getMovementDelta().y));
	}
	//right
	else if(mainCamera->getCenter().x > borders.width) {
		mainCamera->setCenter(borders.width, mainCamera->getCenter().y);
		setMovementDelta(Vector2f(-getMovementDelta().x, getMovementDelta().y));
	}
	//top
	if (mainCamera->getCenter().y < borders.top) {
		mainCamera->setCenter(mainCamera->getCenter().x, borders.top);
		setMovementDelta(Vector2f(getMovementDelta().x, -getMovementDelta().y));
	}
	//bottom
	else if(mainCamera->getCenter().y > borders.height){
		mainCamera->setCenter(mainCamera->getCenter().x, borders.height);
		setMovementDelta(Vector2f(getMovementDelta().x, -getMovementDelta().y));
	}
}

//// limit view to stay inside background domain
//void CameraManager::BorderCollisionsCorrection()
//{
//	//left
//	if (mainCamera->getCenter().x < borders.left) {
//		mainCamera->setCenter(borders.left, mainCamera->getCenter().y);
//	}
//	//right
//	else if (mainCamera->getCenter().x > borders.width) {
//		mainCamera->setCenter(borders.width, mainCamera->getCenter().y);
//	}
//	//top
//	if (mainCamera->getCenter().y < borders.top) {
//		mainCamera->setCenter(mainCamera->getCenter().x, borders.top);
//	}
//	//bottom
//	else if (mainCamera->getCenter().y > borders.height) {
//		mainCamera->setCenter(mainCamera->getCenter().x, borders.height);
//	}
//}
// updates view
void CameraManager::update(Player& player)
{
	//std::cout << mainCamera->getCenter().x << "," << mainCamera->getViewport().contains() << std::endl;
	this->window->setView(*mainCamera);
}

// contains player movement inside this view.
void CameraManager::keepPlayerContained(Player& player)
{
	auto tl = mainCamera->getCenter() - (mainCamera->getSize() / 2.f);
	auto br = mainCamera->getCenter() + (mainCamera->getSize() / 2.f);

	auto playerCorrection = player.getSize() / 2.f;

	auto playerTl = player.getPosition() - playerCorrection;
	auto playerBr = player.getPosition() + playerCorrection;

	// left
	if (tl.x > playerTl.x) {
		player.setPosition(Vector2f(tl.x + playerCorrection.x, player.getPosition().y));
	}
	// right
	else if (br.x < playerBr.x) {
		player.setPosition(Vector2f(br.x - playerCorrection.x, player.getPosition().y));
	}
	
	// top
	if (tl.y > playerTl.y) {
		player.setPosition(Vector2f(player.getPosition().x, tl.y + playerCorrection.y));
	}
	// bottom
	else if (br.y < playerBr.y) {
		player.setPosition(Vector2f(player.getPosition().x, br.y - playerCorrection.y));
	}

}
