#pragma once
#include <time.h>
#include <vector>
#include "Game.h"
#include "Asteroid.h"
#include "Random.h"
using std::vector;

class AsteroidManager
{
	time_t start;
	double secsSinceStart;

	Game* game;
	sf::RenderWindow* window;
	const float windowHeight;

public:
	vector<Asteroid> asteroidList;
	AsteroidManager(sf::RenderWindow* window, Game* game);
	void OneAsteroid();
	void Update(); // removes non intact asteroids, then updates all
	void DrawAsteroids();
};

