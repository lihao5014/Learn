#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

typedef int data_t;

class Base
{
public:
	Base(const data_t value):value(value){};
	Base(const Base& other):value(other.value){};
	virtual ~Base(){};
	
	void setValue(const data_t value);
	data_t getValue()const;
	void display()const;
private:
	data_t value;
};

void Base::setValue(const data_t value)
{
	this->value = value;
}

data_t Base::getValue()const
{
	return value;
}

void Base::display()const
{
	cout<<"display: value ="<<value<<endl;
}

class SubClass:public Base
{
public:
	SubClass(const char* name,const data_t value);
	~SubClass();
	
	void setName(const char* name);
	char* getName()const;
	void show()const;
	
	friend std::ostream& operator <<(std::ostream& os,const SubClass& subclass);
private:
	char* name;
};

SubClass::SubClass(const char* name,const data_t value):Base(value)
{
	if(name == nullptr)
	{
		throw "SubClass: name is null";           //构造函数中没有返回值，只能抛出异常
	}
	
	this->name = new char[strlen(name) + 1];      //new出来的空间不用判断this->name == nullptr,正确的做法是捕获异常
	memcpy(this->name,name,strlen(name)+1);
}

SubClass::~SubClass()
{
	if(name != nullptr)
	{
		delete[] name;               //基本数据类型delete[]等于delete
		name = nullptr;
	}
}
	
void SubClass::setName(const char* name)
{
	if(name == nullptr)
	{
		cout<<"setName: name is null"<<endl;
		return ;
	}
	
	if(this->name != nullptr)
	{
		delete this->name;
	}
	
	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);
}

char* SubClass::getName()const
{
	return name;
}

void SubClass::show()const
{
	display();
	cout<<"show: name ="<<name<<endl;
}

std::ostream& operator <<(std::ostream& os,const SubClass& subclass)
{
	os<<"SubClass: name ="<<subclass.name<<" ,value ="<<subclass.getValue();
	return os;
}

int main()
{
	try{
		SubClass subobject(nullptr,10);
		subobject.show();
		cout<<subobject<<endl;
	}catch(const char* e){
		cout<< e <<endl;
	}
	
	return 0;
}