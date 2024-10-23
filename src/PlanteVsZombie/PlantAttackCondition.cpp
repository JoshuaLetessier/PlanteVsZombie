#include "pch.h"
#include "PlantAttackCondition.h"

#include "Plant.hpp"
#include "Playground.h"
//#include "Enemy.h"

bool PlantAttackCondition::Test(Plant* plant)
{
    if(plant->getAmmoCount() <= 0)
		return false;

	std::vector<Enemy*> mEnemies = Playground::getEnemysInstance();

	for (auto enemy : mEnemies)
	{
		//if (enemy->getPosition().x == plant->getPosition().x)
		//{
		//	return true;
		//}
	}

     return false; 
}
