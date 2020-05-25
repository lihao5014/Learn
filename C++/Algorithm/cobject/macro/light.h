#ifndef _LIGHT_H
#define _LIGHT_H

#include "cclass.h"

CLASS(Light)
{
	void (*turnOn)();
	void (*turnOff)();
};

#endif //_LIGHT_H