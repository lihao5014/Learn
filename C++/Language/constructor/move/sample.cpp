#include "sample.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define _EEROR_
#undef _EEROR_

Sample::Sample()
	:data(0)
	,name(nullptr)
{
	puts("---default constructor---");
}

Sample::Sample(const data_t data)
	:data(data)
	,name(nullptr)
{
	fputs("---normal constructor: 1---\n",stdout);
} 

Sample::Sample(const char* name,const data_t data)
	:data(data)
{
	if(name == nullptr)
	{
		this->name = nullptr;
	}
	else
	{
		int len = strlen(name) + 1;
		this->name = (char*)malloc(len);
		memset(this->name,0,len);
		memcpy(this->name,name,len);
	}
	fputs("---normal constructor: 2---\n",stdout);
}

#ifdef _EEROR_
//如果不加other.name = nullptr语句，那么Sample(Sample& other)被实现为了浅拷贝构造函数，
//other.name和this->name指针指向同一片内存区域，Sample对象析构时会存在同一片内存空间被多次释放问题。
Sample::Sample(Sample& other)
	:data(other.data)
	,name(other.name)
{
	printf("---shallowly copy constructor---\n");
}
#else
//如果加上other.name = nullptr语句，那么Sample(Sample& other)被实现为了移动构造函数，具有内存资源所有权转移功能。
//other.name指针将其指向的内存资源所有权转移给this->name指针，同时other.name被置空了。在Sample对象被析构时就不会
//造成同一片内存空间被多次释放问题。
Sample::Sample(Sample& other)
	:data(other.data)
	,name(other.name)
{
	other.name = nullptr;
	printf("---move constructor by left value reference---\n");
}
#endif

Sample::Sample(const Sample& other)
	:data(other.data)
	,name(nullptr)
{
	if(other.name != nullptr)
	{
		int len = strlen(other.name) + 1;
		name = (char*)malloc(len);
		strcpy(name,other.name);
	}
	fprintf(stdout,"---deeply copy constructor---\n");
}

Sample::Sample(Sample&& other)
	:data(other.data)
	,name(other.name)
{
	other.name = nullptr;
	fprintf(stdout,"---move constructor by right value reference---\n");
}

Sample::~Sample()
{
	free(name);
	puts("---desturctor---");
}

#ifdef _EEROR_
Sample& Sample::operator =(Sample& other)  //被实现为浅拷贝赋值
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = other.name;
	}
	
	fprintf(stdout,"--shallowly copy assign--\n");
	return *this;
}
#else
Sample& Sample::operator =(Sample& other)  //被实现为移动赋值
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = other.name;
		other.name = nullptr;
	}
	
	printf("--move assign by left value reference--\n");
	return *this;
}
#endif

Sample& Sample::operator =(const Sample& other)   //只能被实现为深拷贝赋值
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		int len = strlen(other.name) + 1;    //通过定义一个len变量来保留计算的字符串长度结果，这样可以减少一次strlen函数调用，
		name = (char*)malloc(len);           //从而提升代码执行的速度。
		memcpy(name,other.name,len);
	}
	
	fprintf(stdout,"--deeply copy assign--\n");
	return *this;
}

Sample& Sample::operator =(Sample&& other)   //被实现为移动赋值
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = other.name;
		other.name = nullptr;
	}
	
	printf("--move assign by right value reference--\n");
	return *this;
}

void Sample::setName(const char* name)
{
	if(this->name != nullptr)
	{
		free(this->name);
		this->name = nullptr;
	}
	
	if(name != nullptr)
	{
		// int len = strlen(name) + 1;
		this->name = (char*)malloc(strlen(name) + 1);   //如果不定义len变量来保存strlen函数的返回结果，那么strlen函数就需要被多次调用。
		memcpy(this->name,name,strlen(name) + 1);       //从而降低程序执行的速度。
	}
}

const char* Sample::getName()const
{
	return name;
}

void Sample::setData(const data_t data)
{
	this->data = data;
}

data_t Sample::getData()const
{
	return data;
}

void Sample::show()const
{
	if(name != nullptr)
		printf("name =%s, ",name);
	
	printf("data = %d\n",data);
}