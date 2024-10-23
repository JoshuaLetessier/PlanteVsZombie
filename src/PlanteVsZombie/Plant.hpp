#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Context.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Plant
{
	sf::CircleShape mShape;
    sf::Vector2f mPosition;
    std::string mName;
    int mAmmoCount, mMaxAmmo;
    Context::State mState;
    Behaviour * mBehaviour;

    bool mIsShooting = false;

	int mHealth = 10;

public:
    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Plant();

    void setState(Context::State);
    Context::State getState() const;

    sf::Color getColor() const;
    sf::Vector2f getPosition() const;
	sf::CircleShape getShape() const;

    int getAmmoCount() const;
    void setAmmoCount(int newAmmoCount);

	int getHealth() const;

    void refillMagazine();

	void setIsShooting(bool newIsShooting);

    bool shoot();

    void Update();
};
