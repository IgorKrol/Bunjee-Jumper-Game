#include "PlayerHealth.h"
#include <SFML/Graphics.hpp>

class UIManager
{
	PlayerHealth* healthUI;

public:
	UIManager();
	~UIManager();

	void render(sf::RenderTarget& target);
};
