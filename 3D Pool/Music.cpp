#include "Music.h"


Music::Music()
{
	/*
		There is apparently a bug in the SFML music code which causes a crash when run in debug, works fine in release mode though
		This code simply uses the macro for N(ot)Debug, if it's not debug, use the music, otherwise don't
			this seems to be the related issue: https://github.com/LaurentGomila/SFML/issues/30
	*/

#ifdef NDEBUG
	_music = new sf::Music();
	_music->openFromFile("../Music/loop.ogg");
	_music->setLoop(true);
	_music->setPosition(10.0f, 0.0f, 10.0f);
	_music->setVolume(25.0f);
	_music->setAttenuation(50.0f);
#endif
}


Music::~Music()
{
	delete _music;
}

void Music::Play()
{
	if (_music) _music->play();
}