#ifndef _GREDE_H
#define _GREDE_H

#define CLAZZ_COUNT 4    //每个年级最多具有的班级数量

class Clazz;             //前置声明，以防止头文件重复包含。或将头文件的#include移动到源文件中。

class Grade
{
public:
	Grade(int number);             //函数参数值传递时，前加const关键字与不加const关键字的效果相同。
	Grade(const Grade& other);     //函数参数指针传递和引用传递时，前加const关键字与不加const关键字的效果不同。加上const关键字函数更加安全
	virtual ~Grade();
	
	Grade& operator =(const Grade& other);       //如果Grade对象要放置到list,array等容器中必须重载赋值和等于运算符，
	bool operator ==(const Grade& other);        //如果Grade指针要放置到queue,vector等容器中可以不必重载赋值和等于运算符，
	
	void setNumber(int number);
	int getNumber()const;
	
	void addClazz(Clazz* pclazz);           //如果使用浅拷贝实现的话pclazz不能加const，使用深拷贝实现的话可以加const。
	void removeClazz(const Clazz* pclazz);
	Clazz* getClazz(int index);             //返回值为指针，所以不能加const
	
	void print()const;
private:
	int number;
	Clazz* clazzs[CLAZZ_COUNT];
};

#endif //_GREDE_H