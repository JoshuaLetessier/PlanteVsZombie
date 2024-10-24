#pragma once

class Entity
{
public:
	Entity(std::string name, int radius, sf::Vector2f position, sf::Color color, Behaviour* behaviour)
	{
		mName = name;
		mShape = new sf::CircleShape(radius);
		mShape->setFillColor(color);
		mShape->setPosition(position);
		mState = Context::State::IDLE;
		mBehaviour = behaviour;
	}

	virtual ~Entity()
	{
		delete mShape;
		mBehaviour = nullptr;
	}

	void setState(Context::State newState)
	{ mState = newState; }

	Context::State getState() const
	{ return mState; }

	void setColor(sf::Color newColor)
	{ mShape->setFillColor(newColor); }

	sf::Color getColor() const
	{ return mShape->getFillColor(); }

	void setPosition(sf::Vector2f newPosition)
	{ mShape->setPosition(newPosition); }

	sf::Vector2f getPosition() const
	{ return  mShape->getPosition(); }

	sf::CircleShape* getShape() const
	{ return mShape; }

	sf::FloatRect getGlobalBounds()
	{ return mShape->getGlobalBounds(); }

	virtual void Update() = 0;

private:
	std::string mName;
	sf::CircleShape* mShape;

	Context::State mState;
	Behaviour* mBehaviour;
};