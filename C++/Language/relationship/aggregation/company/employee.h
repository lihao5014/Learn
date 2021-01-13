#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#define _DEEPLY_COPY_
// #undef _DEEPLY_COPY_

enum ReleaseType
{
	DELETE_POINTER,
	SET_NULLPTR
};

class Date;

class Employee
{
public:
	Employee(int number);
	Employee(int number,Date* pbirthday);
	Employee(const Employee& other);
	virtual ~Employee();              //一般情况下如果一个类具有指针成员，那么都要实现析构函数，以防止类对象不存在以后，成员指针造成的内存泄漏问题。
	
	Employee& operator =(const Employee& other);
	bool operator ==(const Employee& other);

	void release(ReleaseType type = DELETE_POINTER);            //释放birthday成员指针指向的堆内存空间。
#ifndef _DEEPLY_COPY_
	void setBirthday(Date* pbirthday);       //使用浅拷贝实现setBirthday方法时，其函数传参不能是const Date*，因为C++中const Date*指针不能直接赋值给Date*指针。
#else
	void setBirthday(const Date* pbirthday); //只用深拷贝实现setBirthday方法时，其函数参数可以是const Date*指针，也可以是Date*指针。
#endif
	Date* getBirthday();
	
	void setNumber(const int number);
	int getNumber()const;
	
	void show()const;
private:
	Date* pbirthday;
	int number;
};

#endif //_EMPLOYEE_H