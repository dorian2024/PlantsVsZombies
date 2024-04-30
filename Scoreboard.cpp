#include "Scoreboard.h"
#include "Game.h"
#include "Header.h"

Scoreboard::Scoreboard() {
	namePrompt.loadFromFile("../SFML/Images/name.png");
}
sf::Texture& Scoreboard::getNamePrompt() {
	return namePrompt;
}
