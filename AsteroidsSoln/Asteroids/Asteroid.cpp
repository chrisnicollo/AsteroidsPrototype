#include "Asteroid.h"

Asteroid::Asteroid(sf::RenderWindow* window, float linearSpd, float rotationSpd) : linearSpd(linearSpd), rotationSpd(rotationSpd) {
	this->window = window;
	// set texture of asteroid
	setTexture(TextureManager::GetTexture("asteroid"));
	// randomize size
	scale(Random::Float(0.05, 0.15), Random::Float(0.05, 0.15));  // (1,1) would be 100% of initial width and height
	// set position in window
	setPosition(Random::Float(0, window->getSize().x), 0); // random x pos, 0 for y
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	
	// FIXME: RANDOMIZE THE COLOR

	isIntact = true; // currently not hit
}

void Asteroid::Explode() {
	isIntact = false;
	// FIXME: set an explosion png to draw
	// setTexture(TextureManager::GetTexture("explosion"));
}

void Asteroid::UpdatePos() {
	move(0, linearSpd);
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2); // FIXME: IDK WHAT THIS IS DOING
	rotate(rotationSpd);

}

bool Asteroid::GetIsIntact() {
	return isIntact;
}

void Asteroid::DrawAsteroid(sf::RenderWindow& window) const {
	// sf::RenderWindow* tempPtr = this->window;
	// Asteroid tempAsteroid = *this;
	this->window->draw(*this);
}

Asteroid& Asteroid::operator=(const Asteroid& origObj) {
	this->window = origObj.window;
	this->isIntact = origObj.isIntact;
	this->linearSpd = origObj.linearSpd;
	this->rotationSpd = origObj.rotationSpd;
	// FIXME: MAKE IT COPY THE TEXTURE PROPERTIES
	return *this;
}

bool Asteroid::operator==(const Asteroid& obj2) {
	if (this->getPosition() != obj2.getPosition()) {
		return false;
	}
	if ((this->linearSpd != obj2.linearSpd) || (this->rotationSpd != obj2.rotationSpd)
		|| (this->isIntact != obj2.isIntact)) {
		return false;
	}
	return true;
}