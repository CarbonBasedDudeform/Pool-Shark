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

		_camera = new Camera();
		_drawables = new std::vector<IDrawable *>();
		//_drawables->push_back(new Room());
		_drawables->push_back(new Table());

		OpenGLInit();
	}
}

//OpenGL specific initialisation tasks
void Game::OpenGLInit() {
	//setup opengl
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);

	glEnable(GL_VERTEX_ARRAY);
	glEnable(GL_COLOR_ARRAY);

	glEnable(GL_CULL_FACE);
	glFrontFace(AD_CLOCKWISE);
	glCullFace(GL_BACK);
}

void Game::Loop() {
	SDL_Event e;
	while (_running) {
		while (SDL_PollEvent(&e) != 0) {
			ProcessInput(e);
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		_camera->Draw();
		Draw();		
		SDL_GL_SwapBuffers();
	}
}

//render everything
void Game::Draw() const {
	for (int i = 0; i < _drawables->size(); i++)
	{
		_drawables->at(i)->Draw();
	}
}

//Process any input from the user
void Game::ProcessInput(SDL_Event & e) {
	if (e.type == SDL_QUIT) {
		_running = false;
	}

	//if mouse moving to the left
	if (e.motion.xrel < 0) {
		_camera->DecreaseYaw();
	}
	else if (e.motion.xrel > 0) { //...else, to right
		_camera->IncreaseYaw();
	}

	//moving up
	if (e.motion.yrel < 0) {
		_camera->IncreaseRoll();
	}
	else if (e.motion.yrel > 0) { //moving down
		_camera->DecreaseRoll();
	}
}