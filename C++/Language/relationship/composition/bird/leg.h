#ifndef _LEG_H
#define _LEG_H

class Leg
{
public:
	Leg(const char* type);
	Leg(const Leg& other);
	~Leg();
	
	void operator =(const Leg& other);
	Leg operator =(const char* type);
	
	void print()const;
private:
	char* type;
};

Leg::Leg(const char* type)
	:type(nullptr)
{
	if(type != nullptr)
	{
		this->type = new char[strlen(type) + 1];
		memcpy(this->type,type,strlen(type) + 1);
	}
}

Leg::Leg(const Leg& other)
	:type(nullptr)
{
	if(other.type != nullptr)
	{
/*		if(type != nullptr)         //因为是拷贝构造，并且type在初始化列表中已经初始化为了nullptr，所以这里不需要判空后的delete操作
		{
			delete type;
			type = nullptr;
		}
*/
		type = new char[strlen(other.type) + 1];
		strcpy(type,other.type);
	}
}

Leg::~Leg()
{
	if(type != nullptr)
	{
		delete type;
		type = nullptr;
	}
}

void Leg::operator =(const Leg& other)
{
	if(other.type != nullptr)
	{
		if(type != nullptr)              //因为这里是赋值，以前对象的type类型可能不为空，如果不为空需要先delete，以免内存泄漏
		{
			delete type;
			type = nullptr;
		}
		
		type = new char[strlen(other.type) + 1];
		strcpy(type,other.type);
	}
}

Leg Leg::operator =(const char* type)
{
	if(type != nullptr)
	{
		if(this->type != nullptr)          //因为这里是赋值，以前对象的type类型可能不为空，如果不为空需要先delete，以免内存泄漏
		{
			delete this->type;
			this->type = nullptr;
		}
		
		this->type = new char[strlen(type) + 1];
		memcpy(this->type,type,strlen(type) + 1);
	}
	
	return *this;
}

void Leg::print()const
{
	if(type != nullptr)
	{
		printf("leg type =%s\n",type);
	}
}

#endif //_LEG_H