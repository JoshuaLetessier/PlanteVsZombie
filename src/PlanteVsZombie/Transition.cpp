#include "Transition.hpp"
#include "Player.hpp"

void Transition::setTargetState(Context::State target_state)
{
    mTargetState = target_state;
}

void Transition::addCondition(Condition* condition)
{
    mConditions.push_back(condition);
}

void Transition::Try(Player * player)
{
    int true_tests = 0;
    for (const auto &c : mConditions)
    {
        true_tests += c->Test(player);
    }
    if (true_tests != 0 && true_tests == mConditions.size())
    {
        player->setState(mTargetState);
    }
}
