#include "Game.h"

int main()
{
	Game * _game = Game::GetInstance();
	_game->Init();

	_game->Loop();

	return 0;
}