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

private:
	double reloadTime = 10.0;
	std::chrono::steady_clock::time_point reloadStartTime;
};

