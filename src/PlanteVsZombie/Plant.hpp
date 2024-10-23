#pragma once

class Entity;

class Plant : public Entity
{
    int mAmmoCount, mMaxAmmo;
    bool mIsShooting = false;
	int mHealth = 10;

public:
    Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count);
    virtual ~Plant();

    int getAmmoCount() const;
    void setAmmoCount(int newAmmoCount);

	int getHealth() const;

    void refillMagazine();

	void setIsShooting(bool newIsShooting);

    bool shoot();

    void Update() override;
};
