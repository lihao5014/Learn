#ifndef _SCHOOL_H
#define _SCHOOL_H

#include <string>
#include <array>

#define GRADE_COUNT 3     //每个学校最多具有的3个年级

class Grade;              //前置声明，以防止头文件重复包含。或将头文件的#include移动到源文件中。

class School              //因为School对象不再放在list，array等容器中，所以不需要重载=和==运算符
{
public:
	School(const std::string& address);
	School(const School& other);
	virtual ~School();
	
	void setAddress(const std::string& address);
	std::string getAddress()const;
	
	void addGrade(const Grade* pgrade);         //如果使用浅拷贝实现的话pgrade不能加const，使用深拷贝实现的话可以加const。
	void removeGrade(const Grade* pgrade);
	Grade* getGrade(const int index);
	
	void detail()const;
private:
	std::string address;
	std::array<Grade*,GRADE_COUNT> grades;
};

#endif //_SCHOOL_H