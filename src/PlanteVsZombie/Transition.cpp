#include "pch.h"
#include "Transition.hpp"
#include "Plant.hpp"

Transition::~Transition()
{
	for (auto c : mConditions)
	{
		delete c;
	}
	mConditions.clear();
}

void Transition::setTargetState(Context::State target_state)
{
    mTargetState = target_state;
}

void Transition::addCondition(Condition* condition)
{
    mConditions.push_back(condition);
}

void Transition::Try(Plant * plant)
{
    int true_tests = 0;
    for (const auto &c : mConditions)
    {
        true_tests += c->Test(plant) ? 1 : 0;
    }
    if (true_tests != 0 && true_tests == mConditions.size())
    {
        plant->setState(mTargetState);
		std::cout << plant->getState()  << std::endl;
    }
}
