#include "Player.h"
#include "TextureMap.h"
#include <iostream>
#include "Collision.h"
using namespace std;

//initiate player's texture and shape
void Player::initSprite(Vector2u startPosition)
{
	shape.setTexture(TextureMap::getInstance().getTexture("Player"));
	shape.setOrigin(getSize().x / 2.f, getSize().y / 2.f);
	//shape.setPosition(startPosition.x, startPosition.y);
	shape.setPosition(2000, 2000);
	shape.scale(0.5f,0.5f);
}

// construct and init main variables for character
Player::Player(Vector2u startPosition)
{
	this->movementSpeed = 20.f;
	initSprite(startPosition);
}

// destructor 
Player::~Player()
{
}

// returns character position as FloatRect contains sides location and size
Vector2f Player::getPosition()
{
	return shape.getPosition();
}

Vector2f Player::getSize()
{
	auto b = shape.getGlobalBounds();
	return Vector2f(b.width,b.height);
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

bool Player::checkCollider(AbstractTrap& trap)
{
	//return Collision::PixelPerfectTest(shape, trap.getSprite());
	for (auto sp : trap.getSprites()) {
		if (Collision::PixelPerfectTest(shape, sp)) {
			return true;
		}
	}

	return false;
}

void Player::update()
{
}

void Player::render(RenderTarget& target)
{
	target.draw(this->shape);
}
