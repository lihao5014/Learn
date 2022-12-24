#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

class Animal
{
public:
	Animal();
	Animal(const std::string& name,int age);
	Animal(const Animal& other);
	
	void setName(const std::string& name);
	const std::string& getName()const;
	
	void setAge(int age);
	int getAge()const;
	
	void display()const;
private:
	std::string m_name;    //名称
	int m_age;             //年龄
};

#endif  //_ANIMAL_H_