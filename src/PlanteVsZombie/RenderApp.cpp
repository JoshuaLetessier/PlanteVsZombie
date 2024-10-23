#include "pch.h"
#include "RenderApp.h"

RenderApp::~RenderApp()
{
}

RenderApp* RenderApp::Init()
{
	auto app = new RenderApp();
	app->mWindow = new sf::RenderWindow(sf::VideoMode(650, 400), "SFML works!");
	app->mWindow->setFramerateLimit(60);
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
}

void RenderApp::Render()
{
	mWindow->clear();
	mWindow->display();
}

void RenderApp::Release()
{
	mWindow->close();
	delete mWindow;
	delete this;
}