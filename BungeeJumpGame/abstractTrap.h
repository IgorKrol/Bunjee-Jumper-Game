#pragma once
#include <SFML/Graphics.hpp>
#include <array> // doesn't compile without it. Why?

using namespace sf;
class AbstractTrap
{
	public:
		virtual std::vector<Sprite> getSprites()=0;
		virtual void render(RenderTarget& target) = 0;
};

