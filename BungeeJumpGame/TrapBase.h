#pragma once
#include <SFML/Graphics.hpp>
#include "BaseParameters.h"
using namespace sf;
class TrapBase
{
public:
	TrapBase(Vector2f position, BaseParameters bp);
		virtual ~TrapBase();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setRotationDegree(int rotationDegree);
	int getRotationDegree();
	void setColors(Color firstColor, Color secondColor, Color thirdColor, Color forthColor);
	Color* getColors();
	void render(RenderTarget& target);

private:
	sf::VertexArray base;
	Vector2f position;
	Color colors[4];
	int height;
	int width;
	int rotationDegree;
	void initBase(int x, int y, int width, int height, Color firstColor, Color secondColor, Color thirdColor, Color forthColor);
	VertexArray colourAsignment(VertexArray triangleShape);
};

