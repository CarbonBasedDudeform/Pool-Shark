#pragma once
//SDL
#include <SDL.h>
#include <GL/glew.h>
#include <GL/GLU.h>

//STL
#include <vector>

//Interfaces
#include "IDrawable.h"

//General
#include "Music.h"

//Game Objects
#include "Camera.h"
#include "Room.h"
#include "Table.h"
#include "Ball.h"


class Game
{
public:
	static const int SCREEN_WIDTH = 1920;
	static const int SCREEN_HEIGHT = 1080;
	static const char * GAME_TITLE;

	static Game * GetInstance();
	~Game();

	void Init();
	void Loop();

private:
	//Singleton stuff
	Game();
	static Game * _instance;

	//SDL
	SDL_Surface * _surface;
	bool _running;
	void ProcessInput(SDL_Event &);
	void OpenGLInit();

	//Music
	Music * _backgroundMusic;

	//Rendering arrays and that
	Camera * _camera;
	std::vector<IDrawable *> * _drawables;
	void Draw() const;
	bool UserWantsToExitViaEscapeKey(SDL_Event& e);
	std::vector<Ball *> * _balls;
	std::vector<Ball*> * GenerateBalls(int);
	const bool ItIsANewRow(int row, int counter) const;
	const float CalculateNewStartingXPosition(BallRenderSettings ballSettings, int row, float originalX) const;

	Ball * _theBadMotherfucker;
};

