#ifndef _FUNCTOR_H
#define _FUNCTOR_H

#include <stdio.h>

typedef int data_t;

bool ascend(data_t x,data_t y)
{
	return x < y;
}

bool descend(data_t x,data_t y)
{
	return x > y;
}

void print(data_t x)
{
	printf("%d ",x);
}

void display(data_t arr[],int size)
{
	for(int i=0;i<size;++i)
	{
		printf("arr[%d] =%d ",i,arr[i]);
	}
	puts("");
}

template <typename T>
class Show
{
public:
	void operator ()(const T& x)
	{
		fprintf(stdout,"%d ",x);
	}
};

template <class T>
class Compare
{
public:
	bool operator ()(const T& x,const T& y)const
	{
		return x < y ? true : false;
	}
};

#endif //_FUNCTOR_H