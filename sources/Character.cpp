#include "Character.hpp"
#include <iostream>
using namespace ariel;

Character::Character(const Point& index, int hit, string name):index(index), hit_count(hit), name(name), have_a_team(false)
{
    if(hit < 0)
    {
        throw invalid_argument("not ilegal.");
    }
}

 
Character::Character(const Character& other): index(other.index), hit_count(other.hit_count), name(other.name){}

Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        hit_count = other.hit_count;
        name = other.name;
    }
    return *this;
}

Character::Character(Character&& other) noexcept: index(other.index), hit_count(other.hit_count), name(std::move(other.name))
{
    other.hit_count = 0;
}

Character& Character::operator=(Character&& other) noexcept
{
    if (this != &other) {
        hit_count = other.hit_count;
        name = std::move(other.name);
        other.hit_count = 0;
    }
    return *this;
}


void Character::hit(int value)
{
    if(value < 0)
    {
        throw invalid_argument("not ilegal.");
    }
    else
    {
        hit_count-=value;
    }
}