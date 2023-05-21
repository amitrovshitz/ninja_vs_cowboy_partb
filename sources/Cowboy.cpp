#include <iostream>
#include "Cowboy.hpp"
using namespace std;
using namespace ariel;

Cowboy::Cowboy(const Cowboy& other): Character(other), amount_of_bullets(other.amount_of_bullets) {}

Cowboy& Cowboy::operator=(const Cowboy& other)
{
    if (this != &other) {
        Character::operator=(other);
        amount_of_bullets = other.amount_of_bullets;
    }
    return *this;
}

Cowboy::Cowboy(Cowboy&& other) noexcept: Character(std::move(other)), amount_of_bullets(other.amount_of_bullets)
{
    other.amount_of_bullets = 0;
}

Cowboy& Cowboy::operator=(Cowboy&& other) noexcept
{
    if (this != &other) {
        Character::operator=(std::move(other));
        amount_of_bullets = other.amount_of_bullets;
        other.amount_of_bullets = 0;
    }
    return *this;
}

void Cowboy::shoot(Character * enemy)
{
    if (enemy == nullptr)
		throw invalid_argument("Other character is null!");

	if (enemy == this)
		throw runtime_error("Can't shoot yourself!");

	if (!isAlive())
		throw runtime_error("Cannot shoot while dead!");

    if(!enemy->isAlive())
    {
        throw runtime_error("The enemy is dead.");
    }
    
    if(hasboolets())
    {
        amount_of_bullets--;
        enemy->hit(10);
    }
}

 string Cowboy::print()const 
{
    string result = "";
    if(isAlive())
    {
        result +=  ("C " + getName() + "  hit count is " + to_string(getHit()) + " and the location is " + getLocation().print() + "\n");
    }
    else
    {
        result +=  ("C (" + getName() + ") and the location is " + getLocation().print() + "\n");
    }
    return result;
}
void Cowboy::reload() {
	if (!this->isAlive())
		throw runtime_error("Cowboy is dead.");
	
	this->amount_of_bullets = 6;
}
