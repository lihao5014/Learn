#ifndef _CONCRETE_PLAYER_H
#define _CONCRETE_PLAYER_H

#include "iplayer.h"
#include <string.h>
#include <iostream>

Player_t gPlayers[2] = {TERRORIST,SOLDIER};
const char* gTasks[2] = {"Plant a bomb","Diffuse bomb"};
const char* gWeapons[4] = {"AK-47", "Maverick", "Gut Knife", "Desert Eagle"};

class Terrorist:public IPlayer
{
public:
    Terrorist()
	{
		memset(this->task,0,SIZE);
		memset(this->weapon,0,SIZE);
		strcpy(task,gTasks[0]);
    }

    virtual void assignWeapon(const char* weapon)override
	{
        if(weapon == nullptr || strlen(weapon) >= SIZE){
			std::cout<<"weapon is illegal"<<std::endl;
		}
		memset(this->weapon,0,SIZE);
		strcpy(this->weapon,weapon);
    }

    virtual void mission()final
	{
		std::cout << "Terrorist with weapon "<<weapon<<", Task is "<<task<< std::endl;
    }
};

class Soldier:public IPlayer
{
public:
    Soldier()
	{
		memset(this->task,0,SIZE);
		memset(this->weapon,0,SIZE);
        strcpy(task,gTasks[1]);
    }

    virtual void assignWeapon(const char weapon[])override
	{
        if(weapon == nullptr || strlen(weapon) >= SIZE){
			std::cout<<"weapon is illegal"<<std::endl;
		}
		memset(this->weapon,0,SIZE);
		strcpy(this->weapon,weapon);
    }

    virtual void mission()final
	{
        std::cout << "Soldier with weapon "<<weapon<<", Task is "<<task<< std::endl;
    }
};


#endif //_CONCRETE_PLAYER_H