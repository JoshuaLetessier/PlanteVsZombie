#pragma once

class Player;

class Condition 
{
public:
    virtual bool Test(Player * player) = 0;
};
