#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, Behaviour* enemy_behaviour)
	: Entity("Enemy", 10, position, sf::Color::Red, enemy_behaviour)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}