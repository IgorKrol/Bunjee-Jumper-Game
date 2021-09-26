#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

class CameraManager
{
private:
	// variables
	sf::RenderWindow* window;
	sf::View* mainCamera;
	sf::IntRect borders;

	int time=-1;
	int counterToTime=0;
	Vector2f movementDelta;


public:
	CameraManager(sf::RenderWindow* rw);
	~CameraManager();

	bool Contains(Player& player);
	void move(float dirX, float dirY);
	void setMovementDelta(Vector2f movementDelta);
	Vector2f getMovementDelta();
	void setPosition(Vector2f pos);
	void setTime(int time);
	int getTime();
	void setCounterToTime(int counterToTime);
	int getCounterToTime();
	Vector2f getTopLeftCorner();
	Vector2f getBottomRightCorner();
	void randomCameraMovement();
	void BorderCollisionsCorrection();
	void update(Player& player);
	void keepPlayerContained(Player& player);


};

