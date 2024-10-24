#include "pch.h"
#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, sf::Vector2f direction, float speed, Behaviour* projectile_behaviour)
	: Entity("Projectile", 10, position, sf::Color::White, projectile_behaviour), mDirection(direction), mSpeed(speed)
{
}

Projectile::~Projectile()
{
}

void Projectile::setDirection(sf::Vector2f newDirection)
{
	mDirection = newDirection;
}

void Projectile::Update()
{
	sf::Vector2f position = this->getPosition();
	position += mDirection * mSpeed;
	this->setPosition(position);
}