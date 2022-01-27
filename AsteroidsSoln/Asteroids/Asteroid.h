#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Random.h"
class Asteroid : public sf::Sprite
{
	sf::RenderWindow* window;
	float linearSpd; // this is entirely in the y-dir
	float rotationSpd; // positive is CW
	bool isIntact;

public:
	Asteroid(sf::RenderWindow* window, float linearSpd, float rotationSpd); // use constructor initializer for const window, velocity
	void Explode(); // explosion.png
	void UpdatePos(); // move the sprite; does no moving if exploding
	bool GetIsIntact();
	void DrawAsteroid(sf::RenderWindow& window) const;
	Asteroid& operator=(const Asteroid& origObj); // FIXME: DEFINITION
	bool operator==(const Asteroid& obj2); // FIXME: DEFINITION
};


