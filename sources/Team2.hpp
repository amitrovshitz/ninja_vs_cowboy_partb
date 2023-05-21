#pragma once
#include "Team.hpp"
using namespace std;
namespace ariel
{
    class Team2: public Team
    {
        public:
            Team2(Character* leader):Team(leader){} 
            void attack(Team* enemy)override;
            int stillAlive()const override;
            Character* the_victim(Team* enemy)override;
            void print()const override;

    };
}
