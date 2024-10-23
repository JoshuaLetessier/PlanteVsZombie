#include "pch.h"
#include "Plant.hpp"
#include "Enemy.h"
#include "Projectile.h"

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
	for (auto plant : mPlants)
	{
		window.draw(*plant->getShape());
	}
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