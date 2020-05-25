#ifndef _ENGINE_H
#define _ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Engine
{
public:
	Engine(const char* brand);
	Engine(const Engine& other);
	~Engine();
	
	void operator =(const char* brand);
	Engine operator =(const Engine& other);
	
	void show()const;
private:
	char* brand;
};

Engine::Engine(const char* brand)
	:brand(nullptr)
{
	if(brand != nullptr)                 //构造函数中建议使用这种嵌套if语句，这样可以减少使用exit、assert、abort和throw等方法
	{
		this->brand = (char*)malloc(strlen(brand) + 1);
		if(this->brand == nullptr)
		{
			printf("malloc brand error\n");
			throw "malloc brand error";           //使用了C和C++的语法混合编程
		}
		
		memcpy(this->brand,brand,strlen(brand) + 1);
	}
}

Engine::Engine(const Engine& other)
	:brand(nullptr)
{
	if(other.brand != nullptr)            //构造函数中建议使用这种嵌套if语句，这样可以减少使用exit、assert、abort和throw等方法
	{
		brand = (char*)malloc(strlen(other.brand) + 1);
		if(brand == nullptr)
		{
			printf("malloc brand error\n");
			throw "malloc brand error";
		}
		
		strcpy(brand,other.brand);
	}	
}

Engine::~Engine()
{
	if(brand != NULL)
	{
		free(brand);
		brand = NULL;
	}
}

void Engine::operator =(const char* brand)
{
	if(brand == NULL)                //成员函数中都不建议使用嵌套if语句，直接取反return掉
	{
		fputs("brand is null",stdout);
		return ;
	}
	
	if(this->brand != NULL)
	{
		free(this->brand);
		this->brand = NULL;
	}
	
	this->brand = (char*)malloc(strlen(brand) + 1);
	if(this->brand == NULL)
	{
		puts("brand malloc failed");
		return ;
	}
	
	memcpy(this->brand,brand,strlen(brand) + 1);
}

Engine Engine::operator =(const Engine& other)
{
	if(other.brand == nullptr)             //成员函数中都不建议使用嵌套if语句，直接取反return掉
	{
		fprintf(stdout,"other.brand is null\n");
		return Engine(NULL);
	}
	
	if(brand != nullptr)
	{
		free(brand);
		brand = nullptr;
	}
	
	brand = (char*)malloc(strlen(other.brand) + 1);
	if(brand == nullptr)
	{
		fputs("brand malloc failed",stdout);
		return Engine(nullptr);
	}
	
	strcpy(brand,other.brand);
	return *this;
}

void Engine::show()const
{
	if(brand == NULL)
	{
		puts("show: brand is null");
		return ;
	}
	
	printf("engine brand =%s\n",brand);
}

#endif