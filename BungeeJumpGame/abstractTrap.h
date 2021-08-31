#include <SFML/Graphics.hpp>
#include <array>

using namespace sf;
class AbstractTrap
{
	public:
		virtual std::array<sf::Sprite, 2> getSprites()=0;
		virtual void render() = 0;
};

