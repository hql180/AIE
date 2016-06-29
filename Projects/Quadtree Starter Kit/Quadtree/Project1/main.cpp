#include "Game1.h"

#include <crtdbg.h>

int main(int argc, char **argv)
{
	//Check Game1.cpp for game code
	Game1 *pGame = new Game1(SCREEN_WIDTH, SCREEN_HEIGHT, false, "Game1");

	pGame->RunGame();
	
	delete pGame;

	_CrtDumpMemoryLeaks();

	return 0;
};