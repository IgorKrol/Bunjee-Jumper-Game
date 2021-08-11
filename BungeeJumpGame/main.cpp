#include <iostream>
#include "Game.h"
#include "main.h"

using namespace std;

int main() {
	Game game;

	while (game.running())
	{
		game.update();

		game.render();
	}

	return 0;
}