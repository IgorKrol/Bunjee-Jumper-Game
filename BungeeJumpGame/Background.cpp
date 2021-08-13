#include "Background.h"
#include "TextureMap.h"
#include <iostream>



Background::Background()
{
	initBackImage();
}

Background::~Background()
{
}

void Background::initBackImage()
{
	backImage.setTexture(TextureMap::getInstance().getTexture("Sky_Background"));
}

void Background::render(RenderWindow& target)
{
	target.draw(backImage);
}
