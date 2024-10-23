#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, sf::Vector2f direction, float speed, Behaviour* enemy_behaviour)
	: Entity("Enemy", 10, position, sf::Color::Red, enemy_behaviour), mDirection(direction), mSpeed(speed)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	sf::Vector2f position = this->getPosition();
	position += mDirection * mSpeed;
	this->setPosition(position);
}