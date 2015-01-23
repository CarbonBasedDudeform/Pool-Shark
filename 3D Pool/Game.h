#pragma once
//SFML
#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp>

//STL
#include <list>

//Interfaces
#include "IDrawable.h"

//General
#include "Music.h"

//Game Objects
#include "Room.h"


class Game
{
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const sf::String GAME_TITLE;

	static Game * GetInstance();
	~Game();

	void Init();
	void Loop();

private:
	//Singleton stuff
	Game();
	static Game * _instance;

	//SFML
	sf::RenderWindow * _window;

	//Music
	Music * _backgroundMusic;

	//Rendering
	std::list<IDrawable *> * _drawables;
	void Draw() const;
};

