#ifndef _CLAZZ_H
#define _CLAZZ_H

#include <string>
#include <list>
#include "student.h"
#include "teacher.h"

class Clazz
{
public:
	Clazz(const std::string& major);
	Clazz(const Clazz& other);
	virtual ~Clazz();                 //Clazz类的析构函数管理着advisor成员指针的内存释放，给setAdvisor方法传参时不能使用栈对象指针，
	                                  //因为setAdvisor方法是使用浅拷贝实现的。如果使用深拷贝实现的话，给setAdvisor方法传参时就可以使用栈对象地址
	Clazz& operator =(const Clazz& other);
	bool operator ==(const Clazz& other);
	bool operator !=(const Clazz& other);
	
	void setMajor(const std::string& major);
	std::string getMajor()const;
	
	void setAdvisor(Teacher* advisor);    //如果setAdvisor方法是使用浅拷贝赋值实现的话，那么advisor参数前不能加const。
	Teacher* getAdvisor();                //如果使用深拷贝实现的话，那么advisor参数前可以加const。
	
	void addStudent(const Student& student);
	void removeStudent(const Student& student);
	
	void clearStudent();
	Student& getStudent(int index);
	
	void display()const;
private:
	std::string major;                 //专业
	Teacher* advisor;                  //导师
	std::list<Student> students;
};

#endif //_CLAZZ_H