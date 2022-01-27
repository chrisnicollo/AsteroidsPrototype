#include "AsteroidManager.h"
#include <iostream>

AsteroidManager::AsteroidManager(sf::RenderWindow* window, Game* game) : windowHeight(window->getSize().y){
	this->window = window;
	this->game = game;
	start = time(0);
	secsSinceStart = 0;
}

void AsteroidManager::OneAsteroid() {
	float linearSpd = 0.5;
	float rotationSpd = 0.2;
	Asteroid temp(window, linearSpd, rotationSpd);
	asteroidList.push_back(temp);
}

void AsteroidManager::Update() {
	if (asteroidList.size() > 0) {

		vector<Asteroid>::iterator iter;
		bool noChanges = true;
		for (iter = asteroidList.begin(); iter != asteroidList.end() && noChanges; iter++) {
			sf::Vector2f position = iter->getPosition();
			float spriteLength = 0;
			if (iter->getGlobalBounds().width > iter->getGlobalBounds().height) {
				spriteLength = iter->getGlobalBounds().width / 2;
			}
			else {
				spriteLength = iter->getGlobalBounds().height / 2;
			}
			if (!iter->GetIsIntact()) {
				asteroidList.erase(iter);
				noChanges = false;
				break;
			}
			else if (position.y > windowHeight + spriteLength) {
				// asteroidList.erase(iter);
				remove(asteroidList.begin(), asteroidList.end(), *iter); // FIXME: THIS ISNT UPDATING THE LIST
				game->LosePoints(100); // FIXME: CHECK THAT THIS UPDATES GAME
				noChanges = false;
				break;
			}
		}


		/*
		unsigned int numAsteroids;
		vector<Asteroid>::iterator iter;
		bool madeChanges = true;
		while (madeChanges) {
			iter = asteroidList.begin();
			numAsteroids = asteroidList.size();

			bool repeatForLoop = true;
			for (unsigned int i = 0; (i < numAsteroids) && (repeatForLoop); i++) {
				sf::Vector2f origin = (iter)->getOrigin();
				sf::Vector2f position = iter->getPosition();
				float spriteLength = 0;

				if (iter->getGlobalBounds().width > iter->getGlobalBounds().height) {
					spriteLength = iter->getGlobalBounds().width / 2;
				}
				else {
					spriteLength = iter->getGlobalBounds().height / 2;
				}
				if (position.y > windowHeight + spriteLength || !(iter->GetIsIntact())) {
					asteroidList.erase(iter);
					repeatForLoop = false; // do not repeat the for loop if there's been a change
				}
				else if (i + 1 == numAsteroids) { // if it's the end and no changes were made
					repeatForLoop = false; // do not repeat the for loop if it's the end and no changes were made
					madeChanges = false; // do not repeat the while loop if it's the end of the for loop and no changes were made
				}
				else {
					iter++;
				}
			}
			if (numAsteroids == 0) {
				repeatForLoop = false;
				madeChanges = false;
			}
		} */

		/*
		for (unsigned int i = 0; i < numAsteroids && iter != asteroidList.end(); i++) {
			sf::Vector2f origin = (iter)->getOrigin();
			sf::Vector2f position = iter->getPosition();
			float spriteLength = 0;
			if (iter->getGlobalBounds().width > iter->getGlobalBounds().height) {
				spriteLength = iter->getGlobalBounds().width / 2;
			}
			else {
				spriteLength = iter->getGlobalBounds().height / 2;
			}

			if (origin.y > windowHeight || position.y - spriteLength > windowHeight) { // asteroid out of bounds
				auto temp = iter;
				if (i + 1 < numAsteroids) {
					iter++;
				}
				asteroidList.erase(temp); // get rid of it in the vector
			}
			else if (!(iter)->GetIsIntact()) { // if asteroid is NOT intact
				asteroidList.erase(iter); // get rid of it in the vector
				// FIXME: ADD THE WORKING CODE FROM ABOVE
			}
			else {
				(iter)->UpdatePos();
				iter++;
			}
			*/
		for (unsigned int i = 0; i < asteroidList.size(); i++) {
			asteroidList.at(i).UpdatePos();
		}
	}

	// spawn new ones
	// FIXME: INCREASE DIFFICULTY WITH TIME
	// secsSinceStart = difftime(time(0), start);
	
	if (asteroidList.size() < 5) { // FIXME: SET A VAL TO KEEP IT LESS THAN
		// spawn
		int spawn = Random::Int(0, 500); // FIXME: FIX THIS VALUE
		if (spawn == 0) { // create and add an asteroid
			// OneAsteroid();
			float linearSpd = Random::Float(0.05, 0.1); // FIXME: THESE ARE CURRENTLY JUST MAGIC NUMBERS
			float rotationSpd = Random::Float(0, 0.1);
			Asteroid temp(window, linearSpd, rotationSpd);
			asteroidList.push_back(temp);	
		}
	}
}

void AsteroidManager::DrawAsteroids() {
	for (unsigned int i = 0; i < asteroidList.size(); i++) {
		// asteroidList.at(i).DrawAsteroid(*window);
		window->draw(asteroidList.at(i));
	}
}