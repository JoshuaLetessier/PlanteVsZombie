#include "pch.h"
#include "Plant.hpp"

Plant::Plant()
{
}

Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)
{
	//Create a circle shape with a radius of 10
	mShape = sf::CircleShape(10);
	mShape.setPosition(position);
	mShape.setFillColor(sf::Color::Blue);
	mPosition = position;

	mState = Context::State::IDLE;
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

int Plant::getAmmoCount() const
{
	return mAmmoCount;
}

void Plant::refillMagazine()
{
}

bool Plant::shoot()
{
	return false;
}

void Plant::Update()
{
}
