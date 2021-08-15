#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Saw : public sf::Transformable
{
public:void render(RenderTarget& target, int rotationDegree);
	Saw(Vector2f position);
	  virtual ~Saw();
	void setPosition(Vector2f position);
	Vector2f getPosition();

private: sf::VertexArray* saw;
	Vector2f position;
	void initSaw(int x, int y);
};
	  

