#ifndef _PLAYER_FACTORY_H
#define _PLAYER_FACTORY_H

#include "concrete_player.h"
#include <map>

class PlayerFactory
{
public:
	~PlayerFactory()
	{
		for(auto data:m_map){
			if(data.second != nullptr){
				delete data.second;
				data.second = nullptr;
			}
		}
		
		m_map.erase(m_map.begin(),m_map.end());
	}
	
    static IPlayer* getPlayer(Player_t type)
    {
		IPlayer* player = nullptr;
		std::map<Player_t, IPlayer*>::iterator iter = m_map.find(type);
        if (iter != m_map.end()) {
			player = m_map[type];
            return player;
        }

		if (type == TERRORIST) {
			player = new Terrorist();
		}else if (type == SOLDIER) {
			player = new Soldier();
		}else{
			std::cout << "type is illegal" << std::endl;
		}
		m_map.insert(std::make_pair(type, player));
        return player;
    }
private:
    static std::map<Player_t, IPlayer*> m_map;
};

std::map<Player_t, IPlayer*>  PlayerFactory::m_map;

#endif //_PLAYER_FACTORY_H