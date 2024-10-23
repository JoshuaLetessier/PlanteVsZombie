#include "pch.h"
#include "PlantAttackCondition.h"

#include "Plant.hpp"
#include "Playground.h"
//#include "Enemy.h"

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
		
		plant->getShape().getRadius();

		if (enemy.getPositions().x >= plant->getPosition().x && enemy.getPositions().x <= plant->getPosition().x + plant->getShape().getRadius() * 2)
		{
			return true;
		}

		//if (enemy->getPosition().x == plant->getPosition().x)
		//{
		//	return true;
		//}
	}

     return false; 
}
