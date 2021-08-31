#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
using namespace std;
using namespace sf;

class Background
{
	Sprite backImage;
	std::list<Sprite*> cloudList;

	void initBackImage();
	void initCloudList();

	void animateClouds();

public:

	Background();
	virtual ~Background();

	Vector2u getSize();

	void update();
	void render(RenderWindow& target);
};

