#ifndef _TURN_H
#define _TURN_H

struct Turn
{
	virtual ~Turn(){};
	virtual void turnUp() = 0;
	virtual void turnDown() = 0;
};

#endif //_TURN_H