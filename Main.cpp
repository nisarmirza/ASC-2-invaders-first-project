#include <windows.h>
#include "Game\Game.h"
#include <cstdlib>

int main()
{
	srand(0);

	Game game;

	game.Initialise();

	game.Run();
	
	return 0;
}
