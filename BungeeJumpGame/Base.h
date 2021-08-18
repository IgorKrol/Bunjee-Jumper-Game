#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Base
{
public:
	Base(Vector2f position, int rotationDegree, int width, int height, Color firstColor, Color secondColor, Color thirdColor, Color forthColor);
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setRotationDegree(int rotationDegree);
	int getRotationDegree();
	void render(RenderTarget& target);

private:
	sf::VertexArray base;
	Vector2f position;
	Color colors[4];
	int height;
	int width;
	int rotationDegree;
	void setColors(Color firstColor, Color secondColor, Color thirdColor, Color forthColor);
	Color* getColors();
	void initBase(int x, int y, int width, int height, Color firstColor, Color secondColor, Color thirdColor, Color forthColor);
	VertexArray colourAsignment(VertexArray triangleShape);
};

