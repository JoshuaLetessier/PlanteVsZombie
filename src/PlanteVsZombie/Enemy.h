#pragma once

class Enemy : public Entity
{
public:
	Enemy(sf::Vector2f position, sf::Vector2f direction, float speed, Behaviour* enemy_behaviour);
	virtual ~Enemy();

	void Update() override;

private:
	sf::Vector2f mDirection;
	float mSpeed;
};