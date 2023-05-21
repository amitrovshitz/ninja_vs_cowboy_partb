#include <iostream>
#include "Team2.hpp"
using namespace std;
using namespace ariel;

int Team2::stillAlive()const
{ 
    int count = 0;

	for (Character *fighter : getTeam())
	{
		if (((dynamic_cast<Cowboy*>(fighter) != nullptr) || (dynamic_cast<Ninja*>(fighter) != nullptr)) && fighter->isAlive())
			count++;
	}

    return count;
}
void Team2::print()const
{

    for(size_t j=0;j<getTeam().size();j++)
    {
        if(dynamic_cast<Ninja*>(getTeam().at(j)) != nullptr || dynamic_cast<Cowboy*>(getTeam().at(j)) != nullptr)
        {
            cout << (getTeam().at(j))->print() << endl;
        }
    }

}

void Team2::attack(Team* enemies)
{

	if (enemies == nullptr)
		throw invalid_argument("ilegal.");

	if (enemies == this)
		throw runtime_error("Can't attack self team");

	if (!enemies->stillAlive())
		throw runtime_error("not have alive members of the enemy team.");

	if (!stillAlive())
		throw runtime_error("all the team memers are dead."); 

    if(!(getLeader()->isAlive()))
    {
        new_leader();
        if(getLeader() == nullptr)
        {
            return;
        }
    }

    Character* the_enemy = (the_victim(enemies));

    if(!the_enemy)
    {
        return;
    }
    
	for (Character *fighter : getTeam())
	{
        if (!the_enemy->isAlive())
		{
			if (enemies->stillAlive() == 0)
				return;

			the_enemy = the_victim(enemies);
		}

		Cowboy * the_coboy = dynamic_cast<Cowboy *>(fighter);
        Ninja * the_ninja = dynamic_cast<Ninja *>(fighter);

		if (the_coboy != nullptr && the_coboy->isAlive())
		{
			if (the_coboy->hasboolets())
				the_coboy->shoot(the_enemy);

			else
				the_coboy->reload();
		}
        else if(the_ninja != nullptr && the_ninja->isAlive())
        {
			if (the_ninja->distance(the_enemy) <= 1.0)
				the_ninja->slash(the_enemy);

			else
				the_ninja->move(the_enemy);
        }
    }
}
   
Character* Team2::the_victim(Team* enemy)
{
    if(!enemy)
    {
        return nullptr;
    }

    if(!enemy->stillAlive())
    {

        return nullptr;
    }

    double min_distance = numeric_limits<double>::max();; 
    Character* victim = nullptr;

    for (Character *fighter : enemy->getTeam())
	{
		if (((dynamic_cast<Cowboy*>(fighter) != nullptr) || (dynamic_cast<Ninja*>(fighter) != nullptr)) && fighter->isAlive() && getLeader()->distance(fighter) < min_distance)
        {
		    victim = fighter;
            min_distance = getLeader()->distance(fighter);
        }
	}
    return victim;    
}
