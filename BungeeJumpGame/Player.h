#pragma once

#include <SFML/Graphics.hpp>
#include "SpinningSawTrap.h"


using namespace sf;

/// <summary>
/// representing playable character
/// </summary>
class Player
{
	Sprite shape;
	float movementSpeed;
	bool isInvincible = false;

	void initSprite(Vector2u startPosition);

public:
	Player(Vector2u startPosition);
	virtual ~Player();

	bool getInvincibilityFrames() { return isInvincible; }
	void setInvincibilityFrames(bool isInv) { isInvincible = isInv; }

	// returns character position center point as Vector2f
	Vector2f getPosition();

	// returns (width,height)
	Vector2f getSize();

	// set new position (center point) on window for character, from top-left corner
	void setPosition(Vector2f pos);

	//move player function +dirX horizontal, +dirY vertical, negative will go to other direction
	void move(const float dirX, const float dirY);

	// checks if player collides wich a trap
	bool checkCollider(SpinningSawTrap& trap);

	//update any changes for the character
	void update();

	//render character on screen
	void render(RenderTarget& target);


};
