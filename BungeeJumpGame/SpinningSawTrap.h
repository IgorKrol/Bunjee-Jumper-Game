#pragma once
#include "Saw.h"
#include "TrapBase.h"
#include "BaseParameters.h"
#include "SawParameters.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SpinningSawTrap 
{
public:
	SpinningSawTrap(Vector2f position, BaseParameters bp, SawParameters sp);
	  virtual ~SpinningSawTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	Vector2f* getTrapDimensions();
	Vector2f getSize();
	void render(RenderTarget& target);

private: Vector2f position;
	  TrapBase* base;
	   Saw* saw;
};

