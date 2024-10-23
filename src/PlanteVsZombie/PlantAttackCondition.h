#pragma once

#include "Condition.hpp"

class PlantAttackCondition :
    public Condition
{
public:
	PlantAttackCondition();
	virtual ~PlantAttackCondition();
	bool Test(Plant* plant) override;
};

