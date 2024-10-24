#include "pch.h"
#include "PlantAttackAction.h"

#include "Plant.hpp"

PlantAttackAction::PlantAttackAction()
{
}

PlantAttackAction::~PlantAttackAction()
{
}

void PlantAttackAction::Start(Plant* plant)
{
	mTimeNextShoot = (float)GET_CURRENT_TIME + 1000;
}

void PlantAttackAction::Update(Plant* plant)
{
	auto currentTime = GET_CURRENT_TIME;
	if (currentTime >= mTimeNextShoot)
	{
		mTimeNextShoot = currentTime + 1000;
		std::cout << "Plant is shooting" << std::endl;
		plant->shoot();
	}
	plant->setIsShooting(true);
}

void PlantAttackAction::End(Plant* plant)
{
	plant->setIsShooting(false);
	mTimeNextShoot = 0.0;
}
