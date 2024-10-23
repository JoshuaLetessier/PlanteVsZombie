#pragma once
class PlantDeadAction :
    public Action
{
public:
	PlantDeadAction();
	~PlantDeadAction();

	void Start(Plant* plant) override;
	void Update(Plant* plant) override;
	void End(Plant* plant) override;
};

