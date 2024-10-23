#include "pch.h"
#include "Plant.hpp"

Plant::Plant()
{
}

Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)
{
	mBehaviour = plant_behaviour;
	mPosition = position;
	mState = Context::State::IDLE;

	mShape.setRadius(10);
	mShape.setFillColor(sf::Color::Blue);
	mShape.setPosition(mPosition);
}

Plant::~Plant()
{
}

void Plant::setState(Context::State newState)
{
	mState = newState;
}

Context::State Plant::getState() const
{
	return mState;
}

sf::Color Plant::getColor() const
{
	return mShape.getFillColor();
}

sf::Vector2f Plant::getPosition() const
{
	return mPosition;
}

sf::CircleShape Plant::getShape() const
{
	return mShape;

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
