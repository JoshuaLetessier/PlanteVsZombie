#pragma once

#include "Condition.hpp"

class PlantAttackCondition :
    public Condition
{
public:
	bool Test(Plant* plant) override;
};

