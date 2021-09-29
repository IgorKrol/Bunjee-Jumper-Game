#include "Background.h"
#include "TextureMap.h"
#include <iostream>
//#include <random>
#include "Randomization.h"



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

Vector2u Background::getSize()
{
	return Vector2u(backImage.getGlobalBounds().width, backImage.getGlobalBounds().height);
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
	for (int i = 0; i < 40; i++) {
			temp = new Sprite(TextureMap::getInstance()
				.getTexture("Cloud_" + to_string((int)Randomization::getRundomNumber(1,20,true))));

			float x = Randomization::getRundomNumber(200, 3800, true);
			float y = Randomization::getRundomNumber(200, 3800, true);

			Vector2f tempVec(x, y);
			temp->setPosition(tempVec);
			temp->setColor(Color(255,255,255,(int)Randomization::getRundomNumber(155, 255, true)));
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
