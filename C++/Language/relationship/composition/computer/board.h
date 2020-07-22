#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <cstring>      //等于#include <string.h>

class Board
{
public:
	Board(const char* brand);
	Board(const Board& other);
	virtual ~Board();                 //有指针数据成员，所以需要写析构函数
	
	void setBrand(const char* brand);
	const char* getBrand()const;
	
	void display()const;
private:
	char* brand;
};

Board::Board(const char* brand)
{
	if(brand == nullptr)
	{
		throw "Board construct error: brand is nullptr";
	}
	
	int len = strlen(brand) + 1;
	this->brand = new char[len];
	memcpy(this->brand,brand,len);
}

Board::Board(const Board& other)
{
	if(other.brand == nullptr)
	{
		throw "Board copy construct error: other.brand is nullptr";
	}
	
	if(brand != nullptr)
	{
		delete[] brand;
		brand = nullptr;
	}

	int len = strlen(other.brand) + 1;
	brand = new char[len];
	memset(brand,0,len);
	strcpy(brand,other.brand);
}

Board::~Board()
{
	if(brand != nullptr)
	{
		delete[] brand;
		brand = nullptr;
	}
}

void Board::setBrand(const char* brand)
{
	if(brand == nullptr)
	{
		std::cout<<"setBrand error: brand is null"<<std::endl;
		return ;
	}
	
	if(this->brand != nullptr)
	{
		delete[] this->brand;
		this->brand = nullptr;
	}
	
	int len = strlen(brand) + 1;
	this->brand = new char[len];
	memcpy(this->brand,brand,len);
}

const char* Board::getBrand()const
{
	return brand;
}

void Board::display()const
{
	if(brand != nullptr)
	{
		std::cout<<"board brand is: "<<brand<<std::endl;
	}
}

#endif //_BOARD_H