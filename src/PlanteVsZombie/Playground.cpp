#include "pch.h"
#include "Plant.hpp"
#include "Enemy.h"
#include "Projectile.h"

#include "PlantIdleAction.h"
#include "PlantAttackAction.h"
#include "PlantDeadAction.h"

Playground* Playground::mInstance = nullptr;

Playground::~Playground()
{
	for (auto plant : mPlants)
	{
		delete plant;
	}
	mPlants.clear();
	delete mPlantBehaviour;
}

Playground* Playground::instantiate()
{
	if (mInstance == nullptr)
	{
		mInstance = new Playground();

		// Create a plant behaviour
		mInstance->mPlantBehaviour = new Behaviour();
		mInstance->mPlantBehaviour->AddAction(Context::State::IDLE, new PlantIdleAction());
		mInstance->mPlantBehaviour->AddAction(Context::State::ATTACK, new PlantAttackAction());
		mInstance->mPlantBehaviour->AddAction(Context::State::DEAD, new PlantDeadAction());

		// Add 4 plants
		sf::Vector2f position(50, 50);
		for (int i = 0; i < 4; i++)
		{
			Plant* plant = new Plant(position, mInstance->mPlantBehaviour, 10);
			position.y += 100;
			mInstance->mPlants.push_back(plant);
		}
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

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Enemy*>& mEnemies)
{
    // Collision checking code
}