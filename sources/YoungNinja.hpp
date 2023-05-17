#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja:public Ninja
    {
        static const int HIT = 100, SPEED = 14; 
        public:
            YoungNinja(const string& name, const Point& point):Ninja(point, HIT, name, SPEED){}

    };
}