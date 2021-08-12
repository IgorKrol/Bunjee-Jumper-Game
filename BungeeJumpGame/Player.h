#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;


class Player
{
	Texture texture;
	Sprite sprite;
	float movementSpeed;

	void initSprite();
	void initTexture();

public:
	Player();
	virtual ~Player();

	FloatRect getPosition();
	void setPosition(Vector2f pos);

	void move(const float dirX, const float dirY);
	void update();
	void render(RenderTarget& target);


};
