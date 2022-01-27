#include "Projectile.h"

Projectile::Projectile(sf::RenderWindow* window, float xPos, float yPos) {
	this->window = window;
	speed = 0.25f;
	isIntact = true;

	setTexture(TextureManager::GetTexture("projectile"));
	scale(0.1, 0.1);
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	setPosition(xPos, yPos);
}

void Projectile::UpdatePos() {
	move(0, -speed);
}

bool Projectile::GetIsIntact() const {
	return isIntact;
}

void Projectile::DrawProjectile() const {
	window->draw(*this);
}

void Projectile::Explode() {
	isIntact = false;
	// asteroid manager will tell game to give points upon hitting asteroid
}