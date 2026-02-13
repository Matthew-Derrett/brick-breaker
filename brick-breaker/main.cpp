#include "Game.h"

int main(int argC, char* argV[])
{
	Game* game = new Game{ 1080, 720, "Brick Breaker", BLACK };

	int result = game->Run();

	delete game;

	return result;
}