#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

class Game
{
	int currScore;
	int HP;
	sf::RenderWindow* window;
	sf::Sprite background;

public:
	Game(sf::RenderWindow* window);
	void LosePoints(int points);
	void WinPoints(int points);
	void LoseHP(int HP);
	void DrawGameBackground();
};

