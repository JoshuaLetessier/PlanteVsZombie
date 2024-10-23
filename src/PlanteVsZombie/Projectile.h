#pragma once

class Projectile : public Entity
{
public:
	Projectile(sf::Vector2f position, sf::Vector2f direction, float speed, Behaviour* projectile_behaviour);
	virtual ~Projectile();

	void Update() override;

	void setDirection(sf::Vector2f newDirection);

private:
	sf::Vector2f mDirection;
	float mSpeed;
};