#pragma once
#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{
    class Character
    {
        private:
            Point index;
            int hit_count;
            string name;
            bool have_a_team;

        public:
            Character(const Point& index, int hit, string name);
            Character(const Character& other);
            Character& operator=(const Character& other);
            Character(Character&& other) noexcept;
            Character& operator=(Character&& other) noexcept;
            virtual ~Character() {}
            bool isAlive()const{return (hit_count > 0);}
            double distance(const Character* other)const{return index.distance(other->index);}
            void hit(int value);
            int getHit()const{return hit_count;}
            string getName()const{return name;}
            Point getLocation()const{return index;}
            void setLocation(const Point point){index = point;}
            bool inTeam()const{return have_a_team;}
            void setTeam(bool team){have_a_team = team;}
            virtual string print()const=0;
    };
}