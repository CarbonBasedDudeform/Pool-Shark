/*
	===========================Summary============================
	This class manages the game, it's states and all it's objects.
*/

#include "Game.h"

//----------CONST DEFINITIONS----------
const sf::String Game::GAME_TITLE = "test";


//----------CONSTRUCTORS AND DESTRUCTORS----------
Game::Game()
{
}


Game::~Game()
{
}

Game * Game::_instance = nullptr;
Game * Game::GetInstance() {
	if (_instance == nullptr) {
		_instance = new Game();
	} 

	return _instance;
}

//---------MAIN GUT OF THE CODE, INITIALISING, GAME LOOP, RENDERING--------------
void Game::Init() {
	_window = new sf::RenderWindow(sf::VideoMode(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT), Game::GAME_TITLE);
	
	_backgroundMusic = new Music();
	_backgroundMusic->Play();

	_drawables = new std::list<IDrawable *>();
	_drawables->push_back(new Room());

	//ensures use of vertex arrays is possible as all drawables will use vertex arrays
	//NOTE: should be switching to VBOs for most stuff so this might not be necessery
	glEnableClientState(GL_VERTEX_ARRAY);
}

void Game::Loop() {

	while (_window->isOpen())
	{
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}

		_window->clear();
		Draw();
		_window->display();
	}
}

void Game::Draw() const {
	for (auto iterator = _drawables->begin(); iterator != _drawables->end(); ++iterator) {
		iterator._Ptr->_Myval->Draw();
	}
}