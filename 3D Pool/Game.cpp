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
		_surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);// | SDL_FULLSCREEN);
		SDL_WM_SetCaption("Pool Shark", NULL);
		
		_running = true;

		_camera = new Camera();
		_drawables = new std::vector<IDrawable *>();
		RenderSettings roomSettings;
		roomSettings.Position.X = roomSettings.Position.Y = roomSettings.Position.Z = 0.0f; //set em all to 0
		roomSettings.Scale.X = 30.0f; roomSettings.Scale.Y = 30.0f; roomSettings.Scale.Z = 30.0f;
		roomSettings.Rotation = 0.0f;
		roomSettings.Resource = "Models/room.txt";
		roomSettings.Colours = "Models/room colours.txt";
		
		_drawables->push_back(new Room(roomSettings));

		RenderSettings tableSettings;
		tableSettings.Position.X = 0.0f; tableSettings.Position.Y = 0.0f; tableSettings.Position.Z = -15.0f;
		tableSettings.Scale.X = 2.0f; tableSettings.Scale.Y = 1.0f; tableSettings.Scale.Z = 4.0f;
		tableSettings.Rotation = 0.0f;
		tableSettings.Resource = "Models/table.txt";
		tableSettings.Colours = "Models/table colours.txt";

		_drawables->push_back(new Table(tableSettings));

		_balls = GenerateBalls(15);

		for (auto iter = _balls->begin(); iter != _balls->end(); ++iter)
		{
			_drawables->push_back((*iter));
		}

		OpenGLInit();
	}
}

//OpenGL specific initialisation tasks
void Game::OpenGLInit() {
	//setup opengl
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);

	glEnable(GL_VERTEX_ARRAY);
	glEnable(GL_COLOR_ARRAY);

	//glEnable(GL_CULL_FACE);
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
		glPushMatrix();
			_drawables->at(i)->Draw();
		glPopMatrix();
	}
}

bool Game::UserWantsToExitViaEscapeKey(SDL_Event& e)
{
	return ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE );
}

//Process any input from the user
void Game::ProcessInput(SDL_Event & e) {
	if (e.type == SDL_QUIT || UserWantsToExitViaEscapeKey(e)) {
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

const float Game::CalculateNewStartingXPosition(BallRenderSettings ballSettings, int row, float originalX) const
{
	return ( originalX - ( (row) * ballSettings.Radius ) );
}

const bool Game::ItIsANewRow(int row, int counter) const
{
	return counter >= row;
}


std::vector<Ball*> * Game::GenerateBalls(int numberOfBalls)
{
	auto balls = new std::vector<Ball *>();

	BallRenderSettings ballSettings;
	ballSettings.Position.X = -0.1f; ballSettings.Position.Y = 1.1f; ballSettings.Position.Z = -18.5f;
	ballSettings.Scale.X = 1.0f; ballSettings.Scale.Y = 1.0f; ballSettings.Scale.Z = 1.0f;
	ballSettings.Rotation = 0.0f;
	ballSettings.Resource = "Models/diamond.txt";
	ballSettings.Colours = "Models/diamond colours.txt";

	ballSettings.Radius = 0.1f;

	auto StartingXPos = ballSettings.Position.X;
	const auto originalX = ballSettings.Position.X;
	int counter = 0;
	int row = 1;
	auto ballDiameter = ballSettings.Radius * 2;
	
	for (int i = 0; i < numberOfBalls; ++i)
	{
		if (ItIsANewRow(row, counter))
		{
			counter = 0;
			row++;
			StartingXPos = CalculateNewStartingXPosition(ballSettings, row, originalX);
			ballSettings.Position.Z -= ballDiameter;
		}
		counter++;
		//horrible hack to handle first ball which is oddly positioned
		if (i == 0) ballSettings.Position.X += ballSettings.Radius;
		else ballSettings.Position.X = StartingXPos + (counter * ballDiameter);
		
		balls->push_back(new Ball(ballSettings));
	}

	return balls;
}