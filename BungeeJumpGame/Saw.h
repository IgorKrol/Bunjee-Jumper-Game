#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Saw : public sf::Transformable
{
public:
	Saw(Vector2f position, Color firstColor, Color secondColor, Color thirdColor);
	  virtual ~Saw();
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void render(RenderTarget& target, int rotationDegree, Color firstColor, Color secondColor, Color thirdColor);

private: 
	sf::VertexArray* saw;
	Vector2f position;
	void initSaw(int x, int y, Color firstColor, Color secondColor, Color thirdColor);
	VertexArray colourAsignment(VertexArray triangleShape, Color firstColor, Color secondColor, Color thirdColor);
};
	  

