#include "smartTeam.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Character* SmartTeam::the_victim(Team* enemies){
	if(!enemies)
	{
		return nullptr;
	}

	Character *the_enemy = nullptr;
	int min_hit_point = numeric_limits<int>::max();

	for (Character* enemy : enemies->getTeam())
	{
		if (enemy->isAlive() && enemy->getHit() < min_hit_point)
		{
			min_hit_point = enemy->getHit();
			the_enemy = enemy;
		}
	}
	return the_enemy;
}

Character *SmartTeam::the_victim_for_ninja(Team *enemies, Character *the_ninja) const{
	if(!enemies)
	{
		return nullptr;
	}

	Character *the_enemy = nullptr;
	double min_distance = numeric_limits<double>::max();
	vector <Character*> Candidates_enemies;

	for (Character* enemy : enemies->getTeam())
	{
		if (enemy->isAlive() && the_ninja->distance(enemy) < min_distance)
		{
			min_distance = the_ninja->distance(enemy);
			the_enemy = enemy;
			if(the_ninja->distance(enemy) <= 1)
			{
				Candidates_enemies.push_back(enemy);
			}
		}
	}

	int temp_small_from_40 = 0;
	int temp_big_from_40 = 0;
	
	if(Candidates_enemies.size())
	{
		for(Character* enemy : Candidates_enemies)
		{
			if(enemy->getHit() == 40)
			{
				return enemy;
			}
			else if(enemy->getHit() < 40 && (temp_big_from_40 == 0))
			{
				if(enemy->getHit() > temp_small_from_40)
				{
					temp_small_from_40 = enemy->getHit();
					the_enemy = enemy;
				}
			}
			else if(enemy->getHit() > 40)
			{
				if(enemy->getHit() > temp_big_from_40)
				{
					temp_big_from_40 = enemy->getHit();
					the_enemy = enemy;
				}
			}
		}
	}
	return the_enemy;
}

void SmartTeam::attack(Team *enemies)
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
		Character *the_new_Leader = nullptr;
		double min_distance_from_the_leader = numeric_limits<double>::max();

		for (Character* fighter: getTeam())
		{
			if (fighter->isAlive() && fighter->distance(getLeader()) < min_distance_from_the_leader)
			{
				min_distance_from_the_leader = fighter->distance(getLeader());
				the_new_Leader = fighter;
			}
		}
		setLeader(the_new_Leader);
	}
	vector<Ninja *> my_ninja;
	vector<Cowboy *> my_cowboy;

	for (Character* fighter: getTeam())
	{
		Cowboy* the_cowboy = dynamic_cast<Cowboy*>(fighter);
		Ninja* the_ninja = dynamic_cast<Ninja*>(fighter);

		if (the_cowboy != nullptr && the_cowboy->isAlive())
			my_cowboy.push_back(the_cowboy);

		else if (the_ninja != nullptr && the_ninja->isAlive())
			my_ninja.push_back(the_ninja);
	}

	Character* enemy = nullptr;

	for (Ninja* ninja: my_ninja)
	{
		if (enemies->stillAlive() == 0)
			return;
		
		enemy = the_victim_for_ninja(enemies, ninja);

		if (ninja->distance(enemy) <= 1)
			ninja->slash(enemy);

		else
			ninja->move(enemy);
	}
	for (Cowboy* cowboy: my_cowboy)
	{
		if (enemies->stillAlive() == 0)
			return;
			
		enemy = the_victim(enemies);
		if (cowboy->hasboolets())
			cowboy->shoot(enemy);
		else
			cowboy->reload();
	}
}

void SmartTeam::print() const
{
    for(size_t j=0;j<getTeam().size();j++)
    {
        if(dynamic_cast<Ninja*>(getTeam().at(j)) != nullptr || dynamic_cast<Cowboy*>(getTeam().at(j)) != nullptr)
        {
            cout << (getTeam().at(j))->print() << endl;
        }
    }
}