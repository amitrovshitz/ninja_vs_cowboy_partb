#pragma once
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>

using namespace std;
namespace ariel
{
    class Team
    {
        private:
            std::vector<Character *> team;
            Character* leader; 
        public:
            Team(Character* leader);
            virtual ~Team();
            Team(const Team& other);
            Team& operator=(const Team& other);
            Team(Team&& other) noexcept;
            Team& operator=(Team&& other) noexcept;
            std::vector<Character *> getTeam() const {
				return team; 
			}
            void add(Character* some);
            virtual void attack(Team* enemy);
            virtual int stillAlive()const;
            void new_leader();
            void setLeader(Character* the_new_leader){leader = the_new_leader;}
            Character* getLeader()const{return leader;}
            virtual Character* the_victim(Team* enemy);
            virtual void print()const;
    };
}
