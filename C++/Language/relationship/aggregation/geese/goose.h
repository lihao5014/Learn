#ifndef _GOOSE_H
#define _GOOSE_H

#include <list>

class Feather;

class Goose
{
public:
	Goose(const char* number);
	Goose(const Goose& other);     //Goose类想放入容器中，则必须实现拷贝构造函数和比较运算符==
	virtual ~Goose();
	
	Goose& operator =(const Goose& other);
	bool operator ==(const Goose& other);      //Goose类实现等于==运算符是为了使其可以放入list容器中
	
	void setNumber(const char* number);
	const char* getNumber()const;
	
	void addFeather(Feather* pfeather);        //参数不能使用const Feather* pfeather，因为会与list<Feather*>中要求存放的Feature*指针类型冲突
	void removeFeather(Feather* pfeather);
	
	void show()const;
private:
	char* number;
	std::list<Feather*> feathers;
};

#endif //_GOOSE_H