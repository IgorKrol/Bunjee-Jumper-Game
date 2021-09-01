#pragma once
#include"TextureMap.h"
#include "AbstractTrap.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class SpinningSawTrap : public AbstractTrap
{
public:
	SpinningSawTrap(Vector2f position,int rotationDegree);
	  virtual ~SpinningSawTrap();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setRotationDegree(int rotationDegree);
	int getRotationDegree();
	Vector2f getSize();
	void sawRotate(int rotationDegree);
	Sprite& getSprite();
	vector<Sprite> getSprites();
	void render(RenderTarget& target);

private: Vector2f position;
	   Sprite saw;
	   int rotationDegree;
	   void initSprite(Vector2f position);
};

