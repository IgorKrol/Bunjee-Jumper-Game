#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Background
{
	Sprite backImage;

	void initBackImage();

public:

	Background();
	virtual ~Background();

	void render(RenderWindow& target);
};

