#include "pch.h"
#include "Plant.hpp"

Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)  
	: Entity("Plant", 10, position, sf::Color::Green, plant_behaviour), mAmmoCount(ammo_count), mMaxAmmo(ammo_count)
{  
}

Plant::~Plant()
{
}

int Plant::getAmmoCount() const
{
	return mAmmoCount;
}

void Plant::setAmmoCount(int newAmmoCount)
{
	mAmmoCount = newAmmoCount;
}

int Plant::getHealth() const
{
	return mHealth;
}

void Plant::refillMagazine()
{
}

void Plant::setIsShooting(bool newIsShooting)
{
	mIsShooting = newIsShooting;
}

bool Plant::shoot()
{
	return mIsShooting;
}

void Plant::Update()
{
}
