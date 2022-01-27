#include "Ship.h"
Ship::Ship(sf::RenderWindow* window, ProjectileManager* projectileManager) : windowHeight(window->getSize().y) {
	this->window = window;
	this->projectileManager = projectileManager;
	isAlive = true;
	speed = 10.0f;
	yOffSet = 100;

	setTexture(TextureManager::GetTexture("ship"));
	scale(0.1, 0.1);
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	setPosition(10, windowHeight - yOffSet); // CURRENTLY JUST MAGIC NUMBERS BASED ON THE SCALE

}

void Ship::ShootProjectile() {
	float xPos = getPosition().x + getGlobalBounds().width / 3;
	float yPos = windowHeight - (getGlobalBounds().height / 4) - yOffSet; // FIXME: CORRECT THESE VALUES
	projectileManager->AddProjectile(xPos, yPos);
}

void Ship::MoveRight() {
	move(speed, 0);
}

void Ship::MoveLeft() {
	move(-speed, 0);
}

void Ship::DrawShip() {
	window->draw(*this);
}