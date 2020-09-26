#ifndef _ENTITY_H
#define _ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

class Entity
{
public:
	Entity(const char* name);
	Entity(const Entity& other);
	virtual ~Entity();              //类中只要使用了指针成员变量，一般都需要使用析构函数来释放内存
	
	Entity& operator =(const Entity& other);
	bool operator ==(const Entity& other);
	
	void setName(const char* name);
	const char* getName()const;
	
	void display()const;
private:
	char* name;
};

Entity::Entity(const char* name)
{
	if(name == NULL)
	{
		puts("Entity constructor error: name is null");
		throw "Entity constructor error: name is null";
	}
	
	int len = strlen(name) + 1;
	this->name = (char*)malloc(len);
	memset(this->name,0,len);
	memcpy(this->name,name,len);
}

Entity::Entity(const Entity& other)
	:Entity(other.name)                    //委托构造函数
{ 

}

Entity::~Entity()
{
	free(name);
}

Entity& Entity::operator =(const Entity& other)
{
	assert(other.name != NULL);
	free(name);                           //free前可以不用做判空处理，因为NULL指针也可以free
	
	int len = strlen(other.name) + 1;
	name = (char*)malloc(len);
	memcpy(name,other.name,len);
	
	return *this;
}

bool Entity::operator ==(const Entity& other)
{
	return strcmp(name,other.name) == 0 ? true : false;    //通过对构造函数和set方法的限制，name属性不可能为NULL，所以不用做判空处理
}

void Entity::setName(const char* name)
{
	if(name == NULL)
	{
		fprintf(stdout,"setName error: name is null\n");
		return ;
	}
	free(this->name);
	
	this->name = (char*)malloc(strlen(name) + 1);
	strcpy(this->name,name);
}

const char* Entity::getName()const
{
	return name;
}

void Entity::display()const
{
	if(name == NULL)
	{
		printf("Entity display name is null\n");
		return ;
	}
	
	printf("Entity name: %s\n",name);
}

#endif //_ENTITY_H