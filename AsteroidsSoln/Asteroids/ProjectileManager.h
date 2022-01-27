#pragma once
#include "Projectile.h"
#include "SFML/Graphics.hpp"
class ProjectileManager
{
	sf::RenderWindow* window;
public:
	vector<Projectile> projectileList;
	ProjectileManager(sf::RenderWindow* window);
	void AddProjectile(float xPos, float yPos);
	void Update(); // removes non intact projectiles, then updates all
	void DrawProjectiles();
};

