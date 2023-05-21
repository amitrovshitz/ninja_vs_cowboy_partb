#pragma once
#include "Team.hpp"
using namespace std;
namespace ariel
{
    class smartTeam: public Team
    {
        public:
            smartTeam(Character* leader):Team(leader){} 
            void attack(Team* enemy)override;
            size_t stillAlive()const override;
            Character* the_victim(Team* enemy)override;
            void print()const override;
    };
}
