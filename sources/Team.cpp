#include <iostream>
#include "Team.hpp"
using namespace std;
using namespace ariel;

Team::~Team() 
{
    for (Character* member : team) 
    {
        delete member;
    }
    size = 0;
    leader = nullptr;
}

Team::Team(Character* leader):leader(leader), size(1)
{
    if (leader == nullptr) 
    {
        throw std::invalid_argument("Leader cannot be null");
    }
    team[0] = leader;
    leader->setTeam(true);
    for (size_t iter = 1; iter < 10; iter++)
        team[iter] = nullptr;
}

 Team::Team(const Team& other) : leader(other.leader), size(1)
{
    for (Character* member : other.team) 
    {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) 
        {
            Cowboy* aadCowboy = new Cowboy(*cowboy);
            team[size++] = aadCowboy;
        } 
        else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) 
        {
            Ninja* addNinja = new Ninja(*ninja);
            team[size++] = addNinja;
        }
    }
}

Team& Team::operator=(const Team& other)
{
    if (this != &other) 
    {
        for (Character* member : team) 
        {
            delete member;
        }
        leader = other.leader;
        size = 1;

        for (Character* member : other.team) 
        {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) 
            {
                Cowboy* addCowboy = new Cowboy(*cowboy);
                team[size++] = addCowboy;
            } 
            else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) 
            {
                Ninja* addNinja = new Ninja(*ninja);
                team[size++] = addNinja;
            }
        }
    }
    return *this;
}

Team::Team(Team&& other) noexcept : leader(other.leader), team(std::move(other.team))
{
    other.leader = nullptr;
}

Team& Team::operator=(Team&& other) noexcept
{
    if (this != &other) {
        for (Character* member : team) 
        {
            delete member;
        }

        leader = other.leader;
        team = std::move(other.team);

        other.leader = nullptr;
    }
    return *this;
}


void Team::add(Character* some)
{
    if(some->inTeam())
    {
        throw invalid_argument("It is impossible to enter the same fighter");
    }
    if(size >= 10)
    {
         throw "Too much Shapes";
    }
    else if(size < 10)
    {
        team[size++] = some;
        some->setTeam(true);
    }

}

void Team::attack(Team* enemies)
{
  /*  
    if(!(leader->isAlive()))
    {
        new_leader();
        if(leader == nullptr)
        {
            return;
        }
    }
    Character* enemy = nullptr;
    Character** the_enemy = (the_victim(enemies));
    if(!the_enemy)
    {
        return;
    }
    enemy = *the_enemy;
    for(int i=0;i<2;i++)
    {

        for(size_t j=0;j<size;j++)
        {
            if(!enemy->isAlive())
            {
                the_enemy = (the_victim(enemies));
                if(the_enemy == nullptr)
                {
                    return;
                }
                enemy = *the_enemy;
            }
            if(i == 0 && (dynamic_cast<Cowboy*>(team[j]) != nullptr) && (team[j]->isAlive()))
            {   
                if(dynamic_cast<Cowboy*>(team[j])->hasboolets())
                {
                    dynamic_cast<Cowboy*>(team[j])->shoot(enemy);
                }
                else
                {
                    dynamic_cast<Cowboy*>(team[j])->reload();
                }      
            }
            else if(i == 0 && (dynamic_cast<Ninja*>(team[j]) != nullptr) && (team[j]->isAlive())) 
            {
                if(dynamic_cast<Ninja*>(team[j])->getLocation().distance(enemy->getLocation()) < 1.0)
                {
                    dynamic_cast<Ninja*>(team[j])->slash(enemy);
                }
                else
                {
                    dynamic_cast<Ninja*>(team[j])->move(enemy);
                }  
            }
        }
    }
*/
}

size_t Team::stillAlive()const
{
  /*  
    size_t count = 0;
    for(int i=0;i<2;i++)
    {
        for(size_t j=0;j<size;j++)
        {
            if(i == 0 && (dynamic_cast<Cowboy*>(team[j]) != nullptr) && team[j]->isAlive())
            {
                count++;
            }
            else if(i == 1 && (dynamic_cast<Ninja*>(team[j]) != nullptr) && team[j]->isAlive())
            {
                count++;
            }
        }
    }
    
    return count;
*/
return 0;
}


void Team::new_leader()
{
    Character ** res = the_victim(this);
    if(!res)
    {
        leader = nullptr;
        return;
    }
    leader = *res;
}
double Team::the_enemy_distance(Team* enemy)
{
    size_t number = enemy->stillAlive();
    double distance_from_leader[enemy->stillAlive()];
    for(size_t i=0;i<enemy->stillAlive();i++)
    {
        distance_from_leader[i]=-1;
    }
    size_t k =0;
    for(int i=0;i<2;i++)
    {
        for(size_t j=0;j<enemy->size;j++)
        {
            if((number > 0) && i == 0 && (dynamic_cast<Cowboy*>(enemy->team[j]) != nullptr) && enemy->team[j]->isAlive())
            {
                distance_from_leader[k++] = leader->distance(enemy->team[j]);
                number--;
            }
            else if(i == 1 && (dynamic_cast<Ninja*>(enemy->team[j]) != nullptr) && enemy->team[j]->isAlive())
            {
                distance_from_leader[k++] = leader->distance(enemy->team[j]);
                number--;
            }
        }
    }

    sort(distance_from_leader, distance_from_leader+k);
    return distance_from_leader[0];
}

Character** Team::the_victim(Team* enemy)
{
    if(!enemy->stillAlive())
    {
        return nullptr;
    }

    double the_distance = the_enemy_distance(enemy); 
    
    for(int i=0;i<2;i++)
    {
        for(size_t j=0;j<enemy->size;j++)
        {
            if(i == 0 && (dynamic_cast<Cowboy*>(team[j]) != nullptr) && leader->distance(dynamic_cast<Cowboy*>(team[j])) == the_distance)
            {
                return &(enemy->team[j]);
            }
            else if(i == 1 && (dynamic_cast<Ninja*>(team[j]) != nullptr) && leader->distance(dynamic_cast<Ninja*>(team[j])) == the_distance)
            {
                return &(enemy->team[j]);
            }
        }
    }
    return nullptr;
}

void Team::print()const
{
    for(size_t i=0;i<size;i++)
    {
        if(dynamic_cast<Cowboy*>(team[i]) != nullptr)
        {
            cout << team[i]->print() << endl;
        }
    }
        for(size_t i=0;i<size;i++)
    {
        if(dynamic_cast<Ninja*>(team[i]) != nullptr)
        {
            cout << team[i]->print() << endl;
        }
    }
}