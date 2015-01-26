/*
	===========================Summary============================
	This class manages the game, it's states and all it's objects.
*/

#include "Game.h"

//----------CONST DEFINITIONS----------
const char * Game::GAME_TITLE = "test";


//----------CONSTRUCTORS AND DESTRUCTORS----------
Game::Game()
{
}


Game::~Game()
{
	SDL_Quit();
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
	
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		_surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_OPENGL);

		_running = true;

		_backgroundMusic = new Music();
		_backgroundMusic->Play();

		_drawables = new std::list<IDrawable *>();
		_drawables->push_back(new Room());

		//setup opengl
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1, 1000.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glEnable(GL_VERTEX_ARRAY);
		glEnable(GL_COLOR_ARRAY);
		glEnable(GL_CULL_FACE);
		glFrontFace(AD_CLOCKWISE);
		glCullFace(GL_BACK);
	}
}

void Game::Loop() {
	SDL_Event e;
	while (_running) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				_running = false;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Draw();		
		SDL_GL_SwapBuffers();
	}
	
}

void Game::Draw() const {
	for (auto iterator = _drawables->begin(); iterator != _drawables->end(); ++iterator) {
		iterator._Ptr->_Myval->Draw();
		iterator._Ptr->_Myval->rotation += 0.1f;
	}
}