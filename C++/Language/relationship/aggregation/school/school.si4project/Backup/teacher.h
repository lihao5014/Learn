#ifndef _TEACHER_H
#define _TEACHER_H

#include <string>

typedef enum Sex_t
{
	GIRL,
	BOY
}Sex;

class Teacher
{
public:
	Teacher(const Sex_t& sex,const std::string& title);
	Teacher(const Teacher& other);
	
	Teacher& operator =(const Teacher& other);
	bool operator ==(const Teacher& other);
	
	void setSex(const Sex_t& sex);
	Sex_t getSex()const;
	
	void setTitle(const std::string& title);
	std::string getTitle()const;
	
	void show()const;
private:
	Sex_t sex;
	std::string title;
};

#endif //_TEACHER_H