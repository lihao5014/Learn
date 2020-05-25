#include "play_factory.h"
#include <ctime>

#define ARRAY_LEN(array,len)                   \
	do{                                            \
		len = sizeof(array)/sizeof(array[0]);      \
	}while(0)

int main()
{
    srand((unsigned)time(NULL));

    int playerLen;
    int weaponsLen;

	ARRAY_LEN(gPlayers, playerLen);	
	ARRAY_LEN(gWeapons, weaponsLen);

   for (int i = 0; i < 10; i++){
        int typeIndex = rand()%playerLen;
        int weaponIndex = rand()%weaponsLen;
        Player_t type = gPlayers[typeIndex];
        const char* weapon = gWeapons[weaponIndex];

        IPlayer *p = PlayerFactory::getPlayer(type);
        p->assignWeapon(weapon);
        p->mission();
    }
	
	return 0;
}