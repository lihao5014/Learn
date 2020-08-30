#include "goose.h"
#include <cassert>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

Goose::Goose(const char* number)
{
	if(number == nullptr)
	{
		cout<<"Goose constructor error: number is nullptr"<<endl;
		throw "Goose constructor error: number is nullptr";
	}
	
	this->number = new char[strlen(number) + 1];
	memcpy(this->number,number,strlen(number) + 1);
}

Goose::Goose(const Goose& other)
{
	if(other.number == nullptr)
	{
		cout<<"copy constructor error: other.number is nullptr"<<endl;
		throw "copy constructor error: other.number is nullptr";
	}
	
	int len = strlen(other.number) + 1;
	number = new char[len];
	memset(number,0,len);
	memcpy(number,other.number,len);
}

Goose::~Goose()
{
#ifndef _CHANGE_WAY_
	delete[] number;          //delete或free前可以不用做判空处理，因为nullptr指针也可以delete或free
#else
	if(nullptr != number)   //1.判断条件nullptr != number并不能排除number是野指针的情况，因为野指针也不指向nullptr。
	{
		delete[] number;      //2.C++语言规定nullptr指针是可以delete的，程序并不会崩溃。
		number = nullptr;
	}
#endif
}
	
void Goose::setNumber(const char* number)
{
	if(nullptr == number)
	{
		cout<<"setNumber error: number is nullptr"<<endl;
		return ;
	}
	
	delete this->number;
	this->number = new char[strlen(number) + 1];
	strcpy(this->number,number);
}

const char* Goose::getNumber()const
{
	return number;
}

Goose& Goose::operator =(const Goose& other)
{
	assert(other.number != nullptr);
	
	delete[] number;
	int len = strlen(other.number) + 1;
	number = new char[len];
	memset(number,0,len);
	strcpy(number,other.number);
	
	return *this;
}

bool Goose::operator ==(const Goose& other)
{
	return strcmp(number,other.number) == 0 ? true : false;
}

void Goose::show()const
{
	if(number == nullptr)     //在指针做读取或者写入操作时，才需要做判空处理。如果指针delete操作，则不需要判空处理。
	{
		return ;
	}
	
	cout<<"number ="<<number<<endl;
}