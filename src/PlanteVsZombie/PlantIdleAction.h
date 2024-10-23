#pragma once
#include "Action.hpp"

class PlantIdleAction : public Action
{
public:
	PlantIdleAction();
	~PlantIdleAction();

	void Start(Plant* plant) override;
	void Update(Plant* plant) override;
	void End(Plant* plant) override;
};

