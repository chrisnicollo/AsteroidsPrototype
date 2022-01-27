#include "ProjectileManager.h"

ProjectileManager::ProjectileManager(sf::RenderWindow* window) {
	this->window = window;
}

void ProjectileManager::AddProjectile(float xPos, float yPos) {
	projectileList.push_back(Projectile(window, xPos, yPos));
}

void ProjectileManager::Update() {
	// FIXME: add functionality to update non-intact projectiles, ie check if hits asteroid

	for (unsigned int i = 0; i < projectileList.size(); i++) {
		projectileList.at(i).UpdatePos();
	}
}

void ProjectileManager::DrawProjectiles() {
	for (unsigned int i = 0; i < projectileList.size(); i++) {
		window->draw(projectileList.at(i));
	}
}