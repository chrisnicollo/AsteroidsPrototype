#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureManager.h"
#include "SoundManager.h"
#include "Asteroid.h"
#include "Game.h"
#include "AsteroidManager.h"
#include "Ship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Sound test(SoundManager::GetSoundBuffer("collide"));
    test.play();
    */

    vector<Asteroid*> asteroids;
    Asteroid asteroid(&window, 1, 0.2f);
    asteroids.push_back(&asteroid);

    Game game(&window);
    AsteroidManager asteroidManager(&window, &game);
    ProjectileManager projectileManager(&window);
    Ship ship(&window, &projectileManager);
    // asteroidManager.OneAsteroid();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    ship.MoveLeft(); // ship is a sprite
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    ship.MoveRight();
                }
                if (event.key.code == sf::Keyboard::Space) {
                    ship.ShootProjectile();
                }
            }
        }

        window.clear();
        // window.draw(shape);
        // window.draw(asteroid);

        /*
        for (auto iter = asteroidManager.asteroidList.begin(); iter != asteroidManager.asteroidList.end(); iter++) {
            Asteroid temp = *iter;
            temp.DrawAsteroid(window);
        }
        */

        game.DrawGameBackground();

        projectileManager.Update();
        projectileManager.DrawProjectiles();

        ship.DrawShip();

        asteroidManager.Update();
        asteroidManager.DrawAsteroids();
    
        // asteroidManager.DrawAsteroids();
       
        window.display();
    }

    TextureManager::Clear();
    SoundManager::Clear();

    return 0;
}


/* maybe want a class for moving objects?
    *  needs to be ship, asteroids, projectiles
    *  maybe asteroids and projectiles are similar enough? maybe not, dont group moving objects together?
    *
    * 
*/
