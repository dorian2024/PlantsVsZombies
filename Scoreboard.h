#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include "Header.h"

using namespace std;
class Scoreboard
{
public:
	sf::Texture namePrompt; 
	Scoreboard();
	sf::Texture& getNamePrompt();
};

