#include "Background.h"
#include "TextureMap.h"
#include <iostream>
#include <random>



Background::Background()
{
	initBackImage();
	initCloudList();
}

Background::~Background()
{
	for (auto c : cloudList) {
		delete c;
	}
}

// initialize background image (sky)
void Background::initBackImage()
{
	backImage.setTexture(TextureMap::getInstance().getTexture("Sky_Background"));
}

// initialize different cloud shapes and random positions
void Background::initCloudList()
{
	Sprite* temp;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
			temp = new Sprite(TextureMap::getInstance()
				.getTexture("Cloud_" + to_string(rand()%20+1)));

			float x = i*200 % 600;
			float y = i*500 % 600;
			Vector2f tempVec(x, y);
			temp->setPosition(tempVec);
			temp->setColor(Color(255,255,255,(rand() % 155)+100));
			cloudList.push_back(temp);
	}



}

void Background::animateClouds()
{
	
}

// render background -> sky + clouds
void Background::render(RenderWindow& target)
{
	target.draw(backImage);
	for (auto c : cloudList) {
		target.draw(*c);
	}
}
