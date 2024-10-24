#include "pch.h"
#include "Plant.hpp"
#include "Enemy.h"
#include "Projectile.h"

#include "PlantIdleAction.h"
#include "PlantAttackAction.h"
#include "PlantDeadAction.h"
#include "Transition.hpp"
#include "PlantAttackCondition.h"

#include "Enemy.h"

Playground* Playground::mInstance = nullptr;

Playground::~Playground()
{
	for (auto plant : mPlants)
	{
		delete plant;
	}
	for (auto enemy : mEnemies)
	{
		delete enemy;
	}
	for (auto projectile : mProjectiles)
	{
		delete projectile;
	}
	mPlants.clear();
	mEnemies.clear();
	mProjectiles.clear();
	delete mPlantBehaviour;
	
	delete mEnemyBehaviour;

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

		// Create AttackPlantTransitions
		Transition* attackPlanteTransition = new Transition();
		attackPlanteTransition->addCondition(new PlantAttackCondition());
		attackPlanteTransition->setTargetState(Context::State::ATTACK);
		mInstance->mPlantBehaviour->AddTransition(Context::State::IDLE, attackPlanteTransition);

		// Add 4 plants
		sf::Vector2f position(50, 50);
		for (int i = 0; i < 4; i++)
		{
			Plant* plant = new Plant(position, mInstance->mPlantBehaviour, 10);
			position.y += 100;
			mInstance->mPlants.push_back(plant);
		}

		// Create a enemy behaviour
		mInstance->mEnemyBehaviour = new Behaviour();

		position.x = 500;
		position.y = 50;
		sf::Vector2f direction = sf::Vector2f(-1, 0);
		Enemy* enemy = new Enemy(position, direction, 2, mInstance->mEnemyBehaviour);
		mInstance->mEnemies.push_back(enemy);
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
	if (mEnemies.size() > 0)
	{
		for (auto enemy : mEnemies)
		{
			window.draw(*enemy->getShape());
		}
	}
}

void Playground::update()
{
	for (auto plant : mPlants)
	{
		mPlantBehaviour->Update(plant);
	}
	for (auto enemy : mEnemies)
	{
		enemy->Update();
	}
	for (auto projectile : mProjectiles)
	{
		projectile->Update();
	}
	checkCollision(mProjectiles, mEnemies);
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2f position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//Direction vers la gauche
			position.x = 200;
			position.y = 50;
			sf::Vector2f direction = sf::Vector2f(-1, 0);
			Enemy* enemy = new Enemy(position, direction, 2, mEnemyBehaviour);
			mEnemies.push_back(enemy);
		}
	}
}

std::vector<Enemy*>& Playground::getEnemysInstance()
{
	return mInstance->mEnemies;
}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Enemy*>& mEnemies)
{
	for (auto projectile : mProjectiles)
	{
		for (auto enemy : mEnemies)
		{
			if (projectile->getGlobalBounds().intersects(enemy->getGlobalBounds()))
			{
				delete enemy;
				delete projectile;
			}
		}
	}
}