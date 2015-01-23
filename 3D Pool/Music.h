#pragma once
#include <SFML\Audio\Music.hpp>

class Music
{
public:
	Music();
	~Music();
	void Play();
private:
	sf::Music * _music;
};

