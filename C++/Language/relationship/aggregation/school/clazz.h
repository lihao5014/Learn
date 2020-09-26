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
	virtual ~Clazz();
	
	Clazz& operator =(const Clazz& other);
	bool operator ==(const Clazz& other);
	
	void setMajor(const std::string& major);
	std::string getMajor()const;
	
	void setAdvisor(Teacher* advisor);
	Teacher* getAdvisor();
	
	void addStudent(const Student& student);
	void removeStudent(const Student& student);
	
	void clearStudent();
	Student& getStudent(const int index);
	
	void display()const;
private:
	std::string major                 //专业
	Teacher* advisor;                 //导师
	std::list<Student> students;
};

#endif //_CLAZZ_H