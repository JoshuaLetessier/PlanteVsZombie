#include "pch.h"
#include "PlantDeadAction.h"

#include "Plant.hpp"

PlantDeadAction::PlantDeadAction()
{
}

PlantDeadAction::~PlantDeadAction()
{
}

void PlantDeadAction::Start(Plant* plant)
{
}

void PlantDeadAction::Update(Plant* plant)
{
	plant->~Plant();
}

void PlantDeadAction::End(Plant* plant)
{
}
