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

}

void PlantAttackAction::Update(Plant* plant)
{
    std::cout << "Plant is shooting" << std::endl;
	plant->setIsShooting(true);
}

void PlantAttackAction::End(Plant* plant)
{
}
