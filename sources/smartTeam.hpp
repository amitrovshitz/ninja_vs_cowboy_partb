#pragma once
#include "Team.hpp"
using namespace std;
namespace ariel
{
    class SmartTeam: public Team
    {
            private:
                Character* the_victim(Team* enemies) override;
                Character *the_victim_for_ninja(Team *enemies, Character *the_ninja) const;
            public:
                SmartTeam(Character* leader):Team(leader){} 
                void attack(Team* enemies)override;
                void print()const override;   
    };
}