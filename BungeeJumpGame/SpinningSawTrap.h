#pragma once
#include "Saw.h"
#include "Base.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SpinningSawTrap 
{
public:SpinningSawTrap(Vector2f possition, int sawRotationDegree, int baseRotationDegree, int sawRadius, int baseWidth, int baseHeigth, Color sawFirstColor, Color sawSecondColor, Color sawThirdColor, Color baseFirstColor, Color baseSecondColor, Color baseThirdColor, Color baseForthColor);
	  virtual ~SpinningSawTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void render(RenderTarget& target);

private: Vector2f position;
	  Base* base;
	   Saw* saw;
};

