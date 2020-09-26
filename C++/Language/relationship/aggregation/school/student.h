#ifndef _STUDENT_H
#define _STUDENT_H

class Student
{
public:
	Student(const char* name,const int age);
	Student(const Student& other);
	virtual ~Student();
	
	Student& operator =(const Student& other);
	bool operator ==(const Student& other)const;
	
	void setName(const char* name);
	const char* getName()const;
	
	void setAge(const int age);
	int getAge()const;
	
	void info()const;
private:
	char *name;
	int age;
};

#endif //_STUDENT_H