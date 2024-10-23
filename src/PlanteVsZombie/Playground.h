#pragma once

class Behaviour;
class Plant;
class Enemy;
class Projectile;

class Playground
{
public:
	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);

	static std::vector<Enemy*>& getEnemysInstance();

private:
	static Playground* mInstance;

	Behaviour* mPlantBehaviour;
	Behaviour* mEnemyBehaviour;

	std::vector<Plant*> mPlants;
	std::vector<Enemy*> mEnemies;
	std::vector<Projectile*> mProjectiles;

	Playground() = default;
	Playground(const Playground&) = delete;
	Playground& operator=(const Playground&) = delete;

	void checkCollision(
		std::vector<Projectile*>& mProjectiles,
		std::vector<Enemy*>& mEnemies);
};