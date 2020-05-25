#ifndef _IPLAYER_H
#define _IPLAYER_H

#define SIZE 32

typedef enum PlayerType
{
	TERRORIST,
	SOLDIER
}Player_t;

class IPlayer
{
public:
	virtual ~IPlayer(){}
	virtual void assignWeapon(const char weapon[]) = 0;
	virtual void mission() = 0;
protected:
	char task[SIZE];
	char weapon[SIZE];
};

#endif //_IPLAYER_H