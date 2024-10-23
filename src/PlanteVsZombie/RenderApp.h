#pragma once

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
};