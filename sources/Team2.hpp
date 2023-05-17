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
            size_t stillAlive()const override;
            double the_enemy_distance(Team* enemy)override;
            Character** the_victim(Team* enemy)override;// always return the victims and if not have return null.
            void print()const override;

    };
}
