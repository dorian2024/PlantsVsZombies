#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Scoreboard.h"
#include "Header.h"
using namespace sf;
using namespace std;

class Game
{
protected:
	Scoreboard* scoreboard;
	sf::Sprite background;
public:
	Game(const sf::Texture& texture, sf::RenderWindow& window);
	void play(sf::RenderWindow& window);
};
