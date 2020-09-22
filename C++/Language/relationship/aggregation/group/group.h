#ifndef _GROUP_H
#define _GROUP_H

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include "element.h"
#include "entity.h"

#define ELEMENT_COUNT 4

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Group
{
public:
	Group(const string& number);
	Group(const Group& other);
	virtual ~Group();                   //类中使用了指针成员，一般都需要定义构造函数来释放指针资源
	
	void setNumber(const string& number);
	string getNumber()const;
	
	void addElement(Element* pelement);
	void removeElement(Element* pelement);
	Element* getElement(const int index);
	
	void addEntity(const Entity& entity);
	void removeEntity(const Entity& entity);
	Entity& getEntity(const int index);
	
	void print()const;
private:
	Group& operator =(const Group& other);     //删除赋值运算符
	
	string number;
	Element* elements[ELEMENT_COUNT];
	vector<Entity> entitys;
};

Group::Group(const string& number)
	:number(number)
	,elements{nullptr}
{
	
}

Group::Group(const Group& other)
	:number(other.number)
	,entitys(entitys)
{
	for(int i=0;i<ELEMENT_COUNT;++i)
	{
		if(other.elements[i] != nullptr)
		{
			elements[i] = new Element(*(other.elements[i]));
			continue;
		}
		elements[i] = nullptr;
	}
}

Group::~Group()
{
	for(int i=0;i<ELEMENT_COUNT;++i)
	{
		if(elements[i] != nullptr)
		{
			delete elements[i];
			elements[i] = nullptr;
		}
	}
}

void Group::setNumber(const string& number)
{
	this->number = number;
}

string Group::getNumber()const
{
	return number;
}

void Group::addElement(Element* pelement)
{
	if(pelement == nullptr)
	{
		cout<<"Group addElement error: pelement is nullptr"<<endl;
		return ;
	}
	
	for(int i=0;i<ELEMENT_COUNT;++i)
	{
		if(elements[i] == nullptr)
		{
			elements[i] = new Element(*pelement);     //使用深拷贝
			return ;
		}
	}
	
	cout<<"Group addElement warn: element array is full"<<endl;
}

void Group::removeElement(Element* pelement)    //每次只删除数组中最先找到的*pelement
{
	if(pelement == nullptr)
	{
		cout<<"Group removeElement error: pelement is nullptr"<<endl;
		return ;
	}
	
	for(int i=0;i<ELEMENT_COUNT;++i)
	{
		if(elements[i] != nullptr && *elements[i] == *pelement)   //delete指针时不需要做判空处理，但是访问指针指向的值必须做判空处理，否则软件有可能会崩溃
		{
			delete elements[i];
			elements[i] = nullptr;
			return ;
		}
	}
}

Element* Group::getElement(const int index)
{
	if(index < 0 || index > ELEMENT_COUNT)
	{
		cout<<"Group getElement error: index is illegal"<<endl;
		return nullptr;
	}
	
	return elements[index];
}

void Group::addEntity(const Entity& entity)
{
	entitys.push_back(entity);
}

void Group::removeEntity(const Entity& entity)     //每次删除vector中包含的所有entity
{
	vector<Entity>::iterator iter = entitys.begin();
	while(iter != entitys.end())
	{
		if(*iter == entity)
		{
			entitys.erase(iter);       //vector中没有remove移除方法，只有erase擦除方法
		}
		++iter;
	}
}

Entity& Group::getEntity(const int index)
{
	assert(index >= 0 && index <= entitys.size());
	return entitys[index];
}

void Group::print()const
{
	cout<<"Group number: "<<number<<endl;
	
	for(int i=0;i<ELEMENT_COUNT;++i)
	{
		if(elements[i] != nullptr)
		{
			elements[i]->show();
		}
	}
	
	for(const auto entity: entitys)
	{
		entity.display();
	}
}

#endif //_GROUP_H