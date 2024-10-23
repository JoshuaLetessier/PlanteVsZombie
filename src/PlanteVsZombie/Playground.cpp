#include "pch.h"
#include "Plant.hpp"
#include "Playground.h"

Playground* Playground::mInstance = nullptr;

Playground::~Playground()
{
}

Playground* Playground::instantiate()
{
	if (mInstance == nullptr)
	{
		mInstance = new Playground();
	}
	return mInstance;
}

Playground* Playground::getInstance()
{
	return mInstance;
}

void Playground::draw(sf::RenderWindow& window)
{
	// Draw code
}

void Playground::update()
{
    // Update code
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
    // Handle user input
}

std::vector<Enemy*>& Playground::getEnemysInstance()
{
	return mInstance->mEnemies;
}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Enemy*>& mEnemies)
{
    // Collision checking code
}