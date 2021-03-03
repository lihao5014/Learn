#include "demo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Demo::Demo()
	:name(NULL)
	,data(0)
{
	
}

Demo::Demo(const data_t data)
	:name(NULL)
	,data(data)
{
	
}

Demo::Demo(const char* name,const data_t data)
	:name(NULL)
	,data(data)
{
	if(name != NULL)
	{
		int len = strlen(name) + 1;
		this->name = (char*)malloc(len);
		memset(this->name,0,len);
		memcpy(this->name,name,len);
	}
}

Demo::Demo(const Demo& other)
	:data(other.data)
{
	if(other.name == NULL)
	{
		name = NULL;
	}
	else        //构造函数中不能使用return语句提前退出，所以这里的else语句必须加上
	{
		int len = strlen(other.name) + 1;
		name = (char*)malloc(len);
		memcpy(name,other.name,len);
	}
}

Demo::~Demo()
{
	delete name;
}
	
void Demo::setName(const char* name)
{
	if(this->name != NULL)
	{
		free(this->name);
		this->name = NULL;
	}
	
	if(name != NULL)
	{
		this->name = (char*)malloc(strlen(name) + 1);
		strcpy(this->name,name);
	}
}

const char* Demo::getName()const
{
	return name;
}

void Demo::setData(const data_t data)
{
	this->data = data;
}

data_t Demo::getData()const
{
	return data;
}

void Demo::show()const
{
	if(name != NULL)
	{
		printf("name =%s, ",name);
	}
	
	printf("data = %d\n",data);
}