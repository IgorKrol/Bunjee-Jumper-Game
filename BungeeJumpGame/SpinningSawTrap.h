#pragma once
#include "Saw.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SpinningSawTrap 
{
public:SpinningSawTrap(Vector2f position);
	  virtual ~SpinningSawTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void render(RenderTarget& target);

private: Vector2f position;
	   sf::VertexArray base;
	   Saw* saw;
	   void initBase(int x, int y);
};

