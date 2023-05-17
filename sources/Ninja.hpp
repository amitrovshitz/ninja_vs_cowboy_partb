#pragma once
#include "Character.hpp"
using namespace std;
namespace ariel
{
    class Ninja:public Character
    {
        private:
            int speed;
        public:
            Ninja(const Point& point, int hit, string name, int speed);
            void move(const Character * enemy);
            int getSpeed()const{return speed;}
            void slash(Character * enemy)const;
            string print()const override;
    };
    
}