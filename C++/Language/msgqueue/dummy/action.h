#ifndef _ACTION_H
#define _ACTION_H

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define EPS 0.000001

typedef double (*pFun)(double,double);

typedef enum Action_t
{
	ADD = 0,
	SUB,
	MULT,
	DIVI,
	MAX,
	MIN,
	ACTION_COUNT	
}Action_t;

typedef struct Message
{
	Action_t action;
	pFun pfun;
}Message;

#ifndef _CHANGE_WAY_
extern const Message messageMap[];      //œ˚œ¢”≥…‰
#else
extern Message messageMap[]; 
#endif

extern const int messageMap_size;

extern double doProcess(double x,double y,Action_t action);

extern double add(double x,double y);
extern double sub(double x,double y);
extern double mult(double x,double y);
extern double divi(double x,double y);
extern double max(double x,double y);
extern double min(double x,double y);

#endif //_ACTION_H