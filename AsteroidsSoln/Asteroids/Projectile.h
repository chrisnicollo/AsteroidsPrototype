#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AsteroidManager.h"

class Projectile : public sf::Sprite
{
	sf::RenderWindow* window;
	float speed; // this is entirely in the y-dir
	bool isIntact;
public:
	Projectile(sf::RenderWindow* window, float xPos, float yPos);
	void UpdatePos(); // move and redraw; does no moving if exploding
	bool GetIsIntact() const;
	void DrawProjectile() const;
	void Explode();
};

