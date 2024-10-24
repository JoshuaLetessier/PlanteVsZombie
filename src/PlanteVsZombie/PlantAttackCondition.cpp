#include "pch.h"
#include "PlantAttackCondition.h"

#include "Plant.hpp"
#include "Playground.h"
#include "Enemy.h"

PlantAttackCondition::PlantAttackCondition()
{
}

PlantAttackCondition::~PlantAttackCondition()
{
}

bool PlantAttackCondition::Test(Plant* plant)
{
    if(plant->getAmmoCount() <= 0)
		return false;

	std::vector<Enemy*> mEnemies = Playground::getEnemysInstance();

	for (auto enemy : mEnemies)
	{
		//Test postions in a rect with the top left corner of the plant and the bottom right corner of the plant

		float tolerance = 0.1f; // ou un autre petit nombre selon la précision dont tu as besoin
		if ((std::abs(enemy->getPosition().y - plant->getPosition().y) < tolerance) && (enemy->getPosition().x >= plant->getPosition().x))
		{
			return true;
		}
	}

     return false; 
}
