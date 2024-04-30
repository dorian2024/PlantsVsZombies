#include "Game.h"
#include "Header.h"
const int XResolution = 1900, YResolution = 1000;
int bOxPixels = 50;
Game::Game(const sf::Texture& texture, sf::RenderWindow& window) {
	scoreboard = new Scoreboard;
	background.setTexture(texture);
	background.setPosition(0, 0);
}
void Game::play(sf::RenderWindow& window) {
	window.draw(background);
	window.setSize(sf::Vector2u(XResolution, YResolution));
	Sprite name;
	name.setTexture(scoreboard->getNamePrompt());
	name.setPosition(13 * bOxPixels, 4 * bOxPixels);
	window.draw(name);

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}