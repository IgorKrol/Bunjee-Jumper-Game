#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Saw : public sf::Transformable
{
public:
	Saw(Vector2f position, int rotationDegree, int radius, Color firstColor, Color secondColor, Color thirdColor);
	  virtual ~Saw();
	void setPosition(Vector2f position);
	void setRotationDegree(int rotationDegree);
	int getRotationDegree();
	Vector2f getPosition();
	void setRadius(int radius);
	int getRadius();
	void render(RenderTarget& target);

private: 
	sf::VertexArray* saw;
	Vector2f position;
	Color colors[3];
	int rotationDegree;
	int radius;
	void setColors(Color firstColor, Color secondColor, Color thirdColor);
	Color* getColors();
	void initSaw(int x, int y, int radius, Color firstColor, Color secondColor, Color thirdColor);
	VertexArray colourAsignment(VertexArray triangleShape);
	
};
	  

