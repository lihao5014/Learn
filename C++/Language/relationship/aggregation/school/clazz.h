#ifndef _CLAZZ_H
#define _CLAZZ_H

#include <string>
#include <list>
#include "student.h"

class Clazz
{
public:
	Clazz(const std::string& major);
	Clazz(const Clazz& other);
	
	Clazz& operator =(const Clazz& other);
	bool operator ==(const Clazz& other);
	
	void setMajor(const std::string& major);
	std::string getMajor()const;
	
	void clearStudent();
	void addStudent(const Student& student);
	bool removeStudent(const Student& student);
	
	void display()const;
private:
	std::string major
	std::list<Student> students;
};

#endif //_CLAZZ_H