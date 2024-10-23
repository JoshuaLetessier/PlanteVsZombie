#include "pch.h"
#include "RenderApp.h"
#include "Plant.hpp"
#include "Behaviour.hpp"

#include "PlantIdleAction.h"
#include "PlantAttackAction.h"
#include "PlantDeadAction.h"


RenderApp::~RenderApp()
{
	for (auto plant : mPlants)
	{
		delete plant;
	}
	mPlants.clear();
	delete mPlantBehaviour;
}

RenderApp* RenderApp::Init()
{
	auto app = new RenderApp();
	app->mWindow = new sf::RenderWindow(sf::VideoMode(650, 400), "SFML works!");
	app->mWindow->setFramerateLimit(60);


	//Create a plant behaviour
    app->mPlantBehaviour = new Behaviour();
	app->mPlantBehaviour->AddAction(Context::State::IDLE, new PlantIdleAction());
	app->mPlantBehaviour->AddAction(Context::State::ATTACK, new PlantAttackAction());
	app->mPlantBehaviour->AddAction(Context::State::DEAD, new PlantDeadAction());

	//Add 4 plants
	sf::Vector2f position(50, 50);
	for (int i = 0; i < 4; i++)
	{
		Plant* plant = new Plant(position,app->mPlantBehaviour, 10);
		position.y += 100;
		app->mPlants.push_back(plant);
	}

	return app;
}

void RenderApp::Run()
{
	while (mWindow->isOpen())
	{
		Update();
		Render();
	}
}

void RenderApp::Update()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || 
			(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			mWindow->close();
	}

	for (auto plant : mPlants)
	{
		mPlantBehaviour->Update(plant);
	}
}

void RenderApp::Render()
{
	mWindow->clear();

	for (auto plant : mPlants)
	{
		plant->Update();
		mWindow->draw(plant->getShape());
	}

	mWindow->display();
}

void RenderApp::Release()
{
	mWindow->close();
	delete mWindow;
	delete this;
}