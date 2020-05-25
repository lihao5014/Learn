#ifndef _POINT_H
#define _POINT_H

#include <iostream>

#define PROPERTY(type,name)               \
private:                                  \
	type name;                            \
public:                                   \
	void set_##name(const type& name)     \
	{                                     \
		this->name = name;                \
	}                                     \
                                          \
	type get_##name()const                \
	{                                     \
		return name;                      \
	}

#define VISITOR(type,name)                \
public:                                   \
	void set##name(const type& name)      \
	{                                     \
		this->name = name;                \
	}                                     \
                                          \
	type get##name()const                 \
	{                                     \
		return name;                      \
	}

typedef int data_t;

class Point
{
	PROPERTY(data_t,x)
	PROPERTY(data_t,y)
	VISITOR(data_t,z);
public:
	Point(data_t x=0,data_t y=0,data_t z=0);
	Point(const Point& other);
	virtual ~Point();
	
	void showPoint()const;
	friend std::ostream& operator <<(std::ostream& os,const Point& point);
private:
	data_t z;
};

#endif //_POINT_H