#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja:public Ninja
    {
        static const int HIT = 150, SPEED = 8; 
        public:
            OldNinja(const string& name,  const Point& point):Ninja(point, HIT, name, SPEED){}
    };
}