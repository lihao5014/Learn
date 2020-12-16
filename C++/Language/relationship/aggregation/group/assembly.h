#ifndef _ASSEMVLY_H
#define _ASSEMVLY_H

#include <array>
#include <vector>
#include <iostream>
#include "element.h"
#include "entity.h"

#define ELEMENT_SIZE 4

using namespace std;

class Assembly
{
public:
	Assembly(const double weight);
	Assembly(const Assembly& other);
	virtual ~Assembly();                    //类中使用了指针成员，一般都需要定义构造函数来释放指针资源
	
	Assembly& operator =(const Assembly& other) = delete;   //禁用拷贝运算符
	
	void setWeight(const double weight);
	double getWeight()const;
	
	void addElement(Element* pelement);
	void removeElement(Element* pelement);
	Element* getElement(const int index);
	
	void addEntity(Entity* pentity);
	void removeEntity(Entity* pentity);
	Entity* getEntity(const int index);
	
	void detail()const;
private:	
	double weight;
	array<Element*,ELEMENT_SIZE> elements;
	vector<Entity*> entitys;
};

Assembly::Assembly(const double weight)
	:weight(weight)
	,elements{nullptr,nullptr,nullptr,nullptr}
{
	
}

Assembly::Assembly(const Assembly& other)
	:weight(other.weight)
{
	for(int i=0;i<ELEMENT_SIZE;++i)
	{
		if(other.elements[i] == nullptr)
		{
			elements[i] = nullptr;
			continue;
		}
		elements[i] = new Element(*(other.elements[i]));
	}
	
	for(int i=0;i<other.entitys.size();++i)
	{
		if(other.entitys[i] != nullptr)
		{
			entitys.push_back(new Entity(*(other.entitys[i])));    //因为需要访问指针other.entitys[i]指向的内容，所有必须做判空处理
		}
	}
}

Assembly::~Assembly()
{
	for(int i=0;i<ELEMENT_SIZE;++i)
	{
		delete elements[i];      //delete指针时可以不用做判空处理，因为nullptr可以delete，且野指针满足不为空
	}
	
	vector<Entity*>::iterator iter = entitys.begin();
	for(;iter != entitys.end();++iter)
	{
		delete *iter;
	}
}

void Assembly::setWeight(const double weight)
{
	this->weight = weight;
}

double Assembly::getWeight()const
{
	return weight;
}

void Assembly::addElement(Element* pelement)
{
	if(pelement == nullptr)
	{
		cout<<"Assembly addElement error: pelement is null"<<endl;
		return ;
	}
	
	for(int i=0;i<ELEMENT_SIZE;++i)
	{
		if(elements[i] != nullptr)
		{
			continue;
		}
		elements[i] = pelement;    //使用浅拷贝
		return ;
	}
	
	cout<<"Assembly addElement warn: element array is full"<<endl;
}

void Assembly::removeElement(Element* pelement)    //每次删除数组中所有等于*pelement的项
{
	if(nullptr == pelement)
	{
		cout<<"Assembly removeElement error: pelement is null"<<endl;
		return ;
	}
	
	for(int i=0;i<ELEMENT_SIZE;++i)
	{
		if(elements[i] != nullptr && *elements[i] == *pelement)
		{
			delete elements[i];
			elements[i] = nullptr;
		}
	}
}

Element* Assembly::getElement(const int index)
{
	if(index <0 || index > ELEMENT_SIZE)
	{
		cout<<"Assembly getElement error: index is illegal"<<endl;
		return nullptr;
	}
	
	return elements[index];
}

void Assembly::addEntity(Entity* pentity)
{
	if(nullptr == pentity)
	{
		cout<<"Assembly addEntity error: pentity is null"<<endl;
		return ;
	}
	
	entitys.push_back(pentity);      //使用浅拷贝
}

void Assembly::removeEntity(Entity* pentity)     //每次删除vector中所有等于*pentity的项
{
	if(nullptr == pentity)
	{
		cout<<"Assembly removeEntity error: pentity is null"<<endl;
		return ;
	}
	
	vector<Entity*>::iterator iter = entitys.begin();
	while(iter != entitys.end())
	{
		if(*iter != nullptr && **iter == *pentity)
		{
			delete *iter;
			*iter = nullptr;
			entitys.erase(iter++);    //将内存释放掉了的Entity指针从vector容器中移除掉，以减小vector容器的大小。
		}
		++iter;
	}
}

Entity* Assembly::getEntity(const int index)
{
	if(index < 0 || index > entitys.size())
	{
		cout<<"Assembly getEntity error: index is out of range"<<endl;
		return nullptr;
	}
	
	return entitys[index];
}

void Assembly::detail()const
{
	cout<<"Assembly weight: "<<weight<<endl;
	
	for(int i=0;i<ELEMENT_SIZE;++i)
	{
		if(elements[i] != nullptr)
		{
			elements[i]->show();
		}
	}
	
	for(const Entity* pentity: entitys)
	{
		if(pentity != nullptr)
		{
			pentity->display();
		}
	}
}

#endif //_ASSEMVLY_H