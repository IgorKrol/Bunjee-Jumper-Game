#pragma once
#include "Saw.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SpinningSawTrap 
{
public:SpinningSawTrap(Vector2f position, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor);
	  virtual ~SpinningSawTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void render(RenderTarget& target, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor);

private: Vector2f position;
	   sf::VertexArray base;
	   Saw* saw;
	   void initBase(int x, int y);
};

