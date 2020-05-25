#ifndef _COLOR_H
#define _COLOR_H

class Color
{
public:
	virtual ~Color(){}
	virtual void fill() = 0;
};

#endif //_COLOR_H