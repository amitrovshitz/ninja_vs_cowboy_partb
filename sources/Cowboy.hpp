#pragma once
#include "Character.hpp"
using namespace std;
namespace ariel
{

    class Cowboy:public Character
    {
        private:
            int amount_of_bullets;
            static const int AMOUNT = 6, HIT = 110; 
        public:
            Cowboy(const string& name, const Point& point):Character(point, HIT, name), amount_of_bullets(AMOUNT){};
            Cowboy(const Cowboy& other);
            Cowboy& operator=(const Cowboy& other);
            Cowboy(Cowboy&& other) noexcept;
            Cowboy& operator=(Cowboy&& other) noexcept;
            ~Cowboy() override = default;
            void shoot(Character * enemy);
            int getBullets()const{return amount_of_bullets;}
            bool hasboolets()const{return (amount_of_bullets>0);}
            void reload(){amount_of_bullets+=AMOUNT;}
            string print()const override;
    };
    
}