#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja:public Ninja
    {
        static const int HIT = 120, SPEED = 12; 
        public:
            TrainedNinja(const string& name, const Point& point):Ninja(point, HIT, name, SPEED){}
    };
}