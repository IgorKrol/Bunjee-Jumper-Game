#include "Player.h"
#include <iostream>
using namespace std;

void Player::initSprite()
{
	sprite.setTexture(this->texture);
	sprite.scale(0.2f,0.2f);
}

void Player::initTexture()
{
	if (!texture.loadFromFile("Textures/Player.png")) {
		cout << "ERROR::PLAYER::INITTEXTURE::Loading texture failed" << endl;
	}
}

Player::Player()
{
	this->movementSpeed = 4.f;
	initTexture();
	initSprite();
}

Player::~Player()
{
}

FloatRect Player::getPosition()
{
	return sprite.getGlobalBounds();
}

void Player::setPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}

void Player::move(const float dirX, const float dirY)
{
	sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
