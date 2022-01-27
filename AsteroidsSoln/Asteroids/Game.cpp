#include "Game.h"

Game::Game(sf::RenderWindow* window) {
	this->window = window;
	currScore = 0;
	HP = 1; // FIXME: FINALIZE HP LATER

	background.setTexture(TextureManager::GetTexture("space"));
	background.scale(1.9, 2.75); // FIXME: THESE ARE CURRENTLY JUST MAGIC NUMBERS
}

void Game::LosePoints(int points) {
	currScore -= points;
}

void Game::WinPoints(int points) {
	currScore += points;
}

void Game::LoseHP(int HP) {
	this->HP -= HP;
}

void Game::DrawGameBackground() {
	window->draw(background);
}
