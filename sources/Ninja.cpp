#include <iostream>
#include "Ninja.hpp"
using namespace std;
using namespace ariel;

Ninja::Ninja(const Point& point, int hit, string name, int speed):Character(point, hit, name), speed(speed)
{
    if(speed < 0)
    {
        throw invalid_argument("not ilegal.");    
    }
}

void Ninja::move(const Character * enemy)
{
    if(!enemy->isAlive())
    {
        throw runtime_error("The enemy is dead.");
    }
    this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), speed));
}

void Ninja::slash(Character * enemy)const
{
    if(!enemy->isAlive())
    {
        throw runtime_error("The enemy is dead.");
    }
    if(isAlive() && (getLocation().distance(enemy->getLocation()) <= 1.0))////////////////
    {
        enemy->hit(40);
    }
}

string Ninja::print()const 
{
    string result = "";
    if(isAlive())
    {
        result +=  ("N " + getName() + "  hit count is " + to_string(getHit()) + " and the location is " + getLocation().print() + "\n");
    }
    else
    {
        result +=  ("N (" + getName() + ") and the location is " + getLocation().print() + "\n");
    }
    return result;
}