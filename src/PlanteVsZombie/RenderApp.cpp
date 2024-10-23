#include "pch.h"
#include "RenderApp.h"
#include "Plant.hpp"
#include "Behaviour.hpp"

RenderApp::~RenderApp()
{
	for (auto plant : mPlants)
	{
		delete plant;
	}
	mPlants.clear();
	delete Playground::getInstance();
}

RenderApp *RenderApp::Init()
{
	auto app = new RenderApp();
	app->mWindow = new sf::RenderWindow(sf::VideoMode(650, 400), "SFML works!");
	app->mWindow->setFramerateLimit(60);

	Playground::instantiate();

	return app;
}

void RenderApp::Run()
{
	while (mWindow->isOpen())
	{
		sf::Event event;
		sf::Event dummy_event;
		while (mWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::Escape))
			{
				mWindow->close();
			}
			Playground::getInstance()->handleUserInput(event, *mWindow);
		}
		mWindow->clear();
		Playground::getInstance()->draw(*mWindow);
		Playground::getInstance()->update();
		mWindow->display();
	}
}

void RenderApp::Release()
{
	mWindow->close();
	delete mWindow;
	delete this;
}