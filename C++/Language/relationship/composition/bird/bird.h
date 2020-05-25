#ifndef _BIRD_H
#define _BIRD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

#include "beak.h"
#include "leg.h"
#include "wing.h"

class Bird
{
public:
	Bird(const Color_t color,const char* type,const string& feature);
	
	void detail()const;
private:
	Beak beak;             //一只鸟有一个喙
	Leg legs[2];           //一只鸟有两条腿
	Wing wings[2];         //一只鸟有两只翅膀
};

Bird::Bird(const Color_t color,const char* type,const string& feature)
	:beak(color)
	,legs{type,type}
	,wings{feature,feature}
{
	legs[1] = "hoof";              //调用Leg重载的赋值运算符operator =(const char* type)。
	wings[1] = "swim";             //调用Wing重载的赋值运算符operator =(const char* feature)。
}

void Bird::detail()const
{
	beak.show();
	legs[0].print();
	legs[1].print();
	wings[0].display();
	wings[1].display();
}

#endif //_BIRD_H