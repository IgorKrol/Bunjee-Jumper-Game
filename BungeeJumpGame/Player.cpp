#include "Player.h"
#include "TextureMap.h"
#include <iostream>
using namespace std;

//initiate player's texture and shape
void Player::initSprite()
{
	shape.setTexture(TextureMap::getInstance().getTexture("Player"));
	shape.scale(0.2f,0.2f);
}

// construct and init main variables for character
Player::Player()
{
	this->movementSpeed = 4.f;
	initSprite();
}

// destructor 
Player::~Player()
{
}

// returns character position as FloatRect contains sides location and size
FloatRect Player::getPosition()
{
	return shape.getGlobalBounds();
}

// set new position on window for character, from top-left corner
void Player::setPosition(Vector2f pos)
{
	shape.setPosition(pos);
}

void Player::move(const float dirX, const float dirY)
{
	shape.move(movementSpeed * dirX, movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(RenderTarget& target)
{
	target.draw(this->shape);
}
