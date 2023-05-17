#pragma once
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <array>

using namespace std;
namespace ariel
{
    class Team
    {
        private:
            static const int SIZE = 10;
            std::array<Character*, SIZE> team;
            Character* leader; 
            size_t size;

        public:
            Team(Character* leader);
            virtual ~Team();
            Team(const Team& other);
            Team& operator=(const Team& other);
            Team(Team&& other) noexcept;
            Team& operator=(Team&& other) noexcept;
            size_t getSize()const{return size;}
            void add(Character* some);// the same player in 2 group.
            virtual void attack(Team* enemy);
            virtual size_t stillAlive()const;
            void new_leader();
            virtual double the_enemy_distance(Team* enemy);
            virtual Character** the_victim(Team* enemy);// always return the victims and if not have return null.
            virtual void print()const;
    };
}
//////////////////////chrck the casting////////////////////////////
