#pragma once
#include "Action.hpp"
class PlantAttackAction :
    public Action
{
public:
	PlantAttackAction();
	~PlantAttackAction();

	void Start(Plant* plant) override;
	void Update(Plant* plant) override;
	void End(Plant* plant) override;
};

