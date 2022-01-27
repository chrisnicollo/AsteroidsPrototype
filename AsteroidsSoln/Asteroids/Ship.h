#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Projectile.h"
#include "AsteroidManager.h"
#include "TextureManager.h"
#include "ProjectileManager.h"
class Ship : public sf::Sprite
{
	sf::RenderWindow* window;
	bool isAlive;
	int speed;
	const float windowHeight;
	float yOffSet;
	ProjectileManager* projectileManager;

public:
	Ship(sf::RenderWindow* window, ProjectileManager* projectileManager);
	void ShootProjectile();
	void MoveRight();
	void MoveLeft();
	void DrawShip();
	// should also have a function that checks from asteroid manager if any asteroids are hitting it
};

