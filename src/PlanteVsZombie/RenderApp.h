#pragma once

class Behaviour;
class Plant;

class RenderApp
{
public:
	RenderApp() = default;
	virtual ~RenderApp();

	static RenderApp* Init();
	void Run();
	void Release();

private:
	sf::RenderWindow* mWindow = nullptr;
	std::vector<Plant*> mPlants;

	Behaviour* mPlantBehaviour;
};