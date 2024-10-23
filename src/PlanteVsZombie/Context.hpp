#pragma once

namespace Context
{
    enum class State 
    {
        // ajoutez vos états ici
		IDLE,
		ATTACK,
		DEAD
    };

    inline std::ostream& operator<<(std::ostream& os, const State& state)
    {
        switch (state)
        {
        case State::IDLE: os << "IDLE"; break;
        case State::ATTACK: os << "ATTACK"; break;
        case State::DEAD: os << "DEAD"; break;
        default: os << "UNKNOWN"; break;
        }
        return os;
    }
};
