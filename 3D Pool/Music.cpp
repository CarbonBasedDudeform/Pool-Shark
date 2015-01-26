#include "Music.h"


Music::Music()
{
	/*
		There is apparently a bug in the SFML music code which causes a crash when run in debug, works fine in release mode though
		This code simply uses the macro for N(ot)Debug, if it's not debug, use the music, otherwise don't
			this seems to be the related issue: https://github.com/LaurentGomila/SFML/issues/30
	*/

#ifdef NDEBUG
#endif
}


Music::~Music()
{
}

void Music::Play()
{
	//if (_music) _music->play();
}