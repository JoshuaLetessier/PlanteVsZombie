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
	mTimeHasShooted = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void PlantAttackAction::Update(Plant* plant)
{
    std::cout << "Plant is shooting" << std::endl;
	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - mTimeHasShooted > 1000)
	{
		mTimeHasShooted = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		plant->shoot();
	}
	plant->setIsShooting(true);
}

void PlantAttackAction::End(Plant* plant)
{
	plant->setIsShooting(false);
}
