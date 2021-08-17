#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

/// <summary>
/// representing playable character
/// </summary>
class Player
{
	Sprite shape;
	float movementSpeed;

	void initSprite();

public:
	Player();
	virtual ~Player();

	// returns character position as FloatRect contains sides location and size
	Vector2f getPosition();

	Vector2f getSize();

	// set new position on window for character, from top-left corner
	void setPosition(Vector2f pos);

	//move player function +dirX horizontal, +dirY vertical, negative will go to other direction
	void move(const float dirX, const float dirY);

	//update any changes for the character
	void update();

	//render character on screen
	void render(RenderTarget& target);


};
