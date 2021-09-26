#pragma once
#include <SFML/Graphics.hpp>
#include <vector> 

using namespace sf;
//template <class T>
class AbstractTrap
{
	public:
		virtual Vector2f getPosition() = 0;
		virtual std::vector<Sprite> getSprites()=0;
		virtual FloatRect getGlobalBounding()=0;
		virtual void render(RenderTarget& target) = 0;
		//virtual T* getType();

		static AbstractTrap* Create(std::string trapType, Vector2f possition, int RotationDegree);

};

