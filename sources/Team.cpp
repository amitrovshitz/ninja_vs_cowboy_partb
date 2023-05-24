#include <iostream>
#include <vector>
#include "Team.hpp"
using namespace std;
using namespace ariel;

const int MAX_TEAM = 10;

Team::Team(Character *leader) : leader(leader)
{
	if (leader == nullptr)
		throw invalid_argument("Leader is null!");

	if (leader->inTeam())
		throw runtime_error("Leader is already in a team!");

	team.reserve(MAX_TEAM);
	team.push_back(leader);

	leader->setTeam(true);
}

Team::~Team()
{
	for (Character *fighter : team)
		delete fighter;

	team.clear();
}

Team::Team(const Team &other)
{
	team.reserve(MAX_TEAM);

	for (Character *fighter : other.team)
	{
		if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
		{
			Cowboy *addCowboy = new Cowboy(*cowboy);
			team.push_back(addCowboy);
		}

		else if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
		{
			Ninja *addNinja = new Ninja(*ninja);
			team.push_back(addNinja);
		}
	}

	leader = team.at(0);
}

Team &Team::operator=(const Team &other)
{
	if (this != &other)
	{
		for (Character *fighter : team)
			delete fighter;

		team.clear();
		team.reserve(MAX_TEAM);

		for (Character *fighter : other.team)
		{
			if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
			{
				Cowboy *addCowboy = new Cowboy(*cowboy);
				team.push_back(addCowboy);
			}

			else if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
			{
				Ninja *addNinja = new Ninja(*ninja);
				team.push_back(addNinja);
			}
		}
		leader = team.at(0);
	}

	return *this;
}

Team::Team(Team &&other) noexcept : leader(other.leader), team(move(other.team))
{
	other.leader = nullptr;
}

Team &Team::operator=(Team &&other) noexcept
{
	if (this != &other)
	{
		for (Character *fighter : team)
			delete fighter;

		team.clear();

		leader = other.leader;
		team = move(other.team);

		other.leader = nullptr;
	}

	return *this;
}

void Team::add(Character* some)
{

    if (some == nullptr)
    {
	    throw invalid_argument("Other character is null!");
    }

    if(some->inTeam())
    {
        throw runtime_error("It is impossible to enter the same fighter");
    }

    if(team.size() >= MAX_TEAM)
    {
         throw runtime_error("Too much Characters.");
    }

    team.push_back(some);
    some->setTeam(true);

}

void Team::attack(Team* enemies)
{

	if (enemies == nullptr)
		throw invalid_argument("ilegal.");

	if (enemies == this)
		throw runtime_error("Can't attack self team");

	if (!enemies->stillAlive())
		throw runtime_error("not have alive members of the enemy team.");

	if (!stillAlive())
		throw runtime_error("all the team memers are dead."); 

    if(!(leader->isAlive()))
    {
        new_leader();
        if(leader == nullptr)
        {
            return;
        }
    }

    Character* the_enemy = (the_victim(enemies));

    if(!the_enemy)
    {
        return;
    }
    
	for (Character *fighter : team)
	{
        if (!the_enemy->isAlive())
		{
			if (enemies->stillAlive() == 0)
				return;

			the_enemy = the_victim(enemies);
		}

		Cowboy * the_coboy = dynamic_cast<Cowboy *>(fighter);

		if (the_coboy != nullptr && the_coboy->isAlive())
		{
			if (the_coboy->hasboolets())
				the_coboy->shoot(the_enemy);

			else
				the_coboy->reload();
		}
    }
    for (Character *fighter : team)
	{
        if (!the_enemy->isAlive())
		{
			if (enemies->stillAlive() == 0)
				return;

			the_enemy = the_victim(enemies);
		}

		Ninja * the_ninja = dynamic_cast<Ninja *>(fighter);

		if (the_ninja != nullptr && the_ninja->isAlive())
		{
			if (the_ninja->distance(the_enemy) <= 1.0)
				the_ninja->slash(the_enemy);

			else
				the_ninja->move(the_enemy);
		}
    }
}

int Team::stillAlive()const
{ 
    int count = 0;

	for (Character *fighter : team)
	{
		if ((dynamic_cast<Cowboy*>(fighter) != nullptr) && fighter->isAlive())
			count++;
	}
    for (Character *fighter : team)
	{
		if ((dynamic_cast<Ninja*>(fighter) != nullptr) && fighter->isAlive())
			count++;
	}
    
    return count;
}


void Team::new_leader()
{
    setLeader(the_victim(this));
}

Character* Team::the_victim(Team* enemy)
{
    if(!enemy)
    {
        return nullptr;
    }
    
    double min_distance = numeric_limits<double>::max();
    Character* victim = nullptr;
    for (Character *fighter : enemy->team)
	{
		if ((dynamic_cast<Cowboy*>(fighter) != nullptr) && fighter->isAlive() && leader->distance(fighter) < min_distance)
        {
            victim = fighter;
            min_distance = leader->distance(fighter);
        }
	}
    for (Character *fighter : enemy->team)
	{
		if ((dynamic_cast<Ninja*>(fighter) != nullptr) && fighter->isAlive() && leader->distance(fighter) < min_distance)
		{
            victim = fighter;
            min_distance = leader->distance(fighter);
        }
	}
    return victim;
    
}


void Team::print()const
{
    for(size_t j=0;j<team.size();j++)
    {
        if(dynamic_cast<Cowboy*>(team.at(j)) != nullptr)
        {
            cout << (team.at(j))->print() << endl;
        }
    }
    for(size_t j=0;j<team.size();j++)
    {
        if(dynamic_cast<Ninja*>(team.at(j)) != nullptr)
        {
            cout << (team.at(j))->print() << endl;
        }
    }
}