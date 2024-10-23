#pragma once

class Enemy : public Entity
{
public:
	Enemy(sf::Vector2f position, Behaviour* enemy_behaviour);
	virtual ~Enemy();

	void Update() override;
};