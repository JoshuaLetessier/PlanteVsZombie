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
	reloadStartTime = std::chrono::steady_clock::now();
}

void PlantAttackAction::Update(Plant* plant)
{
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - reloadStartTime).count();
	if (elapsedTime >= reloadTime)
	{
		plant->setIsShooting(true);
	}
	else
	{
		plant->setIsShooting(false);
	}
}

void PlantAttackAction::End(Plant* plant)
{
}
