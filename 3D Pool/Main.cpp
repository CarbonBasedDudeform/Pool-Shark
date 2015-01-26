#include "Game.h"

int main(int argc, char *argv[])
{
	Game * _game = Game::GetInstance();
	_game->Init();

	_game->Loop();

	return 0;
}