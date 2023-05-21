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
    if (enemy == nullptr)
		throw invalid_argument("the enemy character is null!");

	if (enemy == this)
		throw invalid_argument("can't move to yourself!");

	if (!isAlive())
		throw runtime_error("can't move while dead!");
    if(!enemy->isAlive())
    {
        throw runtime_error("the enemy is dead.");
    }
    
    this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), speed));
}

void Ninja::slash(Character * enemy)const
{
	if (enemy == nullptr)
		throw invalid_argument("Other character is null!");

	if (enemy == this)
		throw runtime_error("Cannot slash yourself!");

	if (!isAlive())
		throw runtime_error("Cannot slash while dead!");

	if (!enemy->isAlive())
		throw runtime_error("Cannot slash a dead character!");
    if((getLocation().distance(enemy->getLocation()) <= 1.0))
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